#define _GNU_SOURCE
#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_OPENCL
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#if !defined(FUZZY_NEURON_OPENCL)
#error FUZZY_NEURON_OPENCL must be enabled for this program
#endif

#include <dlfcn.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_OPENMP)
#include <omp.h>
#endif

#define FUZZY_MODEL_PLUGIN_ABI 1u
#define OUTPUT_DIR "fuzzy-neuron-output"
#define DEFAULT_PLUGIN "./fuzzy_model_rules.so"
#define DEFAULT_TRAIN_DATASET "sugeno/sugeno_complex_sweep.csv"
#define DEFAULT_MODEL OUTPUT_DIR "/fuzzy_neuron_model.csv"
#define DEFAULT_KERNEL "fuzzy_neuron_kernels.cl"
#define DEFAULT_TEST_OUTPUT OUTPUT_DIR "/fuzzy_neuron_test_predictions.csv"
#define DEFAULT_ORIGINAL_OUTPUT OUTPUT_DIR "/fuzzy_neuron_original_predictions.csv"
#define FUZZY_MODEL_EXPORT __attribute__((visibility("default")))

#define LAYERS 100u

#define SCALE 1.0f

typedef struct fuzzy_neuron_regression_statistics
{
    double target_minimum;
    double target_maximum;
    double target_range;
    double target_mean;
    double target_standard_deviation;
    double prediction_minimum;
    double prediction_maximum;
    double prediction_range;
    double prediction_mean;
    double prediction_standard_deviation;
    double error_mean;
    double mse;
    double rmse;
    double mae;
    double maximum_error;
    double correlation;
    double r_squared;
    double regression_slope;
    double regression_intercept;
    double target_variance;
    double prediction_variance;
    double covariance;
    double range_retention;
    double standard_deviation_retention;
    double constant_mean_mse;
    double constant_mean_rmse;
} fuzzy_neuron_regression_statistics_t;

FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, 1.0f, 15.0f, 40.0f, false)
FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, 1.0f, 35.0f, 75.0f, true)
FUZZY_VAR(load_low, FUZZY_SHAPE_RAMP, 1.0f, 20.0f, 50.0f, false)
FUZZY_VAR(load_high, FUZZY_SHAPE_RAMP, 1.0f, 45.0f, 85.0f, true)
FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, 1.0f, 1.0f, 4.0f, false)
FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, 1.0f, 3.0f, 8.0f, true)

FUZZY_NEURON_RULE(idle, SAND(temperature_low(x[0]), load_low(x[1]), vibration_low(x[2])))
FUZZY_NEURON_RULE(economy, SAND(1.0f - temperature_high(x[0]), load_high(x[1])))
FUZZY_NEURON_RULE(balanced, SOR(temperature_high(x[0]), vibration_high(x[2])))
FUZZY_NEURON_RULE(cooling, SAND(temperature_high(x[0]), load_high(x[1])))
FUZZY_NEURON_RULE(heavy_load, SAND(load_high(x[1]), 1.0f - vibration_high(x[2])))
FUZZY_NEURON_RULE(protection, SOR(SAND(temperature_high(x[0]), vibration_high(x[2])), SAND(load_high(x[1]), vibration_high(x[2]))))

static unsigned int fuzzy_neuron_random_state = 0x12345678u;

static float fuzzy_neuron_random_uniform(float minimum, float maximum)
{
    fuzzy_neuron_random_state = fuzzy_neuron_random_state * 1664525u + 1013904223u;
    return minimum + (maximum - minimum) * ((float)(fuzzy_neuron_random_state & 0x00ffffffu) / 16777215.0f);
}

