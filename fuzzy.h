#ifndef FUZZY_H
#define FUZZY_H

#include <stddef.h>
#include <stdarg.h>
#include <string.h>

#ifdef __C51__

typedef unsigned char bool;
typedef unsigned char uint8_t;

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#else

#include <stdbool.h>
#include <stdint.h>

#endif

/*
 * Desktop simulation dependencies.
 *
 * These headers are completely excluded from FUZZY_8051
 * builds.
 */
#ifndef FUZZY_8051

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#endif /* FUZZY_8051 */


#define LEVEL_HI 1.0f
#define LEVEL_LO 0.0f

#ifndef FUZZY_8051

#ifndef FUZZY_PRINTF
#define FUZZY_PRINTF(...) printf(__VA_ARGS__)
#endif

#ifndef FUZZY_ERROR
#define FUZZY_ERROR(...) fprintf(stderr, __VA_ARGS__)
#endif

#endif /* FUZZY_8051 */

/*
 * User-defined hedge exponents.
 *
 * The user may change these values according to the desired
 * linguistic interpretation.
 *
 * Example:
 *
 * hedges_t hedges = {
 *     .none      = 1.0f,
 *     .very      = 2.0f,
 *     .extremely = 3.0f,
 *     .somewhat  = 0.5f,
 *     .slightly  = 0.75f
 * };
 */
#ifndef FUZZY_8051

typedef float fuzzy_hedge_t;

typedef struct Hedges {
    fuzzy_hedge_t none;
    fuzzy_hedge_t very;
    fuzzy_hedge_t extremely;
    fuzzy_hedge_t somewhat;
    fuzzy_hedge_t slightly;
} hedges_t;

#else

/*
 * Integer-only hedge powers for the 8051 backend.
 *
 * Examples:
 *
 * none      = 1
 * very      = 2
 * extremely = 3
 *
 * Fractional hedges are unavailable because they require
 * roots or general exponentiation.
 */
typedef uint8_t fuzzy_hedge_t;

typedef struct Hedges {
    fuzzy_hedge_t none;
    fuzzy_hedge_t very;
    fuzzy_hedge_t extremely;
} hedges_t;

#endif /* FUZZY_8051 */

typedef float (*fuzzy_output_function_t)(float);

typedef enum FuzzyLogicMethod {
    FUZZY_LOGIC_STANDARD = 0,
    FUZZY_LOGIC_ALGEBRAIC,
    FUZZY_LOGIC_BOUNDED
} fuzzy_logic_method_t;


/* ==========================================================
 * Mamdani defuzzification methods
 * ========================================================== */

typedef enum FuzzyDefuzzMethod {
    FUZZY_DEFUZZ_COG = 0,
    FUZZY_DEFUZZ_MOM,
    FUZZY_DEFUZZ_SOM,
    FUZZY_DEFUZZ_LOM
} fuzzy_defuzz_method_t;


typedef struct FuzzyRule {
#ifndef FUZZY_8051
    const char *name;
#endif

    float value;
    fuzzy_output_function_t output_function;
} fuzzy_rule_t;


#ifndef FUZZY_MAX_RULES

#ifdef FUZZY_8051
#define FUZZY_MAX_RULES 8u
#else
#define FUZZY_MAX_RULES 32u
#endif

#endif /* FUZZY_MAX_RULES */


typedef struct FuzzyRules {
    fuzzy_rule_t rules[FUZZY_MAX_RULES];
    size_t count;
} fuzzy_rules_t;


/* ==========================================================
 * Rule-addition macros
 * ========================================================== */

#ifndef FUZZY_8051

#define FUZZY_RULE_ADD(rules, value, output_function) \
    fuzzy_rules_add(                                  \
        (rules),                                      \
        #output_function,                             \
        (value),                                      \
        (output_function)                             \
    )

#define FUZZY_RULE_ADD_NAMED(                         \
    rules, name, value, output_function               \
)                                                     \
    fuzzy_rules_add(                                  \
        (rules),                                      \
        (name),                                       \
        (value),                                      \
        (output_function)                             \
    )

#else

#define FUZZY_RULE_ADD(rules, value, output_function) \
    fuzzy_rules_add(                                  \
        (rules),                                      \
        NULL,                                         \
        (value),                                      \
        (output_function)                             \
    )

#define FUZZY_RULE_ADD_NAMED(                         \
    rules, name, value, output_function               \
)                                                     \
    fuzzy_rules_add(                                  \
        (rules),                                      \
        NULL,                                         \
        (value),                                      \
        (output_function)                             \
    )

#endif /* FUZZY_8051 */


/* ==========================================================
 * Core inference API
 *
 * Available on desktop and 8051.
 * ========================================================== */

float fuzzy_not(
    float membership
);

#ifndef FUZZY_8051_MINIMAL

float fuzzy_or(
    int count,
    ...
);

float fuzzy_and(
    int count,
    ...
);

float fuzzy_or_method(
    fuzzy_logic_method_t method,
    int count,
    ...
);

float fuzzy_and_method(
    fuzzy_logic_method_t method,
    int count,
    ...
);

#endif /* FUZZY_8051_MINIMAL */


/*
 * Sugeno weighted-average output.
 *
 * Arguments:
 *
 *     firing_strength_1, consequent_1,
 *     firing_strength_2, consequent_2,
 *     ...
 */
float fuzzy_sugeno_weighted_average(
    int rule_count,
    ...
);


/*
 * Sugeno weighted-sum output.
 *
 * Arguments use the same firing-strength/consequent pairs.
 */
float fuzzy_sugeno_weighted_sum(
    int rule_count,
    ...
);

float fuzzy_ramp(
    const char *name,
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    fuzzy_hedge_t hedge
);

#ifndef FUZZY_8051_MINIMAL

float fuzzy_function(
    const char *shape,
    float value,
    fuzzy_hedge_t hedge,
    ...
);

#endif

void fuzzy_rules_create(
    fuzzy_rules_t *rules
);

bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
);

/*
 * Defuzzify the aggregated Mamdani output.
 *
 * Supported methods:
 *
 * FUZZY_DEFUZZ_COG
 *     Center of gravity.
 *
 * FUZZY_DEFUZZ_MOM
 *     Mean of all sampled maximum positions.
 *
 * FUZZY_DEFUZZ_SOM
 *     Smallest sampled maximum position.
 *
 * FUZZY_DEFUZZ_LOM
 *     Largest sampled maximum position.
 */
float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
);


/*
 * Compatibility wrapper.
 *
 * Existing calls to fuzzy_rules_cog() continue to work.
 */
float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
);

void fuzzy_rules_free(
    fuzzy_rules_t *rules
);


/* ==========================================================
 * Desktop simulation and visualization API
 * ========================================================== */

#ifndef FUZZY_8051

typedef struct FuzzyPlot {
    FILE *file;

    float lower;
    float upper;
    float step;

    int width;
    int height;
    int padding;

    int plot_count;
} fuzzy_plot_t;


typedef struct FuzzyPlotSeries {
    const char *name;
    const char *color;
    fuzzy_output_function_t function;
} fuzzy_plot_series_t;


typedef struct FuzzySweepDimension {
    const char *name;

    float lower;
    float upper;
    float step;
} fuzzy_sweep_dimension_t;


typedef float (*fuzzy_sweep_evaluator_t)(
    const float inputs[],
    size_t input_count,
    float cog_step
);


typedef struct FuzzyCogSweep {
    const char *filename;
    const char *title;

    const fuzzy_sweep_dimension_t *dimensions;
    size_t dimension_count;

    float cog_step;

    fuzzy_sweep_evaluator_t evaluate;
} fuzzy_cog_sweep_t;


#define FUZZY_PLOT_FUNCTION(function_arg, color_arg)   \
    (fuzzy_plot_series_t) {                            \
        .name = #function_arg,                         \
        .color = (color_arg),                          \
        .function = (function_arg)                     \
    }


#define FUZZY_PLOT_FUNCTION_NAMED(                     \
    name_arg, color_arg, function_arg                  \
)                                                      \
    (fuzzy_plot_series_t) {                            \
        .name = (name_arg),                            \
        .color = (color_arg),                          \
        .function = (function_arg)                     \
    }


#define FUZZY_PLOT(                                    \
    filename_arg, title_arg, lower_arg, upper_arg,     \
    step_arg, ...                                      \
)                                                      \
    fuzzy_plot_many(                                   \
        (filename_arg),                                \
        (title_arg),                                   \
        (lower_arg),                                   \
        (upper_arg),                                   \
        (step_arg),                                    \
        (const fuzzy_plot_series_t[]) { __VA_ARGS__ }, \
        sizeof((const fuzzy_plot_series_t[]) {          \
            __VA_ARGS__                                \
        }) / sizeof(fuzzy_plot_series_t)               \
    )


#define FUZZY_SWEEP_DIMENSION(                         \
    name_arg, lower_arg, upper_arg, step_arg           \
)                                                      \
    (fuzzy_sweep_dimension_t) {                        \
        .name = (name_arg),                            \
        .lower = (lower_arg),                          \
        .upper = (upper_arg),                          \
        .step = (step_arg)                             \
    }


#define FUZZY_COG_SWEEP(                               \
    filename_arg,                                     \
    title_arg,                                        \
    evaluator_arg,                                    \
    cog_step_arg,                                     \
    ...                                               \
)                                                      \
    fuzzy_cog_sweep(                                  \
        &(const fuzzy_cog_sweep_t) {                  \
            .filename = (filename_arg),               \
            .title = (title_arg),                     \
            .dimensions =                             \
                (const fuzzy_sweep_dimension_t[]) {   \
                    __VA_ARGS__                       \
                },                                    \
            .dimension_count =                        \
                sizeof(                               \
                    (const fuzzy_sweep_dimension_t[]) { \
                        __VA_ARGS__                    \
                    }                                 \
                ) / sizeof(fuzzy_sweep_dimension_t),  \
            .cog_step = (cog_step_arg),               \
            .evaluate = (evaluator_arg)               \
        }                                             \
    )


bool fuzzy_plot_many(
    const char *filename,
    const char *title,
    float lower,
    float upper,
    float step,
    const fuzzy_plot_series_t series[],
    size_t series_count
);

bool fuzzy_plot_begin(
    fuzzy_plot_t *plot,
    const char *filename,
    const char *title,
    float lower,
    float upper,
    float step
);

