#define _GNU_SOURCE
#define FUZZY_MAX_RULES 16u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_OPENCL
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#ifndef FUZZY_NEURON_OPENCL
#error FUZZY_NEURON_OPENCL must be enabled for this program
#endif

#include <dlfcn.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FUZZY_MODEL_PLUGIN_ABI 2u
#define FUZZY_MODEL_EXPORT __attribute__((visibility("default")))
#define OUTPUT_DIR "fuzzy-neuron-output"
#define DEFAULT_PLUGIN "./yacht_model.so"
#define DATASET_PATH "plant.csv"
#define MODEL_PATH OUTPUT_DIR "/power_plant_model.csv"
#define KERNEL_PATH "fuzzy_neuron_kernels.cl"
#define LOSS_PATH OUTPUT_DIR "/power_plant_loss_history.csv"
#define LOSS_PLOT_PATH OUTPUT_DIR "/power_plant_loss_history"
#define OUTPUT_MEMBERSHIP_PATH OUTPUT_DIR "/power_plant_final_output_membership_parameters.csv"
#define TRAINING_SWEEP_PATH OUTPUT_DIR "/power_plant_training_sweep"
#define MODEL_SWEEP_PATH OUTPUT_DIR "/power_plant_model_sweep"
#define TEST_SWEEP_PATH OUTPUT_DIR "/power_plant_test_sweep"

#define DATASET_ROWS 9568u
#define TRAIN_ROWS 7654u
#define TEST_ROWS 1914u
#define INPUT_DIMENSIONS 4u
#define OUTPUT_DIMENSIONS 1u
#define OUTPUT_CONSEQUENT_COUNT 3u
#define OUTPUT_MINIMUM 0.0f
#define OUTPUT_MAXIMUM 1.0f
#define OUTPUT_STEP 0.005f
#define SPLIT_SEED 42u
#define XAVIER_SEED 42u
#define TRAIN_EPOCHS 3000u
#define TRAIN_BATCH_SIZE 128u
#define TRAIN_REPORT_INTERVAL 100u
#define TRAIN_LEARNING_RATE 0.0003f
#define TRAIN_ADAM_BETA1 0.9f
#define TRAIN_ADAM_BETA2 0.999f
#define TRAIN_ADAM_EPSILON 0.00000001f
#define HIDDEN_WIDTH 64u
#define INTERPOLATION_STEP 0.10f

/* PART 1: USER-SPECIFIC DATA AND MODEL SEMANTICS */
typedef struct power_plant_scale
{
    float input_minimum[INPUT_DIMENSIONS];
    float input_maximum[INPUT_DIMENSIONS];
    float target_minimum;
    float target_maximum;
} power_plant_scale_t;

FUZZY_NEURON_PARAMETERS(power_plant_low_parameters, 0.25f, 0.30f);
FUZZY_NEURON_PARAMETERS(power_plant_high_parameters, 0.75f, 0.30f);
FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(power_plant_low_membership, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, power_plant_low_parameters);
FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(power_plant_high_membership, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, power_plant_high_parameters);

/* PART 2: FUZZY.H MODEL DSL */
FUZZY_NEURON_LAYERS(
    power_plant_layers,
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_OUTPUT_ENTRY(OUTPUT_CONSEQUENT_COUNT, FUZZY_NEURON_SIGMOID)
);

FUZZY_NEURON_BINARY_MODEL(
    power_plant_model,
    INPUT_DIMENSIONS,
    OUTPUT_CONSEQUENT_COUNT,
    FUZZY_LOGIC_STANDARD,
    power_plant_low_membership,
    power_plant_high_membership,
    power_plant_layers,
    "temperature",
    "exhaust_vacuum",
    "ambient_pressure",
    "relative_humidity"
)

FUZZY_NEURON_MODEL_PLUGIN(power_plant_model, FUZZY_MODEL_PLUGIN_ABI, "combined-cycle-power-plant-fuzzy-ann", FUZZY_MODEL_EXPORT)

#ifndef FUZZY_MODEL_PLUGIN_ONLY
FUZZY_NEURON_HOT_RELOAD(power_plant_plugin, DEFAULT_PLUGIN)

static float power_plant_output_parameters[OUTPUT_CONSEQUENT_COUNT][2] =
{
    {0.15f, 0.20f},
    {0.50f, 0.20f},
    {0.85f, 0.20f}
};

static float power_plant_output_membership(size_t membership, float value)
{
    float difference = (value - power_plant_output_parameters[membership][0]) / power_plant_output_parameters[membership][1];
    return expf(-0.5f * difference * difference);
}

