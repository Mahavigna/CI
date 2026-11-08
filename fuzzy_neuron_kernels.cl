/*
 * Work-group sizing is intentionally unspecified.
 *
 * No reqd_work_group_size attribute is used.
 * No work_group_size_hint attribute is used.
 * No Intel, AMD, or NVIDIA work-group dimensions are hardcoded.
 *
 * The OpenCL implementation selects the local work-group size automatically
 * for the selected device.
 */

#define FN_LOSS_MSE 0u
#define FN_LOSS_HUBER 1u

#define FN_ACTIVATION_LINEAR 0u
#define FN_ACTIVATION_SIGMOID 1u
#define FN_ACTIVATION_TANH 2u
#define FN_ACTIVATION_RELU 3u

#define FN_SHAPE_RAMP 0u
#define FN_SHAPE_TRIANGLE 1u
#define FN_SHAPE_TRAPEZOID 2u
#define FN_SHAPE_SMF 3u
#define FN_SHAPE_ZMF 4u
#define FN_SHAPE_GAUSSIAN 5u
#define FN_SHAPE_BELL 6u
#define FN_SHAPE_SIGMOID 7u
#define FN_SHAPE_PIMF 8u
#define FN_SHAPE_DSIGMOID 9u
#define FN_SHAPE_PSIGMOID 10u
#define FN_SHAPE_GAUSSIAN2 11u

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
}
fn_premise_t;

typedef struct fn_expression
{
    uint kind;
    uint left;
    uint right;
    uint value;
}
fn_expression_t;

inline float fn_activate(float value, uint kind)
{
    if (kind == FN_ACTIVATION_SIGMOID)
    {
        return 1.0f / (1.0f + exp(-clamp(value, -80.0f, 80.0f)));
    }

    if (kind == FN_ACTIVATION_TANH)
    {
        return tanh(value);
    }

    if (kind == FN_ACTIVATION_RELU)
    {
        return fmax(value, 0.0f);
    }

    return value;
}

inline float fn_derivative_from_output(float output, uint kind)
{
    if (kind == FN_ACTIVATION_SIGMOID)
    {
        return output * (1.0f - output);
    }

    if (kind == FN_ACTIVATION_TANH)
    {
        return fma(-output, output, 1.0f);
    }

    if (kind == FN_ACTIVATION_RELU)
    {
        return output > 0.0f ? 1.0f : 0.0f;
    }

    return 1.0f;
}

inline float fn_logic_and(float left, float right, uint method)
{
    if (method == FN_LOGIC_ALGEBRAIC)
    {
        return left * right;
    }

    if (method == FN_LOGIC_BOUNDED)
    {
        return fmax(0.0f, left + right - 1.0f);
    }

    return fmin(left, right);
}

inline float fn_logic_or(float left, float right, uint method)
{
    if (method == FN_LOGIC_ALGEBRAIC)
    {
        return left + right - left * right;
    }

    if (method == FN_LOGIC_BOUNDED)
    {
        return fmin(1.0f, left + right);
    }

    return fmax(left, right);
}

inline float fn_sigmoid(float slope, float center, float x)
{
    return 1.0f / (1.0f + exp(-clamp(slope * (x - center), -80.0f, 80.0f)));
}

inline float fn_parameter(__global const float *parameters, uint index, uint shifted_index, float shift)
{
    return parameters[index] + (index == shifted_index ? shift : 0.0f);
}

