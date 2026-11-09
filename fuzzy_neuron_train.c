#define _GNU_SOURCE
#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_OPENCL
#define FUZZY_SQLITE
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
#define TRAIN_REPORT_INTERVAL 100u
#define TRAIN_LEARNING_RATE 0.000006f
#define TRAIN_ADAM_BETA1 0.9f
#define TRAIN_ADAM_BETA2 0.999f
#define TRAIN_ADAM_EPSILON 0.00000001f
#define HIDDEN_WIDTH 64u
#define INTERPOLATION_STEP 0.10f

/* PART 1: USER-SPECIFIC DATA AND MODEL SEMANTICS */
typedef struct airfoil_scale
{
    float input_minimum[INPUT_DIMENSIONS];
    float input_maximum[INPUT_DIMENSIONS];
    float target_minimum;
    float target_maximum;
} airfoil_scale_t;

FUZZY_NEURON_PARAMETERS(airfoil_low_parameters, 0.25f, 0.30f);
FUZZY_NEURON_PARAMETERS(airfoil_high_parameters, 0.75f, 0.30f);
FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(airfoil_low_membership, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, airfoil_low_parameters);
FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(airfoil_high_membership, FUZZY_SHAPE_GAUSSIAN, 1.0f, 0x3u, 0.0f, 1.0f, airfoil_high_parameters);

/* PART 2: FUZZY.H MODEL DSL */
FUZZY_NEURON_LAYERS(
    airfoil_layers,
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_LAYER_ENTRY(HIDDEN_WIDTH, FUZZY_NEURON_TANH),
    FUZZY_NEURON_OUTPUT_ENTRY(OUTPUT_CONSEQUENT_COUNT, FUZZY_NEURON_SIGMOID)
);

FUZZY_NEURON_BINARY_MODEL(
    airfoil_model,
    INPUT_DIMENSIONS,
    OUTPUT_CONSEQUENT_COUNT,
    FUZZY_LOGIC_STANDARD,
    airfoil_low_membership,
    airfoil_high_membership,
    airfoil_layers,
    "frequency",
    "attack",
    "chord",
    "velocity",
    "displacement"
)

FUZZY_NEURON_MODEL_PLUGIN(airfoil_model, FUZZY_MODEL_PLUGIN_ABI, "airfoil-self-noise-anfis", FUZZY_MODEL_EXPORT)

#ifndef FUZZY_MODEL_PLUGIN_ONLY
FUZZY_NEURON_HOT_RELOAD(airfoil_plugin, DEFAULT_PLUGIN)

static float airfoil_output_parameters[OUTPUT_CONSEQUENT_COUNT][2] =
{
    {0.15f, 0.20f},
    {0.50f, 0.20f},
    {0.85f, 0.20f}
};

static float airfoil_output_membership(size_t membership, float value)
{
    float difference = (value - airfoil_output_parameters[membership][0]) / airfoil_output_parameters[membership][1];
    return expf(-0.5f * difference * difference);
}

static float airfoil_output_low(float value) { return airfoil_output_membership(0u, value); }
static float airfoil_output_medium(float value) { return airfoil_output_membership(1u, value); }
static float airfoil_output_high(float value) { return airfoil_output_membership(2u, value); }

FUZZY_NEURON_OUTPUT_PIPELINE(airfoil_output, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, OUTPUT_STEP, airfoil_output_low, airfoil_output_medium, airfoil_output_high);
FUZZY_NEURON_MODEL_DATABASE(airfoil_database, MODEL_DATABASE_PATH, "airfoil-self-noise-anfis", airfoil_output, INPUT_DIMENSIONS);

#define RESPONSE_VOLTAGE_MINIMUM 0.0f
#define RESPONSE_VOLTAGE_MAXIMUM 5.0f
#define RESPONSE_VOLTAGE_STEP 0.01f

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

