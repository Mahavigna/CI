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

bool fuzzy_plot_begin(
    fuzzy_plot_t *plot,
    char *filename,
    char *title,
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
    char *filename,
    char *title,
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

    printf(
        "Membership plot written to %s\n",
        plot_filename
    );

    return true;
}

#endif /* FUZZY_IMPLEMENTATION_ONCE */
#endif /* FUZZY_IMPLEMENTATION */