inline float fn_shape_shift(uint shape, float x, __global const float *parameters, uint offset, uint count, float epsilon, uint shifted_index, float shift)
{
    if (shape == FN_SHAPE_RAMP && count == 3u)
    {
        float a = fn_parameter(parameters, offset, shifted_index, shift);
        float b = fn_parameter(parameters, offset + 1u, shifted_index, shift);
        int rising = fn_parameter(parameters, offset + 2u, shifted_index, shift) != 0.0f;

        if (!(b > a))
        {
            return 0.0f;
        }

        if (x <= a)
        {
            return rising ? 0.0f : 1.0f;
        }

        if (x >= b)
        {
            return rising ? 1.0f : 0.0f;
        }

        return rising
            ? (x - a) / (b - a)
            : (b - x) / (b - a);
    }

    if (shape == FN_SHAPE_TRIANGLE && count == 3u)
    {
        float a = fn_parameter(parameters, offset, shifted_index, shift);
        float b = fn_parameter(parameters, offset + 1u, shifted_index, shift);
        float c = fn_parameter(parameters, offset + 2u, shifted_index, shift);

        if (!(a < b && b < c) || x <= a || x >= c)
        {
            return 0.0f;
        }

        return x <= b
            ? (x - a) / (b - a)
            : (c - x) / (c - b);
    }

    if (shape == FN_SHAPE_TRAPEZOID && count == 4u)
    {
        float a = fn_parameter(parameters, offset, shifted_index, shift);
        float b = fn_parameter(parameters, offset + 1u, shifted_index, shift);
        float c = fn_parameter(parameters, offset + 2u, shifted_index, shift);
        float d = fn_parameter(parameters, offset + 3u, shifted_index, shift);

        if (!(a < b && b <= c && c < d) || x <= a || x >= d)
        {
            return 0.0f;
        }

        if (x >= b && x <= c)
        {
            return 1.0f;
        }

        return x < b
            ? (x - a) / (b - a)
            : (d - x) / (d - c);
    }

    if ((shape == FN_SHAPE_SMF || shape == FN_SHAPE_ZMF) && count == 2u)
    {
        float a = fn_parameter(parameters, offset, shifted_index, shift);
        float b = fn_parameter(parameters, offset + 1u, shifted_index, shift);
        float result;
        float t;

        if (!(b > a))
        {
            return 0.0f;
        }

        if (x <= a)
        {
            result = 0.0f;
        }
        else if (x >= b)
        {
            result = 1.0f;
        }
        else if (x <= 0.5f * (a + b))
        {
            t = (x - a) / (b - a);
            result = 2.0f * t * t;
        }
        else
        {
            t = (b - x) / (b - a);
            result = 1.0f - 2.0f * t * t;
        }

        return shape == FN_SHAPE_ZMF
            ? 1.0f - result
            : result;
    }

    if (shape == FN_SHAPE_GAUSSIAN && count == 2u)
    {
        float mean = fn_parameter(parameters, offset, shifted_index, shift);
        float sigma = fabs(fn_parameter(parameters, offset + 1u, shifted_index, shift));
        float difference;

        if (sigma <= epsilon)
        {
            return 0.0f;
        }

        difference = (x - mean) / sigma;

        return exp(-0.5f * difference * difference);
    }

    if (shape == FN_SHAPE_BELL && count == 3u)
    {
        float width = fn_parameter(parameters, offset, shifted_index, shift);
        float slope = fn_parameter(parameters, offset + 1u, shifted_index, shift);
        float center = fn_parameter(parameters, offset + 2u, shifted_index, shift);

        if (fabs(width) <= epsilon)
        {
            return 0.0f;
        }

        return 1.0f / (1.0f + pow(fabs((x - center) / (0.5f * width)), 2.0f * slope));
    }

    if (shape == FN_SHAPE_SIGMOID && count == 2u)
    {
        return fn_sigmoid(
            fn_parameter(parameters, offset, shifted_index, shift),
            fn_parameter(parameters, offset + 1u, shifted_index, shift),
            x
        );
    }

    if (shape == FN_SHAPE_PIMF && count == 4u)
    {
        float a = fn_parameter(parameters, offset, shifted_index, shift);
        float b = fn_parameter(parameters, offset + 1u, shifted_index, shift);
        float c = fn_parameter(parameters, offset + 2u, shifted_index, shift);
        float d = fn_parameter(parameters, offset + 3u, shifted_index, shift);
        float t;

        if (!(a < b && b <= c && c < d) || x <= a || x >= d)
        {
            return 0.0f;
        }

        if (x >= b && x <= c)
        {
            return 1.0f;
        }

        if (x < b)
        {
            if (x <= 0.5f * (a + b))
            {
                t = (x - a) / (b - a);
                return 2.0f * t * t;
            }

            t = (b - x) / (b - a);
            return 1.0f - 2.0f * t * t;
        }

        if (x <= 0.5f * (c + d))
        {
            t = (x - c) / (d - c);
            return 1.0f - 2.0f * t * t;
        }

        t = (d - x) / (d - c);

        return 2.0f * t * t;
    }

    if ((shape == FN_SHAPE_DSIGMOID || shape == FN_SHAPE_PSIGMOID) && count == 4u)
    {
        float first = fn_sigmoid(
            fn_parameter(parameters, offset, shifted_index, shift),
            fn_parameter(parameters, offset + 1u, shifted_index, shift),
            x
        );

        float second = fn_sigmoid(
            fn_parameter(parameters, offset + 2u, shifted_index, shift),
            fn_parameter(parameters, offset + 3u, shifted_index, shift),
            x
        );

        return shape == FN_SHAPE_DSIGMOID
            ? clamp(first - second, 0.0f, 1.0f)
            : first * second;
    }

    if (shape == FN_SHAPE_GAUSSIAN2 && count == 4u)
    {
        float mean_1 = fn_parameter(parameters, offset, shifted_index, shift);
        float sigma_1 = fabs(fn_parameter(parameters, offset + 1u, shifted_index, shift));
        float mean_2 = fn_parameter(parameters, offset + 2u, shifted_index, shift);
        float sigma_2 = fabs(fn_parameter(parameters, offset + 3u, shifted_index, shift));
        float difference;

        if (sigma_1 <= epsilon || sigma_2 <= epsilon || mean_1 > mean_2)
        {
            return 0.0f;
        }

        if (x < mean_1)
        {
            difference = (x - mean_1) / sigma_1;
            return exp(-0.5f * difference * difference);
        }

        if (x <= mean_2)
        {
            return 1.0f;
        }

        difference = (x - mean_2) / sigma_2;

        return exp(-0.5f * difference * difference);
    }

    return 0.0f;
}

inline float fn_shape(uint shape, float x, __global const float *parameters, uint offset, uint count, float epsilon)
{
    return fn_shape_shift(shape, x, parameters, offset, count, epsilon, 0xffffffffu, 0.0f);
}

__kernel void fn_premise_forward(__global const float *restrict raw_inputs, __global const fn_premise_t *restrict premises, __global const float *restrict parameters, __global float *restrict memberships, uint sample_count, uint input_count, uint premise_count)
{
    uint sample = get_global_id(0);
    uint premise_index = get_global_id(1);
    fn_premise_t premise;
    float base;

    if (sample >= sample_count || premise_index >= premise_count)
    {
        return;
    }

    premise = premises[premise_index];

    base = fn_shape(
        premise.shape,
        raw_inputs[(size_t)sample * input_count + premise.input_index],
        parameters,
        premise.parameter_offset,
        premise.parameter_count,
        premise.epsilon
    );

    memberships[(size_t)sample * premise_count + premise_index] =
        pow(clamp(base, 0.0f, 1.0f), fmax(premise.hedge, premise.epsilon));
}

__kernel void fn_expression_forward(__global const fn_expression_t *restrict expressions, __global const uint *restrict rule_roots, __global const float *restrict memberships, __global float *restrict expression_values, __global float *restrict raw_rules, uint sample_count, uint premise_count, uint expression_count, uint rule_count, uint logic_method)
{
    uint sample = get_global_id(0);
    size_t expression_base;
    size_t membership_base;
    uint expression_index;
    uint rule;

    if (sample >= sample_count)
    {
        return;
    }

    expression_base = (size_t)sample * expression_count;
    membership_base = (size_t)sample * premise_count;

    for (expression_index = 0u; expression_index < expression_count; expression_index++)
    {
        fn_expression_t expression = expressions[expression_index];
        float value;

        if (expression.kind == FN_EXPR_MEMBERSHIP)
        {
            value = memberships[membership_base + expression.value];
        }
        else if (expression.kind == FN_EXPR_NOT)
        {
            value = 1.0f - expression_values[expression_base + expression.left];
        }
        else if (expression.kind == FN_EXPR_AND)
        {
            value = fn_logic_and(
                expression_values[expression_base + expression.left],
                expression_values[expression_base + expression.right],
                logic_method
            );
        }
        else
        {
            value = fn_logic_or(
                expression_values[expression_base + expression.left],
                expression_values[expression_base + expression.right],
                logic_method
            );
        }

        expression_values[expression_base + expression_index] = value;
    }

    for (rule = 0u; rule < rule_count; rule++)
    {
        raw_rules[(size_t)sample * rule_count + rule] =
            expression_values[expression_base + rule_roots[rule]];
    }
}