/* PART 3: MINIMAL USER CALLBACKS AND APPLICATION FLOW */
static void load_dataset(fuzzy_neuron_dataset_t *dataset)
{
    FILE *file = fopen(DATASET_PATH, "r");
    size_t row;
    if (file == NULL) { fprintf(stderr, "Failed to open %s.\n", DATASET_PATH); exit(EXIT_FAILURE); }
    FUZZY_NEURON_DATASET_ALLOCATE(*dataset, DATASET_ROWS, INPUT_DIMENSIONS, OUTPUT_DIMENSIONS);
    if (dataset->inputs == NULL || dataset->targets == NULL) { fclose(file); fprintf(stderr, "Dataset allocation failed.\n"); exit(EXIT_FAILURE); }
    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        float *input = dataset->inputs + row * INPUT_DIMENSIONS;
        if (fscanf(file, "%f %f %f %f %f %f", &input[0], &input[1], &input[2], &input[3], &input[4], &dataset->targets[row]) != 6)
        { fclose(file); fprintf(stderr, "Invalid dataset row %zu.\n", row); exit(EXIT_FAILURE); }
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

static void normalize_dataset(fuzzy_neuron_dataset_t *training, fuzzy_neuron_dataset_t *test, airfoil_scale_t *scale)
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
    *plugin = airfoil_plugin_load();
    if (plugin->api == NULL || plugin->api->create == NULL || (model = plugin->api->create()) == NULL) { fprintf(stderr, "Failed to create fuzzy-neuron plugin model.\n"); exit(EXIT_FAILURE); }
    return model;
}

static float predict_scalar(fuzzy_neuron_network_t *model, const float inputs[])
{
    float activations[OUTPUT_CONSEQUENT_COUNT];
    if (!fuzzy_neuron_predict(model, inputs, activations)) { fprintf(stderr, "Prediction failed.\n"); exit(EXIT_FAILURE); }
    return fuzzy_neuron_output_decode(&airfoil_output, activations);
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
    return PLOT(OUTPUT_DIR "/airfoil_output_final_memberships", "Mamdani Output Memberships", OUTPUT_MAXIMUM, OUTPUT_STEP, SERIES(airfoil_output_low, "#3b82f6"), SERIES(airfoil_output_medium, "#22c55e"), SERIES(airfoil_output_high, "#ef4444"));
}

