#define _GNU_SOURCE
#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_OPENCL
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#ifndef FUZZY_NEURON_OPENCL
#error FUZZY_NEURON_OPENCL must be enabled for this program
#endif

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FUZZY_MODEL_PLUGIN_ABI 2u
#define OUTPUT_DIR "fuzzy-neuron-output"
#define DEFAULT_PLUGIN "./fuzzy_model_rules.so"
#define DATASET_PATH OUTPUT_DIR "/airfoil_self_noise.dat"
#define MODEL_PATH OUTPUT_DIR "/airfoil_model.csv"
#define KERNEL_PATH "fuzzy_neuron_kernels.cl"
#define TRAINING_INTERPOLATION_PATH OUTPUT_DIR "/airfoil_training_interpolation"
#define MODEL_INTERPOLATION_PATH OUTPUT_DIR "/airfoil_model_interpolation"
#define TEST_INTERPOLATION_PATH OUTPUT_DIR "/airfoil_test_interpolation"
#define FUZZY_MODEL_EXPORT __attribute__((visibility("default")))

#define DATASET_ROWS 1503u
#define INPUT_DIMENSIONS 5u
#define OUTPUT_DIMENSIONS 1u
#define TRAIN_ROWS 1202u
#define TEST_ROWS 301u
#define SPLIT_SEED 42u
#define XAVIER_SEED 42u

#define TRAIN_EPOCHS 10000u
#define TRAIN_BATCH_SIZE 256u
#define TRAIN_LEARNING_RATE 0.0001f
#define TRAIN_REPORT_INTERVAL 25u
#define HIDDEN_WIDTH 16u
#define INTERPOLATION_STEP 0.10f

//User Setup
typedef struct airfoil_scale
{
    float input_minimum[INPUT_DIMENSIONS];
    float input_maximum[INPUT_DIMENSIONS];
    float target_minimum;
    float target_maximum;
} airfoil_scale_t; //User defines these themselves based on the dataset and normalization requirements

//Actual ANN setup via DSL macros
FUZZY_NEURON_PARAMETERS(airfoil_low_parameters, 0.25f, 0.30f);
FUZZY_NEURON_PARAMETERS(airfoil_high_parameters, 0.75f, 0.30f);

FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(airfoil_low_membership, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, airfoil_low_parameters);
FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(airfoil_high_membership, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, airfoil_high_parameters);

FUZZY_NEURON_LAYERS(
    airfoil_layers,
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_OUTPUT_ENTRY(OUTPUT_DIMENSIONS, FUZZY_NEURON_LINEAR)
);

FUZZY_NEURON_BINARY_MODEL(
    airfoil_model,
    INPUT_DIMENSIONS,
    OUTPUT_DIMENSIONS,
    FUZZY_LOGIC_STANDARD,
    airfoil_low_membership,
    airfoil_high_membership,
    airfoil_layers,
    "frequency",
    "attack",
    "chord",
    "velocity",
    "displacement"
);

//Extra functionality for plugin support, user can hold load model changes without full recompilation
FUZZY_NEURON_MODEL_PLUGIN(airfoil_model, FUZZY_MODEL_PLUGIN_ABI, "airfoil-self-noise-anfis", FUZZY_MODEL_EXPORT)

#ifndef FUZZY_MODEL_PLUGIN_ONLY

FUZZY_NEURON_HOT_RELOAD(airfoil_plugin, DEFAULT_PLUGIN)


//User Setup
static float normalize_value(float value, float minimum, float maximum)
{
    return (value - minimum) / (maximum - minimum);
}

//User Setup
static void load_dataset(fuzzy_neuron_dataset_t *dataset)
{
    FILE *file = fopen(DATASET_PATH, "r");
    size_t row;

    FUZZY_NEURON_DATASET_ALLOCATE(*dataset, DATASET_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);

    for (row = 0u; row < DATASET_ROWS; row++)
    {
        float *input = dataset->inputs + row * INPUT_DIMENSIONS;
        fscanf(file, "%f %f %f %f %f %f", &input[0], &input[1], &input[2], &input[3], &input[4], &dataset->targets[row]);
    }

    fclose(file);
}

//User Setup
static void split_dataset(const fuzzy_neuron_dataset_t *source, fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test)
{
    size_t order[DATASET_ROWS];
    unsigned int state = SPLIT_SEED;
    size_t row;

    FUZZY_NEURON_DATASET_ALLOCATE(*training, TRAIN_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);
    FUZZY_NEURON_DATASET_ALLOCATE(*test, TEST_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);

    for (row = 0u; row < DATASET_ROWS; row++)
    {
        order[row] = row;
    }

    for (row = DATASET_ROWS; row > 1u; row--)
    {
        size_t selected;
        size_t temporary;

        state = state * 1664525u + 1013904223u;
        selected = (size_t)state % row;
        temporary = order[row - 1u];
        order[row - 1u] = order[selected];
        order[selected] = temporary;
    }

    for (row = 0u; row < DATASET_ROWS; row++)
    {
        fuzzy_neuron_dataset_t *destination = row < TRAIN_ROWS ? training : test;
        size_t destination_row = row < TRAIN_ROWS ? row : row - TRAIN_ROWS;

        memcpy(destination->inputs + destination_row * INPUT_DIMENSIONS, source->inputs + order[row] * INPUT_DIMENSIONS, INPUT_DIMENSIONS * sizeof(float));
        destination->targets[destination_row] = source->targets[order[row]];
    }
}

