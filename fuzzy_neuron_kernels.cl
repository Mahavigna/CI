#define FN_LOSS_MSE 0u
#define FN_LOSS_HUBER 1u
#define FN_ACTIVATION_LINEAR 0u
#define FN_ACTIVATION_SIGMOID 1u
#define FN_ACTIVATION_TANH 2u
#define FN_ACTIVATION_RELU 3u
#define FN_PREMISE_RAMP 0u
#define FN_EXPR_MEMBERSHIP 0u
#define FN_EXPR_NOT 1u
#define FN_EXPR_AND 2u
#define FN_EXPR_OR 3u
#define FN_LOGIC_STANDARD 0u
#define FN_LOGIC_ALGEBRAIC 1u
#define FN_LOGIC_BOUNDED 2u

typedef struct fn_premise
{
    uint input_index;
    uint shape;
    uint parameter_offset;
    uint parameter_count;
    uint trainable_mask;
    uint reserved0;
    float hedge;
    float domain_minimum;
    float domain_maximum;
    float epsilon;
} fn_premise_t;

typedef struct fn_expression
{
    uint kind;
    uint left;
    uint right;
    uint value;
} fn_expression_t;

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

inline float fn_logic_and(float left, float right, uint method)
{
    if (method == FN_LOGIC_ALGEBRAIC) return left * right;
    if (method == FN_LOGIC_BOUNDED) return fmax(0.0f, left + right - 1.0f);
    return fmin(left, right);
}

inline float fn_logic_or(float left, float right, uint method)
{
    if (method == FN_LOGIC_ALGEBRAIC) return left + right - left * right;
    if (method == FN_LOGIC_BOUNDED) return fmin(1.0f, left + right);
    return fmax(left, right);
}

inline float fn_ramp(float x, float a, float b, float rising)
{
    if (!(b > a)) return 0.0f;
    if (x <= a) return rising != 0.0f ? 0.0f : 1.0f;
    if (x >= b) return rising != 0.0f ? 1.0f : 0.0f;
    float value = (x - a) / (b - a);
    return rising != 0.0f ? value : 1.0f - value;
}

__kernel void fn_premise_forward(__global const float *restrict raw_inputs, __global const fn_premise_t *restrict premises, __global const float *restrict parameters, __global float *restrict memberships, uint sample_count, uint input_count, uint premise_count)
{
    uint sample = get_global_id(0);
    uint premise_index = get_global_id(1);
    if (sample >= sample_count || premise_index >= premise_count) return;
    fn_premise_t premise = premises[premise_index];
    float x = raw_inputs[(size_t)sample * input_count + premise.input_index];
    float value = 0.0f;
    if (premise.shape == FN_PREMISE_RAMP)
    {
        uint offset = premise.parameter_offset;
        value = fn_ramp(x, parameters[offset], parameters[offset + 1u], parameters[offset + 2u]);
    }
    value = pow(clamp(value, 0.0f, 1.0f), fmax(premise.hedge, premise.epsilon));
    memberships[(size_t)sample * premise_count + premise_index] = value;
}

__kernel void fn_expression_forward(__global const fn_expression_t *restrict expressions, __global const uint *restrict rule_roots, __global const float *restrict memberships, __global float *restrict expression_values, __global float *restrict raw_rules, uint sample_count, uint premise_count, uint expression_count, uint rule_count, uint logic_method)
{
    uint sample = get_global_id(0);
    if (sample >= sample_count) return;
    size_t expression_base = (size_t)sample * expression_count;
    size_t membership_base = (size_t)sample * premise_count;
    for (uint node_index = 0u; node_index < expression_count; node_index++)
    {
        fn_expression_t node = expressions[node_index];
        float value;
        if (node.kind == FN_EXPR_MEMBERSHIP) value = memberships[membership_base + node.value];
        else if (node.kind == FN_EXPR_NOT) value = 1.0f - expression_values[expression_base + node.left];
        else if (node.kind == FN_EXPR_AND) value = fn_logic_and(expression_values[expression_base + node.left], expression_values[expression_base + node.right], logic_method);
        else value = fn_logic_or(expression_values[expression_base + node.left], expression_values[expression_base + node.right], logic_method);
        expression_values[expression_base + node_index] = value;
    }
    for (uint rule = 0u; rule < rule_count; rule++) raw_rules[(size_t)sample * rule_count + rule] = expression_values[expression_base + rule_roots[rule]];
}