static void fuzzy_neuron_xavier_initialize(fuzzy_neuron_network_t *model)
{
    size_t layer;

    fuzzy_neuron_random_state = 0x12345678u;

    for (layer = 0u; layer < model->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &model->layers[layer];
        size_t source_count = layer == 0u ? model->rule_count : model->layers[layer - 1u].count;
        size_t destination_count = current->count;
        float limit = sqrtf(6.0f / ((float)source_count + (float)destination_count));
        size_t destination;
        size_t source;

        for (destination = 0u; destination < destination_count; destination++)
        {
            model->biases[current->bias_offset + destination] = 0.0f;

            for (source = 0u; source < source_count; source++)
            {
                size_t weight_index = current->weight_offset + destination * source_count + source;
                model->weights[weight_index] = fuzzy_neuron_random_uniform(-limit, limit);
            }
        }

        printf("Xavier layer %u: %u -> %u, limit %+.9f\n", (unsigned int)layer, (unsigned int)source_count, (unsigned int)destination_count, limit);
    }
}

static void fuzzy_neuron_print_layer_statistics(const fuzzy_neuron_network_t *model, const char *stage)
{
    size_t layer;

    printf("\n============================================================\n");
    printf("Fuzzy-Neuron Layer Statistics: %s\n", stage);
    printf("============================================================\n");

    for (layer = 0u; layer < model->layer_count; layer++)
    {
        const fuzzy_neuron_layer_t *current = &model->layers[layer];
        size_t source_count = layer == 0u ? model->rule_count : model->layers[layer - 1u].count;
        size_t weight_count = source_count * current->count;
        size_t weight;
        size_t bias;
        double weight_sum = 0.0;
        double weight_absolute_sum = 0.0;
        double weight_squared_sum = 0.0;
        double bias_sum = 0.0;
        double bias_absolute_sum = 0.0;
        double bias_squared_sum = 0.0;
        float weight_minimum = model->weights[current->weight_offset];
        float weight_maximum = model->weights[current->weight_offset];
        float bias_minimum = model->biases[current->bias_offset];
        float bias_maximum = model->biases[current->bias_offset];

        for (weight = 0u; weight < weight_count; weight++)
        {
            float value = model->weights[current->weight_offset + weight];
            if (value < weight_minimum) weight_minimum = value;
            if (value > weight_maximum) weight_maximum = value;
            weight_sum += value;
            weight_absolute_sum += fabs((double)value);
            weight_squared_sum += (double)value * value;
        }

        for (bias = 0u; bias < current->count; bias++)
        {
            float value = model->biases[current->bias_offset + bias];
            if (value < bias_minimum) bias_minimum = value;
            if (value > bias_maximum) bias_maximum = value;
            bias_sum += value;
            bias_absolute_sum += fabs((double)value);
            bias_squared_sum += (double)value * value;
        }

        printf("\nLayer %u\n", (unsigned int)layer);
        printf("Source neurons: %u\n", (unsigned int)source_count);
        printf("Destination neurons: %u\n", (unsigned int)current->count);
        printf("Weight count: %u\n", (unsigned int)weight_count);
        printf("Weight minimum: %+.9f\n", weight_minimum);
        printf("Weight maximum: %+.9f\n", weight_maximum);
        printf("Weight mean: %+.9f\n", weight_sum / weight_count);
        printf("Weight absolute mean: %.9f\n", weight_absolute_sum / weight_count);
        printf("Weight RMS: %.9f\n", sqrt(weight_squared_sum / weight_count));
        printf("Bias minimum: %+.9f\n", bias_minimum);
        printf("Bias maximum: %+.9f\n", bias_maximum);
        printf("Bias mean: %+.9f\n", bias_sum / current->count);
        printf("Bias absolute mean: %.9f\n", bias_absolute_sum / current->count);
        printf("Bias RMS: %.9f\n", sqrt(bias_squared_sum / current->count));
    }

    printf("\n============================================================\n");
}