bool fuzzy_plot_add(
    fuzzy_plot_t *plot,
    const char *name,
    const char *color,
    fuzzy_output_function_t function
);

void fuzzy_plot_end(
    fuzzy_plot_t *plot
);

void fuzzy_rules_print(
    const fuzzy_rules_t *rules
);

bool fuzzy_rules_plot_cog(
    const fuzzy_rules_t *rules,
    const char *filename,
    const char *title,
    float cog,
    float lower,
    float upper,
    float step
);

bool fuzzy_cog_sweep(
    const fuzzy_cog_sweep_t *sweep
);

void test_ramp(
    float (*function)(
        const char *,
        float,
        float,
        float,
        bool,
        fuzzy_hedge_t
    ),
    const char *name,
    float lower,
    float upper,
    bool ramp_up,
    fuzzy_hedge_t hedge,
    int run
);

#endif /* FUZZY_8051 */

#endif /* FUZZY_H */


/*
 * Implementation section.
 *
 * Define FUZZY_IMPLEMENTATION in exactly one .c file
 * before including fuzzy.h.
 */

#ifdef FUZZY_IMPLEMENTATION
#ifndef FUZZY_IMPLEMENTATION_ONCE
#define FUZZY_IMPLEMENTATION_ONCE

/*
 * Keep a membership value inside the valid fuzzy range.
 */
static float fuzzy_clamp(float value)
{
    if (value < LEVEL_LO) {
        return LEVEL_LO;
    }

    if (value > LEVEL_HI) {
        return LEVEL_HI;
    }

    return value;
}

/*
 * Keep a membership value inside the valid fuzzy range.
 */
float fuzzy_not(
    float membership
)
{
    return LEVEL_HI -
        fuzzy_clamp(
            membership
        );
}


/*
 * Apply a linguistic hedge using exponentiation.
 *
 * hedge = 1.0  -> unchanged
 * hedge > 1.0  -> concentration, such as "very"
 * hedge < 1.0  -> dilation, such as "somewhat"
 */
static float fuzzy_apply_hedge(
    float membership,
    fuzzy_hedge_t hedge
)
{
#ifdef FUZZY_8051

    float result;

#endif

    membership =
        fuzzy_clamp(membership);

#ifndef FUZZY_8051

    if (hedge <= 0.0f) {
        hedge = 1.0f;
    }

    return powf(
        membership,
        hedge
    );

#else

    if (hedge == 0u) {
        hedge = 1u;
    }

    result = LEVEL_HI;

    while (hedge > 0u) {
        result *= membership;
        hedge--;
    }

    return fuzzy_clamp(
        result
    );

#endif
}

#ifndef FUZZY_8051_MINIMAL
/*
 * Fuzzy OR:
 * Returns the maximum of all supplied membership values.
 *
 * Example:
 *
 * fuzzy_or(3, value1, value2, value3);
 */
static float fuzzy_or_v(fuzzy_logic_method_t method, int count, va_list args)
{
    float result;
    float next;
    int i;

    if (count <= 0) return LEVEL_LO;

    result = fuzzy_clamp((float)va_arg(args, double));

    for (i = 1; i < count; i++) {
        next = fuzzy_clamp((float)va_arg(args, double));

        switch (method) {
            case FUZZY_LOGIC_STANDARD:
                result = result > next ? result : next;
                break;
            case FUZZY_LOGIC_ALGEBRAIC:
                result = result + next - result * next;
                break;
            case FUZZY_LOGIC_BOUNDED:
                result += next;
                if (result > LEVEL_HI) result = LEVEL_HI;
                break;
            default:
                return LEVEL_LO;
        }
    }

    return fuzzy_clamp(result);
}

static float fuzzy_and_v(fuzzy_logic_method_t method, int count, va_list args)
{
    float result;
    float next;
    int i;

    if (count <= 0) return LEVEL_HI;

    result = fuzzy_clamp((float)va_arg(args, double));

    for (i = 1; i < count; i++) {
        next = fuzzy_clamp((float)va_arg(args, double));

        switch (method) {
            case FUZZY_LOGIC_STANDARD:
                result = result < next ? result : next;
                break;
            case FUZZY_LOGIC_ALGEBRAIC:
                result *= next;
                break;
            case FUZZY_LOGIC_BOUNDED:
                result = result + next - LEVEL_HI;
                if (result < LEVEL_LO) result = LEVEL_LO;
                break;
            default:
                return LEVEL_LO;
        }
    }

    return fuzzy_clamp(result);
}

float fuzzy_or_method(fuzzy_logic_method_t method, int count, ...)
{
    va_list args;
    float result;

    if (method < FUZZY_LOGIC_STANDARD || method > FUZZY_LOGIC_BOUNDED) {
        return LEVEL_LO;
    }

    va_start(args, count);
    result = fuzzy_or_v(method, count, args);
    va_end(args);
    return result;
}

float fuzzy_and_method(fuzzy_logic_method_t method, int count, ...)
{
    va_list args;
    float result;

    if (method < FUZZY_LOGIC_STANDARD || method > FUZZY_LOGIC_BOUNDED) {
        return LEVEL_LO;
    }

    va_start(args, count);
    result = fuzzy_and_v(method, count, args);
    va_end(args);
    return result;
}

float fuzzy_or(int count, ...)
{
    va_list args;
    float result;
    va_start(args, count);
    result = fuzzy_or_v(FUZZY_LOGIC_STANDARD, count, args);
    va_end(args);
    return result;
}

float fuzzy_and(int count, ...)
{
    va_list args;
    float result;
    va_start(args, count);
    result = fuzzy_and_v(FUZZY_LOGIC_STANDARD, count, args);
    va_end(args);
    return result;
}


#endif /* FUZZY_8051_MINIMAL */


/*
 * Sugeno weighted-average inference.
 */
float fuzzy_sugeno_weighted_average(
    int rule_count,
    ...
)
{
    va_list args;
    float weighted_sum;
    float firing_sum;
    float firing_strength;
    float consequent;
    int i;

    if (rule_count <= 0) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    firing_sum =
        0.0f;

    va_start(
        args,
        rule_count
    );

    for (
        i = 0;
        i < rule_count;
        i++
    ) {
        firing_strength =
            (float)va_arg(
                args,
                double
            );

        consequent =
            (float)va_arg(
                args,
                double
            );

        firing_strength =
            fuzzy_clamp(
                firing_strength
            );

#ifndef FUZZY_8051

        if (!isfinite(consequent)) {
            continue;
        }

#endif /* FUZZY_8051 */

        weighted_sum +=
            firing_strength *
            consequent;

        firing_sum +=
            firing_strength;
    }

    va_end(args);

    if (firing_sum <= LEVEL_LO) {
        return 0.0f;
    }

    return weighted_sum /
        firing_sum;
}


/*
 * Sugeno weighted-sum inference.
 */
float fuzzy_sugeno_weighted_sum(
    int rule_count,
    ...
)
{
    va_list args;
    float weighted_sum;
    float firing_strength;
    float consequent;
    int i;

    if (rule_count <= 0) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    va_start(
        args,
        rule_count
    );

    for (
        i = 0;
        i < rule_count;
        i++
    ) {
        firing_strength =
            (float)va_arg(
                args,
                double
            );

        consequent =
            (float)va_arg(
                args,
                double
            );

        firing_strength =
            fuzzy_clamp(
                firing_strength
            );

#ifndef FUZZY_8051

        if (!isfinite(consequent)) {
            continue;
        }

#endif /* FUZZY_8051 */

        weighted_sum +=
            firing_strength *
            consequent;
    }

    va_end(args);

    return weighted_sum;
}

/*
 * Linear ramp membership function.
 */