__kernel void fn_normalize_rules(__global const float *restrict raw_rules, __global float *restrict activations, uint sample_count, uint rule_count, uint neuron_count)
{
    uint sample = get_global_id(0);
    size_t rule_base;
    size_t activation_base;
    float total = 0.0f;
    uint rule;

    if (sample >= sample_count)
    {
        return;
    }

    rule_base = (size_t)sample * rule_count;
    activation_base = (size_t)sample * neuron_count;

    for (rule = 0u; rule < rule_count; rule++)
    {
        total += raw_rules[rule_base + rule];
    }

    for (rule = 0u; rule < rule_count; rule++)
    {
        activations[activation_base + rule] = total > 1.0e-12f
            ? raw_rules[rule_base + rule] / total
            : 0.0f;
    }
}

__kernel void fn_forward_gemm(__global const float *restrict weights, __global const float *restrict biases, __global float *restrict activations, uint sample_count, uint neuron_count, uint source_offset, uint source_count, uint destination_offset, uint destination_count, uint weight_offset, uint bias_offset, uint activation_kind)
{
    uint sample = get_global_id(0);
    uint destination = get_global_id(1);
    size_t activation_base;
    size_t weight_base;
    float sum;
    uint source;

    if (sample >= sample_count || destination >= destination_count)
    {
        return;
    }

    activation_base = (size_t)sample * neuron_count;
    weight_base = (size_t)weight_offset + (size_t)destination * source_count;
    sum = biases[bias_offset + destination];

    for (source = 0u; source < source_count; source++)
    {
        sum = fma(
            activations[activation_base + source_offset + source],
            weights[weight_base + source],
            sum
        );
    }

    activations[activation_base + destination_offset + destination] =
        fn_activate(sum, activation_kind);
}

__kernel void fn_output_delta(__global const float *restrict targets, __global const float *restrict activations, __global float *restrict deltas, __global float *restrict losses, uint sample_count, uint output_count, uint neuron_count, uint output_offset, uint activation_kind, uint loss_method, float huber_delta)
{
    size_t index = get_global_id(0);
    size_t total = (size_t)sample_count * output_count;
    size_t sample;
    size_t output;
    size_t activation_index;
    float prediction;
    float error;
    float gradient;
    float loss;

    if (index >= total)
    {
        return;
    }

    sample = index / output_count;
    output = index - sample * output_count;
    activation_index = sample * neuron_count + output_offset + output;

    prediction = activations[activation_index];
    error = prediction - targets[index];
    gradient = error;
    loss = error * error;

    if (loss_method == FN_LOSS_HUBER)
    {
        float magnitude = fabs(error);
        int quadratic = magnitude <= huber_delta;

        gradient = quadratic
            ? error / huber_delta
            : copysign(1.0f, error);

        loss = quadratic
            ? 0.5f * error * error / huber_delta
            : magnitude - 0.5f * huber_delta;
    }

    deltas[activation_index] =
        gradient *
        fn_derivative_from_output(
            prediction,
            activation_kind
        );

    losses[index] = loss;
}

__kernel void fn_hidden_delta_gemm(__global const float *restrict weights, __global const float *restrict activations, __global float *restrict deltas, uint sample_count, uint neuron_count, uint current_offset, uint current_count, uint next_offset, uint next_count, uint next_weight_offset, uint activation_kind)
{
    uint sample = get_global_id(0);
    uint current = get_global_id(1);
    size_t base;
    size_t activation_index;
    float sum = 0.0f;
    uint next;

    if (sample >= sample_count || current >= current_count)
    {
        return;
    }

    base = (size_t)sample * neuron_count;

    for (next = 0u; next < next_count; next++)
    {
        sum = fma(
            weights[(size_t)next_weight_offset + (size_t)next * current_count + current],
            deltas[base + next_offset + next],
            sum
        );
    }

    activation_index = base + current_offset + current;

    deltas[activation_index] =
        sum * fn_derivative_from_output(activations[activation_index], activation_kind);
}

__kernel void fn_input_delta(__global const float *restrict weights, __global const float *restrict deltas, __global float *restrict normalized_rule_gradients, uint sample_count, uint neuron_count, uint rule_count, uint first_destination_offset, uint first_destination_count, uint first_weight_offset)
{
    uint sample = get_global_id(0);
    uint rule = get_global_id(1);
    size_t base;
    float gradient = 0.0f;
    uint destination;

    if (sample >= sample_count || rule >= rule_count)
    {
        return;
    }

    base = (size_t)sample * neuron_count;

    for (destination = 0u; destination < first_destination_count; destination++)
    {
        gradient = fma(
            weights[(size_t)first_weight_offset + (size_t)destination * rule_count + rule],
            deltas[base + first_destination_offset + destination],
            gradient
        );
    }

    normalized_rule_gradients[(size_t)sample * rule_count + rule] = gradient;
}

__kernel void fn_normalize_backward(__global const float *restrict raw_rules, __global const float *restrict normalized_gradients, __global float *restrict raw_rule_gradients, uint sample_count, uint rule_count)
{
    uint sample = get_global_id(0);
    size_t base;
    float total = 0.0f;
    float weighted = 0.0f;
    uint rule;

    if (sample >= sample_count)
    {
        return;
    }

    base = (size_t)sample * rule_count;

    for (rule = 0u; rule < rule_count; rule++)
    {
        total += raw_rules[base + rule];
        weighted += normalized_gradients[base + rule] * raw_rules[base + rule];
    }

    for (rule = 0u; rule < rule_count; rule++)
    {
        raw_rule_gradients[base + rule] = total > 1.0e-12f
            ? (normalized_gradients[base + rule] * total - weighted) / (total * total)
            : 0.0f;
    }
}

