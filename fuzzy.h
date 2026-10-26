#ifndef FUZZY_H
#define FUZZY_H

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEVEL_HI 1.0f
#define LEVEL_LO 0.0f

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
typedef struct Hedges {
    float none;
    float very;
    float extremely;
    float somewhat;
    float slightly;
} hedges_t;

typedef float (*fuzzy_output_function_t)(float);

typedef struct FuzzyRule {
    const char *name;
    float value;
    fuzzy_output_function_t output_function;
} fuzzy_rule_t;

typedef struct FuzzyRules {
    fuzzy_rule_t *rules;
    size_t count;
    size_t capacity;
} fuzzy_rules_t;

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

/* Public declarations */

float fuzzy_or(int count, ...);

float fuzzy_and(int count, ...);

float fuzzy_ramp(
    const char *name,
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    float hedge
);

float fuzzy_function(
    const char *shape,
    float value,
    float hedge,
    ...
);

void test_ramp(
    float (*function)(
        const char *,
        float,
        float,
        float,
        bool,
        float
    ),
    const char *name,
    float lower,
    float upper,
    bool ramp_up,
    float hedge,
    int run
);

fuzzy_rules_t fuzzy_rules_create(void);

bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
);

void fuzzy_rules_print(
    const fuzzy_rules_t *rules
);

float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
);

void fuzzy_rules_free(
    fuzzy_rules_t *rules
);

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
 * Apply a linguistic hedge using exponentiation.
 *
 * hedge = 1.0  -> unchanged
 * hedge > 1.0  -> concentration, such as "very"
 * hedge < 1.0  -> dilation, such as "somewhat"
 */
static float fuzzy_apply_hedge(float membership, float hedge)
{
    membership = fuzzy_clamp(membership);

    if (hedge <= 0.0f) {
        hedge = 1.0f;
    }

    return powf(membership, hedge);
}


/*
 * Fuzzy OR:
 * Returns the maximum of all supplied membership values.
 *
 * Example:
 *
 * fuzzy_or(3, value1, value2, value3);
 */
float fuzzy_or(int count, ...)
{
    if (count <= 0) {
        return LEVEL_LO;
    }

    va_list args;
    va_start(args, count);

    /*
     * Values passed through ... are promoted from float
     * to double.
     */
    float result = (float)va_arg(args, double);

    for (int i = 1; i < count; i++) {
        float next = (float)va_arg(args, double);

        result = (result > next)
            ? result
            : next;
    }

    va_end(args);

    return result;
}


/*
 * Fuzzy AND:
 * Returns the minimum of all supplied membership values.
 *
 * Example:
 *
 * fuzzy_and(3, value1, value2, value3);
 */
