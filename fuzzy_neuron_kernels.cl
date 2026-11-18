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

__kernel void fn_output_delta(
    __global const float *restrict targets,
    __global const float *restrict activations,
    __global float *restrict deltas,
    __global float *restrict losses,
    uint sample_count,
    uint output_count,
    uint neuron_count,
    uint output_offset,
    uint activation_kind,
    uint loss_method,
    float huber_delta
)
{
    size_t index = get_global_id(0);
    size_t total = (size_t)sample_count * output_count;
    size_t sample;
    size_t output;
    size_t activation_index;
    float prediction;
    float error;
    float gradient;

    if (index >= total)
    {
        return;
    }

    sample = index / output_count;
    output = index - sample * output_count;
    activation_index = sample * neuron_count + output_offset + output;

    prediction = activations[activation_index];
    error = prediction - targets[index];

    if (loss_method == FN_LOSS_HUBER)
    {
        float magnitude = fabs(error);

        if (magnitude <= huber_delta)
        {
            losses[index] = 0.5f * error * error / huber_delta;
            gradient = error / huber_delta;
        }
        else
        {
            losses[index] = magnitude - 0.5f * huber_delta;
            gradient = copysign(1.0f, error);
        }
    }
    else
    {
        losses[index] = error * error;
        gradient = 2.0f * error;
    }

    deltas[activation_index] =
        gradient *
        fn_derivative_from_output(
            prediction,
            activation_kind
        );
}

