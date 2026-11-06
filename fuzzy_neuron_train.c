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

#define FUZZY_MODEL_PLUGIN_ABI 2u
#define OUTPUT_DIR "fuzzy-neuron-output"
#define DEFAULT_PLUGIN "./fuzzy_model_rules.so"
#define DEFAULT_TRAIN_DATASET "sugeno/sugeno_complex_sweep.csv"
#define DEFAULT_MODEL OUTPUT_DIR "/fuzzy_neuron_trainable_model.csv"
#define DEFAULT_KERNEL "fuzzy_neuron_kernels.cl"
#define DEFAULT_TEST_OUTPUT OUTPUT_DIR "/fuzzy_neuron_trainable_predictions.csv"
#define FUZZY_MODEL_EXPORT __attribute__((visibility("default")))
#define FIRST_HIDDEN 10u
#define SECOND_HIDDEN 10u
#define THIRD_HIDDEN 10u
#define SCALE 1.0f

FUZZY_NEURON_MODEL(fuzzy_model, 3u, 1u,
    FUZZY_NEURON_INPUT((*model), temperature, 0.0f, 100.0f, 1.0f);
    FUZZY_NEURON_INPUT((*model), load, 0.0f, 100.0f, 1.0f);
    FUZZY_NEURON_INPUT((*model), vibration, 0.0f, 10.0f, 0.1f);

    FUZZY_NEURON_PREMISE((*model), temperature_low, temperature, FUZZY_SHAPE_ZMF, 1.0f, 15.0f, 40.0f);
    FUZZY_NEURON_PREMISE((*model), temperature_high, temperature, FUZZY_SHAPE_SMF, 1.0f, 35.0f, 75.0f);
    FUZZY_NEURON_PREMISE((*model), load_low, load, FUZZY_SHAPE_ZMF, 1.0f, 20.0f, 50.0f);
    FUZZY_NEURON_PREMISE((*model), load_high, load, FUZZY_SHAPE_SMF, 1.0f, 45.0f, 85.0f);
    FUZZY_NEURON_PREMISE((*model), vibration_low, vibration, FUZZY_SHAPE_SIGMOID, 1.0f, -1.5f, 2.5f);
    FUZZY_NEURON_PREMISE((*model), vibration_high, vibration, FUZZY_SHAPE_SIGMOID, 1.0f, 1.0f, 5.5f);

    FUZZY_NEURON_EXPR_MEMBERSHIP((*model), temperature_low_node, temperature_low);
    FUZZY_NEURON_EXPR_MEMBERSHIP((*model), temperature_high_node, temperature_high);
    FUZZY_NEURON_EXPR_MEMBERSHIP((*model), load_low_node, load_low);
    FUZZY_NEURON_EXPR_MEMBERSHIP((*model), load_high_node, load_high);
    FUZZY_NEURON_EXPR_MEMBERSHIP((*model), vibration_low_node, vibration_low);
    FUZZY_NEURON_EXPR_MEMBERSHIP((*model), vibration_high_node, vibration_high);

    FUZZY_NEURON_EXPR_AND((*model), idle_tl, temperature_low_node, load_low_node);
    FUZZY_NEURON_EXPR_AND((*model), idle_root, idle_tl, vibration_low_node);
    FUZZY_NEURON_TRAINABLE_RULE_ROOT((*model), "idle", idle_root);

    FUZZY_NEURON_EXPR_NOT((*model), economy_not_temperature_high, temperature_high_node);
    FUZZY_NEURON_EXPR_AND((*model), economy_root, economy_not_temperature_high, load_high_node);
    FUZZY_NEURON_TRAINABLE_RULE_ROOT((*model), "economy", economy_root);

    FUZZY_NEURON_EXPR_OR((*model), balanced_root, temperature_high_node, vibration_high_node);
    FUZZY_NEURON_TRAINABLE_RULE_ROOT((*model), "balanced", balanced_root);

    FUZZY_NEURON_EXPR_AND((*model), cooling_root, temperature_high_node, load_high_node);
    FUZZY_NEURON_TRAINABLE_RULE_ROOT((*model), "cooling", cooling_root);

    FUZZY_NEURON_EXPR_NOT((*model), heavy_not_vibration_high, vibration_high_node);
    FUZZY_NEURON_EXPR_AND((*model), heavy_load_root, load_high_node, heavy_not_vibration_high);
    FUZZY_NEURON_TRAINABLE_RULE_ROOT((*model), "heavy_load", heavy_load_root);

    FUZZY_NEURON_EXPR_AND((*model), protection_temperature, temperature_high_node, vibration_high_node);
    FUZZY_NEURON_EXPR_AND((*model), protection_load, load_high_node, vibration_high_node);
    FUZZY_NEURON_EXPR_OR((*model), protection_root, protection_temperature, protection_load);
    FUZZY_NEURON_TRAINABLE_RULE_ROOT((*model), "protection", protection_root);

    FUZZY_NEURON_LAYER((*model), FIRST_HIDDEN, FUZZY_NEURON_RELU);
    FUZZY_NEURON_LAYER((*model), SECOND_HIDDEN, FUZZY_NEURON_RELU);
    FUZZY_NEURON_LAYER((*model), THIRD_HIDDEN, FUZZY_NEURON_RELU);
    FUZZY_NEURON_OUTPUT((*model), FUZZY_NEURON_LINEAR);
)