static void fuzzy_neuron_print_parameter_changes(const fuzzy_neuron_network_t *model, const float *initial_weights, const float *initial_biases)
{
    size_t layer;

    printf("\n============================================================\n");
    printf("Fuzzy-Neuron Parameter Changes\n");
    printf("============================================================\n");

    for (layer = 0u; layer < model->layer_count; layer++)
    {
        const fuzzy_neuron_layer_t *current = &model->layers[layer];
        size_t source_count = layer == 0u ? model->rule_count : model->layers[layer - 1u].count;
        size_t weight_count = source_count * current->count;
        size_t weight;
        size_t bias;
        double weight_absolute_change = 0.0;
        double weight_squared_change = 0.0;
        double weight_maximum_change = 0.0;
        double bias_absolute_change = 0.0;
        double bias_squared_change = 0.0;
        double bias_maximum_change = 0.0;

        for (weight = 0u; weight < weight_count; weight++)
        {
            size_t index = current->weight_offset + weight;
            double change = fabs((double)model->weights[index] - initial_weights[index]);
            weight_absolute_change += change;
            weight_squared_change += change * change;
            if (change > weight_maximum_change) weight_maximum_change = change;
        }

        for (bias = 0u; bias < current->count; bias++)
        {
            size_t index = current->bias_offset + bias;
            double change = fabs((double)model->biases[index] - initial_biases[index]);
            bias_absolute_change += change;
            bias_squared_change += change * change;
            if (change > bias_maximum_change) bias_maximum_change = change;
        }

        printf("\nLayer %u\n", (unsigned int)layer);
        printf("Weight mean absolute change: %.12f\n", weight_absolute_change / weight_count);
        printf("Weight RMS change: %.12f\n", sqrt(weight_squared_change / weight_count));
        printf("Weight maximum change: %.12f\n", weight_maximum_change);
        printf("Bias mean absolute change: %.12f\n", bias_absolute_change / current->count);
        printf("Bias RMS change: %.12f\n", sqrt(bias_squared_change / current->count));
        printf("Bias maximum change: %.12f\n", bias_maximum_change);
    }

    printf("\n============================================================\n");
}

static fuzzy_neuron_regression_statistics_t fuzzy_neuron_measure_regression(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *dataset)
{
    fuzzy_neuron_regression_statistics_t statistics = {0};
    float *outputs = malloc(model->output_dimensions * sizeof(*outputs));
    double target_sum = 0.0;
    double prediction_sum = 0.0;
    double target_squared_sum = 0.0;
    double prediction_squared_sum = 0.0;
    double target_prediction_sum = 0.0;
    double error_sum = 0.0;
    double squared_error_sum = 0.0;
    double absolute_error_sum = 0.0;
    double maximum_error = 0.0;
    double sample_count = (double)(dataset->rows * dataset->target_dimensions);
    size_t row;
    size_t output;

    fuzzy_neuron_predict(model, dataset->inputs, outputs);
    statistics.target_minimum = dataset->targets[0] * SCALE;
    statistics.target_maximum = dataset->targets[0] * SCALE;
    statistics.prediction_minimum = outputs[0] * SCALE;
    statistics.prediction_maximum = outputs[0] * SCALE;

    for (row = 0u; row < dataset->rows; row++)
    {
        const float *inputs = dataset->inputs + row * dataset->input_dimensions;
        const float *targets = dataset->targets + row * dataset->target_dimensions;

        fuzzy_neuron_predict(model, inputs, outputs);

        for (output = 0u; output < dataset->target_dimensions; output++)
        {
            double target = targets[output] * SCALE;
            double prediction = outputs[output] * SCALE;
            double error = prediction - target;
            double magnitude = fabs(error);

            if (target < statistics.target_minimum) statistics.target_minimum = target;
            if (target > statistics.target_maximum) statistics.target_maximum = target;
            if (prediction < statistics.prediction_minimum) statistics.prediction_minimum = prediction;
            if (prediction > statistics.prediction_maximum) statistics.prediction_maximum = prediction;
            if (magnitude > maximum_error) maximum_error = magnitude;

            target_sum += target;
            prediction_sum += prediction;
            target_squared_sum += target * target;
            prediction_squared_sum += prediction * prediction;
            target_prediction_sum += target * prediction;
            error_sum += error;
            squared_error_sum += error * error;
            absolute_error_sum += magnitude;
        }
    }

    statistics.target_mean = target_sum / sample_count;
    statistics.prediction_mean = prediction_sum / sample_count;
    statistics.error_mean = error_sum / sample_count;
    statistics.mse = squared_error_sum / sample_count;
    statistics.rmse = sqrt(statistics.mse);
    statistics.mae = absolute_error_sum / sample_count;
    statistics.maximum_error = maximum_error;
    statistics.target_variance = target_squared_sum / sample_count - statistics.target_mean * statistics.target_mean;
    statistics.prediction_variance = prediction_squared_sum / sample_count - statistics.prediction_mean * statistics.prediction_mean;
    statistics.covariance = target_prediction_sum / sample_count - statistics.target_mean * statistics.prediction_mean;

    if (statistics.target_variance < 0.0) statistics.target_variance = 0.0;
    if (statistics.prediction_variance < 0.0) statistics.prediction_variance = 0.0;

    statistics.target_standard_deviation = sqrt(statistics.target_variance);
    statistics.prediction_standard_deviation = sqrt(statistics.prediction_variance);
    statistics.target_range = statistics.target_maximum - statistics.target_minimum;
    statistics.prediction_range = statistics.prediction_maximum - statistics.prediction_minimum;

    if (statistics.target_standard_deviation > 0.0 && statistics.prediction_standard_deviation > 0.0)
    {
        statistics.correlation = statistics.covariance / (statistics.target_standard_deviation * statistics.prediction_standard_deviation);
    }

    if (statistics.correlation > 1.0) statistics.correlation = 1.0;
    if (statistics.correlation < -1.0) statistics.correlation = -1.0;

    statistics.r_squared = statistics.correlation * statistics.correlation;

    if (statistics.target_variance > 0.0)
    {
        statistics.regression_slope = statistics.covariance / statistics.target_variance;
    }

    statistics.regression_intercept = statistics.prediction_mean - statistics.regression_slope * statistics.target_mean;

    if (statistics.target_range > 0.0) statistics.range_retention = statistics.prediction_range / statistics.target_range;
    if (statistics.target_standard_deviation > 0.0) statistics.standard_deviation_retention = statistics.prediction_standard_deviation / statistics.target_standard_deviation;

    statistics.constant_mean_mse = statistics.target_variance;
    statistics.constant_mean_rmse = statistics.target_standard_deviation;

    free(outputs);
    return statistics;
}