float fuzzy_ramp(
    const char *name,
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    fuzzy_hedge_t hedge
)
{
    float result;
    float normalized;

    (void)name;

    if (lower_boundary >= upper_boundary) {
        return LEVEL_LO;
    }

    if (value <= lower_boundary) {
        result =
            ramp_up
                ? LEVEL_LO
                : LEVEL_HI;
    }
    else if (value >= upper_boundary) {
        result =
            ramp_up
                ? LEVEL_HI
                : LEVEL_LO;
    }
    else {
        normalized =
            (value - lower_boundary) /
            (upper_boundary - lower_boundary);

        result =
            ramp_up
                ? normalized
                : LEVEL_HI - normalized;
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

/*
 * Generic membership-function wrapper.
 *
 * Supported shapes and arguments:
 *
 * ramp:
 *     lower_boundary, upper_boundary, ramp_up
 *
 * smf:
 *     lower_boundary, upper_boundary
 *
 * zmf:
 *     lower_boundary, upper_boundary
 *
 * gauss:
 *     mean, standard_deviation
 *
 * bell:
 *     width, slope, center
 *
 * sigmoid:
 *     slope, center
 *
 * Examples:
 *
 * fuzzy_function(
 *     "ramp",
 *     value,
 *     hedges.very,
 *     20.0,
 *     40.0,
 *     true
 * );
 *
 * fuzzy_function(
 *     "gauss",
 *     value,
 *     hedges.none,
 *     50.0,
 *     10.0
 * );
 */
#ifndef FUZZY_8051_MINIMAL

float fuzzy_function(
    const char *shape,
    float value,
    fuzzy_hedge_t hedge,
    ...
)
{
    va_list args;
    float result;

    float parameter_1;
    float parameter_2;
    float parameter_3;
    float parameter_4;

    bool ramp_up;

#ifndef FUZZY_8051

    float middle;
    float normalized;
    float difference;
    float exponent;

#endif /* FUZZY_8051 */

    if (shape == NULL) {
        return LEVEL_LO;
    }

    va_start(args, hedge);

    result = LEVEL_LO;

    if (strcmp(shape, "ramp") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        ramp_up =
            (bool)va_arg(args, int);

        va_end(args);

        return fuzzy_ramp(
            shape,
            parameter_1,
            parameter_2,
            value,
            ramp_up,
            hedge
        );
    }
    else if (strcmp(shape, "triangle") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        parameter_3 =
            (float)va_arg(args, double);

        if (
            parameter_1 >= parameter_2 ||
            parameter_2 >= parameter_3
        ) {
            result = LEVEL_LO;
        }
        else if (
            value <= parameter_1 ||
            value >= parameter_3
        ) {
            result = LEVEL_LO;
        }
        else if (value == parameter_2) {
            result = LEVEL_HI;
        }
        else if (value < parameter_2) {
            result =
                (value - parameter_1) /
                (parameter_2 - parameter_1);
        }
        else {
            result =
                (parameter_3 - value) /
                (parameter_3 - parameter_2);
        }
    }
    else if (strcmp(shape, "trapezoid") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        parameter_3 =
            (float)va_arg(args, double);

        parameter_4 =
            (float)va_arg(args, double);

        if (
            parameter_1 >= parameter_2 ||
            parameter_2 > parameter_3 ||
            parameter_3 >= parameter_4
        ) {
            result = LEVEL_LO;
        }
        else if (
            value <= parameter_1 ||
            value >= parameter_4
        ) {
            result = LEVEL_LO;
        }
        else if (
            value >= parameter_2 &&
            value <= parameter_3
        ) {
            result = LEVEL_HI;
        }
        else if (value < parameter_2) {
            result =
                (value - parameter_1) /
                (parameter_2 - parameter_1);
        }
        else {
            result =
                (parameter_4 - value) /
                (parameter_4 - parameter_3);
        }
    }

#ifndef FUZZY_8051

    else if (strcmp(shape, "smf") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        if (parameter_1 >= parameter_2) {
            result = LEVEL_LO;
        }
        else if (value <= parameter_1) {
            result = LEVEL_LO;
        }
        else if (value >= parameter_2) {
            result = LEVEL_HI;
        }
        else {
            middle =
                (parameter_1 + parameter_2) /
                2.0f;

            if (value <= middle) {
                normalized =
                    (value - parameter_1) /
                    (parameter_2 - parameter_1);

                result =
                    2.0f *
                    normalized *
                    normalized;
            }
            else {
                normalized =
                    (parameter_2 - value) /
                    (parameter_2 - parameter_1);

                result =
                    LEVEL_HI -
                    2.0f *
                    normalized *
                    normalized;
            }
        }
    }
    else if (strcmp(shape, "zmf") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        if (parameter_1 >= parameter_2) {
            result = LEVEL_LO;
        }
        else if (value <= parameter_1) {
            result = LEVEL_HI;
        }
        else if (value >= parameter_2) {
            result = LEVEL_LO;
        }
        else {
            middle =
                (parameter_1 + parameter_2) /
                2.0f;

            if (value <= middle) {
                normalized =
                    (value - parameter_1) /
                    (parameter_2 - parameter_1);

                result =
                    LEVEL_HI -
                    2.0f *
                    normalized *
                    normalized;
            }
            else {
                normalized =
                    (parameter_2 - value) /
                    (parameter_2 - parameter_1);

                result =
                    2.0f *
                    normalized *
                    normalized;
            }
        }
    }
    else if (strcmp(shape, "gauss") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        if (parameter_2 <= 0.0f) {
            result = LEVEL_LO;
        }
        else {
            difference =
                value - parameter_1;

            exponent =
                -(difference * difference) /
                (
                    2.0f *
                    parameter_2 *
                    parameter_2
                );

            result =
                expf(exponent);
        }
    }
    else if (strcmp(shape, "bell") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        parameter_3 =
            (float)va_arg(args, double);

        if (parameter_1 == 0.0f) {
            result = LEVEL_LO;
        }
        else {
            normalized =
                fabsf(
                    (value - parameter_3) /
                    (parameter_1 / 2.0f)
                );

            result =
                LEVEL_HI /
                (
                    LEVEL_HI +
                    powf(
                        normalized,
                        2.0f * parameter_2
                    )
                );
        }
    }
    else if (strcmp(shape, "sigmoid") == 0) {
        parameter_1 =
            (float)va_arg(args, double);

        parameter_2 =
            (float)va_arg(args, double);

        result =
            LEVEL_HI /
            (
                LEVEL_HI +
                expf(
                    -parameter_1 *
                    (value - parameter_2)
                )
            );
    }

#endif /* FUZZY_8051 */

    else {

#ifndef FUZZY_8051

        FUZZY_ERROR(
            "Unknown fuzzy shape: %s\n",
            shape
        );

#endif /* FUZZY_8051 */

        result = LEVEL_LO;
    }

    va_end(args);

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

#endif /* FUZZY_8051_MINIMAL */


#ifndef FUZZY_8051

void test_ramp(
    float (*function)(
        const char *,
        float,
        float,
        float,
        bool,
        fuzzy_hedge_t
    ),
    const char *name,
    float lower,
    float upper,
    bool ramp_up,
    fuzzy_hedge_t hedge,
    int run
)
{
    int i;

    for (i = 0; i < run; i++) {
        float value =
            (float)i;

        float result =
            function(
                name,
                lower,
                upper,
                value,
                ramp_up,
                hedge
            );

        FUZZY_PRINTF(
            "Value: %5.1f, Result: %.5f\n",
            value,
            result
        );
    }
}

#endif /* FUZZY_8051 */

void fuzzy_rules_create(
    fuzzy_rules_t *rules
)
{
    if (rules == NULL) {
        return;
    }

    rules->count = 0;
}


bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
)
{
    size_t index;

    if (
        rules == NULL ||
        output_function == NULL
    ) {
        return false;
    }

    if (rules->count >= FUZZY_MAX_RULES) {
    #ifndef FUZZY_8051

        FUZZY_ERROR(
            "Maximum fuzzy rule count exceeded.\n"
        );

    #endif

        return false;
    }

    index =
        rules->count;

#ifndef FUZZY_8051

    rules->rules[index].name =
        name;

#else

    (void)name;

#endif /* FUZZY_8051 */

    rules->rules[index].value =
        fuzzy_clamp(value);

    rules->rules[index].output_function =
        output_function;

    rules->count++;

    return true;
}


#ifndef FUZZY_8051

void fuzzy_rules_print(
    const fuzzy_rules_t *rules
)
{
    size_t i;

    if (rules == NULL) {
        return;
    }

    for (
        i = 0;
        i < rules->count;
        i++
    ) {
        FUZZY_PRINTF(
            "Rule %zu -> %s: %.5f\n",
            i + 1,
            rules->rules[i].name != NULL
                ? rules->rules[i].name
                : "Unnamed",
            rules->rules[i].value
        );
    }
}

#endif /* FUZZY_8051 */

/*
 * Mamdani defuzzification.
 *
 * The aggregated output is evaluated once at every sampled
 * output value.
 *
 * During the same pass, the function collects:
 *
 * - Weighted height sum for COG
 * - Total height for COG
 * - Maximum aggregated height
 * - Smallest maximum position for SOM
 * - Largest maximum position for LOM
 * - Sum and count of maximum positions for MOM
 */
float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
)
{
    float weighted_sum;
    float height_sum;

    float maximum_height;
    float maximum_position_sum;

    float smallest_maximum;
    float largest_maximum;

    float value;
    float aggregated_height;
    float output_membership;
    float clipped_height;

    size_t maximum_count;
    size_t i;

    bool maximum_found;

    if (
        rules == NULL ||
        rules->count == 0 ||
        lower > upper ||
        step <= 0.0f
    ) {
        return 0.0f;
    }

    if (
        method != FUZZY_DEFUZZ_COG &&
        method != FUZZY_DEFUZZ_MOM &&
        method != FUZZY_DEFUZZ_SOM &&
        method != FUZZY_DEFUZZ_LOM
    ) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    height_sum =
        0.0f;

    maximum_height =
        LEVEL_LO;

    maximum_position_sum =
        0.0f;

    smallest_maximum =
        lower;

    largest_maximum =
        lower;

    maximum_count =
        0u;

    maximum_found =
        false;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        aggregated_height =
            LEVEL_LO;

        /*
         * Mamdani implication and aggregation:
         *
         * implication = MIN
         * aggregation = MAX
         */
        for (
            i = 0;
            i < rules->count;
            i++
        ) {
            output_membership =
                rules->rules[i]
                    .output_function(
                        value
                    );

            output_membership =
                fuzzy_clamp(
                    output_membership
                );

            clipped_height =
                rules->rules[i].value <
                output_membership
                    ? rules->rules[i].value
                    : output_membership;

            aggregated_height =
                aggregated_height >
                clipped_height
                    ? aggregated_height
                    : clipped_height;
        }

        aggregated_height =
            fuzzy_clamp(
                aggregated_height
            );

        /*
         * COG accumulation.
         */
        weighted_sum +=
            value *
            aggregated_height;

        height_sum +=
            aggregated_height;

        /*
         * Maximum-family accumulation.
         *
         * A strictly larger height starts a new maximum set.
         */
        if (
            !maximum_found ||
            aggregated_height > maximum_height
        ) {
            maximum_height =
                aggregated_height;

            smallest_maximum =
                value;

            largest_maximum =
                value;

            maximum_position_sum =
                value;

            maximum_count =
                1u;

            maximum_found =
                true;
        }
        else if (
            aggregated_height == maximum_height
        ) {
            largest_maximum =
                value;

            maximum_position_sum +=
                value;

            maximum_count++;
        }
    }

    /*
     * No activated output area.
     */
    if (
        !maximum_found ||
        maximum_height <= LEVEL_LO ||
        height_sum <= LEVEL_LO
    ) {
        return 0.0f;
    }

    switch (method) {
        case FUZZY_DEFUZZ_COG:
            return weighted_sum /
                height_sum;

        case FUZZY_DEFUZZ_MOM:
            if (maximum_count == 0u) {
                return 0.0f;
            }

            return maximum_position_sum /
                (float)maximum_count;

        case FUZZY_DEFUZZ_SOM:
            return smallest_maximum;

        case FUZZY_DEFUZZ_LOM:
            return largest_maximum;

        default:
            return 0.0f;
    }
}


/*
 * Existing COG compatibility wrapper.
 */
float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
)
{
    return fuzzy_rules_defuzzify(
        rules,
        lower,
        upper,
        step,
        FUZZY_DEFUZZ_COG
    );
}

void fuzzy_rules_free(
    fuzzy_rules_t *rules
)
{
    if (rules == NULL) {
        return;
    }

    /*
     * Static storage requires no deallocation.
     *
     * Resetting count makes the container reusable.
     */
    rules->count = 0;
}

#ifndef FUZZY_8051

/* ==========================================================
 * Desktop simulation and visualization implementation
 * ========================================================== */

