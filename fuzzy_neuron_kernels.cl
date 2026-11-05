#define FN_LOSS_MSE 0u
#define FN_LOSS_HUBER 1u
#define FN_ACTIVATION_LINEAR 0u
#define FN_ACTIVATION_SIGMOID 1u
#define FN_ACTIVATION_TANH 2u
#define FN_ACTIVATION_RELU 3u

inline float fn_activate(float value, uint kind)
{
    if (kind == FN_ACTIVATION_SIGMOID) return native_recip(1.0f + native_exp(-clamp(value, -80.0f, 80.0f)));
    if (kind == FN_ACTIVATION_TANH) return tanh(value);
    if (kind == FN_ACTIVATION_RELU) return fmax(value, 0.0f);
    return value;
}

inline float fn_derivative_from_output(float output, uint kind)
{
    if (kind == FN_ACTIVATION_SIGMOID) return output * (1.0f - output);
    if (kind == FN_ACTIVATION_TANH) return fma(-output, output, 1.0f);
    if (kind == FN_ACTIVATION_RELU) return output > 0.0f ? 1.0f : 0.0f;
    return 1.0f;
}

__kernel void fn_copy_rules(__global const float *restrict rules, __global float *restrict activations, uint sample_count, uint rule_count, uint neuron_count)
{
    size_t index = get_global_id(0);
    size_t total = (size_t)sample_count * rule_count;
    if (index >= total) return;
    size_t sample = index / rule_count;
    size_t rule = index - sample * rule_count;
    activations[sample * neuron_count + rule] = rules[index];
}

__kernel void fn_forward_gemm(__global const float *restrict weights, __global const float *restrict biases, __global float *restrict activations, uint sample_count, uint neuron_count, uint source_offset, uint source_count, uint destination_offset, uint destination_count, uint weight_offset, uint bias_offset, uint activation_kind)
{
    uint sample = get_global_id(0);
    uint destination = get_global_id(1);
    if (sample >= sample_count || destination >= destination_count) return;
    size_t activation_base = (size_t)sample * neuron_count;
    size_t weight_base = (size_t)weight_offset + (size_t)destination * source_count;
    float sum = biases[bias_offset + destination];
    uint source = 0u;
    for (; source + 3u < source_count; source += 4u)
    {
        float4 a = vload4(0, activations + activation_base + source_offset + source);
        float4 w = vload4(0, weights + weight_base + source);
        sum = fma(a.s0, w.s0, sum);
        sum = fma(a.s1, w.s1, sum);
        sum = fma(a.s2, w.s2, sum);
        sum = fma(a.s3, w.s3, sum);
    }
    for (; source < source_count; ++source) sum = fma(activations[activation_base + source_offset + source], weights[weight_base + source], sum);
    activations[activation_base + destination_offset + destination] = fn_activate(sum, activation_kind);
}

__kernel void fn_output_delta(__global const float *restrict targets, __global const float *restrict activations, __global float *restrict deltas, __global float *restrict losses, uint sample_count, uint output_count, uint neuron_count, uint output_offset, uint activation_kind, uint loss_method, float huber_delta)
{
    size_t index = get_global_id(0);
    size_t total = (size_t)sample_count * output_count;
    if (index >= total) return;
    size_t sample = index / output_count;
    size_t output = index - sample * output_count;
    size_t activation_index = sample * neuron_count + output_offset + output;
    float prediction = activations[activation_index];
    float error = prediction - targets[index];
    float gradient = error;
    float loss = error * error;
    if (loss_method == FN_LOSS_HUBER)
    {
        float magnitude = fabs(error);
        int quadratic = magnitude <= huber_delta;
        gradient = quadratic ? error / huber_delta : copysign(1.0f, error);
        loss = quadratic ? 0.5f * error * error / huber_delta : magnitude - 0.5f * huber_delta;
    }
    deltas[activation_index] = gradient * fn_derivative_from_output(prediction, activation_kind);
    losses[index] = loss;
}