static bool plot_final_memberships(fuzzy_neuron_network_t *model)
{
    if (model == NULL || !model->compiled || model->premise_count != INPUT_DIMENSIONS * 2u) return false;
    airfoil_visual_model = model;
    if (!PLOT(OUTPUT_DIR "/airfoil_frequency_final_memberships", "Final Trained Frequency Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_frequency_low_final, "#3b82f6"), SERIES(airfoil_frequency_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_attack_final_memberships", "Final Trained Attack Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_attack_low_final, "#3b82f6"), SERIES(airfoil_attack_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_chord_final_memberships", "Final Trained Chord Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_chord_low_final, "#3b82f6"), SERIES(airfoil_chord_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_velocity_final_memberships", "Final Trained Velocity Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_velocity_low_final, "#3b82f6"), SERIES(airfoil_velocity_high_final, "#ef4444"))) return false;
    if (!PLOT(OUTPUT_DIR "/airfoil_displacement_final_memberships", "Final Trained Displacement Memberships", 1.0f, OUTPUT_STEP, SERIES(airfoil_displacement_low_final, "#3b82f6"), SERIES(airfoil_displacement_high_final, "#ef4444"))) return false;
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

    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(
        TRAINING_SWEEP_PATH,
        "Airfoil Training Data",
        training_points,
        OUTPUT_MINIMUM,
        OUTPUT_MAXIMUM,
        FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP)
    )) return false;

    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(
        MODEL_SWEEP_PATH,
        "Airfoil Model Output",
        model_points,
        OUTPUT_MINIMUM,
        OUTPUT_MAXIMUM,
        FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP)
    )) return false;

    if (!FUZZY_NEURON_INTERPOLATION_SWEEP(
        TEST_SWEEP_PATH,
        "Airfoil Test Data",
        test_points,
        OUTPUT_MINIMUM,
        OUTPUT_MAXIMUM,
        FUZZY_SWEEP_DIMENSION("frequency", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("attack", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("chord", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("velocity", 0.0f, 1.0f, INTERPOLATION_STEP),
        FUZZY_SWEEP_DIMENSION("displacement", 0.0f, 1.0f, INTERPOLATION_STEP)
    )) return false;

    return true;
}

static void write_outputs(fuzzy_neuron_network_t *model, size_t best_epoch, double final_mse)
{
    FILE *file = fopen(OUTPUT_MEMBERSHIP_PATH, "w");
    size_t index;
    if (file == NULL) { fprintf(stderr, "Failed to write output memberships.\n"); exit(EXIT_FAILURE); }
    fprintf(file, "membership,shape,hedge,mean,sigma\n");
    fprintf(file, "low,gaussian,1,%.9g,%.9g\n", airfoil_output_parameters[0][0], airfoil_output_parameters[0][1]);
    fprintf(file, "medium,gaussian,1,%.9g,%.9g\n", airfoil_output_parameters[1][0], airfoil_output_parameters[1][1]);
    fprintf(file, "high,gaussian,1,%.9g,%.9g\n", airfoil_output_parameters[2][0], airfoil_output_parameters[2][1]);
    fprintf(file, "calibration,affine,1,%.9g,%.9g\n", airfoil_output.gain, airfoil_output.bias);
    fclose(file);

    file = fopen(LOSS_PATH, "w");
    if (file == NULL) { fprintf(stderr, "Failed to write loss history.\n"); exit(EXIT_FAILURE); }
    fprintf(file, "epoch,mse,mse_over_initial\n");
    for (index = 0u; index < airfoil_history.count; ++index) fprintf(file, "%zu,%.12g,%.12g\n", airfoil_history.epochs[index], airfoil_history.losses[index], airfoil_history.losses[index] / airfoil_history.initial_loss);
    fclose(file);
    PLOT(LOSS_PLOT_PATH, "Airfoil Training MSE Relative to Initial MSE", (float)TRAIN_EPOCHS, (float)TRAIN_REPORT_INTERVAL, SERIES(loss_plot_function, "#dc2626"));
    if (!FUZZY_NEURON_MODEL_SAVE(model, MODEL_PATH)) { fprintf(stderr, "Model save failed.\n"); exit(EXIT_FAILURE); }
    printf("best_scalar_epoch=%zu\noutput_gain=%.12g\noutput_bias=%.12g\ntraining_mse_final=%.12g\n", best_epoch, airfoil_output.gain, airfoil_output.bias, final_mse);
}

static float response_voltage(const float activations[OUTPUT_CONSEQUENT_COUNT])
{
    fuzzy_rules_t rules;
    float voltage;

    rules.count = 0u;

    if (!FUZZY_RULE_ADD(&rules, activations[0], response_voltage_low) ||
        !FUZZY_RULE_ADD(&rules, activations[1], response_voltage_medium) ||
        !FUZZY_RULE_ADD(&rules, activations[2], response_voltage_high))
    {
        fprintf(stderr, "Failed to bind deployment voltage response rules.\n");
        exit(EXIT_FAILURE);
    }

    voltage = fuzzy_rules_defuzzify(
        &rules,
        RESPONSE_VOLTAGE_MINIMUM,
        RESPONSE_VOLTAGE_MAXIMUM,
        RESPONSE_VOLTAGE_STEP,
        FUZZY_DEFUZZ_COG
    );

    if (!isfinite(voltage))
    {
        fprintf(stderr, "Deployment voltage COG is not finite.\n");
        exit(EXIT_FAILURE);
    }

    return voltage;
}

static void read_cli_float(const char *prompt, float *value)
{
    int result;

    if (prompt == NULL || value == NULL)
    {
        fprintf(stderr, "Invalid CLI input request.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", prompt);
    fflush(stdout);
    result = scanf("%f", value);

    if (result != 1 || !isfinite(*value))
    {
        fprintf(stderr, "Invalid numeric input.\n");
        exit(EXIT_FAILURE);
    }
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

    static const char *input_prompts[INPUT_DIMENSIONS] =
    {
        "Enter frequency: ",
        "Enter angle of attack: ",
        "Enter chord length: ",
        "Enter free-stream velocity: ",
        "Enter suction-side displacement thickness: "
    };

    fuzzy_neuron_loaded_plugin_t plugin = {0};
    fuzzy_neuron_network_t *model;
    airfoil_scale_t scale;
    float raw_inputs[INPUT_DIMENSIONS];
    float normalized_inputs[INPUT_DIMENSIONS];
    float output_activations[OUTPUT_CONSEQUENT_COUNT];
    float raw_cog;
    float calibrated_cog;
    float physical_output;
    float voltage;
    size_t dimension;

    if (!FUZZY_NEURON_MODEL_DATABASE_EXISTS(airfoil_database))
    {
        fprintf(stderr, "No trained model database exists at %s. Train the model first.\n", MODEL_DATABASE_PATH);
        exit(EXIT_FAILURE);
    }

    model = load_plugin(&plugin);

    FUZZY_NEURON_MODEL_DATABASE_LOAD(
        airfoil_database,
        model,
        scale.input_minimum,
        scale.input_maximum,
        scale.target_minimum,
        scale.target_maximum
    );

    printf("\nAirfoil deployment input\n");
    printf("========================\n");

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        read_cli_float(input_prompts[dimension], &raw_inputs[dimension]);

        if (!(scale.input_maximum[dimension] > scale.input_minimum[dimension]))
        {
            fprintf(stderr, "Saved normalization range for %s is invalid.\n", input_names[dimension]);
            exit(EXIT_FAILURE);
        }

        normalized_inputs[dimension] =
            (raw_inputs[dimension] - scale.input_minimum[dimension]) /
            (scale.input_maximum[dimension] - scale.input_minimum[dimension]);

        if (normalized_inputs[dimension] < 0.0f || normalized_inputs[dimension] > 1.0f)
        {
            fprintf(
                stderr,
                "Input %s=%.9g is outside the trained range [%.9g, %.9g].\n",
                input_names[dimension],
                raw_inputs[dimension],
                scale.input_minimum[dimension],
                scale.input_maximum[dimension]
            );
            exit(EXIT_FAILURE);
        }
    }

    if (!fuzzy_neuron_predict(model, normalized_inputs, output_activations))
    {
        fprintf(stderr, "Fuzzy-neuron deployment prediction failed.\n");
        exit(EXIT_FAILURE);
    }

    raw_cog = fuzzy_neuron_output_decode_raw(&airfoil_output, output_activations);
    calibrated_cog = fuzzy_neuron_output_decode(&airfoil_output, output_activations);

    if (!isfinite(raw_cog) || !isfinite(calibrated_cog))
    {
        fprintf(stderr, "Deployment COG output is not finite.\n");
        exit(EXIT_FAILURE);
    }

    physical_output =
        scale.target_minimum +
        calibrated_cog * (scale.target_maximum - scale.target_minimum);

    voltage = response_voltage(output_activations);

    printf("\nNormalized inputs and trained memberships\n");
    printf("=========================================\n");

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        float low_membership = fuzzy_neuron_evaluate_premise(model, dimension * 2u, normalized_inputs);
        float high_membership = fuzzy_neuron_evaluate_premise(model, dimension * 2u + 1u, normalized_inputs);

        printf(
            "%s raw=%.9g normalized=%.9g low=%.9g high=%.9g\n",
            input_names[dimension],
            raw_inputs[dimension],
            normalized_inputs[dimension],
            low_membership,
            high_membership
        );
    }

    printf("\nModel response\n");
    printf("==============\n");
    printf("output_low_activation=%.9g\n", output_activations[0]);
    printf("output_medium_activation=%.9g\n", output_activations[1]);
    printf("output_high_activation=%.9g\n", output_activations[2]);
    printf("raw_normalized_cog=%.9g\n", raw_cog);
    printf("calibrated_normalized_cog=%.9g\n", calibrated_cog);
    printf("predicted_sound_pressure_level=%.9g\n", physical_output);
    printf("response_voltage=%.9g V\n", voltage);

    plugin.api->destroy(model);
    airfoil_plugin_unload(&plugin);
}

static void train(void)
{
    fuzzy_neuron_dataset_t complete = {0}, training = {0}, test = {0}, encoded = {0};
    fuzzy_neuron_loaded_plugin_t plugin = {0};
    fuzzy_neuron_output_cache_t cache = {0};
    fuzzy_neuron_checkpoint_t checkpoint = {0};
    fuzzy_neuron_network_t *model;
    airfoil_scale_t scale;
    airfoil_scale_t saved_scale;
    bool resumed_from_database;
    size_t epoch = 0u, capacity = (TRAIN_EPOCHS + TRAIN_REPORT_INTERVAL - 1u) / TRAIN_REPORT_INTERVAL + 1u;
    double initial_mse, loss;

    load_dataset(&complete);
    split_dataset(&complete, &training, &test);
    normalize_dataset(&training, &test, &scale);
    model = load_plugin(&plugin);
    resumed_from_database = FUZZY_NEURON_MODEL_DATABASE_EXISTS(airfoil_database);
    if (resumed_from_database)
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
    if (!fuzzy_neuron_dataset_encode_targets(&encoded, &training, &airfoil_output)) { fprintf(stderr, "Target encoding failed.\n"); exit(EXIT_FAILURE); }
    initial_mse = dataset_metric(model, &training, false);
    if (!fuzzy_neuron_history_create(&airfoil_history, capacity, initial_mse) || !fuzzy_neuron_checkpoint_create(&checkpoint, model, sizeof(airfoil_output), initial_mse)) { fprintf(stderr, "Training state allocation failed.\n"); exit(EXIT_FAILURE); }
    fuzzy_neuron_checkpoint_capture(&checkpoint, model, &airfoil_output, 0u, initial_mse);
    fuzzy_neuron_history_push(&airfoil_history, 0u, initial_mse);
    if (!FUZZY_NEURON_MODEL_OPENCL_INIT(model, TRAIN_BATCH_SIZE, KERNEL_PATH) || !fuzzy_neuron_output_cache_create(&cache, training.rows, OUTPUT_CONSEQUENT_COUNT)) { fprintf(stderr, "OpenCL initialization failed.\n"); exit(EXIT_FAILURE); }

    while (epoch < TRAIN_EPOCHS)
    {
        size_t chunk = TRAIN_EPOCHS - epoch > TRAIN_REPORT_INTERVAL ? TRAIN_REPORT_INTERVAL : TRAIN_EPOCHS - epoch;
        fuzzy_neuron_train_options_t options = FUZZY_NEURON_TRAIN_OPTIONS_ADAM_CUSTOM(chunk, TRAIN_BATCH_SIZE, TRAIN_LEARNING_RATE, chunk, TRAIN_ADAM_BETA1, TRAIN_ADAM_BETA2, TRAIN_ADAM_EPSILON, false);
        if (!FUZZY_NEURON_MODEL_OPENCL_TRAIN(model, &encoded, &options, MSE)) { fprintf(stderr, "OpenCL training failed at epoch %zu.\n", epoch + chunk); exit(EXIT_FAILURE); }
        epoch += chunk;
        if (!fuzzy_neuron_output_cache_refresh(&cache, model, &training, &airfoil_output) || !fuzzy_neuron_output_fit_affine(&airfoil_output, &cache, training.targets)) { fprintf(stderr, "Output calibration failed.\n"); exit(EXIT_FAILURE); }
        loss = fuzzy_neuron_output_cache_mse(&airfoil_output, &cache, training.targets);
        if (loss < checkpoint.loss) fuzzy_neuron_checkpoint_capture(&checkpoint, model, &airfoil_output, epoch, loss);
        fuzzy_neuron_history_push(&airfoil_history, epoch, loss);
        printf("epoch=%zu mse=%.12g relative=%.12g gain=%.9g bias=%.9g best_epoch=%zu best_mse=%.12g\n", epoch, loss, loss / initial_mse, airfoil_output.gain, airfoil_output.bias, checkpoint.epoch, checkpoint.loss);
    }

    fuzzy_neuron_checkpoint_restore(&checkpoint, model, &airfoil_output);
    loss = dataset_metric(model, &training, false);
    write_outputs(model, checkpoint.epoch, loss);
    FUZZY_NEURON_MODEL_DATABASE_SAVE(airfoil_database, model, scale.input_minimum, scale.input_maximum, scale.target_minimum, scale.target_maximum);
    if (!plot_final_memberships(model)) { fprintf(stderr, "Failed to plot final trained memberships.\n"); exit(EXIT_FAILURE); }
    if (!plot_output_memberships()) { fprintf(stderr, "Failed to plot output memberships.\n"); exit(EXIT_FAILURE); }
    if (!plot_interpolation(model, &training, &test)) { fprintf(stderr, "Failed to generate interpolation sweeps.\n"); exit(EXIT_FAILURE); }
    printf("training_mse_initial=%.12g\ntest_mse=%.12g\ntest_mae=%.12g\n", initial_mse, dataset_metric(model, &test, false), dataset_metric(model, &test, true));

    fuzzy_neuron_output_cache_free(&cache);
    fuzzy_neuron_checkpoint_free(&checkpoint);
    fuzzy_neuron_history_free(&airfoil_history);
    fuzzy_neuron_dataset_free(&complete);
    fuzzy_neuron_dataset_free(&training);
    fuzzy_neuron_dataset_free(&test);
    fuzzy_neuron_dataset_free(&encoded);
    plugin.api->destroy(model);
    airfoil_plugin_unload(&plugin);
}

int main(void)
{
    unsigned int choice;

    printf("\nAirfoil Fuzzy-Neuron CLI\n");
    printf("========================\n");
    printf("1. Train or continue training\n");
    printf("2. Load database and predict from raw inputs\n");
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
    else
    {
        fprintf(stderr, "Unknown mode %u. Expected 1 or 2.\n", choice);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
#endif
