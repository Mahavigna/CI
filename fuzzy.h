#ifndef FUZZY_H
#define FUZZY_H

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define LEVEL_HI 1.0f
#define LEVEL_LO 0.0f

#ifndef FUZZY_PRINTF
#define FUZZY_PRINTF(...) printf(__VA_ARGS__)
#endif

#ifndef FUZZY_ERROR
#define FUZZY_ERROR(...) fprintf(stderr, __VA_ARGS__)
#endif

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
    char *name;
    char *color;
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


bool fuzzy_plot_many(
    char *filename,
    char *title,
    float lower,
    float upper,
    float step,
    const fuzzy_plot_series_t series[],
    size_t series_count
);

#define FUZZY_PLOT_FUNCTION(function_arg, color_arg)        \
    (fuzzy_plot_series_t) {                                 \
        .name = #function_arg,                              \
        .color = (color_arg),                               \
        .function = (function_arg)                          \
    }

#define FUZZY_PLOT_FUNCTION_NAMED(                          \
    name_arg, color_arg, function_arg                       \
)                                                           \
    (fuzzy_plot_series_t) {                                 \
        .name = (name_arg),                                 \
        .color = (color_arg),                               \
        .function = (function_arg)                          \
    }

#define FUZZY_PLOT(                                         \
    filename_arg, title_arg, lower_arg, upper_arg,           \
    step_arg, ...                                           \
)                                                           \
    fuzzy_plot_many(                                        \
        (filename_arg),                                     \
        (title_arg),                                        \
        (lower_arg),                                        \
        (upper_arg),                                        \
        (step_arg),                                         \
        (const fuzzy_plot_series_t[]) { __VA_ARGS__ },      \
        sizeof((const fuzzy_plot_series_t[]) {               \
            __VA_ARGS__                                     \
        }) / sizeof(fuzzy_plot_series_t)                    \
    )

#define FUZZY_SWEEP_DIMENSION(                          \
    name_arg, lower_arg, upper_arg, step_arg            \
)                                                       \
    (fuzzy_sweep_dimension_t) {                         \
        .name = (name_arg),                             \
        .lower = (lower_arg),                           \
        .upper = (upper_arg),                           \
        .step = (step_arg)                              \
    }

#define FUZZY_COG_SWEEP(                                \
    filename_arg,                                      \
    title_arg,                                         \
    evaluator_arg,                                     \
    cog_step_arg,                                      \
    ...                                                \
)                                                       \
    fuzzy_cog_sweep(                                   \
        &(const fuzzy_cog_sweep_t) {                   \
            .filename = (filename_arg),                \
            .title = (title_arg),                      \
            .dimensions =                              \
                (const fuzzy_sweep_dimension_t[]) {    \
                    __VA_ARGS__                        \
                },                                     \
            .dimension_count =                         \
                sizeof(                                \
                    (const fuzzy_sweep_dimension_t[]) {\
                        __VA_ARGS__                    \
                    }                                  \
                ) / sizeof(fuzzy_sweep_dimension_t),   \
            .cog_step = (cog_step_arg),                \
            .evaluate = (evaluator_arg)                \
        }                                              \
    )

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
    char *name,
    char *color,
    fuzzy_output_function_t function
);

void fuzzy_plot_end(
    fuzzy_plot_t *plot
);

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

bool fuzzy_cog_sweep(const fuzzy_cog_sweep_t *sweep);

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