__kernel void fn_normalize_rules(__global const float *restrict raw_rules, __global float *restrict activations, uint sample_count, uint rule_count, uint neuron_count)
{
    uint sample = get_global_id(0);
    if (sample >= sample_count) return;
    size_t rule_base = (size_t)sample * rule_count;
    size_t activation_base = (size_t)sample * neuron_count;
    float total = 0.0f;
    for (uint rule = 0u; rule < rule_count; rule++) total += raw_rules[rule_base + rule];
    if (total <= 1.0e-12f)
    {
        for (uint rule = 0u; rule < rule_count; rule++) activations[activation_base + rule] = 0.0f;
        return;
    }
    for (uint rule = 0u; rule < rule_count; rule++) activations[activation_base + rule] = raw_rules[rule_base + rule] / total;
}

__kernel void fn_forward_gemm(__global const float *restrict weights, __global const float *restrict biases, __global float *restrict activations, uint sample_count, uint neuron_count, uint source_offset, uint source_count, uint destination_offset, uint destination_count, uint weight_offset, uint bias_offset, uint activation_kind)
{
    uint sample = get_global_id(0);
    uint destination = get_global_id(1);
    if (sample >= sample_count || destination >= destination_count) return;
    size_t activation_base = (size_t)sample * neuron_count;
    size_t weight_base = (size_t)weight_offset + (size_t)destination * source_count;
    float sum = biases[bias_offset + destination];
    for (uint source = 0u; source < source_count; source++) sum = fma(activations[activation_base + source_offset + source], weights[weight_base + source], sum);
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
    for (uint next = 0u; next < next_count; next++) sum = fma(weights[(size_t)next_weight_offset + (size_t)next * current_count + current], deltas[base + next_offset + next], sum);
    size_t index = base + current_offset + current;
    deltas[index] = sum * fn_derivative_from_output(activations[index], activation_kind);
}

__kernel void fn_input_delta(__global const float *restrict weights, __global const float *restrict deltas, __global float *restrict normalized_rule_gradients, uint sample_count, uint neuron_count, uint rule_count, uint first_destination_offset, uint first_destination_count, uint first_weight_offset)
{
    uint sample = get_global_id(0);
    uint rule = get_global_id(1);
    if (sample >= sample_count || rule >= rule_count) return;
    size_t base = (size_t)sample * neuron_count;
    float gradient = 0.0f;
    for (uint destination = 0u; destination < first_destination_count; destination++) gradient = fma(weights[(size_t)first_weight_offset + (size_t)destination * rule_count + rule], deltas[base + first_destination_offset + destination], gradient);
    normalized_rule_gradients[(size_t)sample * rule_count + rule] = gradient;
}

__kernel void fn_normalize_backward(__global const float *restrict raw_rules, __global const float *restrict normalized_gradients, __global float *restrict raw_rule_gradients, uint sample_count, uint rule_count)
{
    uint sample = get_global_id(0);
    if (sample >= sample_count) return;
    size_t base = (size_t)sample * rule_count;
    float total = 0.0f;
    float weighted = 0.0f;
    for (uint rule = 0u; rule < rule_count; rule++)
    {
        total += raw_rules[base + rule];
        weighted += normalized_gradients[base + rule] * raw_rules[base + rule];
    }
    if (total <= 1.0e-12f)
    {
        for (uint rule = 0u; rule < rule_count; rule++) raw_rule_gradients[base + rule] = 0.0f;
        return;
    }
    float denominator = total * total;
    for (uint rule = 0u; rule < rule_count; rule++) raw_rule_gradients[base + rule] = (normalized_gradients[base + rule] * total - weighted) / denominator;
}