static void fuzzy_neuron_print_regression_statistics(const fuzzy_neuron_regression_statistics_t *statistics, const char *stage)
{
    double baseline_ratio = statistics->constant_mean_mse > 0.0 ? statistics->mse / statistics->constant_mean_mse : 0.0;

    printf("\n============================================================\n");
    printf("Fuzzy-Neuron Regression Monitor: %s\n", stage);
    printf("============================================================\n");
    printf("Target minimum:                %+.10f\n", statistics->target_minimum);
    printf("Target maximum:                %+.10f\n", statistics->target_maximum);
    printf("Target range:                  %.10f\n", statistics->target_range);
    printf("Prediction minimum:            %+.10f\n", statistics->prediction_minimum);
    printf("Prediction maximum:            %+.10f\n", statistics->prediction_maximum);
    printf("Prediction range:              %.10f\n", statistics->prediction_range);
    printf("Mean error:                    %+.10f\n", statistics->error_mean);
    printf("MSE:                           %.10f\n", statistics->mse);
    printf("RMSE:                          %.10f\n", statistics->rmse);
    printf("MAE:                           %.10f\n", statistics->mae);
    printf("Maximum absolute error:        %.10f\n", statistics->maximum_error);
    printf("Correlation R:                 %+.10f\n", statistics->correlation);
    printf("R-squared:                     %.10f\n", statistics->r_squared);
    printf("Regression slope:              %+.10f\n", statistics->regression_slope);
    printf("Regression intercept:          %+.10f\n", statistics->regression_intercept);
    printf("Range retained:                %.6f%%\n", statistics->range_retention * 100.0);
    printf("Standard deviation retained:   %.6f%%\n", statistics->standard_deviation_retention * 100.0);
    printf("Model MSE / baseline MSE:      %.10f\n", baseline_ratio);
    printf("============================================================\n");
}

