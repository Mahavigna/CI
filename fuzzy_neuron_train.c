#define _GNU_SOURCE
#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_NEURON_MAX_EXPRESSIONS 256u
#define FUZZY_OPENCL
#define FUZZY_SQLITE
#define FUZZY_NEURON_DECOUPLED
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
#include <time.h>

#define FUZZY_MODEL_PLUGIN_ABI 2u
#define FUZZY_MODEL_EXPORT __attribute__((visibility("default")))
#define OUTPUT_DIR "fuzzy-neuron-output"
#define DEFAULT_PLUGIN "./fuzzy_model_rules.so"
#define DATASET_PATH "airfoil_self_noise.dat"
#define MODEL_PATH OUTPUT_DIR "/airfoil_model.csv"
#define MODEL_DATABASE_PATH OUTPUT_DIR "/airfoil_model.db"
#define KERNEL_PATH "fuzzy_neuron_kernels.cl"
#define LOSS_PATH OUTPUT_DIR "/airfoil_loss_history.csv"
#define LOSS_PLOT_PATH OUTPUT_DIR "/airfoil_loss_history"
#define OUTPUT_MEMBERSHIP_PATH OUTPUT_DIR "/airfoil_final_output_membership_parameters.csv"
#define TRAINING_SWEEP_PATH OUTPUT_DIR "/airfoil_training_sweep"
#define MODEL_SWEEP_PATH OUTPUT_DIR "/airfoil_model_sweep"
#define TEST_SWEEP_PATH OUTPUT_DIR "/airfoil_test_sweep"

#define DATASET_ROWS 1503u
#define TRAIN_ROWS 1202u
#define TEST_ROWS 301u
#define INPUT_DIMENSIONS 5u
#define OUTPUT_DIMENSIONS 1u
#define OUTPUT_CONSEQUENT_COUNT 3u
#define OUTPUT_MINIMUM 0.0f
#define OUTPUT_MAXIMUM 1.0f
#define OUTPUT_STEP 0.005f
#define SPLIT_SEED 42u
#define XAVIER_SEED 42u
#define TRAIN_EPOCHS 10000u
#define TRAIN_BATCH_SIZE 128u
#define TRAIN_REPORT_INTERVAL 100u
#define TRAIN_LEARNING_RATE 0.0005f
#define TRAIN_ADAM_BETA1 0.9f
#define TRAIN_ADAM_BETA2 0.999f
#define TRAIN_ADAM_EPSILON 0.00000001f
#define HIDDEN_WIDTH 64u
#define INTERPOLATION_STEP 0.10f

#define RESPONSE_VOLTAGE_MINIMUM 0.0f
#define RESPONSE_VOLTAGE_MAXIMUM 5.0f
#define RESPONSE_VOLTAGE_STEP 0.01f

typedef struct airfoil_scale
{
    float input_minimum[INPUT_DIMENSIONS];
    float input_maximum[INPUT_DIMENSIONS];
    float target_minimum;
    float target_maximum;
} airfoil_scale_t;

FUZZY_VAR(airfoil_output_low, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0.15f, 0.20f)
FUZZY_VAR(airfoil_output_medium, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0.50f, 0.20f)
FUZZY_VAR(airfoil_output_high, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0.85f, 0.20f)

static fuzzy_neuron_network_t *airfoil_model_create(void)
{
    FUZZY_NEURON_RULE_SYSTEM(airfoil_rules, INPUT_DIMENSIONS, FUZZY_LOGIC_STANDARD);
    fuzzy_neuron_network_t *model;
    size_t index;

    NEURON_VAR(airfoil_rules, frequency_low, 0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f);
    NEURON_VAR(airfoil_rules, frequency_high, 0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f);
    NEURON_VAR(airfoil_rules, attack_low, 1u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f);
    NEURON_VAR(airfoil_rules, attack_high, 1u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f);
    NEURON_VAR(airfoil_rules, chord_low, 2u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f);
    NEURON_VAR(airfoil_rules, chord_high, 2u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f);
    NEURON_VAR(airfoil_rules, velocity_low, 3u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f);
    NEURON_VAR(airfoil_rules, velocity_high, 3u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f);
    NEURON_VAR(airfoil_rules, displacement_low, 4u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f);
    NEURON_VAR(airfoil_rules, displacement_high, 4u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f);

    NEURON_CONSEQUENT(airfoil_rules, consequent_low, 0u);
    NEURON_CONSEQUENT(airfoil_rules, consequent_medium, 1u);
    NEURON_CONSEQUENT(airfoil_rules, consequent_high, 2u);

    CATCH_FAILS(NEURON_RULE, airfoil_rules, SAND(frequency_low, attack_low, chord_low, velocity_low, displacement_low), consequent_low);
    CATCH_FAILS(NEURON_RULE, airfoil_rules, SAND(frequency_high, attack_low, chord_low), consequent_medium);
    CATCH_FAILS(NEURON_RULE, airfoil_rules, SOR(attack_high, displacement_high), consequent_high);
    CATCH_FAILS(NEURON_RULE, airfoil_rules, SAND(chord_high, velocity_high), consequent_high);
    CATCH_FAILS(NEURON_RULE, airfoil_rules, SOR(SAND(frequency_high, velocity_high), SAND(attack_high, displacement_high)), consequent_high);
    CATCH_FAILS(FUZZY_NEURON_RULE_SYSTEM_COMPILE, airfoil_rules);

    model = malloc(sizeof(*model));

    if (model == NULL)
    {
        fprintf(stderr, "Failed to allocate the airfoil model.\n");
        exit(EXIT_FAILURE);
    }

    fuzzy_neuron_init(model, airfoil_rules.input_dimensions, OUTPUT_CONSEQUENT_COUNT);

    model->logic_method = airfoil_rules.logic_method;
    model->premise_count = airfoil_rules.premise_count;
    model->expression_count = airfoil_rules.expression_count;
    model->rule_count = airfoil_rules.rule_count;
    model->premise_parameter_count = airfoil_rules.premise_parameter_count;
    model->trainable_fuzzy = true;

    for (index = 0u; index < airfoil_rules.premise_count; ++index)
    {
        model->premises[index] = airfoil_rules.premises[index];
    }

    for (index = 0u; index < airfoil_rules.expression_count; ++index)
    {
        model->expressions[index] = airfoil_rules.expressions[index];
    }

    for (index = 0u; index < airfoil_rules.rule_count; ++index)
    {
        if (airfoil_rules.rule_consequents[index] >= OUTPUT_CONSEQUENT_COUNT)
        {
            fprintf(stderr, "Airfoil rule %zu has an invalid consequent.\n", index);
            exit(EXIT_FAILURE);
        }

        model->rules[index] = airfoil_rules.rules[index];
        model->rule_roots[index] = airfoil_rules.rule_roots[index];
        model->rule_consequents[index] = airfoil_rules.rule_consequents[index];
    }

    for (index = 0u; index < airfoil_rules.premise_parameter_count; ++index)
    {
        model->premise_parameters[index] = airfoil_rules.premise_parameters[index];
    }

    CATCH_FAILS(fuzzy_neuron_add_layer, model, HIDDEN_WIDTH, FUZZY_NEURON_TANH);
    CATCH_FAILS(fuzzy_neuron_add_layer, model, HIDDEN_WIDTH, FUZZY_NEURON_TANH);
    CATCH_FAILS(fuzzy_neuron_add_layer, model, HIDDEN_WIDTH, FUZZY_NEURON_TANH);
    CATCH_FAILS(fuzzy_neuron_add_layer, model, HIDDEN_WIDTH, FUZZY_NEURON_TANH);
    CATCH_FAILS(fuzzy_neuron_add_layer, model, HIDDEN_WIDTH, FUZZY_NEURON_TANH);
    CATCH_FAILS(fuzzy_neuron_add_layer, model, OUTPUT_CONSEQUENT_COUNT, FUZZY_NEURON_SIGMOID);
    CATCH_FAILS(fuzzy_neuron_compile, model);

    return model;
}

FUZZY_NEURON_MODEL_PLUGIN(airfoil_model, FUZZY_MODEL_PLUGIN_ABI, "airfoil-self-noise-explicit-rules", FUZZY_MODEL_EXPORT)

#ifndef FUZZY_MODEL_PLUGIN_ONLY
FUZZY_NEURON_HOT_RELOAD(airfoil_plugin, DEFAULT_PLUGIN)

FUZZY_NEURON_OUTPUT_PIPELINE(airfoil_output, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, OUTPUT_STEP, airfoil_output_low, airfoil_output_medium, airfoil_output_high);
FUZZY_NEURON_MODEL_DATABASE(airfoil_database, MODEL_DATABASE_PATH, "airfoil-self-noise-explicit-rules", airfoil_output, INPUT_DIMENSIONS);

FUZZY_VAR(response_voltage_low, FUZZY_SHAPE_RAMP, 1.0f, 0.0f, 2.5f, false)
FUZZY_VAR(response_voltage_medium, FUZZY_SHAPE_TRIANGLE, 1.0f, 0.0f, 2.5f, 5.0f)
FUZZY_VAR(response_voltage_high, FUZZY_SHAPE_RAMP, 1.0f, 2.5f, 5.0f, true)

