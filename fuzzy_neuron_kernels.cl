/* Generic fuzzy_neuron.h dense backend kernels.
 * Rule evaluation stays in C/fuzzy.h. The host uploads normalized rule vectors.
 */

inline float fn_activate(float x, uint kind)
{
    if (kind == 1u) return 1.0f / (1.0f + exp(-x));
    if (kind == 2u) return tanh(x);
    if (kind == 3u) return fmax(x, 0.0f);
    return x;
}

inline float fn_derivative(float y, uint kind)
{
    if (kind == 1u) return y * (1.0f - y);
    if (kind == 2u) return 1.0f - y * y;
    if (kind == 3u) return y > 0.0f ? 1.0f : 0.0f;
    return 1.0f;
}

__kernel void fn_forward(__global const float *rule_inputs, __global const float *weights, __global const float *biases, __global float *activations, __global const uint *layer_counts, __global const uint *weight_offsets, __global const uint *bias_offsets, __global const uint *activation_kinds, uint sample_count, uint rule_count, uint layer_count, uint neuron_count)
{
    uint sample = get_global_id(0);
    uint source_count = rule_count;
    uint source_offset = 0u;
    uint destination_offset = rule_count;

    if (sample >= sample_count) return;

    for (uint rule = 0u; rule < rule_count; rule++)
    {
        activations[sample * neuron_count + rule] = rule_inputs[sample * rule_count + rule];
    }

    for (uint layer = 0u; layer < layer_count; layer++)
    {
        uint destination_count = layer_counts[layer];

        for (uint destination = 0u; destination < destination_count; destination++)
        {
            float sum = biases[bias_offsets[layer] + destination];

            for (uint source = 0u; source < source_count; source++)
            {
                sum += activations[sample * neuron_count + source_offset + source] * weights[weight_offsets[layer] + destination * source_count + source];
            }

            activations[sample * neuron_count + destination_offset + destination] = fn_activate(sum, activation_kinds[layer]);
        }

        source_offset = destination_offset;
        destination_offset += destination_count;
        source_count = destination_count;
    }
}

__kernel void fn_backward(__global const float *targets, __global const float *weights, __global const float *activations, __global float *deltas, __global float *weight_gradients, __global float *bias_gradients, __global const uint *layer_counts, __global const uint *weight_offsets, __global const uint *bias_offsets, __global const uint *activation_kinds, uint sample_count, uint rule_count, uint output_count, uint layer_count, uint neuron_count, uint weight_count, uint bias_count)
{
    uint sample = get_global_id(0);
    uint last_layer = layer_count - 1u;
    uint output_offset = neuron_count - output_count;

    if (sample >= sample_count) return;

    for (uint output = 0u; output < output_count; output++)
    {
        float value = activations[sample * neuron_count + output_offset + output];
        float error = value - targets[sample * output_count + output];

        deltas[sample * neuron_count + output_offset + output] = error * fn_derivative(value, activation_kinds[last_layer]);
    }

    for (uint reverse = 0u; reverse < layer_count; reverse++)
    {
        uint layer = layer_count - 1u - reverse;
        uint source_count = layer == 0u ? rule_count : layer_counts[layer - 1u];
        uint destination_count = layer_counts[layer];
        uint source_offset = 0u;
        uint destination_offset;

        if (layer > 0u)
        {
            source_offset = rule_count;

            for (uint prior = 0u; prior + 1u < layer; prior++)
            {
                source_offset += layer_counts[prior];
            }
        }

        destination_offset = source_offset + source_count;

        if (layer + 1u < layer_count)
        {
            uint next_count = layer_counts[layer + 1u];
            uint next_offset = destination_offset + destination_count;

            for (uint destination = 0u; destination < destination_count; destination++)
            {
                float propagated = 0.0f;

                for (uint next = 0u; next < next_count; next++)
                {
                    propagated += weights[weight_offsets[layer + 1u] + next * destination_count + destination] * deltas[sample * neuron_count + next_offset + next];
                }

                deltas[sample * neuron_count + destination_offset + destination] = propagated * fn_derivative(activations[sample * neuron_count + destination_offset + destination], activation_kinds[layer]);
            }
        }

        for (uint destination = 0u; destination < destination_count; destination++)
        {
            float delta = deltas[sample * neuron_count + destination_offset + destination];

            bias_gradients[sample * bias_count + bias_offsets[layer] + destination] = delta;

            for (uint source = 0u; source < source_count; source++)
            {
                weight_gradients[sample * weight_count + weight_offsets[layer] + destination * source_count + source] = delta * activations[sample * neuron_count + source_offset + source];
            }
        }
    }
}

__kernel void fn_update(__global float *parameters, __global const float *gradients, uint parameter_count, uint sample_count, float learning_rate)
{
    uint parameter = get_global_id(0);
    float sum = 0.0f;

    if (parameter >= parameter_count) return;

    for (uint sample = 0u; sample < sample_count; sample++)
    {
        sum += gradients[sample * parameter_count + parameter];
    }

    parameters[parameter] -= learning_rate * sum / (float)sample_count;
}