static bool fuzzy_neuron_calibrate_output_range(fuzzy_neuron_network_t *model, const fuzzy_neuron_regression_statistics_t *statistics)
{
    fuzzy_neuron_layer_t *output_layer;
    size_t source_count;
    double calibration_scale;
    double calibration_offset;
    size_t source;

    if (model->layer_count < 2u || model->output_dimensions != 1u || statistics->prediction_range <= 1.0e-12)
    {
        return false;
    }

    output_layer = &model->layers[model->layer_count - 1u];
    source_count = model->layers[model->layer_count - 2u].count;
    calibration_scale = statistics->target_range / statistics->prediction_range;
    calibration_offset = statistics->target_minimum - calibration_scale * statistics->prediction_minimum;

    printf("\n============================================================\n");
    printf("CPU Exact-Range Output Calibration\n");
    printf("============================================================\n");
    printf("Scale:                         %+.12f\n", calibration_scale);
    printf("Offset:                        %+.12f\n", calibration_offset);
    printf("Target range:                  %.12f\n", statistics->target_range);
    printf("Prediction range before:       %.12f\n", statistics->prediction_range);

    for (source = 0u; source < source_count; source++)
    {
        size_t weight_index = output_layer->weight_offset + source;
        model->weights[weight_index] = (float)(calibration_scale * model->weights[weight_index]);
    }

    model->biases[output_layer->bias_offset] = (float)(calibration_scale * model->biases[output_layer->bias_offset] + calibration_offset);

    printf("Calibration folded into final-layer weights and bias\n");
    printf("============================================================\n");
    return true;
}

FUZZY_NEURON_MODEL(fuzzy_model, 3u, 1u,
    FUZZY_NEURON_BIND((*model), idle);
    FUZZY_NEURON_BIND((*model), economy);
    FUZZY_NEURON_BIND((*model), balanced);
    FUZZY_NEURON_BIND((*model), cooling);
    FUZZY_NEURON_BIND((*model), heavy_load);
    FUZZY_NEURON_BIND((*model), protection);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), LAYERS, FUZZY_NEURON_SIGMOID);

    FUZZY_NEURON_OUTPUT((*model), FUZZY_NEURON_LINEAR);
)

FUZZY_NEURON_MODEL_PLUGIN(fuzzy_model, FUZZY_MODEL_PLUGIN_ABI, "temperature-load-vibration", FUZZY_MODEL_EXPORT)

#ifndef FUZZY_MODEL_PLUGIN_ONLY

FUZZY_NEURON_HOT_RELOAD(fuzzy_model_plugin, DEFAULT_PLUGIN)

static fuzzy_neuron_network_t *plot_model;

FUZZY_NEURON_SWEEP_EVALUATOR(evaluate_trained_model, plot_model, 1u, 0u, SCALE)

static fuzzy_neuron_csv_t csv_format(void)
{
    static const float input_scales[3] = {1.0f, 1.0f, 1.0f};
    static const float target_scales[1] = {SCALE};
    fuzzy_neuron_csv_t csv = {3u, 1u, true, ',', input_scales, target_scales};
    return csv;
}

static void generate_model_plots(fuzzy_neuron_network_t *model)
{
    plot_model = model;
    PLOT(OUTPUT_DIR "/fuzzy_neuron_temperature_memberships", "Temperature Membership Functions", 100.0f, 1.0f, SERIES(temperature_low, "#3b82f6"), SERIES(temperature_high, "#ef4444"));
    PLOT(OUTPUT_DIR "/fuzzy_neuron_load_memberships", "Load Membership Functions", 100.0f, 1.0f, SERIES(load_low, "#22c55e"), SERIES(load_high, "#f97316"));
    PLOT(OUTPUT_DIR "/fuzzy_neuron_vibration_memberships", "Vibration Membership Functions", 10.0f, 0.1f, SERIES(vibration_low, "#06b6d4"), SERIES(vibration_high, "#a855f7"));
    FUZZY_COG_SWEEP(OUTPUT_DIR "/fuzzy_neuron_learned_surface", "Trained Fuzzy-Neuron Surface", evaluate_trained_model, 1.0f, FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 2.0f), FUZZY_SWEEP_DIMENSION("Load", 0.0f, 100.0f, 2.0f), FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f));
}