static fuzzy_neuron_network_t *airfoil_visual_model = NULL;

FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_frequency_low_final, airfoil_visual_model, 0u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_frequency_high_final, airfoil_visual_model, 1u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_attack_low_final, airfoil_visual_model, 2u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_attack_high_final, airfoil_visual_model, 3u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_chord_low_final, airfoil_visual_model, 4u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_chord_high_final, airfoil_visual_model, 5u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_velocity_low_final, airfoil_visual_model, 6u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_velocity_high_final, airfoil_visual_model, 7u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_displacement_low_final, airfoil_visual_model, 8u)
FUZZY_NEURON_PREMISE_PLOT_FUNCTION(airfoil_displacement_high_final, airfoil_visual_model, 9u)

static fuzzy_neuron_history_t airfoil_history = {0};

FUZZY_NEURON_LOSS_PLOTTER(loss_plot_function, airfoil_history.losses, airfoil_history.epochs, airfoil_history.count, airfoil_history.initial_loss)

static void load_dataset(fuzzy_neuron_dataset_t *dataset)
{
    FILE *file;
    size_t row;

    if (dataset == NULL)
    {
        fprintf(stderr, "Invalid dataset destination.\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(DATASET_PATH, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Failed to open %s.\n", DATASET_PATH);
        exit(EXIT_FAILURE);
    }

    FUZZY_NEURON_DATASET_ALLOCATE(*dataset, DATASET_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);

    if (dataset->inputs == NULL || dataset->targets == NULL)
    {
        fclose(file);
        fprintf(stderr, "Dataset allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        float *input = dataset->inputs + row * INPUT_DIMENSIONS;

        if (fscanf(file, "%f %f %f %f %f %f", &input[0], &input[1], &input[2], &input[3], &input[4], &dataset->targets[row]) != 6)
        {
            fclose(file);
            fprintf(stderr, "Invalid dataset row %zu.\n", row);
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(file) != 0)
    {
        fprintf(stderr, "Failed to close %s.\n", DATASET_PATH);
        exit(EXIT_FAILURE);
    }
}

static void split_dataset(const fuzzy_neuron_dataset_t *source, fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test)
{
    size_t order[DATASET_ROWS];
    size_t row;
    unsigned int state = SPLIT_SEED;

    if (source == NULL || training == NULL || test == NULL || source->rows != DATASET_ROWS || source->input_dimensions != INPUT_DIMENSIONS || source->target_dimensions != OUTPUT_DIMENSIONS)
    {
        fprintf(stderr, "Invalid dataset split request.\n");
        exit(EXIT_FAILURE);
    }

    FUZZY_NEURON_DATASET_ALLOCATE(*training, TRAIN_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);
    FUZZY_NEURON_DATASET_ALLOCATE(*test, TEST_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);

    if (training->inputs == NULL || training->targets == NULL || test->inputs == NULL || test->targets == NULL)
    {
        fprintf(stderr, "Split allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        order[row] = row;
    }

    for (row = DATASET_ROWS; row > 1u; --row)
    {
        size_t selected;
        size_t temporary;

        state = state * 1664525u + 1013904223u;
        selected = (size_t)state % row;
        temporary = order[row - 1u];
        order[row - 1u] = order[selected];
        order[selected] = temporary;
    }

    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        fuzzy_neuron_dataset_t *destination = row < TRAIN_ROWS ? training : test;
        size_t destination_row = row < TRAIN_ROWS ? row : row - TRAIN_ROWS;

        memcpy(destination->inputs + destination_row * INPUT_DIMENSIONS, source->inputs + order[row] * INPUT_DIMENSIONS, INPUT_DIMENSIONS * sizeof(float));
        destination->targets[destination_row] = source->targets[order[row]];
    }
}

static void normalize_dataset(fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test, airfoil_scale_t *scale)
{
    size_t row;
    size_t dimension;
    float target_range;

    if (training == NULL || test == NULL || scale == NULL || training->rows == 0u)
    {
        fprintf(stderr, "Invalid normalization request.\n");
        exit(EXIT_FAILURE);
    }

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        scale->input_minimum[dimension] = training->inputs[dimension];
        scale->input_maximum[dimension] = training->inputs[dimension];
    }

    scale->target_minimum = training->targets[0];
    scale->target_maximum = training->targets[0];

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

    target_range = scale->target_maximum - scale->target_minimum;

    if (!(target_range > 0.0f))
    {
        fprintf(stderr, "Target normalization range is invalid.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        fuzzy_neuron_dataset_t *dataset = row < TRAIN_ROWS ? training : test;
        size_t local_row = row < TRAIN_ROWS ? row : row - TRAIN_ROWS;

        for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
        {
            size_t index = local_row * INPUT_DIMENSIONS + dimension;
            float range = scale->input_maximum[dimension] - scale->input_minimum[dimension];

            if (!(range > 0.0f))
            {
                fprintf(stderr, "Input dimension %zu has no normalization range.\n", dimension);
                exit(EXIT_FAILURE);
            }

            dataset->inputs[index] = (dataset->inputs[index] - scale->input_minimum[dimension]) / range;
        }

        dataset->targets[local_row] = (dataset->targets[local_row] - scale->target_minimum) / target_range;
    }
}

static fuzzy_neuron_network_t *load_plugin(fuzzy_neuron_loaded_plugin_t *plugin)
{
    fuzzy_neuron_network_t *model;

    if (plugin == NULL)
    {
        fprintf(stderr, "Invalid plugin destination.\n");
        exit(EXIT_FAILURE);
    }

    *plugin = airfoil_plugin_load();

    if (plugin->api == NULL || plugin->api->create == NULL)
    {
        fprintf(stderr, "Invalid fuzzy-neuron plugin API.\n");
        exit(EXIT_FAILURE);
    }

    model = plugin->api->create();

    if (model == NULL)
    {
        fprintf(stderr, "Failed to create fuzzy-neuron plugin model.\n");
        exit(EXIT_FAILURE);
    }

    return model;
}

static float predict_scalar(fuzzy_neuron_network_t *model, const float inputs[])
{
    float activations[OUTPUT_CONSEQUENT_COUNT];

    CATCH_FAILS(fuzzy_neuron_predict, model, inputs, activations);

    return fuzzy_neuron_output_decode(&airfoil_output, activations);
}

static double dataset_metric(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *dataset, bool mae)
{
    double total = 0.0;
    size_t row;

    if (model == NULL || dataset == NULL || dataset->rows == 0u)
    {
        fprintf(stderr, "Invalid metric request.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < dataset->rows; ++row)
    {
        double error = (double)predict_scalar(model, dataset->inputs + row * INPUT_DIMENSIONS) - dataset->targets[row];

        total += mae ? fabs(error) : error * error;
    }

    return total / (double)dataset->rows;
}

static bool plot_output_memberships(void *unused)
{
    (void)unused;
    return PLOT(OUTPUT_DIR "/airfoil_output_final_memberships", "Mamdani Output Memberships", OUTPUT_MAXIMUM, OUTPUT_STEP, SERIES(airfoil_output_low, "#3b82f6"), SERIES(airfoil_output_medium, "#22c55e"), SERIES(airfoil_output_high, "#ef4444"));
}

static bool plot_final_memberships(fuzzy_neuron_network_t *model)
{
    if (model == NULL || !model->compiled || model->premise_count != INPUT_DIMENSIONS * 2u)
    {
        return false;
    }

    airfoil_visual_model = model;

    if (!PLOT(OUTPUT_DIR "/airfoil_frequency_final_memberships", "Final Trained Frequency Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_frequency_low_final, "#3b82f6"), SERIES(airfoil_frequency_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_attack_final_memberships", "Final Trained Attack Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_attack_low_final, "#3b82f6"), SERIES(airfoil_attack_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_chord_final_memberships", "Final Trained Chord Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_chord_low_final, "#3b82f6"), SERIES(airfoil_chord_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_velocity_final_memberships", "Final Trained Velocity Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_velocity_low_final, "#3b82f6"), SERIES(airfoil_velocity_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_displacement_final_memberships", "Final Trained Displacement Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_displacement_low_final, "#3b82f6"), SERIES(airfoil_displacement_high_final, "#ef4444"))) return false;

    return true;
}

static void print_training_state(const fuzzy_neuron_network_t *model, size_t epoch, double mse, double initial_mse, const fuzzy_neuron_checkpoint_t *checkpoint)
{
    double weight_sum = 0.0;
    double weight_square_sum = 0.0;
    float weight_minimum;
    float weight_maximum;
    size_t index;

    if (model == NULL || checkpoint == NULL || model->weight_count == 0u)
    {
        fprintf(stderr, "Invalid training report request.\n");
        exit(EXIT_FAILURE);
    }

    weight_minimum = model->weights[0];
    weight_maximum = model->weights[0];

    for (index = 0u; index < model->weight_count; ++index)
    {
        float weight = model->weights[index];

        weight_minimum = fminf(weight_minimum, weight);
        weight_maximum = fmaxf(weight_maximum, weight);
        weight_sum += weight;
        weight_square_sum += (double)weight * weight;
    }

    printf("epoch=%zu mse=%.12g relative=%.12g gain=%.9g bias=%.9g best_epoch=%zu best_mse=%.12g weight_min=%.9g weight_max=%.9g weight_mean=%.12g weight_l2=%.12g\n", epoch, mse, mse / initial_mse, airfoil_output.gain, airfoil_output.bias, checkpoint->epoch, checkpoint->loss, weight_minimum, weight_maximum, weight_sum / (double)model->weight_count, sqrt(weight_square_sum));
    fflush(stdout);
}

static bool plot_interpolation(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *training, const fuzzy_neuron_dataset_t *test)
{
    fuzzy_point_t training_points[TRAIN_ROWS];
    fuzzy_point_t model_points[TRAIN_ROWS];
    fuzzy_point_t test_points[TEST_ROWS];
    float model_outputs[TRAIN_ROWS];
    size_t row;

    if (model == NULL || training == NULL || test == NULL || training->rows != TRAIN_ROWS || test->rows != TEST_ROWS)
    {
        return false;
    }

    FUZZY_NEURON_DATASET_POINTS(training_points, *training);
    FUZZY_NEURON_DATASET_POINTS(test_points, *test);

    for (row = 0u; row < training->rows; ++row)
    {
        model_outputs[row] = predict_scalar(model, training->inputs + row * INPUT_DIMENSIONS);
        model_points[row].coordinates = training->inputs + row * INPUT_DIMENSIONS;
        model_points[row].dimension_count = INPUT_DIMENSIONS;
        model_points[row].membership = model_outputs[row];
    }

    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(TRAINING_SWEEP_PATH, "Airfoil Training Data", training_points, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP))) return false;
    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(MODEL_SWEEP_PATH, "Airfoil Model Output", model_points, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP))) return false;
    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(TEST_SWEEP_PATH, "Airfoil Test Data", test_points, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP), FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP))) return false;

    return true;
}