static float power_plant_output_low(float value) { return power_plant_output_membership(0u, value); }
static float power_plant_output_medium(float value) { return power_plant_output_membership(1u, value); }
static float power_plant_output_high(float value) { return power_plant_output_membership(2u, value); }

FUZZY_NEURON_OUTPUT_PIPELINE(power_plant_output, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, OUTPUT_STEP, power_plant_output_low, power_plant_output_medium, power_plant_output_high);

static fuzzy_neuron_network_t *power_plant_visual_model = NULL;
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_temperature_low_final, power_plant_visual_model, 0u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_temperature_high_final, power_plant_visual_model, 1u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_exhaust_vacuum_low_final, power_plant_visual_model, 2u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_exhaust_vacuum_high_final, power_plant_visual_model, 3u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_ambient_pressure_low_final, power_plant_visual_model, 4u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_ambient_pressure_high_final, power_plant_visual_model, 5u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_relative_humidity_low_final, power_plant_visual_model, 6u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(power_plant_relative_humidity_high_final, power_plant_visual_model, 7u)

static fuzzy_neuron_history_t power_plant_history = {0};
FUZZY_NEURON_LOSS_PLOTTER(loss_plot_function, power_plant_history.losses, power_plant_history.epochs, power_plant_history.count, power_plant_history.initial_loss)

/* PART 3: MINIMAL USER CALLBACKS AND APPLICATION FLOW */
static void load_dataset(fuzzy_neuron_dataset_t *dataset)
{
    FILE *file = fopen(DATASET_PATH, "r");
    char header[256];
    size_t row;
    if (file == NULL) { fprintf(stderr, "Failed to open %s. Export Folds5x2_pp.xlsx as CSV first.\n", DATASET_PATH); exit(EXIT_FAILURE); }
    if (fgets(header, sizeof(header), file) == NULL) { fclose(file); fprintf(stderr, "Power-plant CSV is empty.\n"); exit(EXIT_FAILURE); }
    FUZZY_NEURON_DATASET_ALLOCATE(*dataset, DATASET_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);
    if (dataset->inputs == NULL || dataset->targets == NULL) { fclose(file); fprintf(stderr, "Dataset allocation failed.\n"); exit(EXIT_FAILURE); }
    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        float *input = dataset->inputs + row * INPUT_DIMENSIONS;
        if (fscanf(file, " %f,%f,%f,%f,%f", &input[0], &input[1], &input[2], &input[3], &dataset->targets[row]) != 5)
        { fclose(file); fprintf(stderr, "Invalid power-plant CSV row %zu. Expected AT,V,AP,RH,PE.\n", row + 2u); exit(EXIT_FAILURE); }
    }
    fclose(file);
}

static void split_dataset(const fuzzy_neuron_dataset_t *source, fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test)
{
    size_t order[DATASET_ROWS], row;
    unsigned int state = SPLIT_SEED;
    FUZZY_NEURON_DATASET_ALLOCATE(*training, TRAIN_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);
    FUZZY_NEURON_DATASET_ALLOCATE(*test, TEST_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);
    if (training->inputs == NULL || training->targets == NULL || test->inputs == NULL || test->targets == NULL) { fprintf(stderr, "Split allocation failed.\n"); exit(EXIT_FAILURE); }
    for (row = 0u; row < DATASET_ROWS; ++row) order[row] = row;
    for (row = DATASET_ROWS; row > 1u; --row)
    {
        size_t selected, temporary;
        state = state * 1664525u + 1013904223u;
        selected = (size_t)state % row;
        temporary = order[row - 1u]; order[row - 1u] = order[selected]; order[selected] = temporary;
    }
    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        fuzzy_neuron_dataset_t *destination = row < TRAIN_ROWS ? training : test;
        size_t target_row = row < TRAIN_ROWS ? row : row - TRAIN_ROWS;
        memcpy(destination->inputs + target_row * INPUT_DIMENSIONS, source->inputs + order[row] * INPUT_DIMENSIONS, INPUT_DIMENSIONS * sizeof(float));
        destination->targets[target_row] = source->targets[order[row]];
    }
}

