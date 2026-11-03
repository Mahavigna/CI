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

#define FUZZY_MODEL_PLUGIN_ABI 1u
#define OUTPUT_DIR "fuzzy-neuron-output"
#define DEFAULT_PLUGIN "./fuzzy_model_rules.so"
#define DEFAULT_TRAIN_DATASET "sugeno/sugeno_complex_sweep.csv"
#define DEFAULT_MODEL OUTPUT_DIR "/fuzzy_neuron_model.csv"
#define DEFAULT_KERNEL "fuzzy_neuron_kernels.cl"
#define DEFAULT_TEST_OUTPUT OUTPUT_DIR "/fuzzy_neuron_test_predictions.csv"
#define DEFAULT_ORIGINAL_OUTPUT OUTPUT_DIR "/fuzzy_neuron_original_predictions.csv"
#define FUZZY_MODEL_EXPORT __attribute__((visibility("default")))

typedef struct fuzzy_model_plugin
{
    unsigned int abi_version;
    const char *name;
    fuzzy_neuron_network_t *(*create)(void);
    void (*destroy)(fuzzy_neuron_network_t *model);
} fuzzy_model_plugin_t;

typedef const fuzzy_model_plugin_t *(*fuzzy_model_plugin_entry_fn)(void);

typedef struct loaded_plugin
{
    void *library;
    const fuzzy_model_plugin_t *api;
} loaded_plugin_t;

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

static fuzzy_neuron_network_t *plot_model;