__kernel void fn_expression_backward(__global const fn_expression_t *restrict expressions, __global const uint *restrict rule_roots, __global const float *restrict expression_values, __global const float *restrict raw_rule_gradients, __global float *restrict expression_gradients, __global float *restrict membership_gradients, uint sample_count, uint premise_count, uint expression_count, uint rule_count, uint logic_method)
{
    uint sample = get_global_id(0);
    size_t expression_base;
    size_t membership_base;
    uint expression_index;
    uint premise;
    uint rule;
    uint reverse;

    if (sample >= sample_count)
    {
        return;
    }

    expression_base = (size_t)sample * expression_count;
    membership_base = (size_t)sample * premise_count;

    for (expression_index = 0u; expression_index < expression_count; expression_index++)
    {
        expression_gradients[expression_base + expression_index] = 0.0f;
    }

    for (premise = 0u; premise < premise_count; premise++)
    {
        membership_gradients[membership_base + premise] = 0.0f;
    }

    for (rule = 0u; rule < rule_count; rule++)
    {
        expression_gradients[expression_base + rule_roots[rule]] +=
            raw_rule_gradients[(size_t)sample * rule_count + rule];
    }

    for (reverse = expression_count; reverse-- > 0u;)
    {
        fn_expression_t expression = expressions[reverse];
        float incoming = expression_gradients[expression_base + reverse];

        if (expression.kind == FN_EXPR_MEMBERSHIP)
        {
            membership_gradients[membership_base + expression.value] += incoming;
        }
        else if (expression.kind == FN_EXPR_NOT)
        {
            expression_gradients[expression_base + expression.left] -= incoming;
        }
        else
        {
            float left = expression_values[expression_base + expression.left];
            float right = expression_values[expression_base + expression.right];

            if (logic_method == FN_LOGIC_ALGEBRAIC)
            {
                if (expression.kind == FN_EXPR_AND)
                {
                    expression_gradients[expression_base + expression.left] += incoming * right;
                    expression_gradients[expression_base + expression.right] += incoming * left;
                }
                else
                {
                    expression_gradients[expression_base + expression.left] += incoming * (1.0f - right);
                    expression_gradients[expression_base + expression.right] += incoming * (1.0f - left);
                }
            }
            else if (logic_method == FN_LOGIC_BOUNDED)
            {
                float active = expression.kind == FN_EXPR_AND
                    ? left + right > 1.0f
                    : left + right < 1.0f;

                if (active)
                {
                    expression_gradients[expression_base + expression.left] += incoming;
                    expression_gradients[expression_base + expression.right] += incoming;
                }
            }
            else
            {
                int left_wins = expression.kind == FN_EXPR_AND
                    ? left < right
                    : left > right;

                int right_wins = expression.kind == FN_EXPR_AND
                    ? right < left
                    : right > left;

                if (!left_wins && !right_wins)
                {
                    expression_gradients[expression_base + expression.left] += 0.5f * incoming;
                    expression_gradients[expression_base + expression.right] += 0.5f * incoming;
                }
                else if (left_wins)
                {
                    expression_gradients[expression_base + expression.left] += incoming;
                }
                else
                {
                    expression_gradients[expression_base + expression.right] += incoming;
                }
            }
        }
    }
}

__kernel void fn_premise_gradient(__global const float *restrict raw_inputs, __global const fn_premise_t *restrict premises, __global const float *restrict parameters, __global const float *restrict memberships, __global const float *restrict membership_gradients, __global float *restrict parameter_gradients, uint sample_count, uint input_count, uint premise_count, uint parameter_count, __local float *partial)
{
    uint lane = get_local_id(0);
    uint local_count = get_local_size(0);
    uint parameter = get_group_id(0);
    float gradient = 0.0f;
    uint premise_index;

    if (parameter >= parameter_count)
    {
        return;
    }

    for (premise_index = 0u; premise_index < premise_count; premise_index++)
    {
        fn_premise_t premise = premises[premise_index];
        uint local_parameter;

        if (parameter < premise.parameter_offset ||
            parameter >= premise.parameter_offset + premise.parameter_count)
        {
            continue;
        }

        local_parameter = parameter - premise.parameter_offset;

        if (local_parameter >= 32u ||
            (premise.trainable_mask & (1u << local_parameter)) == 0u)
        {
            continue;
        }

        for (uint sample = lane; sample < sample_count; sample += local_count)
        {
            float x = raw_inputs[(size_t)sample * input_count + premise.input_index];
            float original = parameters[parameter];
            float step = fmax(premise.epsilon, fabs(original) * 1.0e-4f);
            float plus;
            float minus;
            float base;
            float derivative;

            plus = fn_shape_shift(
                premise.shape,
                x,
                parameters,
                premise.parameter_offset,
                premise.parameter_count,
                premise.epsilon,
                parameter,
                step
            );

            minus = fn_shape_shift(
                premise.shape,
                x,
                parameters,
                premise.parameter_offset,
                premise.parameter_count,
                premise.epsilon,
                parameter,
                -step
            );

            base = fn_shape(
                premise.shape,
                x,
                parameters,
                premise.parameter_offset,
                premise.parameter_count,
                premise.epsilon
            );

            derivative = (plus - minus) / (2.0f * step);

            derivative *=
                premise.hedge *
                pow(fmax(base, premise.epsilon), premise.hedge - 1.0f);

            gradient +=
                membership_gradients[(size_t)sample * premise_count + premise_index] *
                derivative;
        }
    }

    partial[lane] = gradient;

    barrier(CLK_LOCAL_MEM_FENCE);

    for (uint stride = local_count >> 1u; stride > 0u; stride >>= 1u)
    {
        if (lane < stride)
        {
            partial[lane] += partial[lane + stride];
        }

        barrier(CLK_LOCAL_MEM_FENCE);
    }

    if (lane == 0u)
    {
        parameter_gradients[parameter] = partial[0];
    }
}

__kernel void fn_weight_gradient_gemm(__global const float *restrict activations, __global const float *restrict deltas, __global float *restrict gradients, uint sample_count, uint neuron_count, uint source_offset, uint source_count, uint destination_offset, uint destination_count, uint weight_offset, __local float *partial)
{
    uint lane = get_local_id(0);
    uint local_count = get_local_size(0);
    uint parameter = get_group_id(0);
    uint parameter_count = source_count * destination_count;
    uint source;
    uint destination;
    float gradient = 0.0f;

    if (parameter >= parameter_count)
    {
        return;
    }

    source = parameter % source_count;
    destination = parameter / source_count;

    for (uint sample = lane; sample < sample_count; sample += local_count)
    {
        size_t base = (size_t)sample * neuron_count;

        gradient = fma(
            deltas[base + destination_offset + destination],
            activations[base + source_offset + source],
            gradient
        );
    }

    partial[lane] = gradient;

    barrier(CLK_LOCAL_MEM_FENCE);

    for (uint stride = local_count >> 1u; stride > 0u; stride >>= 1u)
    {
        if (lane < stride)
        {
            partial[lane] += partial[lane + stride];
        }

        barrier(CLK_LOCAL_MEM_FENCE);
    }

    if (lane == 0u)
    {
        gradients[(size_t)weight_offset + parameter] = partial[0];
    }
}