__kernel void fn_mamdani_output_delta(
    __global const float *restrict targets,
    __global const float *restrict activations,
    __global const float *restrict output_memberships,
    __global float *restrict predictions,
    __global float *restrict deltas,
    __global float *restrict losses,
    uint sample_count,
    uint consequent_count,
    uint neuron_count,
    uint output_offset,
    uint output_sample_count,
    float output_minimum,
    float output_step,
    uint activation_kind,
    uint loss_method,
    float huber_delta
)
{
    size_t sample = get_global_id(0);
    size_t activation_base;
    float numerator = 0.0f;
    float denominator = 0.0f;
    float prediction;
    float error;
    float loss_gradient;
    float consequence_gradient;
    uint consequent;
    uint output_sample;

    if (sample >= (size_t)sample_count)
    {
        return;
    }

    activation_base =
        sample *
        neuron_count +
        output_offset;

    for (
        output_sample = 0u;
        output_sample < output_sample_count;
        ++output_sample
    )
    {
        float output_value =
            output_minimum +
            output_step *
            (float)output_sample;

        float aggregated_membership = 0.0f;

        for (
            consequent = 0u;
            consequent < consequent_count;
            ++consequent
        )
        {
            float activation =
                clamp(
                    activations[
                        activation_base +
                        consequent
                    ],
                    0.0f,
                    1.0f
                );

            float consequent_membership =
                output_memberships[
                    (size_t)consequent *
                    output_sample_count +
                    output_sample
                ];

            float implied_membership =
                fmin(
                    activation,
                    consequent_membership
                );

            aggregated_membership =
                fmax(
                    aggregated_membership,
                    implied_membership
                );
        }

        numerator = fma(
            output_value,
            aggregated_membership,
            numerator
        );

        denominator += aggregated_membership;
    }

    if (!(denominator > 1.0e-12f))
    {
        predictions[sample] = 0.0f;
        losses[sample] = 0.0f;

        for (
            consequent = 0u;
            consequent < consequent_count;
            ++consequent
        )
        {
            deltas[
                activation_base +
                consequent
            ] = 0.0f;
        }

        return;
    }

    prediction = numerator / denominator;
    predictions[sample] = prediction;

    error = prediction - targets[sample];

    if (loss_method == FN_LOSS_HUBER)
    {
        float magnitude = fabs(error);

        if (magnitude <= huber_delta)
        {
            losses[sample] =
                0.5f *
                error *
                error /
                huber_delta;

            loss_gradient =
                error /
                huber_delta;
        }
        else
        {
            losses[sample] =
                magnitude -
                0.5f *
                huber_delta;

            loss_gradient =
                copysign(
                    1.0f,
                    error
                );
        }
    }
    else
    {
        losses[sample] =
            error *
            error;

        loss_gradient =
            2.0f *
            error;
    }

    for (
        consequent = 0u;
        consequent < consequent_count;
        ++consequent
    )
    {
        float activation =
            clamp(
                activations[
                    activation_base +
                    consequent
                ],
                0.0f,
                1.0f
            );

        consequence_gradient = 0.0f;

        for (
            output_sample = 0u;
            output_sample < output_sample_count;
            ++output_sample
        )
        {
            float output_value =
                output_minimum +
                output_step *
                (float)output_sample;

            float consequent_membership =
                output_memberships[
                    (size_t)consequent *
                    output_sample_count +
                    output_sample
                ];

            float implied_membership =
                fmin(
                    activation,
                    consequent_membership
                );

            float aggregated_membership = 0.0f;

            uint winner = 0xffffffffu;
            uint candidate;

            for (
                candidate = 0u;
                candidate < consequent_count;
                ++candidate
            )
            {
                float candidate_activation =
                    clamp(
                        activations[
                            activation_base +
                            candidate
                        ],
                        0.0f,
                        1.0f
                    );

                float candidate_membership =
                    output_memberships[
                        (size_t)candidate *
                        output_sample_count +
                        output_sample
                    ];

                float candidate_implied =
                    fmin(
                        candidate_activation,
                        candidate_membership
                    );

                if (
                    winner == 0xffffffffu ||
                    candidate_implied >
                    aggregated_membership
                )
                {
                    aggregated_membership =
                        candidate_implied;

                    winner = candidate;
                }
            }

            if (
                winner == consequent &&
                implied_membership ==
                aggregated_membership &&
                activation <
                consequent_membership
            )
            {
                consequence_gradient +=
                    (
                        output_value -
                        prediction
                    ) /
                    denominator;
            }
        }

        deltas[
            activation_base +
            consequent
        ] =
            loss_gradient *
            consequence_gradient *
            fn_derivative_from_output(
                activations[
                    activation_base +
                    consequent
                ],
                activation_kind
            );
    }
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

        if (sample < (size_t)sample_count && destination < (size_t)destination_count)
        {
            size_t source = 0u;
            size_t input_base = local_sample * source_tile_count;

            size_t weight_base = local_destination * source_tile_count;

            for (; source + 4u <= source_tile_count; source += 4u)
            {
                float4 input_values = vload4(0u, input_tile + input_base + source);
                float4 weight_values = vload4(0u, weight_tile + weight_base + source);
                weighted_sum += dot( input_values, weight_values);
            }

            for (; source < source_tile_count; source++)
                weighted_sum = fma(input_tile[input_base + source ], weight_tile[weight_base + source], weighted_sum);
    }
        barrier(CLK_LOCAL_MEM_FENCE);
    }

    if (sample < (size_t)sample_count && destination < (size_t)destination_count)
        activations[ sample * neuron_count + destination_offset + destination] = fn_activate(weighted_sum, activation_kind);
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
                global_sample < (size_t)sample_count ? deltas[     global_sample *     neuron_count +     next_offset +     next_base +     tile_next_neuron ]: 0.0f;
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

        size_t next_neuron = 0u;
        size_t weight_base =
            local_current_neuron *
            next_tile_count;

        size_t delta_base =
            local_sample *
            next_tile_count;

        for (
            ;
            next_neuron + 4u <= next_tile_count;
            next_neuron += 4u
        )
        {
            float4 weight_values = vload4(
                0u,
                transposed_weight_tile +
                weight_base +
                next_neuron
            );

            float4 delta_values = vload4(
                0u,
                next_delta_tile +
                delta_base +
                next_neuron
            );

            weighted_delta_sum += dot(
                weight_values,
                delta_values
            );
        }

        for (
            ;
            next_neuron < next_tile_count;
            next_neuron++
        )
        {
            weighted_delta_sum = fma(
                transposed_weight_tile[
                    weight_base +
                    next_neuron
                ],
                next_delta_tile[
                    delta_base +
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

/* ============================================================================
 * Adaptive Fuzzy Rules + ANN Membership Function Tuning OpenCL Kernels
 *
 * Extends fuzzy_neuron_kernels.cl so an ANN dynamically adjusts and tunes both
 * input and output membership function parameters while evaluating static fuzzy
 * rules and differentiable multi-output Mamdani COG & BOA defuzzification.
 * ============================================================================ */

#define FN_DEFUZZ_COG 0u
#define FN_DEFUZZ_BOA 1u
#define FN_TUNER_MAX_CHANNEL_MFS 16u
#define FN_TUNER_MAX_CHANNEL_PARAMS 64u

typedef struct fn_output_channel
{
    float minimum;
    float maximum;
    float step;
    uint sample_count;
    uint defuzz_method;
    uint mf_offset;
    uint mf_count;
    uint reserved0;
}
fn_output_channel_t;

inline float fn_eval_mf_hedged(
    fn_premise_t mf,
    float x,
    __global const float *params,
    uint param_base_offset
)
{
    float base = fn_shape(
        mf.shape,
        x,
        params,
        param_base_offset + mf.parameter_offset,
        mf.parameter_count,
        mf.epsilon
    );

    if (fabs(mf.hedge - 1.0f) <= 1.0e-6f)
    {
        return clamp(base, 0.0f, 1.0f);
    }

    return pow(clamp(base, 0.0f, 1.0f), fmax(mf.hedge, mf.epsilon));
}

inline float fn_eval_mf_param_deriv(
    fn_premise_t mf,
    float x,
    __global const float *params,
    uint param_base_offset,
    uint local_param
)
{
    uint global_param = param_base_offset + mf.parameter_offset + local_param;
    float span = fmax(mf.domain_maximum - mf.domain_minimum, mf.epsilon);
    float step = fmax(mf.epsilon, span * 1.0e-3f);
    float plus = fn_shape_shift(
        mf.shape,
        x,
        params,
        param_base_offset + mf.parameter_offset,
        mf.parameter_count,
        mf.epsilon,
        global_param,
        step
    );
    float minus = fn_shape_shift(
        mf.shape,
        x,
        params,
        param_base_offset + mf.parameter_offset,
        mf.parameter_count,
        mf.epsilon,
        global_param,
        -step
    );
    float derivative = (plus - minus) / (2.0f * step);

    if (fabs(mf.hedge - 1.0f) > 1.0e-6f)
    {
        float base = fn_shape(
            mf.shape,
            x,
            params,
            param_base_offset + mf.parameter_offset,
            mf.parameter_count,
            mf.epsilon
        );
        derivative *= mf.hedge * pow(fmax(base, mf.epsilon), mf.hedge - 1.0f);
    }

    return derivative;
}

inline void fn_project_mf_at(
    fn_premise_t mf,
    __global float *params,
    size_t base_offset
)
{
    uint count = mf.parameter_count;
    float dmin = mf.domain_minimum;
    float dmax = mf.domain_maximum;
    float span = fmax(dmax - dmin, mf.epsilon * 4.0f);
    float sep = fmax(mf.epsilon * 2.0f, span * 1.0e-3f);
    uint p;

    for (p = 0u; p < count; ++p)
    {
        float val = params[base_offset + p];
        if (!isfinite(val))
        {
            val = 0.5f * (dmin + dmax);
        }
        if (p < 32u && (mf.trainable_mask & (1u << p)) != 0u)
        {
            val = clamp(val, dmin, dmax);
        }
        params[base_offset + p] = val;
    }

    if (mf.shape == FN_SHAPE_RAMP && count == 3u)
    {
        float a = clamp(params[base_offset + 0u], dmin, dmax - sep);
        float b = clamp(params[base_offset + 1u], a + sep, dmax);
        params[base_offset + 0u] = a;
        params[base_offset + 1u] = b;
        params[base_offset + 2u] = params[base_offset + 2u] != 0.0f ? 1.0f : 0.0f;
    }
    else if (mf.shape == FN_SHAPE_TRIANGLE && count == 3u)
    {
        float a = clamp(params[base_offset + 0u], dmin, dmax - 2.0f * sep);
        float b = clamp(params[base_offset + 1u], a + sep, dmax - sep);
        float c = clamp(params[base_offset + 2u], b + sep, dmax);
        params[base_offset + 0u] = a;
        params[base_offset + 1u] = b;
        params[base_offset + 2u] = c;
    }
    else if ((mf.shape == FN_SHAPE_TRAPEZOID || mf.shape == FN_SHAPE_PIMF) && count == 4u)
    {
        float a = clamp(params[base_offset + 0u], dmin, dmax - 2.0f * sep);
        float b = clamp(params[base_offset + 1u], a + sep, dmax - sep);
        float c = clamp(params[base_offset + 2u], b, dmax - sep);
        float d = clamp(params[base_offset + 3u], c + sep, dmax);
        params[base_offset + 0u] = a;
        params[base_offset + 1u] = b;
        params[base_offset + 2u] = c;
        params[base_offset + 3u] = d;
    }
    else if ((mf.shape == FN_SHAPE_SMF || mf.shape == FN_SHAPE_ZMF) && count == 2u)
    {
        float a = clamp(params[base_offset + 0u], dmin, dmax - sep);
        float b = clamp(params[base_offset + 1u], a + sep, dmax);
        params[base_offset + 0u] = a;
        params[base_offset + 1u] = b;
    }
    else if (mf.shape == FN_SHAPE_GAUSSIAN && count == 2u)
    {
        float min_sigma = fmax(mf.epsilon, span * 0.02f);
        params[base_offset + 0u] = clamp(params[base_offset + 0u], dmin, dmax);
        params[base_offset + 1u] = clamp(fabs(params[base_offset + 1u]), min_sigma, span);
    }
    else if (mf.shape == FN_SHAPE_BELL && count == 3u)
    {
        float min_w = fmax(mf.epsilon, span * 0.02f);
        float sign = params[base_offset + 0u] < 0.0f ? -1.0f : 1.0f;
        params[base_offset + 0u] = sign * fmax(fabs(params[base_offset + 0u]), min_w);
    }
    else if (mf.shape == FN_SHAPE_GAUSSIAN2 && count == 4u)
    {
        float min_sigma = fmax(mf.epsilon, span * 0.02f);
        float m1 = clamp(params[base_offset + 0u], dmin, dmax);
        float s1 = clamp(fabs(params[base_offset + 1u]), min_sigma, span);
        float m2 = clamp(params[base_offset + 2u], m1, dmax);
        float s2 = clamp(fabs(params[base_offset + 3u]), min_sigma, span);
        params[base_offset + 0u] = m1;
        params[base_offset + 1u] = s1;
        params[base_offset + 2u] = m2;
        params[base_offset + 3u] = s2;
    }
}

__kernel void fn_tuner_prepare_inputs(
    __global const float *restrict dataset_inputs,
    __global const float *restrict input_min,
    __global const float *restrict input_max,
    __global float *restrict raw_inputs,
    __global float *restrict ann_activations,
    uint batch_start,
    uint sample_count,
    uint input_count,
    uint neuron_count
)
{
    size_t idx = get_global_id(0);
    size_t total = (size_t)sample_count * input_count;
    size_t sample;
    size_t dim;
    float value;
    float span;
    float normalized;

    if (idx >= total)
    {
        return;
    }

    sample = idx / input_count;
    dim = idx - sample * input_count;

    value = dataset_inputs[((size_t)batch_start + sample) * input_count + dim];
    raw_inputs[idx] = value;

    span = input_max[dim] - input_min[dim];
    normalized = span > 1.0e-12f
        ? clamp((value - input_min[dim]) / span, 0.0f, 1.0f)
        : value;

    ann_activations[sample * neuron_count + dim] = normalized;
}

__kernel void fn_tuner_effective_mfs(
    __global const fn_premise_t *restrict all_mfs,
    __global const float *restrict base_params,
    __global const float *restrict ann_activations,
    __global float *restrict eff_params,
    uint sample_count,
    uint total_mf_count,
    uint total_param_count,
    uint neuron_count,
    uint ann_output_offset,
    float tuner_scale,
    uint ann_enabled
)
{
    size_t sample = get_global_id(0);
    size_t mf_idx = get_global_id(1);
    fn_premise_t mf;
    size_t sample_param_base;
    size_t ann_base;
    float span;
    uint p;

    if (sample >= (size_t)sample_count || mf_idx >= (size_t)total_mf_count)
    {
        return;
    }

    mf = all_mfs[mf_idx];
    sample_param_base = sample * total_param_count;
    ann_base = sample * neuron_count + ann_output_offset;
    span = fmax(mf.domain_maximum - mf.domain_minimum, mf.epsilon);

    for (p = 0u; p < mf.parameter_count; ++p)
    {
        uint param_idx = mf.parameter_offset + p;
        float base_val = base_params[param_idx];
        float eff_val = base_val;

        if (ann_enabled != 0u &&
            tuner_scale > 0.0f &&
            p < 32u &&
            (mf.trainable_mask & (1u << p)) != 0u)
        {
            float ann_out = ann_activations[ann_base + param_idx];
            eff_val = fma(tuner_scale * span, ann_out, base_val);
        }

        eff_params[sample_param_base + param_idx] = eff_val;
    }

    fn_project_mf_at(mf, eff_params, sample_param_base + mf.parameter_offset);
}

__kernel void fn_tuner_rules_forward(
    __global const float *restrict raw_inputs,
    __global const fn_premise_t *restrict input_mfs,
    __global const float *restrict eff_params,
    __global const fn_expression_t *restrict expressions,
    __global const uint *restrict rule_roots,
    __global float *restrict memberships,
    __global float *restrict expression_values,
    __global float *restrict raw_rules,
    uint sample_count,
    uint input_count,
    uint premise_count,
    uint expression_count,
    uint rule_count,
    uint total_param_count,
    uint logic_method
)
{
    size_t sample = get_global_id(0);
    size_t raw_base;
    size_t param_base;
    size_t mem_base;
    size_t expr_base;
    size_t rule_base;
    uint i;

    if (sample >= (size_t)sample_count)
    {
        return;
    }

    raw_base = sample * input_count;
    param_base = sample * total_param_count;
    mem_base = sample * premise_count;
    expr_base = sample * expression_count;
    rule_base = sample * rule_count;

    for (i = 0u; i < premise_count; ++i)
    {
        fn_premise_t mf = input_mfs[i];
        float x = raw_inputs[raw_base + mf.input_index];
        memberships[mem_base + i] = fn_eval_mf_hedged(mf, x, eff_params, (uint)param_base);
    }

    for (i = 0u; i < expression_count; ++i)
    {
        fn_expression_t expr = expressions[i];
        float value;

        if (expr.kind == FN_EXPR_MEMBERSHIP)
        {
            value = memberships[mem_base + expr.value];
        }
        else if (expr.kind == FN_EXPR_NOT)
        {
            value = 1.0f - expression_values[expr_base + expr.left];
        }
        else if (expr.kind == FN_EXPR_AND)
        {
            value = fn_logic_and(
                expression_values[expr_base + expr.left],
                expression_values[expr_base + expr.right],
                logic_method
            );
        }
        else
        {
            value = fn_logic_or(
                expression_values[expr_base + expr.left],
                expression_values[expr_base + expr.right],
                logic_method
            );
        }

        expression_values[expr_base + i] = value;
    }

    for (i = 0u; i < rule_count; ++i)
    {
        raw_rules[rule_base + i] = clamp(expression_values[expr_base + rule_roots[i]], 0.0f, 1.0f);
    }
}

__kernel void fn_tuner_defuzz_forward_backward(
    __global const fn_output_channel_t *restrict channels,
    __global const fn_premise_t *restrict output_mfs,
    __global const uint *restrict rule_consequents,
    __global const float *restrict raw_rules,
    __global const float *restrict eff_params,
    __global const float *restrict dataset_targets,
    __global const float *restrict ann_activations,
    __global float *restrict predictions,
    __global float *restrict losses,
    __global float *restrict raw_rule_gradients,
    __global float *restrict sample_mf_gradients,
    __global float *restrict ann_deltas,
    uint batch_start,
    uint sample_count,
    uint output_count,
    uint rule_count,
    uint total_param_count,
    uint neuron_count,
    uint ann_output_offset,
    float tuner_scale,
    uint ann_enabled,
    uint compute_gradients,
    uint loss_method,
    float huber_delta
)
{
    size_t sample = get_global_id(0);
    size_t out_idx = get_global_id(1);
    fn_output_channel_t ch;
    float alpha[FN_TUNER_MAX_CHANNEL_MFS];
    float alpha_grad[FN_TUNER_MAX_CHANNEL_MFS];
    float out_param_grads[FN_TUNER_MAX_CHANNEL_PARAMS];
    size_t param_base;
    size_t rule_base;
    uint c;
    uint k;
    uint step_idx;
    uint ch_first_param_offset;
    float weighted_sum = 0.0f;
    float height_sum = 0.0f;
    float prediction = 0.0f;
    float mu_at_boa = 0.0f;

    if (sample >= (size_t)sample_count || out_idx >= (size_t)output_count)
    {
        return;
    }

    ch = channels[out_idx];
    if (ch.mf_count == 0u || ch.mf_count > FN_TUNER_MAX_CHANNEL_MFS)
    {
        predictions[sample * output_count + out_idx] = 0.0f;
        return;
    }

    param_base = sample * total_param_count;
    rule_base = sample * rule_count;
    ch_first_param_offset = output_mfs[ch.mf_offset].parameter_offset;

    for (c = 0u; c < ch.mf_count; ++c)
    {
        alpha[c] = 0.0f;
        alpha_grad[c] = 0.0f;
    }

    for (k = 0u; k < rule_count; ++k)
    {
        uint conseq = rule_consequents[k];
        if (conseq >= ch.mf_offset && conseq < ch.mf_offset + ch.mf_count)
        {
            uint local_c = conseq - ch.mf_offset;
            float r = raw_rules[rule_base + k];
            if (r > alpha[local_c])
            {
                alpha[local_c] = r;
            }
        }
    }

    for (step_idx = 0u; step_idx < ch.sample_count; ++step_idx)
    {
        float y = ch.minimum + ch.step * (float)step_idx;
        float agg = 0.0f;

        for (c = 0u; c < ch.mf_count; ++c)
        {
            if (alpha[c] > agg)
            {
                float mu = fn_eval_mf_hedged(
                    output_mfs[ch.mf_offset + c],
                    y,
                    eff_params,
                    (uint)param_base
                );
                float implied = fmin(alpha[c], mu);
                if (implied > agg)
                {
                    agg = implied;
                }
            }
        }

        weighted_sum = fma(y, agg, weighted_sum);
        height_sum += agg;
    }

    if (height_sum > 1.0e-12f)
    {
        if (ch.defuzz_method == FN_DEFUZZ_BOA)
        {
            float half_area = 0.5f * height_sum;
            float acc = 0.0f;
            prediction = ch.maximum;

            for (step_idx = 0u; step_idx < ch.sample_count; ++step_idx)
            {
                float y = ch.minimum + ch.step * (float)step_idx;
                float agg = 0.0f;

                for (c = 0u; c < ch.mf_count; ++c)
                {
                    if (alpha[c] > agg)
                    {
                        float mu = fn_eval_mf_hedged(
                            output_mfs[ch.mf_offset + c],
                            y,
                            eff_params,
                            (uint)param_base
                        );
                        float implied = fmin(alpha[c], mu);
                        if (implied > agg)
                        {
                            agg = implied;
                        }
                    }
                }

                acc += agg;
                if (acc >= half_area)
                {
                    prediction = y;
                    mu_at_boa = agg;
                    break;
                }
            }
        }
        else
        {
            prediction = weighted_sum / height_sum;
        }
    }

    predictions[sample * output_count + out_idx] = prediction;

    if (compute_gradients == 0u)
    {
        return;
    }

    {
        float target = dataset_targets[((size_t)batch_start + sample) * output_count + out_idx];
        float ch_span = fmax(ch.maximum - ch.minimum, 1.0e-6f);
        float error = prediction - target;
        float norm_error = error / ch_span;
        float loss_grad;
        uint p_idx;

        if (loss_method == FN_LOSS_HUBER)
        {
            float mag = fabs(error);
            if (mag <= huber_delta)
            {
                losses[sample * output_count + out_idx] = 0.5f * error * error / huber_delta;
                loss_grad = (error / huber_delta) / (ch_span * ch_span);
            }
            else
            {
                losses[sample * output_count + out_idx] = mag - 0.5f * huber_delta;
                loss_grad = copysign(1.0f, error) / ch_span;
            }
        }
        else
        {
            losses[sample * output_count + out_idx] = error * error;
            /* Scale gradient by 1/(span^2) so multi-scale outputs train uniformly */
            loss_grad = (2.0f * norm_error) / ch_span;
        }

        for (p_idx = 0u; p_idx < FN_TUNER_MAX_CHANNEL_PARAMS; ++p_idx)
        {
            out_param_grads[p_idx] = 0.0f;
        }

        if (height_sum > 1.0e-12f)
        {
            for (step_idx = 0u; step_idx < ch.sample_count; ++step_idx)
            {
                float y = ch.minimum + ch.step * (float)step_idx;
                float best_implied = -1.0f;
                float best_mu = 0.0f;
                uint winner = 0u;

                for (c = 0u; c < ch.mf_count; ++c)
                {
                    float mu = fn_eval_mf_hedged(
                        output_mfs[ch.mf_offset + c],
                        y,
                        eff_params,
                        (uint)param_base
                    );
                    float implied = fmin(alpha[c], mu);
                    if (implied > best_implied)
                    {
                        best_implied = implied;
                        best_mu = mu;
                        winner = c;
                    }
                }

                if (best_implied > 0.0f)
                {
                    float sens;
                    float g_agg;
                    float alpha_share;
                    float mu_share;

                    if (ch.defuzz_method == FN_DEFUZZ_BOA)
                    {
                        float sgn = y < prediction ? -0.5f : (y > prediction ? 0.5f : 0.0f);
                        sens = (ch.step * sgn) / fmax(mu_at_boa, 0.05f);
                    }
                    else
                    {
                        sens = (y - prediction) / height_sum;
                    }

                    g_agg = loss_grad * sens;

                    if (alpha[winner] < best_mu - 1.0e-6f)
                    {
                        alpha_share = 1.0f;
                        mu_share = 0.0f;
                    }
                    else if (best_mu < alpha[winner] - 1.0e-6f)
                    {
                        alpha_share = 0.0f;
                        mu_share = 1.0f;
                    }
                    else
                    {
                        alpha_share = 0.5f;
                        mu_share = 0.5f;
                    }

                    if (alpha_share > 0.0f)
                    {
                        alpha_grad[winner] = fma(g_agg, alpha_share, alpha_grad[winner]);
                    }

                    if (mu_share > 0.0f)
                    {
                        fn_premise_t wmf = output_mfs[ch.mf_offset + winner];
                        uint p;
                        for (p = 0u; p < wmf.parameter_count; ++p)
                        {
                            if (p < 32u && (wmf.trainable_mask & (1u << p)) != 0u)
                            {
                                uint local_p = (wmf.parameter_offset - ch_first_param_offset) + p;
                                if (local_p < FN_TUNER_MAX_CHANNEL_PARAMS)
                                {
                                    float dmu = fn_eval_mf_param_deriv(
                                        wmf,
                                        y,
                                        eff_params,
                                        (uint)param_base,
                                        p
                                    );
                                    out_param_grads[local_p] = fma(
                                        g_agg * mu_share,
                                        dmu,
                                        out_param_grads[local_p]
                                    );
                                }
                            }
                        }
                    }
                }
            }
        }

        /* Write output MF gradients for both base MF optimizer and ANN backprop */
        {
            size_t ann_base = sample * neuron_count + ann_output_offset;
            for (c = 0u; c < ch.mf_count; ++c)
            {
                fn_premise_t mf = output_mfs[ch.mf_offset + c];
                float mf_span = fmax(mf.domain_maximum - mf.domain_minimum, mf.epsilon);
                uint p;
                for (p = 0u; p < mf.parameter_count; ++p)
                {
                    uint global_p = mf.parameter_offset + p;
                    uint local_p = global_p - ch_first_param_offset;
                    float g = (local_p < FN_TUNER_MAX_CHANNEL_PARAMS) ? out_param_grads[local_p] : 0.0f;
                    float ann_delta = 0.0f;

                    sample_mf_gradients[param_base + global_p] = g;

                    if (ann_enabled != 0u &&
                        tuner_scale > 0.0f &&
                        p < 32u &&
                        (mf.trainable_mask & (1u << p)) != 0u)
                    {
                        float ann_out = ann_activations[ann_base + global_p];
                        ann_delta = g * (tuner_scale * mf_span) *
                                    fn_derivative_from_output(ann_out, FN_ACTIVATION_TANH);
                    }
                    ann_deltas[ann_base + global_p] = ann_delta;
                }
            }
        }

        /* Route consequent activation gradients back to winning rules (lock-free per channel) */
        for (c = 0u; c < ch.mf_count; ++c)
        {
            uint target_conseq = ch.mf_offset + c;
            uint tie_count = 0u;
            float max_a = alpha[c];

            if (max_a > 0.0f)
            {
                for (k = 0u; k < rule_count; ++k)
                {
                    if (rule_consequents[k] == target_conseq &&
                        raw_rules[rule_base + k] >= max_a - 1.0e-6f)
                    {
                        ++tie_count;
                    }
                }
            }

            {
                float split_grad = tie_count > 0u ? alpha_grad[c] / (float)tie_count : 0.0f;
                for (k = 0u; k < rule_count; ++k)
                {
                    if (rule_consequents[k] == target_conseq)
                    {
                        raw_rule_gradients[rule_base + k] =
                            (tie_count > 0u && raw_rules[rule_base + k] >= max_a - 1.0e-6f)
                                ? split_grad
                                : 0.0f;
                    }
                }
            }
        }
    }
}

__kernel void fn_tuner_rules_backward(
    __global const float *restrict raw_inputs,
    __global const fn_premise_t *restrict input_mfs,
    __global const float *restrict eff_params,
    __global const fn_expression_t *restrict expressions,
    __global const uint *restrict rule_roots,
    __global const float *restrict expression_values,
    __global const float *restrict raw_rule_gradients,
    __global const float *restrict ann_activations,
    __global float *restrict expression_gradients,
    __global float *restrict membership_gradients,
    __global float *restrict sample_mf_gradients,
    __global float *restrict ann_deltas,
    uint sample_count,
    uint input_count,
    uint premise_count,
    uint expression_count,
    uint rule_count,
    uint total_param_count,
    uint neuron_count,
    uint ann_output_offset,
    uint logic_method,
    float tuner_scale,
    uint ann_enabled
)
{
    size_t sample = get_global_id(0);
    size_t raw_base;
    size_t param_base;
    size_t mem_base;
    size_t expr_base;
    size_t rule_base;
    size_t ann_base;
    uint i;
    uint rev;

    if (sample >= (size_t)sample_count)
    {
        return;
    }

    raw_base = sample * input_count;
    param_base = sample * total_param_count;
    mem_base = sample * premise_count;
    expr_base = sample * expression_count;
    rule_base = sample * rule_count;
    ann_base = sample * neuron_count + ann_output_offset;

    for (i = 0u; i < expression_count; ++i)
    {
        expression_gradients[expr_base + i] = 0.0f;
    }

    for (i = 0u; i < premise_count; ++i)
    {
        membership_gradients[mem_base + i] = 0.0f;
    }

    for (i = 0u; i < rule_count; ++i)
    {
        expression_gradients[expr_base + rule_roots[i]] += raw_rule_gradients[rule_base + i];
    }

    for (rev = expression_count; rev-- > 0u;)
    {
        fn_expression_t expr = expressions[rev];
        float incoming = expression_gradients[expr_base + rev];

        if (incoming == 0.0f)
        {
            continue;
        }

        if (expr.kind == FN_EXPR_MEMBERSHIP)
        {
            membership_gradients[mem_base + expr.value] += incoming;
        }
        else if (expr.kind == FN_EXPR_NOT)
        {
            expression_gradients[expr_base + expr.left] -= incoming;
        }
        else
        {
            float left = expression_values[expr_base + expr.left];
            float right = expression_values[expr_base + expr.right];

            if (logic_method == FN_LOGIC_ALGEBRAIC)
            {
                if (expr.kind == FN_EXPR_AND)
                {
                    expression_gradients[expr_base + expr.left] += incoming * right;
                    expression_gradients[expr_base + expr.right] += incoming * left;
                }
                else
                {
                    expression_gradients[expr_base + expr.left] += incoming * (1.0f - right);
                    expression_gradients[expr_base + expr.right] += incoming * (1.0f - left);
                }
            }
            else if (logic_method == FN_LOGIC_BOUNDED)
            {
                int active = expr.kind == FN_EXPR_AND
                    ? (left + right > 1.0f)
                    : (left + right < 1.0f);
                if (active)
                {
                    expression_gradients[expr_base + expr.left] += incoming;
                    expression_gradients[expr_base + expr.right] += incoming;
                }
            }
            else
            {
                int left_wins = expr.kind == FN_EXPR_AND ? (left < right) : (left > right);
                int right_wins = expr.kind == FN_EXPR_AND ? (right < left) : (right > left);

                if (!left_wins && !right_wins)
                {
                    expression_gradients[expr_base + expr.left] += 0.5f * incoming;
                    expression_gradients[expr_base + expr.right] += 0.5f * incoming;
                }
                else if (left_wins)
                {
                    expression_gradients[expr_base + expr.left] += incoming;
                }
                else
                {
                    expression_gradients[expr_base + expr.right] += incoming;
                }
            }
        }
    }

    /* Compute per-sample input MF parameter gradients and ANN output deltas */
    for (i = 0u; i < premise_count; ++i)
    {
        fn_premise_t mf = input_mfs[i];
        float mem_g = membership_gradients[mem_base + i];
        float x = raw_inputs[raw_base + mf.input_index];
        float mf_span = fmax(mf.domain_maximum - mf.domain_minimum, mf.epsilon);
        uint p;

        for (p = 0u; p < mf.parameter_count; ++p)
        {
            uint global_p = mf.parameter_offset + p;
            float g = 0.0f;
            float ann_delta = 0.0f;

            if (mem_g != 0.0f && p < 32u && (mf.trainable_mask & (1u << p)) != 0u)
            {
                float dmu = fn_eval_mf_param_deriv(
                    mf,
                    x,
                    eff_params,
                    (uint)param_base,
                    p
                );
                g = mem_g * dmu;
            }

            sample_mf_gradients[param_base + global_p] = g;

            if (ann_enabled != 0u &&
                tuner_scale > 0.0f &&
                p < 32u &&
                (mf.trainable_mask & (1u << p)) != 0u)
            {
                float ann_out = ann_activations[ann_base + global_p];
                ann_delta = g * (tuner_scale * mf_span) *
                            fn_derivative_from_output(ann_out, FN_ACTIVATION_TANH);
            }

            ann_deltas[ann_base + global_p] = ann_delta;
        }
    }
}

__kernel void fn_tuner_base_mf_update(
    __global const float *restrict sample_mf_gradients,
    __global float *restrict base_params,
    __global float *restrict first_moment,
    __global float *restrict second_moment,
    uint sample_count,
    uint total_param_count,
    uint optimizer_kind,
    float learning_rate,
    float alpha,
    float beta1,
    float beta2,
    float epsilon,
    float grad_clip,
    __local float *partial
)
{
    size_t lane = get_local_id(0);
    size_t local_count = get_local_size(0);
    size_t param = get_group_id(0);
    float sum = 0.0f;

    if (param >= (size_t)total_param_count)
    {
        return;
    }

    for (size_t s = lane; s < (size_t)sample_count; s += local_count)
    {
        sum += sample_mf_gradients[s * total_param_count + param];
    }

    partial[lane] = sum;
    barrier(CLK_LOCAL_MEM_FENCE);

    fn_reduce_local_sum(partial, lane, local_count);

    if (lane == 0u)
    {
        float g = sample_count != 0u ? partial[0] / (float)sample_count : 0.0f;
        if (!isfinite(g))
        {
            g = 0.0f;
        }
        if (grad_clip > 0.0f)
        {
            g = clamp(g, -grad_clip, grad_clip);
        }

        if (optimizer_kind == 1u)
        {
            float m1 = fma(1.0f - beta1, g, beta1 * first_moment[param]);
            float m2 = fma(1.0f - beta2, g * g, beta2 * second_moment[param]);
            first_moment[param] = m1;
            second_moment[param] = m2;
            base_params[param] -= alpha * m1 / (sqrt(m2) + epsilon);
        }
        else
        {
            base_params[param] -= learning_rate * g;
        }
    }
}

__kernel void fn_tuner_project_base_mfs(
    __global const fn_premise_t *restrict all_mfs,
    __global float *restrict base_params,
    uint total_mf_count
)
{
    size_t mf_idx = get_global_id(0);
    fn_premise_t mf;

    if (mf_idx >= (size_t)total_mf_count)
    {
        return;
    }

    mf = all_mfs[mf_idx];
    fn_project_mf_at(mf, base_params, (size_t)mf.parameter_offset);
}