FUZZY_NEURON_MODEL_PLUGIN(fuzzy_model, FUZZY_MODEL_PLUGIN_ABI, "temperature-load-vibration-trainable", FUZZY_MODEL_EXPORT)

#ifndef FUZZY_MODEL_PLUGIN_ONLY

FUZZY_NEURON_HOT_RELOAD(fuzzy_model_plugin, DEFAULT_PLUGIN)

static void generate_model_plots(fuzzy_neuron_network_t *model)
{
    if (!FUZZY_NEURON_PLOT_MEMBERSHIPS((*model), OUTPUT_DIR)) exit(EXIT_FAILURE);
    if (!FUZZY_NEURON_SWEEP_MODEL((*model), OUTPUT_DIR "/fuzzy_neuron_learned_surface", "Trained Fuzzy-Neuron Surface", 0u, SCALE, FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 2.0f), FUZZY_SWEEP_DIMENSION("Load", 0.0f, 100.0f, 2.0f), FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f))) exit(EXIT_FAILURE);
}

static unsigned int random_state = 0x12345678u;

static float random_uniform(float minimum, float maximum)
{
    random_state = random_state * 1664525u + 1013904223u;
    return minimum + (maximum - minimum) * ((float)(random_state & 0x00ffffffu) / 16777215.0f);
}

static void initialize_network(fuzzy_neuron_network_t *model)
{
    size_t layer;
    random_state = 0x12345678u;
    for (layer = 0u; layer < model->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &model->layers[layer];
        size_t source_count = layer == 0u ? model->rule_count : model->layers[layer - 1u].count;
        size_t destination_count = current->count;
        bool relu = current->activation == FUZZY_NEURON_RELU;
        float limit = relu ? sqrtf(6.0f / (float)source_count) : sqrtf(6.0f / ((float)source_count + (float)destination_count));
        size_t destination;
        size_t source;
        for (destination = 0u; destination < destination_count; destination++)
        {
            model->biases[current->bias_offset + destination] = 0.0f;
            for (source = 0u; source < source_count; source++) model->weights[current->weight_offset + destination * source_count + source] = random_uniform(-limit, limit);
        }
    }
}

static fuzzy_neuron_csv_t csv_format(void)
{
    static const float input_scales[3] = {1.0f, 1.0f, 1.0f};
    static const float target_scales[1] = {SCALE};
    fuzzy_neuron_csv_t csv = {3u, 1u, true, ',', input_scales, target_scales};
    return csv;
}

static void print_premises(const fuzzy_neuron_network_t *model, const char *stage)
{
    size_t premise_index;
    printf("\n============================================================\n");
    printf("Trainable Premises: %s\n", stage);
    printf("============================================================\n");
    for (premise_index = 0u; premise_index < model->premise_count; premise_index++)
    {
        const fuzzy_neuron_premise_t *premise = &model->premises[premise_index];
        size_t parameter_index;
        printf("%s input=%s shape=%u hedge=%+.9f trainable_mask=0x%X parameters=", premise->name, model->inputs[premise->input_index].name, (unsigned int)premise->shape, premise->hedge, premise->trainable_mask);
        for (parameter_index = 0u; parameter_index < premise->parameter_count; parameter_index++) printf("%s%+.9f", parameter_index == 0u ? "" : ",", model->premise_parameters[premise->parameter_offset + parameter_index]);
        printf("\n");
    }
    printf("============================================================\n");
}

static void measure(fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *dataset, const char *stage)
{
    double mse = 0.0;
    double mae = 0.0;
    double maximum = 0.0;
    float output[1];
    size_t row;
    for (row = 0u; row < dataset->rows; row++)
    {
        const float *input = dataset->inputs + row * dataset->input_dimensions;
        float expected = dataset->targets[row];
        float error;
        fuzzy_neuron_predict(model, input, output);
        error = output[0] - expected;
        mse += (double)error * error;
        mae += fabs((double)error);
        if (fabs((double)error) > maximum) maximum = fabs((double)error);
    }
    printf("%s MSE %.10f RMSE %.10f MAE %.10f maximum %.10f\n", stage, mse / dataset->rows, sqrt(mse / dataset->rows), mae / dataset->rows, maximum);
}

