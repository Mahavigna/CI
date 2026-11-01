# 0 "greenhouse.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "greenhouse.c"

# 1 "fuzzy.h" 1



# 1 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 1 3 4
# 160 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4

# 160 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 229 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 344 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4
typedef int wchar_t;
# 440 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 451 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4
} max_align_t;
# 465 "/usr/lib/gcc/x86_64-linux-gnu/15/include/stddef.h" 3 4
  typedef __typeof__(nullptr) nullptr_t;
# 5 "fuzzy.h" 2
# 31 "fuzzy.h"

# 31 "fuzzy.h"
typedef long unsigned int size_t;
typedef _Bool bool;





typedef struct _IO_FILE FILE;

extern FILE *stderr;

extern int printf(const char *, ...);
extern int fprintf(FILE *, const char *, ...);
extern int snprintf(char *, size_t, const char *, ...);
extern int scanf(const char *, ...);

extern FILE *fopen(const char *, const char *);
extern int fclose(FILE *);
extern int ferror(FILE *);
extern int fputc(int, FILE *);
extern int fputs(const char *, FILE *);

extern void *malloc(size_t);
extern void *calloc(size_t, size_t);
extern void free(void *);

extern float powf(float, float);
extern float expf(float);
extern float fabsf(float);
extern float ceilf(float);




typedef float fuzzy_hedge_t;

typedef struct FuzzyHedges {
    fuzzy_hedge_t none;
    fuzzy_hedge_t very;
    fuzzy_hedge_t extremely;
    fuzzy_hedge_t somewhat;
    fuzzy_hedge_t slightly;
} hedges_t;


typedef struct FuzzyPoint {
    const float *coordinates;
    size_t dimension_count;
    float membership;
} fuzzy_point_t;

float fuzzy_interpolate_membership_array(const float *inputs, size_t dimension_count, const fuzzy_point_t *points, size_t point_count);
# 268 "fuzzy.h"
typedef float (*fuzzy_output_function_t)(float);

typedef enum FuzzyLogicMethod {
    FUZZY_LOGIC_STANDARD = 0,
    FUZZY_LOGIC_ALGEBRAIC,
    FUZZY_LOGIC_BOUNDED
} fuzzy_logic_method_t;

typedef enum FuzzyImplicationMethod {
    FUZZY_IMPLICATION_MIN = 0,
    FUZZY_IMPLICATION_PRODUCT
} fuzzy_implication_method_t;

typedef enum FuzzyAggregationMethod {
    FUZZY_AGGREGATION_MAX = 0,
    FUZZY_AGGREGATION_ALGEBRAIC,
    FUZZY_AGGREGATION_BOUNDED
} fuzzy_aggregation_method_t;




typedef enum FuzzyShape {
    FUZZY_SHAPE_RAMP = 0,
    FUZZY_SHAPE_TRIANGLE,
    FUZZY_SHAPE_TRAPEZOID,
    FUZZY_SHAPE_SMF,
    FUZZY_SHAPE_ZMF,
    FUZZY_SHAPE_GAUSSIAN,
    FUZZY_SHAPE_BELL,
    FUZZY_SHAPE_SIGMOID,
    FUZZY_SHAPE_PIMF,
    FUZZY_SHAPE_DSIGMOID,
    FUZZY_SHAPE_PSIGMOID,
    FUZZY_SHAPE_GAUSSIAN2,
    FUZZY_SHAPE_PIECEWISE
} fuzzy_shape_t;






typedef enum FuzzyDefuzzMethod {
    FUZZY_DEFUZZ_COG = 0,
    FUZZY_DEFUZZ_MOM,
    FUZZY_DEFUZZ_SOM,
    FUZZY_DEFUZZ_LOM
} fuzzy_defuzz_method_t;



typedef struct FuzzyRule {
    const char *name;
    float value;
    fuzzy_output_function_t output_function;
} fuzzy_rule_t;


typedef struct FuzzyRules {
    fuzzy_rule_t rules[32u];
    size_t count;
} fuzzy_rules_t;
# 364 "fuzzy.h"
float fuzzy_not(float membership);







float fuzzy_and_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
);

float fuzzy_or_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
);
# 427 "fuzzy.h"
float fuzzy_sugeno_weighted_average_array(
    size_t value_count,
    const float *values
);

float fuzzy_sugeno_weighted_sum_array(
    size_t value_count,
    const float *values
);
# 453 "fuzzy.h"
float fuzzy_ramp(
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    fuzzy_hedge_t hedge
);