__kernel void fn_bias_gradient(__global const float *restrict deltas, __global float *restrict gradients, uint sample_count, uint neuron_count, uint destination_offset, uint destination_count, uint bias_offset, __local float *partial)
{
    uint lane = get_local_id(0);
    uint local_count = get_local_size(0);
    uint destination = get_group_id(0);
    float gradient = 0.0f;

    if (destination >= destination_count)
    {
        return;
    }

    for (uint sample = lane; sample < sample_count; sample += local_count)
    {
        gradient += deltas[
            (size_t)sample * neuron_count +
            destination_offset +
            destination
        ];
    }

    partial[lane] = gradient;

    barrier(CLK_LOCAL_MEM_FENCE);

    for (uint stride = local_count >> 1u; stride > 0u; stride >>= 1u)
    {
        if (lane < stride)
        {
            partial[lane] += partial[lane + stride];
        }

        barrier(CLK_LOCAL_MEM_FENCE);
    }

    if (lane == 0u)
    {
        gradients[bias_offset + destination] = partial[0];
    }
}

__kernel void fn_apply_parameters(__global float *parameters, __global const float *gradients, uint parameter_count, uint parameter_offset, uint sample_count, float learning_rate)
{
    uint parameter = get_global_id(0);
    size_t index;

    if (parameter >= parameter_count)
    {
        return;
    }

    index = (size_t)parameter_offset + parameter;

    parameters[index] = fma(
        -learning_rate / (float)sample_count,
        gradients[index],
        parameters[index]
    );
}

__kernel void fn_adam_apply(__global float *parameters, __global const float *gradients, __global float *first_moment, __global float *second_moment, uint parameter_count, uint parameter_offset, uint sample_count, float alpha, float beta1, float beta2, float epsilon)
{
    uint parameter = get_global_id(0);
    size_t index;
    float gradient;
    float moment_1;
    float moment_2;

    if (parameter >= parameter_count)
    {
        return;
    }

    index = (size_t)parameter_offset + parameter;
    gradient = gradients[index] / (float)sample_count;

    moment_1 = fma(
        1.0f - beta1,
        gradient,
        beta1 * first_moment[index]
    );

    moment_2 = fma(
        1.0f - beta2,
        gradient * gradient,
        beta2 * second_moment[index]
    );

    first_moment[index] = moment_1;
    second_moment[index] = moment_2;

    parameters[index] -=
        alpha * moment_1 /
        (sqrt(moment_2) + epsilon);
}

inline void fn_order2(__global float *parameters, uint first, uint second, float epsilon)
{
    float left = parameters[first];
    float right = parameters[second];

    if (!isfinite(left))
    {
        left = 0.0f;
    }

    if (!isfinite(right))
    {
        right = left + epsilon;
    }

    if (right < left + epsilon)
    {
        right = left + epsilon;
    }

    parameters[first] = left;
    parameters[second] = right;
}

__kernel void fn_project_premises(__global const fn_premise_t *restrict premises, __global float *parameters, uint premise_count)
{
    uint premise_index = get_global_id(0);
    fn_premise_t premise;
    uint offset;
    uint count;
    uint parameter;

    if (premise_index >= premise_count)
    {
        return;
    }

    premise = premises[premise_index];
    offset = premise.parameter_offset;
    count = premise.parameter_count;

    for (parameter = 0u; parameter < count; parameter++)
    {
        float value = parameters[offset + parameter];

        if (!isfinite(value))
        {
            parameters[offset + parameter] = 0.0f;
        }
    }

    if (premise.shape == FN_SHAPE_RAMP && count == 3u)
    {
        fn_order2(parameters, offset, offset + 1u, premise.epsilon);

        parameters[offset + 2u] =
            parameters[offset + 2u] != 0.0f
                ? 1.0f
                : 0.0f;
    }
    else if (premise.shape == FN_SHAPE_TRIANGLE && count == 3u)
    {
        fn_order2(parameters, offset, offset + 1u, premise.epsilon);
        fn_order2(parameters, offset + 1u, offset + 2u, premise.epsilon);
    }
    else if ((premise.shape == FN_SHAPE_TRAPEZOID ||
              premise.shape == FN_SHAPE_PIMF) &&
             count == 4u)
    {
        fn_order2(parameters, offset, offset + 1u, premise.epsilon);

        if (parameters[offset + 2u] < parameters[offset + 1u])
        {
            parameters[offset + 2u] = parameters[offset + 1u];
        }

        fn_order2(parameters, offset + 2u, offset + 3u, premise.epsilon);
    }
    else if ((premise.shape == FN_SHAPE_SMF ||
              premise.shape == FN_SHAPE_ZMF) &&
             count == 2u)
    {
        fn_order2(parameters, offset, offset + 1u, premise.epsilon);
    }
    else if (premise.shape == FN_SHAPE_GAUSSIAN && count == 2u)
    {
        parameters[offset + 1u] =
            fmax(fabs(parameters[offset + 1u]), premise.epsilon);
    }
    else if (premise.shape == FN_SHAPE_BELL && count == 3u)
    {
        float sign = parameters[offset] < 0.0f
            ? -1.0f
            : 1.0f;

        parameters[offset] =
            sign * fmax(fabs(parameters[offset]), premise.epsilon);
    }
    else if (premise.shape == FN_SHAPE_GAUSSIAN2 && count == 4u)
    {
        parameters[offset + 1u] =
            fmax(fabs(parameters[offset + 1u]), premise.epsilon);

        parameters[offset + 3u] =
            fmax(fabs(parameters[offset + 3u]), premise.epsilon);

        if (parameters[offset + 2u] < parameters[offset])
        {
            parameters[offset + 2u] = parameters[offset];
        }
    }

    for (parameter = 0u; parameter < count; parameter++)
    {
        uint bit = parameter < 32u
            ? 1u << parameter
            : 0u;

        if ((premise.trainable_mask & bit) != 0u)
        {
            parameters[offset + parameter] = clamp(
                parameters[offset + parameter],
                premise.domain_minimum,
                premise.domain_maximum
            );
        }
    }
}