static void train_model(void)
{
    fuzzy_neuron_csv_t csv = csv_format();
    fuzzy_neuron_dataset_t dataset = {0};
    fuzzy_neuron_loaded_plugin_t plugin = fuzzy_model_plugin_load();
    fuzzy_neuron_network_t *model = plugin.api->create();
    fuzzy_neuron_train_options_t mse_options;
    fuzzy_neuron_train_options_t huber_options;
    fuzzy_neuron_regression_statistics_t before_statistics;
    fuzzy_neuron_regression_statistics_t after_mse_statistics;
    fuzzy_neuron_regression_statistics_t after_huber_statistics;
    fuzzy_neuron_regression_statistics_t after_calibration_statistics;
    unsigned int mse_epochs;
    unsigned int mse_batch_size;
    unsigned int mse_report_interval;
    unsigned int huber_epochs;
    unsigned int huber_batch_size;
    unsigned int huber_report_interval;
    unsigned int opencl_batch_capacity;
    float mse_learning_rate;
    float huber_learning_rate;
    float *initial_weights;
    float *initial_biases;

    unsigned int continue_training;

    printf("Continue existing model? 0 = new, 1 = continue: ");
    scanf("%u", &continue_training);

    if (continue_training)
    {
        fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL);
        printf("Loaded existing model: %s\n", DEFAULT_MODEL);
    }
    else
    {
        fuzzy_neuron_xavier_initialize(model);
        printf("Initialized new model with Xavier initialization\n");
    }

    initial_weights = malloc(model->weight_count * sizeof(*initial_weights));
    initial_biases = malloc(model->bias_count * sizeof(*initial_biases));
    memcpy(initial_weights, model->weights, model->weight_count * sizeof(*initial_weights));
    memcpy(initial_biases, model->biases, model->bias_count * sizeof(*initial_biases));

    printf("\nLoaded plugin model topology\n");
    printf("Plugin: %s\n", plugin.api->name);
    printf("Rules: %u\n", (unsigned int)model->rule_count);
    printf("Layers: %u\n", (unsigned int)model->layer_count);
    printf("Weights: %u\n", (unsigned int)model->weight_count);
    printf("Biases: %u\n", (unsigned int)model->bias_count);
    printf("Activation slots: %u\n\n", (unsigned int)model->neuron_count);

    printf("GPU MSE epochs: ");
    scanf("%u", &mse_epochs);
    printf("GPU MSE batch size: ");
    scanf("%u", &mse_batch_size);
    printf("GPU MSE learning rate: ");
    scanf("%f", &mse_learning_rate);
    printf("GPU MSE report interval: ");
    scanf("%u", &mse_report_interval);

    printf("GPU Huber epochs: ");
    scanf("%u", &huber_epochs);
    printf("GPU Huber batch size: ");
    scanf("%u", &huber_batch_size);
    printf("GPU Huber learning rate: ");
    scanf("%f", &huber_learning_rate);
    printf("GPU Huber report interval: ");
    scanf("%u", &huber_report_interval);

    mse_options = FUZZY_NEURON_TRAIN_OPTIONS(mse_epochs, mse_batch_size, mse_learning_rate, mse_report_interval);
    huber_options = FUZZY_NEURON_TRAIN_OPTIONS(huber_epochs, huber_batch_size, huber_learning_rate, huber_report_interval);
    opencl_batch_capacity = mse_batch_size > huber_batch_size ? mse_batch_size : huber_batch_size;

    system("mkdir -p " OUTPUT_DIR);
    fuzzy_neuron_dataset_load_csv(DEFAULT_TRAIN_DATASET, &csv, &dataset);

    before_statistics = fuzzy_neuron_measure_regression(model, &dataset);
    fuzzy_neuron_print_regression_statistics(&before_statistics, "Before Training");

    printf("\n============================================================\n");
    printf("Staged Training Pipeline\n");
    printf("============================================================\n");
    printf("Stage 1: OpenCL GPU MSE coarse training\n");
    printf("Stage 2: OpenCL GPU Huber refinement\n");
    printf("Stage 3: CPU exact-range output calibration\n");
    printf("Dataset samples:              %u\n", (unsigned int)dataset.rows);
    printf("OpenCL batch capacity:        %u\n", opencl_batch_capacity);
    printf("Model output:                 %s\n", DEFAULT_MODEL);
    printf("============================================================\n");

    if (!fuzzy_neuron_opencl_init(model, opencl_batch_capacity, DEFAULT_KERNEL))
    {
        fprintf(stderr, "OpenCL GPU initialization failed\n");
        exit(EXIT_FAILURE);
    }

    printf("\n============================================================\n");
    printf("Stage 1: OpenCL GPU MSE Coarse Training\n");
    printf("============================================================\n");

    if (!fuzzy_neuron_opencl_train(model, &dataset, &mse_options, MSE))
    {
        fprintf(stderr, "OpenCL GPU MSE training failed\n");
        exit(EXIT_FAILURE);
    }

    after_mse_statistics = fuzzy_neuron_measure_regression(model, &dataset);
    fuzzy_neuron_print_regression_statistics(&after_mse_statistics, "After GPU MSE");

    printf("\n============================================================\n");
    printf("Stage 2: OpenCL GPU Huber Refinement\n");
    printf("============================================================\n");

    if (!fuzzy_neuron_opencl_train(model, &dataset, &huber_options, HUBER))
    {
        fprintf(stderr, "OpenCL GPU Huber training failed\n");
        exit(EXIT_FAILURE);
    }

    after_huber_statistics = fuzzy_neuron_measure_regression(model, &dataset);
    fuzzy_neuron_print_regression_statistics(&after_huber_statistics, "After GPU Huber");

    printf("\n============================================================\n");
    printf("Stage 3: CPU Exact-Range Calibration\n");
    printf("============================================================\n");

    if (!fuzzy_neuron_calibrate_output_range(model, &after_huber_statistics))
    {
        fprintf(stderr, "CPU output calibration failed\n");
        exit(EXIT_FAILURE);
    }

    after_calibration_statistics = fuzzy_neuron_measure_regression(model, &dataset);
    fuzzy_neuron_print_regression_statistics(&after_calibration_statistics, "After CPU Calibration");
    fuzzy_neuron_print_layer_statistics(model, "Final Model");
    fuzzy_neuron_print_parameter_changes(model, initial_weights, initial_biases);

    fuzzy_neuron_model_save_csv(model, DEFAULT_MODEL);
    generate_model_plots(model);

    printf("\nTraining pipeline complete\n");
    printf("Stage 1 backend: OpenCL GPU MSE\n");
    printf("Stage 2 backend: OpenCL GPU Huber\n");
    printf("Stage 3 backend: CPU output-head calibration\n");
    printf("Final MAE: %.10f\n", after_calibration_statistics.mae);
    printf("Final RMSE: %.10f\n", after_calibration_statistics.rmse);
    printf("Final range retained: %.6f%%\n", after_calibration_statistics.range_retention * 100.0);
    printf("Model: %s\n", DEFAULT_MODEL);
    printf("Plots: %s/\n", OUTPUT_DIR);

    free(initial_weights);
    free(initial_biases);
    fuzzy_neuron_dataset_free(&dataset);
    plugin.api->destroy(model);
    fuzzy_model_plugin_unload(&plugin);
}