bool fuzzy_rules_plot_cog(
    const fuzzy_rules_t *rules,
    const char *filename,
    const char *title,
    float cog,
    float lower,
    float upper,
    float step
)
{
    if (
        rules == NULL ||
        filename == NULL ||
        rules->count == 0 ||
        lower >= upper ||
        step <= 0.0f
    ) {
        return false;
    }

    char plot_filename[256];

    int written = snprintf(
        plot_filename,
        sizeof(plot_filename),
        "%s.svg",
        filename
    );

    if (
        written < 0 ||
        (size_t)written >= sizeof(plot_filename)
    ) {
        return false;
    }

    fuzzy_plot_t plot;

    if (!fuzzy_plot_begin(
        &plot,
        plot_filename,
        title,
        lower,
        upper,
        step
    )) {
        return false;
    }

    FILE *file = plot.file;

    int left = plot.padding;
    int right = plot.width - plot.padding;
    int top = plot.padding;
    int bottom = plot.height - plot.padding;

    size_t sample_count = (size_t)ceilf(
        (upper - lower) / step
    );

    /*
     * Draw the aggregated Mamdani output.
     */
    fprintf(
        file,
        "<polyline fill=\"none\" stroke=\"#a855f7\" "
        "stroke-width=\"3\" stroke-linejoin=\"round\" "
        "stroke-linecap=\"round\" points=\""
    );

    for (size_t sample = 0; sample <= sample_count; sample++) {
        float value =
            lower + (float)sample * step;

        if (value > upper) {
            value = upper;
        }

        float aggregated_height = LEVEL_LO;

        for (size_t i = 0; i < rules->count; i++) {
            float output_membership =
                rules->rules[i].output_function(value);

            float clipped_height =
                rules->rules[i].value < output_membership
                    ? rules->rules[i].value
                    : output_membership;

            aggregated_height =
                aggregated_height > clipped_height
                    ? aggregated_height
                    : clipped_height;
        }

        aggregated_height =
            fuzzy_clamp(aggregated_height);

        float ratio =
            (value - lower) /
            (upper - lower);

        float x =
            (float)left +
            ratio * (float)(right - left);

        float y =
            (float)bottom -
            aggregated_height *
            (float)(bottom - top);

        fprintf(
            file,
            "%.2f,%.2f",
            x,
            y
        );

        if (sample < sample_count) {
            fputc(' ', file);
        }
    }

    fprintf(file, "\" />\n");

    /*
     * Draw a vertical line at the calculated COG.
     */
    float cog_ratio =
        (cog - lower) /
        (upper - lower);

    cog_ratio = fuzzy_clamp(cog_ratio);

    float cog_x =
        (float)left +
        cog_ratio * (float)(right - left);

    fprintf(
        file,
        "<line x1=\"%.2f\" y1=\"%d\" x2=\"%.2f\" y2=\"%d\" "
        "stroke=\"#ef4444\" stroke-width=\"3\" "
        "stroke-dasharray=\"8 5\" />\n",
        cog_x,
        top,
        cog_x,
        bottom
    );

    /*
     * COG point on the horizontal axis.
     */
    fprintf(
        file,
        "<circle cx=\"%.2f\" cy=\"%d\" r=\"6\" "
        "fill=\"#ef4444\" />\n",
        cog_x,
        bottom
    );

    /*
     * Label the COG value.
     */
    fprintf(
        file,
        "<rect x=\"%.2f\" y=\"%d\" width=\"130\" height=\"28\" "
        "rx=\"5\" fill=\"white\" stroke=\"#ef4444\" />\n",
        cog_x + 8.0f,
        top + 8
    );

    fprintf(
        file,
        "<text x=\"%.2f\" y=\"%d\" "
        "font-family=\"sans-serif\" font-size=\"14\" "
        "fill=\"#ef4444\">COG = %.5f</text>\n",
        cog_x + 16.0f,
        top + 27,
        cog
    );

    /*
     * Legend.
     */
    fprintf(
        file,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" "
        "stroke=\"#a855f7\" stroke-width=\"4\" />\n",
        left + 15,
        top + 20,
        left + 45,
        top + 20
    );

    fprintf(
        file,
        "<text x=\"%d\" y=\"%d\" dominant-baseline=\"middle\" "
        "font-family=\"sans-serif\" font-size=\"14\" "
        "fill=\"black\">Aggregated output</text>\n",
        left + 55,
        top + 20
    );

    fuzzy_plot_end(&plot);

    FUZZY_PRINTF(
        "COG plot written to %s\n",
        plot_filename
    );

    return true;
}

static void fuzzy_plot_write_text(
    FILE *file,
    const char *text
)
{
    if (file == NULL || text == NULL) {
        return;
    }

    while (*text != '\0') {
        switch (*text) {
            case '&':
                fputs("&amp;", file);
                break;

            case '<':
                fputs("&lt;", file);
                break;

            case '>':
                fputs("&gt;", file);
                break;

            case '"':
                fputs("&quot;", file);
                break;

            case '\'':
                fputs("&apos;", file);
                break;

            default:
                fputc(*text, file);
                break;
        }

        text++;
    }
}

bool fuzzy_plot_begin(
    fuzzy_plot_t *plot,
    const char *filename,
    const char *title,
    float lower,
    float upper,
    float step
)
{
    if (
        plot == NULL ||
        filename == NULL ||
        lower >= upper ||
        step <= 0.0f
    ) {
        return false;
    }

    plot->file = fopen(filename, "w");

    if (plot->file == NULL) {
        return false;
    }

    plot->lower = lower;
    plot->upper = upper;
    plot->step = step;

    plot->width = 900;
    plot->height = 600;
    plot->padding = 80;
    plot->plot_count = 0;

    FILE *file = plot->file;

    int left = plot->padding;
    int right = plot->width - plot->padding;
    int top = plot->padding;
    int bottom = plot->height - plot->padding;

    fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");

    fprintf(
        file,
        "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n",
        plot->width,
        plot->height,
        plot->width,
        plot->height
    );

    fprintf(
        file,
        "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"white\" />\n",
        plot->width,
        plot->height
    );

    fprintf(
        file,
        "<text x=\"%d\" y=\"35\" text-anchor=\"middle\" font-family=\"sans-serif\" font-size=\"22\" font-weight=\"bold\" fill=\"black\">",
        plot->width / 2
    );

    fuzzy_plot_write_text(
        file,
        title != NULL
            ? title
            : "Fuzzy Membership Functions"
    );

    fprintf(file, "</text>\n");

    /*
     * Horizontal grid lines and membership-axis labels.
     */
    for (int i = 0; i <= 10; i++) {
        float membership = (float)i / 10.0f;

        float y =
            (float)bottom -
            membership * (float)(bottom - top);

        fprintf(
            file,
            "<line x1=\"%d\" y1=\"%.2f\" x2=\"%d\" y2=\"%.2f\" stroke=\"#dddddd\" stroke-width=\"1\" />\n",
            left,
            y,
            right,
            y
        );

        fprintf(
            file,
            "<text x=\"%d\" y=\"%.2f\" text-anchor=\"end\" dominant-baseline=\"middle\" font-family=\"sans-serif\" font-size=\"12\" fill=\"black\">%.1f</text>\n",
            left - 10,
            y,
            membership
        );
    }

    /*
     * Vertical grid lines and input-axis labels.
     */
    for (int i = 0; i <= 10; i++) {
        float ratio = (float)i / 10.0f;

        float value =
            lower +
            ratio * (upper - lower);

        float x =
            (float)left +
            ratio * (float)(right - left);

        fprintf(
            file,
            "<line x1=\"%.2f\" y1=\"%d\" x2=\"%.2f\" y2=\"%d\" stroke=\"#eeeeee\" stroke-width=\"1\" />\n",
            x,
            top,
            x,
            bottom
        );

        fprintf(
            file,
            "<text x=\"%.2f\" y=\"%d\" text-anchor=\"middle\" font-family=\"sans-serif\" font-size=\"12\" fill=\"black\">%.1f</text>\n",
            x,
            bottom + 22,
            value
        );
    }

    /*
     * Main horizontal and vertical axes.
     */
    fprintf(
        file,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"2\" />\n",
        left,
        bottom,
        right,
        bottom
    );

    fprintf(
        file,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"2\" />\n",
        left,
        top,
        left,
        bottom
    );

    /*
     * Axis titles.
     */
    fprintf(
        file,
        "<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" font-family=\"sans-serif\" font-size=\"15\" fill=\"black\">Input value</text>\n",
        plot->width / 2,
        plot->height - 20
    );

    fprintf(
        file,
        "<text x=\"22\" y=\"%d\" text-anchor=\"middle\" font-family=\"sans-serif\" font-size=\"15\" fill=\"black\" transform=\"rotate(-90 22 %d)\">Membership</text>\n",
        plot->height / 2,
        plot->height / 2
    );

    return true;
}

bool fuzzy_plot_add(
    fuzzy_plot_t *plot,
    const char *name,
    const char *color,
    fuzzy_output_function_t function
)
{
    if (
        plot == NULL ||
        plot->file == NULL ||
        function == NULL
    ) {
        return false;
    }

    if (name == NULL) {
        name = "Unnamed";
    }

    if (color == NULL) {
        color = "black";
    }

    FILE *file = plot->file;

    int left = plot->padding;
    int right = plot->width - plot->padding;
    int top = plot->padding;
    int bottom = plot->height - plot->padding;

    fprintf(
        file,
        "<polyline fill=\"none\" stroke=\"%s\" stroke-width=\"3\" stroke-linejoin=\"round\" stroke-linecap=\"round\" points=\"",
        color
    );

    /*
     * Use an integer sample index to avoid floating-point
     * accumulation errors from repeatedly adding step.
     */
    size_t sample_count =
        (size_t)ceilf(
            (plot->upper - plot->lower) /
            plot->step
        );

    for (size_t i = 0; i <= sample_count; i++) {
        float value =
            plot->lower +
            (float)i * plot->step;

        if (value > plot->upper) {
            value = plot->upper;
        }

        float membership =
            fuzzy_clamp(function(value));

        float input_ratio =
            (value - plot->lower) /
            (plot->upper - plot->lower);

        float x =
            (float)left +
            input_ratio * (float)(right - left);

        float y =
            (float)bottom -
            membership * (float)(bottom - top);

        fprintf(
            file,
            "%.2f,%.2f",
            x,
            y
        );

        if (i < sample_count) {
            fputc(' ', file);
        }
    }

    fprintf(file, "\" />\n");

    /*
     * Legend entry.
     */
    int legend_x = left + 15;

    int legend_y =
        top +
        20 +
        plot->plot_count * 24;

    fprintf(
        file,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"4\" />\n",
        legend_x,
        legend_y,
        legend_x + 30,
        legend_y,
        color
    );

    fprintf(
        file,
        "<text x=\"%d\" y=\"%d\" dominant-baseline=\"middle\" font-family=\"sans-serif\" font-size=\"14\" fill=\"black\">",
        legend_x + 40,
        legend_y
    );

    fuzzy_plot_write_text(
        file,
        name
    );

    fprintf(file, "</text>\n");

    plot->plot_count++;

    return true;
}