bool fuzzy_rules_plot_cog(
    const fuzzy_rules_t *rules,
    const char *filename,
    const char *title,
    float cog,
    float lower,
    float upper,
    float step
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
static inline float fuzzy_apply_hedge(float membership, float hedge)
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
inline float fuzzy_or(int count, ...)
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
inline float fuzzy_and(int count, ...)
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
inline float fuzzy_ramp(
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
inline float fuzzy_function(
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
    * Triangular membership function.
    *
    * Arguments:
    * double left
    * double peak
    * double right
    */
    else if (strcmp(shape, "triangle") == 0) {
        float left =
            (float)va_arg(args, double);

        float peak =
            (float)va_arg(args, double);

        float right =
            (float)va_arg(args, double);

        if (
            left >= peak ||
            peak >= right
        ) {
            result = LEVEL_LO;
        }
        else if (
            value <= left ||
            value >= right
        ) {
            result = LEVEL_LO;
        }
        else if (value == peak) {
            result = LEVEL_HI;
        }
        else if (value < peak) {
            result =
                (value - left) /
                (peak - left);
        }
        else {
            result =
                (right - value) /
                (right - peak);
        }
    }

    /*
    * Trapezoidal membership function.
    *
    * Arguments:
    * double left
    * double top_left
    * double top_right
    * double right
    */
    else if (strcmp(shape, "trapezoid") == 0) {
        float left =
            (float)va_arg(args, double);

        float top_left =
            (float)va_arg(args, double);

        float top_right =
            (float)va_arg(args, double);

        float right =
            (float)va_arg(args, double);

        if (
            left >= top_left ||
            top_left > top_right ||
            top_right >= right
        ) {
            result = LEVEL_LO;
        }
        else if (
            value <= left ||
            value >= right
        ) {
            result = LEVEL_LO;
        }
        else if (
            value >= top_left &&
            value <= top_right
        ) {
            result = LEVEL_HI;
        }
        else if (value < top_left) {
            result =
                (value - left) /
                (top_left - left);
        }
        else {
            result =
                (right - value) /
                (right - top_right);
        }
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
                    (width/2.0f)
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

        FUZZY_PRINTF(
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

        // FUZZY_PRINTF(
        //     "Value: %5.1f, Aggregated height: %.5f\n",
        //     value,
        //     aggregated_height
        // );

        weighted_sum += value * aggregated_height;
        height_sum += aggregated_height;
    }

    if (height_sum == 0.0f) {
        return 0.0f;
    }

    return weighted_sum / height_sum;
}

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
    char *name,
    char *color,
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
    char *filename,
    char *title,
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
                .name = (char *)demos[i].name,
                .color = (char *)demos[i].color,
                .function = demos[i].function
            }
        };

        if (!fuzzy_plot_many(
            (char *)demos[i].filename,
            (char *)demos[i].title,
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
 * Parse the generated sweep CSV and write its contents
 * into the supplied flat arrays.
 *
 * This is private because CSV parsing is an internal part
 * of sweep generation, not part of the public API.
 */
static bool fuzzy_sweep_parse_csv(
    const char *filename,
    size_t expected_dimension_count,
    size_t expected_point_count,
    float inputs[],
    float cog_values[]
)
{
    if (
        filename == NULL ||
        expected_dimension_count == 0 ||
        expected_point_count == 0 ||
        inputs == NULL ||
        cog_values == NULL
    ) {
        return false;
    }

    FILE *file = fopen(
        filename,
        "r"
    );

    if (file == NULL) {
        FUZZY_ERROR(
            "Failed to open sweep CSV: %s\n",
            filename
        );

        return false;
    }

    char line[4096];

    /*
     * Read and validate the heading.
     */
    if (
        fgets(
            line,
            sizeof(line),
            file
        ) == NULL
    ) {
        FUZZY_ERROR(
            "Sweep CSV is empty: %s\n",
            filename
        );

        fclose(file);

        return false;
    }

    size_t heading_columns = 1;

    for (
        const char *character = line;
        *character != '\0';
        character++
    ) {
        if (*character == ',') {
            heading_columns++;
        }
    }

    if (
        heading_columns !=
        expected_dimension_count + 1
    ) {
        FUZZY_ERROR(
            "Sweep CSV has %zu columns; expected %zu.\n",
            heading_columns,
            expected_dimension_count + 1
        );

        fclose(file);

        return false;
    }

    size_t point = 0;
    size_t line_number = 1;

    while (
        fgets(
            line,
            sizeof(line),
            file
        ) != NULL
    ) {
        line_number++;

        size_t length =
            strlen(line);

        while (
            length > 0 &&
            (
                line[length - 1] == '\n' ||
                line[length - 1] == '\r'
            )
        ) {
            line[length - 1] = '\0';
            length--;
        }

        if (line[0] == '\0') {
            continue;
        }

        if (point >= expected_point_count) {
            FUZZY_ERROR(
                "Sweep CSV contains more than %zu points.\n",
                expected_point_count
            );

            fclose(file);

            return false;
        }

        char *cursor = line;

        for (
            size_t dimension = 0;
            dimension < expected_dimension_count;
            dimension++
        ) {
            char *end = NULL;

            float value =
                strtof(cursor, &end);

            if (
                end == cursor ||
                *end != ','
            ) {
                FUZZY_ERROR(
                    "Invalid input value on CSV line %zu, "
                    "dimension %zu.\n",
                    line_number,
                    dimension
                );

                fclose(file);

                return false;
            }

            inputs[
                point *
                expected_dimension_count +
                dimension
            ] = value;

            cursor =
                end + 1;
        }

        char *end = NULL;

        float cog =
            strtof(cursor, &end);

        if (end == cursor) {
            FUZZY_ERROR(
                "Invalid COG value on CSV line %zu.\n",
                line_number
            );

            fclose(file);

            return false;
        }

        while (
            *end == ' ' ||
            *end == '\t'
        ) {
            end++;
        }

        if (*end != '\0') {
            FUZZY_ERROR(
                "Unexpected data after COG on CSV line %zu.\n",
                line_number
            );

            fclose(file);

            return false;
        }

        cog_values[point] =
            cog;

        point++;
    }

    if (ferror(file)) {
        FUZZY_ERROR(
            "Failed while reading sweep CSV: %s\n",
            filename
        );

        fclose(file);

        return false;
    }

    if (fclose(file) != 0) {
        FUZZY_ERROR(
            "Failed to close sweep CSV: %s\n",
            filename
        );

        return false;
    }

    if (point != expected_point_count) {
        FUZZY_ERROR(
            "Sweep CSV contains %zu points; expected %zu.\n",
            point,
            expected_point_count
        );

        return false;
    }

    return true;
}

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
                "x=\"%d\" y=\"650\" "
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
                    "step=\"1\" value=\"0\" />"
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
         * Repaint one reusable heatmap grid.
         */
        fprintf(
            file,
            "function fuzzyRenderHeatmap(){\n"
            "  const indices=new Array(fuzzyDimensionCount).fill(0);\n"
            "\n"
            "  for(let d=2;d<fuzzyDimensionCount;d++){\n"
            "    const slider=document.getElementById("
            "'slice-slider-'+d);\n"
            "    if(slider){\n"
            "      indices[d]=Number(slider.value);\n"
            "      const value=fuzzyLowers[d]+"
            "indices[d]*fuzzySteps[d];\n"
            "      const label=document.getElementById("
            "'slice-value-'+d);\n"
            "      if(label){label.textContent=value.toFixed(4);}\n"
            "    }\n"
            "  }\n"
            "\n"
            "  for(let x=0;x<fuzzyXCount;x++){\n"
            "    indices[0]=x;\n"
            "\n"
            "    for(let y=0;y<fuzzyYCount;y++){\n"
            "      indices[1]=y;\n"
            "\n"
            "      const cell=x*fuzzyYCount+y;\n"
            "      const point=fuzzyPointIndex(indices);\n"
            "      const cog=fuzzyCogValues[point];\n"
            "      const rect=document.getElementById("
            "'fuzzy-cell-'+cell);\n"
            "      const title=document.getElementById("
            "'fuzzy-title-'+cell);\n"
            "\n"
            "      if(rect){rect.setAttribute("
            "'fill',fuzzyColour(cog));}\n"
            "\n"
            "      if(title){\n"
            "        let text="
            "fuzzyNames[0]+' = '+"
            "(fuzzyLowers[0]+x*fuzzySteps[0]).toFixed(4)+"
            "', '+fuzzyNames[1]+' = '+"
            "(fuzzyLowers[1]+y*fuzzySteps[1]).toFixed(4);\n"
            "\n"
            "        for(let d=2;d<fuzzyDimensionCount;d++){\n"
            "          text+=', '+fuzzyNames[d]+' = '+"
            "(fuzzyLowers[d]+indices[d]*fuzzySteps[d])"
            ".toFixed(4);\n"
            "        }\n"
            "\n"
            "        title.textContent=text+', COG = '+"
            "cog.toFixed(5);\n"
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

bool fuzzy_cog_sweep(const fuzzy_cog_sweep_t *sweep)
{
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

    size_t dimension_count =
        sweep->dimension_count;

    size_t *sample_counts = calloc(
        dimension_count,
        sizeof(*sample_counts)
    );

    size_t *indices = calloc(
        dimension_count,
        sizeof(*indices)
    );

    float *inputs = calloc(
        dimension_count,
        sizeof(*inputs)
    );

    if (
        sample_counts == NULL ||
        indices == NULL ||
        inputs == NULL
    ) {
        free(sample_counts);
        free(indices);
        free(inputs);

        FUZZY_ERROR(
            "Failed to allocate COG sweep data.\n"
        );

        return false;
    }

    size_t total_points = 1;

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
            ) + 1;

        if (
            sample_counts[dimension] != 0 &&
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

    char output_filename[256];

    int written = snprintf(
        output_filename,
        sizeof(output_filename),
        "%s.csv",
        sweep->filename
    );

    if (
        written < 0 ||
        (size_t)written >= sizeof(output_filename)
    ) {
        FUZZY_ERROR(
            "COG sweep filename is too long.\n"
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    FILE *file = fopen(
        output_filename,
        "w"
    );

    if (file == NULL) {
        FUZZY_ERROR(
            "Failed to open %s.\n",
            output_filename
        );

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
            file,
            "%s,",
            name != NULL
                ? name
                : "Input"
        );
    }

    fprintf(
        file,
        "COG\n"
    );

    /*
     * N-dimensional odometer loop.
     *
     * The final dimension changes fastest.
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

            fprintf(
                file,
                "%.9g,",
                input
            );
        }

        float cog = sweep->evaluate(
            inputs,
            dimension_count,
            sweep->cog_step
        );

        fprintf(
            file,
            "%.9g\n",
            cog
        );

        /*
         * Increment the last dimension.
         * Carry into preceding dimensions when required.
         */
        for (
            size_t dimension = dimension_count;
            dimension > 0;
            dimension--
        ) {
            size_t index =
                dimension - 1;

            indices[index]++;

            if (
                indices[index] <
                sample_counts[index]
            ) {
                break;
            }

            indices[index] = 0;
        }
    }

    /*
     * Close the CSV before reopening it for parsing.
     */
    if (fclose(file) != 0) {
        FUZZY_ERROR(
            "Failed to finish writing %s.\n",
            output_filename
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    /*
     * Prevent allocation-size overflow.
     */
    if (
        dimension_count != 0 &&
        total_points >
            SIZE_MAX /
            dimension_count
    ) {
        FUZZY_ERROR(
            "Parsed sweep input data is too large.\n"
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    size_t parsed_input_count =
        total_points *
        dimension_count;

    if (
        parsed_input_count >
            SIZE_MAX /
            sizeof(float) ||
        total_points >
            SIZE_MAX /
            sizeof(float)
    ) {
        FUZZY_ERROR(
            "Parsed sweep allocation is too large.\n"
        );

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    float *parsed_inputs = malloc(
        parsed_input_count *
        sizeof(*parsed_inputs)
    );

    float *parsed_cog_values = malloc(
        total_points *
        sizeof(*parsed_cog_values)
    );

    if (
        parsed_inputs == NULL ||
        parsed_cog_values == NULL
    ) {
        FUZZY_ERROR(
            "Failed to allocate parsed sweep data.\n"
        );

        free(parsed_inputs);
        free(parsed_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    /*
     * Parse the CSV generated above.
     */
    if (!fuzzy_sweep_parse_csv(
        output_filename,
        dimension_count,
        total_points,
        parsed_inputs,
        parsed_cog_values
    )) {
        FUZZY_ERROR(
            "Failed to parse generated sweep CSV.\n"
        );

        free(parsed_inputs);
        free(parsed_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    /*
     * Generate the SVG from the parsed sweep data.
     */
    if (!fuzzy_sweep_write_svg(
        sweep,
        sample_counts,
        total_points,
        parsed_inputs,
        parsed_cog_values
    )) {
        FUZZY_ERROR(
            "Failed to generate COG sweep SVG.\n"
        );

        free(parsed_inputs);
        free(parsed_cog_values);

        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    free(parsed_inputs);
    free(parsed_cog_values);

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

#endif /* FUZZY_IMPLEMENTATION_ONCE */
#endif /* FUZZY_IMPLEMENTATION */