static void run_input(void)
{
    fuzzy_neuron_loaded_plugin_t plugin = fuzzy_model_plugin_load();
    fuzzy_neuron_network_t *model = plugin.api->create();
    float input[3];
    float output[1];

    fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL);
    printf("Temperature Load Vibration: ");
    scanf("%f %f %f", &input[0], &input[1], &input[2]);
    fuzzy_neuron_predict(model, input, output);
    printf("Input: %.6f %.6f %.6f\n", input[0], input[1], input[2]);
    printf("Normalized output: %.9f\n", output[0]);
    printf("Scaled output: %.9f\n", output[0] * SCALE);
    plugin.api->destroy(model);
    fuzzy_model_plugin_unload(&plugin);
}

static void test_dataset(const char *dataset_path, const char *predictions_path)
{
    fuzzy_neuron_csv_t csv = csv_format();
    fuzzy_neuron_dataset_t dataset = {0};
    fuzzy_neuron_loaded_plugin_t plugin = fuzzy_model_plugin_load();
    fuzzy_neuron_network_t *model = plugin.api->create();
    FILE *predictions;
    double squared_error = 0.0;
    double absolute_error = 0.0;
    double maximum_error = 0.0;
    float output[1];
    size_t row;

    system("mkdir -p " OUTPUT_DIR);
    fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL);
    fuzzy_neuron_dataset_load_csv(dataset_path, &csv, &dataset);
    predictions = fopen(predictions_path, "w");
    fprintf(predictions, "Temperature,Load,Vibration,Expected,Predicted,Error\n");

    for (row = 0u; row < dataset.rows; row++)
    {
        const float *input = dataset.inputs + row * dataset.input_dimensions;
        float expected = dataset.targets[row] * SCALE;
        float predicted;
        float error;
        double magnitude;

        fuzzy_neuron_predict(model, input, output);
        predicted = output[0] * SCALE;
        error = predicted - expected;
        magnitude = fabs((double)error);
        squared_error += (double)error * error;
        absolute_error += magnitude;
        if (magnitude > maximum_error) maximum_error = magnitude;
        fprintf(predictions, "%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n", input[0], input[1], input[2], expected, predicted, error);
    }

    fclose(predictions);
    printf("\nDataset test complete\n");
    printf("Dataset: %s\n", dataset_path);
    printf("Samples: %u\n", (unsigned int)dataset.rows);
    printf("MSE: %.10f\n", squared_error / dataset.rows);
    printf("RMSE: %.10f\n", sqrt(squared_error / dataset.rows));
    printf("MAE: %.10f\n", absolute_error / dataset.rows);
    printf("Maximum error: %.10f\n", maximum_error);
    printf("Predictions: %s\n", predictions_path);

    fuzzy_neuron_dataset_free(&dataset);
    plugin.api->destroy(model);
    fuzzy_model_plugin_unload(&plugin);
}