static void normalize_dataset(fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test, power_plant_scale_t *scale)
{
    size_t row, dimension;
    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension) scale->input_minimum[dimension] = scale->input_maximum[dimension] = training->inputs[dimension];
    scale->target_minimum = scale->target_maximum = training->targets[0];
    for (row = 0u; row < training->rows; ++row)
    {
        for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
        {
            float value = training->inputs[row * INPUT_DIMENSIONS + dimension];
            scale->input_minimum[dimension] = fminf(scale->input_minimum[dimension], value);
            scale->input_maximum[dimension] = fmaxf(scale->input_maximum[dimension], value);
        }
        scale->target_minimum = fminf(scale->target_minimum, training->targets[row]);
        scale->target_maximum = fmaxf(scale->target_maximum, training->targets[row]);
    }
    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        fuzzy_neuron_dataset_t *dataset = row < TRAIN_ROWS ? training : test;
        size_t local = row < TRAIN_ROWS ? row : row - TRAIN_ROWS;
        for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
        {
            size_t index = local * INPUT_DIMENSIONS + dimension;
            dataset->inputs[index] = (dataset->inputs[index] - scale->input_minimum[dimension]) / (scale->input_maximum[dimension] - scale->input_minimum[dimension]);
        }
        dataset->targets[local] = (dataset->targets[local] - scale->target_minimum) / (scale->target_maximum - scale->target_minimum);
    }
}

static fuzzy_neuron_network_t *load_plugin(fuzzy_neuron_loaded_plugin_t *plugin)
{
    fuzzy_neuron_network_t *model;
    *plugin = power_plant_plugin_load();
    if (plugin->api == NULL || plugin->api->create == NULL || (model = plugin->api->create()) == NULL) { fprintf(stderr, "Failed to create fuzzy-neuron plugin model.\n"); exit(EXIT_FAILURE); }
    return model;
}

static float predict_scalar(fuzzy_neuron_network_t *model, const float inputs[])
{
    float activations[OUTPUT_CONSEQUENT_COUNT];
    if (!fuzzy_neuron_predict(model, inputs, activations)) { fprintf(stderr, "Prediction failed.\n"); exit(EXIT_FAILURE); }
    return fuzzy_neuron_output_decode(&power_plant_output, activations);
} 

static double dataset_metric(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *dataset, bool mae)
{
    double total = 0.0;
    size_t row;
    for (row = 0u; row < dataset->rows; ++row)
    {
        double error = (double)predict_scalar(model, dataset->inputs + row * INPUT_DIMENSIONS) - dataset->targets[row];
        total += mae ? fabs(error) : error * error;
    }
    return total / (double)dataset->rows;
}


static bool plot_output_memberships(void)
{
    return PLOT(OUTPUT_DIR "/power_plant_output_final_memberships", "Mamdani Output Memberships", OUTPUT_MAXIMUM, OUTPUT_STEP, SERIES(power_plant_output_low, "#3b82f6"), SERIES(power_plant_output_medium, "#22c55e"), SERIES(power_plant_output_high, "#ef4444"));
}