//User Setup
static void normalize_dataset(fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test, airfoil_scale_t *scale)
{
    size_t dimension;
    size_t row;

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; dimension++)
    {
        scale->input_minimum[dimension] = training->inputs[dimension];
        scale->input_maximum[dimension] = training->inputs[dimension];
    }

    scale->target_minimum = training->targets[0];
    scale->target_maximum = training->targets[0];

    for (row = 0u; row < TRAIN_ROWS; row++)
    {
        for (dimension = 0u; dimension < INPUT_DIMENSIONS; dimension++)
        {
            float value = training->inputs[row * INPUT_DIMENSIONS + dimension];

            if (value < scale->input_minimum[dimension]) scale->input_minimum[dimension] = value;

            if (value > scale->input_maximum[dimension]) scale->input_maximum[dimension] = value;
        }

        if (training->targets[row] < scale->target_minimum) scale->target_minimum = training->targets[row];

        if (training->targets[row] > scale->target_maximum) scale->target_maximum = training->targets[row];
    }

    for (row = 0u; row < DATASET_ROWS; row++)
    {
        fuzzy_neuron_dataset_t *dataset = row < TRAIN_ROWS ? training : test;
        size_t local_row = row < TRAIN_ROWS ? row : row - TRAIN_ROWS;

        for (dimension = 0u; dimension < INPUT_DIMENSIONS; dimension++)
        {
            size_t index = local_row * INPUT_DIMENSIONS + dimension;
            dataset->inputs[index] = normalize_value(dataset->inputs[index], scale->input_minimum[dimension], scale->input_maximum[dimension]);
        }

        dataset->targets[local_row] = normalize_value(dataset->targets[local_row], scale->target_minimum, scale->target_maximum);
    }
}

static fuzzy_neuron_network_t *load_plugin(fuzzy_neuron_loaded_plugin_t *plugin)
{
    fuzzy_neuron_network_t *model;

    *plugin = airfoil_plugin_load();
    model = plugin->api->create();

    return model;
}

//User Setup
static void plot_interpolation(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *training, const fuzzy_neuron_dataset_t *test)
{
    fuzzy_point_t training_points[TRAIN_ROWS];
    fuzzy_point_t model_points[TRAIN_ROWS];
    fuzzy_point_t test_points[TEST_ROWS];
    float model_outputs[TRAIN_ROWS * OUTPUT_DIMENSIONS];

    FUZZY_NEURON_DATASET_POINTS(training_points, *training);
    FUZZY_NEURON_MODEL_POINTS(model_points, model, *training, model_outputs);
    FUZZY_NEURON_DATASET_POINTS(test_points, *test);

    FUZZY_INTERPOLATION_SWEEP(
            TRAINING_INTERPOLATION_PATH,
            "Airfoil Training Data",
            training_points,
            FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP)
        );

    FUZZY_INTERPOLATION_SWEEP(
            MODEL_INTERPOLATION_PATH,
            "Airfoil Model Output",
            model_points,
            FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP)
        );

    FUZZY_INTERPOLATION_SWEEP(
            TEST_INTERPOLATION_PATH,
            "Airfoil Test Data",
            test_points,
            FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP),
            FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP)
        );
}

//User Setup
static void train(void)
{
    fuzzy_neuron_dataset_t complete = {0};
    fuzzy_neuron_dataset_t training = {0};
    fuzzy_neuron_dataset_t test = {0};
    fuzzy_neuron_loaded_plugin_t plugin = {0};
    fuzzy_neuron_network_t *model;
    fuzzy_neuron_train_options_t options;
    airfoil_scale_t scale;
    double initial_mse;
    double final_mse;

    load_dataset(&complete);
    split_dataset(&complete, &training, &test);
    normalize_dataset(&training, &test, &scale);

    model = load_plugin(&plugin);
    FUZZY_NEURON_XAVIER_INIT(model, XAVIER_SEED);

    initial_mse = fuzzy_neuron_dataset_mse(model, &training);
    options = FUZZY_NEURON_TRAIN_OPTIONS_ADAM(TRAIN_EPOCHS, TRAIN_BATCH_SIZE, TRAIN_LEARNING_RATE, TRAIN_REPORT_INTERVAL);

    FUZZY_NEURON_MODEL_OPENCL_INIT(model, TRAIN_BATCH_SIZE, KERNEL_PATH);
    FUZZY_NEURON_MODEL_OPENCL_TRAIN(model, &training, &options, MSE);
    
    final_mse = fuzzy_neuron_dataset_mse(model, &training);

    FUZZY_NEURON_MODEL_SAVE(model, MODEL_PATH);

    plot_interpolation(model, &training, &test);

    printf("training_mse_initial=%.12g\n", initial_mse);
    printf("training_mse_final=%.12g\n", final_mse);
    printf("test_mse=%.12g\n", fuzzy_neuron_dataset_mse(model, &test));
    printf("test_mae=%.12g\n", fuzzy_neuron_dataset_mae(model, &test));

    fuzzy_neuron_dataset_free(&complete);
    fuzzy_neuron_dataset_free(&training);
    fuzzy_neuron_dataset_free(&test);

    plugin.api->destroy(model);
    airfoil_plugin_unload(&plugin);
}

int main(void)
{
    train();
    return EXIT_SUCCESS;
}

#endif