void fuzzy_plot_end(
    fuzzy_plot_t *plot
)
{
    if (
        plot == NULL ||
        plot->file == NULL
    ) {
        return;
    }

    fprintf(plot->file, "</svg>\n");

    fclose(plot->file);

    plot->file = NULL;
}

bool fuzzy_plot_many(
    const char *filename,
    const char *title,
    float lower,
    float upper,
    float step,
    const fuzzy_plot_series_t series[],
    size_t series_count
)
{
    if (
        filename == NULL ||
        series == NULL ||
        series_count == 0
    ) {
        return false;
    }

    fuzzy_plot_t plot;

    const char *plot_title = title != NULL
        ? title
        : "Fuzzy Membership Functions";

    char plot_filename[256];

    int written = snprintf(
        plot_filename,
        sizeof(plot_filename),
        "%s.svg",
        filename
    );

    if (
        written < 0 ||
        (size_t)written >= sizeof(plot_filename)
    ) {
        fprintf(
            stderr,
            "Plot filename is too long.\n"
        );

        return false;
    }

    if (!fuzzy_plot_begin(
        &plot,
        plot_filename,
        plot_title,
        lower,
        upper,
        step
    )) {
        return false;
    }

    for (size_t i = 0; i < series_count; i++) {
        if (series[i].function == NULL) {
            fuzzy_plot_end(&plot);
            return false;
        }

        if (!fuzzy_plot_add(
            &plot,
            series[i].name,
            series[i].color,
            series[i].function
        )) {
            fuzzy_plot_end(&plot);
            return false;
        }
    }

    fuzzy_plot_end(&plot);

    FUZZY_PRINTF(
        "Membership plot written to %s\n",
        plot_filename
    );

    return true;
}

#ifdef FUZZY_DEMO

/* ==========================================================
 * Built-in membership-function SVG demonstration
 * ========================================================== */

static float fuzzy_demo_ramp(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        1.0f,
        20.0,
        80.0,
        true
    );
}

static float fuzzy_demo_triangle(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        1.0f,
        20.0,
        50.0,
        80.0
    );
}