__kernel void fn_hidden_delta_gemm(__global const float *restrict weights, __global const float *restrict activations, __global float *restrict deltas, uint sample_count, uint neuron_count, uint current_offset, uint current_count, uint next_offset, uint next_count, uint next_weight_offset, uint activation_kind)
{
    uint sample = get_global_id(0);
    uint current = get_global_id(1);
    if (sample >= sample_count || current >= current_count) return;
    size_t base = (size_t)sample * neuron_count;
    float sum = 0.0f;
    for (uint next = 0u; next < next_count; ++next) sum = fma(weights[(size_t)next_weight_offset + (size_t)next * current_count + current], deltas[base + next_offset + next], sum);
    size_t index = base + current_offset + current;
    deltas[index] = sum * fn_derivative_from_output(activations[index], activation_kind);
}

__kernel void fn_weight_gradient_gemm(__global const float *restrict activations, __global const float *restrict deltas, __global float *restrict gradients, uint sample_count, uint neuron_count, uint source_offset, uint source_count, uint destination_offset, uint destination_count, uint weight_offset)
{
    uint source = get_global_id(0);
    uint destination = get_global_id(1);
    if (source >= source_count || destination >= destination_count) return;
    float gradient = 0.0f;
    uint sample = 0u;
    for (; sample + 3u < sample_count; sample += 4u)
    {
        size_t base0 = (size_t)sample * neuron_count;
        size_t base1 = base0 + neuron_count;
        size_t base2 = base1 + neuron_count;
        size_t base3 = base2 + neuron_count;
        gradient = fma(deltas[base0 + destination_offset + destination], activations[base0 + source_offset + source], gradient);
        gradient = fma(deltas[base1 + destination_offset + destination], activations[base1 + source_offset + source], gradient);
        gradient = fma(deltas[base2 + destination_offset + destination], activations[base2 + source_offset + source], gradient);
        gradient = fma(deltas[base3 + destination_offset + destination], activations[base3 + source_offset + source], gradient);
    }
    for (; sample < sample_count; ++sample)
    {
        size_t base = (size_t)sample * neuron_count;
        gradient = fma(deltas[base + destination_offset + destination], activations[base + source_offset + source], gradient);
    }
    gradients[(size_t)weight_offset + (size_t)destination * source_count + source] = gradient;
}

__kernel void fn_bias_gradient(__global const float *restrict deltas, __global float *restrict gradients, uint sample_count, uint neuron_count, uint destination_offset, uint destination_count, uint bias_offset)
{
    uint destination = get_global_id(0);
    if (destination >= destination_count) return;
    float gradient = 0.0f;
    for (uint sample = 0u; sample < sample_count; ++sample) gradient += deltas[(size_t)sample * neuron_count + destination_offset + destination];
    gradients[bias_offset + destination] = gradient;
}

__kernel void fn_apply_weights(__global float *weights, __global const float *gradients, uint parameter_count, uint weight_offset, uint sample_count, float learning_rate)
{
    uint parameter = get_global_id(0);
    if (parameter >= parameter_count) return;
    size_t index = (size_t)weight_offset + parameter;
    weights[index] = fma(-learning_rate / (float)sample_count, gradients[index], weights[index]);
}

__kernel void fn_apply_biases(__global float *biases, __global const float *gradients, uint parameter_count, uint bias_offset, uint sample_count, float learning_rate)
{
    uint parameter = get_global_id(0);
    if (parameter >= parameter_count) return;
    size_t index = (size_t)bias_offset + parameter;
    biases[index] = fma(-learning_rate / (float)sample_count, gradients[index], biases[index]);
}

__kernel void fn_adam_apply(__global float *parameters, __global const float *gradients, __global float *first_moment, __global float *second_moment, uint parameter_count, uint parameter_offset, uint sample_count, float alpha, float beta1, float beta2, float epsilon)
{
    uint parameter = get_global_id(0);
    size_t index;
    float gradient;
    float moment1;
    float moment2;
    if (parameter >= parameter_count) return;
    index = (size_t)parameter_offset + parameter;
    gradient = gradients[index] / (float)sample_count;
    moment1 = fma(1.0f - beta1, gradient, beta1 * first_moment[index]);
    moment2 = fma(1.0f - beta2, gradient * gradient, beta2 * second_moment[index]);
    first_moment[index] = moment1;
    second_moment[index] = moment2;
    parameters[index] -= alpha * moment1 / (sqrt(moment2) + epsilon);
}