/*
 * Additional fuzzy-neuron OpenCL kernels required by fuzzy.h.
 *
 * Paste this complete block after the final closing brace of
 * fn_project_premises() in fuzzy_neuron_kernels.cl.
 *
 * The original kernel definitions above this block remain unchanged.
 *
 * No required work-group size is specified.
 * No vendor-specific work-group size is specified.
 */

inline void fn_reduce_local_sum(
    __local float *partial,
    size_t lane,
    size_t local_count
)
{
    size_t active_count = local_count;

    while (active_count > 1u)
    {
        size_t next_count = (active_count + 1u) >> 1u;
        size_t pair_count = active_count - next_count;

        if (lane < pair_count)
        {
            partial[lane] += partial[lane + next_count];
        }

        barrier(CLK_LOCAL_MEM_FENCE);

        active_count = next_count;
    }
}

__kernel void fn_loss_reduce_stage(
    __global const float *restrict losses,
    __global float *restrict partials,
    uint loss_count,
    __local float *partial
)
{
    size_t lane = get_local_id(0);
    size_t local_count = get_local_size(0);
    size_t group = get_group_id(0);
    size_t index = group * local_count + lane;
    size_t stride = get_global_size(0);
    float sum = 0.0f;

    while (index < (size_t)loss_count)
    {
        sum += losses[index];
        index += stride;
    }

    partial[lane] = sum;

    barrier(CLK_LOCAL_MEM_FENCE);

    fn_reduce_local_sum(
        partial,
        lane,
        local_count
    );

    if (lane == 0u)
    {
        partials[group] = partial[0];
    }
}

__kernel void fn_loss_reduce_final(
    __global const float *restrict partials,
    __global float *restrict epoch_loss_sum,
    uint partial_count,
    __local float *partial
)
{
    size_t lane = get_local_id(0);
    size_t local_count = get_local_size(0);
    float sum = 0.0f;

    for (
        size_t index = lane;
        index < (size_t)partial_count;
        index += local_count
    )
    {
        sum += partials[index];
    }

    partial[lane] = sum;

    barrier(CLK_LOCAL_MEM_FENCE);

    fn_reduce_local_sum(
        partial,
        lane,
        local_count
    );

    if (lane == 0u)
    {
        epoch_loss_sum[0] += partial[0];
    }
}

__kernel void fn_best_model(
    __global const float *restrict epoch_loss_sum,
    __global float *restrict best_loss,
    __global uint *restrict best_updated,
    uint normalization_count
)
{
    float candidate;
    float current;
    uint update;

    if (get_global_id(0) != 0u)
    {
        return;
    }

    candidate = normalization_count != 0u
        ? epoch_loss_sum[0] / (float)normalization_count
        : NAN;

    current = best_loss[0];

    update =
        isfinite(candidate) &&
        (
            !isfinite(current) ||
            candidate < current
        );

    if (update != 0u)
    {
        best_loss[0] = candidate;
    }

    best_updated[0] = update;
}

__kernel void fn_conditional_copy(
    __global const float *restrict source,
    __global float *restrict destination,
    __global const uint *restrict enabled,
    uint element_count
)
{
    size_t index = get_global_id(0);

    if (
        enabled[0] != 0u &&
        index < (size_t)element_count
    )
    {
        destination[index] = source[index];
    }
}

__kernel void fn_gather_outputs(
    __global const float *restrict activations,
    __global float *restrict outputs,
    uint sample_count,
    uint neuron_count,
    uint output_offset,
    uint output_count
)
{
    size_t index = get_global_id(0);
    size_t total =
        (size_t)sample_count *
        output_count;
    size_t sample;
    size_t output;

    if (index >= total)
    {
        return;
    }

    sample = index / output_count;
    output = index - sample * output_count;

    outputs[index] =
        activations[
            sample *
            neuron_count +
            output_offset +
            output
        ];
}

__kernel void fn_forward_gemm_tiled(
    __global const float *restrict weights,
    __global const float *restrict biases,
    __global float *restrict activations,
    uint sample_count,
    uint neuron_count,
    uint source_offset,
    uint source_count,
    uint destination_offset,
    uint destination_count,
    uint weight_offset,
    uint bias_offset,
    uint activation_kind,
    __local float *input_tile,
    __local float *weight_tile
)
{
    size_t sample = get_global_id(0);
    size_t destination = get_global_id(1);
    size_t local_sample = get_local_id(0);
    size_t local_destination = get_local_id(1);
    size_t sample_tile_size = get_local_size(0);
    size_t destination_tile_size = get_local_size(1);
    size_t work_group_size =
        sample_tile_size *
        destination_tile_size;
    size_t work_item_index =
        local_sample *
        destination_tile_size +
        local_destination;
    float weighted_sum = 0.0f;

    if (
        sample < (size_t)sample_count &&
        destination < (size_t)destination_count
    )
    {
        weighted_sum =
            biases[
                bias_offset +
                destination
            ];
    }

    for (
        size_t source_base = 0u;
        source_base < (size_t)source_count;
        source_base += destination_tile_size
    )
    {
        size_t remaining_sources =
            (size_t)source_count -
            source_base;

        size_t source_tile_count =
            remaining_sources < destination_tile_size
                ? remaining_sources
                : destination_tile_size;

        size_t input_element_count =
            sample_tile_size *
            source_tile_count;

        size_t weight_element_count =
            destination_tile_size *
            source_tile_count;

        for (
            size_t element = work_item_index;
            element < input_element_count;
            element += work_group_size
        )
        {
            size_t tile_sample =
                element /
                source_tile_count;

            size_t tile_source =
                element -
                tile_sample *
                source_tile_count;

            size_t global_sample =
                get_group_id(0) *
                sample_tile_size +
                tile_sample;

            input_tile[element] =
                global_sample < (size_t)sample_count
                    ? activations[
                        global_sample *
                        neuron_count +
                        source_offset +
                        source_base +
                        tile_source
                    ]
                    : 0.0f;
        }

        for (
            size_t element = work_item_index;
            element < weight_element_count;
            element += work_group_size
        )
        {
            size_t tile_destination =
                element /
                source_tile_count;

            size_t tile_source =
                element -
                tile_destination *
                source_tile_count;

            size_t global_destination =
                get_group_id(1) *
                destination_tile_size +
                tile_destination;

            weight_tile[element] =
                global_destination <
                (size_t)destination_count
                    ? weights[
                        (size_t)weight_offset +
                        global_destination *
                        source_count +
                        source_base +
                        tile_source
                    ]
                    : 0.0f;
        }

        barrier(CLK_LOCAL_MEM_FENCE);

        if (
            sample < (size_t)sample_count &&
            destination < (size_t)destination_count
        )
        {
            for (
                size_t source = 0u;
                source < source_tile_count;
                source++
            )
            {
                weighted_sum = fma(
                    input_tile[
                        local_sample *
                        source_tile_count +
                        source
                    ],
                    weight_tile[
                        local_destination *
                        source_tile_count +
                        source
                    ],
                    weighted_sum
                );
            }
        }

        barrier(CLK_LOCAL_MEM_FENCE);
    }

    if (
        sample < (size_t)sample_count &&
        destination < (size_t)destination_count
    )
    {
        activations[
            sample *
            neuron_count +
            destination_offset +
            destination
        ] = fn_activate(
            weighted_sum,
            activation_kind
        );
    }
}