static bool plot_final_memberships(fuzzy_neuron_network_t *model)
{
    if (model == NULL || !model->compiled || model->premise_count != INPUT_DIMENSIONS * 2u) return false;
    power_plant_visual_model = model;
    if (!PLOT(OUTPUT_DIR "/power_plant_temperature_final_memberships", "Final Trained Temperature Memberships", 1.0f, OUTPUT_STEP, SERIES(power_plant_temperature_low_final, "#3b82f6"), SERIES(power_plant_temperature_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/power_plant_exhaust_vacuum_final_memberships", "Final Trained Exhaust Vacuum Memberships", 1.0f, OUTPUT_STEP, SERIES(power_plant_exhaust_vacuum_low_final, "#3b82f6"), SERIES(power_plant_exhaust_vacuum_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/power_plant_ambient_pressure_final_memberships", "Final Trained Ambient Pressure Memberships", 1.0f, OUTPUT_STEP, SERIES(power_plant_ambient_pressure_low_final, "#3b82f6"), SERIES(power_plant_ambient_pressure_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/power_plant_relative_humidity_final_memberships", "Final Trained Relative Humidity Memberships", 1.0f, OUTPUT_STEP, SERIES(power_plant_relative_humidity_low_final, "#3b82f6"), SERIES(power_plant_relative_humidity_high_final, "#ef4444"))) return false;
    return true;
}

static bool plot_interpolation(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *training, const fuzzy_neuron_dataset_t *test)
{
    fuzzy_point_t training_points[TRAIN_ROWS], model_points[TRAIN_ROWS], test_points[TEST_ROWS];
    float model_outputs[TRAIN_ROWS];
    size_t row;
    if (model == NULL || training == NULL || test == NULL) return false;
    FUZZY_NEURON_DATASET_POINTS(training_points, *training);
    FUZZY_NEURON_DATASET_POINTS(test_points, *test);
    for (row = 0u; row < training->rows; ++row)
    {
        model_outputs[row] = predict_scalar(model, training->inputs + row * INPUT_DIMENSIONS);
        model_points[row].coordinates = training->inputs + row * INPUT_DIMENSIONS;
        model_points[row].dimension_count = INPUT_DIMENSIONS;
        model_points[row].membership = model_outputs[row];
    }
    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(TRAINING_SWEEP_PATH, "Power Plant Training Data", training_points, OUTPUT_MINIMUM, OUTPUT_MAXIMUM,
        FUZZY_SWEEP_DIMENSION("temperature", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("exhaust_vacuum", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("ambient_pressure", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("relative_humidity", 0.0f, 1.0f, INTERPOLATION_STEP))) return false;

    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(MODEL_SWEEP_PATH, "Power Plant Model Output", model_points, OUTPUT_MINIMUM, OUTPUT_MAXIMUM,
        FUZZY_SWEEP_DIMENSION("temperature", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("exhaust_vacuum", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("ambient_pressure", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("relative_humidity", 0.0f, 1.0f, INTERPOLATION_STEP))) return false;

    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(TEST_SWEEP_PATH, "Power Plant Test Data", test_points, OUTPUT_MINIMUM, OUTPUT_MAXIMUM,
        FUZZY_SWEEP_DIMENSION("temperature", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("exhaust_vacuum", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("ambient_pressure", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("relative_humidity", 0.0f, 1.0f, INTERPOLATION_STEP))) return false;
    return true;
}

static void write_outputs(fuzzy_neuron_network_t *model, size_t best_epoch, double final_mse)
{
    FILE *file = fopen(OUTPUT_MEMBERSHIP_PATH, "w");
    size_t index;
    if (file == NULL) { fprintf(stderr, "Failed to write output memberships.\n"); exit(EXIT_FAILURE); }
    fprintf(file, "membership,shape,hedge,mean,sigma\n");
    fprintf(file, "low,gaussian,1,%.9g,%.9g\n", power_plant_output_parameters[0][0], power_plant_output_parameters[0][1]);
    fprintf(file, "medium,gaussian,1,%.9g,%.9g\n", power_plant_output_parameters[1][0], power_plant_output_parameters[1][1]);
    fprintf(file, "high,gaussian,1,%.9g,%.9g\n", power_plant_output_parameters[2][0], power_plant_output_parameters[2][1]);
    fprintf(file, "calibration,affine,1,%.9g,%.9g\n", power_plant_output.gain, power_plant_output.bias);
    fclose(file);

    file = fopen(LOSS_PATH, "w");
    if (file == NULL) { fprintf(stderr, "Failed to write loss history.\n"); exit(EXIT_FAILURE); }
    fprintf(file, "epoch,mse,mse_over_initial\n");
    for (index = 0u; index < power_plant_history.count; ++index) fprintf(file, "%zu,%.12g,%.12g\n", power_plant_history.epochs[index], power_plant_history.losses[index], power_plant_history.losses[index] / power_plant_history.initial_loss);
    fclose(file);
    PLOT(LOSS_PLOT_PATH, "Power Plant Training MSE Relative to Initial MSE", (float)TRAIN_EPOCHS, (float)TRAIN_REPORT_INTERVAL, SERIES(loss_plot_function, "#dc2626"));
    if (!FUZZY_NEURON_MODEL_SAVE(model, MODEL_PATH)) { fprintf(stderr, "Model save failed.\n"); exit(EXIT_FAILURE); }
    printf("best_scalar_epoch=%zu\noutput_gain=%.12g\noutput_bias=%.12g\ntraining_mse_final=%.12g\n", best_epoch, power_plant_output.gain, power_plant_output.bias, final_mse);
}

static void train(void)
{
    fuzzy_neuron_dataset_t complete = {0}, training = {0}, test = {0}, encoded = {0};
    fuzzy_neuron_loaded_plugin_t plugin = {0};
    fuzzy_neuron_output_cache_t cache = {0};
    fuzzy_neuron_checkpoint_t checkpoint = {0};
    fuzzy_neuron_network_t *model;
    power_plant_scale_t scale;
    size_t epoch = 0u, capacity = (TRAIN_EPOCHS + TRAIN_REPORT_INTERVAL - 1u) / TRAIN_REPORT_INTERVAL + 1u;
    double initial_mse, loss;

    load_dataset(&complete);
    split_dataset(&complete, &training, &test);
    normalize_dataset(&training, &test, &scale);
    if (!fuzzy_neuron_dataset_encode_targets(&encoded, &training, &power_plant_output)) { fprintf(stderr, "Target encoding failed.\n"); exit(EXIT_FAILURE); }
    model = load_plugin(&plugin);
    FUZZY_NEURON_XAVIER_INIT(model, XAVIER_SEED);
    initial_mse = dataset_metric(model, &training, false);
    if (!fuzzy_neuron_history_create(&power_plant_history, capacity, initial_mse) || !fuzzy_neuron_checkpoint_create(&checkpoint, model, sizeof(power_plant_output), initial_mse)) { fprintf(stderr, "Training state allocation failed.\n"); exit(EXIT_FAILURE); }
    fuzzy_neuron_checkpoint_capture(&checkpoint, model, &power_plant_output, 0u, initial_mse);
    fuzzy_neuron_history_push(&power_plant_history, 0u, initial_mse);
    if (!FUZZY_NEURON_MODEL_OPENCL_INIT(model, TRAIN_BATCH_SIZE, KERNEL_PATH) || !fuzzy_neuron_output_cache_create(&cache, training.rows, OUTPUT_CONSEQUENT_COUNT)) { fprintf(stderr, "OpenCL initialization failed.\n"); exit(EXIT_FAILURE); }

    while (epoch < TRAIN_EPOCHS)
    {
        size_t chunk = TRAIN_EPOCHS - epoch > TRAIN_REPORT_INTERVAL ? TRAIN_REPORT_INTERVAL : TRAIN_EPOCHS - epoch;
        fuzzy_neuron_train_options_t options = FUZZY_NEURON_TRAIN_OPTIONS_ADAM_CUSTOM(chunk, TRAIN_BATCH_SIZE, TRAIN_LEARNING_RATE, chunk, TRAIN_ADAM_BETA1, TRAIN_ADAM_BETA2, TRAIN_ADAM_EPSILON, false);
        if (!FUZZY_NEURON_MODEL_OPENCL_TRAIN(model, &encoded, &options, MSE)) { fprintf(stderr, "OpenCL training failed at epoch %zu.\n", epoch + chunk); exit(EXIT_FAILURE); }
        epoch += chunk;
        if (!fuzzy_neuron_output_cache_refresh(&cache, model, &training, &power_plant_output) || !fuzzy_neuron_output_fit_affine(&power_plant_output, &cache, training.targets)) { fprintf(stderr, "Output calibration failed.\n"); exit(EXIT_FAILURE); }
        loss = fuzzy_neuron_output_cache_mse(&power_plant_output, &cache, training.targets);
        if (loss < checkpoint.loss) fuzzy_neuron_checkpoint_capture(&checkpoint, model, &power_plant_output, epoch, loss);
        fuzzy_neuron_history_push(&power_plant_history, epoch, loss);
        printf("epoch=%zu mse=%.12g relative=%.12g gain=%.9g bias=%.9g best_epoch=%zu best_mse=%.12g\n", epoch, loss, loss / initial_mse, power_plant_output.gain, power_plant_output.bias, checkpoint.epoch, checkpoint.loss);
    }

    fuzzy_neuron_checkpoint_restore(&checkpoint, model, &power_plant_output);
    loss = dataset_metric(model, &training, false);
    write_outputs(model, checkpoint.epoch, loss);
    if (!plot_final_memberships(model)) { fprintf(stderr, "Failed to plot final trained memberships.\n"); exit(EXIT_FAILURE); }
    if (!plot_output_memberships()) { fprintf(stderr, "Failed to plot output memberships.\n"); exit(EXIT_FAILURE); }
    if (!plot_interpolation(model, &training, &test)) { fprintf(stderr, "Failed to generate interpolation sweeps.\n"); exit(EXIT_FAILURE); }
    printf("training_mse_initial=%.12g\ntest_mse=%.12g\ntest_mae=%.12g\n", initial_mse, dataset_metric(model, &test, false), dataset_metric(model, &test, true));

    fuzzy_neuron_output_cache_free(&cache);
    fuzzy_neuron_checkpoint_free(&checkpoint);
    fuzzy_neuron_history_free(&power_plant_history);
    fuzzy_neuron_dataset_free(&complete);
    fuzzy_neuron_dataset_free(&training);
    fuzzy_neuron_dataset_free(&test);
    fuzzy_neuron_dataset_free(&encoded);
    plugin.api->destroy(model);
    power_plant_plugin_unload(&plugin);
}

int main(void)
{
    train();
    return EXIT_SUCCESS;
}
#endif