float fuzzy_and(int count, ...)
{
    if (count <= 0) {
        return LEVEL_HI;
    }

    va_list args;
    va_start(args, count);

    float result = (float)va_arg(args, double);

    for (int i = 1; i < count; i++) {
        float next = (float)va_arg(args, double);

        result = (result < next)
            ? result
            : next;
    }

    va_end(args);

    return result;
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
    float hedge
)
{
    (void)name;

    if (lower_boundary >= upper_boundary) {
        return LEVEL_LO;
    }

    float result;

    if (value <= lower_boundary) {
        result = ramp_up
            ? LEVEL_LO
            : LEVEL_HI;
    }
    else if (value >= upper_boundary) {
        result = ramp_up
            ? LEVEL_HI
            : LEVEL_LO;
    }
    else {
        float normalized =
            (value - lower_boundary) /
            (upper_boundary - lower_boundary);

        result = ramp_up
            ? normalized
            : LEVEL_HI - normalized;
    }

    return fuzzy_apply_hedge(result, hedge);
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
float fuzzy_function(
    const char *shape,
    float value,
    float hedge,
    ...
)
{
    if (shape == NULL) {
        return LEVEL_LO;
    }

    va_list args;
    va_start(args, hedge);

    float result = LEVEL_LO;


    /*
     * Linear ramp
     *
     * Arguments:
     * double lower
     * double upper
     * int ramp_up
     */
    if (strcmp(shape, "ramp") == 0) {
        float lower = (float)va_arg(args, double);

        float upper = (float)va_arg(args, double);

        bool ramp_up = (bool)va_arg(args, int);

        va_end(args);

        /*
         * fuzzy_ramp() already applies the hedge.
         */
        return fuzzy_ramp(
            shape,
            lower,
            upper,
            value,
            ramp_up,
            hedge
        );
    }


    /*
     * S-shaped membership function.
     *
     * Arguments:
     * double lower
     * double upper
     */
    else if (strcmp(shape, "smf") == 0) {
        float lower =
            (float)va_arg(args, double);

        float upper = (float)va_arg(args, double);

        if (lower >= upper) {
            result = LEVEL_LO;
        }
        else if (value <= lower) {
            result = LEVEL_LO;
        }
        else if (value >= upper) {
            result = LEVEL_HI;
        }
        else {
            float middle =
                (lower + upper) / 2.0f;

            if (value <= middle) {
                float normalized =
                    (value - lower) /
                    (upper - lower);

                result =
                    2.0f *
                    normalized *
                    normalized;
            }
            else {
                float normalized =
                    (upper - value) /
                    (upper - lower);

                result =
                    LEVEL_HI -
                    2.0f *
                    normalized *
                    normalized;
            }
        }
    }


    /*
     * Z-shaped membership function.
     *
     * Arguments:
     * double lower
     * double upper
     */
    else if (strcmp(shape, "zmf") == 0) {
        float lower =
            (float)va_arg(args, double);

        float upper =
            (float)va_arg(args, double);

        if (lower >= upper) {
            result = LEVEL_LO;
        }
        else if (value <= lower) {
            result = LEVEL_HI;
        }
        else if (value >= upper) {
            result = LEVEL_LO;
        }
        else {
            float middle =
                (lower + upper) / 2.0f;

            if (value <= middle) {
                float normalized =
                    (value - lower) /
                    (upper - lower);

                result =
                    LEVEL_HI -
                    2.0f *
                    normalized *
                    normalized;
            }
            else {
                float normalized =
                    (upper - value) /
                    (upper - lower);

                result =
                    2.0f *
                    normalized *
                    normalized;
            }
        }
    }


    /*
     * Gaussian membership function.
     *
     * Arguments:
     * double mean
     * double standard_deviation
     */
    else if (strcmp(shape, "gauss") == 0) {
        float mean = (float)va_arg(args, double);

        float standard_deviation =
            (float)va_arg(args, double);

        if (standard_deviation <= 0.0f) {
            result = LEVEL_LO;
        }
        else {
            float difference =
                value - mean;

            float exponent =
                -(difference * difference) /
                (
                    2.0f *
                    standard_deviation *
                    standard_deviation
                );

            result = expf(exponent);
        }
    }


    /*
     * Generalized bell membership function.
     *
     * Arguments:
     * double width
     * double slope
     * double center
     */
    else if (strcmp(shape, "bell") == 0) {
        float width =
            (float)va_arg(args, double);

        float slope =
            (float)va_arg(args, double);

        float center =
            (float)va_arg(args, double);

        if (width == 0.0f) {
            result = LEVEL_LO;
        }
        else {
            float normalized =
                fabsf(
                    (value - center) /
                    width
                );

            result =
                LEVEL_HI /
                (
                    LEVEL_HI +
                    powf(
                        normalized,
                        2.0f * slope
                    )
                );
        }
    }


    /*
     * Sigmoid membership function.
     *
     * Arguments:
     * double slope
     * double center
     *
     * Positive slope produces a rising sigmoid.
     * Negative slope produces a falling sigmoid.
     */
    else if (strcmp(shape, "sigmoid") == 0) {
        float slope =
            (float)va_arg(args, double);

        float center =
            (float)va_arg(args, double);

        result =
            LEVEL_HI /
            (
                LEVEL_HI +
                expf(
                    -slope *
                    (value - center)
                )
            );
    }


    /*
     * Unknown shape name.
     */
    else {
        fprintf(
            stderr,
            "Unknown fuzzy shape: %s\n",
            shape
        );

        result = LEVEL_LO;
    }

    va_end(args);

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}


/*
 * Test a linear ramp over integer values. Deprecated, but useful for debugging.
 */
void test_ramp(
    float (*function)(
        const char *,
        float,
        float,
        float,
        bool,
        float
    ),
    const char *name,
    float lower,
    float upper,
    bool ramp_up,
    float hedge,
    int run
)
{
    for (int i = 0; i < run; i++) {
        float value = (float)i;

        float result = function(
            name,
            lower,
            upper,
            value,
            ramp_up,
            hedge
        );

        printf(
            "Value: %5.1f, Result: %.5f\n",
            value,
            result
        );
    }
}

fuzzy_rules_t fuzzy_rules_create(void)
{
    fuzzy_rules_t rules = {
        .rules = NULL,
        .count = 0,
        .capacity = 0
    };

    return rules;
}

static bool fuzzy_rules_resize(
    fuzzy_rules_t *rules,
    size_t new_capacity
)
{
    fuzzy_rule_t *new_rules = realloc(
        rules->rules,
        new_capacity * sizeof(*new_rules)
    );

    if (new_rules == NULL) {
        return false;
    }

    rules->rules = new_rules;
    rules->capacity = new_capacity;

    return true;
}

bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
)
{
    if (rules == NULL || output_function == NULL) {
        return false;
    }

    if (rules->count == rules->capacity) {
        size_t new_capacity = rules->capacity == 0
            ? 4
            : rules->capacity * 2;

        if (!fuzzy_rules_resize(rules, new_capacity)) {
            return false;
        }
    }

    rules->rules[rules->count] = (fuzzy_rule_t) {
        .name = name,
        .value = fuzzy_clamp(value),
        .output_function = output_function
    };

    rules->count++;

    return true;
}

void fuzzy_rules_print(const fuzzy_rules_t *rules)
{
    if (rules == NULL) {
        return;
    }

    for (size_t i = 0; i < rules->count; i++) {
        printf(
            "Rule %zu -> %s: %.5f\n",
            i + 1,
            rules->rules[i].name != NULL
                ? rules->rules[i].name
                : "Unnamed",
            rules->rules[i].value
        );
    }
}

float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
)
{
    if (
        rules == NULL ||
        rules->count == 0 ||
        lower > upper ||
        step <= 0.0f
    ) {
        return 0.0f;
    }

    float weighted_sum = 0.0f;
    float height_sum = 0.0f;

    for (
        float value = lower;
        value <= upper;
        value += step
    ) {
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

        printf(
            "Value: %5.1f, Aggregated height: %.5f\n",
            value,
            aggregated_height
        );

        weighted_sum += value * aggregated_height;
        height_sum += aggregated_height;
    }

    if (height_sum == 0.0f) {
        return 0.0f;
    }

    return weighted_sum / height_sum;
}

void fuzzy_rules_free(fuzzy_rules_t *rules)
{
    if (rules == NULL) {
        return;
    }

    free(rules->rules);

    rules->rules = NULL;
    rules->count = 0;
    rules->capacity = 0;
}

#endif /* FUZZY_IMPLEMENTATION_ONCE */
#endif /* FUZZY_IMPLEMENTATION */