__kernel void fn_hidden_delta_gemm_tiled(
    __global const float *restrict weights,
    __global const float *restrict activations,
    __global float *restrict deltas,
    uint sample_count,
    uint neuron_count,
    uint current_offset,
    uint current_count,
    uint next_offset,
    uint next_count,
    uint next_weight_offset,
    uint current_activation_kind,
    __local float *next_delta_tile,
    __local float *transposed_weight_tile
)
{
    size_t sample = get_global_id(0);
    size_t current_neuron = get_global_id(1);
    size_t local_sample = get_local_id(0);
    size_t local_current_neuron = get_local_id(1);
    size_t sample_tile_size = get_local_size(0);
    size_t current_tile_size = get_local_size(1);
    size_t work_group_size =
        sample_tile_size *
        current_tile_size;
    size_t work_item_index =
        local_sample *
        current_tile_size +
        local_current_neuron;
    float weighted_delta_sum = 0.0f;

    for (
        size_t next_base = 0u;
        next_base < (size_t)next_count;
        next_base += current_tile_size
    )
    {
        size_t remaining_next_neurons =
            (size_t)next_count -
            next_base;

        size_t next_tile_count =
            remaining_next_neurons < current_tile_size
                ? remaining_next_neurons
                : current_tile_size;

        size_t next_delta_element_count =
            sample_tile_size *
            next_tile_count;

        size_t weight_element_count =
            current_tile_size *
            next_tile_count;

        for (
            size_t element = work_item_index;
            element < next_delta_element_count;
            element += work_group_size
        )
        {
            size_t tile_sample =
                element /
                next_tile_count;

            size_t tile_next_neuron =
                element -
                tile_sample *
                next_tile_count;

            size_t global_sample =
                get_group_id(0) *
                sample_tile_size +
                tile_sample;

            next_delta_tile[element] =
                global_sample < (size_t)sample_count
                    ? deltas[
                        global_sample *
                        neuron_count +
                        next_offset +
                        next_base +
                        tile_next_neuron
                    ]
                    : 0.0f;
        }

        for (
            size_t element = work_item_index;
            element < weight_element_count;
            element += work_group_size
        )
        {
            size_t tile_current_neuron =
                element /
                next_tile_count;

            size_t tile_next_neuron =
                element -
                tile_current_neuron *
                next_tile_count;

            size_t global_current_neuron =
                get_group_id(1) *
                current_tile_size +
                tile_current_neuron;

            transposed_weight_tile[element] =
                global_current_neuron <
                (size_t)current_count
                    ? weights[
                        (size_t)next_weight_offset +
                        (
                            next_base +
                            tile_next_neuron
                        ) *
                        current_count +
                        global_current_neuron
                    ]
                    : 0.0f;
        }

        barrier(CLK_LOCAL_MEM_FENCE);

        if (
            sample < (size_t)sample_count &&
            current_neuron < (size_t)current_count
        )
        {
            for (
                size_t next_neuron = 0u;
                next_neuron < next_tile_count;
                next_neuron++
            )
            {
                weighted_delta_sum = fma(
                    transposed_weight_tile[
                        local_current_neuron *
                        next_tile_count +
                        next_neuron
                    ],
                    next_delta_tile[
                        local_sample *
                        next_tile_count +
                        next_neuron
                    ],
                    weighted_delta_sum
                );
            }
        }

        barrier(CLK_LOCAL_MEM_FENCE);
    }

    if (
        sample < (size_t)sample_count &&
        current_neuron < (size_t)current_count
    )
    {
        size_t current_activation_index =
            sample *
            neuron_count +
            current_offset +
            current_neuron;

        float current_activation_output =
            activations[
                current_activation_index
            ];

        float current_activation_derivative =
            fn_derivative_from_output(
                current_activation_output,
                current_activation_kind
            );

        deltas[current_activation_index] =
            weighted_delta_sum *
            current_activation_derivative;
    }
}