static fuzzy_neuron_network_t *create_fuzzy_model(void)
{
    fuzzy_neuron_network_t *model = malloc(sizeof(*model));

    fuzzy_neuron_init(model, 3u, 1u);
    FUZZY_NEURON_BIND((*model), idle);
    FUZZY_NEURON_BIND((*model), economy);
    FUZZY_NEURON_BIND((*model), balanced);
    FUZZY_NEURON_BIND((*model), cooling);
    FUZZY_NEURON_BIND((*model), heavy_load);
    FUZZY_NEURON_BIND((*model), protection);
    FUZZY_NEURON_LAYER((*model), 10u, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_LAYER((*model), 10u, FUZZY_NEURON_SIGMOID);
    FUZZY_NEURON_OUTPUT((*model), FUZZY_NEURON_LINEAR);
    fuzzy_neuron_compile(model);

    return model;
}

static void destroy_fuzzy_model(fuzzy_neuron_network_t *model)
{
    fuzzy_neuron_free(model);
    free(model);
}

FUZZY_MODEL_EXPORT const fuzzy_model_plugin_t *fuzzy_model_plugin_entry(void)
{
    static const fuzzy_model_plugin_t plugin = {FUZZY_MODEL_PLUGIN_ABI, "temperature-load-vibration", create_fuzzy_model, destroy_fuzzy_model};

    return &plugin;
}

#ifndef FUZZY_MODEL_PLUGIN_ONLY

static loaded_plugin_t load_plugin(void)
{
    loaded_plugin_t plugin;
    fuzzy_model_plugin_entry_fn entry;

    plugin.library = dlopen(DEFAULT_PLUGIN, RTLD_NOW | RTLD_LOCAL);
    *(void **)(&entry) = dlsym(plugin.library, "fuzzy_model_plugin_entry");
    plugin.api = entry();

    return plugin;
}

static void unload_plugin(loaded_plugin_t *plugin)
{
    dlclose(plugin->library);
}

static fuzzy_neuron_csv_t csv_format(void)
{
    static const float input_scales[3] = {1.0f, 1.0f, 1.0f};
    static const float target_scales[1] = {255.0f};
    fuzzy_neuron_csv_t csv = {3u, 1u, true, ',', input_scales, target_scales};

    return csv;
}

static float evaluate_trained_model(const float inputs[], size_t input_count, float step)
{
    float output[1];

    (void)input_count;
    (void)step;

    fuzzy_neuron_predict(plot_model, inputs, output);

    return output[0] * 255.0f;
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
    loaded_plugin_t plugin = load_plugin();
    fuzzy_neuron_network_t *model = plugin.api->create();
    fuzzy_neuron_train_options_t options;
    unsigned int epochs;
    unsigned int batch_size;
    unsigned int report_interval;
    float learning_rate;

    printf("Epochs: ");
    scanf("%u", &epochs);

    printf("Batch size: ");
    scanf("%u", &batch_size);

    printf("Learning rate: ");
    scanf("%f", &learning_rate);

    printf("Report interval: ");
    scanf("%u", &report_interval);

    options = FUZZY_NEURON_TRAIN_OPTIONS(epochs, batch_size, learning_rate, report_interval);

    system("mkdir -p " OUTPUT_DIR);

    printf("\nTraining configuration\n");
    printf("Epochs: %u\n", epochs);
    printf("Batch size: %u\n", batch_size);
    printf("Learning rate: %.9f\n", learning_rate);
    printf("Report interval: %u\n", report_interval);
    printf("Dataset: %s\n", DEFAULT_TRAIN_DATASET);
    printf("Kernel: %s\n", DEFAULT_KERNEL);
    printf("Model output: %s\n\n", DEFAULT_MODEL);

    fuzzy_neuron_dataset_load_csv(DEFAULT_TRAIN_DATASET, &csv, &dataset);

    printf("Training samples: %u\n", (unsigned int)dataset.rows);
    printf("Input dimensions: %u\n", (unsigned int)dataset.input_dimensions);
    printf("Target dimensions: %u\n", (unsigned int)dataset.target_dimensions);
    printf("Batches per epoch: %u\n", (unsigned int)((dataset.rows + options.batch_size - 1u) / options.batch_size));
    printf("Training backend: OpenCL GPU mini-batch\n");

    if (!fuzzy_neuron_opencl_init(model, options.batch_size, DEFAULT_KERNEL))
    {
        fprintf(stderr, "OpenCL GPU initialization failed\n");
        exit(EXIT_FAILURE);
    }

    if (!model->opencl.ready)
    {
        fprintf(stderr, "OpenCL GPU backend is not ready\n");
        exit(EXIT_FAILURE);
    }

    if (!fuzzy_neuron_opencl_train(model, &dataset, &options))
    {
        fprintf(stderr, "OpenCL GPU mini-batch training failed\n");
        exit(EXIT_FAILURE);
    }

    fuzzy_neuron_model_save_csv(model, DEFAULT_MODEL);
    generate_model_plots(model);

    printf("\nTraining complete\n");
    printf("Backend: OpenCL GPU mini-batch\n");
    printf("Model: %s\n", DEFAULT_MODEL);
    printf("Training samples: %u\n", (unsigned int)dataset.rows);
    printf("Batch size: %u\n", (unsigned int)options.batch_size);
    printf("Batches per epoch: %u\n", (unsigned int)((dataset.rows + options.batch_size - 1u) / options.batch_size));
    printf("Plots: %s/\n", OUTPUT_DIR);

    fuzzy_neuron_dataset_free(&dataset);
    plugin.api->destroy(model);
    unload_plugin(&plugin);
}

static void run_input(void)
{
    loaded_plugin_t plugin = load_plugin();
    fuzzy_neuron_network_t *model = plugin.api->create();
    float input[3];
    float output[1];

    fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL);

    printf("Temperature Load Vibration: ");
    scanf("%f %f %f", &input[0], &input[1], &input[2]);

    fuzzy_neuron_predict(model, input, output);

    printf("Input: %.6f %.6f %.6f\n", input[0], input[1], input[2]);
    printf("Normalized output: %.9f\n", output[0]);
    printf("Scaled output: %.6f\n", output[0] * 255.0f);

    plugin.api->destroy(model);
    unload_plugin(&plugin);
}

static void test_dataset(const char *dataset_path, const char *predictions_path)
{
    fuzzy_neuron_csv_t csv = csv_format();
    fuzzy_neuron_dataset_t dataset = {0};
    loaded_plugin_t plugin = load_plugin();
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
        float expected = dataset.targets[row] * 255.0f;
        float predicted;
        float error;
        double magnitude;

        fuzzy_neuron_predict(model, input, output);

        predicted = output[0] * 255.0f;
        error = predicted - expected;
        magnitude = fabs((double)error);

        squared_error += (double)error * error;
        absolute_error += magnitude;

        if (magnitude > maximum_error)
        {
            maximum_error = magnitude;
        }

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
    unload_plugin(&plugin);
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

        if (choice == 1)
        {
            train_model();
        }

        if (choice == 2)
        {
            run_input();
        }

        if (choice == 3)
        {
            test_new_dataset();
        }

        if (choice == 4)
        {
            test_dataset(DEFAULT_TRAIN_DATASET, DEFAULT_ORIGINAL_OUTPUT);
        }
    }
}

int main(void)
{
    system("mkdir -p " OUTPUT_DIR);
    menu();

    return 0;
}

#endif