static void train_model(void)
{
    fuzzy_neuron_csv_t csv = csv_format();
    fuzzy_neuron_dataset_t dataset = {0};
    fuzzy_neuron_loaded_plugin_t plugin = fuzzy_model_plugin_load();
    fuzzy_neuron_network_t *model = plugin.api->create();
    fuzzy_neuron_train_options_t mse_options;
    fuzzy_neuron_train_options_t huber_options;
    unsigned int continue_training;
    unsigned int mse_epochs;
    unsigned int mse_batch_size;
    unsigned int mse_report_interval;
    unsigned int huber_epochs;
    unsigned int huber_batch_size;
    unsigned int huber_report_interval;
    unsigned int opencl_batch_capacity;
    float mse_learning_rate;
    float huber_learning_rate;

    printf("Continue existing model? 0 = new, 1 = continue: ");
    if (scanf("%u", &continue_training) != 1) exit(EXIT_FAILURE);
    if (continue_training)
    {
        if (!fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL)) exit(EXIT_FAILURE);
    }
    else initialize_network(model);

    printf("GPU MSE epochs: ");
    if (scanf("%u", &mse_epochs) != 1) exit(EXIT_FAILURE);
    printf("GPU MSE batch size: ");
    if (scanf("%u", &mse_batch_size) != 1) exit(EXIT_FAILURE);
    printf("GPU MSE learning rate: ");
    if (scanf("%f", &mse_learning_rate) != 1) exit(EXIT_FAILURE);
    printf("GPU MSE report interval: ");
    if (scanf("%u", &mse_report_interval) != 1) exit(EXIT_FAILURE);
    printf("GPU Huber epochs: ");
    if (scanf("%u", &huber_epochs) != 1) exit(EXIT_FAILURE);
    printf("GPU Huber batch size: ");
    if (scanf("%u", &huber_batch_size) != 1) exit(EXIT_FAILURE);
    printf("GPU Huber learning rate: ");
    if (scanf("%f", &huber_learning_rate) != 1) exit(EXIT_FAILURE);
    printf("GPU Huber report interval: ");
    if (scanf("%u", &huber_report_interval) != 1) exit(EXIT_FAILURE);

    mse_options = FUZZY_NEURON_TRAIN_OPTIONS_ADAM(mse_epochs, mse_batch_size, mse_learning_rate, mse_report_interval);
    huber_options = FUZZY_NEURON_TRAIN_OPTIONS_ADAM_CONTINUE(huber_epochs, huber_batch_size, huber_learning_rate, huber_report_interval);
    opencl_batch_capacity = mse_batch_size > huber_batch_size ? mse_batch_size : huber_batch_size;

    if (system("mkdir -p " OUTPUT_DIR) != 0) exit(EXIT_FAILURE);
    if (!fuzzy_neuron_dataset_load_csv(DEFAULT_TRAIN_DATASET, &csv, &dataset)) exit(EXIT_FAILURE);
    print_premises(model, "Before Training");
    measure(model, &dataset, "Before Training");

    if (!fuzzy_neuron_opencl_init(model, opencl_batch_capacity, DEFAULT_KERNEL)) exit(EXIT_FAILURE);
    if (mse_epochs > 0u && !fuzzy_neuron_opencl_train(model, &dataset, &mse_options, MSE)) exit(EXIT_FAILURE);
    measure(model, &dataset, "After GPU MSE");
    if (huber_epochs > 0u && !fuzzy_neuron_opencl_train(model, &dataset, &huber_options, HUBER)) exit(EXIT_FAILURE);
    measure(model, &dataset, "After GPU Huber");
    print_premises(model, "After Training");

    if (!fuzzy_neuron_model_save_csv(model, DEFAULT_MODEL)) exit(EXIT_FAILURE);
    generate_model_plots(model);
    printf("Membership plots and trained surface written to %s/\n", OUTPUT_DIR);
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
    if (!fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL)) exit(EXIT_FAILURE);
    printf("Temperature Load Vibration: ");
    if (scanf("%f %f %f", &input[0], &input[1], &input[2]) != 3) exit(EXIT_FAILURE);
    if (!fuzzy_neuron_predict(model, input, output)) exit(EXIT_FAILURE);
    printf("Predicted output: %.9f\n", output[0]);
    plugin.api->destroy(model);
    fuzzy_model_plugin_unload(&plugin);
}

static void test_dataset(const char *dataset_path)
{
    fuzzy_neuron_csv_t csv = csv_format();
    fuzzy_neuron_dataset_t dataset = {0};
    fuzzy_neuron_loaded_plugin_t plugin = fuzzy_model_plugin_load();
    fuzzy_neuron_network_t *model = plugin.api->create();
    if (!fuzzy_neuron_model_load_csv(model, DEFAULT_MODEL)) exit(EXIT_FAILURE);
    if (!fuzzy_neuron_dataset_load_csv(dataset_path, &csv, &dataset)) exit(EXIT_FAILURE);
    measure(model, &dataset, "Dataset Test");
    fuzzy_neuron_dataset_free(&dataset);
    plugin.api->destroy(model);
    fuzzy_model_plugin_unload(&plugin);
}

static void menu(void)
{
    int choice = 0;
    while (choice != 4)
    {
        printf("\n1. Train model\n2. Run one input\n3. Test original dataset\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) exit(EXIT_FAILURE);
        if (choice == 1) train_model();
        else if (choice == 2) run_input();
        else if (choice == 3) test_dataset(DEFAULT_TRAIN_DATASET);
    }
}

int main(void)
{
    if (system("mkdir -p " OUTPUT_DIR) != 0) return EXIT_FAILURE;
    menu();
    return EXIT_SUCCESS;
}

#endif