__kernel void fn_expression_backward(__global const fn_expression_t *restrict expressions, __global const uint *restrict rule_roots, __global const float *restrict expression_values, __global const float *restrict raw_rule_gradients, __global float *restrict expression_gradients, __global float *restrict membership_gradients, uint sample_count, uint premise_count, uint expression_count, uint rule_count, uint logic_method)
{
    uint sample = get_global_id(0);
    if (sample >= sample_count) return;
    size_t expression_base = (size_t)sample * expression_count;
    size_t membership_base = (size_t)sample * premise_count;
    for (uint node = 0u; node < expression_count; node++) expression_gradients[expression_base + node] = 0.0f;
    for (uint premise = 0u; premise < premise_count; premise++) membership_gradients[membership_base + premise] = 0.0f;
    for (uint rule = 0u; rule < rule_count; rule++) expression_gradients[expression_base + rule_roots[rule]] += raw_rule_gradients[(size_t)sample * rule_count + rule];
    for (uint reverse = expression_count; reverse-- > 0u;)
    {
        fn_expression_t node = expressions[reverse];
        float incoming = expression_gradients[expression_base + reverse];
        if (node.kind == FN_EXPR_MEMBERSHIP)
        {
            membership_gradients[membership_base + node.value] += incoming;
        }
        else if (node.kind == FN_EXPR_NOT)
        {
            expression_gradients[expression_base + node.left] -= incoming;
        }
        else
        {
            float left_value = expression_values[expression_base + node.left];
            float right_value = expression_values[expression_base + node.right];
            if (logic_method == FN_LOGIC_ALGEBRAIC)
            {
                if (node.kind == FN_EXPR_AND)
                {
                    expression_gradients[expression_base + node.left] += incoming * right_value;
                    expression_gradients[expression_base + node.right] += incoming * left_value;
                }
                else
                {
                    expression_gradients[expression_base + node.left] += incoming * (1.0f - right_value);
                    expression_gradients[expression_base + node.right] += incoming * (1.0f - left_value);
                }
            }
            else
            {
                int left_wins = node.kind == FN_EXPR_AND ? left_value < right_value : left_value > right_value;
                int right_wins = node.kind == FN_EXPR_AND ? right_value < left_value : right_value > left_value;
                if (!left_wins && !right_wins)
                {
                    expression_gradients[expression_base + node.left] += 0.5f * incoming;
                    expression_gradients[expression_base + node.right] += 0.5f * incoming;
                }
                else if (left_wins) expression_gradients[expression_base + node.left] += incoming;
                else expression_gradients[expression_base + node.right] += incoming;
            }
        }
    }
}

