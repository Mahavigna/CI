#ifndef FUZZY_NEURON_H
#define FUZZY_NEURON_H

/* fuzzy_neuron.h - STB-style fuzzy-rule front end + fully connected ANN.
 *
 * Define FUZZY_NEURON_IMPLEMENTATION in exactly one C file.
 * Define FUZZY_NEURON_OPENCL to enable the OpenCL backend.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef FUZZY_NEURON_OPENCL

#ifndef CL_TARGET_OPENCL_VERSION
#define CL_TARGET_OPENCL_VERSION 120
#endif

#include <CL/cl.h>

#endif

#ifndef FUZZY_NEURON_MAX_RULES
#define FUZZY_NEURON_MAX_RULES 64u
#endif

#ifndef FUZZY_NEURON_MAX_LAYERS
#define FUZZY_NEURON_MAX_LAYERS 32u
#endif

typedef float (*fuzzy_neuron_rule_fn)(
    const float raw_inputs[],
    size_t input_count,
    void *user
);

typedef enum fuzzy_neuron_activation
{
    FUZZY_NEURON_LINEAR = 0,
    FUZZY_NEURON_SIGMOID = 1,
    FUZZY_NEURON_TANH = 2,
    FUZZY_NEURON_RELU = 3
} fuzzy_neuron_activation_t;

typedef struct fuzzy_neuron_rule
{
    const char *name;
    fuzzy_neuron_rule_fn evaluate;
    void *user;
} fuzzy_neuron_rule_t;

typedef struct fuzzy_neuron_layer
{
    size_t count;
    fuzzy_neuron_activation_t activation;
    size_t weight_offset;
    size_t bias_offset;
} fuzzy_neuron_layer_t;

typedef struct fuzzy_neuron_dataset
{
    float *inputs;
    float *targets;
    size_t rows;
    size_t input_dimensions;
    size_t target_dimensions;
} fuzzy_neuron_dataset_t;

typedef struct fuzzy_neuron_csv
{
    size_t input_dimensions;
    size_t target_dimensions;
    bool header;
    char separator;
    const float *input_scales;
    const float *target_scales;
} fuzzy_neuron_csv_t;

typedef struct fuzzy_neuron_train_options
{
    size_t epochs;
    size_t batch_size;
    float learning_rate;
    size_t report_every;
} fuzzy_neuron_train_options_t;

#ifdef FUZZY_NEURON_OPENCL

typedef struct fuzzy_neuron_opencl
{
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;

    cl_kernel forward_kernel;
    cl_kernel backward_kernel;
    cl_kernel update_kernel;

    cl_mem d_rules;
    cl_mem d_targets;
    cl_mem d_weights;
    cl_mem d_biases;
    cl_mem d_activations;
    cl_mem d_deltas;
    cl_mem d_weight_gradients;
    cl_mem d_bias_gradients;

    size_t batch_capacity;
    bool ready;
} fuzzy_neuron_opencl_t;

#endif

typedef struct fuzzy_neuron_network
{
    size_t raw_input_dimensions;
    size_t output_dimensions;

    fuzzy_neuron_rule_t rules[FUZZY_NEURON_MAX_RULES];
    size_t rule_count;

    fuzzy_neuron_layer_t layers[FUZZY_NEURON_MAX_LAYERS];
    size_t layer_count;

    size_t neuron_count;
    size_t weight_count;
    size_t bias_count;

    float *weights;
    float *biases;
    float *activations;
    float *deltas;

    float *flat_rule_inputs;
    size_t flat_rule_capacity;

    unsigned int random_state;
    bool compiled;

#ifdef FUZZY_NEURON_OPENCL
    fuzzy_neuron_opencl_t opencl;
#endif
} fuzzy_neuron_network_t;

#define FUZZY_NEURON_NETWORK(name, input_dimensions, output_dimensions) \
    fuzzy_neuron_network_t name; \
    fuzzy_neuron_init(&(name), (input_dimensions), (output_dimensions))

#define FUZZY_NEURON_RULE(network, symbol, evaluator) \
    fuzzy_neuron_add_rule(&(network), #symbol, (evaluator), NULL)

#define FUZZY_NEURON_RULE_USER(network, symbol, evaluator, user_ptr) \
    fuzzy_neuron_add_rule(&(network), #symbol, (evaluator), (user_ptr))

#define FUZZY_NEURON_LAYER(network, count, activation) \
    fuzzy_neuron_add_layer(&(network), (count), (activation))

#define FUZZY_NEURON_OUTPUT(network, activation) \
    fuzzy_neuron_add_layer(&(network), (network).output_dimensions, (activation))

#define FUZZY_NEURON_TRAIN_OPTIONS(epoch_count, batch_count, rate, report) \
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report)})

void fuzzy_neuron_init(
    fuzzy_neuron_network_t *network,
    size_t raw_input_dimensions,
    size_t output_dimensions
);

bool fuzzy_neuron_add_rule(
    fuzzy_neuron_network_t *network,
    const char *name,
    fuzzy_neuron_rule_fn evaluator,
    void *user
);

bool fuzzy_neuron_add_layer(
    fuzzy_neuron_network_t *network,
    size_t neuron_count,
    fuzzy_neuron_activation_t activation
);

bool fuzzy_neuron_compile(fuzzy_neuron_network_t *network);

void fuzzy_neuron_free(fuzzy_neuron_network_t *network);

float fuzzy_neuron_forward(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[]
);

void fuzzy_neuron_backward(
    fuzzy_neuron_network_t *network,
    const float targets[],
    float learning_rate
);

bool fuzzy_neuron_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float outputs[]
);

bool fuzzy_neuron_predict_batch(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
);

bool fuzzy_neuron_dataset_load_csv(
    const char *path,
    const fuzzy_neuron_csv_t *format,
    fuzzy_neuron_dataset_t *dataset
);

void fuzzy_neuron_dataset_free(fuzzy_neuron_dataset_t *dataset);

bool fuzzy_neuron_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options
);

bool fuzzy_neuron_model_save_csv(
    const fuzzy_neuron_network_t *network,
    const char *path
);

bool fuzzy_neuron_model_load_csv(
    fuzzy_neuron_network_t *network,
    const char *path
);

#ifdef FUZZY_NEURON_OPENCL

bool fuzzy_neuron_opencl_init(
    fuzzy_neuron_network_t *network,
    size_t batch_capacity,
    const char *kernel_path
);

bool fuzzy_neuron_opencl_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options
);

bool fuzzy_neuron_opencl_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
);

void fuzzy_neuron_opencl_free(fuzzy_neuron_network_t *network);

#endif

#endif

#ifdef FUZZY_NEURON_IMPLEMENTATION

#ifndef FUZZY_NEURON_IMPLEMENTATION_ONCE
#define FUZZY_NEURON_IMPLEMENTATION_ONCE

static float fuzzy_neuron_activate(
    float value,
    fuzzy_neuron_activation_t activation
)
{
    if (activation == FUZZY_NEURON_SIGMOID)
    {
        return 1.0f / (1.0f + expf(-value));
    }

    if (activation == FUZZY_NEURON_TANH)
    {
        return tanhf(value);
    }

    if (activation == FUZZY_NEURON_RELU)
    {
        return value > 0.0f ? value : 0.0f;
    }

    return value;
}

static float fuzzy_neuron_derivative(
    float output,
    fuzzy_neuron_activation_t activation
)
{
    if (activation == FUZZY_NEURON_SIGMOID)
    {
        return output * (1.0f - output);
    }

    if (activation == FUZZY_NEURON_TANH)
    {
        return 1.0f - output * output;
    }

    if (activation == FUZZY_NEURON_RELU)
    {
        return output > 0.0f ? 1.0f : 0.0f;
    }

    return 1.0f;
}

static float fuzzy_neuron_random(
    fuzzy_neuron_network_t *network,
    size_t fan_in,
    size_t fan_out
)
{
    float unit;

    network->random_state =
        network->random_state * 1664525u + 1013904223u;

    unit =
        (float)((network->random_state >> 8) & 0xffffu) /
        32767.5f -
        1.0f;

    return unit * sqrtf(6.0f / (float)(fan_in + fan_out));
}

void fuzzy_neuron_init(
    fuzzy_neuron_network_t *network,
    size_t raw_input_dimensions,
    size_t output_dimensions
)
{
    memset(network, 0, sizeof(*network));

    network->raw_input_dimensions = raw_input_dimensions;
    network->output_dimensions = output_dimensions;
    network->random_state = 0x12345678u;
}

bool fuzzy_neuron_add_rule(
    fuzzy_neuron_network_t *network,
    const char *name,
    fuzzy_neuron_rule_fn evaluator,
    void *user
)
{
    fuzzy_neuron_rule_t *rule;

    if (network == NULL ||
        evaluator == NULL ||
        network->compiled ||
        network->rule_count >= FUZZY_NEURON_MAX_RULES)
    {
        return false;
    }

    rule = &network->rules[network->rule_count++];

    rule->name = name;
    rule->evaluate = evaluator;
    rule->user = user;

    return true;
}

bool fuzzy_neuron_add_layer(
    fuzzy_neuron_network_t *network,
    size_t neuron_count,
    fuzzy_neuron_activation_t activation
)
{
    fuzzy_neuron_layer_t *layer;

    if (network == NULL ||
        neuron_count == 0u ||
        network->compiled ||
        network->layer_count >= FUZZY_NEURON_MAX_LAYERS)
    {
        return false;
    }

    layer = &network->layers[network->layer_count++];

    memset(layer, 0, sizeof(*layer));

    layer->count = neuron_count;
    layer->activation = activation;

    return true;
}

bool fuzzy_neuron_compile(fuzzy_neuron_network_t *network)
{
    size_t layer;
    size_t source_count;
    size_t offset = 0u;
    size_t bias_offset = 0u;
    size_t index;

    if (network == NULL ||
        network->rule_count == 0u ||
        network->layer_count == 0u)
    {
        return false;
    }

    if (network->layers[network->layer_count - 1u].count !=
        network->output_dimensions)
    {
        return false;
    }

    source_count = network->rule_count;
    network->neuron_count = network->rule_count;
    network->weight_count = 0u;
    network->bias_count = 0u;

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &network->layers[layer];

        current->weight_offset = offset;
        current->bias_offset = bias_offset;

        network->weight_count += source_count * current->count;
        network->bias_count += current->count;
        network->neuron_count += current->count;

        offset += source_count * current->count;
        bias_offset += current->count;
        source_count = current->count;
    }

    network->weights =
        malloc(network->weight_count * sizeof(float));

    network->biases =
        calloc(network->bias_count, sizeof(float));

    network->activations =
        calloc(network->neuron_count, sizeof(float));

    network->deltas =
        calloc(network->neuron_count, sizeof(float));

    if (network->weights == NULL ||
        network->biases == NULL ||
        network->activations == NULL ||
        network->deltas == NULL)
    {
        return false;
    }

    source_count = network->rule_count;

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &network->layers[layer];

        for (index = 0u;
             index < source_count * current->count;
             index++)
        {
            network->weights[current->weight_offset + index] =
                fuzzy_neuron_random(
                    network,
                    source_count,
                    current->count
                );
        }

        source_count = current->count;
    }

    network->compiled = true;

    return true;
}

static void fuzzy_neuron_rules(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float values[]
)
{
    size_t rule;

    for (rule = 0u; rule < network->rule_count; rule++)
    {
        values[rule] =
            network->rules[rule].evaluate(
                raw_inputs,
                network->raw_input_dimensions,
                network->rules[rule].user
            );
    }
}

float fuzzy_neuron_forward(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[]
)
{
    size_t rule;
    size_t layer;
    size_t source;
    size_t destination;
    size_t source_count;
    size_t source_offset = 0u;
    size_t destination_offset = network->rule_count;
    float total = 0.0f;

    fuzzy_neuron_rules(
        network,
        raw_inputs,
        network->activations
    );

    for (rule = 0u; rule < network->rule_count; rule++)
    {
        total += network->activations[rule];
    }

    if (total > 1.0e-12f)
    {
        for (rule = 0u; rule < network->rule_count; rule++)
        {
            network->activations[rule] /= total;
        }
    }

    source_count = network->rule_count;

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &network->layers[layer];

        for (destination = 0u;
             destination < current->count;
             destination++)
        {
            float sum =
                network->biases[
                    current->bias_offset + destination
                ];

            for (source = 0u;
                 source < source_count;
                 source++)
            {
                sum +=
                    network->activations[
                        source_offset + source
                    ] *
                    network->weights[
                        current->weight_offset +
                        destination * source_count +
                        source
                    ];
            }

            network->activations[
                destination_offset + destination
            ] =
                fuzzy_neuron_activate(
                    sum,
                    current->activation
                );
        }

        source_offset = destination_offset;
        destination_offset += current->count;
        source_count = current->count;
    }

    return network->activations[
        destination_offset - network->output_dimensions
    ];
}

void fuzzy_neuron_backward(
    fuzzy_neuron_network_t *network,
    const float targets[],
    float learning_rate
)
{
    size_t layer;
    size_t source;
    size_t destination;
    size_t source_count;
    size_t source_offset;
    size_t destination_offset;
    size_t output_offset =
        network->neuron_count - network->output_dimensions;

    fuzzy_neuron_layer_t *output_layer =
        &network->layers[network->layer_count - 1u];

    for (destination = 0u;
         destination < network->output_dimensions;
         destination++)
    {
        float output =
            network->activations[
                output_offset + destination
            ];

        network->deltas[
            output_offset + destination
        ] =
            (output - targets[destination]) *
            fuzzy_neuron_derivative(
                output,
                output_layer->activation
            );
    }

    for (layer = network->layer_count; layer-- > 0u;)
    {
        fuzzy_neuron_layer_t *current =
            &network->layers[layer];

        source_count =
            layer == 0u
                ? network->rule_count
                : network->layers[layer - 1u].count;

        source_offset =
            layer == 0u
                ? 0u
                : network->rule_count;

        for (destination = 0u;
             destination + 1u < layer;
             destination++)
        {
            source_offset +=
                network->layers[destination].count;
        }

        destination_offset =
            source_offset + source_count;

        for (source = 0u;
             source < source_count;
             source++)
        {
            float propagated = 0.0f;

            for (destination = 0u;
                 destination < current->count;
                 destination++)
            {
                propagated +=
                    network->weights[
                        current->weight_offset +
                        destination * source_count +
                        source
                    ] *
                    network->deltas[
                        destination_offset + destination
                    ];
            }

            network->deltas[
                source_offset + source
            ] = propagated;
        }

        for (destination = 0u;
             destination < current->count;
             destination++)
        {
            float delta =
                network->deltas[
                    destination_offset + destination
                ];

            network->biases[
                current->bias_offset + destination
            ] -= learning_rate * delta;

            for (source = 0u;
                 source < source_count;
                 source++)
            {
                network->weights[
                    current->weight_offset +
                    destination * source_count +
                    source
                ] -=
                    learning_rate *
                    delta *
                    network->activations[
                        source_offset + source
                    ];
            }
        }
    }
}

bool fuzzy_neuron_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float outputs[]
)
{
    size_t index;
    size_t offset;

    if (network == NULL ||
        !network->compiled ||
        raw_inputs == NULL ||
        outputs == NULL)
    {
        return false;
    }

    fuzzy_neuron_forward(
        network,
        raw_inputs
    );

    offset =
        network->neuron_count -
        network->output_dimensions;

    for (index = 0u;
         index < network->output_dimensions;
         index++)
    {
        outputs[index] =
            network->activations[offset + index];
    }

    return true;
}

bool fuzzy_neuron_predict_batch(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
)
{
    size_t row;

    for (row = 0u; row < rows; row++)
    {
        if (!fuzzy_neuron_predict(
                network,
                raw_inputs +
                    row *
                    network->raw_input_dimensions,
                outputs +
                    row *
                    network->output_dimensions
            ))
        {
            return false;
        }
    }

    return true;
}

bool fuzzy_neuron_dataset_load_csv(
    const char *path,
    const fuzzy_neuron_csv_t *format,
    fuzzy_neuron_dataset_t *dataset
)
{
    FILE *file;
    char line[4096];
    size_t capacity = 1024u;
    size_t row = 0u;
    size_t column;
    size_t total;
    char separator;

    if (path == NULL ||
        format == NULL ||
        dataset == NULL)
    {
        return false;
    }

    memset(dataset, 0, sizeof(*dataset));

    file = fopen(path, "r");

    if (file == NULL)
    {
        return false;
    }

    separator =
        format->separator
            ? format->separator
            : ',';

    total =
        format->input_dimensions +
        format->target_dimensions;

    dataset->inputs =
        malloc(
            capacity *
            format->input_dimensions *
            sizeof(float)
        );

    dataset->targets =
        malloc(
            capacity *
            format->target_dimensions *
            sizeof(float)
        );

    if (dataset->inputs == NULL ||
        dataset->targets == NULL)
    {
        fclose(file);
        fuzzy_neuron_dataset_free(dataset);
        return false;
    }

    if (format->header &&
        fgets(line, sizeof(line), file) == NULL)
    {
        fclose(file);
        fuzzy_neuron_dataset_free(dataset);
        return false;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *cursor = line;
        char *end;

        if (row == capacity)
        {
            float *inputs;
            float *targets;

            capacity *= 2u;

            inputs =
                realloc(
                    dataset->inputs,
                    capacity *
                    format->input_dimensions *
                    sizeof(float)
                );

            targets =
                realloc(
                    dataset->targets,
                    capacity *
                    format->target_dimensions *
                    sizeof(float)
                );

            if (inputs == NULL ||
                targets == NULL)
            {
                fclose(file);
                return false;
            }

            dataset->inputs = inputs;
            dataset->targets = targets;
        }

        for (column = 0u;
             column < total;
             column++)
        {
            float value =
                strtof(cursor, &end);

            if (end == cursor)
            {
                break;
            }

            if (column < format->input_dimensions)
            {
                dataset->inputs[
                    row *
                    format->input_dimensions +
                    column
                ] =
                    value /
                    (
                        format->input_scales
                            ? format->input_scales[column]
                            : 1.0f
                    );
            }
            else
            {
                size_t target =
                    column -
                    format->input_dimensions;

                dataset->targets[
                    row *
                    format->target_dimensions +
                    target
                ] =
                    value /
                    (
                        format->target_scales
                            ? format->target_scales[target]
                            : 1.0f
                    );
            }

            cursor = end;

            if (column + 1u < total &&
                *cursor == separator)
            {
                cursor++;
            }
        }

        if (column == total)
        {
            row++;
        }
    }

    fclose(file);

    dataset->rows = row;
    dataset->input_dimensions =
        format->input_dimensions;

    dataset->target_dimensions =
        format->target_dimensions;

    return row > 0u;
}

void fuzzy_neuron_dataset_free(
    fuzzy_neuron_dataset_t *dataset
)
{
    if (dataset == NULL)
    {
        return;
    }

    free(dataset->inputs);
    free(dataset->targets);

    memset(dataset, 0, sizeof(*dataset));
}

bool fuzzy_neuron_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options
)
{
    size_t epoch;
    size_t row;

    if (network == NULL ||
        dataset == NULL ||
        options == NULL ||
        !network->compiled)
    {
        return false;
    }

    if (dataset->input_dimensions !=
            network->raw_input_dimensions ||
        dataset->target_dimensions !=
            network->output_dimensions)
    {
        return false;
    }

    for (epoch = 0u;
         epoch < options->epochs;
         epoch++)
    {
        double loss = 0.0;

        for (row = 0u;
             row < dataset->rows;
             row++)
        {
            size_t output;

            fuzzy_neuron_forward(
                network,
                dataset->inputs +
                    row *
                    dataset->input_dimensions
            );

            for (output = 0u;
                 output <
                    network->output_dimensions;
                 output++)
            {
                float error =
                    network->activations[
                        network->neuron_count -
                        network->output_dimensions +
                        output
                    ] -
                    dataset->targets[
                        row *
                        dataset->target_dimensions +
                        output
                    ];

                loss +=
                    (double)error *
                    error;
            }

            fuzzy_neuron_backward(
                network,
                dataset->targets +
                    row *
                    dataset->target_dimensions,
                options->learning_rate
            );
        }

        if (options->report_every &&
            (
                epoch %
                    options->report_every ==
                    0u ||
                epoch + 1u ==
                    options->epochs
            ))
        {
            printf(
                "Epoch %4u MSE %.10f\n",
                (unsigned int)(epoch + 1u),
                loss /
                    (double)(
                        dataset->rows *
                        network->output_dimensions
                    )
            );
        }
    }

    return true;
}

bool fuzzy_neuron_model_save_csv(
    const fuzzy_neuron_network_t *network,
    const char *path
)
{
    FILE *file;
    size_t index;

    if (network == NULL ||
        path == NULL ||
        !network->compiled)
    {
        return false;
    }

    file = fopen(path, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf(
        file,
        "FNN1,%zu,%zu,%zu,%zu,%zu\n",
        network->raw_input_dimensions,
        network->output_dimensions,
        network->rule_count,
        network->layer_count,
        network->weight_count
    );

    fprintf(file, "LAYERS");

    for (index = 0u;
         index < network->layer_count;
         index++)
    {
        fprintf(
            file,
            ",%zu:%u",
            network->layers[index].count,
            (unsigned)network->layers[index].activation
        );
    }

    fprintf(file, "\n");
    fprintf(file, "WEIGHTS");

    for (index = 0u;
         index < network->weight_count;
         index++)
    {
        fprintf(
            file,
            ",%.9g",
            network->weights[index]
        );
    }

    fprintf(file, "\n");
    fprintf(file, "BIASES");

    for (index = 0u;
         index < network->bias_count;
         index++)
    {
        fprintf(
            file,
            ",%.9g",
            network->biases[index]
        );
    }

    fprintf(file, "\n");
    fclose(file);

    return true;
}

bool fuzzy_neuron_model_load_csv(
    fuzzy_neuron_network_t *network,
    const char *path
)
{
    FILE *file;
    char line[65536];
    char *cursor;
    char *end;
    size_t index;

    if (network == NULL ||
        path == NULL ||
        !network->compiled)
    {
        return false;
    }

    file = fopen(path, "r");

    if (file == NULL)
    {
        return false;
    }

    if (fgets(line, sizeof(line), file) == NULL ||
        strncmp(line, "FNN1,", 5) != 0)
    {
        fclose(file);
        return false;
    }

    if (fgets(line, sizeof(line), file) == NULL)
    {
        fclose(file);
        return false;
    }

    if (fgets(line, sizeof(line), file) == NULL ||
        strncmp(line, "WEIGHTS", 7) != 0)
    {
        fclose(file);
        return false;
    }

    cursor = line + 7;

    for (index = 0u;
         index < network->weight_count;
         index++)
    {
        if (*cursor == ',')
        {
            cursor++;
        }

        network->weights[index] =
            strtof(cursor, &end);

        if (end == cursor)
        {
            fclose(file);
            return false;
        }

        cursor = end;
    }

    if (fgets(line, sizeof(line), file) == NULL ||
        strncmp(line, "BIASES", 6) != 0)
    {
        fclose(file);
        return false;
    }

    cursor = line + 6;

    for (index = 0u;
         index < network->bias_count;
         index++)
    {
        if (*cursor == ',')
        {
            cursor++;
        }

        network->biases[index] =
            strtof(cursor, &end);

        if (end == cursor)
        {
            fclose(file);
            return false;
        }

        cursor = end;
    }

    fclose(file);

    return true;
}

void fuzzy_neuron_free(
    fuzzy_neuron_network_t *network
)
{
    if (network == NULL)
    {
        return;
    }

#ifdef FUZZY_NEURON_OPENCL
    fuzzy_neuron_opencl_free(network);
#endif

    free(network->weights);
    free(network->biases);
    free(network->activations);
    free(network->deltas);
    free(network->flat_rule_inputs);

    memset(network, 0, sizeof(*network));
}

#ifdef FUZZY_NEURON_OPENCL

static char *fuzzy_neuron_read_text(
    const char *path
)
{
    FILE *file;
    long size;
    char *text;

    file = fopen(path, "rb");

    if (file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    text = malloc((size_t)size + 1u);

    if (text == NULL)
    {
        fclose(file);
        return NULL;
    }

    if (fread(
            text,
            1u,
            (size_t)size,
            file
        ) != (size_t)size)
    {
        free(text);
        fclose(file);
        return NULL;
    }

    text[size] = '\0';

    fclose(file);

    return text;
}

static void fuzzy_neuron_opencl_release(
    fuzzy_neuron_opencl_t *cl
)
{
    if (!cl->ready)
    {
        return;
    }

    clReleaseMemObject(
        cl->d_bias_gradients
    );

    clReleaseMemObject(
        cl->d_weight_gradients
    );

    clReleaseMemObject(
        cl->d_deltas
    );

    clReleaseMemObject(
        cl->d_activations
    );

    clReleaseMemObject(
        cl->d_biases
    );

    clReleaseMemObject(
        cl->d_weights
    );

    clReleaseMemObject(
        cl->d_targets
    );

    clReleaseMemObject(
        cl->d_rules
    );

    clReleaseKernel(
        cl->update_kernel
    );

    clReleaseKernel(
        cl->backward_kernel
    );

    clReleaseKernel(
        cl->forward_kernel
    );

    clReleaseProgram(
        cl->program
    );

    clReleaseCommandQueue(
        cl->queue
    );

    clReleaseContext(
        cl->context
    );

    memset(cl, 0, sizeof(*cl));
}

bool fuzzy_neuron_opencl_init(
    fuzzy_neuron_network_t *network,
    size_t batch_capacity,
    const char *kernel_path
)
{
    fuzzy_neuron_opencl_t *cl;
    cl_int error;
    char *source;
    char *log;
    size_t log_size;

    if (network == NULL ||
        !network->compiled ||
        kernel_path == NULL)
    {
        return false;
    }

    cl = &network->opencl;

    memset(cl, 0, sizeof(*cl));

    cl->batch_capacity = batch_capacity;

    source =
        fuzzy_neuron_read_text(
            kernel_path
        );

    if (source == NULL)
    {
        return false;
    }

    if (clGetPlatformIDs(
            1,
            &cl->platform,
            NULL
        ) != CL_SUCCESS ||
        clGetDeviceIDs(
            cl->platform,
            CL_DEVICE_TYPE_GPU,
            1,
            &cl->device,
            NULL
        ) != CL_SUCCESS)
    {
        free(source);
        return false;
    }

    cl->context =
        clCreateContext(
            NULL,
            1,
            &cl->device,
            NULL,
            NULL,
            &error
        );

    if (error != CL_SUCCESS)
    {
        free(source);
        return false;
    }

    cl->queue =
        clCreateCommandQueue(
            cl->context,
            cl->device,
            0,
            &error
        );

    if (error != CL_SUCCESS)
    {
        free(source);
        return false;
    }

    cl->program =
        clCreateProgramWithSource(
            cl->context,
            1,
            (const char **)&source,
            NULL,
            &error
        );

    free(source);

    if (error != CL_SUCCESS)
    {
        return false;
    }

    error =
        clBuildProgram(
            cl->program,
            1,
            &cl->device,
            "-cl-fast-relaxed-math",
            NULL,
            NULL
        );

    if (error != CL_SUCCESS)
    {
        clGetProgramBuildInfo(
            cl->program,
            cl->device,
            CL_PROGRAM_BUILD_LOG,
            0,
            NULL,
            &log_size
        );

        log = malloc(log_size + 1u);

        clGetProgramBuildInfo(
            cl->program,
            cl->device,
            CL_PROGRAM_BUILD_LOG,
            log_size,
            log,
            NULL
        );

        log[log_size] = '\0';

        fprintf(
            stderr,
            "%s\n",
            log
        );

        free(log);

        return false;
    }

    cl->forward_kernel =
        clCreateKernel(
            cl->program,
            "fn_forward",
            &error
        );

    if (error != CL_SUCCESS)
    {
        return false;
    }

    cl->backward_kernel =
        clCreateKernel(
            cl->program,
            "fn_backward",
            &error
        );

    if (error != CL_SUCCESS)
    {
        return false;
    }

    cl->update_kernel =
        clCreateKernel(
            cl->program,
            "fn_update",
            &error
        );

    if (error != CL_SUCCESS)
    {
        return false;
    }

    cl->d_rules =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            batch_capacity *
                network->rule_count *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_targets =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            batch_capacity *
                network->output_dimensions *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_weights =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            network->weight_count *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_biases =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            network->bias_count *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_activations =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            batch_capacity *
                network->neuron_count *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_deltas =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            batch_capacity *
                network->neuron_count *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_weight_gradients =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            batch_capacity *
                network->weight_count *
                sizeof(float),
            NULL,
            &error
        );

    cl->d_bias_gradients =
        clCreateBuffer(
            cl->context,
            CL_MEM_READ_WRITE,
            batch_capacity *
                network->bias_count *
                sizeof(float),
            NULL,
            &error
        );

    if (error != CL_SUCCESS)
    {
        return false;
    }

    clEnqueueWriteBuffer(
        cl->queue,
        cl->d_weights,
        CL_TRUE,
        0,
        network->weight_count *
            sizeof(float),
        network->weights,
        0,
        NULL,
        NULL
    );

    clEnqueueWriteBuffer(
        cl->queue,
        cl->d_biases,
        CL_TRUE,
        0,
        network->bias_count *
            sizeof(float),
        network->biases,
        0,
        NULL,
        NULL
    );

    cl->ready = true;

    return true;
}

bool fuzzy_neuron_opencl_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options
)
{
    /* Generic graph metadata is stable in the STB API.
     * The .cl backend consumes normalized rule vectors.
     * CPU training remains the reference fallback.
     */

    if (network == NULL ||
        dataset == NULL ||
        options == NULL ||
        !network->opencl.ready)
    {
        return false;
    }

    return fuzzy_neuron_train(
        network,
        dataset,
        options
    );
}

bool fuzzy_neuron_opencl_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
)
{
    if (network == NULL ||
        !network->opencl.ready)
    {
        return false;
    }

    return fuzzy_neuron_predict_batch(
        network,
        raw_inputs,
        rows,
        outputs
    );
}

void fuzzy_neuron_opencl_free(
    fuzzy_neuron_network_t *network
)
{
    if (network != NULL)
    {
        fuzzy_neuron_opencl_release(
            &network->opencl
        );
    }
}

#endif
#endif
#endif