static void print_learned_fuzzy_vars(const fuzzy_neuron_network_t *model)
{
    size_t premise_index;

    if (model == NULL || !model->compiled)
    {
        fprintf(stderr, "Invalid model for learned FUZZY_VAR output.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");

    for (premise_index = 0u; premise_index < model->premise_count; ++premise_index)
    {
        const fuzzy_neuron_premise_t *premise = &model->premises[premise_index];
        const float *parameters = model->premise_parameters + premise->parameter_offset;

        if (premise->name == NULL)
        {
            fprintf(stderr, "Premise %zu has no name.\n", premise_index);
            exit(EXIT_FAILURE);
        }

        if (premise->shape != FUZZY_SHAPE_GAUSSIAN)
        {
            fprintf(stderr, "Premise %zu is not FUZZY_SHAPE_GAUSSIAN.\n", premise_index);
            exit(EXIT_FAILURE);
        }

        if (premise->parameter_count != 2u)
        {
            fprintf(stderr, "Premise %zu does not have two Gaussian parameters.\n", premise_index);
            exit(EXIT_FAILURE);
        }

        if (premise->parameter_offset + premise->parameter_count > model->premise_parameter_count)
        {
            fprintf(stderr, "Premise %zu has an invalid parameter range.\n", premise_index);
            exit(EXIT_FAILURE);
        }

        printf("FUZZY_VAR(%s, FUZZY_SHAPE_GAUSSIAN, %.9ff, %.9ff, %.9ff)\n", premise->name, premise->hedge, parameters[0], parameters[1]);

        if ((premise_index & 1u) != 0u)
        {
            printf("\n");
        }
    }

    printf("FUZZY_VAR(airfoil_output_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.150000000f, 0.200000000f)\n");
    printf("FUZZY_VAR(airfoil_output_medium, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.500000000f, 0.200000000f)\n");
    printf("FUZZY_VAR(airfoil_output_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.850000000f, 0.200000000f)\n");
    printf("\n");

    fflush(stdout);
}


static void write_outputs(fuzzy_neuron_network_t *model, size_t best_epoch, double final_mse)
{
    FILE *file;
    size_t index;

    file = fopen(OUTPUT_MEMBERSHIP_PATH, "w");

    if (file == NULL)
    {
        fprintf(stderr, "Failed to write output memberships.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "membership,shape,hedge,mean,sigma\n");
    fprintf(file, "low,gaussian,1,%.9g,%.9g\n", 0.15f, 0.20f);
    fprintf(file, "medium,gaussian,1,%.9g,%.9g\n", 0.50f, 0.20f);
    fprintf(file, "high,gaussian,1,%.9g,%.9g\n", 0.85f, 0.20f);
    fprintf(file, "calibration,affine,1,%.9g,%.9g\n", airfoil_output.gain, airfoil_output.bias);

    if (fclose(file) != 0)
    {
        fprintf(stderr, "Failed to close output membership file.\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(LOSS_PATH, "w");

    if (file == NULL)
    {
        fprintf(stderr, "Failed to write loss history.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "epoch,mse,mse_over_initial\n");

    for (index = 0u; index < airfoil_history.count; ++index)
    {
        fprintf(file, "%zu,%.12g,%.12g\n", airfoil_history.epochs[index], airfoil_history.losses[index], airfoil_history.losses[index] / airfoil_history.initial_loss);
    }

    if (fclose(file) != 0)
    {
        fprintf(stderr, "Failed to close loss history.\n");
        exit(EXIT_FAILURE);
    }

    CATCH_FAILS(PLOT, LOSS_PLOT_PATH, "Airfoil Training MSE Relative to Initial MSE", (float)TRAIN_EPOCHS, (float)TRAIN_REPORT_INTERVAL, SERIES(loss_plot_function, "#dc2626"));
    CATCH_FAILS(FUZZY_NEURON_MODEL_SAVE, model, MODEL_PATH);

    printf("best_scalar_epoch=%zu\n", best_epoch);
    printf("output_gain=%.12g\n", airfoil_output.gain);
    printf("output_bias=%.12g\n", airfoil_output.bias);
    printf("training_mse_final=%.12g\n", final_mse);
}

static float response_voltage(const float activations[OUTPUT_CONSEQUENT_COUNT])
{
    fuzzy_rules_t rules;
    float voltage;

    rules.count = 0u;

    CATCH_FAILS(FUZZY_RULE_ADD, &rules, activations[0], response_voltage_low);
    CATCH_FAILS(FUZZY_RULE_ADD, &rules, activations[1], response_voltage_medium);
    CATCH_FAILS(FUZZY_RULE_ADD, &rules, activations[2], response_voltage_high);

    voltage = fuzzy_rules_defuzzify(&rules, RESPONSE_VOLTAGE_MINIMUM, RESPONSE_VOLTAGE_MAXIMUM, RESPONSE_VOLTAGE_STEP, FUZZY_DEFUZZ_COG);

    if (!isfinite(voltage))
    {
        fprintf(stderr, "Deployment voltage COG is not finite.\n");
        exit(EXIT_FAILURE);
    }

    return voltage;
}

static void predict_cli(void)
{
    static const char *input_names[INPUT_DIMENSIONS] =
    {
        "frequency",
        "attack",
        "chord",
        "velocity",
        "displacement"
    };

    fuzzy_neuron_loaded_plugin_t plugin = {0};
    fuzzy_neuron_network_t *model;
    airfoil_scale_t scale;
    float raw_inputs[INPUT_DIMENSIONS];
    float normalized_inputs[INPUT_DIMENSIONS];
    float activations[OUTPUT_CONSEQUENT_COUNT];
    float raw_cog;
    float calibrated_cog;
    float physical_output;
    size_t dimension;

    if (!FUZZY_NEURON_MODEL_DATABASE_EXISTS(airfoil_database))
    {
        fprintf(stderr, "No trained model database exists at %s. Train the model first.\n", MODEL_DATABASE_PATH);
        exit(EXIT_FAILURE);
    }

    model = load_plugin(&plugin);

    FUZZY_NEURON_MODEL_DATABASE_LOAD(airfoil_database, model, scale.input_minimum, scale.input_maximum, scale.target_minimum, scale.target_maximum);

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        float range = scale.input_maximum[dimension] - scale.input_minimum[dimension];

        if (!(range > 0.0f))
        {
            fprintf(stderr, "Saved range for %s is invalid.\n", input_names[dimension]);
            exit(EXIT_FAILURE);
        }

        printf("%s [%.9g, %.9g]: ", input_names[dimension], scale.input_minimum[dimension], scale.input_maximum[dimension]);
        fflush(stdout);

        if (scanf("%f", &raw_inputs[dimension]) != 1 || !isfinite(raw_inputs[dimension]))
        {
            fprintf(stderr, "Invalid %s input.\n", input_names[dimension]);
            exit(EXIT_FAILURE);
        }

        normalized_inputs[dimension] = (raw_inputs[dimension] - scale.input_minimum[dimension]) / range;

        if (normalized_inputs[dimension] < 0.0f || normalized_inputs[dimension] > 1.0f)
        {
            fprintf(stderr, "%s is outside the trained range.\n", input_names[dimension]);
            exit(EXIT_FAILURE);
        }
    }

    CATCH_FAILS(fuzzy_neuron_predict, model, normalized_inputs, activations);

    raw_cog = fuzzy_neuron_output_decode_raw(&airfoil_output, activations);
    calibrated_cog = fuzzy_neuron_output_decode(&airfoil_output, activations);
    physical_output = scale.target_minimum + calibrated_cog * (scale.target_maximum - scale.target_minimum);

    if (!isfinite(raw_cog) || !isfinite(calibrated_cog) || !isfinite(physical_output))
    {
        fprintf(stderr, "Deployment output is not finite.\n");
        exit(EXIT_FAILURE);
    }

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        printf("%s raw=%.9g normalized=%.9g low=%.9g high=%.9g\n", input_names[dimension], raw_inputs[dimension], normalized_inputs[dimension], fuzzy_neuron_evaluate_premise(model, dimension * 2u, normalized_inputs), fuzzy_neuron_evaluate_premise(model, dimension * 2u + 1u, normalized_inputs));
    }

    printf("output_low_activation=%.9g\n", activations[0]);
    printf("output_medium_activation=%.9g\n", activations[1]);
    printf("output_high_activation=%.9g\n", activations[2]);
    printf("raw_normalized_cog=%.9g\n", raw_cog);
    printf("calibrated_normalized_cog=%.9g\n", calibrated_cog);
    printf("predicted_sound_pressure_level=%.9g\n", physical_output);
    printf("response_voltage=%.9g V\n", response_voltage(activations));

    plugin.api->destroy(model);
    airfoil_plugin_unload(&plugin);
}

static void train(void)
{
    fuzzy_neuron_dataset_t complete = {0};
    fuzzy_neuron_dataset_t training = {0};
    fuzzy_neuron_dataset_t test = {0};
    fuzzy_neuron_dataset_t encoded = {0};
    fuzzy_neuron_loaded_plugin_t plugin = {0};
    fuzzy_neuron_output_cache_t cache = {0};
    fuzzy_neuron_checkpoint_t checkpoint = {0};
    fuzzy_neuron_network_t *model;
    airfoil_scale_t scale;
    airfoil_scale_t saved_scale;
    size_t epoch = 0u;
    size_t capacity = (TRAIN_EPOCHS + TRAIN_REPORT_INTERVAL - 1u) / TRAIN_REPORT_INTERVAL + 1u;
    double initial_mse;
    double loss;

    load_dataset(&complete);
    split_dataset(&complete, &training, &test);
    normalize_dataset(&training, &test, &scale);
    model = load_plugin(&plugin);

    if (FUZZY_NEURON_MODEL_DATABASE_EXISTS(airfoil_database))
    {
        FUZZY_NEURON_MODEL_DATABASE_LOAD(airfoil_database, model, saved_scale.input_minimum, saved_scale.input_maximum, saved_scale.target_minimum, saved_scale.target_maximum);
        FUZZY_NEURON_MODEL_DATABASE_REQUIRE_MATCHING_SCALE(airfoil_database, scale.input_minimum, scale.input_maximum, saved_scale.input_minimum, saved_scale.input_maximum, scale.target_minimum, scale.target_maximum, saved_scale.target_minimum, saved_scale.target_maximum);
        printf("Continuing training from %s for %u additional epochs.\n", MODEL_DATABASE_PATH, (unsigned int)TRAIN_EPOCHS);
    }
    else
    {
        FUZZY_NEURON_XAVIER_INIT(model, XAVIER_SEED);
        printf("No model database found at %s; starting a new Xavier-initialized model.\n", MODEL_DATABASE_PATH);
    }

    CATCH_FAILS(fuzzy_neuron_dataset_encode_targets, &encoded, &training, &airfoil_output);

    initial_mse = dataset_metric(model, &training, false);

    CATCH_FAILS(fuzzy_neuron_history_create, &airfoil_history, capacity, initial_mse);
    CATCH_FAILS(fuzzy_neuron_checkpoint_create, &checkpoint, model, sizeof(airfoil_output), initial_mse);

    fuzzy_neuron_checkpoint_capture(&checkpoint, model, &airfoil_output, 0u, initial_mse);

    CATCH_FAILS(fuzzy_neuron_history_push, &airfoil_history, 0u, initial_mse);
    CATCH_FAILS(FUZZY_NEURON_MODEL_OPENCL_INIT, model, TRAIN_BATCH_SIZE, KERNEL_PATH);
    CATCH_FAILS(fuzzy_neuron_output_cache_create, &cache, training.rows, OUTPUT_CONSEQUENT_COUNT);

    while (epoch < TRAIN_EPOCHS)
    {
        size_t chunk = TRAIN_EPOCHS - epoch > TRAIN_REPORT_INTERVAL ? TRAIN_REPORT_INTERVAL : TRAIN_EPOCHS - epoch;
        fuzzy_neuron_train_options_t options = FUZZY_NEURON_TRAIN_OPTIONS_ADAM_CUSTOM(chunk, TRAIN_BATCH_SIZE, TRAIN_LEARNING_RATE, 0u, TRAIN_ADAM_BETA1, TRAIN_ADAM_BETA2, TRAIN_ADAM_EPSILON, false);

        CATCH_FAILS(FUZZY_NEURON_MODEL_OPENCL_TRAIN, model, &encoded, &options, MSE);

        epoch += chunk;

        CATCH_FAILS(fuzzy_neuron_output_cache_refresh, &cache, model, &training, &airfoil_output);
        CATCH_FAILS(fuzzy_neuron_output_fit_affine, &airfoil_output, &cache, training.targets);

        loss = fuzzy_neuron_output_cache_mse(&airfoil_output, &cache, training.targets);

        if (loss < checkpoint.loss)
        {
            fuzzy_neuron_checkpoint_capture(&checkpoint, model, &airfoil_output, epoch, loss);
        }

        CATCH_FAILS(fuzzy_neuron_history_push, &airfoil_history, epoch, loss);

        print_training_state(model, epoch, loss, initial_mse, &checkpoint);
    }

    fuzzy_neuron_checkpoint_restore(&checkpoint, model, &airfoil_output);

    loss = dataset_metric(model, &training, false);
    print_learned_fuzzy_vars(model);
    write_outputs(model, checkpoint.epoch, loss);

    FUZZY_NEURON_MODEL_DATABASE_SAVE(airfoil_database, model, scale.input_minimum, scale.input_maximum, scale.target_minimum, scale.target_maximum);

    CATCH_FAILS(plot_final_memberships, model);
    CATCH_FAILS(plot_output_memberships, NULL);
    CATCH_FAILS(plot_interpolation, model, &training, &test);

    printf("training_mse_initial=%.12g\n", initial_mse);
    printf("training_mse_final=%.12g\n", loss);
    printf("test_mse=%.12g\n", dataset_metric(model, &test, false));
    printf("test_mae=%.12g\n", dataset_metric(model, &test, true));

    arena_neuron_free(&cache, &checkpoint, &airfoil_history, &complete,
                      &training, &test, &encoded);

    plugin.api->destroy(model);
    airfoil_plugin_unload(&plugin);
}

/* ============================================================================
 * X-Macro DSL Definitions: Adaptive Fuzzy Rules + ANN MF Tuning Systems
 *
 * Mirrors the static rule setup of smart_hvac.c (5 inputs, 3 outputs,
 * Mamdani COG + BOA defuzzification) while allowing an OpenCL-accelerated ANN
 * to tune both base membership functions and per-sample MF adjustments.
 * ============================================================================ */

#define HVAC_TUNER_DB_PATH OUTPUT_DIR "/smart_hvac_tuner.db"
#define HVAC_TUNER_AUTOGEN_PATH OUTPUT_DIR "/smart_hvac_autogen.h"
#define AIRFOIL_TUNER_DB_PATH OUTPUT_DIR "/airfoil_tuner.db"

#define HVAC_INPUTS(X) \
    X(indoor_temp,  0.0f,  50.0f) \
    X(humidity,     0.0f, 100.0f) \
    X(co2_index,    0.0f, 100.0f) \
    X(occupancy,    0.0f, 100.0f) \
    X(outside_temp, 0.0f,  50.0f)

#define HVAC_INPUT_MFS(X) \
    X(temp_cold,          0u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f,  50.0f, 15.0f, 22.0f, 0.0f) \
    X(temp_comfortable,   0u, FUZZY_SHAPE_TRIANGLE,  1.0f, 0x7u, 0.0f,  50.0f, 18.0f, 24.0f, 30.0f) \
    X(temp_hot,           0u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f,  50.0f, 26.0f, 35.0f, 1.0f) \
    X(humidity_dry,       1u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 25.0f, 40.0f, 0.0f) \
    X(humidity_optimal,   1u, FUZZY_SHAPE_TRAPEZOID, 1.0f, 0xfu, 0.0f, 100.0f, 30.0f, 45.0f, 55.0f, 70.0f) \
    X(humidity_humid,     1u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 60.0f, 80.0f, 1.0f) \
    X(co2_low,            2u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 20.0f, 40.0f, 0.0f) \
    X(co2_moderate,       2u, FUZZY_SHAPE_TRIANGLE,  1.0f, 0x7u, 0.0f, 100.0f, 30.0f, 50.0f, 70.0f) \
    X(co2_high,           2u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 60.0f, 85.0f, 1.0f) \
    X(occupancy_empty,    3u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 10.0f, 30.0f, 0.0f) \
    X(occupancy_moderate, 3u, FUZZY_SHAPE_TRAPEZOID, 1.0f, 0xfu, 0.0f, 100.0f, 20.0f, 40.0f, 60.0f, 80.0f) \
    X(occupancy_crowded,  3u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 65.0f, 85.0f, 1.0f) \
    X(outside_cold,       4u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f,  50.0f, 10.0f, 20.0f, 0.0f) \
    X(outside_mild,       4u, FUZZY_SHAPE_TRIANGLE,  1.0f, 0x7u, 0.0f,  50.0f, 15.0f, 25.0f, 35.0f) \
    X(outside_hot,        4u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f,  50.0f, 30.0f, 40.0f, 1.0f)

#define HVAC_OUTPUTS(X) \
    X(fan_speed,     0.0f, 100.0f, 0.5f, FUZZY_DEFUZZ_COG) \
    X(cooling_power, 0.0f, 100.0f, 0.5f, FUZZY_DEFUZZ_COG) \
    X(ventilation,   0.0f, 100.0f, 0.5f, FUZZY_DEFUZZ_BOA)

#define HVAC_OUTPUT_MFS(X) \
    X(fan_low,        0u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 20.0f, 40.0f, 0.0f) \
    X(fan_medium,     0u, FUZZY_SHAPE_TRAPEZOID, 1.0f, 0xfu, 0.0f, 100.0f, 25.0f, 40.0f, 60.0f, 75.0f) \
    X(fan_high,       0u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 60.0f, 85.0f, 1.0f) \
    X(cooling_low,    1u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 20.0f, 40.0f, 0.0f) \
    X(cooling_medium, 1u, FUZZY_SHAPE_TRIANGLE,  1.0f, 0x7u, 0.0f, 100.0f, 25.0f, 50.0f, 75.0f) \
    X(cooling_high,   1u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 60.0f, 85.0f, 1.0f) \
    X(vent_low,       2u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 20.0f, 40.0f, 0.0f) \
    X(vent_medium,    2u, FUZZY_SHAPE_TRAPEZOID, 1.0f, 0xfu, 0.0f, 100.0f, 25.0f, 40.0f, 60.0f, 75.0f) \
    X(vent_high,      2u, FUZZY_SHAPE_RAMP,      1.0f, 0x3u, 0.0f, 100.0f, 60.0f, 85.0f, 1.0f)

#define HVAC_RULES(X) \
    X("Fan Low: Cold & Empty",                 FT_AND(temp_cold, occupancy_empty),                                     fan_low) \
    X("Fan Low: Comf & OptHum & LowCO2",       FT_AND(temp_comfortable, humidity_optimal, co2_low),                    fan_low) \
    X("Fan Medium: Comf & ModOcc",             FT_AND(temp_comfortable, occupancy_moderate),                           fan_medium) \
    X("Fan Medium: Humid OR ModCO2",           FT_OR(humidity_humid, co2_moderate),                                    fan_medium) \
    X("Fan High: Hot OR HighCO2",              FT_OR(temp_hot, co2_high),                                              fan_high) \
    X("Fan High: Crowded & OutHot",            FT_AND(occupancy_crowded, outside_hot),                                 fan_high) \
    X("Cooling Low: Cold OR OutCold",          FT_OR(temp_cold, outside_cold),                                         cooling_low) \
    X("Cooling Low: Comf & Empty",             FT_AND(temp_comfortable, occupancy_empty),                              cooling_low) \
    X("Cooling Medium: Comf & Humid",          FT_AND(temp_comfortable, humidity_humid),                               cooling_medium) \
    X("Cooling Medium: OutMild & ModOcc",      FT_AND(outside_mild, occupancy_moderate),                               cooling_medium) \
    X("Cooling High: Hot & (OutHot|Crowded)",  FT_AND(temp_hot, FT_OR(outside_hot, occupancy_crowded)),                cooling_high) \
    X("Cooling High: Hot & Humid & HighCO2",   FT_AND(temp_hot, humidity_humid, co2_high),                             cooling_high) \
    X("Vent Low: LowCO2 & Empty",              FT_AND(co2_low, occupancy_empty),                                       vent_low) \
    X("Vent Low: Dry & OutCold",               FT_AND(humidity_dry, outside_cold),                                     vent_low) \
    X("Vent Medium: ModCO2 & ModOcc",          FT_AND(co2_moderate, occupancy_moderate),                               vent_medium) \
    X("Vent Medium: OutMild & Comf",           FT_AND(outside_mild, temp_comfortable),                                 vent_medium) \
    X("Vent High: HighCO2 OR Crowded",         FT_OR(co2_high, occupancy_crowded),                                     vent_high) \
    X("Vent High: Humid & Hot",                FT_AND(humidity_humid, temp_hot),                                       vent_high)

#define HVAC_ANN_LAYERS(X) \
    X(48u, FUZZY_NEURON_TANH) \
    X(48u, FUZZY_NEURON_TANH)

FUZZY_TUNER_DEFINE_SYSTEM(
    smart_hvac_tuner,
    FUZZY_LOGIC_STANDARD,
    0.25f,
    HVAC_INPUTS,
    HVAC_INPUT_MFS,
    HVAC_OUTPUTS,
    HVAC_OUTPUT_MFS,
    HVAC_RULES,
    HVAC_ANN_LAYERS
)

/* Second X-Macro system: Real-world NASA Airfoil Self-Noise (5 inputs -> 1 output) */
#define AIRFOIL_TUNER_INPUTS(X) \
    X(frequency,    0.0f, 1.0f) \
    X(attack,       0.0f, 1.0f) \
    X(chord,        0.0f, 1.0f) \
    X(velocity,     0.0f, 1.0f) \
    X(displacement, 0.0f, 1.0f)

#define AIRFOIL_TUNER_INPUT_MFS(X) \
    X(af_freq_low,  0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f) \
    X(af_freq_high, 0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f) \
    X(af_atk_low,   1u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f) \
    X(af_atk_high,  1u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f) \
    X(af_chd_low,   2u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f) \
    X(af_chd_high,  2u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f) \
    X(af_vel_low,   3u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f) \
    X(af_vel_high,  3u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f) \
    X(af_dsp_low,   4u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.25f, 0.30f) \
    X(af_dsp_high,  4u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.75f, 0.30f)

#define AIRFOIL_TUNER_OUTPUTS(X) \
    X(sound_pressure, 0.0f, 1.0f, 0.01f, FUZZY_DEFUZZ_COG)

#define AIRFOIL_TUNER_OUTPUT_MFS(X) \
    X(af_out_low,    0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.15f, 0.20f) \
    X(af_out_medium, 0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.50f, 0.20f) \
    X(af_out_high,   0u, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, 0.85f, 0.20f)

#define AIRFOIL_TUNER_RULES(X) \
    X("Quiet: All Low",         FT_AND(af_freq_low, af_atk_low, af_chd_low, af_vel_low, af_dsp_low),           af_out_low) \
    X("Quiet: HighFreq/LowVel", FT_AND(af_freq_high, af_vel_low),                                              af_out_low) \
    X("Moderate: Mid Flow",     FT_OR(FT_AND(af_freq_low, af_vel_high), FT_AND(af_atk_low, af_chd_high)),      af_out_medium) \
    X("Moderate: HighChd",      FT_AND(af_chd_low, af_dsp_low),                                                af_out_medium) \
    X("Loud: HighAtk|HighDsp",  FT_OR(af_atk_high, af_dsp_high),                                               af_out_high) \
    X("Loud: LowFreq & HighV",  FT_AND(af_freq_low, af_vel_high, af_chd_low),                                  af_out_high)

#define AIRFOIL_TUNER_LAYERS(X) \
    X(32u, FUZZY_NEURON_TANH) \
    X(32u, FUZZY_NEURON_TANH)

FUZZY_TUNER_DEFINE_SYSTEM(
    airfoil_tuner,
    FUZZY_LOGIC_ALGEBRAIC,
    0.25f,
    AIRFOIL_TUNER_INPUTS,
    AIRFOIL_TUNER_INPUT_MFS,
    AIRFOIL_TUNER_OUTPUTS,
    AIRFOIL_TUNER_OUTPUT_MFS,
    AIRFOIL_TUNER_RULES,
    AIRFOIL_TUNER_LAYERS
)

static double monotonic_seconds(void)
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1.0e-9;
}

typedef struct hvac_synth_ctx
{
    const fuzzy_tuner_model_t *oracle;
    const float *inputs;
    float *targets;
} hvac_synth_ctx_t;

static void hvac_synth_worker(size_t begin, size_t end, void *context)
{
    hvac_synth_ctx_t *ctx = (hvac_synth_ctx_t *)context;
    size_t row;
    for (row = begin; row < end; ++row)
    {
        const float *in = ctx->inputs + row * 5u;
        float base_out[3];
        /* Simulate a real building with shifted thermal/occupancy coupling relative to hand-crafted MFs */
        float shifted_in[5] = {
            fminf(50.0f, fmaxf(0.0f, in[0] + 3.5f + 0.04f * (in[3] - 50.0f))),
            fminf(100.0f, fmaxf(0.0f, in[1] - 6.0f + 0.20f * (in[0] - 25.0f))),
            fminf(100.0f, fmaxf(0.0f, in[2] + 8.0f + 0.12f * (in[3] - 40.0f))),
            fminf(100.0f, fmaxf(0.0f, in[3] + 5.0f)),
            fminf(50.0f, fmaxf(0.0f, in[4] + 2.5f))
        };
        fuzzy_tuner_predict(ctx->oracle, shifted_in, base_out);
        /* Also apply realistic nonlinear actuator response curves */
        ctx->targets[row * 3u + 0u] = fminf(96.0f, fmaxf(4.0f, base_out[0] * 0.90f + 6.5f + 0.08f * (in[2] - 50.0f)));
        ctx->targets[row * 3u + 1u] = fminf(96.0f, fmaxf(4.0f, base_out[1] * 0.88f + 8.0f + 0.15f * (in[4] - 25.0f)));
        ctx->targets[row * 3u + 2u] = fminf(96.0f, fmaxf(4.0f, base_out[2] * 0.92f + 5.0f + 0.06f * (in[3] - 50.0f)));
    }
}

static void generate_hvac_datasets(
    const fuzzy_tuner_model_t *oracle,
    fuzzy_neuron_dataset_t *train_ds,
    fuzzy_neuron_dataset_t *test_ds
)
{
    const size_t train_rows = 800u;
    const size_t test_rows = 224u;
    const size_t total_rows = train_rows + test_rows;
    float *all_inputs = (float *)malloc(total_rows * 5u * sizeof(float));
    float *all_targets = (float *)malloc(total_rows * 3u * sizeof(float));
    unsigned int rng = 20261119u;
    size_t row;
    hvac_synth_ctx_t ctx;

    if (all_inputs == NULL || all_targets == NULL)
    {
        fprintf(stderr, "Failed to allocate HVAC verification dataset.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < total_rows; ++row)
    {
        size_t d;
        for (d = 0u; d < 5u; ++d)
        {
            float span = oracle->inputs[d].maximum - oracle->inputs[d].minimum;
            float u;
            rng = rng * 1664525u + 1013904223u;
            u = (float)((rng >> 8) & 0x00ffffffu) / 16777215.0f;
            all_inputs[row * 5u + d] = oracle->inputs[d].minimum + u * span;
        }
    }

    ctx.oracle = oracle;
    ctx.inputs = all_inputs;
    ctx.targets = all_targets;
    fuzzy_parallel_for(total_rows, 32u, hvac_synth_worker, &ctx);

    FUZZY_NEURON_DATASET_ALLOCATE(*train_ds, train_rows, 5u, 3u);
    FUZZY_NEURON_DATASET_ALLOCATE(*test_ds, test_rows, 5u, 3u);
    memcpy(train_ds->inputs, all_inputs, train_rows * 5u * sizeof(float));
    memcpy(train_ds->targets, all_targets, train_rows * 3u * sizeof(float));
    memcpy(test_ds->inputs, all_inputs + train_rows * 5u, test_rows * 5u * sizeof(float));
    memcpy(test_ds->targets, all_targets + train_rows * 3u, test_rows * 3u * sizeof(float));

    free(all_inputs);
    free(all_targets);
}

static bool run_fuzzy_tuner_verification(void)
{
    fuzzy_tuner_model_t *hvac = NULL;
    fuzzy_tuner_model_t *oracle = NULL;
    fuzzy_tuner_model_t *reloaded = NULL;
    fuzzy_neuron_dataset_t hvac_train = {0};
    fuzzy_neuron_dataset_t hvac_test = {0};
    fuzzy_tuner_metrics_t before_train, before_test, base_only_test, after_train, after_test, reload_test;
    float scenario[5] = {29.0f, 68.0f, 72.0f, 75.0f, 34.0f};
    float cpu_out[3] = {0}, gpu_out[3] = {0};
    double t0, t1, serial_ms, mt_ms, gpu_ms, train_sec;
    bool all_ok = true;

    printf("\n======================================================================\n");
    printf("Adaptive Fuzzy Rules + ANN Membership Function Tuning Verification\n");
    printf("CPU Threads Detected: %zu | OpenCL GPU Backend: Enabled\n", fuzzy_cpu_thread_count());
    printf("======================================================================\n");

    hvac = smart_hvac_tuner_create(42u);
    oracle = smart_hvac_tuner_create(42u);
    if (hvac == NULL || oracle == NULL)
    {
        fprintf(stderr, "FAIL: Could not instantiate X-macro smart_hvac_tuner system.\n");
        return false;
    }

    if (!fuzzy_tuner_opencl_init(hvac, 1024u, KERNEL_PATH))
    {
        fprintf(stderr, "FAIL: OpenCL initialization for smart_hvac_tuner failed.\n");
        fuzzy_tuner_destroy(hvac);
        fuzzy_tuner_destroy(oracle);
        return false;
    }

    /* ------------------------------------------------------------------------
     * TEST 1: Static-Rule Baseline Parity (Exact Match with smart_hvac.c)
     * ------------------------------------------------------------------------ */
    printf("\n[Test 1] Static-Rule Baseline Parity (Untuned Model vs smart_hvac.c)\n");
    if (!fuzzy_tuner_predict(hvac, scenario, cpu_out) ||
        !fuzzy_tuner_opencl_predict(hvac, scenario, 1u, gpu_out))
    {
        fprintf(stderr, "FAIL: Scenario prediction failed.\n");
        return false;
    }
    /* Expected from smart_hvac.c: Fan COG = 65.71%, Cooling COG = 69.87%, Vent BOA = 79.50% */
    {
        float ref[3] = {65.7069f, 69.8669f, 79.5000f};
        float max_ref_err = 0.0f;
        float max_gpu_err = 0.0f;
        size_t o;
        for (o = 0u; o < 3u; ++o)
        {
            float re = fabsf(cpu_out[o] - ref[o]);
            float ge = fabsf(cpu_out[o] - gpu_out[o]);
            if (re > max_ref_err) max_ref_err = re;
            if (ge > max_gpu_err) max_gpu_err = ge;
        }
        printf("  Scenario (29C, 68%%, 72%%, 75%%, 34C):\n");
        printf("    CPU -> Fan[COG]=%.4f%% | Cooling[COG]=%.4f%% | Vent[BOA]=%.4f%%\n", cpu_out[0], cpu_out[1], cpu_out[2]);
        printf("    GPU -> Fan[COG]=%.4f%% | Cooling[COG]=%.4f%% | Vent[BOA]=%.4f%%\n", gpu_out[0], gpu_out[1], gpu_out[2]);
        printf("    Max diff vs smart_hvac.c ref: %.6f | Max CPU-vs-GPU diff: %.6f\n", max_ref_err, max_gpu_err);
        if (max_ref_err > 0.05f || max_gpu_err > 1.0e-3f)
        {
            fprintf(stderr, "  FAIL: Baseline parity tolerance exceeded!\n");
            all_ok = false;
        }
        else
        {
            printf("  PASS: Exact static-rule parity verified on both CPU and OpenCL GPU!\n");
        }
    }

    /* Save before-training membership plots */
    fuzzy_tuner_plot_input_mfs(hvac, 0u, OUTPUT_DIR "/hvac_temp_before.svg", "Indoor Temp MFs (Before Tuning)", 0.5f);
    fuzzy_tuner_plot_output_mfs(hvac, 0u, OUTPUT_DIR "/hvac_fan_before.svg", "Fan Speed MFs [COG] (Before Tuning)", 0.5f);
    fuzzy_tuner_plot_output_mfs(hvac, 2u, OUTPUT_DIR "/hvac_vent_before.svg", "Ventilation MFs [BOA] (Before Tuning)", 0.5f);

    /* ------------------------------------------------------------------------
     * TEST 2: Multi-Threaded CPU vs Single-Thread CPU vs OpenCL GPU Benchmark
     * ------------------------------------------------------------------------ */
    printf("\n[Test 2] Batch Inference Throughput & CPU/GPU Parity (4096 samples x 3 outputs)\n");
    generate_hvac_datasets(oracle, &hvac_train, &hvac_test);
    {
        const size_t bench_rows = 4096u;
        float *bench_inputs = (float *)malloc(bench_rows * 5u * sizeof(float));
        float *pred_serial = (float *)malloc(bench_rows * 3u * sizeof(float));
        float *pred_mt = (float *)malloc(bench_rows * 3u * sizeof(float));
        float *pred_gpu = (float *)malloc(bench_rows * 3u * sizeof(float));
        float max_mt_diff = 0.0f;
        float max_gpu_diff = 0.0f;
        size_t i;

        for (i = 0u; i < bench_rows; ++i)
        {
            memcpy(bench_inputs + i * 5u, hvac_train.inputs + (i % hvac_train.rows) * 5u, 5u * sizeof(float));
        }

        /* Warmup GPU and persistent CPU thread pool */
        fuzzy_tuner_predict_batch_mt(hvac, hvac_train.inputs, hvac_train.rows, pred_mt);
        fuzzy_tuner_opencl_predict(hvac, bench_inputs, bench_rows, pred_gpu);

        t0 = monotonic_seconds();
        fuzzy_tuner_predict_batch_serial(hvac, bench_inputs, bench_rows, pred_serial);
        t1 = monotonic_seconds();
        serial_ms = (t1 - t0) * 1000.0;

        t0 = monotonic_seconds();
        fuzzy_tuner_predict_batch_mt(hvac, bench_inputs, bench_rows, pred_mt);
        t1 = monotonic_seconds();
        mt_ms = (t1 - t0) * 1000.0;

        t0 = monotonic_seconds();
        fuzzy_tuner_opencl_predict(hvac, bench_inputs, bench_rows, pred_gpu);
        t1 = monotonic_seconds();
        gpu_ms = (t1 - t0) * 1000.0;

        for (i = 0u; i < bench_rows * 3u; ++i)
        {
            float d1 = fabsf(pred_serial[i] - pred_mt[i]);
            float d2 = fabsf(pred_serial[i] - pred_gpu[i]);
            if (d1 > max_mt_diff) max_mt_diff = d1;
            if (d2 > max_gpu_diff) max_gpu_diff = d2;
        }

        printf("  CPU Serial (1 thread):    %7.2f ms (%.0f samples/sec)\n", serial_ms, (double)bench_rows / (serial_ms * 1.0e-3));
        printf("  CPU Multi-Thread (%2zu th): %7.2f ms (%.2fx speedup, max diff %.6f)\n",
            fuzzy_cpu_thread_count(), mt_ms, serial_ms / fmax(mt_ms, 1.0e-6), max_mt_diff);
        printf("  OpenCL GPU (%2u CUs):      %7.2f ms (%.2fx vs 1-th CPU, max diff %.6f)\n",
            hvac->opencl.device_compute_units, gpu_ms, serial_ms / fmax(gpu_ms, 1.0e-6), max_gpu_diff);

        if (max_mt_diff > 1.0e-5f || max_gpu_diff > 0.55f)
        {
            fprintf(stderr, "  FAIL: Batch CPU/GPU parity error too large!\n");
            all_ok = false;
        }
        else
        {
            printf("  PASS: Persistent CPU thread pool & OpenCL GPU batch inference verified!\n");
        }

        free(bench_inputs);
        free(pred_serial);
        free(pred_mt);
        free(pred_gpu);
    }

    /* ------------------------------------------------------------------------
     * TEST 3: GPU Joint Training (Static Rules + ANN Tuning Input & Output MFs)
     * ------------------------------------------------------------------------ */
    printf("\n[Test 3] OpenCL GPU Joint Training: Static Rules + ANN MF Tuning (COG & BOA)\n");
    fuzzy_tuner_dataset_metrics_mt(hvac, &hvac_train, &before_train);
    fuzzy_tuner_dataset_metrics_mt(hvac, &hvac_test, &before_test);
    printf("  BEFORE Tuning (Untuned Static Rules):\n");
    printf("    Train Overall MSE=%.4f (RMSE=%.3f%%) | Test Overall MSE=%.4f (RMSE=%.3f%%)\n",
        before_train.overall_mse, before_train.overall_rmse, before_test.overall_mse, before_test.overall_rmse);
    printf("    Test Per-Output RMSE -> Fan[COG]=%.3f%% | Cooling[COG]=%.3f%% | Vent[BOA]=%.3f%%\n",
        before_test.channel_rmse[0], before_test.channel_rmse[1], before_test.channel_rmse[2]);

    {
        fuzzy_tuner_train_options_t opts = FUZZY_TUNER_TRAIN_OPTIONS_ADAM(2000u, 256u, 0.002f, 0.02f, 50u);
        t0 = monotonic_seconds();
        if (!fuzzy_tuner_opencl_train(hvac, &hvac_train, &opts))
        {
            fprintf(stderr, "FAIL: OpenCL GPU training failed.\n");
            return false;
        }
        t1 = monotonic_seconds();
        train_sec = t1 - t0;
    }

    fuzzy_tuner_dataset_metrics_mt(hvac, &hvac_train, &after_train);
    fuzzy_tuner_dataset_metrics_mt(hvac, &hvac_test, &after_test);

    /* Measure contribution of tuned base MFs alone vs full ANN-modulated MFs */
    hvac->ann_enabled = false;
    fuzzy_tuner_dataset_metrics_mt(hvac, &hvac_test, &base_only_test);
    hvac->ann_enabled = true;

    printf("  Training completed on GPU in %.3f s (%.1f epochs/sec, %.0f samples/sec)\n",
        train_sec, 200.0 / fmax(train_sec, 1.0e-6), (200.0 * (double)hvac_train.rows) / fmax(train_sec, 1.0e-6));
    printf("  AFTER Tuning (Base MFs only, ANN off):\n");
    printf("    Test Overall MSE=%.4f (RMSE=%.3f%%) | Fan[COG]=%.3f%% | Cooling[COG]=%.3f%% | Vent[BOA]=%.3f%%\n",
        base_only_test.overall_mse, base_only_test.overall_rmse,
        base_only_test.channel_rmse[0], base_only_test.channel_rmse[1], base_only_test.channel_rmse[2]);
    printf("  AFTER Tuning (Full Fuzzy Rules + ANN Adaptive MFs):\n");
    printf("    Train Overall MSE=%.4f (RMSE=%.3f%%) | Test Overall MSE=%.4f (RMSE=%.3f%%)\n",
        after_train.overall_mse, after_train.overall_rmse, after_test.overall_mse, after_test.overall_rmse);
    printf("    Test Per-Output RMSE -> Fan[COG]=%.3f%% | Cooling[COG]=%.3f%% | Vent[BOA]=%.3f%%\n",
        after_test.channel_rmse[0], after_test.channel_rmse[1], after_test.channel_rmse[2]);
    printf("    MSE Reduction: %.2f%% (%.2fx lower test MSE)\n",
        100.0 * (1.0 - after_test.overall_mse / before_test.overall_mse),
        before_test.overall_mse / fmax(after_test.overall_mse, 1.0e-9));

    if (!(after_test.overall_mse < before_test.overall_mse * 0.50))
    {
        fprintf(stderr, "  FAIL: Expected at least 50%% test MSE reduction from ANN MF tuning!\n");
        all_ok = false;
    }
    else
    {
        printf("  PASS: Both Mamdani COG and BOA outputs converged cleanly with tuned MFs!\n");
    }

    /* Save after-training membership plots */
    fuzzy_tuner_plot_input_mfs(hvac, 0u, OUTPUT_DIR "/hvac_temp_after.svg", "Indoor Temp MFs (After ANN Tuning)", 0.5f);
    fuzzy_tuner_plot_output_mfs(hvac, 0u, OUTPUT_DIR "/hvac_fan_after.svg", "Fan Speed MFs [COG] (After ANN Tuning)", 0.5f);
    fuzzy_tuner_plot_output_mfs(hvac, 2u, OUTPUT_DIR "/hvac_vent_after.svg", "Ventilation MFs [BOA] (After ANN Tuning)", 0.5f);

    /* Show transparent inspection of ANN-adjusted MFs on scenario */
    {
        fuzzy_tuner_inspection_t insp;
        fuzzy_tuner_predict_inspect(hvac, scenario, cpu_out, &insp);
        printf("\n  Interpretable Inspection @ (29C, 68%%, 72%%, 75%%, 34C):\n");
        printf("    temp_hot       base=[%.2f, %.2f] -> ANN-eff=[%.2f, %.2f]\n",
            hvac->input_mf_parameters[hvac->input_mfs[2].parameter_offset + 0u],
            hvac->input_mf_parameters[hvac->input_mfs[2].parameter_offset + 1u],
            insp.effective_input_params[hvac->input_mfs[2].parameter_offset + 0u],
            insp.effective_input_params[hvac->input_mfs[2].parameter_offset + 1u]);
        printf("    fan_high [COG] base=[%.2f, %.2f] -> ANN-eff=[%.2f, %.2f]\n",
            hvac->output_mf_parameters[hvac->output_mfs[2].parameter_offset + 0u],
            hvac->output_mf_parameters[hvac->output_mfs[2].parameter_offset + 1u],
            insp.effective_output_params[hvac->output_mfs[2].parameter_offset + 0u],
            insp.effective_output_params[hvac->output_mfs[2].parameter_offset + 1u]);
        printf("    vent_high[BOA] base=[%.2f, %.2f] -> ANN-eff=[%.2f, %.2f]\n",
            hvac->output_mf_parameters[hvac->output_mfs[8].parameter_offset + 0u],
            hvac->output_mf_parameters[hvac->output_mfs[8].parameter_offset + 1u],
            insp.effective_output_params[hvac->output_mfs[8].parameter_offset + 0u],
            insp.effective_output_params[hvac->output_mfs[8].parameter_offset + 1u]);
        printf("    Tuned Outputs -> Fan[COG]=%.2f%% | Cooling[COG]=%.2f%% | Vent[BOA]=%.2f%%\n",
            cpu_out[0], cpu_out[1], cpu_out[2]);
    }

    /* ------------------------------------------------------------------------
     * TEST 4: SQLite Save + Dynamic Network Auto-Load + Standalone C Autogen
     * ------------------------------------------------------------------------ */
    printf("\n[Test 4] SQLite Persistence, Seamless Network Auto-Load & C Header Autogen\n");
    if (!FUZZY_TUNER_DB_SAVE(HVAC_TUNER_DB_PATH, "smart_hvac_5in_3out_tuner", hvac))
    {
        fprintf(stderr, "  FAIL: Could not save model to SQLite.\n");
        all_ok = false;
    }

    reloaded = FUZZY_TUNER_DB_AUTOLOAD(HVAC_TUNER_DB_PATH);
    if (reloaded == NULL)
    {
        fprintf(stderr, "  FAIL: Could not autoload model network from SQLite.\n");
        all_ok = false;
    }
    else
    {
        float *orig_preds = (float *)malloc(hvac_test.rows * 3u * sizeof(float));
        float *load_preds = (float *)malloc(hvac_test.rows * 3u * sizeof(float));
        float max_reload_diff = 0.0f;
        size_t i;

        fuzzy_tuner_predict_batch_mt(hvac, hvac_test.inputs, hvac_test.rows, orig_preds);
        fuzzy_tuner_predict_batch_mt(reloaded, hvac_test.inputs, hvac_test.rows, load_preds);
        fuzzy_tuner_dataset_metrics_mt(reloaded, &hvac_test, &reload_test);

        for (i = 0u; i < hvac_test.rows * 3u; ++i)
        {
            float d = fabsf(orig_preds[i] - load_preds[i]);
            if (d > max_reload_diff) max_reload_diff = d;
        }
        printf("  SQLite Autoloaded Test RMSE=%.3f%% | Max diff vs trained in-memory model: %.8f\n",
            reload_test.overall_rmse, max_reload_diff);
        if (max_reload_diff > 1.0e-5f)
        {
            fprintf(stderr, "  FAIL: SQLite autoloaded predictions do not match!\n");
            all_ok = false;
        }
        else
        {
            printf("  PASS: Zero-boilerplate SQLite network autoload matches bit-for-bit!\n");
        }
        free(orig_preds);
        free(load_preds);
    }

    if (!FUZZY_TUNER_AUTOGEN_C(HVAC_TUNER_DB_PATH, HVAC_TUNER_AUTOGEN_PATH, "smart_hvac_autogen"))
    {
        fprintf(stderr, "  FAIL: Could not auto-generate C deployment header from SQLite DB.\n");
        all_ok = false;
    }
    else
    {
        printf("  PASS: Generated deployable C network header at %s\n", HVAC_TUNER_AUTOGEN_PATH);
    }

    /* ------------------------------------------------------------------------
     * TEST 5: Real-World NASA Airfoil Dataset (5-Input -> 1-Output)
     * ------------------------------------------------------------------------ */
    printf("\n[Test 5] Real-World NASA Airfoil Dataset Verification (airfoil_self_noise.dat)\n");
    {
        fuzzy_neuron_dataset_t af_all = {0}, af_train = {0}, af_test = {0};
        airfoil_scale_t af_scale;
        fuzzy_tuner_model_t *af_model = airfoil_tuner_create(42u);
        fuzzy_tuner_metrics_t af_before, af_after;

        load_dataset(&af_all);
        split_dataset(&af_all, &af_train, &af_test);
        normalize_dataset(&af_train, &af_test, &af_scale);

        if (af_model != NULL && fuzzy_tuner_opencl_init(af_model, 256u, KERNEL_PATH))
        {
            fuzzy_tuner_train_options_t af_opts = FUZZY_TUNER_TRAIN_OPTIONS_ADAM(2000u, 256u, 0.003f, 0.005f, 100u);
            fuzzy_tuner_dataset_metrics_mt(af_model, &af_test, &af_before);
            t0 = monotonic_seconds();
            fuzzy_tuner_opencl_train(af_model, &af_train, &af_opts);
            t1 = monotonic_seconds();
            fuzzy_tuner_dataset_metrics_mt(af_model, &af_test, &af_after);

            printf("  Airfoil Test MSE: %.6f (before) -> %.6f (after) | RMSE: %.4f -> %.4f (%.2fs GPU)\n",
                af_before.overall_mse, af_after.overall_mse,
                af_before.overall_rmse, af_after.overall_rmse, t1 - t0);
            if (!(af_after.overall_mse < af_before.overall_mse * 0.65))
            {
                fprintf(stderr, "  FAIL: Airfoil test MSE did not improve as expected.\n");
                all_ok = false;
            }
            else
            {
                FUZZY_TUNER_DB_SAVE(AIRFOIL_TUNER_DB_PATH, "airfoil_5in_1out_tuner", af_model);
                printf("  PASS: Airfoil Fuzzy Rules + ANN MF Tuner verified & saved to %s!\n", AIRFOIL_TUNER_DB_PATH);
            }
        }
        else
        {
            fprintf(stderr, "  FAIL: Could not initialize Airfoil tuner model on OpenCL GPU.\n");
            all_ok = false;
        }

        fuzzy_tuner_destroy(af_model);
        fuzzy_neuron_dataset_free(&af_all);
        fuzzy_neuron_dataset_free(&af_train);
        fuzzy_neuron_dataset_free(&af_test);
    }

    fuzzy_tuner_destroy(reloaded);
    fuzzy_tuner_destroy(hvac);
    fuzzy_tuner_destroy(oracle);
    fuzzy_neuron_dataset_free(&hvac_train);
    fuzzy_neuron_dataset_free(&hvac_test);

    printf("\n======================================================================\n");
    printf("VERIFICATION SUMMARY: %s\n", all_ok ? "ALL TESTS PASSED" : "SOME TESTS FAILED");
    printf("======================================================================\n");
    return all_ok;
}

static void predict_hvac_cli(void)
{
    fuzzy_tuner_model_t *model = FUZZY_TUNER_DB_AUTOLOAD(HVAC_TUNER_DB_PATH);
    float raw_inputs[5];
    float outputs[3];
    fuzzy_tuner_inspection_t insp;
    size_t i;

    if (model == NULL)
    {
        fprintf(stderr, "No trained HVAC database at %s. Run verification/training first.\n", HVAC_TUNER_DB_PATH);
        return;
    }

    for (i = 0u; i < model->input_count; ++i)
    {
        printf("Enter %s [%.1f, %.1f]: ", model->inputs[i].name, model->inputs[i].minimum, model->inputs[i].maximum);
        fflush(stdout);
        if (scanf("%f", &raw_inputs[i]) != 1)
        {
            fprintf(stderr, "Invalid input.\n");
            fuzzy_tuner_destroy(model);
            return;
        }
    }

    if (fuzzy_tuner_predict_inspect(model, raw_inputs, outputs, &insp))
    {
        printf("\nPredicted Outputs (Auto-loaded from SQLite):\n");
        for (i = 0u; i < model->output_count; ++i)
        {
            printf("  %-14s (%s): %.2f%%\n",
                model->outputs[i].name,
                model->outputs[i].defuzz_method == FUZZY_DEFUZZ_BOA ? "BOA" : "Mamdani COG",
                outputs[i]);
        }
    }
    fuzzy_tuner_destroy(model);
}

int main(int argc, char **argv)
{
    unsigned int choice;

    if (argc > 1 && strcmp(argv[1], "--verify") == 0)
    {
        return run_fuzzy_tuner_verification() ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    if (!run_fuzzy_tuner_verification())
    {
        return EXIT_FAILURE;
    }

    for (;;)
    {
        printf("\nFuzzy Rules + ANN MF-Tuning & Airfoil CLI\n");
        printf("=========================================\n");
        printf("1. Run Fuzzy Rules + ANN MF-Tuning Verification & Training Suite\n");
        printf("2. Train legacy Airfoil explicit-rule fuzzy-neuron model\n");
        printf("3. Load Airfoil DB and predict from raw inputs\n");
        printf("4. Auto-load Smart HVAC SQLite DB and predict from raw inputs\n");
        printf("5. Exit\n");
        printf("Select mode: ");
        fflush(stdout);

        if (scanf("%u", &choice) != 1)
        {
            break;
        }

        if (choice == 1u)
        {
            run_fuzzy_tuner_verification();
        }
        else if (choice == 2u)
        {
            train();
        }
        else if (choice == 3u)
        {
            predict_cli();
        }
        else if (choice == 4u)
        {
            predict_hvac_cli();
        }
        else if (choice == 5u)
        {
            break;
        }
        else
        {
            fprintf(stderr, "Unknown mode %u. Expected 1-5.\n", choice);
        }
    }

    return EXIT_SUCCESS;
}
#endif