static float fuzzy_demo_trapezoid(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        1.0f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float fuzzy_demo_trapezoid_normal(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        1.0f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float fuzzy_demo_trapezoid_very(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        2.0f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float fuzzy_demo_trapezoid_extremely(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        3.0f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float fuzzy_demo_trapezoid_somewhat(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        0.5f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float fuzzy_demo_trapezoid_slightly(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        0.75f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float fuzzy_demo_smf(float value)
{
    return fuzzy_function(
        "smf",
        value,
        1.0f,
        20.0,
        80.0
    );
}

static float fuzzy_demo_zmf(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        1.0f,
        20.0,
        80.0
    );
}

static float fuzzy_demo_gauss(float value)
{
    return fuzzy_function(
        "gauss",
        value,
        1.0f,
        50.0,
        15.0
    );
}

static float fuzzy_demo_bell(float value)
{
    return fuzzy_function(
        "bell",
        value,
        1.0f,
        30.0,
        2.0,
        50.0
    );
}

static float fuzzy_demo_sigmoid(float value)
{
    return fuzzy_function(
        "sigmoid",
        value,
        1.0f,
        0.12,
        50.0
    );
}

typedef struct FuzzyDemoFunction {
    const char *filename;
    const char *title;
    const char *name;
    const char *color;
    fuzzy_output_function_t function;
} fuzzy_demo_function_t;

bool fuzzy_demo(void)
{
    const fuzzy_demo_function_t demos[] = {
        {
            .filename = "demo-svg/ramp",
            .title = "Ramp Membership Function",
            .name = "Ramp",
            .color = "#ef4444",
            .function = fuzzy_demo_ramp
        },
        {
            .filename = "demo-svg/triangle",
            .title = "Triangular Membership Function",
            .name = "Triangle",
            .color = "#eab308",
            .function = fuzzy_demo_triangle
        },
        {
            .filename = "demo-svg/trapezoid",
            .title = "Trapezoidal Membership Function",
            .name = "Trapezoid",
            .color = "#f97316",
            .function = fuzzy_demo_trapezoid
        },
        {
            .filename = "demo-svg/smf",
            .title = "S-Shaped Membership Function",
            .name = "SMF",
            .color = "#22c55e",
            .function = fuzzy_demo_smf
        },
        {
            .filename = "demo-svg/zmf",
            .title = "Z-Shaped Membership Function",
            .name = "ZMF",
            .color = "#3b82f6",
            .function = fuzzy_demo_zmf
        },
        {
            .filename = "demo-svg/gauss",
            .title = "Gaussian Membership Function",
            .name = "Gaussian",
            .color = "#a855f7",
            .function = fuzzy_demo_gauss
        },
        {
            .filename = "demo-svg/bell",
            .title = "Generalized Bell Membership Function",
            .name = "Bell",
            .color = "#f97316",
            .function = fuzzy_demo_bell
        },
        {
            .filename = "demo-svg/sigmoid",
            .title = "Sigmoid Membership Function",
            .name = "Sigmoid",
            .color = "#06b6d4",
            .function = fuzzy_demo_sigmoid
        }
    };

    const size_t demo_count = sizeof(demos) / sizeof(demos[0]);

    for (size_t i = 0; i < demo_count; i++) {
        const fuzzy_plot_series_t series[] = {
            {
                .name = demos[i].name,
                .color = demos[i].color,
                .function = demos[i].function
            }
        };

        if (!fuzzy_plot_many(
            demos[i].filename,
            demos[i].title,
            0.0f,
            100.0f,
            1.0f,
            series,
            sizeof(series) / sizeof(series[0])
        )) {
            fprintf(
                stderr,
                "[FAILED] Could not generate %s.svg\n",
                demos[i].filename
            );

            return false;
        }

        FUZZY_PRINTF(
            "[OK] Generated %s.svg\n",
            demos[i].filename
        );
    }
        if (!FUZZY_PLOT(
        "demo-svg/trapezoid_hedges",
        "Trapezoidal Membership Function Hedges",
        0.0f,
        100.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Normal",
            "#111827",
            fuzzy_demo_trapezoid_normal
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Very",
            "#ef4444",
            fuzzy_demo_trapezoid_very
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Extremely",
            "#a855f7",
            fuzzy_demo_trapezoid_extremely
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Somewhat",
            "#22c55e",
            fuzzy_demo_trapezoid_somewhat
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Slightly",
            "#3b82f6",
            fuzzy_demo_trapezoid_slightly
        )
    )) {
        fprintf(
            stderr,
            "[FAILED] Could not generate trapezoid_hedges.svg\n"
        );

        return false;
    }

    FUZZY_PRINTF("[OK] Generated trapezoid_hedges.svg\n");

    FUZZY_PRINTF(
        "\nGenerated all %zu membership-function SVG demos.\n",
        demo_count
    );

    return true;
}

#endif /* FUZZY_DEMO */

/*
 * Write the parsed N-dimensional COG sweep as SVG.
 *
 * 1 dimension:
 *     COG line graph.
 *
 * 2 dimensions:
 *     COG heatmap.
 *
 * 3+ dimensions:
 *     First two dimensions form the heatmap.
 *     Remaining dimensions are selectable SVG slices.
 *
 * This function is private. The user only calls
 * FUZZY_COG_SWEEP().
 */
static bool fuzzy_sweep_write_svg(
    const fuzzy_cog_sweep_t *sweep,
    const size_t sample_counts[],
    size_t total_points,
    const float parsed_inputs[],
    const float parsed_cog_values[]
)
{
    if (
        sweep == NULL ||
        sweep->filename == NULL ||
        sweep->dimensions == NULL ||
        sweep->dimension_count == 0 ||
        sample_counts == NULL ||
        total_points == 0 ||
        parsed_inputs == NULL ||
        parsed_cog_values == NULL
    ) {
        return false;
    }

    const size_t dimension_count =
        sweep->dimension_count;

    char svg_filename[256];

    int written = snprintf(
        svg_filename,
        sizeof(svg_filename),
        "%s.svg",
        sweep->filename
    );

    if (
        written < 0 ||
        (size_t)written >= sizeof(svg_filename)
    ) {
        FUZZY_ERROR(
            "COG sweep SVG filename is too long.\n"
        );

        return false;
    }

    FILE *file = fopen(
        svg_filename,
        "w"
    );

    if (file == NULL) {
        FUZZY_ERROR(
            "Failed to open %s.\n",
            svg_filename
        );

        return false;
    }

    float minimum_cog =
        parsed_cog_values[0];

    float maximum_cog =
        parsed_cog_values[0];

    for (
        size_t point = 1;
        point < total_points;
        point++
    ) {
        if (
            parsed_cog_values[point] <
            minimum_cog
        ) {
            minimum_cog =
                parsed_cog_values[point];
        }

        if (
            parsed_cog_values[point] >
            maximum_cog
        ) {
            maximum_cog =
                parsed_cog_values[point];
        }
    }

    float cog_range =
        maximum_cog -
        minimum_cog;

    if (cog_range <= 0.0f) {
        cog_range = 1.0f;
    }

    const int width = 1050;
    const int height =
        dimension_count > 2
            ? 820
            : 730;

    const int left = 110;
    const int right = 850;
    const int top = 90;
    const int bottom = 610;

    const int plot_width =
        right - left;

    const int plot_height =
        bottom - top;

    fprintf(
        file,
        "<?xml version=\"1.0\" "
        "encoding=\"UTF-8\"?>\n"
    );

    fprintf(
        file,
        "<svg "
        "xmlns=\"http://www.w3.org/2000/svg\" "
        "xmlns:xlink=\"http://www.w3.org/1999/xlink\" "
        "width=\"%d\" height=\"%d\" "
        "viewBox=\"0 0 %d %d\">\n",
        width,
        height,
        width,
        height
    );

    fprintf(
        file,
        "<rect x=\"0\" y=\"0\" "
        "width=\"%d\" height=\"%d\" "
        "fill=\"white\" />\n",
        width,
        height
    );

    fprintf(
        file,
        "<text x=\"%d\" y=\"38\" "
        "text-anchor=\"middle\" "
        "font-family=\"sans-serif\" "
        "font-size=\"24\" "
        "font-weight=\"bold\">",
        width / 2
    );

    fuzzy_plot_write_text(
        file,
        sweep->title != NULL
            ? sweep->title
            : "COG Sweep"
    );

    fprintf(
        file,
        "</text>\n"
    );

    /*
     * One-dimensional sweep:
     * draw a normal COG line graph.
     */
    if (dimension_count == 1) {
        fprintf(
            file,
            "<rect x=\"%d\" y=\"%d\" "
            "width=\"%d\" height=\"%d\" "
            "fill=\"#fafafa\" "
            "stroke=\"#111827\" "
            "stroke-width=\"2\" />\n",
            left,
            top,
            plot_width,
            plot_height
        );

        for (int tick = 0; tick <= 10; tick++) {
            float ratio =
                (float)tick / 10.0f;

            float x =
                (float)left +
                ratio *
                (float)plot_width;

            float y =
                (float)bottom -
                ratio *
                (float)plot_height;

            float input_value =
                sweep->dimensions[0].lower +
                ratio *
                (
                    sweep->dimensions[0].upper -
                    sweep->dimensions[0].lower
                );

            float cog_value =
                minimum_cog +
                ratio *
                (
                    maximum_cog -
                    minimum_cog
                );

            fprintf(
                file,
                "<line x1=\"%.2f\" y1=\"%d\" "
                "x2=\"%.2f\" y2=\"%d\" "
                "stroke=\"#e5e7eb\" />\n",
                x,
                top,
                x,
                bottom
            );

            fprintf(
                file,
                "<line x1=\"%d\" y1=\"%.2f\" "
                "x2=\"%d\" y2=\"%.2f\" "
                "stroke=\"#e5e7eb\" />\n",
                left,
                y,
                right,
                y
            );

            fprintf(
                file,
                "<text x=\"%.2f\" y=\"%d\" "
                "text-anchor=\"middle\" "
                "font-family=\"sans-serif\" "
                "font-size=\"11\">%.2f</text>\n",
                x,
                bottom + 22,
                input_value
            );

            fprintf(
                file,
                "<text x=\"%d\" y=\"%.2f\" "
                "text-anchor=\"end\" "
                "dominant-baseline=\"middle\" "
                "font-family=\"sans-serif\" "
                "font-size=\"11\">%.2f</text>\n",
                left - 10,
                y,
                cog_value
            );
        }

        fprintf(
            file,
            "<polyline fill=\"none\" "
            "stroke=\"#7c3aed\" "
            "stroke-width=\"4\" "
            "stroke-linejoin=\"round\" "
            "stroke-linecap=\"round\" "
            "points=\""
        );

        for (
            size_t point = 0;
            point < total_points;
            point++
        ) {
            float input_value =
                parsed_inputs[point];

            float input_ratio =
                (
                    input_value -
                    sweep->dimensions[0].lower
                ) /
                (
                    sweep->dimensions[0].upper -
                    sweep->dimensions[0].lower
                );

            float cog_ratio =
                (
                    parsed_cog_values[point] -
                    minimum_cog
                ) /
                cog_range;

            float x =
                (float)left +
                input_ratio *
                (float)plot_width;

            float y =
                (float)bottom -
                cog_ratio *
                (float)plot_height;

            fprintf(
                file,
                "%.2f,%.2f",
                x,
                y
            );

            if (point + 1 < total_points) {
                fputc(' ', file);
            }
        }

        fprintf(
            file,
            "\" />\n"
        );

        fprintf(
            file,
            "<text x=\"%d\" y=\"%d\" "
            "text-anchor=\"middle\" "
            "font-family=\"sans-serif\" "
            "font-size=\"15\">",
            (left + right) / 2,
            bottom + 55
        );

        fuzzy_plot_write_text(
            file,
            sweep->dimensions[0].name != NULL
                ? sweep->dimensions[0].name
                : "Input"
        );

        fprintf(
            file,
            "</text>\n"
        );

        fprintf(
            file,
            "<text x=\"35\" y=\"%d\" "
            "text-anchor=\"middle\" "
            "font-family=\"sans-serif\" "
            "font-size=\"15\" "
            "transform=\"rotate(-90 35 %d)\">"
            "COG</text>\n",
            (top + bottom) / 2,
            (top + bottom) / 2
        );
    }
    else {
        /*
         * Dynamic multidimensional heatmap.
         *
         * Only x_count * y_count SVG cells are created.
         * All COG values are embedded as JavaScript data.
         *
         * Slider movement recalculates flat point indices
         * and repaints the existing heatmap cells.
         */
        const size_t x_count =
            sample_counts[0];

        const size_t y_count =
            sample_counts[1];

        const size_t cell_count =
            x_count * y_count;

        float cell_width =
            (float)plot_width /
            (float)x_count;

        float cell_height =
            (float)plot_height /
            (float)y_count;

        /*
         * Heatmap background and border.
         */
        fprintf(
            file,
            "<rect x=\"%d\" y=\"%d\" "
            "width=\"%d\" height=\"%d\" "
            "fill=\"#f9fafb\" "
            "stroke=\"#111827\" "
            "stroke-width=\"2\" />\n",
            left,
            top,
            plot_width,
            plot_height
        );

        /*
         * Create only one reusable grid.
         */
        fprintf(
            file,
            "<g id=\"fuzzy-heatmap\">\n"
        );

        for (
            size_t x_index = 0;
            x_index < x_count;
            x_index++
        ) {
            for (
                size_t y_index = 0;
                y_index < y_count;
                y_index++
            ) {
                size_t cell =
                    x_index * y_count +
                    y_index;

                float x =
                    (float)left +
                    (float)x_index *
                    cell_width;

                /*
                 * Reverse the SVG Y direction so larger
                 * dimension values appear upward.
                 */
                float y =
                    (float)bottom -
                    (float)(y_index + 1) *
                    cell_height;

                fprintf(
                    file,
                    "<rect "
                    "id=\"fuzzy-cell-%zu\" "
                    "x=\"%.3f\" y=\"%.3f\" "
                    "width=\"%.3f\" height=\"%.3f\" "
                    "fill=\"#2563eb\" "
                    "stroke=\"none\">"
                    "<title id=\"fuzzy-title-%zu\">"
                    "Loading"
                    "</title>"
                    "</rect>\n",
                    cell,
                    x,
                    y,
                    cell_width + 0.3f,
                    cell_height + 0.3f,
                    cell
                );
            }
        }

        fprintf(
            file,
            "</g>\n"
        );

        /*
         * Heatmap axes.
         */
        for (int tick = 0; tick <= 10; tick++) {
            float ratio =
                (float)tick / 10.0f;

            float x =
                (float)left +
                ratio *
                (float)plot_width;

            float y =
                (float)bottom -
                ratio *
                (float)plot_height;

            float x_value =
                sweep->dimensions[0].lower +
                ratio *
                (
                    sweep->dimensions[0].upper -
                    sweep->dimensions[0].lower
                );

            float y_value =
                sweep->dimensions[1].lower +
                ratio *
                (
                    sweep->dimensions[1].upper -
                    sweep->dimensions[1].lower
                );

            fprintf(
                file,
                "<text x=\"%.2f\" y=\"%d\" "
                "text-anchor=\"middle\" "
                "font-family=\"sans-serif\" "
                "font-size=\"11\">%.2f</text>\n",
                x,
                bottom + 22,
                x_value
            );

            fprintf(
                file,
                "<text x=\"%d\" y=\"%.2f\" "
                "text-anchor=\"end\" "
                "dominant-baseline=\"middle\" "
                "font-family=\"sans-serif\" "
                "font-size=\"11\">%.2f</text>\n",
                left - 10,
                y,
                y_value
            );
        }

        /*
         * Horizontal axis title.
         */
        fprintf(
            file,
            "<text x=\"%d\" y=\"%d\" "
            "text-anchor=\"middle\" "
            "font-family=\"sans-serif\" "
            "font-size=\"15\">",
            (left + right) / 2,
            bottom + 55
        );

        fuzzy_plot_write_text(
            file,
            sweep->dimensions[0].name != NULL
                ? sweep->dimensions[0].name
                : "Input 1"
        );

        fprintf(
            file,
            "</text>\n"
        );

        /*
         * Vertical axis title.
         */
        fprintf(
            file,
            "<text x=\"35\" y=\"%d\" "
            "text-anchor=\"middle\" "
            "font-family=\"sans-serif\" "
            "font-size=\"15\" "
            "transform=\"rotate(-90 35 %d)\">",
            (top + bottom) / 2,
            (top + bottom) / 2
        );

        fuzzy_plot_write_text(
            file,
            sweep->dimensions[1].name != NULL
                ? sweep->dimensions[1].name
                : "Input 2"
        );

        fprintf(
            file,
            "</text>\n"
        );

        /*
         * COG colour bar.
         */
        fprintf(
            file,
            "<defs>"
            "<linearGradient id=\"cog-gradient\" "
            "x1=\"0\" y1=\"1\" x2=\"0\" y2=\"0\">"
            "<stop offset=\"0%%\" "
            "stop-color=\"rgb(37,99,235)\" />"
            "<stop offset=\"33%%\" "
            "stop-color=\"rgb(37,231,235)\" />"
            "<stop offset=\"66%%\" "
            "stop-color=\"rgb(250,244,41)\" />"
            "<stop offset=\"100%%\" "
            "stop-color=\"rgb(239,68,14)\" />"
            "</linearGradient>"
            "</defs>\n"
        );

        fprintf(
            file,
            "<rect x=\"900\" y=\"%d\" "
            "width=\"28\" height=\"%d\" "
            "fill=\"url(#cog-gradient)\" "
            "stroke=\"#111827\" />\n",
            top,
            plot_height
        );

        fprintf(
            file,
            "<text x=\"940\" y=\"%d\" "
            "font-family=\"sans-serif\" "
            "font-size=\"12\">%.3f</text>\n",
            top + 5,
            maximum_cog
        );

        fprintf(
            file,
            "<text x=\"940\" y=\"%d\" "
            "font-family=\"sans-serif\" "
            "font-size=\"12\">%.3f</text>\n",
            bottom,
            minimum_cog
        );

        fprintf(
            file,
            "<text x=\"914\" y=\"%d\" "
            "text-anchor=\"middle\" "
            "font-family=\"sans-serif\" "
            "font-size=\"14\" "
            "transform=\"rotate(-90 914 %d)\">"
            "COG</text>\n",
            (top + bottom) / 2,
            (top + bottom) / 2
        );

        /*
         * Slider controls for dimensions 3 through N.
         */
        if (dimension_count > 2) {
            int control_height =
                55 +
                (int)(dimension_count - 2) * 38;

            fprintf(
                file,
                "<foreignObject "
                "x=\"%d\" y=\"700\" "
                "width=\"%d\" height=\"%d\">\n",
                left,
                right - left,
                control_height
            );

            fprintf(
                file,
                "<div "
                "xmlns=\"http://www.w3.org/1999/xhtml\" "
                "style=\"font-family:sans-serif;"
                "display:grid;"
                "grid-template-columns:repeat(2,minmax(0,1fr));"
                "gap:10px 18px;"
                "padding:10px;"
                "border:1px solid #d1d5db;"
                "border-radius:8px;"
                "background:#f9fafb;\">\n"
            );

            for (
                size_t dimension = 2;
                dimension < dimension_count;
                dimension++
            ) {
                fprintf(
                    file,
                    "<label style=\"display:flex;"
                    "flex-direction:column;"
                    "font-size:13px;\">"
                );

                fuzzy_plot_write_text(
                    file,
                    sweep->dimensions[dimension].name != NULL
                        ? sweep->dimensions[dimension].name
                        : "Slice dimension"
                );

                fprintf(
                    file,
                    ": <span id=\"slice-value-%zu\">"
                    "%.4f</span>"
                    "<input id=\"slice-slider-%zu\" "
                    "type=\"range\" "
                    "min=\"0\" max=\"%zu\" "
                    "step=\"0.01\" value=\"0\" />"
                    "</label>\n",
                    dimension,
                    sweep->dimensions[dimension].lower,
                    dimension,
                    sample_counts[dimension] - 1
                );
            }

            fprintf(
                file,
                "</div>\n"
                "</foreignObject>\n"
            );
        }

        /*
         * Embedded JavaScript data and renderer.
         */
        fprintf(
            file,
            "<script type=\"application/ecmascript\">"
            "<![CDATA[\n"
        );

        /*
         * Dimension sample counts.
         */
        fprintf(
            file,
            "const fuzzySampleCounts=["
        );

        for (
            size_t dimension = 0;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                file,
                "%zu%s",
                sample_counts[dimension],
                dimension + 1 < dimension_count
                    ? ","
                    : ""
            );
        }

        fprintf(
            file,
            "];\n"
        );

        /*
         * Dimension lower limits.
         */
        fprintf(
            file,
            "const fuzzyLowers=["
        );

        for (
            size_t dimension = 0;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                file,
                "%.9g%s",
                sweep->dimensions[dimension].lower,
                dimension + 1 < dimension_count
                    ? ","
                    : ""
            );
        }

        fprintf(
            file,
            "];\n"
        );

        /*
         * Dimension steps.
         */
        fprintf(
            file,
            "const fuzzySteps=["
        );

        for (
            size_t dimension = 0;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                file,
                "%.9g%s",
                sweep->dimensions[dimension].step,
                dimension + 1 < dimension_count
                    ? ","
                    : ""
            );
        }

        fprintf(
            file,
            "];\n"
        );

        /*
         * Dimension names for cell tooltips.
         */
        fprintf(
            file,
            "const fuzzyNames=["
        );

        for (
            size_t dimension = 0;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                file,
                "\""
            );

            const char *name =
                sweep->dimensions[dimension].name != NULL
                    ? sweep->dimensions[dimension].name
                    : "Input";

            while (*name != '\0') {
                if (
                    *name == '\\' ||
                    *name == '"'
                ) {
                    fputc('\\', file);
                }

                if (
                    *name != '\n' &&
                    *name != '\r'
                ) {
                    fputc(*name, file);
                }

                name++;
            }

            fprintf(
                file,
                "\"%s",
                dimension + 1 < dimension_count
                    ? ","
                    : ""
            );
        }

        fprintf(
            file,
            "];\n"
        );

        /*
         * Embed only numerical COG data.
         *
         * No SVG element is created for each data point.
         */
        fprintf(
            file,
            "const fuzzyCogValues=[\n"
        );

        for (
            size_t point = 0;
            point < total_points;
            point++
        ) {
            fprintf(
                file,
                "%.7g%s",
                parsed_cog_values[point],
                point + 1 < total_points
                    ? ","
                    : ""
            );

            if (
                point % 16 == 15
            ) {
                fputc('\n', file);
            }
        }

        fprintf(
            file,
            "\n];\n"
        );

        fprintf(
            file,
            "const fuzzyMinCog=%.9g;\n"
            "const fuzzyMaxCog=%.9g;\n"
            "const fuzzyCogRange="
            "Math.max(fuzzyMaxCog-fuzzyMinCog,1e-12);\n"
            "const fuzzyDimensionCount=%zu;\n"
            "const fuzzyXCount=%zu;\n"
            "const fuzzyYCount=%zu;\n"
            "const fuzzyCellCount=%zu;\n",
            minimum_cog,
            maximum_cog,
            dimension_count,
            x_count,
            y_count,
            cell_count
        );

        /*
         * Convert normalized COG into the heatmap colour.
         */
        fprintf(
            file,
            "function fuzzyColour(cog){\n"
            "  let ratio=(cog-fuzzyMinCog)/fuzzyCogRange;\n"
            "  ratio=Math.max(0,Math.min(1,ratio));\n"
            "  let r,g,b;\n"
            "  if(ratio<0.33){\n"
            "    const local=ratio/0.33;\n"
            "    r=37;\n"
            "    g=Math.round(99+local*132);\n"
            "    b=235;\n"
            "  }else if(ratio<0.66){\n"
            "    const local=(ratio-0.33)/0.33;\n"
            "    r=Math.round(37+local*213);\n"
            "    g=Math.round(231+local*13);\n"
            "    b=Math.round(235-local*194);\n"
            "  }else{\n"
            "    const local=(ratio-0.66)/0.34;\n"
            "    r=Math.round(250-local*11);\n"
            "    g=Math.round(244-local*176);\n"
            "    b=Math.round(41-local*27);\n"
            "  }\n"
            "  return 'rgb('+r+','+g+','+b+')';\n"
            "}\n"
        );

        /*
         * Convert an N-dimensional index into the flattened
         * point index used by the C sweep odometer.
         */
        fprintf(
            file,
            "function fuzzyPointIndex(indices){\n"
            "  let point=indices[0];\n"
            "  for(let d=1;d<fuzzyDimensionCount;d++){\n"
            "    point=point*fuzzySampleCounts[d]+indices[d];\n"
            "  }\n"
            "  return point;\n"
            "}\n"
        );

            /*
         * Interpolate continuously across dimensions 2..N-1.
         *
         * Dimensions 0 and 1 remain the heatmap X/Y indices.
         * Every slider dimension may contain a fractional
         * sample position.
         *
         * For three slider dimensions, this combines the
         * eight surrounding sweep points using trilinear
         * interpolation.
         */
        fprintf(
            file,
            "function fuzzyInterpolatedCog(x,y,positions){\n"
            "  const sliderDimensions="
            "fuzzyDimensionCount-2;\n"
            "\n"
            "  if(sliderDimensions<=0){\n"
            "    return fuzzyCogValues["
            "fuzzyPointIndex([x,y])];\n"
            "  }\n"
            "\n"
            "  const lowerIndices=[];\n"
            "  const upperIndices=[];\n"
            "  const fractions=[];\n"
            "\n"
            "  for(let local=0;"
            "local<sliderDimensions;"
            "local++){\n"
            "    const dimension=local+2;\n"
            "    const maximum="
            "fuzzySampleCounts[dimension]-1;\n"
            "    const position=Math.max("
            "0,Math.min(maximum,positions[local]));\n"
            "\n"
            "    const lower=Math.floor(position);\n"
            "    const upper=Math.min(lower+1,maximum);\n"
            "\n"
            "    lowerIndices.push(lower);\n"
            "    upperIndices.push(upper);\n"
            "    fractions.push(position-lower);\n"
            "  }\n"
            "\n"
            "  const cornerCount="
            "Math.pow(2,sliderDimensions);\n"
            "  let result=0;\n"
            "\n"
            "  for(let corner=0;"
            "corner<cornerCount;"
            "corner++){\n"
            "    const indices="
            "new Array(fuzzyDimensionCount).fill(0);\n"
            "\n"
            "    indices[0]=x;\n"
            "    indices[1]=y;\n"
            "\n"
            "    let weight=1;\n"
            "\n"
            "    for(let local=0;"
            "local<sliderDimensions;"
            "local++){\n"
            "      const useUpper="
            "((corner>>local)&1)!==0;\n"
            "      const fraction=fractions[local];\n"
            "      const dimension=local+2;\n"
            "\n"
            "      if(useUpper){\n"
            "        indices[dimension]="
            "upperIndices[local];\n"
            "        weight*=fraction;\n"
            "      }else{\n"
            "        indices[dimension]="
            "lowerIndices[local];\n"
            "        weight*=1-fraction;\n"
            "      }\n"
            "    }\n"
            "\n"
            "    result+=weight*fuzzyCogValues["
            "fuzzyPointIndex(indices)];\n"
            "  }\n"
            "\n"
            "  return result;\n"
            "}\n"
        );


        /*
         * Repaint one reusable heatmap grid.
         */
        /*
         * Repaint one reusable heatmap using continuous
         * interpolation between precomputed sweep samples.
         */
        fprintf(
            file,
            "function fuzzyRenderHeatmap(){\n"
            "  const positions=[];\n"
            "  const physicalValues=[];\n"
            "\n"
            "  for(let d=2;"
            "d<fuzzyDimensionCount;"
            "d++){\n"
            "    const slider=document.getElementById("
            "'slice-slider-'+d);\n"
            "\n"
            "    let position=0;\n"
            "\n"
            "    if(slider){\n"
            "      position=Number(slider.value);\n"
            "    }\n"
            "\n"
            "    const maximum="
            "fuzzySampleCounts[d]-1;\n"
            "\n"
            "    position=Math.max("
            "0,Math.min(maximum,position));\n"
            "\n"
            "    const value="
            "fuzzyLowers[d]+"
            "position*fuzzySteps[d];\n"
            "\n"
            "    positions.push(position);\n"
            "    physicalValues.push(value);\n"
            "\n"
            "    const label=document.getElementById("
            "'slice-value-'+d);\n"
            "\n"
            "    if(label){\n"
            "      label.textContent=value.toFixed(4);\n"
            "    }\n"
            "  }\n"
            "\n"
            "  for(let x=0;"
            "x<fuzzyXCount;"
            "x++){\n"
            "    for(let y=0;"
            "y<fuzzyYCount;"
            "y++){\n"
            "      const cell="
            "x*fuzzyYCount+y;\n"
            "\n"
            "      const cog=fuzzyInterpolatedCog("
            "x,y,positions);\n"
            "\n"
            "      const rect=document.getElementById("
            "'fuzzy-cell-'+cell);\n"
            "\n"
            "      const title=document.getElementById("
            "'fuzzy-title-'+cell);\n"
            "\n"
            "      if(rect){\n"
            "        rect.setAttribute("
            "'fill',fuzzyColour(cog));\n"
            "      }\n"
            "\n"
            "      if(title){\n"
            "        let text="
            "fuzzyNames[0]+' = '+"
            "(fuzzyLowers[0]+"
            "x*fuzzySteps[0]).toFixed(4)+"
            "', '+"
            "fuzzyNames[1]+' = '+"
            "(fuzzyLowers[1]+"
            "y*fuzzySteps[1]).toFixed(4);\n"
            "\n"
            "        for(let local=0;"
            "local<physicalValues.length;"
            "local++){\n"
            "          const d=local+2;\n"
            "\n"
            "          text+=', '+"
            "fuzzyNames[d]+' = '+"
            "physicalValues[local].toFixed(4);\n"
            "        }\n"
            "\n"
            "        title.textContent="
            "text+', COG = '+cog.toFixed(5);\n"
            "      }\n"
            "    }\n"
            "  }\n"
            "}\n"
        );

        /*
         * Attach the slider event listeners.
         */
        for (
            size_t dimension = 2;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                file,
                "document.getElementById("
                "'slice-slider-%zu'"
                ").addEventListener("
                "'input',fuzzyRenderHeatmap"
                ");\n",
                dimension
            );
        }

        fprintf(
            file,
            "fuzzyRenderHeatmap();\n"
            "]]></script>\n"
        );
    }

    /*
     * Close the SVG document.
     */
    fprintf(
        file,
        "</svg>\n"
    );

    if (ferror(file)) {
        FUZZY_ERROR(
            "Failed while writing %s.\n",
            svg_filename
        );

        fclose(file);

        return false;
    }

    if (fclose(file) != 0) {
        FUZZY_ERROR(
            "Failed to finish writing %s.\n",
            svg_filename
        );

        return false;
    }

    FUZZY_PRINTF(
        "COG sweep SVG written to %s\n",
        svg_filename
    );

    return true;
}

