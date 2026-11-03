/*
 * Minimal fuzzy-neuron demonstration.
 *
 * Build with fuzzy_core.c (CPU-only) or with fuzzy_gpu_backend.c
 * (if you intentionally want the OpenCL-enabled library build).
 */
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
#include <stdio.h>
#include <stddef.h>

/*
 * fuzzy_output_function_t is declared by fuzzy.h:
 *     typedef float (*fuzzy_output_function_t)(float);
 *
 * fuzzy.h provides membership-function shapes through fuzzy_function().
 * Here we use a sigmoid-shaped fuzzy function as the neuron's activation.
 */
FUZZY_VAR(neuron_sigmoid, FUZZY_SHAPE_SIGMOID, 1.0f, 0.15f, 0.0f)

/* First struct: the data/configuration belonging to one neuron. */
typedef struct fuzzy_neuron_data {
    const float *inputs;
    const float *weights;
    size_t input_count;
    fuzzy_output_function_t activation;
} fuzzy_neuron_data_t;

/* Second struct: one neuron instance, suitable for an array of neurons. */
typedef struct fuzzy_neuron {
    fuzzy_neuron_data_t data;
    float output;
} fuzzy_neuron_t;

static int fuzzy_neuron_init(
    fuzzy_neuron_t *neuron,
    const float *inputs,
    const float *weights,
    size_t input_count,
    fuzzy_output_function_t activation
)
{
    if (neuron == NULL || inputs == NULL || weights == NULL ||
        input_count == 0u || activation == NULL) {
        return 0;
    }

    neuron->data.inputs = inputs;
    neuron->data.weights = weights;
    neuron->data.input_count = input_count;
    neuron->data.activation = activation;
    neuron->output = 0.0f;

    return 1;
}

static float fuzzy_neuron_evaluate(fuzzy_neuron_t *neuron)
{
    size_t i;
    float weighted_sum = 0.0f;

    if (neuron == NULL || neuron->data.activation == NULL ||
        neuron->data.inputs == NULL || neuron->data.weights == NULL) {
        return 0.0f;
    }

    for (i = 0u; i < neuron->data.input_count; ++i) {
        weighted_sum += neuron->data.inputs[i] * neuron->data.weights[i];
    }

    neuron->output = neuron->data.activation(weighted_sum);
    return neuron->output;
}

int main(void)
{
    /* Inputs can be shared by neurons; each neuron has its own weights. */
    const float input_a[] = { 0.25f, 0.80f, 0.40f };
    const float input_b[] = { 0.90f, 0.10f, 0.65f };

    const float weights_a[] = { 0.20f, 0.50f, 0.30f };
    const float weights_b[] = { 0.70f, 0.15f, 0.15f };

    fuzzy_neuron_t neuron[2];

    if (!fuzzy_neuron_init(
            &neuron[0], input_a, weights_a, 3u, neuron_sigmoid) ||
        !fuzzy_neuron_init(
            &neuron[1], input_b, weights_b, 3u, neuron_sigmoid)) {
        fprintf(stderr, "Failed to initialise fuzzy neuron(s).\n");
        return 1;
    }

    printf("Neuron 0: %.6f\n", fuzzy_neuron_evaluate(&neuron[0]));
    printf("Neuron 1: %.6f\n", fuzzy_neuron_evaluate(&neuron[1]));

    return 0;
}
