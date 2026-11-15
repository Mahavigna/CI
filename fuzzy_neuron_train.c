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
#define TRAIN_EPOCHS 1000u
#define TRAIN_BATCH_SIZE 128u
#define TRAIN_REPORT_INTERVAL 10u
#define TRAIN_LEARNING_RATE 0.001f
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

int main(void)
{
    unsigned int choice;

    for (;;)
    {
        printf("\nAirfoil Explicit-Rule Fuzzy-Neuron CLI\n");
        printf("=======================================\n");
        printf("1. Train or continue training\n");
        printf("2. Load database and predict from raw inputs\n");
        printf("3. Exit\n");
        printf("Select mode: ");
        fflush(stdout);

        if (scanf("%u", &choice) != 1)
        {
            fprintf(stderr, "Invalid mode selection.\n");
            return EXIT_FAILURE;
        }

        if (choice == 1u)
        {
            train();
        }
        else if (choice == 2u)
        {
            predict_cli();
        }
        else if (choice == 3u)
        {
            break;
        }
        else
        {
            fprintf(stderr, "Unknown mode %u. Expected 1, 2, or 3.\n", choice);
        }
    }

    return EXIT_SUCCESS;
}
#endif