bool fuzzy_cog_sweep(
    const fuzzy_cog_sweep_t *sweep
)
{
    size_t dimension_count;
    size_t total_points;
    size_t sweep_input_count;

    size_t *sample_counts;
    size_t *indices;

    float *inputs;
    float *sweep_inputs;
    float *sweep_cog_values;

    FILE *csv_file;

    char csv_filename[256];

    int written;

    bool success;

    if (
        sweep == NULL ||
        sweep->filename == NULL ||
        sweep->dimensions == NULL ||
        sweep->dimension_count == 0 ||
        sweep->evaluate == NULL ||
        sweep->cog_step <= 0.0f
    ) {
        return false;
    }

    dimension_count =
        sweep->dimension_count;

    sample_counts =
        calloc(
            dimension_count,
            sizeof(*sample_counts)
        );

    indices =
        calloc(
            dimension_count,
            sizeof(*indices)
        );

    inputs =
        calloc(
            dimension_count,
            sizeof(*inputs)
        );

    if (
        sample_counts == NULL ||
        indices == NULL ||
        inputs == NULL
    ) {
        FUZZY_ERROR(
            "Failed to allocate COG sweep dimensions.\n"
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    total_points =
        1;

    /*
     * Validate every dimension and determine the total
     * number of points.
     */
    for (
        size_t dimension = 0;
        dimension < dimension_count;
        dimension++
    ) {
        const fuzzy_sweep_dimension_t *current =
            &sweep->dimensions[dimension];

        if (
            current->lower > current->upper ||
            current->step <= 0.0f
        ) {
            FUZZY_ERROR(
                "Invalid sweep dimension %zu.\n",
                dimension
            );

            free(sample_counts);
            free(indices);
            free(inputs);

            return false;
        }

        sample_counts[dimension] =
            (size_t)ceilf(
                (
                    current->upper -
                    current->lower
                ) /
                current->step
            ) + 1u;

        if (
            sample_counts[dimension] == 0 ||
            total_points >
                SIZE_MAX /
                sample_counts[dimension]
        ) {
            FUZZY_ERROR(
                "COG sweep contains too many points.\n"
            );

            free(sample_counts);
            free(indices);
            free(inputs);

            return false;
        }

        total_points *=
            sample_counts[dimension];
    }

    /*
     * The flat input array contains every input coordinate
     * for every generated point.
     */
    if (
        total_points >
            SIZE_MAX /
            dimension_count
    ) {
        FUZZY_ERROR(
            "COG sweep input count overflow.\n"
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    sweep_input_count =
        total_points *
        dimension_count;

    /*
     * Prevent byte-size overflow before allocating.
     */
    if (
        sweep_input_count >
            SIZE_MAX /
            sizeof(*sweep_inputs) ||
        total_points >
            SIZE_MAX /
            sizeof(*sweep_cog_values)
    ) {
        FUZZY_ERROR(
            "COG sweep allocation is too large.\n"
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    sweep_inputs =
        malloc(
            sweep_input_count *
            sizeof(*sweep_inputs)
        );

    sweep_cog_values =
        malloc(
            total_points *
            sizeof(*sweep_cog_values)
        );

    if (
        sweep_inputs == NULL ||
        sweep_cog_values == NULL
    ) {
        FUZZY_ERROR(
            "Failed to allocate COG sweep results.\n"
        );

        free(sweep_inputs);
        free(sweep_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    written =
        snprintf(
            csv_filename,
            sizeof(csv_filename),
            "%s.csv",
            sweep->filename
        );

    if (
        written < 0 ||
        (size_t)written >= sizeof(csv_filename)
    ) {
        FUZZY_ERROR(
            "COG sweep CSV filename is too long.\n"
        );

        free(sweep_inputs);
        free(sweep_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    csv_file =
        fopen(
            csv_filename,
            "w"
        );

    if (csv_file == NULL) {
        FUZZY_ERROR(
            "Failed to open %s.\n",
            csv_filename
        );

        free(sweep_inputs);
        free(sweep_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    /*
     * CSV heading.
     */
    for (
        size_t dimension = 0;
        dimension < dimension_count;
        dimension++
    ) {
        const char *name =
            sweep->dimensions[dimension].name;

        fprintf(
            csv_file,
            "%s,",
            name != NULL
                ? name
                : "Input"
        );
    }

    fprintf(
        csv_file,
        "COG\n"
    );

    /*
     * Generate the sweep once.
     *
     * Every calculated input and COG value is:
     *
     * 1. Stored directly in memory for the SVG.
     * 2. Written directly to the CSV.
     *
     * The CSV is never reopened or parsed.
     */
    for (
        size_t point = 0;
        point < total_points;
        point++
    ) {
        for (
            size_t dimension = 0;
            dimension < dimension_count;
            dimension++
        ) {
            const fuzzy_sweep_dimension_t *current =
                &sweep->dimensions[dimension];

            float input =
                current->lower +
                (float)indices[dimension] *
                current->step;

            if (input > current->upper) {
                input =
                    current->upper;
            }

            inputs[dimension] =
                input;

            sweep_inputs[
                point *
                dimension_count +
                dimension
            ] = input;

            fprintf(
                csv_file,
                "%.9g,",
                input
            );
        }

        sweep_cog_values[point] =
            sweep->evaluate(
                inputs,
                dimension_count,
                sweep->cog_step
            );

        fprintf(
            csv_file,
            "%.9g\n",
            sweep_cog_values[point]
        );

        /*
         * Increment the N-dimensional odometer.
         *
         * The final dimension changes fastest.
         */
        for (
            size_t dimension = dimension_count;
            dimension > 0;
            dimension--
        ) {
            size_t index =
                dimension - 1u;

            indices[index]++;

            if (
                indices[index] <
                sample_counts[index]
            ) {
                break;
            }

            indices[index] =
                0;
        }
    }

    /*
     * Ensure the CSV was written successfully.
     */
    if (ferror(csv_file)) {
        FUZZY_ERROR(
            "Failed while writing %s.\n",
            csv_filename
        );

        fclose(csv_file);

        free(sweep_inputs);
        free(sweep_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    if (fclose(csv_file) != 0) {
        FUZZY_ERROR(
            "Failed to finish writing %s.\n",
            csv_filename
        );

        free(sweep_inputs);
        free(sweep_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    /*
     * Generate the SVG directly from the same values that
     * were written to the CSV.
     *
     * No CSV parsing and no controller reevaluation.
     */
    success =
        fuzzy_sweep_write_svg(
            sweep,
            sample_counts,
            total_points,
            sweep_inputs,
            sweep_cog_values
        );

    if (!success) {
        FUZZY_ERROR(
            "Failed to generate COG sweep SVG.\n"
        );

        free(sweep_inputs);
        free(sweep_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    free(sweep_inputs);
    free(sweep_cog_values);

    free(sample_counts);
    free(indices);
    free(inputs);

    FUZZY_PRINTF(
        "COG sweep complete "
        "(%zu dimensions, %zu points)\n",
        dimension_count,
        total_points
    );

    return true;
}

#endif /* FUZZY_8051 */
#endif /* FUZZY_IMPLEMENTATION_ONCE */
#endif /* FUZZY_IMPLEMENTATION */