float fuzzy_triangle(
    float a,
    float b,
    float c,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_trapezoid(
    float a,
    float b,
    float c,
    float d,
    float value,
    fuzzy_hedge_t hedge
);



float fuzzy_smf(
    float lower_boundary,
    float upper_boundary,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_zmf(
    float lower_boundary,
    float upper_boundary,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_pimf(
    float a,
    float b,
    float c,
    float d,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_gaussian(
    float mean,
    float standard_deviation,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_gaussian2(
    float mean_1,
    float standard_deviation_1,
    float mean_2,
    float standard_deviation_2,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_bell(
    float width,
    float slope,
    float center,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_sigmoid(
    float slope,
    float center,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_dsigmoid(
    float slope_1,
    float center_1,
    float slope_2,
    float center_2,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_psigmoid(
    float slope_1,
    float center_1,
    float slope_2,
    float center_2,
    float value,
    fuzzy_hedge_t hedge
);

float fuzzy_interpolate_membership_array(const float *inputs, size_t dimension_count, const fuzzy_point_t *points, size_t point_count);







float fuzzy_function_array(
    fuzzy_shape_t shape,
    float value,
    fuzzy_hedge_t hedge,
    size_t parameter_count,
    const float *parameters
);
# 610 "fuzzy.h"
bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
);

float fuzzy_rules_defuzzify_method(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t defuzz_method,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);
# 645 "fuzzy.h"
float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
);







float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
);







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


typedef float (*fuzzy_sweep_evaluator_t)(const float inputs[], size_t input_count, float cog_step);

typedef struct FuzzyCogSweep {
    const char *filename;
    const char *title;
    const char *value_name;
    const fuzzy_sweep_dimension_t *dimensions;
    size_t dimension_count;
    float cog_step;
    fuzzy_sweep_evaluator_t evaluate;
} fuzzy_cog_sweep_t;

typedef struct FuzzyInterpolationSweep {
    const char *filename;
    const char *title;
    const fuzzy_sweep_dimension_t *dimensions;
    size_t dimension_count;
    const fuzzy_point_t *points;
    size_t point_count;
} fuzzy_interpolation_sweep_t;
# 807 "fuzzy.h"
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

bool fuzzy_cog_sweep(const fuzzy_cog_sweep_t *sweep);

bool fuzzy_interpolation_sweep(const fuzzy_interpolation_sweep_t *sweep);

bool fuzzy_interpolation_slices(const fuzzy_interpolation_sweep_t *sweep);
# 874 "fuzzy.h"
static float fuzzy_clamp(float value)
{
    if (value < 0.0f) {
        return 0.0f;
    }

    if (value > 1.0f) {
        return 1.0f;
    }

    return value;
}




float fuzzy_not(
    float membership
)
{
    return 1.0f -
        fuzzy_clamp( membership
        );
}
# 907 "fuzzy.h"
static float fuzzy_apply_hedge(
    float membership,
    fuzzy_hedge_t hedge
)
{
    membership =
        fuzzy_clamp( membership
        );
# 937 "fuzzy.h"
    if (hedge <= 0.0f) {
        hedge =
            1.0f;
    }

    return powf(
        membership,
        hedge
    );


}
# 962 "fuzzy.h"
float fuzzy_and_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
)
{
    float result;
    float next;
    size_t index;

    if (
        args == ((void *)0) ||
        count == 0u
    ) {
        return 1.0f;
    }

    if (
        method != FUZZY_LOGIC_STANDARD &&
        method != FUZZY_LOGIC_ALGEBRAIC &&
        method != FUZZY_LOGIC_BOUNDED
    ) {
        return 0.0f;
    }

    result =
        fuzzy_clamp(
            args[0]
        );

    for (
        index = 1u;
        index < count;
        index++
    ) {
        next =
            fuzzy_clamp(
                args[index]
            );

        switch (method) {
            case FUZZY_LOGIC_STANDARD:
                if (next < result) {
                    result = next;
                }
                break;

            case FUZZY_LOGIC_ALGEBRAIC:
                result *=
                    next;
                break;

            case FUZZY_LOGIC_BOUNDED:
                result =
                    result +
                    next -
                    1.0f;

                if (result < 0.0f) {
                    result = 0.0f;
                }
                break;

            default:
                return 0.0f;
        }
    }

    return fuzzy_clamp(
        result
    );
}
# 1048 "fuzzy.h"
float fuzzy_or_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
)
{
    float result;
    float next;
    size_t index;

    if (
        args == ((void *)0) ||
        count == 0u
    ) {
        return 0.0f;
    }

    if (
        method != FUZZY_LOGIC_STANDARD &&
        method != FUZZY_LOGIC_ALGEBRAIC &&
        method != FUZZY_LOGIC_BOUNDED
    ) {
        return 0.0f;
    }

    result =
        fuzzy_clamp(
            args[0]
        );

    for (
        index = 1u;
        index < count;
        index++
    ) {
        next =
            fuzzy_clamp(
                args[index]
            );

        switch (method) {
            case FUZZY_LOGIC_STANDARD:
                if (next > result) {
                    result = next;
                }
                break;

            case FUZZY_LOGIC_ALGEBRAIC:
                result =
                    result +
                    next -
                    result * next;
                break;

            case FUZZY_LOGIC_BOUNDED:
                result +=
                    next;

                if (result > 1.0f) {
                    result = 1.0f;
                }
                break;

            default:
                return 0.0f;
        }
    }

    return fuzzy_clamp(
        result
    );
}
# 1130 "fuzzy.h"
float fuzzy_sugeno_weighted_average_array(
    size_t value_count,
    const float *values
)
{
    float weighted_sum;
    float firing_sum;
    float firing_strength;
    float consequent;

    size_t index;

    if (
        values == ((void *)0) ||
        value_count == 0u ||
        value_count % 2u != 0u
    ) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    firing_sum =
        0.0f;

    for (
        index = 0u;
        index < value_count;
        index += 2u
    ) {
        firing_strength =
            fuzzy_clamp(
                values[index]
            );

        consequent =
            values[index + 1u];


        weighted_sum +=
            firing_strength *
            consequent;

        firing_sum +=
            firing_strength;
    }

    if (firing_sum <= 0.0f) {
        return 0.0f;
    }

    return weighted_sum /
        firing_sum;
}
# 1194 "fuzzy.h"
float fuzzy_sugeno_weighted_sum_array(
    size_t value_count,
    const float *values
)
{
    float weighted_sum;
    float firing_strength;
    float consequent;

    size_t index;

    if (
        values == ((void *)0) ||
        value_count == 0u ||
        value_count % 2u != 0u
    ) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    for (
        index = 0u;
        index < value_count;
        index += 2u
    ) {
        firing_strength =
            fuzzy_clamp(
                values[index]
            );

        consequent =
            values[index + 1u];


        weighted_sum +=
            firing_strength *
            consequent;
    }

    return weighted_sum;
}





float fuzzy_ramp(
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    fuzzy_hedge_t hedge
)
{
    float result;
    float normalized;

    if (lower_boundary >= upper_boundary) {
        return 0.0f;
    }

    if (value <= lower_boundary) {
        result =
            ramp_up
                ? 0.0f
                : 1.0f;
    }
    else if (value >= upper_boundary) {
        result =
            ramp_up
                ? 1.0f
                : 0.0f;
    }
    else {
        normalized =
            (value - lower_boundary) /
            (upper_boundary - lower_boundary);

        result =
            ramp_up
                ? normalized
                : 1.0f - normalized;
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}



float fuzzy_interpolate_membership_array(const float *inputs, size_t dimension_count, const fuzzy_point_t *points, size_t point_count)
{
    size_t point;
    size_t dimension;
    float distance_squared;
    float difference;
    float weight;
    float weighted_membership = 0.0f;
    float weight_sum = 0.0f;

    if (inputs == ((void *)0) || points == ((void *)0) || dimension_count == 0u || point_count == 0u) {
        return 0.0f;
    }

    for (point = 0u; point < point_count; point++) {
        if (points[point].coordinates == ((void *)0) || points[point].dimension_count != dimension_count) {
            return 0.0f;
        }

        distance_squared = 0.0f;

        for (dimension = 0u; dimension < dimension_count; dimension++) {
            difference = inputs[dimension] - points[point].coordinates[dimension];
            distance_squared += difference * difference;
        }

        if (distance_squared == 0.0f) {
            return fuzzy_clamp(points[point].membership);
        }

        weight = 1.0f / distance_squared;
        weighted_membership += weight * fuzzy_clamp(points[point].membership);
        weight_sum += weight;
    }

    return fuzzy_clamp(weighted_membership / weight_sum);
}



float fuzzy_triangle(
    float a,
    float b,
    float c,
    float value,
    fuzzy_hedge_t hedge
)
{
    float result;

    if (
        a >= b ||
        b >= c ||
        value <= a ||
        value >= c
    ) {
        result = 0.0f;
    }
    else if (value == b) {
        result = 1.0f;
    }
    else if (value < b) {
        result =
            (value - a) /
            (b - a);
    }
    else {
        result =
            (c - value) /
            (c - b);
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_trapezoid(
    float a,
    float b,
    float c,
    float d,
    float value,
    fuzzy_hedge_t hedge
)
{
    float result;

    if (
        a >= b ||
        b > c ||
        c >= d ||
        value <= a ||
        value >= d
    ) {
        result = 0.0f;
    }
    else if (
        value >= b &&
        value <= c
    ) {
        result = 1.0f;
    }
    else if (value < b) {
        result =
            (value - a) /
            (b - a);
    }
    else {
        result =
            (d - value) /
            (d - c);
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}



float fuzzy_smf(
    float lower_boundary,
    float upper_boundary,
    float value,
    fuzzy_hedge_t hedge
)
{
    float middle;
    float normalized;
    float result;

    if (
        lower_boundary >= upper_boundary ||
        value <= lower_boundary
    ) {
        result = 0.0f;
    }
    else if (value >= upper_boundary) {
        result = 1.0f;
    }
    else {
        middle =
            (lower_boundary + upper_boundary) /
            2.0f;

        if (value <= middle) {
            normalized =
                (value - lower_boundary) /
                (upper_boundary - lower_boundary);

            result =
                2.0f *
                normalized *
                normalized;
        }
        else {
            normalized =
                (upper_boundary - value) /
                (upper_boundary - lower_boundary);

            result =
                1.0f -
                2.0f *
                normalized *
                normalized;
        }
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_zmf(
    float lower_boundary,
    float upper_boundary,
    float value,
    fuzzy_hedge_t hedge
)
{
    float middle;
    float normalized;
    float result;

    if (
        lower_boundary >= upper_boundary ||
        value >= upper_boundary
    ) {
        result = 0.0f;
    }
    else if (value <= lower_boundary) {
        result = 1.0f;
    }
    else {
        middle =
            (lower_boundary + upper_boundary) /
            2.0f;

        if (value <= middle) {
            normalized =
                (value - lower_boundary) /
                (upper_boundary - lower_boundary);

            result =
                1.0f -
                2.0f *
                normalized *
                normalized;
        }
        else {
            normalized =
                (upper_boundary - value) /
                (upper_boundary - lower_boundary);

            result =
                2.0f *
                normalized *
                normalized;
        }
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_pimf(
    float a,
    float b,
    float c,
    float d,
    float value,
    fuzzy_hedge_t hedge
)
{
    float middle;
    float normalized;
    float result;

    if (
        a >= b ||
        b > c ||
        c >= d
    ) {
        return 0.0f;
    }

    if (
        value <= a ||
        value >= d
    ) {
        result = 0.0f;
    }
    else if (
        value >= b &&
        value <= c
    ) {
        result = 1.0f;
    }
    else if (value < b) {
        middle =
            (a + b) /
            2.0f;

        if (value <= middle) {
            normalized =
                (value - a) /
                (b - a);

            result =
                2.0f *
                normalized *
                normalized;
        }
        else {
            normalized =
                (b - value) /
                (b - a);

            result =
                1.0f -
                2.0f *
                normalized *
                normalized;
        }
    }
    else {
        middle =
            (c + d) /
            2.0f;

        if (value <= middle) {
            normalized =
                (value - c) /
                (d - c);

            result =
                1.0f -
                2.0f *
                normalized *
                normalized;
        }
        else {
            normalized =
                (d - value) /
                (d - c);

            result =
                2.0f *
                normalized *
                normalized;
        }
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_gaussian(
    float mean,
    float standard_deviation,
    float value,
    fuzzy_hedge_t hedge
)
{
    float difference;
    float exponent;
    float result;

    if (standard_deviation <= 0.0f) {
        result = 0.0f;
    }
    else {
        difference =
            value -
            mean;

        exponent =
            -(difference * difference) /
            (
                2.0f *
                standard_deviation *
                standard_deviation
            );

        result =
            expf(exponent);
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_gaussian2(
    float mean_1,
    float standard_deviation_1,
    float mean_2,
    float standard_deviation_2,
    float value,
    fuzzy_hedge_t hedge
)
{
    float difference;
    float exponent;
    float result;

    if (
        standard_deviation_1 <= 0.0f ||
        standard_deviation_2 <= 0.0f ||
        mean_1 > mean_2
    ) {
        return 0.0f;
    }

    if (value < mean_1) {
        difference =
            value -
            mean_1;

        exponent =
            -(difference * difference) /
            (
                2.0f *
                standard_deviation_1 *
                standard_deviation_1
            );

        result =
            expf(exponent);
    }
    else if (value <= mean_2) {
        result = 1.0f;
    }
    else {
        difference =
            value -
            mean_2;

        exponent =
            -(difference * difference) /
            (
                2.0f *
                standard_deviation_2 *
                standard_deviation_2
            );

        result =
            expf(exponent);
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_bell(
    float width,
    float slope,
    float center,
    float value,
    fuzzy_hedge_t hedge
)
{
    float normalized;
    float result;

    if (width == 0.0f) {
        result = 0.0f;
    }
    else {
        normalized =
            fabsf(
                (value - center) /
                (width / 2.0f)
            );

        result =
            1.0f /
            (
                1.0f +
                powf(
                    normalized,
                    2.0f * slope
                )
            );
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_sigmoid(
    float slope,
    float center,
    float value,
    fuzzy_hedge_t hedge
)
{
    float result;

    result =
        1.0f /
        (
            1.0f +
            expf(
                -slope *
                (value - center)
            )
        );

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_dsigmoid(
    float slope_1,
    float center_1,
    float slope_2,
    float center_2,
    float value,
    fuzzy_hedge_t hedge
)
{
    float sigmoid_1;
    float sigmoid_2;
    float result;

    sigmoid_1 =
        1.0f /
        (
            1.0f +
            expf(
                -slope_1 *
                (value - center_1)
            )
        );

    sigmoid_2 =
        1.0f /
        (
            1.0f +
            expf(
                -slope_2 *
                (value - center_2)
            )
        );

    result =
        sigmoid_1 -
        sigmoid_2;

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}

float fuzzy_psigmoid(
    float slope_1,
    float center_1,
    float slope_2,
    float center_2,
    float value,
    fuzzy_hedge_t hedge
)
{
    float sigmoid_1;
    float sigmoid_2;
    float result;

    sigmoid_1 =
        1.0f /
        (
            1.0f +
            expf(
                -slope_1 *
                (value - center_1)
            )
        );

    sigmoid_2 =
        1.0f /
        (
            1.0f +
            expf(
                -slope_2 *
                (value - center_2)
            )
        );

    result =
        sigmoid_1 *
        sigmoid_2;

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}



float fuzzy_function_array(
    fuzzy_shape_t shape,
    float value,
    fuzzy_hedge_t hedge,
    size_t parameter_count,
    const float *parameters
)
{
    if (parameters == ((void *)0)) {
        return 0.0f;
    }

    switch (shape) {
        case FUZZY_SHAPE_RAMP:
            if (parameter_count != 3u) {
                return 0.0f;
            }

            return fuzzy_ramp(
                parameters[0],
                parameters[1],
                value,
                parameters[2] != 0.0f,
                hedge
            );

        case FUZZY_SHAPE_TRIANGLE:
            if (parameter_count != 3u) {
                return 0.0f;
            }

            return fuzzy_triangle(
                parameters[0],
                parameters[1],
                parameters[2],
                value,
                hedge
            );

        case FUZZY_SHAPE_TRAPEZOID:
            if (parameter_count != 4u) {
                return 0.0f;
            }

            return fuzzy_trapezoid(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );



        case FUZZY_SHAPE_SMF:
            if (parameter_count != 2u) {
                return 0.0f;
            }

            return fuzzy_smf(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_ZMF:
            if (parameter_count != 2u) {
                return 0.0f;
            }

            return fuzzy_zmf(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_PIMF:
            if (parameter_count != 4u) {
                return 0.0f;
            }

            return fuzzy_pimf(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );

        case FUZZY_SHAPE_GAUSSIAN:
            if (parameter_count != 2u) {
                return 0.0f;
            }

            return fuzzy_gaussian(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_GAUSSIAN2:
            if (parameter_count != 4u) {
                return 0.0f;
            }

            return fuzzy_gaussian2(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );

        case FUZZY_SHAPE_BELL:
            if (parameter_count != 3u) {
                return 0.0f;
            }

            return fuzzy_bell(
                parameters[0],
                parameters[1],
                parameters[2],
                value,
                hedge
            );

        case FUZZY_SHAPE_SIGMOID:
            if (parameter_count != 2u) {
                return 0.0f;
            }

            return fuzzy_sigmoid(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_DSIGMOID:
            if (parameter_count != 4u) {
                return 0.0f;
            }

            return fuzzy_dsigmoid(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );

        case FUZZY_SHAPE_PSIGMOID:
            if (parameter_count != 4u) {
                return 0.0f;
            }

            return fuzzy_psigmoid(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );
# 2051 "fuzzy.h"
        default:
            return 0.0f;
    }
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
        rules == ((void *)0) ||
        output_function == ((void *)0)
    ) {
        return 0;
    }

    if (rules->count >= 32u) {
        return 0;
    }

    index =
        rules->count;

    rules->rules[index].name =
        name;

    rules->rules[index].value =
        fuzzy_clamp(value);

    rules->rules[index].output_function =
        output_function;

    rules->count++;

    return 1;
}




void fuzzy_rules_print(
    const fuzzy_rules_t *rules
)
{
    size_t i;

    if (rules == ((void *)0)) {
        return;
    }

    for (
        i = 0;
        i < rules->count;
        i++
    ) {
        printf(
            "Rule %zu -> %s: %.5f\n",
            i + 1,
            rules->rules[i].name != ((void *)0)
                ? rules->rules[i].name
                : "Unnamed",
            rules->rules[i].value
        );
    }
}



static float fuzzy_implication(
    fuzzy_implication_method_t method,
    float activation,
    float membership
)
{
    activation = fuzzy_clamp(activation);
    membership = fuzzy_clamp(membership);

    switch (method) {
        case FUZZY_IMPLICATION_MIN:
            return activation < membership
                ? activation
                : membership;

        case FUZZY_IMPLICATION_PRODUCT:
            return activation * membership;

        default:
            return 0.0f;
    }
}

static float fuzzy_aggregation(
    fuzzy_aggregation_method_t method,
    float aggregated,
    float implied
)
{
    aggregated = fuzzy_clamp(aggregated);
    implied = fuzzy_clamp(implied);

    switch (method) {
        case FUZZY_AGGREGATION_MAX:
            return aggregated > implied
                ? aggregated
                : implied;

        case FUZZY_AGGREGATION_ALGEBRAIC:
            return aggregated +
                   implied -
                   aggregated * implied;

        case FUZZY_AGGREGATION_BOUNDED:
            return fuzzy_clamp(
                aggregated +
                implied
            );

        default:
            return 0.0f;
    }
}
# 2193 "fuzzy.h"
float fuzzy_rules_defuzzify_method(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t defuzz_method,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    float weighted_sum = 0.0f;
    float height_sum = 0.0f;
    float maximum_height = 0.0f;
    float maximum_position_sum = 0.0f;
    float smallest_maximum = lower;
    float largest_maximum = lower;
    float value;
    float aggregated_height;
    float output_membership;
    float implied_height;
    size_t maximum_count = 0u;
    size_t index;
    bool maximum_found = 0;

    if (
        rules == ((void *)0) ||
        rules->count == 0u ||
        lower > upper ||
        step <= 0.0f
    ) {
        return 0.0f;
    }

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        aggregated_height = 0.0f;

        for (
            index = 0u;
            index < rules->count;
            index++
        ) {
            output_membership = fuzzy_clamp(
                rules->rules[index].output_function(value)
            );

            implied_height = fuzzy_implication(
                implication_method,
                rules->rules[index].value,
                output_membership
            );

            aggregated_height = fuzzy_aggregation(
                aggregation_method,
                aggregated_height,
                implied_height
            );
        }

        aggregated_height = fuzzy_clamp(
            aggregated_height
        );

        weighted_sum +=
            value *
            aggregated_height;

        height_sum +=
            aggregated_height;

        if (
            !maximum_found ||
            aggregated_height > maximum_height
        ) {
            maximum_height = aggregated_height;
            smallest_maximum = value;
            largest_maximum = value;
            maximum_position_sum = value;
            maximum_count = 1u;
            maximum_found = 1;
        }
        else if (aggregated_height == maximum_height) {
            largest_maximum = value;
            maximum_position_sum += value;
            maximum_count++;
        }
    }

    if (
        !maximum_found ||
        maximum_height <= 0.0f ||
        height_sum <= 0.0f
    ) {
        return 0.0f;
    }

    switch (defuzz_method) {
        case FUZZY_DEFUZZ_COG:
            return weighted_sum /
                   height_sum;

        case FUZZY_DEFUZZ_MOM:
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

float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
)
{
    return fuzzy_rules_defuzzify_method(
        rules,
        lower,
        upper,
        step,
        method,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX
    );
}




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
# 2357 "fuzzy.h"
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
        rules == ((void *)0) ||
        filename == ((void *)0) ||
        rules->count == 0 ||
        lower >= upper ||
        step <= 0.0f
    ) {
        return 0;
    }

    char plot_filename[256];

    int written = snprintf(
        plot_filename,
        sizeof(plot_filename),
        "%s.svg",
        filename
    );

    if (written < 0 || (size_t)written >= sizeof(plot_filename)) return 0;


    fuzzy_plot_t plot;

    if (!fuzzy_plot_begin(
        &plot,
        plot_filename,
        title,
        lower,
        upper,
        step
    )) {
        return 0;
    }

    FILE *file = plot.file;

    int left = plot.padding;
    int right = plot.width - plot.padding;
    int top = plot.padding;
    int bottom = plot.height - plot.padding;

    size_t sample_count = (size_t)ceilf((upper - lower) / step);




    fprintf(
        file,
        "<polyline fill=\"none\" stroke=\"#a855f7\" "
        "stroke-width=\"3\" stroke-linejoin=\"round\" "
        "stroke-linecap=\"round\" points=\""
    );

    for (size_t sample = 0; sample <= sample_count; sample++) {
        float value = lower + (float)sample * step;

        if (value > upper) value = upper;

        float aggregated_height = 0.0f;

        for (size_t i = 0; i < rules->count; i++) {
            float output_membership = rules->rules[i].output_function(value);

            float clipped_height =
                rules->rules[i].value < output_membership
                    ? rules->rules[i].value
                    : output_membership;

            aggregated_height =
                aggregated_height > clipped_height
                    ? aggregated_height
                    : clipped_height;
        }

        aggregated_height = fuzzy_clamp(aggregated_height);

        float ratio = (value - lower) / (upper - lower);

        float x = (float)left + ratio * (float)(right - left);

        float y = (float)bottom - aggregated_height * (float)(bottom - top);

        fprintf(
            file,
            "%.2f,%.2f",
            x,
            y
        );

        if (sample < sample_count) fputc(' ', file);
    }

    fprintf(file, "\" />\n");




    float cog_ratio = (cog - lower) / (upper - lower);

    cog_ratio = fuzzy_clamp(cog_ratio);

    float cog_x = (float)left + cog_ratio * (float)(right - left);

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




    fprintf(
        file,
        "<circle cx=\"%.2f\" cy=\"%d\" r=\"6\" "
        "fill=\"#ef4444\" />\n",
        cog_x,
        bottom
    );




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




    fprintf(
        file,
        "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" "
        "stroke=\"#a855f7\" stroke-width=\"4\" />\n",
        left + 15,
        top - 20,
        left + 45,
        top - 20
    );

    fprintf(
        file,
        "<text x=\"%d\" y=\"%d\" dominant-baseline=\"middle\" "
        "font-family=\"sans-serif\" font-size=\"14\" "
        "fill=\"black\">Aggregated output</text>\n",
        left + 55,
        top - 20
    );

    fuzzy_plot_end(&plot);

    printf(
        "COG plot written to %s\n",
        plot_filename
    );

    return 1;
}

static void fuzzy_plot_write_text(FILE *file, const char *text)
{
    if (file == ((void *)0) || text == ((void *)0)) {
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
        plot == ((void *)0) ||
        filename == ((void *)0) ||
        lower >= upper ||
        step <= 0.0f
    ) {
        return 0;
    }

    plot->file = fopen(filename, "w");

    if (plot->file == ((void *)0)) return 0;

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
        title != ((void *)0)
            ? title
            : "Fuzzy Membership Functions"
    );

    fprintf(file, "</text>\n");




    for (int i = 0; i <= 10; i++) {
        float membership = (float)i / 10.0f;

        float y = (float)bottom - membership * (float)(bottom - top);

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

    return 1;
}

bool fuzzy_plot_add(
    fuzzy_plot_t *plot,
    const char *name,
    const char *color,
    fuzzy_output_function_t function
)
{
    if (
        plot == ((void *)0) ||
        plot->file == ((void *)0) ||
        function == ((void *)0)
    ) {
        return 0;
    }

    if (name == ((void *)0)) {
        name = "Unnamed";
    }

    if (color == ((void *)0)) {
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

    return 1;
}

void fuzzy_plot_end(
    fuzzy_plot_t *plot
)
{
    if (
        plot == ((void *)0) ||
        plot->file == ((void *)0)
    ) {
        return;
    }

    fprintf(plot->file, "</svg>\n");

    fclose(plot->file);

    plot->file = ((void *)0);
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
        filename == ((void *)0) ||
        series == ((void *)0) ||
        series_count == 0
    ) {
        return 0;
    }

    fuzzy_plot_t plot;

    const char *plot_title = title != ((void *)0)
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

        return 0;
    }

    if (!fuzzy_plot_begin(
        &plot,
        plot_filename,
        plot_title,
        lower,
        upper,
        step
    )) {
        return 0;
    }

    for (size_t i = 0; i < series_count; i++) {
        if (series[i].function == ((void *)0)) {
            fuzzy_plot_end(&plot);
            return 0;
        }

        if (!fuzzy_plot_add(
            &plot,
            series[i].name,
            series[i].color,
            series[i].function
        )) {
            fuzzy_plot_end(&plot);
            return 0;
        }
    }

    fuzzy_plot_end(&plot);

    printf(
        "Membership plot written to %s\n",
        plot_filename
    );

    return 1;
}
# 2993 "fuzzy.h"
static bool fuzzy_sweep_write_svg(
    const fuzzy_cog_sweep_t *sweep,
    const size_t sample_counts[],
    size_t total_points,
    const float parsed_inputs[],
    const float parsed_cog_values[]
)
{
    if (
        sweep == ((void *)0) ||
        sweep->filename == ((void *)0) ||
        sweep->dimensions == ((void *)0) ||
        sweep->dimension_count == 0 ||
        sample_counts == ((void *)0) ||
        total_points == 0 ||
        parsed_inputs == ((void *)0) ||
        parsed_cog_values == ((void *)0)
    ) {
        return 0;
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
        fprintf(stderr,
            "COG sweep SVG filename is too long.\n"
        );

        return 0;
    }

    FILE *file = fopen(
        svg_filename,
        "w"
    );

    if (file == ((void *)0)) {
        fprintf(stderr,
            "Failed to open %s.\n",
            svg_filename
        );

        return 0;
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
            minimum_cog = parsed_cog_values[point];
        }

        if (
            parsed_cog_values[point] > maximum_cog
        ) {
            maximum_cog = parsed_cog_values[point];
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
        sweep->title != ((void *)0)
            ? sweep->title
            : "N-Dimensional Sweep"
    );

    fprintf(
        file,
        "</text>\n"
    );





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
            float ratio = (float)tick / 10.0f;

            float x = (float)left + ratio * (float)plot_width;

            float y = (float)bottom - ratio * (float)plot_height;

            float input_value = sweep->dimensions[0].lower + ratio * (sweep->dimensions[0].upper - sweep->dimensions[0].lower );

            float cog_value = minimum_cog + ratio * (maximum_cog - minimum_cog);

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

        for (size_t point = 0; point < total_points; point++)
        {
            float input_value = parsed_inputs[point];

            float input_ratio = (input_value - sweep->dimensions[0].lower ) / (sweep->dimensions[0].upper - sweep->dimensions[0].lower);

            float cog_ratio = (parsed_cog_values[point] - minimum_cog ) / cog_range;

            float x = (float)left + input_ratio * (float)plot_width;

            float y = (float)bottom - cog_ratio * (float)plot_height;

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
            sweep->dimensions[0].name != ((void *)0)
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
            "transform=\"rotate(-90 35 %d)\">",
            (top + bottom) / 2,
            (top + bottom) / 2
        );

        fuzzy_plot_write_text(
            file,
            sweep->value_name
        );

        fprintf(
            file,
            "</text>\n"
        );
    }
    else {
# 3318 "fuzzy.h"
        const size_t x_count = sample_counts[0];

        const size_t y_count = sample_counts[1];

        const size_t cell_count = x_count * y_count;

        float cell_width = (float)plot_width / (float)x_count;

        float cell_height = (float)plot_height / (float)y_count;




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
            sweep->dimensions[0].name != ((void *)0)
                ? sweep->dimensions[0].name
                : "Input 1"
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
            "transform=\"rotate(-90 35 %d)\">",
            (top + bottom) / 2,
            (top + bottom) / 2
        );

        fuzzy_plot_write_text(
            file,
            sweep->dimensions[1].name != ((void *)0)
                ? sweep->dimensions[1].name
                : "Input 2"
        );

        fprintf(
            file,
            "</text>\n"
        );




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
            "transform=\"rotate(-90 914 %d)\">",
            (top + bottom) / 2,
            (top + bottom) / 2
        );

        fuzzy_plot_write_text(
            file,
            sweep->value_name
        );

        fprintf(
            file,
            "</text>\n"
        );




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
                    sweep->dimensions[dimension].name != ((void *)0)
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




        fprintf(
            file,
            "<script type=\"application/ecmascript\">"
            "<![CDATA[\n"
            "const fuzzyValueName=\"%s\";\n",
            sweep->value_name
        );




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
                sweep->dimensions[dimension].name != ((void *)0)
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
# 3917 "fuzzy.h"
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
# 3999 "fuzzy.h"
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
            "text+', '+fuzzyValueName+' = '+cog.toFixed(5);\n"
            "      }\n"
            "    }\n"
            "  }\n"
            "}\n"
        );




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




    fprintf(
        file,
        "</svg>\n"
    );

    if (ferror(file)) {
        fprintf(stderr,
            "Failed while writing %s.\n",
            svg_filename
        );

        fclose(file);

        return 0;
    }

    if (fclose(file) != 0) {
        fprintf(stderr,
            "Failed to finish writing %s.\n",
            svg_filename
        );

        return 0;
    }

    printf(
        "%s sweep SVG written to %s\n",
        sweep->value_name,
        svg_filename
    );

    return 1;
}

static bool fuzzy_sweep_generate(
    const fuzzy_cog_sweep_t *sweep,
    const fuzzy_point_t points[],
    size_t point_count
)
{
    size_t dimension_count;
    size_t total_points;
    size_t sweep_input_count;

    size_t *sample_counts;
    size_t *indices;

    float *inputs;
    float *sweep_inputs;
    float *sweep_values;

    FILE *csv_file;

    char csv_filename[256];

    int written;

    bool success;

    if (
        sweep == ((void *)0) ||
        sweep->filename == ((void *)0) ||
        sweep->dimensions == ((void *)0) ||
        sweep->dimension_count == 0u
    ) {
        return 0;
    }

    if (
        sweep->evaluate == ((void *)0) &&
        (
            points == ((void *)0) ||
            point_count == 0u
        )
    ) {
        return 0;
    }

    dimension_count =
        sweep->dimension_count;

    sample_counts =
        calloc(
            dimension_count,
            sizeof(sample_counts[0])
        );

    indices =
        calloc(
            dimension_count,
            sizeof(indices[0])
        );

    inputs =
        calloc(
            dimension_count,
            sizeof(inputs[0])
        );

    if (
        sample_counts == ((void *)0) ||
        indices == ((void *)0) ||
        inputs == ((void *)0)
    ) {
        free(sample_counts);
        free(indices);
        free(inputs);

        return 0;
    }

    total_points =
        1u;

    for (
        size_t dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        const fuzzy_sweep_dimension_t *current =
            &sweep->dimensions[dimension];

        if (
            current->lower > current->upper ||
            current->step <= 0.0f
        ) {
            free(sample_counts);
            free(indices);
            free(inputs);

            return 0;
        }

        sample_counts[dimension] =
            (size_t)ceilf(
                (
                    current->upper -
                    current->lower
                ) /
                current->step
            ) + 1u;

        total_points *=
            sample_counts[dimension];
    }

    sweep_input_count =
        total_points *
        dimension_count;

    sweep_inputs =
        malloc(
            sweep_input_count *
            sizeof(sweep_inputs[0])
        );

    sweep_values =
        malloc(
            total_points *
            sizeof(sweep_values[0])
        );

    if (
        sweep_inputs == ((void *)0) ||
        sweep_values == ((void *)0)
    ) {
        free(sweep_inputs);
        free(sweep_values);
        free(sample_counts);
        free(indices);
        free(inputs);

        return 0;
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
        free(sweep_inputs);
        free(sweep_values);
        free(sample_counts);
        free(indices);
        free(inputs);

        return 0;
    }

    csv_file =
        fopen(
            csv_filename,
            "w"
        );

    if (csv_file == ((void *)0)) {
        free(sweep_inputs);
        free(sweep_values);
        free(sample_counts);
        free(indices);
        free(inputs);

        return 0;
    }

    for (
        size_t dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        fprintf(
            csv_file,
            "%s,",
            sweep->dimensions[dimension].name != ((void *)0)
                ? sweep->dimensions[dimension].name
                : "Input"
        );
    }

    fprintf(
        csv_file,
        "%s\n",
        sweep->value_name
    );

    for (
        size_t point = 0u;
        point < total_points;
        point++
    ) {
        for (
            size_t dimension = 0u;
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

        if (sweep->evaluate != ((void *)0)) {
            sweep_values[point] =
                sweep->evaluate(
                    inputs,
                    dimension_count,
                    sweep->cog_step
                );
        }
        else {
            sweep_values[point] =
                fuzzy_interpolate_membership_array(
                    inputs,
                    dimension_count,
                    points,
                    point_count
                );
        }

        fprintf(
            csv_file,
            "%.9g\n",
            sweep_values[point]
        );

        for (
            size_t dimension = dimension_count;
            dimension > 0u;
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
                0u;
        }
    }

    fclose(
        csv_file
    );

    success =
        fuzzy_sweep_write_svg(
            sweep,
            sample_counts,
            total_points,
            sweep_inputs,
            sweep_values
        );

    free(sweep_inputs);
    free(sweep_values);
    free(sample_counts);
    free(indices);
    free(inputs);

    printf(
        "%s sweep complete "
        "(%zu dimensions, %zu points)\n",
        sweep->value_name,
        dimension_count,
        total_points
    );

    return success;
}

bool fuzzy_cog_sweep(const fuzzy_cog_sweep_t *sweep)
{
    if (
        sweep == ((void *)0) ||
        sweep->evaluate == ((void *)0) ||
        sweep->cog_step <= 0.0f
    ) {
        return 0;
    }

    return fuzzy_sweep_generate(
        sweep,
        ((void *)0),
        0u
    );
}

bool fuzzy_interpolation_slices(
    const fuzzy_interpolation_sweep_t *sweep
)
{
    float *inputs;
    char filename[256];
    char title[256];

    if (
        sweep == ((void *)0) ||
        sweep->filename == ((void *)0) ||
        sweep->dimensions == ((void *)0) ||
        sweep->dimension_count == 0u ||
        sweep->points == ((void *)0) ||
        sweep->point_count == 0u
    ) {
        return 0;
    }

    inputs =
        malloc(
            sweep->dimension_count *
            sizeof(inputs[0])
        );

    if (inputs == ((void *)0)) {
        return 0;
    }

    for (
        size_t dimension = 0u;
        dimension < sweep->dimension_count;
        dimension++
    ) {
        inputs[dimension] =
            (
                sweep->dimensions[dimension].lower +
                sweep->dimensions[dimension].upper
            ) /
            2.0f;
    }

    for (
        size_t sliced_dimension = 0u;
        sliced_dimension < sweep->dimension_count;
        sliced_dimension++
    ) {
        const fuzzy_sweep_dimension_t *current =
            &sweep->dimensions[sliced_dimension];

        fuzzy_plot_t plot;

        snprintf(
            filename,
            sizeof(filename),
            "%s_%zu.svg",
            sweep->filename,
            sliced_dimension
        );

        snprintf(
            title,
            sizeof(title),
            "%s: %s Slice",
            sweep->title != ((void *)0)
                ? sweep->title
                : "Membership Interpolation",
            current->name != ((void *)0)
                ? current->name
                : "Input"
        );

        if (!fuzzy_plot_begin(
            &plot,
            filename,
            title,
            current->lower,
            current->upper,
            current->step
        )) {
            free(inputs);

            return 0;
        }

        FILE *file =
            plot.file;

        int left =
            plot.padding;

        int right =
            plot.width -
            plot.padding;

        int top =
            plot.padding;

        int bottom =
            plot.height -
            plot.padding;

        size_t sample_count =
            (size_t)ceilf(
                (
                    current->upper -
                    current->lower
                ) /
                current->step
            );

        fprintf(
            file,
            "<polyline fill=\"none\" "
            "stroke=\"#7c3aed\" "
            "stroke-width=\"3\" "
            "stroke-linejoin=\"round\" "
            "stroke-linecap=\"round\" "
            "points=\""
        );

        for (
            size_t sample = 0u;
            sample <= sample_count;
            sample++
        ) {
            float value =
                current->lower +
                (float)sample *
                current->step;

            if (value > current->upper) {
                value =
                    current->upper;
            }

            inputs[sliced_dimension] =
                value;

            float membership =
                fuzzy_interpolate_membership_array(
                    inputs,
                    sweep->dimension_count,
                    sweep->points,
                    sweep->point_count
                );

            float ratio =
                (
                    value -
                    current->lower
                ) /
                (
                    current->upper -
                    current->lower
                );

            float x =
                (float)left +
                ratio *
                (float)(right - left);

            float y =
                (float)bottom -
                membership *
                (float)(bottom - top);

            fprintf(
                file,
                "%.2f,%.2f",
                x,
                y
            );

            if (sample < sample_count) {
                fputc(
                    ' ',
                    file
                );
            }
        }

        fprintf(
            file,
            "\" />\n"
        );

        fuzzy_plot_end(
            &plot
        );

        inputs[sliced_dimension] =
            (
                current->lower +
                current->upper
            ) /
            2.0f;
    }

    free(
        inputs
    );

    return 1;
}

bool fuzzy_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep
)
{
    fuzzy_cog_sweep_t shared_sweep;

    if (
        sweep == ((void *)0) ||
        sweep->points == ((void *)0) ||
        sweep->point_count == 0u
    ) {
        return 0;
    }

    shared_sweep.filename =
        sweep->filename;

    shared_sweep.title =
        sweep->title;

    shared_sweep.value_name =
        "Membership";

    shared_sweep.dimensions =
        sweep->dimensions;

    shared_sweep.dimension_count =
        sweep->dimension_count;

    shared_sweep.cog_step =
        0.0f;

    shared_sweep.evaluate =
        ((void *)0);

    return fuzzy_sweep_generate(
        &shared_sweep,
        sweep->points,
        sweep->point_count
    );
}
# 3 "greenhouse.c" 2

static float temp_low(float x) { return fuzzy_function_array( (FUZZY_SHAPE_RAMP), (x), (1.0f), ( sizeof((const float[]) { 10.0f, 15.0f, 0 }) / sizeof(float) ), ((const float[]) { 10.0f, 15.0f, 0 }) ); }
static float temp_medium(float x) { return fuzzy_function_array( (FUZZY_SHAPE_TRIANGLE), (x), (1.0f), ( sizeof((const float[]) { 5.0f, 15.0f, 25.0f }) / sizeof(float) ), ((const float[]) { 5.0f, 15.0f, 25.0f }) ); }
static float temp_high(float x) { return fuzzy_function_array( (FUZZY_SHAPE_RAMP), (x), (1.0f), ( sizeof((const float[]) { 15.0f, 25.0f, 1 }) / sizeof(float) ), ((const float[]) { 15.0f, 25.0f, 1 }) ); }

static float humidity_low(float x) { return fuzzy_function_array( (FUZZY_SHAPE_RAMP), (x), (1.0f), ( sizeof((const float[]) { 5.0f, 10.0f, 0 }) / sizeof(float) ), ((const float[]) { 5.0f, 10.0f, 0 }) ); }
static float humidity_medium(float x) { return fuzzy_function_array( (FUZZY_SHAPE_TRAPEZOID), (x), (1.0f), ( sizeof((const float[]) { 5.0f, 10.0f, 20.0f, 25.0f }) / sizeof(float) ), ((const float[]) { 5.0f, 10.0f, 20.0f, 25.0f }) ); }
static float humidity_high(float x) { return fuzzy_function_array( (FUZZY_SHAPE_RAMP), (x), (1.0f), ( sizeof((const float[]) { 15.0f, 25.0f, 1 }) / sizeof(float) ), ((const float[]) { 15.0f, 25.0f, 1 }) ); }

static float time_short(float x) { return fuzzy_function_array( (FUZZY_SHAPE_TRAPEZOID), (x), (1.0f), ( sizeof((const float[]) { 0.0f, 10.0f, 20.0f, 30.0f }) / sizeof(float) ), ((const float[]) { 0.0f, 10.0f, 20.0f, 30.0f }) ); }
static float time_medium(float x) { return fuzzy_function_array( (FUZZY_SHAPE_TRIANGLE), (x), (1.0f), ( sizeof((const float[]) { 15.0f, 30.0f, 45.0f }) / sizeof(float) ), ((const float[]) { 15.0f, 30.0f, 45.0f }) ); }
static float time_long(float x) { return fuzzy_function_array( (FUZZY_SHAPE_TRAPEZOID), (x), (1.0f), ( sizeof((const float[]) { 30.0f, 40.0f, 50.0f, 60.0f }) / sizeof(float) ), ((const float[]) { 30.0f, 40.0f, 50.0f, 60.0f }) ); }

static float watering(float temperature, float humidity, float step, const char *plot)
{
    fuzzy_rules_t rules;
    rules.count = 0;

    fuzzy_rules_add( (&rules), ("Time: Short"), (fuzzy_or_array( (FUZZY_LOGIC_STANDARD), ( sizeof((const float[]) { temp_low(temperature), humidity_medium(humidity) }) / sizeof(float) ), ((const float[]) { temp_low(temperature), humidity_medium(humidity) }) )), (time_short) );
    fuzzy_rules_add( (&rules), ("Time: Medium"), (fuzzy_and_array( (FUZZY_LOGIC_STANDARD), ( sizeof((const float[]) { humidity_medium(humidity), temp_medium(temperature) }) / sizeof(float) ), ((const float[]) { humidity_medium(humidity), temp_medium(temperature) }) )), (time_medium) );
    fuzzy_rules_add( (&rules), ("Time: Long"), (fuzzy_or_array( (FUZZY_LOGIC_STANDARD), ( sizeof((const float[]) { humidity_low(humidity), temp_high(temperature) }) / sizeof(float) ), ((const float[]) { humidity_low(humidity), temp_high(temperature) }) )), (time_long) );

    float result = fuzzy_rules_defuzzify(&rules, 0.0f, 60.0f, step, FUZZY_DEFUZZ_COG);

    fuzzy_rules_print(&rules);
    fuzzy_rules_plot_cog(&rules, plot, "Center of Gravity Defuzzification", result, 0.0f, 60.0f, step);

    return result;
}

static float sweep( const float inputs[], size_t input_count, float cog_step ) { (void)input_count; (void)cog_step; return watering(inputs[0], inputs[1], cog_step, ((void *)0)); }

int main(void)
{
    float temperature, humidity;

    fuzzy_plot_many( ("greenhouse/humidity"), ("Humidity Membership Functions"), (0.0f), (30.0f), (1.0f), (const fuzzy_plot_series_t[]) { (fuzzy_plot_series_t) { .name = ("humidity_low"), .color = ("#ef4444"), .function = (humidity_low) }, (fuzzy_plot_series_t) { .name = ("humidity_medium"), .color = ("#3b82f6"), .function = (humidity_medium) }, (fuzzy_plot_series_t) { .name = ("humidity_high"), .color = ("#70f63b"), .function = (humidity_high) } }, sizeof((const fuzzy_plot_series_t[]) { (fuzzy_plot_series_t) { .name = ("humidity_low"), .color = ("#ef4444"), .function = (humidity_low) }, (fuzzy_plot_series_t) { .name = ("humidity_medium"), .color = ("#3b82f6"), .function = (humidity_medium) }, (fuzzy_plot_series_t) { .name = ("humidity_high"), .color = ("#70f63b"), .function = (humidity_high) } }) / sizeof(fuzzy_plot_series_t) )


                                         ;

    fuzzy_plot_many( ("greenhouse/temperature"), ("Temperature Membership Functions"), (0.0f), (30.0f), (1.0f), (const fuzzy_plot_series_t[]) { (fuzzy_plot_series_t) { .name = ("temp_low"), .color = ("#3b82f6"), .function = (temp_low) }, (fuzzy_plot_series_t) { .name = ("temp_medium"), .color = ("#22c55e"), .function = (temp_medium) }, (fuzzy_plot_series_t) { .name = ("temp_high"), .color = ("#ef4444"), .function = (temp_high) } }, sizeof((const fuzzy_plot_series_t[]) { (fuzzy_plot_series_t) { .name = ("temp_low"), .color = ("#3b82f6"), .function = (temp_low) }, (fuzzy_plot_series_t) { .name = ("temp_medium"), .color = ("#22c55e"), .function = (temp_medium) }, (fuzzy_plot_series_t) { .name = ("temp_high"), .color = ("#ef4444"), .function = (temp_high) } }) / sizeof(fuzzy_plot_series_t) )


                                     ;

    fuzzy_plot_many( ("greenhouse/time"), ("Watering-Time Membership Functions"), (0.0f), (60.0f), (1.0f), (const fuzzy_plot_series_t[]) { (fuzzy_plot_series_t) { .name = ("time_short"), .color = ("#ef4444"), .function = (time_short) }, (fuzzy_plot_series_t) { .name = ("time_medium"), .color = ("#22c55e"), .function = (time_medium) }, (fuzzy_plot_series_t) { .name = ("time_long"), .color = ("#3b82f6"), .function = (time_long) } }, sizeof((const fuzzy_plot_series_t[]) { (fuzzy_plot_series_t) { .name = ("time_short"), .color = ("#ef4444"), .function = (time_short) }, (fuzzy_plot_series_t) { .name = ("time_medium"), .color = ("#22c55e"), .function = (time_medium) }, (fuzzy_plot_series_t) { .name = ("time_long"), .color = ("#3b82f6"), .function = (time_long) } }) / sizeof(fuzzy_plot_series_t) )


                                     ;

    fuzzy_cog_sweep( &(const fuzzy_cog_sweep_t) { .filename = ("greenhouse/greenhouse_cog_sweep"), .title = ("Greenhouse Watering-Time COG Sweep"), .value_name = "COG", .dimensions = (const fuzzy_sweep_dimension_t[]) { (fuzzy_sweep_dimension_t) { .name = ("Temperature"), .lower = (0.0f), .upper = (30.0f), .step = (1.0f) }, (fuzzy_sweep_dimension_t) { .name = ("Humidity"), .lower = (0.0f), .upper = (30.0f), .step = (1.0f) } }, .dimension_count = sizeof( (const fuzzy_sweep_dimension_t[]) { (fuzzy_sweep_dimension_t) { .name = ("Temperature"), .lower = (0.0f), .upper = (30.0f), .step = (1.0f) }, (fuzzy_sweep_dimension_t) { .name = ("Humidity"), .lower = (0.0f), .upper = (30.0f), .step = (1.0f) } } ) / sizeof(fuzzy_sweep_dimension_t), .cog_step = (0.1f), .evaluate = (sweep) } )






     ;

        printf("\nWater Time Fuzzy System\n=======================\n");
        printf("Enter the temperature (C): ");
        scanf("%f", &temperature);

        printf("Enter the humidity (%%): ");
        scanf("%f", &humidity);

        float result = watering(temperature, humidity, 0.01f, "greenhouse/cog");
        printf("\nWatering-time COG: %.5f\n", result);


    printf("\nProgram closed.\n");
}