static void test_new_dataset(void)
{
    char dataset_path[512];
    printf("Test CSV: ");
    scanf("%511s", dataset_path);
    test_dataset(dataset_path, DEFAULT_TEST_OUTPUT);
}

static void menu(void)
{
    int choice = 0;

    while (choice != 5)
    {
        printf("\n============================================================\n");
        printf("Fuzzy-Neuron CLI\n");
        printf("============================================================\n");
        printf("1. Train model\n");
        printf("2. Run one input\n");
        printf("3. Test new CSV dataset\n");
        printf("4. Test original dataset\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1) train_model();
        if (choice == 2) run_input();
        if (choice == 3) test_new_dataset();
        if (choice == 4) test_dataset(DEFAULT_TRAIN_DATASET, DEFAULT_ORIGINAL_OUTPUT);
    }
}

static void fuzzy_neuron_configure_cpu_parallelism(void)
{
#if defined(_OPENMP)
    omp_set_dynamic(0);
    omp_set_nested(0);

    printf("OpenMP enabled\n");
    printf("Logical processors: %d\n", omp_get_num_procs());
    printf("Maximum CPU worker threads: %d\n", omp_get_max_threads());
#else
    printf("OpenMP disabled: build with -fopenmp\n");
#endif
}

int main(void)
{
    if (system("mkdir -p " OUTPUT_DIR) != 0)
    {
        fprintf(stderr, "Failed to create output directory: %s\n", OUTPUT_DIR);
        return EXIT_FAILURE;
    }

    fuzzy_neuron_configure_cpu_parallelism();
    menu();

    return EXIT_SUCCESS;
}

#endif