__kernel void fn_layer_backward_update(
    __global float *restrict weights,
    __global float *restrict biases,
    __global const float *restrict activations,
    __global const float *restrict deltas,
    __global float *restrict weight_first_moment,
    __global float *restrict weight_second_moment,
    __global float *restrict bias_first_moment,
    __global float *restrict bias_second_moment,
    uint sample_count,
    uint neuron_count,
    uint source_offset,
    uint source_count,
    uint destination_offset,
    uint destination_count,
    uint weight_offset,
    uint bias_offset,
    uint optimizer_kind,
    float learning_rate,
    float alpha,
    float beta1,
    float beta2,
    float epsilon,
    __local float *partial
)
{
    size_t lane = get_local_id(0);
    size_t local_count = get_local_size(0);
    size_t parameter = get_group_id(0);
    size_t weight_count =
        (size_t)source_count *
        destination_count;
    size_t total_parameter_count =
        weight_count +
        destination_count;
    float gradient = 0.0f;

    if (parameter >= total_parameter_count)
    {
        return;
    }

    if (parameter < weight_count)
    {
        size_t destination =
            parameter /
            source_count;

        size_t source =
            parameter -
            destination *
            source_count;

        for (
            size_t sample = lane;
            sample < (size_t)sample_count;
            sample += local_count
        )
        {
            size_t activation_base =
                sample *
                neuron_count;

            gradient = fma(
                deltas[
                    activation_base +
                    destination_offset +
                    destination
                ],
                activations[
                    activation_base +
                    source_offset +
                    source
                ],
                gradient
            );
        }
    }
    else
    {
        size_t destination =
            parameter -
            weight_count;

        for (
            size_t sample = lane;
            sample < (size_t)sample_count;
            sample += local_count
        )
        {
            gradient +=
                deltas[
                    sample *
                    neuron_count +
                    destination_offset +
                    destination
                ];
        }
    }

    partial[lane] = gradient;

    barrier(CLK_LOCAL_MEM_FENCE);

    fn_reduce_local_sum(
        partial,
        lane,
        local_count
    );

    if (lane == 0u)
    {
        float mean_gradient =
            sample_count != 0u
                ? partial[0] /
                    (float)sample_count
                : 0.0f;

        if (parameter < weight_count)
        {
            size_t index =
                (size_t)weight_offset +
                parameter;

            if (optimizer_kind == 1u)
            {
                float moment_1 = fma(
                    1.0f - beta1,
                    mean_gradient,
                    beta1 *
                    weight_first_moment[index]
                );

                float moment_2 = fma(
                    1.0f - beta2,
                    mean_gradient *
                    mean_gradient,
                    beta2 *
                    weight_second_moment[index]
                );

                weight_first_moment[index] =
                    moment_1;

                weight_second_moment[index] =
                    moment_2;

                weights[index] -=
                    alpha *
                    moment_1 /
                    (
                        sqrt(moment_2) +
                        epsilon
                    );
            }
            else
            {
                weights[index] -=
                    learning_rate *
                    mean_gradient;
            }
        }
        else
        {
            size_t index =
                (size_t)bias_offset +
                parameter -
                weight_count;

            if (optimizer_kind == 1u)
            {
                float moment_1 = fma(
                    1.0f - beta1,
                    mean_gradient,
                    beta1 *
                    bias_first_moment[index]
                );

                float moment_2 = fma(
                    1.0f - beta2,
                    mean_gradient *
                    mean_gradient,
                    beta2 *
                    bias_second_moment[index]
                );

                bias_first_moment[index] =
                    moment_1;

                bias_second_moment[index] =
                    moment_2;

                biases[index] -=
                    alpha *
                    moment_1 /
                    (
                        sqrt(moment_2) +
                        epsilon
                    );
            }
            else
            {
                biases[index] -=
                    learning_rate *
                    mean_gradient;
            }
        }
    }
}

__kernel void fn_fuzzy_backward(
    __global const float *restrict weights,
    __global const float *restrict deltas,
    __global const float *restrict raw_rules,
    __global float *restrict normalized_rule_gradients,
    __global float *restrict raw_rule_gradients,
    uint sample_count,
    uint neuron_count,
    uint rule_count,
    uint first_destination_offset,
    uint first_destination_count,
    uint first_weight_offset
)
{
    size_t sample = get_global_id(0);
    size_t rule_base;
    size_t neuron_base;
    float total_rule_activation = 0.0f;
    float weighted_gradient = 0.0f;

    if (sample >= (size_t)sample_count)
    {
        return;
    }

    rule_base =
        sample *
        rule_count;

    neuron_base =
        sample *
        neuron_count;

    for (
        uint rule = 0u;
        rule < rule_count;
        rule++
    )
    {
        float normalized_gradient = 0.0f;

        for (
            uint destination = 0u;
            destination < first_destination_count;
            destination++
        )
        {
            normalized_gradient = fma(
                weights[
                    (size_t)first_weight_offset +
                    (size_t)destination *
                    rule_count +
                    rule
                ],
                deltas[
                    neuron_base +
                    first_destination_offset +
                    destination
                ],
                normalized_gradient
            );
        }

        normalized_rule_gradients[
            rule_base +
            rule
        ] = normalized_gradient;

        total_rule_activation +=
            raw_rules[
                rule_base +
                rule
            ];

        weighted_gradient = fma(
            normalized_gradient,
            raw_rules[
                rule_base +
                rule
            ],
            weighted_gradient
        );
    }

    if (total_rule_activation > 1.0e-12f)
    {
        float denominator =
            total_rule_activation *
            total_rule_activation;

        for (
            uint rule = 0u;
            rule < rule_count;
            rule++
        )
        {
            raw_rule_gradients[
                rule_base +
                rule
            ] =
                (
                    normalized_rule_gradients[
                        rule_base +
                        rule
                    ] *
                    total_rule_activation -
                    weighted_gradient
                ) /
                denominator;
        }
    }
    else
    {
        for (
            uint rule = 0u;
            rule < rule_count;
            rule++
        )
        {
            raw_rule_gradients[
                rule_base +
                rule
            ] = 0.0f;
        }
    }
}

__kernel void fn_fuzzy_update(
    __global const float *restrict parameter_gradients,
    __global float *restrict parameters,
    __global float *restrict first_moment,
    __global float *restrict second_moment,
    uint parameter_count,
    uint sample_count,
    uint optimizer_kind,
    float learning_rate,
    float alpha,
    float beta1,
    float beta2,
    float epsilon
)
{
    size_t parameter = get_global_id(0);
    float gradient;

    if (parameter >= (size_t)parameter_count)
    {
        return;
    }

    gradient =
        sample_count != 0u
            ? parameter_gradients[parameter] /
                (float)sample_count
            : 0.0f;

    if (optimizer_kind == 1u)
    {
        float updated_first_moment =
            fma(
                1.0f - beta1,
                gradient,
                beta1 *
                first_moment[parameter]
            );

        float updated_second_moment =
            fma(
                1.0f - beta2,
                gradient *
                gradient,
                beta2 *
                second_moment[parameter]
            );

        first_moment[parameter] =
            updated_first_moment;

        second_moment[parameter] =
            updated_second_moment;

        parameters[parameter] -=
            alpha *
            updated_first_moment /
            (
                sqrt(
                    updated_second_moment
                ) +
                epsilon
            );
    }
    else
    {
        parameters[parameter] -=
            learning_rate *
            gradient;
    }
}