__kernel void fn_premise_gradient(__global const float *restrict raw_inputs, __global const fn_premise_t *restrict premises, __global const float *restrict parameters, __global const float *restrict memberships, __global const float *restrict membership_gradients, __global float *restrict parameter_gradients, uint sample_count, uint input_count, uint premise_count, uint parameter_count)
{
    uint parameter = get_global_id(0);
    if (parameter >= parameter_count) return;
    float gradient = 0.0f;
    for (uint premise_index = 0u; premise_index < premise_count; premise_index++)
    {
        fn_premise_t premise = premises[premise_index];
        if (parameter < premise.parameter_offset || parameter >= premise.parameter_offset + premise.parameter_count) continue;
        uint local_parameter = parameter - premise.parameter_offset;
        if ((premise.trainable_mask & (1u << local_parameter)) == 0u) continue;
        if (premise.shape != FN_PREMISE_RAMP || local_parameter > 1u) continue;
        float a = parameters[premise.parameter_offset];
        float b = parameters[premise.parameter_offset + 1u];
        float rising = parameters[premise.parameter_offset + 2u];
        float width = b - a;
        if (!(width > premise.epsilon)) continue;
        for (uint sample = 0u; sample < sample_count; sample++)
        {
            float x = raw_inputs[(size_t)sample * input_count + premise.input_index];
            if (!(x > a && x < b)) continue;
            float base = rising != 0.0f ? (x - a) / width : 1.0f - (x - a) / width;
            float dbase;
            if (rising != 0.0f) dbase = local_parameter == 0u ? (x - b) / (width * width) : -(x - a) / (width * width);
            else dbase = local_parameter == 0u ? (b - x) / (width * width) : (x - a) / (width * width);
            float hedge = fmax(premise.hedge, premise.epsilon);
            float hedge_derivative = hedge * pow(fmax(base, premise.epsilon), hedge - 1.0f);
            gradient += membership_gradients[(size_t)sample * premise_count + premise_index] * hedge_derivative * dbase;
        }
    }
    parameter_gradients[parameter] = gradient;
}

__kernel void fn_weight_gradient_gemm(__global const float *restrict activations, __global const float *restrict deltas, __global float *restrict gradients, uint sample_count, uint neuron_count, uint source_offset, uint source_count, uint destination_offset, uint destination_count, uint weight_offset)
{
    uint source = get_global_id(0);
    uint destination = get_global_id(1);
    if (source >= source_count || destination >= destination_count) return;
    float gradient = 0.0f;
    for (uint sample = 0u; sample < sample_count; sample++)
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
    for (uint sample = 0u; sample < sample_count; sample++) gradient += deltas[(size_t)sample * neuron_count + destination_offset + destination];
    gradients[bias_offset + destination] = gradient;
}

__kernel void fn_apply_parameters(__global float *parameters, __global const float *gradients, uint parameter_count, uint parameter_offset, uint sample_count, float learning_rate)
{
    uint parameter = get_global_id(0);
    if (parameter >= parameter_count) return;
    size_t index = (size_t)parameter_offset + parameter;
    parameters[index] = fma(-learning_rate / (float)sample_count, gradients[index], parameters[index]);
}

__kernel void fn_adam_apply(__global float *parameters, __global const float *gradients, __global float *first_moment, __global float *second_moment, uint parameter_count, uint parameter_offset, uint sample_count, float alpha, float beta1, float beta2, float epsilon)
{
    uint parameter = get_global_id(0);
    if (parameter >= parameter_count) return;
    size_t index = (size_t)parameter_offset + parameter;
    float gradient = gradients[index] / (float)sample_count;
    float moment1 = fma(1.0f - beta1, gradient, beta1 * first_moment[index]);
    float moment2 = fma(1.0f - beta2, gradient * gradient, beta2 * second_moment[index]);
    first_moment[index] = moment1;
    second_moment[index] = moment2;
    parameters[index] -= alpha * moment1 / (sqrt(moment2) + epsilon);
}

__kernel void fn_project_premises(__global const fn_premise_t *restrict premises, __global float *parameters, uint premise_count)
{
    uint premise_index = get_global_id(0);
    if (premise_index >= premise_count) return;
    fn_premise_t premise = premises[premise_index];
    if (premise.shape != FN_PREMISE_RAMP) return;
    uint offset = premise.parameter_offset;
    float a = clamp(parameters[offset], premise.domain_minimum, premise.domain_maximum);
    float b = clamp(parameters[offset + 1u], premise.domain_minimum, premise.domain_maximum);
    if (b <= a + premise.epsilon)
    {
        float middle = 0.5f * (a + b);
        a = clamp(middle - 0.5f * premise.epsilon, premise.domain_minimum, premise.domain_maximum - premise.epsilon);
        b = a + premise.epsilon;
    }
    parameters[offset] = a;
    parameters[offset + 1u] = b;
}
