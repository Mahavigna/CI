#ifndef FUZZY_H
#define FUZZY_H

#define CATCH_FAILS(function, ...) \
    do { \
        if (!(function(__VA_ARGS__))) { \
            fprintf(stderr, "%s failed.\n", #function); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

#ifdef FUZZY_8051

#include <stddef.h>
#include <stdint.h>
#include <math.h>

typedef unsigned char bool;
typedef unsigned char uint8_t;

#define false 0u
#define true 1u

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef FUZZY_MAX_RULES
#define FUZZY_MAX_RULES 16u
#endif

#ifndef FUZZY_MAX_VALUES
#define FUZZY_MAX_VALUES 16u
#endif

#define LEVEL_HI 1.0f
#define LEVEL_LO 0.0f

typedef uint8_t fuzzy_hedge_t;

typedef struct FuzzyHedges {
    fuzzy_hedge_t none;
    fuzzy_hedge_t very;
    fuzzy_hedge_t extremely;
} hedges_t;

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
    FUZZY_DEFUZZ_BOA,
    FUZZY_DEFUZZ_COS,
    FUZZY_DEFUZZ_MOM,
    FUZZY_DEFUZZ_SOM,
    FUZZY_DEFUZZ_LOM
} fuzzy_defuzz_method_t;

typedef struct FuzzyVariable8051 {
    uint8_t shape;
    fuzzy_hedge_t hedge;
    float parameters[4];
} fuzzy_variable_8051_t;

typedef struct FuzzyRule {
    float value;
    const fuzzy_variable_8051_t *output;
} fuzzy_rule_t;

typedef struct FuzzyRules {
    fuzzy_rule_t rules[FUZZY_MAX_RULES];
    uint8_t count;
} fuzzy_rules_t;

static float fuzzy_8051_eval(const fuzzy_variable_8051_t *variable, float value);
float fuzzy_not(float membership);
float fuzzy_ramp(float lower_boundary, float upper_boundary, float value, bool ramp_up, fuzzy_hedge_t hedge);
float fuzzy_triangle(float a, float b, float c, float value, fuzzy_hedge_t hedge);
float fuzzy_trapezoid(float a, float b, float c, float d, float value, fuzzy_hedge_t hedge);
bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output);
float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method);
float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step);

#define FUZZY_8051_VAR_SELECT_I(shape) FUZZY_8051_VAR_##shape
#define FUZZY_8051_VAR_SELECT(shape) FUZZY_8051_VAR_SELECT_I(shape)
#define FUZZY_VAR(name, shape, hedge, ...) FUZZY_8051_VAR_SELECT(shape)(name, hedge, __VA_ARGS__)
#define FUZZY_8051_VAR_FUZZY_SHAPE_RAMP(name, hedge, a, b, up) static const fuzzy_variable_8051_t name##_fuzzy_variable = { FUZZY_SHAPE_RAMP, (fuzzy_hedge_t)(hedge), { (float)(a), (float)(b), (float)(up), 0.0f } }; static float name(float x) { return fuzzy_8051_eval(&name##_fuzzy_variable, x); }
#define FUZZY_8051_VAR_FUZZY_SHAPE_TRIANGLE(name, hedge, a, b, c) static const fuzzy_variable_8051_t name##_fuzzy_variable = { FUZZY_SHAPE_TRIANGLE, (fuzzy_hedge_t)(hedge), { (float)(a), (float)(b), (float)(c), 0.0f } }; static float name(float x) { return fuzzy_8051_eval(&name##_fuzzy_variable, x); }
#define FUZZY_8051_VAR_FUZZY_SHAPE_TRAPEZOID(name, hedge, a, b, c, d) static const fuzzy_variable_8051_t name##_fuzzy_variable = { FUZZY_SHAPE_TRAPEZOID, (fuzzy_hedge_t)(hedge), { (float)(a), (float)(b), (float)(c), (float)(d) } }; static float name(float x) { return fuzzy_8051_eval(&name##_fuzzy_variable, x); }
#define RULE(rule_var, name, activation, output) fuzzy_rules_add_8051(&(rule_var), (activation), &output##_fuzzy_variable)
#define FUZZY_RULE_ADD(rules, value, output) fuzzy_rules_add_8051((rules), (value), &output##_fuzzy_variable)
#define FUZZY_RULE_ADD_NAMED(rules, name, value, output) fuzzy_rules_add_8051((rules), (value), &output##_fuzzy_variable)

static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b)
{
    if (method == FUZZY_LOGIC_ALGEBRAIC) {
        return a * b;
    }

    if (method == FUZZY_LOGIC_BOUNDED) {
        float value = a + b - 1.0f;
        return value > 0.0f ? value : 0.0f;
    }

    return a < b ? a : b;
}

static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c)
{
    return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c);
}

static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b)
{
    if (method == FUZZY_LOGIC_ALGEBRAIC) {
        return a + b - a * b;
    }

    if (method == FUZZY_LOGIC_BOUNDED) {
        float value = a + b;
        return value < 1.0f ? value : 1.0f;
    }

    return a > b ? a : b;
}

static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c)
{
    return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c);
}

#define FUZZY_8051_SELECT_3(_1, _2, _3, NAME, ...) NAME
#define fuzzy_and_method(method, ...) FUZZY_8051_SELECT_3(__VA_ARGS__, fuzzy_8051_and3, fuzzy_8051_and2)((method), __VA_ARGS__)
#define fuzzy_or_method(method, ...) FUZZY_8051_SELECT_3(__VA_ARGS__, fuzzy_8051_or3, fuzzy_8051_or2)((method), __VA_ARGS__)
#define fuzzy_sugeno_weighted_average(w1,z1,w2,z2,w3,z3,w4,z4,w5,z5,w6,z6) ((((w1)*(z1))+((w2)*(z2))+((w3)*(z3))+((w4)*(z4))+((w5)*(z5))+((w6)*(z6)))/((w1)+(w2)+(w3)+(w4)+(w5)+(w6)))
#define fuzzy_sugeno_weighted_sum(w1,z1,w2,z2,w3,z3,w4,z4,w5,z5,w6,z6) (((w1)*(z1))+((w2)*(z2))+((w3)*(z3))+((w4)*(z4))+((w5)*(z5))+((w6)*(z6)))

#ifdef FUZZY_IMPLEMENTATION

static float fuzzy_8051_clamp(float value)
{
    if (value < 0.0f) {
        return 0.0f;
    }

    if (value > 1.0f) {
        return 1.0f;
    }

    return value;
}

static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge)
{
    float result;

    value = fuzzy_8051_clamp(value);

    if (hedge == 0u) {
        hedge = 1u;
    }

    result = 1.0f;

    while (hedge != 0u) {
        result *= value;
        --hedge;
    }

    return fuzzy_8051_clamp(result);
}

float fuzzy_not(float membership)
{
    return 1.0f - fuzzy_8051_clamp(membership);
}

float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge)
{
    float result;

    if (a >= b) {
        return 0.0f;
    }

    if (x <= a) {
        result = up ? 0.0f : 1.0f;
    }
    else if (x >= b) {
        result = up ? 1.0f : 0.0f;
    }
    else {
        result = (x - a) / (b - a);

        if (!up) {
            result = 1.0f - result;
        }
    }

    return fuzzy_8051_hedge(result, hedge);
}

float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge)
{
    float result;

    if (a >= b || b >= c || x <= a || x >= c) {
        result = 0.0f;
    }
    else if (x == b) {
        result = 1.0f;
    }
    else if (x < b) {
        result = (x - a) / (b - a);
    }
    else {
        result = (c - x) / (c - b);
    }

    return fuzzy_8051_hedge(result, hedge);
}

float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge)
{
    float result;

    if (a >= b || b > c || c >= d || x <= a || x >= d) {
        result = 0.0f;
    }
    else if (x >= b && x <= c) {
        result = 1.0f;
    }
    else if (x < b) {
        result = (x - a) / (b - a);
    }
    else {
        result = (d - x) / (d - c);
    }

    return fuzzy_8051_hedge(result, hedge);
}

static float fuzzy_8051_eval(const fuzzy_variable_8051_t *variable, float value)
{
    if (variable->shape == FUZZY_SHAPE_RAMP) {
        return fuzzy_ramp(variable->parameters[0], variable->parameters[1], value, variable->parameters[2] != 0.0f, variable->hedge);
    }

    if (variable->shape == FUZZY_SHAPE_TRIANGLE) {
        return fuzzy_triangle(variable->parameters[0], variable->parameters[1], variable->parameters[2], value, variable->hedge);
    }

    if (variable->shape == FUZZY_SHAPE_TRAPEZOID) {
        return fuzzy_trapezoid(variable->parameters[0], variable->parameters[1], variable->parameters[2], variable->parameters[3], value, variable->hedge);
    }

    return 0.0f;
}

bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output)
{
    uint8_t index;

    if (rules->count >= FUZZY_MAX_RULES) {
        return false;
    }

    index = rules->count;
    rules->rules[index].value = fuzzy_8051_clamp(value);
    rules->rules[index].output = output;
    rules->count = index + 1u;

    return true;
}

static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x)
{
    uint8_t index;
    float aggregate;
    float membership;
    float implied;

    aggregate = 0.0f;

    for (index = 0u; index < rules->count; ++index) {
        membership = fuzzy_8051_eval(rules->rules[index].output, x);
        implied = rules->rules[index].value < membership ? rules->rules[index].value : membership;

        if (implied > aggregate) {
            aggregate = implied;
        }
    }

    return aggregate;
}

float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method)
{
    float x;
    float height;
    float weighted;
    float sum;
    float maximum;
    float maximum_sum;
    float smallest;
    float largest;
    unsigned int maximum_count;

    if (rules->count == 0u || lower > upper || step <= 0.0f) {
        return 0.0f;
    }

    weighted = 0.0f;
    sum = 0.0f;
    maximum = -1.0f;
    maximum_sum = 0.0f;
    maximum_count = 0u;
    smallest = lower;
    largest = lower;

    for (x = lower; x <= upper; x += step) {
        height = fuzzy_8051_height(rules, x);

        weighted += x * height;
        sum += height;

        if (height > maximum) {
            maximum = height;
            maximum_sum = x;
            maximum_count = 1u;
            smallest = x;
            largest = x;
        }
        else if (height == maximum) {
            maximum_sum += x;
            ++maximum_count;
            largest = x;
        }
    }

    if (method == FUZZY_DEFUZZ_MOM) {
        return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f;
    }

    if (method == FUZZY_DEFUZZ_SOM) {
        return maximum > 0.0f ? smallest : 0.0f;
    }

    if (method == FUZZY_DEFUZZ_LOM) {
        return maximum > 0.0f ? largest : 0.0f;
    }

    return sum > 0.0f ? weighted / sum : 0.0f;
}

float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step)
{
    return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG);
}

#endif

#else

#include <stddef.h>

/* ==========================================================
 * Full CPU backend platform configuration
 *
 * ESP32 uses the real newlib declarations supplied by the
 * Espressif toolchain.
 *
 * Desktop platforms retain the existing minimal manually
 * declared CRT interface.
 * ========================================================== */

#if defined(FUZZY_ESP32)

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FUZZY_CDECL

#else

/* ==========================================================
 * Minimal compiler and CRT declarations
 *
 * Supported:
 *
 * - GCC on Linux
 * - Clang on Linux
 * - MinGW-w64
 * - MSVC
 * - clang-cl
 * - Apple Clang
 *
 * Standard library headers are intentionally not included.
 * The platform C runtime supplies the linked definitions.
 * ========================================================== */

#if defined(_MSC_VER)
typedef unsigned char bool;
#else
typedef _Bool bool;
#endif

#define true 1
#define false 0

#ifndef NULL
#define NULL ((void *)0)
#endif

/* ==========================================================
 * Platform FILE type and standard streams
 * ========================================================== */

#if defined(_WIN32)

typedef struct _iobuf FILE;

#if defined(_MSC_VER)
#define FUZZY_CDECL __cdecl
#else
#define FUZZY_CDECL
#endif

extern FILE *FUZZY_CDECL __acrt_iob_func(unsigned int);

#define FUZZY_STDERR (__acrt_iob_func(2u))
#define FUZZY_STDOUT (__acrt_iob_func(1u))
#define FUZZY_STDIN (__acrt_iob_func(0u))

#ifndef stderr
#define stderr FUZZY_STDERR
#endif

#ifndef stdout
#define stdout FUZZY_STDOUT
#endif

#ifndef stdin
#define stdin FUZZY_STDIN
#endif

#ifndef RAND_MAX
#define RAND_MAX 32767
#endif

#elif defined(__APPLE__)

typedef struct __sFILE FILE;

#define FUZZY_CDECL

extern FILE *__stderrp;
extern FILE *__stdoutp;
extern FILE *__stdinp;

#define FUZZY_STDERR (__stderrp)
#define FUZZY_STDOUT (__stdoutp)
#define FUZZY_STDIN (__stdinp)

#ifndef stderr
#define stderr FUZZY_STDERR
#endif

#ifndef stdout
#define stdout FUZZY_STDOUT
#endif

#ifndef stdin
#define stdin FUZZY_STDIN
#endif

#ifndef RAND_MAX
#define RAND_MAX 2147483647
#endif

#else

typedef struct _IO_FILE FILE;

#define FUZZY_CDECL

extern FILE *stderr;
extern FILE *stdout;
extern FILE *stdin;

#define FUZZY_STDERR (stderr)
#define FUZZY_STDOUT (stdout)
#define FUZZY_STDIN (stdin)

#ifndef RAND_MAX
#define RAND_MAX 2147483647
#endif

#endif

/* ==========================================================
 * Formatted input and output
 * ========================================================== */

extern int FUZZY_CDECL printf(const char *, ...);
extern int FUZZY_CDECL fprintf(FILE *, const char *, ...);
extern int FUZZY_CDECL snprintf(char *, size_t, const char *, ...);
extern int FUZZY_CDECL scanf(const char *, ...);

/* ==========================================================
 * File operations
 * ========================================================== */

extern FILE *FUZZY_CDECL fopen(const char *, const char *);
extern int FUZZY_CDECL fclose(FILE *);
extern int FUZZY_CDECL ferror(FILE *);
extern int FUZZY_CDECL fputc(int, FILE *);
extern int FUZZY_CDECL fputs(const char *, FILE *);

/* ==========================================================
 * Dynamic memory
 * ========================================================== */

extern void *FUZZY_CDECL malloc(size_t);
extern void *FUZZY_CDECL calloc(size_t, size_t);
extern void FUZZY_CDECL free(void *);
extern void FUZZY_CDECL abort(void);
extern void *FUZZY_CDECL realloc(void *, size_t);

/* ==========================================================
 * Memory operations
 * ========================================================== */

extern void *FUZZY_CDECL memset(void *, int, size_t);
extern void *FUZZY_CDECL memcpy(void *, const void *, size_t);

/* ==========================================================
 * Mathematics
 * ========================================================== */

extern float FUZZY_CDECL powf(float, float);
extern float FUZZY_CDECL expf(float);
extern float FUZZY_CDECL fabsf(float);
extern float FUZZY_CDECL ceilf(float);

/* ==========================================================
 * Pseudorandom numbers
 * ========================================================== */

extern int FUZZY_CDECL rand(void);
extern void FUZZY_CDECL srand(unsigned int);

#endif

/* ==========================================================
 * Full CPU backend configuration
 * ========================================================== */

#ifndef FUZZY_MAX_RULES
#define FUZZY_MAX_RULES 32u
#endif

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

#define FUZZY_INPUTS(...) ((fuzzy_point_t){(const float[]){__VA_ARGS__}, FUZZY_VALUE_COUNT(__VA_ARGS__), 0.0f})
#define FUZZY_POINT(membership, ...) ((fuzzy_point_t){(const float[]){__VA_ARGS__}, FUZZY_VALUE_COUNT(__VA_ARGS__), (float)(membership)})
#define fuzzy_interpolate_membership(inputs, ...) fuzzy_interpolate_membership_array((inputs).coordinates, (inputs).dimension_count, (const fuzzy_point_t[]){__VA_ARGS__}, sizeof((const fuzzy_point_t[]){__VA_ARGS__}) / sizeof(fuzzy_point_t))

/* ==========================================================
 * Shared constants and argument-array helpers
 * ========================================================== */

#define LEVEL_HI 1.0f
#define LEVEL_LO 0.0f

#ifndef FUZZY_MAX_VALUES
#define FUZZY_MAX_VALUES 16u
#endif

#ifndef FUZZY_8051

#define FUZZY_VALUES(...)                             \
    ((const float[]) { __VA_ARGS__ })

#define FUZZY_VALUE_COUNT(...)                        \
    (                                                 \
        sizeof((const float[]) { __VA_ARGS__ }) /     \
        sizeof(float)                                 \
    )

#else

/*
 * Count between 1 and 16 supplied values.
 */
#define FUZZY_VALUE_COUNT_PRIVATE(                    \
    _1, _2, _3, _4, _5, _6, _7, _8,                 \
    _9, _10, _11, _12, _13, _14, _15, _16,          \
    count, ...                                        \
)                                                     \
    count

#define FUZZY_VALUE_COUNT(...)                        \
    FUZZY_VALUE_COUNT_PRIVATE(                        \
        __VA_ARGS__,                                  \
        16u, 15u, 14u, 13u,                          \
        12u, 11u, 10u, 9u,                           \
        8u, 7u, 6u, 5u,                              \
        4u, 3u, 2u, 1u                               \
    )


/*
 * Monolithic fixed buffer.
 */
static float fuzzy_values_buffer[FUZZY_MAX_VALUES];


/*
 * Initialize the complete buffer to zero.
 */
static float *fuzzy_values_initialize(void)
{
    size_t index;

    for (
        index = 0u;
        index < FUZZY_MAX_VALUES;
        index++
    ) {
        fuzzy_values_buffer[index] = 0.0f;
    }

    return fuzzy_values_buffer;
}


/*
 * Fixed-arity initializers write only the supplied values.
 *
 * The monolithic initializer clears all remaining entries.
 */
#define FUZZY_VALUES_1(v1)                            \
    (                                                 \
        fuzzy_values_initialize(),                    \
        fuzzy_values_buffer[0] = (float)(v1),         \
        fuzzy_values_buffer                           \
    )

#define FUZZY_VALUES_2(v1, v2)                        \
    (                                                 \
        fuzzy_values_initialize(),                    \
        fuzzy_values_buffer[0] = (float)(v1),         \
        fuzzy_values_buffer[1] = (float)(v2),         \
        fuzzy_values_buffer                           \
    )

#define FUZZY_VALUES_3(v1, v2, v3)                    \
    (                                                 \
        fuzzy_values_initialize(),                    \
        fuzzy_values_buffer[0] = (float)(v1),         \
        fuzzy_values_buffer[1] = (float)(v2),         \
        fuzzy_values_buffer[2] = (float)(v3),         \
        fuzzy_values_buffer                           \
    )

#define FUZZY_VALUES_4(v1, v2, v3, v4)                \
    (                                                 \
        fuzzy_values_initialize(),                    \
        fuzzy_values_buffer[0] = (float)(v1),         \
        fuzzy_values_buffer[1] = (float)(v2),         \
        fuzzy_values_buffer[2] = (float)(v3),         \
        fuzzy_values_buffer[3] = (float)(v4),         \
        fuzzy_values_buffer                           \
    )

#define FUZZY_VALUES_5(v1, v2, v3, v4, v5)            \
    (                                                 \
        fuzzy_values_initialize(),                    \
        fuzzy_values_buffer[0] = (float)(v1),         \
        fuzzy_values_buffer[1] = (float)(v2),         \
        fuzzy_values_buffer[2] = (float)(v3),         \
        fuzzy_values_buffer[3] = (float)(v4),         \
        fuzzy_values_buffer[4] = (float)(v5),         \
        fuzzy_values_buffer                           \
    )

#define FUZZY_VALUES_12(                              \
    v1, v2, v3, v4, v5, v6,                          \
    v7, v8, v9, v10, v11, v12                        \
)                                                     \
    (                                                 \
        fuzzy_values_initialize(),                    \
        fuzzy_values_buffer[0] = (float)(v1),         \
        fuzzy_values_buffer[1] = (float)(v2),         \
        fuzzy_values_buffer[2] = (float)(v3),         \
        fuzzy_values_buffer[3] = (float)(v4),         \
        fuzzy_values_buffer[4] = (float)(v5),         \
        fuzzy_values_buffer[5] = (float)(v6),         \
        fuzzy_values_buffer[6] = (float)(v7),         \
        fuzzy_values_buffer[7] = (float)(v8),         \
        fuzzy_values_buffer[8] = (float)(v9),         \
        fuzzy_values_buffer[9] = (float)(v10),        \
        fuzzy_values_buffer[10] = (float)(v11),       \
        fuzzy_values_buffer[11] = (float)(v12),       \
        fuzzy_values_buffer                           \
    )


#define FUZZY_VALUES_SELECT_PRIVATE(                  \
    _1, _2, _3, _4, _5, _6, _7, _8,                 \
    _9, _10, _11, _12, _13, _14, _15, _16,          \
    selected, ...                                     \
)                                                     \
    selected


#define FUZZY_VALUES_UNSUPPORTED(...)                 \
    fuzzy_values_unsupported_argument_count


#define FUZZY_VALUES(...)                             \
    FUZZY_VALUES_SELECT_PRIVATE(                      \
        __VA_ARGS__,                                  \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_12,                              \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_UNSUPPORTED,                     \
        FUZZY_VALUES_5,                               \
        FUZZY_VALUES_4,                               \
        FUZZY_VALUES_3,                               \
        FUZZY_VALUES_2,                               \
        FUZZY_VALUES_1                                \
    )(                                                \
        __VA_ARGS__                                   \
    )

#endif /* FUZZY_8051 */

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

/*
 * Membership-function shape selection.
 */
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


/* ==========================================================
 * Mamdani defuzzification methods
 * ========================================================== */

typedef enum FuzzyDefuzzMethod {
    FUZZY_DEFUZZ_COG = 0,
    FUZZY_DEFUZZ_BOA,
    FUZZY_DEFUZZ_COS,
    FUZZY_DEFUZZ_MOM,
    FUZZY_DEFUZZ_SOM,
    FUZZY_DEFUZZ_LOM
} fuzzy_defuzz_method_t;


//Inheritance Nonsense in C :)P
typedef struct FuzzyRule {
    const char *name;
    float value;    
    fuzzy_output_function_t output_function;
} fuzzy_rule_t;


typedef struct FuzzyRules {
    fuzzy_rule_t rules[FUZZY_MAX_RULES];
    size_t count;
} fuzzy_rules_t;


/* ==========================================================
 * Rule-addition macros
 * ========================================================== */

#define FUZZY_RULE_ADD(                               \
    rules, value, output_function                     \
)                                                     \
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


/* ==========================================================
 * Core inference API
 *
 * Available on desktop and 8051.
 * ========================================================== */

float fuzzy_not(float membership);


/*
 * Internal array implementations.
 *
 * The public macros calculate the array size automatically.
 */
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


/*
 * Public count-free interfaces.
 *
 * Examples:
 *
 * fuzzy_and_method(
 *     FUZZY_LOGIC_STANDARD,
 *     value_1,
 *     value_2,
 *     value_3
 * );
 *
 * fuzzy_or_method(
 *     FUZZY_LOGIC_ALGEBRAIC,
 *     value_1,
 *     value_2,
 *     value_3
 * );
 */
#define fuzzy_and_method(method, ...)                 \
    fuzzy_and_array(                                  \
        (method),                                     \
        FUZZY_VALUE_COUNT(__VA_ARGS__),               \
        FUZZY_VALUES(__VA_ARGS__)                     \
    )

#define fuzzy_or_method(method, ...)                  \
    fuzzy_or_array(                                   \
        (method),                                     \
        FUZZY_VALUE_COUNT(__VA_ARGS__),               \
        FUZZY_VALUES(__VA_ARGS__)                     \
    )



/*
 * Internal array-based Sugeno implementations.
 *
 * Values are supplied as alternating pairs:
 *
 *     firing_strength, consequent
 */
float fuzzy_sugeno_weighted_average_array(
    size_t value_count,
    const float *values
);

float fuzzy_sugeno_weighted_sum_array(
    size_t value_count,
    const float *values
);


/*
 * Public count-free Sugeno interfaces.
 */
#define fuzzy_sugeno_weighted_average(...)            \
    fuzzy_sugeno_weighted_average_array(              \
        FUZZY_VALUE_COUNT(__VA_ARGS__),               \
        FUZZY_VALUES(__VA_ARGS__)                     \
    )

#define fuzzy_sugeno_weighted_sum(...)                \
    fuzzy_sugeno_weighted_sum_array(                  \
        FUZZY_VALUE_COUNT(__VA_ARGS__),               \
        FUZZY_VALUES(__VA_ARGS__)                     \
    )

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

#ifndef FUZZY_8051

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

#define FUZZY_INPUTS(...) ((fuzzy_point_t){(const float[]){__VA_ARGS__}, FUZZY_VALUE_COUNT(__VA_ARGS__), 0.0f})
#define FUZZY_POINT(membership, ...) ((fuzzy_point_t){(const float[]){__VA_ARGS__}, FUZZY_VALUE_COUNT(__VA_ARGS__), (float)(membership)})
#define fuzzy_interpolate_membership(inputs, ...) fuzzy_interpolate_membership_array((inputs).coordinates, (inputs).dimension_count, (const fuzzy_point_t[]){__VA_ARGS__}, sizeof((const fuzzy_point_t[]){__VA_ARGS__}) / sizeof(fuzzy_point_t))

#endif /* FUZZY_8051 */

float fuzzy_function_array(
    fuzzy_shape_t shape,
    float value,
    fuzzy_hedge_t hedge,
    size_t parameter_count,
    const float *parameters
);

#define fuzzy_function(shape, value, hedge, ...)      \
    fuzzy_function_array(                             \
        (shape),                                      \
        (value),                                      \
        (hedge),                                      \
        FUZZY_VALUE_COUNT(__VA_ARGS__),               \
        FUZZY_VALUES(__VA_ARGS__)                     \
    )


/* FUZZY LOGIC OPERATOR ADAPTERS */
#define SAND(...) fuzzy_and_method(FUZZY_LOGIC_STANDARD, __VA_ARGS__)
#define SOR(...)  fuzzy_or_method(FUZZY_LOGIC_STANDARD, __VA_ARGS__)
#define AAND(...) fuzzy_and_method(FUZZY_LOGIC_ALGEBRAIC, __VA_ARGS__)
#define AOR(...)  fuzzy_or_method(FUZZY_LOGIC_ALGEBRAIC, __VA_ARGS__)
#define BAND(...) fuzzy_and_method(FUZZY_LOGIC_BOUNDED, __VA_ARGS__)
#define BOR(...)  fuzzy_or_method(FUZZY_LOGIC_BOUNDED, __VA_ARGS__)

#define RULE(rule_var, name, activation, output) FUZZY_RULE_ADD_NAMED(&(rule_var), name, activation, output)
#define OPERATOR(name, operation, method) static float name(float x) { return operation(method, x, 0.5f); }

//Temp Test
#define SWEEP_EVALUATOR(name, function, ...)          \
    static float name(                                \
        const float inputs[],                         \
        size_t input_count,                           \
        float cog_step                                \
    )                                                 \
    {                                                 \
        (void)input_count;                            \
        (void)cog_step;                               \
        return function(__VA_ARGS__);                 \
    }


/*FUZZY VARIABLE NAMING AND SHAPE SET WITH PY-STYLE SYNTAX*/        
#define FUZZY_VAR(name, shape, hedge, ...) static float name(float x) { return fuzzy_function(shape, x, hedge, __VA_ARGS__); }


bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
);

/*
 * Direct low-level Mamdani defuzzification functions.
 */

float fuzzy_rules_defuzzify_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);

float fuzzy_rules_defuzzify_boa(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);

float fuzzy_rules_defuzzify_cos(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method
);

float fuzzy_rules_defuzzify_mom(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);

float fuzzy_rules_defuzzify_som(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);

float fuzzy_rules_defuzzify_lom(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);


/*
 * Configurable method-selection wrapper.
 */
float fuzzy_rules_defuzzify_method(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t defuzz_method,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
);


/*
 * Default min-implication and max-aggregation wrapper.
 */
float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
);


/*
 * Existing COG compatibility wrapper.
 */
float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
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


typedef float (*fuzzy_sweep_evaluator_t)(const float inputs[], size_t input_count, float cog_step);

typedef struct fuzzy_cog_sweep
{
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
            .value_name = "COG",                      \
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

#ifdef FUZZY_OPENCL

#ifndef CL_TARGET_OPENCL_VERSION
#define CL_TARGET_OPENCL_VERSION 120
#endif

#include <CL/cl.h>
#include <math.h>

typedef enum FuzzyGpuOperator {
    FUZZY_OPERATOR_AND = 0,
    FUZZY_OPERATOR_OR
} fuzzy_gpu_operator_t;

typedef struct FuzzyGpuVariable {
    cl_uint input;
    cl_uint shape;
    cl_float hedge;
    cl_float parameters[4];
} fuzzy_gpu_variable_t;

typedef struct FuzzyGpuRule {
    cl_uint left;
    cl_uint right;
    cl_uint operator;
    cl_uint output;
} fuzzy_gpu_rule_t;

typedef enum FuzzyNeuronErrorFunction {
    MSE,
    HUBER,
    MAE
} fuzzy_error_fn_t;

_Static_assert(
    sizeof(fuzzy_gpu_variable_t) == 28u,
    "fuzzy_gpu_variable_t does not match the OpenCL ABI"
);

_Static_assert(
    sizeof(fuzzy_gpu_rule_t) == 16u,
    "fuzzy_gpu_rule_t does not match the OpenCL ABI"
);

typedef struct FuzzyGpuController {
    const fuzzy_gpu_variable_t *variables;
    size_t variable_count;

    const fuzzy_gpu_variable_t *outputs;
    size_t output_count;

    const fuzzy_gpu_rule_t *rules;
    size_t rule_count;

    fuzzy_logic_method_t logic_method;
    fuzzy_implication_method_t implication_method;
    fuzzy_aggregation_method_t aggregation_method;
    fuzzy_defuzz_method_t defuzz_method;

    float output_minimum;
    float output_maximum;
} fuzzy_gpu_controller_t;

typedef struct FuzzyGpuSweep {
    const char *filename;
    const char *title;
    const char *value_name;

    const fuzzy_gpu_controller_t *controller;

    const fuzzy_sweep_dimension_t *dimensions;
    size_t dimension_count;

    float defuzz_step;
} fuzzy_gpu_sweep_t;



#define FUZZY_GPU_VARIABLE(input_arg, shape_arg, hedge_arg, ...) \
    { \
        .input = (cl_uint)(input_arg), \
        .shape = (cl_uint)(shape_arg), \
        .hedge = (cl_float)(hedge_arg), \
        .parameters = { __VA_ARGS__ } \
    }

#define FUZZY_GPU_OUTPUT(shape_arg, hedge_arg, ...) \
    { \
        .input = 0u, \
        .shape = (cl_uint)(shape_arg), \
        .hedge = (cl_float)(hedge_arg), \
        .parameters = { __VA_ARGS__ } \
    }

#define FUZZY_GPU_RULE_INDEXED(left_arg, operator_arg, right_arg, output_arg) \
    { \
        .left = (cl_uint)(left_arg), \
        .right = (cl_uint)(right_arg), \
        .operator = (cl_uint)(operator_arg), \
        .output = (cl_uint)(output_arg) \
    }

#define FUZZY_GPU_RULE(left_name, operator_arg, right_name, output_name) \
    FUZZY_GPU_RULE_INDEXED( \
        left_name##_gpu_id, \
        operator_arg, \
        right_name##_gpu_id, \
        output_name##_gpu_id \
    )

#define FUZZY_GPU_CONTROLLER(name, variables_arg, outputs_arg, rules_arg, logic_arg, implication_arg, aggregation_arg, defuzz_arg, minimum_arg, maximum_arg) \
    static const fuzzy_gpu_controller_t name = { \
        .variables = (variables_arg), \
        .variable_count = sizeof(variables_arg) / sizeof((variables_arg)[0]), \
        .outputs = (outputs_arg), \
        .output_count = sizeof(outputs_arg) / sizeof((outputs_arg)[0]), \
        .rules = (rules_arg), \
        .rule_count = sizeof(rules_arg) / sizeof((rules_arg)[0]), \
        .logic_method = (logic_arg), \
        .implication_method = (implication_arg), \
        .aggregation_method = (aggregation_arg), \
        .defuzz_method = (defuzz_arg), \
        .output_minimum = (minimum_arg), \
        .output_maximum = (maximum_arg) \
    }

#define FUZZY_GPU_RULES(name, variables_arg, outputs_arg, logic_arg, implication_arg, aggregation_arg, defuzz_arg, minimum_arg, maximum_arg, ...) \
    static const fuzzy_gpu_rule_t name##_rules[] = { __VA_ARGS__ }; \
    static const fuzzy_gpu_controller_t name = { \
        .variables = (variables_arg), \
        .variable_count = sizeof(variables_arg) / sizeof((variables_arg)[0]), \
        .outputs = (outputs_arg), \
        .output_count = sizeof(outputs_arg) / sizeof((outputs_arg)[0]), \
        .rules = name##_rules, \
        .rule_count = sizeof(name##_rules) / sizeof(name##_rules[0]), \
        .logic_method = (logic_arg), \
        .implication_method = (implication_arg), \
        .aggregation_method = (aggregation_arg), \
        .defuzz_method = (defuzz_arg), \
        .output_minimum = (minimum_arg), \
        .output_maximum = (maximum_arg) \
    }

#define FUZZY_GPU_SWEEP(filename_arg, title_arg, value_name_arg, controller_arg, defuzz_step_arg, ...) \
    fuzzy_gpu_sweep( \
        &(const fuzzy_gpu_sweep_t) { \
            .filename = (filename_arg), \
            .title = (title_arg), \
            .value_name = (value_name_arg), \
            .controller = &(controller_arg), \
            .dimensions = (const fuzzy_sweep_dimension_t[]) { __VA_ARGS__ }, \
            .dimension_count = sizeof((const fuzzy_sweep_dimension_t[]) { __VA_ARGS__ }) / sizeof(fuzzy_sweep_dimension_t), \
            .defuzz_step = (defuzz_step_arg) \
        } \
    )


#define FUZZY_GPU_INTERPOLATION_SWEEP(filename_arg, title_arg, points_arg, ...) \
    fuzzy_gpu_interpolation_sweep( \
        &(const fuzzy_interpolation_sweep_t) { \
            .filename = (filename_arg), \
            .title = (title_arg), \
            .dimensions = (const fuzzy_sweep_dimension_t[]) { __VA_ARGS__ }, \
            .dimension_count = sizeof((const fuzzy_sweep_dimension_t[]) { __VA_ARGS__ }) / sizeof(fuzzy_sweep_dimension_t), \
            .points = (points_arg), \
            .point_count = sizeof(points_arg) / sizeof((points_arg)[0]) \
        } \
    )

#define TRAIN_FAIL(...) do { fprintf(stderr, __VA_ARGS__); exit(EXIT_FAILURE); } while (0)
#define TRAIN_CHECK(condition, ...) do { if (!(condition)) TRAIN_FAIL(__VA_ARGS__); } while (0)
#define TRAIN_MKDIR(path) TRAIN_CHECK(system("mkdir -p " path) == 0, "Failed to create %s.\n", path)
#define TRAIN_DATASET_LOAD(path, format, dataset) TRAIN_CHECK(fuzzy_neuron_dataset_load_csv((path), (format), (dataset)), "Failed to load %s.\n", path)
#define TRAIN_DATASET_FREE(dataset) fuzzy_neuron_dataset_free(dataset)
#define TRAIN_MODEL_SAVE(model, path) TRAIN_CHECK(FUZZY_NEURON_MODEL_SAVE((model), (path)), "Failed to save %s.\n", path)
#define TRAIN_MODEL_LOAD(model, path) TRAIN_CHECK(FUZZY_NEURON_MODEL_LOAD((model), (path)), "Failed to load %s.\n", path)
#define TRAIN_PREDICT(model, inputs, outputs) TRAIN_CHECK(FUZZY_NEURON_MODEL_PREDICT((model), (inputs), (outputs)), "Prediction failed.\n")
#define TRAIN_OPENCL_INIT(model, batch, path) TRAIN_CHECK(FUZZY_NEURON_MODEL_OPENCL_INIT((model), (batch), (path)), "OpenCL initialization failed.\n")
#define TRAIN_OPENCL_TRAIN(model, dataset, options, loss) TRAIN_CHECK(FUZZY_NEURON_MODEL_OPENCL_TRAIN((model), (dataset), (options), (loss)), "OpenCL training failed.\n")
#define TRAIN_PLOT(call, message) TRAIN_CHECK((call), "%s\n", (message))

#define TRAIN_HISTORY_INIT() do { \
    loss_history_capacity = (training_epochs + training_report_interval - 1u) / training_report_interval + 1u; \
    loss_history = malloc(loss_history_capacity * sizeof(*loss_history)); \
    loss_epoch_history = malloc(loss_history_capacity * sizeof(*loss_epoch_history)); \
    TRAIN_CHECK(loss_history != NULL && loss_epoch_history != NULL, "Failed to allocate loss history.\n"); \
    loss_history_count = 0u; \
} while (0)

#define TRAIN_HISTORY_PUSH(epoch_value, loss_value) do { \
    TRAIN_CHECK(loss_history_count < loss_history_capacity, "Loss history capacity exceeded.\n"); \
    loss_epoch_history[loss_history_count] = (epoch_value); \
    loss_history[loss_history_count] = (loss_value); \
    loss_history_count++; \
} while (0)

#define TRAIN_HISTORY_FREE() do { \
    free(loss_history); \
    free(loss_epoch_history); \
    loss_history = NULL; \
    loss_epoch_history = NULL; \
    loss_history_count = 0u; \
    loss_history_capacity = 0u; \
} while (0)

#define FUZZY_NEURON_XAVIER_INIT(model_pointer, seed_value) \
    do \
    { \
        fuzzy_neuron_network_t *fuzzy_neuron_xavier_model__ = (model_pointer); \
        unsigned int fuzzy_neuron_xavier_state__ = (unsigned int)(seed_value); \
        size_t fuzzy_neuron_xavier_layer__; \
        if (fuzzy_neuron_xavier_model__ == NULL || !fuzzy_neuron_xavier_model__->compiled) \
        { \
            abort(); \
        } \
        for (fuzzy_neuron_xavier_layer__ = 0u; fuzzy_neuron_xavier_layer__ < fuzzy_neuron_xavier_model__->layer_count; fuzzy_neuron_xavier_layer__++) \
        { \
            fuzzy_neuron_layer_t *fuzzy_neuron_xavier_current__ = &fuzzy_neuron_xavier_model__->layers[fuzzy_neuron_xavier_layer__]; \
            size_t fuzzy_neuron_xavier_source_count__ = fuzzy_neuron_xavier_layer__ == 0u ? fuzzy_neuron_xavier_model__->rule_count : fuzzy_neuron_xavier_model__->layers[fuzzy_neuron_xavier_layer__ - 1u].count; \
            size_t fuzzy_neuron_xavier_destination_count__ = fuzzy_neuron_xavier_current__->count; \
            float fuzzy_neuron_xavier_limit__; \
            size_t fuzzy_neuron_xavier_destination__; \
            if (fuzzy_neuron_xavier_source_count__ == 0u || fuzzy_neuron_xavier_destination_count__ == 0u) \
            { \
                abort(); \
            } \
            fuzzy_neuron_xavier_limit__ = sqrtf(6.0f / (float)(fuzzy_neuron_xavier_source_count__ + fuzzy_neuron_xavier_destination_count__)); \
            for (fuzzy_neuron_xavier_destination__ = 0u; fuzzy_neuron_xavier_destination__ < fuzzy_neuron_xavier_destination_count__; fuzzy_neuron_xavier_destination__++) \
            { \
                size_t fuzzy_neuron_xavier_source__; \
                fuzzy_neuron_xavier_model__->biases[fuzzy_neuron_xavier_current__->bias_offset + fuzzy_neuron_xavier_destination__] = 0.0f; \
                for (fuzzy_neuron_xavier_source__ = 0u; fuzzy_neuron_xavier_source__ < fuzzy_neuron_xavier_source_count__; fuzzy_neuron_xavier_source__++) \
                { \
                    float fuzzy_neuron_xavier_unit__; \
                    fuzzy_neuron_xavier_state__ = fuzzy_neuron_xavier_state__ * 1664525u + 1013904223u; \
                    fuzzy_neuron_xavier_unit__ = (float)(fuzzy_neuron_xavier_state__ & 0x00ffffffu) / 16777215.0f; \
                    fuzzy_neuron_xavier_model__->weights[fuzzy_neuron_xavier_current__->weight_offset + fuzzy_neuron_xavier_destination__ * fuzzy_neuron_xavier_source_count__ + fuzzy_neuron_xavier_source__] = -fuzzy_neuron_xavier_limit__ + 2.0f * fuzzy_neuron_xavier_limit__ * fuzzy_neuron_xavier_unit__; \
                } \
            } \
        } \
    } while (0)

#define FUZZY_NEURON_LOSS_PLOTTER(function_name, loss_values, epoch_values, history_count, reference_loss) \
    static float function_name(float epoch_value) \
    { \
        size_t fuzzy_neuron_loss_index__; \
        size_t fuzzy_neuron_loss_selected__ = 0u; \
        if ((history_count) == 0u) \
        { \
            return 0.0f; \
        } \
        if ((loss_values) == NULL || (epoch_values) == NULL || !isfinite(reference_loss) || (reference_loss) <= 0.0) \
        { \
            abort(); \
        } \
        for (fuzzy_neuron_loss_index__ = 0u; fuzzy_neuron_loss_index__ < (history_count); fuzzy_neuron_loss_index__++) \
        { \
            if ((float)(epoch_values)[fuzzy_neuron_loss_index__] <= epoch_value) \
            { \
                fuzzy_neuron_loss_selected__ = fuzzy_neuron_loss_index__; \
            } \
        } \
        if (!isfinite((loss_values)[fuzzy_neuron_loss_selected__])) \
        { \
            abort(); \
        } \
        return (float)((loss_values)[fuzzy_neuron_loss_selected__] / (reference_loss)); \
    }

bool fuzzy_gpu_sweep(const fuzzy_gpu_sweep_t *sweep);

bool fuzzy_gpu_interpolation_sweep(const fuzzy_interpolation_sweep_t *sweep);

#endif /* FUZZY_OPENCL */

#define FUZZY_INTERPOLATION_SWEEP(filename_arg, title_arg, points_arg, ...) fuzzy_interpolation_sweep(&(const fuzzy_interpolation_sweep_t){.filename = (filename_arg), .title = (title_arg), .dimensions = (const fuzzy_sweep_dimension_t[]){__VA_ARGS__}, .dimension_count = sizeof((const fuzzy_sweep_dimension_t[]){__VA_ARGS__}) / sizeof(fuzzy_sweep_dimension_t), .points = (points_arg), .point_count = sizeof(points_arg) / sizeof((points_arg)[0])})

#define FUZZY_NEURON_INTERPOLATION_SWEEP(filename_arg, title_arg, points_arg, value_minimum_arg, value_maximum_arg, ...) fuzzy_neuron_interpolation_sweep(&(const fuzzy_interpolation_sweep_t){.filename = (filename_arg), .title = (title_arg), .dimensions = (const fuzzy_sweep_dimension_t[]){__VA_ARGS__}, .dimension_count = sizeof((const fuzzy_sweep_dimension_t[]){__VA_ARGS__}) / sizeof(fuzzy_sweep_dimension_t), .points = (points_arg), .point_count = sizeof(points_arg) / sizeof((points_arg)[0])}, (value_minimum_arg), (value_maximum_arg))

#define FUZZY_INTERPOLATION_SLICES(filename_arg, title_arg, points_arg, ...) fuzzy_interpolation_slices(&(const fuzzy_interpolation_sweep_t){.filename = (filename_arg), .title = (title_arg), .dimensions = (const fuzzy_sweep_dimension_t[]){__VA_ARGS__}, .dimension_count = sizeof((const fuzzy_sweep_dimension_t[]){__VA_ARGS__}) / sizeof(fuzzy_sweep_dimension_t), .points = (points_arg), .point_count = sizeof(points_arg) / sizeof((points_arg)[0])})

/* PLOTTING ADAPTER FOR COMPRESSED SYNTAX */
#define SERIES(fn, color) FUZZY_PLOT_FUNCTION_NAMED(#fn, color, fn)
#define PLOT(path, title, max, step, ...) \
    FUZZY_PLOT(path, title, 0.0f, max, step, __VA_ARGS__)

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

bool fuzzy_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep
);

bool fuzzy_neuron_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep,
    float value_minimum,
    float value_maximum
);

bool fuzzy_interpolation_slices(
    const fuzzy_interpolation_sweep_t *sweep
);

#ifdef FUZZY_OPENCL

bool fuzzy_gpu_sweep(
    const fuzzy_gpu_sweep_t *sweep
);

bool fuzzy_gpu_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep
);

#endif /* FUZZY_OPENCL */

#endif /* FUZZY_8051 */




/*
 * Implementation section.
 *
 * Define FUZZY_IMPLEMENTATION in exactly one .c file
 * before including fuzzy.h.
 */

#ifdef FUZZY_IMPLEMENTATION

/*
 * Keep a membership value inside the valid fuzzy range.
 */
static float fuzzy_clamp(float value)
{
    if (value < LEVEL_LO) return LEVEL_LO;

    if (value > LEVEL_HI) return LEVEL_HI;

    return value;
}

/*
 * Keep a membership value inside the valid fuzzy range.
 */
float fuzzy_not(float membership)
{
    return LEVEL_HI - fuzzy_clamp(membership);
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
    membership =
        fuzzy_clamp( membership
        );

#ifdef FUZZY_8051

    float result =
        LEVEL_HI;

    if (hedge == 0u) {
        hedge = 1u;
    }

    while (hedge > 0u) {
        result *= membership;

        hedge--;
    }

    return fuzzy_clamp(
        result
    );

#else

    if (hedge <= 0.0f) {
        hedge =
            1.0f;
    }

    return powf(
        membership,
        hedge
    );

#endif /* FUZZY_8051 */
}

/*
 * Internal fuzzy AND implementation.
 *
 * FUZZY_LOGIC_STANDARD:
 *     Minimum.
 *
 * FUZZY_LOGIC_ALGEBRAIC:
 *     Product.
 *
 * FUZZY_LOGIC_BOUNDED:
 *     max(0, a + b - 1).
 */
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
        args == NULL ||
        count == 0u
    ) {
        return LEVEL_HI;
    }

    if (
        method != FUZZY_LOGIC_STANDARD &&
        method != FUZZY_LOGIC_ALGEBRAIC &&
        method != FUZZY_LOGIC_BOUNDED
    ) {
        return LEVEL_LO;
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
                    LEVEL_HI;

                if (result < LEVEL_LO) {
                    result = LEVEL_LO;
                }
                break;

            default:
                return LEVEL_LO;
        }
    }

    return fuzzy_clamp(
        result
    );
}


/*
 * Internal fuzzy OR implementation.
 *
 * FUZZY_LOGIC_STANDARD:
 *     Maximum.
 *
 * FUZZY_LOGIC_ALGEBRAIC:
 *     a + b - a*b.
 *
 * FUZZY_LOGIC_BOUNDED:
 *     min(1, a + b).
 */
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
        args == NULL ||
        count == 0u
    ) {
        return LEVEL_LO;
    }

    if (
        method != FUZZY_LOGIC_STANDARD &&
        method != FUZZY_LOGIC_ALGEBRAIC &&
        method != FUZZY_LOGIC_BOUNDED
    ) {
        return LEVEL_LO;
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

                if (result > LEVEL_HI) {
                    result = LEVEL_HI;
                }
                break;

            default:
                return LEVEL_LO;
        }
    }

    return fuzzy_clamp(
        result
    );
}



/*
 * Array-based Sugeno weighted-average inference.
 *
 * The array contains alternating:
 *
 *     firing strength, consequent
 */
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
        values == NULL ||
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

    if (firing_sum <= LEVEL_LO) {
        return 0.0f;
    }

    return weighted_sum /
        firing_sum;
}


/*
 * Array-based Sugeno weighted-sum inference.
 *
 * The array contains alternating:
 *
 *     firing strength, consequent
 */
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
        values == NULL ||
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


/*
 * Linear ramp membership function.
 */
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

#ifndef FUZZY_8051

float fuzzy_interpolate_membership_array(const float *inputs, size_t dimension_count, const fuzzy_point_t *points, size_t point_count)
{
    size_t point;
    size_t dimension;
    float distance_squared;
    float difference;
    float weight;
    float weighted_membership = 0.0f;
    float weight_sum = 0.0f;

    if (inputs == NULL || points == NULL || dimension_count == 0u || point_count == 0u) {
        return LEVEL_LO;
    }

    for (point = 0u; point < point_count; point++) {
        if (points[point].coordinates == NULL || points[point].dimension_count != dimension_count) {
            return LEVEL_LO;
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

#endif /* FUZZY_8051 */

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
        result = LEVEL_LO;
    }
    else if (value == b) {
        result = LEVEL_HI;
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
        result = LEVEL_LO;
    }
    else if (
        value >= b &&
        value <= c
    ) {
        result = LEVEL_HI;
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

#ifndef FUZZY_8051

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
        result = LEVEL_LO;
    }
    else if (value >= upper_boundary) {
        result = LEVEL_HI;
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
                LEVEL_HI -
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
        result = LEVEL_LO;
    }
    else if (value <= lower_boundary) {
        result = LEVEL_HI;
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
                LEVEL_HI -
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
        return LEVEL_LO;
    }

    if (
        value <= a ||
        value >= d
    ) {
        result = LEVEL_LO;
    }
    else if (
        value >= b &&
        value <= c
    ) {
        result = LEVEL_HI;
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
                LEVEL_HI -
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
                LEVEL_HI -
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
        result = LEVEL_LO;
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
        return LEVEL_LO;
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
        result = LEVEL_HI;
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
        result = LEVEL_LO;
    }
    else {
        normalized =
            fabsf(
                (value - center) /
                (width / 2.0f)
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
        LEVEL_HI /
        (
            LEVEL_HI +
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
        LEVEL_HI /
        (
            LEVEL_HI +
            expf(
                -slope_1 *
                (value - center_1)
            )
        );

    sigmoid_2 =
        LEVEL_HI /
        (
            LEVEL_HI +
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
        LEVEL_HI /
        (
            LEVEL_HI +
            expf(
                -slope_1 *
                (value - center_1)
            )
        );

    sigmoid_2 =
        LEVEL_HI /
        (
            LEVEL_HI +
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

#endif /* FUZZY_8051 */

float fuzzy_function_array(
    fuzzy_shape_t shape,
    float value,
    fuzzy_hedge_t hedge,
    size_t parameter_count,
    const float *parameters
)
{
    if (parameters == NULL) {
        return LEVEL_LO;
    }

    switch (shape) {
        case FUZZY_SHAPE_RAMP:
            if (parameter_count != 3u) {
                return LEVEL_LO;
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
                return LEVEL_LO;
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
                return LEVEL_LO;
            }

            return fuzzy_trapezoid(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );

#ifndef FUZZY_8051

        case FUZZY_SHAPE_SMF:
            if (parameter_count != 2u) {
                return LEVEL_LO;
            }

            return fuzzy_smf(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_ZMF:
            if (parameter_count != 2u) {
                return LEVEL_LO;
            }

            return fuzzy_zmf(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_PIMF:
            if (parameter_count != 4u) {
                return LEVEL_LO;
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
                return LEVEL_LO;
            }

            return fuzzy_gaussian(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_GAUSSIAN2:
            if (parameter_count != 4u) {
                return LEVEL_LO;
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
                return LEVEL_LO;
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
                return LEVEL_LO;
            }

            return fuzzy_sigmoid(
                parameters[0],
                parameters[1],
                value,
                hedge
            );

        case FUZZY_SHAPE_DSIGMOID:
            if (parameter_count != 4u) {
                return LEVEL_LO;
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
                return LEVEL_LO;
            }

            return fuzzy_psigmoid(
                parameters[0],
                parameters[1],
                parameters[2],
                parameters[3],
                value,
                hedge
            );

#else

        case FUZZY_SHAPE_SMF:
        case FUZZY_SHAPE_ZMF:
        case FUZZY_SHAPE_PIMF:
        case FUZZY_SHAPE_GAUSSIAN:
        case FUZZY_SHAPE_GAUSSIAN2:
        case FUZZY_SHAPE_BELL:
        case FUZZY_SHAPE_SIGMOID:
        case FUZZY_SHAPE_DSIGMOID:
        case FUZZY_SHAPE_PSIGMOID:
            return LEVEL_LO;

#endif /* FUZZY_8051 */

        default:
            return LEVEL_LO;
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
        rules == NULL ||
        output_function == NULL
    ) {
        return false;
    }

    if (rules->count >= FUZZY_MAX_RULES) {
        return false;
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

#endif /* FUZZY_8051 */

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
            return LEVEL_LO;
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
            return LEVEL_LO;
    }
}

/*
 * Calculate the aggregated Mamdani output height at one
 * sampled output value.
 */
static float fuzzy_rules_aggregated_height(
    const fuzzy_rules_t *rules,
    float value,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    float aggregated_height;
    float output_membership;
    float implied_height;
    size_t index;

    aggregated_height =
        LEVEL_LO;

    for (
        index = 0u;
        index < rules->count;
        index++
    ) {
        output_membership =
            fuzzy_clamp(
                rules->rules[index]
                    .output_function(value)
            );

        implied_height =
            fuzzy_implication(
                implication_method,
                rules->rules[index].value,
                output_membership
            );

        aggregated_height =
            fuzzy_aggregation(
                aggregation_method,
                aggregated_height,
                implied_height
            );
    }

    return fuzzy_clamp(
        aggregated_height
    );
}


/*
 * Internal result used by MOM, SOM and LOM.
 */
typedef struct FuzzyMaximumResult {
    float height;
    float smallest_position;
    float largest_position;
    float position_sum;
    size_t position_count;
} fuzzy_maximum_result_t;


/*
 * Find every sampled position having the maximum aggregated
 * Mamdani output height.
 */

static void fuzzy_rules_maximum_result(
    fuzzy_maximum_result_t *result,
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    float value;
    float height;

    result->height =
        LEVEL_LO;

    result->smallest_position =
        lower;

    result->largest_position =
        lower;

    result->position_sum =
        0.0f;

    result->position_count =
        0u;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        height =
            fuzzy_rules_aggregated_height(
                rules,
                value,
                implication_method,
                aggregation_method
            );

        if (
            result->position_count == 0u ||
            height > result->height
        ) {
            result->height =
                height;

            result->smallest_position =
                value;

            result->largest_position =
                value;

            result->position_sum =
                value;

            result->position_count =
                1u;
        }
        else if (
            height ==
            result->height
        ) {
            result->largest_position =
                value;

            result->position_sum +=
                value;

            result->position_count++;
        }
    }
}

 /*
 * Center of gravity.
 *
 * Operates on the final aggregated Mamdani output.
 */
float fuzzy_rules_defuzzify_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    float weighted_sum;
    float height_sum;
    float value;
    float height;

    weighted_sum =
        0.0f;

    height_sum =
        0.0f;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        height =
            fuzzy_rules_aggregated_height(
                rules,
                value,
                implication_method,
                aggregation_method
            );

        weighted_sum +=
            value *
            height;

        height_sum +=
            height;
    }

    if (height_sum <= LEVEL_LO) {
        return 0.0f;
    }

    return weighted_sum /
        height_sum;
}


/*
 * Bisector of area.
 *
 * The first pass calculates the complete aggregated area.
 * The second pass finds the sampled output position where
 * half of that area has been accumulated.
 */
float fuzzy_rules_defuzzify_boa(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    float total_area;
    float half_area;
    float accumulated_area;
    float value;

    total_area =
        0.0f;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        total_area +=
            fuzzy_rules_aggregated_height(
                rules,
                value,
                implication_method,
                aggregation_method
            );
    }

    if (total_area <= LEVEL_LO) {
        return 0.0f;
    }

    half_area =
        total_area /
        2.0f;

    accumulated_area =
        0.0f;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        accumulated_area +=
            fuzzy_rules_aggregated_height(
                rules,
                value,
                implication_method,
                aggregation_method
            );

        if (
            accumulated_area >=
            half_area
        ) {
            return value;
        }
    }

    return upper;
}


/*
 * Center of sums.
 *
 * Every implied rule output is accumulated independently.
 * Overlapping rule outputs are therefore counted once for
 * every rule contributing to the overlap.
 *
 * Aggregation is intentionally not used.
 */
float fuzzy_rules_defuzzify_cos(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method
)
{
    float weighted_sum;
    float height_sum;
    float value;
    float output_membership;
    float implied_height;
    size_t index;

    weighted_sum =
        0.0f;

    height_sum =
        0.0f;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        for (
            index = 0u;
            index < rules->count;
            index++
        ) {
            output_membership =
                fuzzy_clamp(
                    rules->rules[index]
                        .output_function(value)
                );

            implied_height =
                fuzzy_implication(
                    implication_method,
                    rules->rules[index].value,
                    output_membership
                );

            weighted_sum +=
                value *
                implied_height;

            height_sum +=
                implied_height;
        }
    }

    if (height_sum <= LEVEL_LO) {
        return 0.0f;
    }

    return weighted_sum /
        height_sum;
}


/*
 * Mean of maximum.
 */
float fuzzy_rules_defuzzify_mom(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    fuzzy_maximum_result_t result;

    fuzzy_rules_maximum_result(
        &result,
        rules,
        lower,
        upper,
        step,
        implication_method,
        aggregation_method
    );

    if (
        result.position_count == 0u ||
        result.height <= LEVEL_LO
    ) {
        return 0.0f;
    }

    return result.position_sum /
        (float)result.position_count;
}


/*
 * Smallest of maximum.
 */
float fuzzy_rules_defuzzify_som(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    fuzzy_maximum_result_t result;

    fuzzy_rules_maximum_result(
        &result,
        rules,
        lower,
        upper,
        step,
        implication_method,
        aggregation_method
    );

    if (
        result.position_count == 0u ||
        result.height <= LEVEL_LO
    ) {
        return 0.0f;
    }

    return result.smallest_position;
}


/*
 * Largest of maximum.
 */
float fuzzy_rules_defuzzify_lom(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method
)
{
    fuzzy_maximum_result_t result;

    fuzzy_rules_maximum_result(
        &result,
        rules,
        lower,
        upper,
        step,
        implication_method,
        aggregation_method
    );

    if (
        result.position_count == 0u ||
        result.height <= LEVEL_LO
    ) {
        return 0.0f;
    }

    return result.largest_position;
}


/*
 * Select and call one low-level defuzzification function.
 */
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
    if (
        rules == NULL ||
        rules->count == 0u ||
        lower > upper ||
        step <= 0.0f
    ) {
        return 0.0f;
    }

    switch (defuzz_method) {
        case FUZZY_DEFUZZ_COG:
            return fuzzy_rules_defuzzify_cog(
                rules,
                lower,
                upper,
                step,
                implication_method,
                aggregation_method
            );

        case FUZZY_DEFUZZ_BOA:
            return fuzzy_rules_defuzzify_boa(
                rules,
                lower,
                upper,
                step,
                implication_method,
                aggregation_method
            );

        case FUZZY_DEFUZZ_COS:
            return fuzzy_rules_defuzzify_cos(
                rules,
                lower,
                upper,
                step,
                implication_method
            );

        case FUZZY_DEFUZZ_MOM:
            return fuzzy_rules_defuzzify_mom(
                rules,
                lower,
                upper,
                step,
                implication_method,
                aggregation_method
            );

        case FUZZY_DEFUZZ_SOM:
            return fuzzy_rules_defuzzify_som(
                rules,
                lower,
                upper,
                step,
                implication_method,
                aggregation_method
            );

        case FUZZY_DEFUZZ_LOM:
            return fuzzy_rules_defuzzify_lom(
                rules,
                lower,
                upper,
                step,
                implication_method,
                aggregation_method
            );

        default:
            return 0.0f;
    }
}


/*
 * Standard Mamdani wrapper using minimum implication and
 * maximum aggregation.
 */
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
    return fuzzy_rules_defuzzify_cog(
        rules,
        lower,
        upper,
        step,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX
    );
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

    if (written < 0 || (size_t)written >= sizeof(plot_filename)) return false;
    

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

    size_t sample_count = (size_t)ceilf((upper - lower) / step);

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
        float value = lower + (float)sample * step;

        if (value > upper) value = upper;

        float aggregated_height = LEVEL_LO;

        for (size_t i = 0; i < rules->count; i++) {
            float output_membership =     rules->rules[i].output_function(value);

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

    /*
     * Draw a vertical line at the calculated COG.
     */
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

    return true;
}

static void fuzzy_plot_write_text(FILE *file, const char *text)
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

    if (plot->file == NULL) return false;

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

    printf(
        "Membership plot written to %s\n",
        plot_filename
    );

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
,
    bool fixed_value_range,
    float fixed_value_minimum,
    float fixed_value_maximum
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
        fprintf(stderr, 
            "COG sweep SVG filename is too long.\n"
        );

        return false;
    }

    FILE *file = fopen(
        svg_filename,
        "w"
    );

    if (file == NULL) {
        fprintf(stderr, 
            "Failed to open %s.\n",
            svg_filename
        );

        return false;
    }


    float minimum_cog;
    float maximum_cog;
    float cog_range;

    if (fixed_value_range)
    {
        minimum_cog = fixed_value_minimum;
        maximum_cog = fixed_value_maximum;
    }
    else
    {
        minimum_cog = parsed_cog_values[0];
        maximum_cog = parsed_cog_values[0];

        for (size_t point = 1u; point < total_points; point++)
        {
            if (parsed_cog_values[point] < minimum_cog) minimum_cog = parsed_cog_values[point];
            if (parsed_cog_values[point] > maximum_cog) maximum_cog = parsed_cog_values[point];
        }
    }

    cog_range = maximum_cog - minimum_cog;

    if (!(cog_range > 0.0f))
    {
        if (fixed_value_range)
        {
            fclose(file);
            fprintf(stderr, "COG sweep fixed plot range is invalid.\n");
            return false;
        }

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
            : "N-Dimensional Sweep"
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
        /*
         * Dynamic multidimensional heatmap.
         *
         * Only x_count * y_count SVG cells are created.
         * All COG values are embedded as JavaScript data.
         *
         * Slider movement recalculates flat point indices
         * and repaints the existing heatmap cells.
         */
        const size_t x_count = sample_counts[0];

        const size_t y_count = sample_counts[1];

        const size_t cell_count = x_count * y_count;

        float cell_width = (float)plot_width / (float)x_count;

        float cell_height = (float)plot_height / (float)y_count;

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
            "const fuzzyValueName=\"%s\";\n",
            sweep->value_name
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
            "text+', '+fuzzyValueName+' = '+cog.toFixed(5);\n"
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
        fprintf(stderr, 
            "Failed while writing %s.\n",
            svg_filename
        );

        fclose(file);

        return false;
    }

    if (fclose(file) != 0) {
        fprintf(stderr, 
            "Failed to finish writing %s.\n",
            svg_filename
        );

        return false;
    }

    printf(
        "%s sweep SVG written to %s\n",
        sweep->value_name,
        svg_filename
    );

    return true;
}

#ifdef FUZZY_OPENCL

typedef struct FuzzyGpuHarness {
    cl_context context;
    cl_command_queue queue;
    cl_program program;
    cl_kernel kernel;
    cl_device_id device;
} fuzzy_gpu_harness_t;

static const char *fuzzy_gpu_interpolation_kernel_source =
    "__kernel void fuzzy_gpu_interpolation_kernel(\n"
    "    __global const float *inputs,\n"
    "    __global float *outputs,\n"
    "    __global const float *point_coordinates,\n"
    "    __global const float *point_memberships,\n"
    "    const uint sweep_point_count,\n"
    "    const uint dimension_count,\n"
    "    const uint interpolation_point_count)\n"
    "{\n"
    "    const uint id = get_global_id(0);\n"
    "\n"
    "    if (id >= sweep_point_count) return;\n"
    "\n"
    "    const uint input_base = id * dimension_count;\n"
    "\n"
    "    float weighted_membership = 0.0f;\n"
    "    float weight_sum = 0.0f;\n"
    "\n"
    "    for (\n"
    "        uint point = 0u;\n"
    "        point < interpolation_point_count;\n"
    "        point++\n"
    "    ) {\n"
    "        const uint point_base = point * dimension_count;\n"
    "        float distance_squared = 0.0f;\n"
    "\n"
    "        for (\n"
    "            uint dimension = 0u;\n"
    "            dimension < dimension_count;\n"
    "            dimension++\n"
    "        ) {\n"
    "            const float difference =\n"
    "                inputs[input_base + dimension] -\n"
    "                point_coordinates[point_base + dimension];\n"
    "\n"
    "            distance_squared +=\n"
    "                difference * difference;\n"
    "        }\n"
    "\n"
    "        const float membership = clamp(\n"
    "            point_memberships[point],\n"
    "            0.0f,\n"
    "            1.0f\n"
    "        );\n"
    "\n"
    "        if (distance_squared == 0.0f) {\n"
    "            outputs[id] = membership;\n"
    "            return;\n"
    "        }\n"
    "\n"
    "        const float weight =\n"
    "            1.0f / distance_squared;\n"
    "\n"
    "        weighted_membership +=\n"
    "            weight * membership;\n"
    "\n"
    "        weight_sum +=\n"
    "            weight;\n"
    "    }\n"
    "\n"
    "    outputs[id] = clamp(\n"
    "        weighted_membership / weight_sum,\n"
    "        0.0f,\n"
    "        1.0f\n"
    "    );\n"
    "}\n";

static const char *fuzzy_gpu_kernel_source =
    "typedef struct {\n"
    "    uint input;\n"
    "    uint shape;\n"
    "    float hedge;\n"
    "    float parameters[4];\n"
    "} fuzzy_gpu_variable_t;\n"

    "typedef struct {\n"
    "    uint left;\n"
    "    uint right;\n"
    "    uint operator;\n"
    "    uint output;\n"
    "} fuzzy_gpu_rule_t;\n"

    "float fuzzy_gpu_shape(uint shape,float value,float4 p)\n"
    "{\n"
    "    switch(shape){\n"

    "        case 0u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const int rising=p.z!=0.0f;\n"
    "            if(a>=b)return 0.0f;\n"
    "            if(value<=a)return rising?0.0f:1.0f;\n"
    "            if(value>=b)return rising?1.0f:0.0f;\n"
    "            const float t=(value-a)/(b-a);\n"
    "            return rising?t:1.0f-t;\n"
    "        }\n"

    "        case 1u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const float c=p.z;\n"
    "            if(a>=b||b>=c||value<=a||value>=c)return 0.0f;\n"
    "            if(value==b)return 1.0f;\n"
    "            if(value<b)return(value-a)/(b-a);\n"
    "            return(c-value)/(c-b);\n"
    "        }\n"

    "        case 2u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const float c=p.z;\n"
    "            const float d=p.w;\n"
    "            if(a>=b||b>c||c>=d||value<=a||value>=d)return 0.0f;\n"
    "            if(value>=b&&value<=c)return 1.0f;\n"
    "            if(value<b)return(value-a)/(b-a);\n"
    "            return(d-value)/(d-c);\n"
    "        }\n"

    "        case 3u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const float middle=(a+b)*0.5f;\n"
    "            float ratio;\n"
    "            if(a>=b||value<=a)return 0.0f;\n"
    "            if(value>=b)return 1.0f;\n"
    "            if(value<=middle){\n"
    "                ratio=(value-a)/(b-a);\n"
    "                return 2.0f*ratio*ratio;\n"
    "            }\n"
    "            ratio=(b-value)/(b-a);\n"
    "            return 1.0f-2.0f*ratio*ratio;\n"
    "        }\n"

    "        case 4u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const float middle=(a+b)*0.5f;\n"
    "            float ratio;\n"
    "            if(a>=b||value>=b)return 0.0f;\n"
    "            if(value<=a)return 1.0f;\n"
    "            if(value<=middle){\n"
    "                ratio=(value-a)/(b-a);\n"
    "                return 1.0f-2.0f*ratio*ratio;\n"
    "            }\n"
    "            ratio=(b-value)/(b-a);\n"
    "            return 2.0f*ratio*ratio;\n"
    "        }\n"

    "        case 5u:{\n"
    "            const float mean=p.x;\n"
    "            const float deviation=p.y;\n"
    "            if(deviation<=0.0f)return 0.0f;\n"
    "            const float difference=value-mean;\n"
    "            return exp(-(difference*difference)/(2.0f*deviation*deviation));\n"
    "        }\n"

    "        case 6u:{\n"
    "            const float width=p.x;\n"
    "            const float slope=p.y;\n"
    "            const float centre=p.z;\n"
    "            if(width==0.0f)return 0.0f;\n"
    "            const float normalized=fabs((value-centre)/(width*0.5f));\n"
    "            return 1.0f/(1.0f+pow(normalized,2.0f*slope));\n"
    "        }\n"

    "        case 7u:\n"
    "            return 1.0f/(1.0f+exp(-p.x*(value-p.y)));\n"

    "        case 8u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const float c=p.z;\n"
    "            const float d=p.w;\n"
    "            float middle;\n"
    "            float ratio;\n"
    "            if(a>=b||b>c||c>=d||value<=a||value>=d)return 0.0f;\n"
    "            if(value>=b&&value<=c)return 1.0f;\n"
    "            if(value<b){\n"
    "                middle=(a+b)*0.5f;\n"
    "                if(value<=middle){\n"
    "                    ratio=(value-a)/(b-a);\n"
    "                    return 2.0f*ratio*ratio;\n"
    "                }\n"
    "                ratio=(b-value)/(b-a);\n"
    "                return 1.0f-2.0f*ratio*ratio;\n"
    "            }\n"
    "            middle=(c+d)*0.5f;\n"
    "            if(value<=middle){\n"
    "                ratio=(value-c)/(d-c);\n"
    "                return 1.0f-2.0f*ratio*ratio;\n"
    "            }\n"
    "            ratio=(d-value)/(d-c);\n"
    "            return 2.0f*ratio*ratio;\n"
    "        }\n"

    "        case 9u:{\n"
    "            const float first=1.0f/(1.0f+exp(-p.x*(value-p.y)));\n"
    "            const float second=1.0f/(1.0f+exp(-p.z*(value-p.w)));\n"
    "            return first-second;\n"
    "        }\n"

    "        case 10u:{\n"
    "            const float first=1.0f/(1.0f+exp(-p.x*(value-p.y)));\n"
    "            const float second=1.0f/(1.0f+exp(-p.z*(value-p.w)));\n"
    "            return first*second;\n"
    "        }\n"

    "        case 11u:{\n"
    "            const float mean1=p.x;\n"
    "            const float deviation1=p.y;\n"
    "            const float mean2=p.z;\n"
    "            const float deviation2=p.w;\n"
    "            float difference;\n"
    "            if(deviation1<=0.0f||deviation2<=0.0f||mean1>mean2)return 0.0f;\n"
    "            if(value<mean1){\n"
    "                difference=value-mean1;\n"
    "                return exp(-(difference*difference)/(2.0f*deviation1*deviation1));\n"
    "            }\n"
    "            if(value<=mean2)return 1.0f;\n"
    "            difference=value-mean2;\n"
    "            return exp(-(difference*difference)/(2.0f*deviation2*deviation2));\n"
    "        }\n"

    "        case 12u:{\n"
    "            const float a=p.x;\n"
    "            const float b=p.y;\n"
    "            const float c=p.z;\n"
    "            if(a>=b||b>=c||value<=a||value>=c)return 0.0f;\n"
    "            if(value<=b)return(value-a)/(b-a);\n"
    "            return(c-value)/(c-b);\n"
    "        }\n"

    "        default:\n"
    "            return 0.0f;\n"
    "    }\n"
    "}\n"

    "float fuzzy_gpu_membership(fuzzy_gpu_variable_t variable,float value)\n"
    "{\n"
    "    const float membership=fuzzy_gpu_shape(\n"
    "        variable.shape,\n"
    "        value,\n"
    "        vload4(0,variable.parameters)\n"
    "    );\n"
    "    const float hedge=variable.hedge>0.0f\n"
    "        ? variable.hedge\n"
    "        : 1.0f;\n"
    "    return pow(clamp(membership,0.0f,1.0f),hedge);\n"
    "}\n"

    "float fuzzy_gpu_and(uint method,float left,float right)\n"
    "{\n"
    "    switch(method){\n"
    "        case 1u:return left*right;\n"
    "        case 2u:return fmax(0.0f,left+right-1.0f);\n"
    "        default:return fmin(left,right);\n"
    "    }\n"
    "}\n"

    "float fuzzy_gpu_or(uint method,float left,float right)\n"
    "{\n"
    "    switch(method){\n"
    "        case 1u:return left+right-left*right;\n"
    "        case 2u:return fmin(1.0f,left+right);\n"
    "        default:return fmax(left,right);\n"
    "    }\n"
    "}\n"

    "float fuzzy_gpu_implication(uint method,float activation,float membership)\n"
    "{\n"
    "    return method==1u\n"
    "        ? activation*membership\n"
    "        : fmin(activation,membership);\n"
    "}\n"

    "float fuzzy_gpu_aggregation(uint method,float aggregate,float implied)\n"
    "{\n"
    "    switch(method){\n"
    "        case 1u:return aggregate+implied-aggregate*implied;\n"
    "        case 2u:return fmin(1.0f,aggregate+implied);\n"
    "        default:return fmax(aggregate,implied);\n"
    "    }\n"
    "}\n"

    "__kernel void fuzzy_gpu_sweep_kernel(\n"
    "    __global const float *inputs,\n"
    "    __global float *results,\n"
    "    __global const fuzzy_gpu_variable_t *variables,\n"
    "    __global const fuzzy_gpu_variable_t *output_variables,\n"
    "    __global const fuzzy_gpu_rule_t *rules,\n"
    "    const uint point_count,\n"
    "    const uint dimension_count,\n"
    "    const uint variable_count,\n"
    "    const uint output_count,\n"
    "    const uint rule_count,\n"
    "    const float defuzz_step,\n"
    "    const float output_minimum,\n"
    "    const float output_maximum,\n"
    "    const uint logic_method,\n"
    "    const uint implication_method,\n"
    "    const uint aggregation_method,\n"
    "    const uint defuzz_method)\n"
    "{\n"
    "    const uint id=get_global_id(0);\n"
    "    if(id>=point_count)return;\n"

    "    const uint base=id*dimension_count;\n"
    "    float memberships[32];\n"
    "    float activations[32];\n"

    "    for(uint index=0u;index<variable_count;index++){\n"
    "        const fuzzy_gpu_variable_t variable=variables[index];\n"
    "        memberships[index]=fuzzy_gpu_membership(\n"
    "            variable,\n"
    "            inputs[base+variable.input]\n"
    "        );\n"
    "    }\n"

    "    for(uint index=0u;index<rule_count;index++){\n"
    "        const fuzzy_gpu_rule_t rule=rules[index];\n"
    "        const float left=memberships[rule.left];\n"
    "        const float right=memberships[rule.right];\n"
    "        activations[index]=rule.operator==0u\n"
    "            ? fuzzy_gpu_and(logic_method,left,right)\n"
    "            : fuzzy_gpu_or(logic_method,left,right);\n"
    "    }\n"

    "    if(id==0u||id==point_count/2u||id==point_count-1u){\n"
    "        printf(\"GPU point %u inputs:\",id);\n"
    "        for(uint dimension=0u;dimension<dimension_count;dimension++){\n"
    "            printf(\" %.6f\",inputs[base+dimension]);\n"
    "        }\n"
    "        printf(\"\\n\");\n"
    "        printf(\"GPU point %u memberships:\",id);\n"
    "        for(uint index=0u;index<variable_count;index++){\n"
    "            printf(\" %.6f\",memberships[index]);\n"
    "        }\n"
    "        printf(\"\\n\");\n"
    "        printf(\"GPU point %u activations:\",id);\n"
    "        for(uint index=0u;index<rule_count;index++){\n"
    "            printf(\" %.6f\",activations[index]);\n"
    "        }\n"
    "        printf(\"\\n\");\n"
    "    }\n"
    "    float weighted_sum=0.0f;\n"
    "    float membership_sum=0.0f;\n"
    "    float area_sum=0.0f;\n"
    "    float previous_aggregate=0.0f;\n"
    "    float previous_value=output_minimum;\n"
    "    float maximum_membership=-1.0f;\n"
    "    float maximum_sum=0.0f;\n"
    "    uint maximum_count=0u;\n"
    "    float smallest_maximum=output_minimum;\n"
    "    float largest_maximum=output_minimum;\n"

    "const uint sample_count=(uint)ceil(\n"
"    (output_maximum-output_minimum)/defuzz_step\n"
");\n"

"for(uint sample=0u;sample<=sample_count;sample++){\n"
"    const float value=fmin(\n"
"        output_minimum+(float)sample*defuzz_step,\n"
"        output_maximum\n"
"    );\n"
    "        float aggregate=0.0f;\n"

    "        for(uint index=0u;index<rule_count;index++){\n"
    "            const uint output=rules[index].output;\n"
    "            if(output>=output_count)continue;\n"

    "            const float output_membership=fuzzy_gpu_membership(\n"
    "                output_variables[output],\n"
    "                value\n"
    "            );\n"

    "            const float implied=fuzzy_gpu_implication(\n"
    "                implication_method,\n"
    "                activations[index],\n"
    "                output_membership\n"
    "            );\n"

    "            aggregate=fuzzy_gpu_aggregation(\n"
    "                aggregation_method,\n"
    "                aggregate,\n"
    "                implied\n"
    "            );\n"
    "        }\n"

    "        weighted_sum+=value*aggregate;\n"
    "        membership_sum+=aggregate;\n"

    "        if(value>output_minimum){\n"
    "            area_sum+=(previous_aggregate+aggregate)*0.5f*defuzz_step;\n"
    "        }\n"

    "        if(aggregate>maximum_membership){\n"
    "            maximum_membership=aggregate;\n"
    "            maximum_sum=value;\n"
    "            maximum_count=1u;\n"
    "            smallest_maximum=value;\n"
    "            largest_maximum=value;\n"
    "        }else if(aggregate==maximum_membership){\n"
    "            maximum_sum+=value;\n"
    "            maximum_count++;\n"
    "            largest_maximum=value;\n"
    "        }\n"

    "        previous_aggregate=aggregate;\n"
    "        previous_value=value;\n"
    "    }\n"

    "    if(defuzz_method==3u){\n"
    "        results[id]=maximum_count>0u\n"
    "            ? maximum_sum/(float)maximum_count\n"
    "            : 0.0f;\n"
    "        return;\n"
    "    }\n"

    "    if(defuzz_method==4u){\n"
    "        results[id]=smallest_maximum;\n"
    "        return;\n"
    "    }\n"

    "    if(defuzz_method==5u){\n"
    "        results[id]=largest_maximum;\n"
    "        return;\n"
    "    }\n"

    "    if(defuzz_method==1u){\n"
    "        const float target_area=area_sum*0.5f;\n"
    "        float accumulated_area=0.0f;\n"
    "        float previous=0.0f;\n"
    "        float previous_x=output_minimum;\n"

    "        const uint sample_count=(uint)ceil(\n"
    "            (output_maximum-output_minimum)/defuzz_step\n"
    "        );\n"

    "        for(uint sample=0u;sample<=sample_count;sample++){\n"
    "            const float value=fmin(\n"
    "                output_minimum+(float)sample*defuzz_step,\n"
    "                output_maximum\n"
    "            );\n"
    "            float aggregate=0.0f;\n"

    "            for(uint index=0u;index<rule_count;index++){\n"
    "                const uint output=rules[index].output;\n"
    "                if(output>=output_count)continue;\n"

    "                const float output_membership=fuzzy_gpu_membership(\n"
    "                    output_variables[output],\n"
    "                    value\n"
    "                );\n"

    "                const float implied=fuzzy_gpu_implication(\n"
    "                    implication_method,\n"
    "                    activations[index],\n"
    "                    output_membership\n"
    "                );\n"

    "                aggregate=fuzzy_gpu_aggregation(\n"
    "                    aggregation_method,\n"
    "                    aggregate,\n"
    "                    implied\n"
    "                );\n"
    "            }\n"

    "            if(value>output_minimum){\n"
    "                const float segment=(previous+aggregate)*0.5f*defuzz_step;\n"
    "                if(accumulated_area+segment>=target_area){\n"
    "                    results[id]=(previous_x+value)*0.5f;\n"
    "                    return;\n"
    "                }\n"
    "                accumulated_area+=segment;\n"
    "            }\n"

    "            previous=aggregate;\n"
    "            previous_x=value;\n"
    "        }\n"

    "        results[id]=output_maximum;\n"
    "        return;\n"
    "    }\n"

    "    results[id]=membership_sum>0.0f\n"
    "        ? weighted_sum/membership_sum\n"
    "        : 0.0f;\n"
    "    if(id==0u||id==point_count/2u||id==point_count-1u){\n"
    "        printf(\n"
    "            \"GPU point %u weighted_sum=%.9f membership_sum=%.9f result=%.9f\\n\",\n"
    "            id,\n"
    "            weighted_sum,\n"
    "            membership_sum,\n"
    "            results[id]\n"
    "        );\n"
    "    }\n"
    "}\n";

static bool fuzzy_gpu_harness_begin(
    fuzzy_gpu_harness_t *gpu,
    const char *source,
    const char *kernel_name
)
{
    cl_platform_id platform;
    cl_uint platform_count;
    cl_int error;

    error =
        clGetPlatformIDs(
            1,
            &platform,
            &platform_count
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    error =
        clGetDeviceIDs(
            platform,
            CL_DEVICE_TYPE_GPU,
            1,
            &gpu->device,
            NULL
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    gpu->context =
        clCreateContext(
            NULL,
            1,
            &gpu->device,
            NULL,
            NULL,
            &error
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    gpu->queue =
        clCreateCommandQueue(
            gpu->context,
            gpu->device,
            0,
            &error
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    gpu->program =
        clCreateProgramWithSource(
            gpu->context,
            1,
            &source,
            NULL,
            &error
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    error =
        clBuildProgram(
            gpu->program,
            1,
            &gpu->device,
            NULL,
            NULL,
            NULL
        );

    if (error != CL_SUCCESS) {
        size_t log_size;
        char *build_log;

        clGetProgramBuildInfo(
            gpu->program,
            gpu->device,
            CL_PROGRAM_BUILD_LOG,
            0,
            NULL,
            &log_size
        );

        build_log =
            malloc(
                log_size + 1u
            );

        clGetProgramBuildInfo(
            gpu->program,
            gpu->device,
            CL_PROGRAM_BUILD_LOG,
            log_size,
            build_log,
            NULL
        );

        build_log[log_size] =
            '\0';

        fprintf(
            stderr,
            "%s\n",
            build_log
        );

        free(
            build_log
        );

        return false;
    }

    gpu->kernel =
        clCreateKernel(
            gpu->program,
            kernel_name,
            &error
        );

    return error == CL_SUCCESS;
}

static bool fuzzy_gpu_harness_run(
    fuzzy_gpu_harness_t *gpu,
    const fuzzy_gpu_controller_t *controller,
    const float *inputs,
    float *outputs,
    size_t point_count,
    size_t dimension_count,
    float defuzz_step
)
{
    cl_mem input_buffer;
    cl_mem output_buffer;
    cl_mem variable_buffer;
    cl_mem fuzzy_output_buffer;
    cl_mem rule_buffer;

    cl_uint gpu_point_count;
    cl_uint gpu_dimension_count;
    cl_uint gpu_variable_count;
    cl_uint gpu_output_count;
    cl_uint gpu_rule_count;

    cl_int error;
    size_t global_size;

    gpu_point_count =
        (cl_uint)point_count;

    gpu_dimension_count =
        (cl_uint)dimension_count;

    gpu_variable_count =
        (cl_uint)controller->variable_count;

    gpu_output_count =
        (cl_uint)controller->output_count;

    gpu_rule_count =
        (cl_uint)controller->rule_count;

    input_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            point_count *
            dimension_count *
            sizeof(float),
            (void *)inputs,
            &error
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    output_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_WRITE_ONLY,
            point_count *
            sizeof(float),
            NULL,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(
            input_buffer
        );

        return false;
    }

    variable_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            controller->variable_count *
            sizeof(fuzzy_gpu_variable_t),
            (void *)controller->variables,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(
            input_buffer
        );

        clReleaseMemObject(
            output_buffer
        );

        return false;
    }

    fuzzy_output_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            controller->output_count *
            sizeof(fuzzy_gpu_variable_t),
            (void *)controller->outputs,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(
            input_buffer
        );

        clReleaseMemObject(
            output_buffer
        );

        clReleaseMemObject(
            variable_buffer
        );

        return false;
    }

    rule_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            controller->rule_count *
            sizeof(fuzzy_gpu_rule_t),
            (void *)controller->rules,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(
            input_buffer
        );

        clReleaseMemObject(
            output_buffer
        );

        clReleaseMemObject(
            variable_buffer
        );

        clReleaseMemObject(
            fuzzy_output_buffer
        );

        return false;
    }

    error =
        clSetKernelArg(
            gpu->kernel,
            0,
            sizeof(input_buffer),
            &input_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            1,
            sizeof(output_buffer),
            &output_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            2,
            sizeof(variable_buffer),
            &variable_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            3,
            sizeof(fuzzy_output_buffer),
            &fuzzy_output_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            4,
            sizeof(rule_buffer),
            &rule_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            5,
            sizeof(gpu_point_count),
            &gpu_point_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            6,
            sizeof(gpu_dimension_count),
            &gpu_dimension_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            7,
            sizeof(gpu_variable_count),
            &gpu_variable_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            8,
            sizeof(gpu_output_count),
            &gpu_output_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            9,
            sizeof(gpu_rule_count),
            &gpu_rule_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            10,
            sizeof(defuzz_step),
            &defuzz_step
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            11,
            sizeof(controller->output_minimum),
            &controller->output_minimum
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            12,
            sizeof(controller->output_maximum),
            &controller->output_maximum
        );
    
    cl_uint gpu_logic_method = (cl_uint)controller->logic_method;
    cl_uint gpu_implication_method = (cl_uint)controller->implication_method;
    cl_uint gpu_aggregation_method = (cl_uint)controller->aggregation_method;
    cl_uint gpu_defuzz_method = (cl_uint)controller->defuzz_method;

    error |= clSetKernelArg(gpu->kernel, 13, sizeof(gpu_logic_method), &gpu_logic_method);
    error |= clSetKernelArg(gpu->kernel, 14, sizeof(gpu_implication_method), &gpu_implication_method);
    error |= clSetKernelArg(gpu->kernel, 15, sizeof(gpu_aggregation_method), &gpu_aggregation_method);
    error |= clSetKernelArg(gpu->kernel, 16, sizeof(gpu_defuzz_method), &gpu_defuzz_method);

    if (error == CL_SUCCESS) {
        global_size =
            point_count;

        error =
            clEnqueueNDRangeKernel(
                gpu->queue,
                gpu->kernel,
                1,
                NULL,
                &global_size,
                NULL,
                0,
                NULL,
                NULL
            );
    }

    if (error == CL_SUCCESS) {
        error =
            clFinish(
                gpu->queue
            );
    }

    if (error == CL_SUCCESS) {
        error =
            clEnqueueReadBuffer(
                gpu->queue,
                output_buffer,
                CL_TRUE,
                0,
                point_count *
                sizeof(float),
                outputs,
                0,
                NULL,
                NULL
            );
    }

    clReleaseMemObject(
        input_buffer
    );

    clReleaseMemObject(
        output_buffer
    );

    clReleaseMemObject(
        variable_buffer
    );

    clReleaseMemObject(
        fuzzy_output_buffer
    );

    clReleaseMemObject(
        rule_buffer
    );

    return error == CL_SUCCESS;
}

static bool fuzzy_gpu_interpolation_run(
    fuzzy_gpu_harness_t *gpu,
    const float *inputs,
    float *outputs,
    const float *point_coordinates,
    const float *point_memberships,
    size_t sweep_point_count,
    size_t dimension_count,
    size_t interpolation_point_count
)
{
    cl_mem input_buffer;
    cl_mem output_buffer;
    cl_mem coordinate_buffer;
    cl_mem membership_buffer;

    cl_uint gpu_sweep_point_count;
    cl_uint gpu_dimension_count;
    cl_uint gpu_interpolation_point_count;

    cl_int error;
    size_t global_size;

    gpu_sweep_point_count =
        (cl_uint)sweep_point_count;

    gpu_dimension_count =
        (cl_uint)dimension_count;

    gpu_interpolation_point_count =
        (cl_uint)interpolation_point_count;

    input_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            sweep_point_count *
            dimension_count *
            sizeof(float),
            (void *)inputs,
            &error
        );

    if (error != CL_SUCCESS) {
        return false;
    }

    output_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_WRITE_ONLY,
            sweep_point_count *
            sizeof(float),
            NULL,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(input_buffer);
        return false;
    }

    coordinate_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            interpolation_point_count *
            dimension_count *
            sizeof(float),
            (void *)point_coordinates,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(input_buffer);
        clReleaseMemObject(output_buffer);
        return false;
    }

    membership_buffer =
        clCreateBuffer(
            gpu->context,
            CL_MEM_READ_ONLY |
            CL_MEM_COPY_HOST_PTR,
            interpolation_point_count *
            sizeof(float),
            (void *)point_memberships,
            &error
        );

    if (error != CL_SUCCESS) {
        clReleaseMemObject(input_buffer);
        clReleaseMemObject(output_buffer);
        clReleaseMemObject(coordinate_buffer);
        return false;
    }

    error =
        clSetKernelArg(
            gpu->kernel,
            0,
            sizeof(input_buffer),
            &input_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            1,
            sizeof(output_buffer),
            &output_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            2,
            sizeof(coordinate_buffer),
            &coordinate_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            3,
            sizeof(membership_buffer),
            &membership_buffer
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            4,
            sizeof(gpu_sweep_point_count),
            &gpu_sweep_point_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            5,
            sizeof(gpu_dimension_count),
            &gpu_dimension_count
        );

    error |=
        clSetKernelArg(
            gpu->kernel,
            6,
            sizeof(gpu_interpolation_point_count),
            &gpu_interpolation_point_count
        );

    if (error == CL_SUCCESS) {
        global_size =
            sweep_point_count;

        error =
            clEnqueueNDRangeKernel(
                gpu->queue,
                gpu->kernel,
                1,
                NULL,
                &global_size,
                NULL,
                0,
                NULL,
                NULL
            );
    }

    if (error == CL_SUCCESS) {
        error =
            clEnqueueReadBuffer(
                gpu->queue,
                output_buffer,
                CL_TRUE,
                0,
                sweep_point_count *
                sizeof(float),
                outputs,
                0,
                NULL,
                NULL
            );
    }

    clReleaseMemObject(input_buffer);
    clReleaseMemObject(output_buffer);
    clReleaseMemObject(coordinate_buffer);
    clReleaseMemObject(membership_buffer);

    return error == CL_SUCCESS;
}

static void fuzzy_gpu_harness_end(
    fuzzy_gpu_harness_t *gpu
)
{
    clReleaseKernel(
        gpu->kernel
    );

    clReleaseProgram(
        gpu->program
    );

    clReleaseCommandQueue(
        gpu->queue
    );

    clReleaseContext(
        gpu->context
    );
}

#endif /* FUZZY_OPENCL */

static bool fuzzy_sweep_generate(
    const fuzzy_cog_sweep_t *sweep,
    const fuzzy_point_t points[],
    size_t point_count,
    bool fixed_value_range,
    float fixed_value_minimum,
    float fixed_value_maximum
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
        sweep == NULL ||
        sweep->filename == NULL ||
        sweep->dimensions == NULL ||
        sweep->dimension_count == 0u
    ) {
        return false;
    }

    if (
        sweep->evaluate == NULL &&
        (
            points == NULL ||
            point_count == 0u
        )
    ) {
        return false;
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
        sample_counts == NULL ||
        indices == NULL ||
        inputs == NULL
    ) {
        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
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
        sweep_inputs == NULL ||
        sweep_values == NULL
    ) {
        free(sweep_inputs);
        free(sweep_values);
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
        free(sweep_inputs);
        free(sweep_values);
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
        free(sweep_inputs);
        free(sweep_values);
        free(sample_counts);
        free(indices);
        free(inputs);

        return false;
    }

    for (
        size_t dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        fprintf(
            csv_file,
            "%s,",
            sweep->dimensions[dimension].name != NULL
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

        if (sweep->evaluate != NULL) {
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
            sweep_values,
            fixed_value_range,
            fixed_value_minimum,
            fixed_value_maximum
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

#ifdef FUZZY_OPENCL


bool fuzzy_gpu_sweep(const fuzzy_gpu_sweep_t *sweep)
{
    fuzzy_gpu_harness_t gpu;
    fuzzy_cog_sweep_t render_sweep;

    size_t *sample_counts;
    size_t *indices;

    float *inputs;
    float *outputs;

    size_t dimension_count;
    size_t total_points;
    size_t point;
    size_t dimension;

    FILE *csv_file;
    char csv_filename[256];

    bool success;

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

    total_points =
        1u;

    for (
        dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        sample_counts[dimension] =
            (size_t)ceilf(
                (
                    sweep->dimensions[dimension].upper -
                    sweep->dimensions[dimension].lower
                ) /
                sweep->dimensions[dimension].step
            ) + 1u;

        total_points *=
            sample_counts[dimension];
    }

    inputs =
        malloc(
            total_points *
            dimension_count *
            sizeof(inputs[0])
        );

    outputs =
        malloc(
            total_points *
            sizeof(outputs[0])
        );

    for (
        point = 0u;
        point < total_points;
        point++
    ) {
        for (
            dimension = 0u;
            dimension < dimension_count;
            dimension++
        ) {
            float input =
                sweep->dimensions[dimension].lower +
                (float)indices[dimension] *
                sweep->dimensions[dimension].step;

            if (
                input >
                sweep->dimensions[dimension].upper
            ) {
                input =
                    sweep->dimensions[dimension].upper;
            }

            inputs[
                point *
                dimension_count +
                dimension
            ] = input;
        }

        for (
            dimension = dimension_count;
            dimension > 0u;
            dimension--
        ) {
            size_t current =
                dimension - 1u;

            indices[current]++;

            if (
                indices[current] <
                sample_counts[current]
            ) {
                break;
            }

            indices[current] =
                0u;
        }
    }

    success =
        fuzzy_gpu_harness_begin(
            &gpu,
            fuzzy_gpu_kernel_source,
            "fuzzy_gpu_sweep_kernel"
        );

    if (success) {
        success =
            fuzzy_gpu_harness_run(
                &gpu,
                sweep->controller,
                inputs,
                outputs,
                total_points,
                dimension_count,
                sweep->defuzz_step
            );

        if (success) {
            float minimum_output =
                outputs[0];

            float maximum_output =
                outputs[0];

            size_t different_output_count =
                0u;

            for (
                point = 1u;
                point < total_points;
                point++
            ) {
                if (
                    outputs[point] <
                    minimum_output
                ) {
                    minimum_output =
                        outputs[point];
                }

                if (
                    outputs[point] >
                    maximum_output
                ) {
                    maximum_output =
                        outputs[point];
                }

                if (
                    outputs[point] !=
                    outputs[0]
                ) {
                    different_output_count++;
                }
            }

            printf(
                "\nGPU sweep diagnostics:\n"
                "  Dimensions:            %zu\n"
                "  Total points:          %zu\n"
                "  Variable ABI size:     %zu\n"
                "  Rule ABI size:         %zu\n"
                "  First output:          %.9g\n"
                "  Middle output:         %.9g\n"
                "  Last output:           %.9g\n"
                "  Minimum output:        %.9g\n"
                "  Maximum output:        %.9g\n"
                "  Outputs unlike first:  %zu\n",
                dimension_count,
                total_points,
                sizeof(fuzzy_gpu_variable_t),
                sizeof(fuzzy_gpu_rule_t),
                outputs[0],
                outputs[total_points / 2u],
                outputs[total_points - 1u],
                minimum_output,
                maximum_output,
                different_output_count
            );

            printf(
                "  First inputs:"
            );

            for (
                dimension = 0u;
                dimension < dimension_count;
                dimension++
            ) {
                printf(
                    " %.9g",
                    inputs[dimension]
                );
            }

            printf(
                "\n  Middle inputs:"
            );

            for (
                dimension = 0u;
                dimension < dimension_count;
                dimension++
            ) {
                printf(
                    " %.9g",
                    inputs[
                        (
                            total_points /
                            2u
                        ) *
                        dimension_count +
                        dimension
                    ]
                );
            }

            printf(
                "\n  Last inputs:"
            );

            for (
                dimension = 0u;
                dimension < dimension_count;
                dimension++
            ) {
                printf(
                    " %.9g",
                    inputs[
                        (
                            total_points -
                            1u
                        ) *
                        dimension_count +
                        dimension
                    ]
                );
            }

            printf(
                "\n\n"
            );
        }

        fuzzy_gpu_harness_end(
            &gpu
        );
    }

    if (!success) {
        free(sample_counts);
        free(indices);
        free(inputs);
        free(outputs);

        return false;
    }

    snprintf(
        csv_filename,
        sizeof(csv_filename),
        "%s.csv",
        sweep->filename
    );

    csv_file =
        fopen(
            csv_filename,
            "w"
        );

    for (
        dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        fprintf(
            csv_file,
            "%s,",
            sweep->dimensions[dimension].name
        );
    }

    fprintf(
        csv_file,
        "%s\n",
        sweep->value_name
    );

    for (
        point = 0u;
        point < total_points;
        point++
    ) {
        for (
            dimension = 0u;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                csv_file,
                "%.9g,",
                inputs[
                    point *
                    dimension_count +
                    dimension
                ]
            );
        }

        fprintf(
            csv_file,
            "%.9g\n",
            outputs[point]
        );
    }

    fclose(
        csv_file
    );

    render_sweep.filename =
        sweep->filename;

    render_sweep.title =
        sweep->title;

    render_sweep.value_name =
        sweep->value_name;

    render_sweep.dimensions =
        sweep->dimensions;

    render_sweep.dimension_count =
        dimension_count;

    render_sweep.cog_step =
        sweep->defuzz_step;

    render_sweep.evaluate =
        NULL;

    success =
        fuzzy_sweep_write_svg(
            &render_sweep,
            sample_counts,
            total_points,
            inputs,
            outputs,
            false,
            0.0f,
            0.0f
        );

    free(sample_counts);
    free(indices);
    free(inputs);
    free(outputs);

    return success;
}

static bool fuzzy_gpu_interpolation_sweep_range(
    const fuzzy_interpolation_sweep_t *sweep,
    bool fixed_value_range,
    float fixed_value_minimum,
    float fixed_value_maximum
)
{
    fuzzy_gpu_harness_t gpu;
    fuzzy_cog_sweep_t render_sweep;

    size_t *sample_counts;
    size_t *indices;

    float *inputs;
    float *outputs;
    float *point_coordinates;
    float *point_memberships;

    size_t dimension_count;
    size_t total_points;
    size_t point;
    size_t dimension;

    FILE *csv_file;
    char csv_filename[256];

    bool success;

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

    total_points =
        1u;

    for (
        dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        sample_counts[dimension] =
            (size_t)ceilf(
                (
                    sweep->dimensions[dimension].upper -
                    sweep->dimensions[dimension].lower
                ) /
                sweep->dimensions[dimension].step
            ) + 1u;

        total_points *=
            sample_counts[dimension];
    }

    inputs =
        malloc(
            total_points *
            dimension_count *
            sizeof(inputs[0])
        );

    outputs =
        malloc(
            total_points *
            sizeof(outputs[0])
        );

    point_coordinates =
        malloc(
            sweep->point_count *
            dimension_count *
            sizeof(point_coordinates[0])
        );

    point_memberships =
        malloc(
            sweep->point_count *
            sizeof(point_memberships[0])
        );

    for (
        point = 0u;
        point < sweep->point_count;
        point++
    ) {
        point_memberships[point] =
            sweep->points[point].membership;

        for (
            dimension = 0u;
            dimension < dimension_count;
            dimension++
        ) {
            point_coordinates[
                point *
                dimension_count +
                dimension
            ] =
                sweep->points[point]
                    .coordinates[dimension];
        }
    }

    for (
        point = 0u;
        point < total_points;
        point++
    ) {
        for (
            dimension = 0u;
            dimension < dimension_count;
            dimension++
        ) {
            float input =
                sweep->dimensions[dimension].lower +
                (float)indices[dimension] *
                sweep->dimensions[dimension].step;

            if (
                input >
                sweep->dimensions[dimension].upper
            ) {
                input =
                    sweep->dimensions[dimension].upper;
            }

            inputs[
                point *
                dimension_count +
                dimension
            ] = input;
        }

        for (
            dimension = dimension_count;
            dimension > 0u;
            dimension--
        ) {
            size_t current =
                dimension - 1u;

            indices[current]++;

            if (
                indices[current] <
                sample_counts[current]
            ) {
                break;
            }

            indices[current] =
                0u;
        }
    }

    success =
        fuzzy_gpu_harness_begin(
            &gpu,
            fuzzy_gpu_interpolation_kernel_source,
            "fuzzy_gpu_interpolation_kernel"
        );

    if (success) {
        success =
            fuzzy_gpu_interpolation_run(
                &gpu,
                inputs,
                outputs,
                point_coordinates,
                point_memberships,
                total_points,
                dimension_count,
                sweep->point_count
            );

        fuzzy_gpu_harness_end(
            &gpu
        );
    }

    if (!success) {
        free(sample_counts);
        free(indices);
        free(inputs);
        free(outputs);
        free(point_coordinates);
        free(point_memberships);

        return false;
    }

    snprintf(
        csv_filename,
        sizeof(csv_filename),
        "%s.csv",
        sweep->filename
    );

    csv_file =
        fopen(
            csv_filename,
            "w"
        );

    for (
        dimension = 0u;
        dimension < dimension_count;
        dimension++
    ) {
        fprintf(
            csv_file,
            "%s,",
            sweep->dimensions[dimension].name
        );
    }

    fprintf(
        csv_file,
        "Membership\n"
    );

    for (
        point = 0u;
        point < total_points;
        point++
    ) {
        for (
            dimension = 0u;
            dimension < dimension_count;
            dimension++
        ) {
            fprintf(
                csv_file,
                "%.9g,",
                inputs[
                    point *
                    dimension_count +
                    dimension
                ]
            );
        }

        fprintf(
            csv_file,
            "%.9g\n",
            outputs[point]
        );
    }

    fclose(
        csv_file
    );

    render_sweep.filename =
        sweep->filename;

    render_sweep.title =
        sweep->title;

    render_sweep.value_name =
        "Membership";

    render_sweep.dimensions =
        sweep->dimensions;

    render_sweep.dimension_count =
        dimension_count;

    render_sweep.cog_step =
        0.0f;

    render_sweep.evaluate =
        NULL;

    success =
        fuzzy_sweep_write_svg(
            &render_sweep,
            sample_counts,
            total_points,
            inputs,
            outputs,
            fixed_value_range,
            fixed_value_minimum,
            fixed_value_maximum
        );

    free(sample_counts);
    free(indices);
    free(inputs);
    free(outputs);
    free(point_coordinates);
    free(point_memberships);

    printf(
        "GPU membership sweep complete "
        "(%zu dimensions, %zu points)\n",
        dimension_count,
        total_points
    );

    return success;
}

bool fuzzy_gpu_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep
)
{
    return fuzzy_gpu_interpolation_sweep_range(
        sweep,
        false,
        0.0f,
        0.0f
    );
}

#endif /* FUZZY_OPENCL */

bool fuzzy_cog_sweep(const fuzzy_cog_sweep_t *sweep)
{
    if (
        sweep == NULL ||
        sweep->evaluate == NULL ||
        sweep->cog_step <= 0.0f
    ) {
        return false;
    }

    return fuzzy_sweep_generate(
        sweep,
        NULL,
        0u,
        false,
        0.0f,
        0.0f
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
        sweep == NULL ||
        sweep->filename == NULL ||
        sweep->dimensions == NULL ||
        sweep->dimension_count == 0u ||
        sweep->points == NULL ||
        sweep->point_count == 0u
    ) {
        return false;
    }

    inputs =
        malloc(
            sweep->dimension_count *
            sizeof(inputs[0])
        );

    if (inputs == NULL) {
        return false;
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
            sweep->title != NULL
                ? sweep->title
                : "Membership Interpolation",
            current->name != NULL
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

            return false;
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

    return true;
}

bool fuzzy_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep
)
{
    fuzzy_cog_sweep_t shared_sweep;

    if (
        sweep == NULL ||
        sweep->points == NULL ||
        sweep->point_count == 0u
    ) {
        return false;
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
        NULL;
    
    return fuzzy_sweep_generate(
        &shared_sweep,
        sweep->points,
        sweep->point_count,
        false,
        0.0f,
        0.0f
    );
}

#endif /* FUZZY_8051 */



#endif /* FUZZY_IMPLEMENTATION */
#endif /* FUZZY_8051 compact backend / desktop original */


/* ==========================================================
 * Fuzzy-neuron / ANFIS network API
 *
 * This module is part of fuzzy.h. FUZZY_IMPLEMENTATION emits
 * both the fuzzy and fuzzy-neuron implementations. FUZZY_OPENCL
 * enables both OpenCL backends.
 * ========================================================== */
#ifndef FUZZY_8051
#ifdef FUZZY_OPENCL
#ifndef FUZZY_NEURON_OPENCL
#define FUZZY_NEURON_OPENCL
#endif
#endif
#ifdef FUZZY_IMPLEMENTATION
#ifndef FUZZY_NEURON_IMPLEMENTATION
#define FUZZY_NEURON_IMPLEMENTATION
#endif
#endif

/* CRT declarations required by the merged neuron module. */
extern void *FUZZY_CDECL realloc(void *, size_t);
extern void *FUZZY_CDECL memset(void *, int, size_t);
extern int FUZZY_CDECL strncmp(const char *, const char *, size_t);
extern float FUZZY_CDECL strtof(const char *, char **);
extern char *FUZZY_CDECL fgets(char *, int, FILE *);
extern size_t FUZZY_CDECL fread(void *, size_t, size_t, FILE *);
extern int FUZZY_CDECL fseek(FILE *, long, int);
extern long FUZZY_CDECL ftell(FILE *);
extern void FUZZY_CDECL rewind(FILE *);
extern float FUZZY_CDECL tanhf(float);
extern float FUZZY_CDECL sqrtf(float);
#ifndef SEEK_END
#define SEEK_END 2
#endif

/* fuzzy_neuron.h - STB-style fuzzy-rule front end + fully connected ANN.
 *
 * Define FUZZY_NEURON_IMPLEMENTATION in exactly one C file.
 * Define FUZZY_NEURON_OPENCL to enable the OpenCL backend.
 */


#ifdef FUZZY_NEURON_OPENCL

#ifndef CL_TARGET_OPENCL_VERSION
#define CL_TARGET_OPENCL_VERSION 120
#endif


#endif

#ifndef FUZZY_NEURON_MAX_RULES
#define FUZZY_NEURON_MAX_RULES 64u
#endif

#ifndef FUZZY_NEURON_MAX_LAYERS
#define FUZZY_NEURON_MAX_LAYERS 32u
#endif

#ifndef FUZZY_NEURON_MAX_PREMISES
#define FUZZY_NEURON_MAX_PREMISES 64u
#endif

#ifndef FUZZY_NEURON_MAX_EXPRESSIONS
#define FUZZY_NEURON_MAX_EXPRESSIONS 256u
#endif

#ifndef FUZZY_NEURON_MAX_PREMISE_PARAMETERS
#define FUZZY_NEURON_MAX_PREMISE_PARAMETERS 256u
#endif


typedef enum fuzzy_neuron_expression_kind
{
    FUZZY_NEURON_EXPRESSION_MEMBERSHIP = 0,
    FUZZY_NEURON_EXPRESSION_NOT = 1,
    FUZZY_NEURON_EXPRESSION_AND = 2,
    FUZZY_NEURON_EXPRESSION_OR = 3
} fuzzy_neuron_expression_kind_t;

typedef struct fuzzy_neuron_premise
{
    const char *name;
    size_t input_index;
    fuzzy_shape_t shape;
    size_t parameter_offset;
    size_t parameter_count;
    unsigned int trainable_mask;
    float hedge;
    float domain_minimum;
    float domain_maximum;
    float epsilon;
} fuzzy_neuron_premise_t;

typedef struct fuzzy_neuron_expression
{
    fuzzy_neuron_expression_kind_t kind;
    size_t left;
    size_t right;
    size_t value;
} fuzzy_neuron_expression_t;

typedef float (*fuzzy_neuron_rule_fn)(
    const float raw_inputs[],
    size_t input_count,
    void *user
);

typedef enum fuzzy_neuron_activation
{
    FUZZY_NEURON_LINEAR = 0,
    FUZZY_NEURON_SIGMOID = 1,
    FUZZY_NEURON_TANH = 2,
    FUZZY_NEURON_RELU = 3
} fuzzy_neuron_activation_t;
#ifdef FUZZY_NEURON_OPENCL
_Static_assert(FUZZY_LOGIC_STANDARD == 0, "OpenCL logic ABI mismatch");
_Static_assert(FUZZY_LOGIC_ALGEBRAIC == 1, "OpenCL logic ABI mismatch");
_Static_assert(FUZZY_LOGIC_BOUNDED == 2, "OpenCL logic ABI mismatch");
_Static_assert(FUZZY_SHAPE_RAMP == 0, "OpenCL shape ABI mismatch");
_Static_assert(FUZZY_SHAPE_GAUSSIAN2 == 11, "OpenCL shape ABI mismatch");
#endif

typedef struct fuzzy_neuron_rule
{
    const char *name;
    fuzzy_neuron_rule_fn evaluate;
    void *user;
} fuzzy_neuron_rule_t;

typedef struct fuzzy_neuron_layer
{
    size_t count;
    fuzzy_neuron_activation_t activation;
    size_t weight_offset;
    size_t bias_offset;
} fuzzy_neuron_layer_t;

typedef struct fuzzy_neuron_dataset
{
    float *inputs;
    float *targets;
    size_t rows;
    size_t input_dimensions;
    size_t target_dimensions;
} fuzzy_neuron_dataset_t;

typedef struct fuzzy_neuron_csv
{
    size_t input_dimensions;
    size_t target_dimensions;
    bool header;
    char separator;
    const float *input_scales;
    const float *target_scales;
} fuzzy_neuron_csv_t;

typedef enum fuzzy_neuron_optimizer
{
    FUZZY_NEURON_OPTIMIZER_SGD = 0,
    FUZZY_NEURON_OPTIMIZER_ADAM = 1
} fuzzy_neuron_optimizer_t;

typedef struct fuzzy_neuron_train_options
{
    size_t epochs;
    size_t batch_size;
    float learning_rate;
    size_t report_every;
    fuzzy_neuron_optimizer_t optimizer;
    float adam_beta1;
    float adam_beta2;
    float adam_epsilon;
    bool reset_optimizer_state;
} fuzzy_neuron_train_options_t;

#ifdef FUZZY_NEURON_OPENCL

typedef struct fuzzy_neuron_opencl_kernel_plan
{
    size_t maximum_work_group_size;
    size_t preferred_multiple;
    size_t local_size;
    cl_ulong static_local_memory;
    cl_ulong private_memory;
} fuzzy_neuron_opencl_kernel_plan_t;

typedef struct fuzzy_neuron_opencl
{
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;

    cl_kernel premise_forward_kernel;
    cl_kernel expression_forward_kernel;
    cl_kernel normalize_rules_kernel;
    cl_kernel input_delta_kernel;
    cl_kernel normalize_backward_kernel;
    cl_kernel expression_backward_kernel;
    cl_kernel premise_gradient_kernel;
    cl_kernel project_premises_kernel;
    cl_kernel forward_gemm_kernel;
    cl_kernel output_delta_kernel;
    cl_kernel hidden_delta_gemm_kernel;
    cl_kernel weight_gradient_gemm_kernel;
    cl_kernel bias_gradient_kernel;
    cl_kernel apply_weights_kernel;
    cl_kernel apply_biases_kernel;
    cl_kernel apply_premises_kernel;
    cl_kernel adam_weights_kernel;
    cl_kernel adam_biases_kernel;
    cl_kernel adam_premises_kernel;
    cl_kernel loss_reduce_stage_kernel;
    cl_kernel loss_reduce_final_kernel;
    cl_kernel best_model_kernel;
    cl_kernel conditional_copy_kernel;
    cl_kernel gather_outputs_kernel;
    cl_kernel forward_gemm_tiled_kernel;
    cl_kernel hidden_delta_gemm_tiled_kernel;
    cl_kernel layer_backward_update_kernel;
    cl_kernel fuzzy_backward_kernel;
    cl_kernel fuzzy_update_kernel;

    fuzzy_neuron_opencl_kernel_plan_t premise_gradient_plan;
    fuzzy_neuron_opencl_kernel_plan_t loss_reduce_stage_plan;
    fuzzy_neuron_opencl_kernel_plan_t loss_reduce_final_plan;
    fuzzy_neuron_opencl_kernel_plan_t forward_gemm_plan;
    fuzzy_neuron_opencl_kernel_plan_t hidden_delta_gemm_plan;
    fuzzy_neuron_opencl_kernel_plan_t layer_backward_update_plan;
    fuzzy_neuron_opencl_kernel_plan_t fuzzy_backward_plan;
    fuzzy_neuron_opencl_kernel_plan_t fuzzy_update_plan;

    cl_mem d_raw_inputs;
    cl_mem d_premises;
    cl_mem d_premise_parameters;
    cl_mem d_expressions;
    cl_mem d_rule_roots;
    cl_mem d_memberships;
    cl_mem d_expression_values;
    cl_mem d_raw_rules;
    cl_mem d_normalized_rule_gradients;
    cl_mem d_raw_rule_gradients;
    cl_mem d_expression_gradients;
    cl_mem d_membership_gradients;
    cl_mem d_premise_parameter_gradients;
    cl_mem d_premise_first_moment;
    cl_mem d_premise_second_moment;
    cl_mem d_targets;
    cl_mem d_weights;
    cl_mem d_biases;
    cl_mem d_activations;
    cl_mem d_deltas;
    cl_mem d_losses;
    cl_mem d_weight_gradients;
    cl_mem d_bias_gradients;
    cl_mem d_weight_first_moment;
    cl_mem d_weight_second_moment;
    cl_mem d_bias_first_moment;
    cl_mem d_bias_second_moment;
    cl_mem d_dataset_inputs;
    cl_mem d_dataset_targets;
    cl_mem d_outputs;
    cl_mem d_loss_partials;
    cl_mem d_epoch_loss;
    cl_mem d_best_loss;
    cl_mem d_best_updated;
    cl_mem d_best_weights;
    cl_mem d_best_biases;
    cl_mem d_best_premise_parameters;
    cl_ulong optimizer_step;

    size_t batch_capacity;
    size_t dataset_capacity_rows;
    size_t loss_partial_capacity;
    bool ready;
} fuzzy_neuron_opencl_t;

#endif

typedef struct fuzzy_neuron_network
{
    size_t raw_input_dimensions;
    size_t output_dimensions;
    fuzzy_logic_method_t logic_method;

    fuzzy_neuron_rule_t rules[FUZZY_NEURON_MAX_RULES];
    size_t rule_count;

    fuzzy_neuron_premise_t premises[FUZZY_NEURON_MAX_PREMISES];
    size_t premise_count;
    fuzzy_neuron_expression_t expressions[FUZZY_NEURON_MAX_EXPRESSIONS];
    size_t expression_count;
    size_t rule_roots[FUZZY_NEURON_MAX_RULES];
    float premise_parameters[FUZZY_NEURON_MAX_PREMISE_PARAMETERS];
    size_t premise_parameter_count;
    bool trainable_fuzzy;

    fuzzy_neuron_layer_t layers[FUZZY_NEURON_MAX_LAYERS];
    size_t layer_count;

    size_t neuron_count;
    size_t weight_count;
    size_t bias_count;

    float *weights;
    float *biases;
    float *activations;
    float *deltas;

    float *flat_rule_inputs;
    size_t flat_rule_capacity;

    unsigned int random_state;
    bool compiled;

#ifdef FUZZY_NEURON_OPENCL
    fuzzy_neuron_opencl_t opencl;
#endif
} fuzzy_neuron_network_t;

typedef struct fuzzy_neuron_premise_descriptor
{
    const char *name;
    size_t input_index;
    fuzzy_shape_t shape;
    float hedge;
    unsigned int trainable_mask;
    float domain_minimum;
    float domain_maximum;
    float epsilon;
    const float *parameters;
    size_t parameter_count;
} fuzzy_neuron_premise_descriptor_t;

typedef struct fuzzy_neuron_rule_descriptor
{
    const char *name;
    size_t root;
} fuzzy_neuron_rule_descriptor_t;

typedef struct fuzzy_neuron_model_descriptor
{
    size_t input_dimensions;
    size_t output_dimensions;
    fuzzy_logic_method_t logic_method;
    const fuzzy_neuron_premise_descriptor_t *premises;
    size_t premise_count;
    const fuzzy_neuron_expression_t *expressions;
    size_t expression_count;
    const fuzzy_neuron_rule_descriptor_t *rules;
    size_t rule_count;
    const fuzzy_neuron_layer_t *layers;
    size_t layer_count;
} fuzzy_neuron_model_descriptor_t;

/* ==========================================================
 * Compressed fuzzy-neuron model DSL
 *
 * Every DSL array is a single self-describing object containing
 * both its element count and its complete value storage.
 * ========================================================== */
#define FUZZY_NEURON_COUNTED_ARRAY(symbol, type, ...) \
    static const struct \
    { \
        size_t count; \
        type values[sizeof((type[]){__VA_ARGS__}) / sizeof(type)]; \
    } symbol = \
    { \
        sizeof((type[]){__VA_ARGS__}) / sizeof(type), \
        {__VA_ARGS__} \
    }

#define FUZZY_NEURON_OBJECT_COUNT(object) ((object).count)
#define FUZZY_NEURON_OBJECT_VALUES(object) ((object).values)

#define FUZZY_NEURON_PARAMETERS(symbol, ...) \
    FUZZY_NEURON_COUNTED_ARRAY(symbol, float, __VA_ARGS__)

#define FUZZY_NEURON_PREMISE(name_arg, input_arg, shape_arg, hedge_arg, mask_arg, minimum_arg, maximum_arg, epsilon_arg, parameter_object) \
    { \
        (name_arg), \
        (input_arg), \
        (shape_arg), \
        (hedge_arg), \
        (mask_arg), \
        (minimum_arg), \
        (maximum_arg), \
        (epsilon_arg), \
        FUZZY_NEURON_OBJECT_VALUES(parameter_object), \
        FUZZY_NEURON_OBJECT_COUNT(parameter_object) \
    }

#define FUZZY_NEURON_PREMISES(symbol, ...) \
    FUZZY_NEURON_COUNTED_ARRAY(symbol, fuzzy_neuron_premise_descriptor_t, __VA_ARGS__)

#define FUZZY_NEURON_MEMBERSHIP(premise_index) \
    {FUZZY_NEURON_EXPRESSION_MEMBERSHIP, 0u, 0u, (premise_index)}

#define FUZZY_NEURON_NOT(expression_index) \
    {FUZZY_NEURON_EXPRESSION_NOT, (expression_index), 0u, 0u}

#define FUZZY_NEURON_AND(left_index, right_index) \
    {FUZZY_NEURON_EXPRESSION_AND, (left_index), (right_index), 0u}

#define FUZZY_NEURON_OR(left_index, right_index) \
    {FUZZY_NEURON_EXPRESSION_OR, (left_index), (right_index), 0u}

#define FUZZY_NEURON_EXPRESSIONS(symbol, ...) \
    FUZZY_NEURON_COUNTED_ARRAY(symbol, fuzzy_neuron_expression_t, __VA_ARGS__)

#define FUZZY_NEURON_RULE_ENTRY(name_arg, root_arg) {(name_arg), (root_arg)}

#define FUZZY_NEURON_RULES(symbol, ...) \
    FUZZY_NEURON_COUNTED_ARRAY(symbol, fuzzy_neuron_rule_descriptor_t, __VA_ARGS__)

#define FUZZY_NEURON_LAYER_ENTRY(count_arg, activation_arg) \
    {(count_arg), (activation_arg), 0u, 0u}

#define FUZZY_NEURON_OUTPUT_ENTRY(output_dimensions, activation_arg) \
    {(output_dimensions), (activation_arg), 0u, 0u}

#define FUZZY_NEURON_LAYERS(symbol, ...) \
    FUZZY_NEURON_COUNTED_ARRAY(symbol, fuzzy_neuron_layer_t, __VA_ARGS__)

#define FUZZY_NEURON_MODEL(symbol, input_dimensions_arg, output_dimensions_arg, logic_method_arg, premise_object, expression_object, rule_object, layer_object) \
    static const fuzzy_neuron_model_descriptor_t symbol##_descriptor = \
    { \
        (input_dimensions_arg), \
        (output_dimensions_arg), \
        (logic_method_arg), \
        FUZZY_NEURON_OBJECT_VALUES(premise_object), \
        FUZZY_NEURON_OBJECT_COUNT(premise_object), \
        FUZZY_NEURON_OBJECT_VALUES(expression_object), \
        FUZZY_NEURON_OBJECT_COUNT(expression_object), \
        FUZZY_NEURON_OBJECT_VALUES(rule_object), \
        FUZZY_NEURON_OBJECT_COUNT(rule_object), \
        FUZZY_NEURON_OBJECT_VALUES(layer_object), \
        FUZZY_NEURON_OBJECT_COUNT(layer_object) \
    }; \
    static fuzzy_neuron_network_t *symbol##_create(void) \
    { \
        return fuzzy_neuron_create_model(&symbol##_descriptor); \
    } \
    static void symbol##_destroy(fuzzy_neuron_network_t *model) \
    { \
        if (model == NULL) \
        { \
            abort(); \
        } \
        fuzzy_neuron_free(model); \
        free(model); \
    }

typedef struct fuzzy_neuron_membership_descriptor
{
    fuzzy_shape_t shape;
    float hedge;
    unsigned int trainable_mask;
    float domain_minimum;
    float domain_maximum;
    const float *parameters;
    size_t parameter_count;
} fuzzy_neuron_membership_descriptor_t;

#define FUZZY_NEURON_MEMBERSHIP_DESCRIPTOR(symbol, shape_arg, hedge_arg, trainable_mask_arg, domain_minimum_arg, domain_maximum_arg, parameter_object) \
    static const fuzzy_neuron_membership_descriptor_t symbol = \
    { \
        (shape_arg), \
        (hedge_arg), \
        (trainable_mask_arg), \
        (domain_minimum_arg), \
        (domain_maximum_arg), \
        FUZZY_NEURON_OBJECT_VALUES(parameter_object), \
        FUZZY_NEURON_OBJECT_COUNT(parameter_object) \
    }

#define FUZZY_NEURON_BINARY_MODEL(symbol, input_dimensions_arg, output_dimensions_arg, logic_method_arg, low_membership_object, high_membership_object, layer_object, ...) \
    static const char *symbol##_input_names[] = \
    { \
        __VA_ARGS__ \
    }; \
    static char symbol##_premise_names[(input_dimensions_arg)][2][64]; \
    static char symbol##_rule_names[(size_t)1u << (input_dimensions_arg)][(input_dimensions_arg) + 1u]; \
    static fuzzy_neuron_network_t *symbol##_create(void) \
    { \
        const fuzzy_neuron_membership_descriptor_t *fuzzy_neuron_binary_memberships__[] = \
        { \
            &(low_membership_object), \
            &(high_membership_object) \
        }; \
        fuzzy_neuron_network_t *fuzzy_neuron_binary_model__ = malloc(sizeof(*fuzzy_neuron_binary_model__)); \
        size_t fuzzy_neuron_binary_expressions__[(input_dimensions_arg)][2]; \
        size_t fuzzy_neuron_binary_rule_count__ = (size_t)1u << (input_dimensions_arg); \
        size_t fuzzy_neuron_binary_dimension__; \
        size_t fuzzy_neuron_binary_membership__; \
        size_t fuzzy_neuron_binary_rule__; \
        size_t fuzzy_neuron_binary_layer__; \
        if (fuzzy_neuron_binary_model__ == NULL) \
        { \
            return NULL; \
        } \
        fuzzy_neuron_init(fuzzy_neuron_binary_model__, (input_dimensions_arg), (output_dimensions_arg)); \
        fuzzy_neuron_set_logic_method(fuzzy_neuron_binary_model__, (logic_method_arg)); \
        for (fuzzy_neuron_binary_dimension__ = 0u; fuzzy_neuron_binary_dimension__ < (input_dimensions_arg); fuzzy_neuron_binary_dimension__++) \
        { \
            for (fuzzy_neuron_binary_membership__ = 0u; fuzzy_neuron_binary_membership__ < 2u; fuzzy_neuron_binary_membership__++) \
            { \
                const fuzzy_neuron_membership_descriptor_t *fuzzy_neuron_binary_descriptor__ = fuzzy_neuron_binary_memberships__[fuzzy_neuron_binary_membership__]; \
                size_t fuzzy_neuron_binary_premise__; \
                snprintf( \
                    symbol##_premise_names[fuzzy_neuron_binary_dimension__][fuzzy_neuron_binary_membership__], \
                    sizeof(symbol##_premise_names[fuzzy_neuron_binary_dimension__][fuzzy_neuron_binary_membership__]), \
                    "%s_%s", \
                    symbol##_input_names[fuzzy_neuron_binary_dimension__], \
                    fuzzy_neuron_binary_membership__ == 0u ? "low" : "high" \
                ); \
                fuzzy_neuron_binary_premise__ = fuzzy_neuron_add_premise( \
                    fuzzy_neuron_binary_model__, \
                    symbol##_premise_names[fuzzy_neuron_binary_dimension__][fuzzy_neuron_binary_membership__], \
                    fuzzy_neuron_binary_dimension__, \
                    fuzzy_neuron_binary_descriptor__->shape, \
                    fuzzy_neuron_binary_descriptor__->hedge, \
                    fuzzy_neuron_binary_descriptor__->trainable_mask, \
                    fuzzy_neuron_binary_descriptor__->domain_minimum, \
                    fuzzy_neuron_binary_descriptor__->domain_maximum, \
                    fuzzy_neuron_binary_descriptor__->parameter_count, \
                    fuzzy_neuron_binary_descriptor__->parameters \
                ); \
                if (fuzzy_neuron_binary_premise__ == SIZE_MAX) \
                { \
                    fuzzy_neuron_free(fuzzy_neuron_binary_model__); \
                    free(fuzzy_neuron_binary_model__); \
                    return NULL; \
                } \
                fuzzy_neuron_binary_expressions__[fuzzy_neuron_binary_dimension__][fuzzy_neuron_binary_membership__] = fuzzy_neuron_add_expression( \
                    fuzzy_neuron_binary_model__, \
                    FUZZY_NEURON_EXPRESSION_MEMBERSHIP, \
                    0u, \
                    0u, \
                    fuzzy_neuron_binary_premise__ \
                ); \
                if (fuzzy_neuron_binary_expressions__[fuzzy_neuron_binary_dimension__][fuzzy_neuron_binary_membership__] == SIZE_MAX) \
                { \
                    fuzzy_neuron_free(fuzzy_neuron_binary_model__); \
                    free(fuzzy_neuron_binary_model__); \
                    return NULL; \
                } \
            } \
        } \
        for (fuzzy_neuron_binary_rule__ = 0u; fuzzy_neuron_binary_rule__ < fuzzy_neuron_binary_rule_count__; fuzzy_neuron_binary_rule__++) \
        { \
            size_t fuzzy_neuron_binary_selected__ = (fuzzy_neuron_binary_rule__ >> ((input_dimensions_arg) - 1u)) & 1u; \
            size_t fuzzy_neuron_binary_root__ = fuzzy_neuron_binary_expressions__[0][fuzzy_neuron_binary_selected__]; \
            for (fuzzy_neuron_binary_dimension__ = 0u; fuzzy_neuron_binary_dimension__ < (input_dimensions_arg); fuzzy_neuron_binary_dimension__++) \
            { \
                fuzzy_neuron_binary_selected__ = (fuzzy_neuron_binary_rule__ >> ((input_dimensions_arg) - 1u - fuzzy_neuron_binary_dimension__)) & 1u; \
                symbol##_rule_names[fuzzy_neuron_binary_rule__][fuzzy_neuron_binary_dimension__] = (char)('0' + fuzzy_neuron_binary_selected__); \
            } \
            symbol##_rule_names[fuzzy_neuron_binary_rule__][input_dimensions_arg] = '\0'; \
            for (fuzzy_neuron_binary_dimension__ = 1u; fuzzy_neuron_binary_dimension__ < (input_dimensions_arg); fuzzy_neuron_binary_dimension__++) \
            { \
                fuzzy_neuron_binary_selected__ = (fuzzy_neuron_binary_rule__ >> ((input_dimensions_arg) - 1u - fuzzy_neuron_binary_dimension__)) & 1u; \
                fuzzy_neuron_binary_root__ = fuzzy_neuron_add_expression( \
                    fuzzy_neuron_binary_model__, \
                    FUZZY_NEURON_EXPRESSION_AND, \
                    fuzzy_neuron_binary_root__, \
                    fuzzy_neuron_binary_expressions__[fuzzy_neuron_binary_dimension__][fuzzy_neuron_binary_selected__], \
                    0u \
                ); \
                if (fuzzy_neuron_binary_root__ == SIZE_MAX) \
                { \
                    fuzzy_neuron_free(fuzzy_neuron_binary_model__); \
                    free(fuzzy_neuron_binary_model__); \
                    return NULL; \
                } \
            } \
            if (!fuzzy_neuron_add_trainable_rule_root( \
                    fuzzy_neuron_binary_model__, \
                    symbol##_rule_names[fuzzy_neuron_binary_rule__], \
                    fuzzy_neuron_binary_root__ \
                )) \
            { \
                fuzzy_neuron_free(fuzzy_neuron_binary_model__); \
                free(fuzzy_neuron_binary_model__); \
                return NULL; \
            } \
        } \
        for (fuzzy_neuron_binary_layer__ = 0u; fuzzy_neuron_binary_layer__ < FUZZY_NEURON_OBJECT_COUNT(layer_object); fuzzy_neuron_binary_layer__++) \
        { \
            const fuzzy_neuron_layer_t *fuzzy_neuron_binary_layer_descriptor__ = &FUZZY_NEURON_OBJECT_VALUES(layer_object)[fuzzy_neuron_binary_layer__]; \
            if (!fuzzy_neuron_add_layer( \
                    fuzzy_neuron_binary_model__, \
                    fuzzy_neuron_binary_layer_descriptor__->count, \
                    fuzzy_neuron_binary_layer_descriptor__->activation \
                )) \
            { \
                fuzzy_neuron_free(fuzzy_neuron_binary_model__); \
                free(fuzzy_neuron_binary_model__); \
                return NULL; \
            } \
        } \
        if (!fuzzy_neuron_compile(fuzzy_neuron_binary_model__)) \
        { \
            fuzzy_neuron_free(fuzzy_neuron_binary_model__); \
            free(fuzzy_neuron_binary_model__); \
            return NULL; \
        } \
        return fuzzy_neuron_binary_model__; \
    } \
    static void symbol##_destroy(fuzzy_neuron_network_t *model) \
    { \
        fuzzy_neuron_free(model); \
        free(model); \
    }


#define FUZZY_NEURON_DATASET_ALLOCATE(dataset_arg, row_count_arg, input_count_arg, target_count_arg) \
    do \
    { \
        (dataset_arg).rows = (row_count_arg); \
        (dataset_arg).input_dimensions = (input_count_arg); \
        (dataset_arg).target_dimensions = (target_count_arg); \
        (dataset_arg).inputs = malloc((row_count_arg) * (input_count_arg) * sizeof(*(dataset_arg).inputs)); \
        (dataset_arg).targets = malloc((row_count_arg) * (target_count_arg) * sizeof(*(dataset_arg).targets)); \
    } while (0)
#define FUZZY_NEURON_DATASET_POINTS(points_arg, dataset_arg) \
    do \
    { \
        size_t fuzzy_neuron_point__; \
        for (fuzzy_neuron_point__ = 0u; fuzzy_neuron_point__ < (dataset_arg).rows; ++fuzzy_neuron_point__) \
        { \
            (points_arg)[fuzzy_neuron_point__].coordinates = (dataset_arg).inputs + fuzzy_neuron_point__ * (dataset_arg).input_dimensions; \
            (points_arg)[fuzzy_neuron_point__].dimension_count = (dataset_arg).input_dimensions; \
            (points_arg)[fuzzy_neuron_point__].membership = (dataset_arg).targets[fuzzy_neuron_point__ * (dataset_arg).target_dimensions]; \
        } \
    } while (0)
#define FUZZY_NEURON_MODEL_POINTS(points_arg, model_arg, dataset_arg, outputs_arg) \
    do \
    { \
        size_t fuzzy_neuron_point__; \
        fuzzy_neuron_predict_batch((model_arg), (dataset_arg).inputs, (dataset_arg).rows, (outputs_arg)); \
        for (fuzzy_neuron_point__ = 0u; fuzzy_neuron_point__ < (dataset_arg).rows; ++fuzzy_neuron_point__) \
        { \
            (points_arg)[fuzzy_neuron_point__].coordinates = (dataset_arg).inputs + fuzzy_neuron_point__ * (dataset_arg).input_dimensions; \
            (points_arg)[fuzzy_neuron_point__].dimension_count = (dataset_arg).input_dimensions; \
            (points_arg)[fuzzy_neuron_point__].membership = (outputs_arg)[fuzzy_neuron_point__ * (dataset_arg).target_dimensions]; \
        } \
    } while (0)

#define FUZZY_NEURON_PREMISE_PLOT_FUNCTION(function_name, model_pointer, premise_index) \
    static float function_name(float value) \
    { \
        const fuzzy_neuron_network_t *fuzzy_neuron_premise_plot_model__ = (model_pointer); \
        const fuzzy_neuron_premise_t *fuzzy_neuron_premise_plot_premise__; \
        const float *fuzzy_neuron_premise_plot_parameters__; \
        if (fuzzy_neuron_premise_plot_model__ == NULL || !fuzzy_neuron_premise_plot_model__->compiled || (premise_index) >= fuzzy_neuron_premise_plot_model__->premise_count) \
        { \
            abort(); \
        } \
        fuzzy_neuron_premise_plot_premise__ = &fuzzy_neuron_premise_plot_model__->premises[(premise_index)]; \
        fuzzy_neuron_premise_plot_parameters__ = fuzzy_neuron_premise_plot_model__->premise_parameters + fuzzy_neuron_premise_plot_premise__->parameter_offset; \
        return fuzzy_function_array(fuzzy_neuron_premise_plot_premise__->shape, value, fuzzy_neuron_premise_plot_premise__->hedge, fuzzy_neuron_premise_plot_premise__->parameter_count, fuzzy_neuron_premise_plot_parameters__); \
    }
    
#define FUZZY_NEURON_MODEL_INIT(symbol) symbol##_create()
#define FUZZY_NEURON_MODEL_DESTROY(symbol, model) symbol##_destroy(model)
#define FUZZY_NEURON_MODEL_PREDICT(model, inputs, outputs) fuzzy_neuron_predict((model), (inputs), (outputs))
#define FUZZY_NEURON_MODEL_SAVE(model, path) fuzzy_neuron_model_save_csv((model), (path))
#define FUZZY_NEURON_MODEL_LOAD(model, path) fuzzy_neuron_model_load_csv((model), (path))
#define FUZZY_NEURON_MODEL_OPENCL_INIT(model, batch_size, kernel_path) fuzzy_neuron_opencl_init((model), (batch_size), (kernel_path))
#define FUZZY_NEURON_MODEL_OPENCL_TRAIN(model, dataset, options, loss) fuzzy_neuron_opencl_train((model), (dataset), (options), (loss))

#define FUZZY_NEURON_NETWORK(name, input_dimensions, output_dimensions) \
    fuzzy_neuron_network_t name; \
    fuzzy_neuron_init(&(name), (input_dimensions), (output_dimensions))

#define FUZZY_NEURON_RULE(symbol, expression) \
    static float fuzzy_neuron_rule_##symbol(const float x[], size_t n, void *user) \
    { \
        (void)n; \
        (void)user; \
        return (expression); \
    }

#define FUZZY_NEURON_RULE_USER(symbol, expression) \
    static float fuzzy_neuron_rule_##symbol(const float x[], size_t n, void *user) \
    { \
        (void)n; \
        return (expression); \
    }

#define FUZZY_NEURON_BIND(network, symbol) fuzzy_neuron_add_rule(&(network), #symbol, fuzzy_neuron_rule_##symbol, NULL)

#define FUZZY_NEURON_BIND_USER(network, symbol, user_ptr) \
    fuzzy_neuron_add_rule(&(network), #symbol, fuzzy_neuron_rule_##symbol, (user_ptr))

#define FUZZY_NEURON_LAYER(network, count, activation) \
    fuzzy_neuron_add_layer(&(network), (count), (activation))

#define FUZZY_NEURON_OUTPUT(network, activation) \
    fuzzy_neuron_add_layer(&(network), (network).output_dimensions, (activation))

#define FUZZY_NEURON_TRAIN_OPTIONS(epoch_count, batch_count, rate, report) \
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report), FUZZY_NEURON_OPTIMIZER_SGD, 0.9f, 0.999f, 1.0e-8f, true})
#define FUZZY_NEURON_TRAIN_OPTIONS_SGD(epoch_count, batch_count, rate, report) \
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report), FUZZY_NEURON_OPTIMIZER_SGD, 0.9f, 0.999f, 1.0e-8f, true})
#define FUZZY_NEURON_TRAIN_OPTIONS_ADAM(epoch_count, batch_count, rate, report) \
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report), FUZZY_NEURON_OPTIMIZER_ADAM, 0.9f, 0.999f, 1.0e-8f, true})
#define FUZZY_NEURON_TRAIN_OPTIONS_ADAM_CONTINUE(epoch_count, batch_count, rate, report) \
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report), FUZZY_NEURON_OPTIMIZER_ADAM, 0.9f, 0.999f, 1.0e-8f, false})
#define FUZZY_NEURON_TRAIN_OPTIONS_ADAM_CUSTOM(epoch_count, batch_count, rate, report, beta1_arg, beta2_arg, epsilon_arg, reset_arg) \
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report), FUZZY_NEURON_OPTIMIZER_ADAM, (beta1_arg), (beta2_arg), (epsilon_arg), (reset_arg)})

/* ==========================================================
 * Fuzzy-neuron model and plugin DSL
 * ========================================================== */

typedef struct fuzzy_neuron_model_plugin
{
    unsigned int abi_version;
    const char *name;
    fuzzy_neuron_network_t *(*create)(void);
    void (*destroy)(fuzzy_neuron_network_t *model);
} fuzzy_neuron_model_plugin_t;

typedef const fuzzy_neuron_model_plugin_t *(*fuzzy_neuron_model_plugin_entry_fn)(void);

typedef struct fuzzy_neuron_loaded_plugin
{
    void *library;
    const fuzzy_neuron_model_plugin_t *api;
} fuzzy_neuron_loaded_plugin_t;

#define FUZZY_NEURON_MODEL_PLUGIN(symbol, abi, plugin_name, export_specifier) \
    export_specifier const fuzzy_neuron_model_plugin_t *fuzzy_model_plugin_entry(void) \
    { \
        static const fuzzy_neuron_model_plugin_t plugin = {(abi), (plugin_name), symbol##_create, symbol##_destroy}; \
        return &plugin; \
    }

#define FUZZY_NEURON_HOT_RELOAD(symbol, plugin_path) \
    static fuzzy_neuron_loaded_plugin_t symbol##_load(void) \
    { \
        fuzzy_neuron_loaded_plugin_t plugin; \
        fuzzy_neuron_model_plugin_entry_fn entry; \
        plugin.library = dlopen((plugin_path), RTLD_NOW | RTLD_LOCAL); \
        *(void **)(&entry) = dlsym(plugin.library, "fuzzy_model_plugin_entry"); \
        plugin.api = entry(); \
        return plugin; \
    } \
    static void symbol##_unload(fuzzy_neuron_loaded_plugin_t *plugin) \
    { \
        dlclose(plugin->library); \
    }

#define FUZZY_NEURON_SWEEP_EVALUATOR(name, model_pointer, output_dimensions, output_index, output_scale) \
    static float name(const float inputs[], size_t input_count, float step) \
    { \
        float outputs[(output_dimensions)]; \
        (void)input_count; \
        (void)step; \
        fuzzy_neuron_predict((model_pointer), inputs, outputs); \
        return outputs[(output_index)] * (output_scale); \
    }

//Error methods: Huber, MSE, MAE
double fuzzy_neuron_dataset_huber(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset);
double fuzzy_neuron_dataset_mse(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset);
double fuzzy_neuron_dataset_mae(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset);

fuzzy_neuron_network_t *fuzzy_neuron_create_model(const fuzzy_neuron_model_descriptor_t *descriptor);
size_t fuzzy_neuron_add_premise(fuzzy_neuron_network_t *network, const char *name, size_t input_index, fuzzy_shape_t shape, float hedge, unsigned int trainable_mask, float domain_minimum, float domain_maximum, size_t parameter_count, const float parameters[]);
size_t fuzzy_neuron_add_expression(fuzzy_neuron_network_t *network, fuzzy_neuron_expression_kind_t kind, size_t left, size_t right, size_t value);
bool fuzzy_neuron_add_trainable_rule_root(fuzzy_neuron_network_t *network, const char *name, size_t root);
float fuzzy_neuron_evaluate_premise(const fuzzy_neuron_network_t *network, size_t premise_index, const float *raw_inputs);
bool fuzzy_neuron_trainable_rules(const fuzzy_neuron_network_t *network, const float *raw_inputs, float *raw_rules, float *normalized_rules);

void fuzzy_neuron_init(
    fuzzy_neuron_network_t *network,
    size_t raw_input_dimensions,
    size_t output_dimensions
);
void fuzzy_neuron_set_logic_method(
    fuzzy_neuron_network_t *network,
    fuzzy_logic_method_t logic_method
);

bool fuzzy_neuron_add_rule(
    fuzzy_neuron_network_t *network,
    const char *name,
    fuzzy_neuron_rule_fn evaluator,
    void *user
);

bool fuzzy_neuron_add_layer(
    fuzzy_neuron_network_t *network,
    size_t neuron_count,
    fuzzy_neuron_activation_t activation
);

bool fuzzy_neuron_compile(fuzzy_neuron_network_t *network);

void fuzzy_neuron_free(fuzzy_neuron_network_t *network);

float fuzzy_neuron_forward(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[]
);

void fuzzy_neuron_backward(
    fuzzy_neuron_network_t *network,
    const float targets[],
    float learning_rate
);

bool fuzzy_neuron_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float outputs[]
);

bool fuzzy_neuron_predict_batch(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
);

bool fuzzy_neuron_dataset_load_csv(
    const char *path,
    const fuzzy_neuron_csv_t *format,
    fuzzy_neuron_dataset_t *dataset
);

void fuzzy_neuron_dataset_free(fuzzy_neuron_dataset_t *dataset);

bool fuzzy_neuron_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options
);

bool fuzzy_neuron_model_save_csv(
    const fuzzy_neuron_network_t *network,
    const char *path
);

bool fuzzy_neuron_model_load_csv(
    fuzzy_neuron_network_t *network,
    const char *path
);

#ifdef FUZZY_NEURON_OPENCL

bool fuzzy_neuron_opencl_init(
    fuzzy_neuron_network_t *network,
    size_t batch_capacity,
    const char *kernel_path
);

bool fuzzy_neuron_opencl_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options,
    fuzzy_error_fn_t error_fn
);

bool fuzzy_neuron_opencl_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
);

void fuzzy_neuron_opencl_free(fuzzy_neuron_network_t *network);

#endif

#ifdef FUZZY_NEURON_IMPLEMENTATION

#ifndef FUZZY_NEURON_IMPLEMENTATION_ONCE
#define FUZZY_NEURON_IMPLEMENTATION_ONCE

static float fuzzy_neuron_activate(
    float value,
    fuzzy_neuron_activation_t activation
)
{
    if (activation == FUZZY_NEURON_SIGMOID)
    {
        return 1.0f / (1.0f + expf(-value));
    }

    if (activation == FUZZY_NEURON_TANH)
    {
        return tanhf(value);
    }

    if (activation == FUZZY_NEURON_RELU)
    {
        return value > 0.0f ? value : 0.0f;
    }

    return value;
}

static float fuzzy_neuron_derivative(
    float output,
    fuzzy_neuron_activation_t activation
)
{
    if (activation == FUZZY_NEURON_SIGMOID)
    {
        return output * (1.0f - output);
    }

    if (activation == FUZZY_NEURON_TANH)
    {
        return 1.0f - output * output;
    }

    if (activation == FUZZY_NEURON_RELU)
    {
        return output > 0.0f ? 1.0f : 0.0f;
    }

    return 1.0f;
}

static float fuzzy_neuron_random(
    fuzzy_neuron_network_t *network,
    size_t fan_in,
    size_t fan_out
)
{
    float unit;

    network->random_state =
        network->random_state * 1664525u + 1013904223u;

    unit =
        (float)((network->random_state >> 8) & 0xffffu) /
        32767.5f -
        1.0f;

    return unit * sqrtf(6.0f / (float)(fan_in + fan_out));
}

extern float powf(float, float);
extern float fminf(float, float);
extern float fmaxf(float, float);

static bool fuzzy_neuron_shape_parameter_count_valid(fuzzy_shape_t shape, size_t count)
{
    switch (shape)
    {
        case FUZZY_SHAPE_RAMP: return count == 3u;
        case FUZZY_SHAPE_TRIANGLE: return count == 3u;
        case FUZZY_SHAPE_TRAPEZOID: return count == 4u;
        case FUZZY_SHAPE_SMF: return count == 2u;
        case FUZZY_SHAPE_ZMF: return count == 2u;
        case FUZZY_SHAPE_GAUSSIAN: return count == 2u;
        case FUZZY_SHAPE_BELL: return count == 3u;
        case FUZZY_SHAPE_SIGMOID: return count == 2u;
        case FUZZY_SHAPE_PIMF: return count == 4u;
        case FUZZY_SHAPE_DSIGMOID: return count == 4u;
        case FUZZY_SHAPE_PSIGMOID: return count == 4u;
        case FUZZY_SHAPE_GAUSSIAN2: return count == 4u;
        default: return false;
    }
}

static bool fuzzy_neuron_shape_parameters_valid(fuzzy_shape_t shape, size_t count, const float parameters[], float epsilon)
{
    if (!fuzzy_neuron_shape_parameter_count_valid(shape, count) || parameters == NULL) return false;
    switch (shape)
    {
        case FUZZY_SHAPE_RAMP: return parameters[1] > parameters[0];
        case FUZZY_SHAPE_TRIANGLE: return parameters[0] < parameters[1] && parameters[1] < parameters[2];
        case FUZZY_SHAPE_TRAPEZOID: return parameters[0] < parameters[1] && parameters[1] <= parameters[2] && parameters[2] < parameters[3];
        case FUZZY_SHAPE_SMF:
        case FUZZY_SHAPE_ZMF: return parameters[1] > parameters[0];
        case FUZZY_SHAPE_GAUSSIAN: return fabsf(parameters[1]) > epsilon;
        case FUZZY_SHAPE_BELL: return fabsf(parameters[0]) > epsilon;
        case FUZZY_SHAPE_SIGMOID:
        case FUZZY_SHAPE_DSIGMOID:
        case FUZZY_SHAPE_PSIGMOID: return true;
        case FUZZY_SHAPE_PIMF: return parameters[0] < parameters[1] && parameters[1] <= parameters[2] && parameters[2] < parameters[3];
        case FUZZY_SHAPE_GAUSSIAN2: return fabsf(parameters[1]) > epsilon && fabsf(parameters[3]) > epsilon && parameters[0] <= parameters[2];
        default: return false;
    }
}

fuzzy_neuron_network_t *fuzzy_neuron_create_model(const fuzzy_neuron_model_descriptor_t *descriptor)
{
    fuzzy_neuron_network_t *model;
    size_t index;

    if (descriptor == NULL || descriptor->input_dimensions == 0u || descriptor->output_dimensions == 0u || descriptor->premises == NULL || descriptor->premise_count == 0u || descriptor->expressions == NULL || descriptor->expression_count == 0u || descriptor->rules == NULL || descriptor->rule_count == 0u || descriptor->layers == NULL || descriptor->layer_count == 0u)
    {
        abort();
    }

    model = malloc(sizeof(*model));

    if (model == NULL)
    {
        abort();
    }

    fuzzy_neuron_init(model, descriptor->input_dimensions, descriptor->output_dimensions);
    fuzzy_neuron_set_logic_method(model, descriptor->logic_method);

    for (index = 0u; index < descriptor->premise_count; index++)
    {
        const fuzzy_neuron_premise_descriptor_t *premise = &descriptor->premises[index];
        size_t result = fuzzy_neuron_add_premise(model, premise->name, premise->input_index, premise->shape, premise->hedge, premise->trainable_mask, premise->domain_minimum, premise->domain_maximum, premise->parameter_count, premise->parameters);

        if (result != index)
        {
            fuzzy_neuron_free(model);
            free(model);
            abort();
        }
    }

    for (index = 0u; index < descriptor->expression_count; index++)
    {
        const fuzzy_neuron_expression_t *expression = &descriptor->expressions[index];
        size_t result = fuzzy_neuron_add_expression(model, expression->kind, expression->left, expression->right, expression->value);

        if (result != index)
        {
            fuzzy_neuron_free(model);
            free(model);
            abort();
        }
    }

    for (index = 0u; index < descriptor->rule_count; index++)
    {
        const fuzzy_neuron_rule_descriptor_t *rule = &descriptor->rules[index];

        if (!fuzzy_neuron_add_trainable_rule_root(model, rule->name, rule->root))
        {
            fuzzy_neuron_free(model);
            free(model);
            abort();
        }
    }

    for (index = 0u; index < descriptor->layer_count; index++)
    {
        const fuzzy_neuron_layer_t *layer = &descriptor->layers[index];

        if (!fuzzy_neuron_add_layer(model, layer->count, layer->activation))
        {
            fuzzy_neuron_free(model);
            free(model);
            abort();
        }
    }

    if (!fuzzy_neuron_compile(model))
    {
        fuzzy_neuron_free(model);
        free(model);
        abort();
    }

    return model;
}

size_t fuzzy_neuron_add_premise(fuzzy_neuron_network_t *network, const char *name, size_t input_index, fuzzy_shape_t shape, float hedge, unsigned int trainable_mask, float domain_minimum, float domain_maximum, size_t parameter_count, const float parameters[])
{
    fuzzy_neuron_premise_t *premise;
    size_t index;
    size_t parameter_index;
    unsigned int valid_mask;

    if (network == NULL || name == NULL || parameters == NULL || network->compiled || input_index >= network->raw_input_dimensions || network->premise_count >= FUZZY_NEURON_MAX_PREMISES || parameter_count == 0u || parameter_count > FUZZY_MAX_VALUES || network->premise_parameter_count + parameter_count > FUZZY_NEURON_MAX_PREMISE_PARAMETERS || !(domain_maximum > domain_minimum) || !(hedge > 0.0f)) return ((size_t)-1);
    if (shape < FUZZY_SHAPE_RAMP || shape > FUZZY_SHAPE_GAUSSIAN2 || !fuzzy_neuron_shape_parameter_count_valid(shape, parameter_count) || !fuzzy_neuron_shape_parameters_valid(shape, parameter_count, parameters, 1.0e-4f)) return ((size_t)-1);

    valid_mask = (unsigned int)(parameter_count >= 32u ? 0xffffffffu : ((1u << parameter_count) - 1u));
    if ((trainable_mask & ~valid_mask) != 0u) return ((size_t)-1);

    index = network->premise_count++;
    premise = &network->premises[index];
    premise->name = name;
    premise->input_index = input_index;
    premise->shape = shape;
    premise->parameter_offset = network->premise_parameter_count;
    premise->parameter_count = parameter_count;
    premise->trainable_mask = trainable_mask;
    premise->hedge = hedge;
    premise->domain_minimum = domain_minimum;
    premise->domain_maximum = domain_maximum;
    premise->epsilon = 1.0e-4f;

    for (parameter_index = 0u; parameter_index < parameter_count; parameter_index++) network->premise_parameters[network->premise_parameter_count++] = parameters[parameter_index];

    if (trainable_mask != 0u) network->trainable_fuzzy = true;
    return index;
}
size_t fuzzy_neuron_add_expression(fuzzy_neuron_network_t *network, fuzzy_neuron_expression_kind_t kind, size_t left, size_t right, size_t value)
{
    fuzzy_neuron_expression_t *expression;
    size_t index;
    if (network == NULL || network->compiled || network->expression_count >= FUZZY_NEURON_MAX_EXPRESSIONS) return ((size_t)-1);
    if (kind == FUZZY_NEURON_EXPRESSION_MEMBERSHIP && value >= network->premise_count) return ((size_t)-1);
    if (kind != FUZZY_NEURON_EXPRESSION_MEMBERSHIP && left >= network->expression_count) return ((size_t)-1);
    if ((kind == FUZZY_NEURON_EXPRESSION_AND || kind == FUZZY_NEURON_EXPRESSION_OR) && right >= network->expression_count) return ((size_t)-1);
    index = network->expression_count++;
    expression = &network->expressions[index];
    expression->kind = kind;
    expression->left = left;
    expression->right = right;
    expression->value = value;
    return index;
}

bool fuzzy_neuron_add_trainable_rule_root(fuzzy_neuron_network_t *network, const char *name, size_t root)
{
    if (network == NULL || network->compiled || root >= network->expression_count || network->rule_count >= FUZZY_NEURON_MAX_RULES) return false;
    network->rules[network->rule_count].name = name;
    network->rules[network->rule_count].evaluate = NULL;
    network->rules[network->rule_count].user = NULL;
    network->rule_roots[network->rule_count++] = root;
    network->trainable_fuzzy = true;
    return true;
}

float fuzzy_neuron_evaluate_premise(const fuzzy_neuron_network_t *network, size_t premise_index, const float *raw_inputs)
{
    const fuzzy_neuron_premise_t *premise;
    const float *parameters;

    if (network == NULL || raw_inputs == NULL || premise_index >= network->premise_count)
    {
        abort();
    }

    premise = &network->premises[premise_index];

    if (premise->input_index >= network->raw_input_dimensions)
    {
        abort();
    }

    parameters = network->premise_parameters + premise->parameter_offset;

    return fuzzy_function_array(premise->shape, raw_inputs[premise->input_index], premise->hedge, premise->parameter_count, parameters);
}

bool fuzzy_neuron_trainable_rules(const fuzzy_neuron_network_t *network, const float *raw_inputs, float *raw_rules, float *normalized_rules)
{
    float memberships[FUZZY_NEURON_MAX_PREMISES];
    float values[FUZZY_NEURON_MAX_EXPRESSIONS];
    float operands[2];
    float total;
    size_t index;

    if (network == NULL || raw_inputs == NULL || raw_rules == NULL || normalized_rules == NULL || !network->trainable_fuzzy)
    {
        abort();
    }

    for (index = 0u; index < network->premise_count; index++)
    {
        memberships[index] = fuzzy_neuron_evaluate_premise(network, index, raw_inputs);
    }

    for (index = 0u; index < network->expression_count; index++)
    {
        const fuzzy_neuron_expression_t *expression = &network->expressions[index];

        switch (expression->kind)
        {
            case FUZZY_NEURON_EXPRESSION_MEMBERSHIP:
                if (expression->value >= network->premise_count)
                {
                    abort();
                }
                values[index] = memberships[expression->value];
                break;

            case FUZZY_NEURON_EXPRESSION_NOT:
                if (expression->left >= index)
                {
                    abort();
                }
                values[index] = fuzzy_not(values[expression->left]);
                break;

            case FUZZY_NEURON_EXPRESSION_AND:
                if (expression->left >= index || expression->right >= index)
                {
                    abort();
                }
                operands[0] = values[expression->left];
                operands[1] = values[expression->right];
                values[index] = fuzzy_and_array(network->logic_method, 2u, operands);
                break;

            case FUZZY_NEURON_EXPRESSION_OR:
                if (expression->left >= index || expression->right >= index)
                {
                    abort();
                }
                operands[0] = values[expression->left];
                operands[1] = values[expression->right];
                values[index] = fuzzy_or_array(network->logic_method, 2u, operands);
                break;

            default:
                abort();
        }
    }

    total = 0.0f;

    for (index = 0u; index < network->rule_count; index++)
    {
        size_t root = network->rule_roots[index];

        if (root >= network->expression_count)
        {
            abort();
        }

        raw_rules[index] = values[root];
        total += raw_rules[index];
    }

    if (total <= 1.0e-12f)
    {
        memset(normalized_rules, 0, network->rule_count * sizeof(*normalized_rules));
        return true;
    }

    for (index = 0u; index < network->rule_count; index++)
    {
        normalized_rules[index] = raw_rules[index] / total;
    }

    return true;
}

void fuzzy_neuron_init(
    fuzzy_neuron_network_t *network,
    size_t raw_input_dimensions,
    size_t output_dimensions
)
{
    if (network == NULL)
    {
        abort();
    }

    memset(network, 0, sizeof(*network));
    network->raw_input_dimensions = raw_input_dimensions;
    network->output_dimensions = output_dimensions;
    network->logic_method = FUZZY_LOGIC_STANDARD;
    network->random_state = 0x12345678u;
}

void fuzzy_neuron_set_logic_method(fuzzy_neuron_network_t *network, fuzzy_logic_method_t logic_method)
{
    if (network == NULL || network->compiled)
    {
        abort();
    }

    if (logic_method != FUZZY_LOGIC_STANDARD && logic_method != FUZZY_LOGIC_ALGEBRAIC && logic_method != FUZZY_LOGIC_BOUNDED)
    {
        abort();
    }

    network->logic_method = logic_method;
}

bool fuzzy_neuron_add_rule(
    fuzzy_neuron_network_t *network,
    const char *name,
    fuzzy_neuron_rule_fn evaluator,
    void *user
)
{
    fuzzy_neuron_rule_t *rule;

    if (network == NULL ||
        evaluator == NULL ||
        network->compiled ||
        network->rule_count >= FUZZY_NEURON_MAX_RULES)
    {
        return false;
    }

    rule = &network->rules[network->rule_count++];

    rule->name = name;
    rule->evaluate = evaluator;
    rule->user = user;

    return true;
}

bool fuzzy_neuron_add_layer(
    fuzzy_neuron_network_t *network,
    size_t neuron_count,
    fuzzy_neuron_activation_t activation
)
{
    fuzzy_neuron_layer_t *layer;

    if (network == NULL ||
        neuron_count == 0u ||
        network->compiled ||
        network->layer_count >= FUZZY_NEURON_MAX_LAYERS)
    {
        return false;
    }

    layer = &network->layers[network->layer_count++];

    memset(layer, 0, sizeof(*layer));

    layer->count = neuron_count;
    layer->activation = activation;

    return true;
}

bool fuzzy_neuron_compile(fuzzy_neuron_network_t *network)
{
    size_t layer;
    size_t source_count;
    size_t offset = 0u;
    size_t bias_offset = 0u;
    size_t index;

    if (network == NULL ||
        network->rule_count == 0u ||
        network->layer_count == 0u)
    {
        return false;
    }

    if (network->layers[network->layer_count - 1u].count !=
        network->output_dimensions)
    {
        return false;
    }

    source_count = network->rule_count;
    network->neuron_count = network->rule_count;
    network->weight_count = 0u;
    network->bias_count = 0u;

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &network->layers[layer];

        current->weight_offset = offset;
        current->bias_offset = bias_offset;

        network->weight_count += source_count * current->count;
        network->bias_count += current->count;
        network->neuron_count += current->count;

        offset += source_count * current->count;
        bias_offset += current->count;
        source_count = current->count;
    }

    network->weights =
        malloc(network->weight_count * sizeof(float));

    network->biases =
        calloc(network->bias_count, sizeof(float));

    network->activations =
        calloc(network->neuron_count, sizeof(float));

    network->deltas =
        calloc(network->neuron_count, sizeof(float));

    if (network->weights == NULL ||
        network->biases == NULL ||
        network->activations == NULL ||
        network->deltas == NULL)
    {
        return false;
    }

    source_count = network->rule_count;

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &network->layers[layer];

        for (index = 0u;
             index < source_count * current->count;
             index++)
        {
            network->weights[current->weight_offset + index] =
                fuzzy_neuron_random(
                    network,
                    source_count,
                    current->count
                );
        }

        source_count = current->count;
    }

    network->compiled = true;

    return true;
}

static void fuzzy_neuron_normalize_rules(float *rules, size_t rule_count)
{
    float total = 0.0f;
    size_t rule;

    for (rule = 0u; rule < rule_count; rule++)
    {
        total += rules[rule];
    }

    if (total > 1.0e-12f)
    {
        for (rule = 0u; rule < rule_count; rule++)
        {
            rules[rule] /= total;
        }
    }
}

static void fuzzy_neuron_rules(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float values[]
)
{
    size_t rule;

    if (network->trainable_fuzzy)
    {
        float normalized[FUZZY_NEURON_MAX_RULES];

        if (!fuzzy_neuron_trainable_rules(network, raw_inputs, values, normalized))
        {
            memset(values, 0, network->rule_count * sizeof(*values));
        }

        return;
    }

    for (rule = 0u; rule < network->rule_count; rule++)
    {
        if (network->rules[rule].evaluate == NULL)
        {
            values[rule] = 0.0f;
        }
        else
        {
            values[rule] = network->rules[rule].evaluate(raw_inputs, network->raw_input_dimensions, network->rules[rule].user);
        }
    }
}

float fuzzy_neuron_forward(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[]
)
{
    size_t rule;
    size_t layer;
    size_t source;
    size_t destination;
    size_t source_count;
    size_t source_offset = 0u;
    size_t destination_offset = network->rule_count;
    float total = 0.0f;

    fuzzy_neuron_rules(
        network,
        raw_inputs,
        network->activations
    );

    for (rule = 0u; rule < network->rule_count; rule++)
    {
        total += network->activations[rule];
    }

    if (total > 1.0e-12f)
    {
        for (rule = 0u; rule < network->rule_count; rule++)
        {
            network->activations[rule] /= total;
        }
    }

    source_count = network->rule_count;

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        fuzzy_neuron_layer_t *current = &network->layers[layer];

        for (destination = 0u;
             destination < current->count;
             destination++)
        {
            float sum =
                network->biases[
                    current->bias_offset + destination
                ];

            for (source = 0u;
                 source < source_count;
                 source++)
            {
                sum +=
                    network->activations[
                        source_offset + source
                    ] *
                    network->weights[
                        current->weight_offset +
                        destination * source_count +
                        source
                    ];
            }

            network->activations[
                destination_offset + destination
            ] =
                fuzzy_neuron_activate(
                    sum,
                    current->activation
                );
        }

        source_offset = destination_offset;
        destination_offset += current->count;
        source_count = current->count;
    }

    return network->activations[
        destination_offset - network->output_dimensions
    ];
}

void fuzzy_neuron_backward(
    fuzzy_neuron_network_t *network,
    const float targets[],
    float learning_rate
)
{
    size_t layer;
    size_t source;
    size_t destination;
    size_t source_count;
    size_t source_offset;
    size_t destination_offset;
    size_t output_offset =
        network->neuron_count - network->output_dimensions;

    fuzzy_neuron_layer_t *output_layer =
        &network->layers[network->layer_count - 1u];

    for (destination = 0u;
         destination < network->output_dimensions;
         destination++)
    {
        float output =
            network->activations[
                output_offset + destination
            ];

        network->deltas[
            output_offset + destination
        ] =
            (output - targets[destination]) *
            fuzzy_neuron_derivative(
                output,
                output_layer->activation
            );
    }

    for (layer = network->layer_count; layer-- > 0u;)
    {
        fuzzy_neuron_layer_t *current =
            &network->layers[layer];

        source_count =
            layer == 0u
                ? network->rule_count
                : network->layers[layer - 1u].count;

        source_offset =
            layer == 0u
                ? 0u
                : network->rule_count;

        for (destination = 0u;
             destination + 1u < layer;
             destination++)
        {
            source_offset +=
                network->layers[destination].count;
        }

        destination_offset =
            source_offset + source_count;

        for (source = 0u;
             source < source_count;
             source++)
        {
            float propagated = 0.0f;

            for (destination = 0u;
                 destination < current->count;
                 destination++)
            {
                propagated +=
                    network->weights[
                        current->weight_offset +
                        destination * source_count +
                        source
                    ] *
                    network->deltas[
                        destination_offset + destination
                    ];
            }

            if (layer > 0u)
            {
                propagated *=
                    fuzzy_neuron_derivative(
                        network->activations[
                            source_offset + source
                        ],
                        network->layers[layer - 1u].activation
                    );
            }

            network->deltas[
                source_offset + source
            ] = propagated;
        }

        for (destination = 0u;
             destination < current->count;
             destination++)
        {
            float delta =
                network->deltas[
                    destination_offset + destination
                ];

            network->biases[
                current->bias_offset + destination
            ] -= learning_rate * delta;

            for (source = 0u;
                 source < source_count;
                 source++)
            {
                network->weights[
                    current->weight_offset +
                    destination * source_count +
                    source
                ] -=
                    learning_rate *
                    delta *
                    network->activations[
                        source_offset + source
                    ];
            }
        }
    }
}

bool fuzzy_neuron_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float outputs[]
)
{
    size_t index;
    size_t offset;

    if (network == NULL ||
        !network->compiled ||
        raw_inputs == NULL ||
        outputs == NULL)
    {
        return false;
    }

    fuzzy_neuron_forward(
        network,
        raw_inputs
    );

    offset =
        network->neuron_count -
        network->output_dimensions;

    for (index = 0u;
         index < network->output_dimensions;
         index++)
    {
        outputs[index] =
            network->activations[offset + index];
    }

    return true;
}

bool fuzzy_neuron_predict_batch(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
)
{
    size_t row;

    for (row = 0u; row < rows; row++)
    {
        if (!fuzzy_neuron_predict(
                network,
                raw_inputs +
                    row *
                    network->raw_input_dimensions,
                outputs +
                    row *
                    network->output_dimensions
            ))
        {
            return false;
        }
    }

    return true;
}

bool fuzzy_neuron_dataset_load_csv(
    const char *path,
    const fuzzy_neuron_csv_t *format,
    fuzzy_neuron_dataset_t *dataset
)
{
    FILE *file;
    char line[4096];
    size_t capacity = 1024u;
    size_t row = 0u;
    size_t column;
    size_t total;
    char separator;

    if (path == NULL ||
        format == NULL ||
        dataset == NULL)
    {
        return false;
    }

    memset(dataset, 0, sizeof(*dataset));

    file = fopen(path, "r");

    if (file == NULL)
    {
        return false;
    }

    separator =
        format->separator
            ? format->separator
            : ',';

    total =
        format->input_dimensions +
        format->target_dimensions;

    dataset->inputs =
        malloc(
            capacity *
            format->input_dimensions *
            sizeof(float)
        );

    dataset->targets =
        malloc(
            capacity *
            format->target_dimensions *
            sizeof(float)
        );

    if (dataset->inputs == NULL ||
        dataset->targets == NULL)
    {
        fclose(file);
        fuzzy_neuron_dataset_free(dataset);
        return false;
    }

    if (format->header &&
        fgets(line, sizeof(line), file) == NULL)
    {
        fclose(file);
        fuzzy_neuron_dataset_free(dataset);
        return false;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *cursor = line;
        char *end;

        if (row == capacity)
        {
            float *inputs;
            float *targets;

            capacity *= 2u;

            inputs =
                realloc(
                    dataset->inputs,
                    capacity *
                    format->input_dimensions *
                    sizeof(float)
                );

            targets =
                realloc(
                    dataset->targets,
                    capacity *
                    format->target_dimensions *
                    sizeof(float)
                );

            if (inputs == NULL ||
                targets == NULL)
            {
                fclose(file);
                return false;
            }

            dataset->inputs = inputs;
            dataset->targets = targets;
        }

        for (column = 0u;
             column < total;
             column++)
        {
            float value =
                strtof(cursor, &end);

            if (end == cursor)
            {
                break;
            }

            if (column < format->input_dimensions)
            {
                dataset->inputs[
                    row *
                    format->input_dimensions +
                    column
                ] =
                    value /
                    (
                        format->input_scales
                            ? format->input_scales[column]
                            : 1.0f
                    );
            }
            else
            {
                size_t target =
                    column -
                    format->input_dimensions;

                dataset->targets[
                    row *
                    format->target_dimensions +
                    target
                ] =
                    value /
                    (
                        format->target_scales
                            ? format->target_scales[target]
                            : 1.0f
                    );
            }

            cursor = end;

            if (column + 1u < total &&
                *cursor == separator)
            {
                cursor++;
            }
        }

        if (column == total)
        {
            row++;
        }
    }

    fclose(file);

    dataset->rows = row;
    dataset->input_dimensions =
        format->input_dimensions;

    dataset->target_dimensions =
        format->target_dimensions;

    return row > 0u;
}

void fuzzy_neuron_dataset_free(
    fuzzy_neuron_dataset_t *dataset
)
{
    if (dataset == NULL)
    {
        return;
    }

    free(dataset->inputs);
    free(dataset->targets);

    memset(dataset, 0, sizeof(*dataset));
}

bool fuzzy_neuron_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options
)
{
    size_t epoch;
    size_t row;

    if (network == NULL ||
        dataset == NULL ||
        options == NULL ||
        !network->compiled)
    {
        return false;
    }

    if (dataset->input_dimensions !=
            network->raw_input_dimensions ||
        dataset->target_dimensions !=
            network->output_dimensions)
    {
        return false;
    }

    for (epoch = 0u;
         epoch < options->epochs;
         epoch++)
    {
        double loss = 0.0;

        for (row = 0u;
             row < dataset->rows;
             row++)
        {
            size_t output;

            fuzzy_neuron_forward(
                network,
                dataset->inputs +
                    row *
                    dataset->input_dimensions
            );

            for (output = 0u;
                 output <
                    network->output_dimensions;
                 output++)
            {
                float error =
                    network->activations[
                        network->neuron_count -
                        network->output_dimensions +
                        output
                    ] -
                    dataset->targets[
                        row *
                        dataset->target_dimensions +
                        output
                    ];

                loss +=
                    (double)error *
                    error;
            }

            fuzzy_neuron_backward(
                network,
                dataset->targets +
                    row *
                    dataset->target_dimensions,
                options->learning_rate
            );
        }

        if (options->report_every &&
            (
                epoch %
                    options->report_every ==
                    0u ||
                epoch + 1u ==
                    options->epochs
            ))
        {
            printf(
                "Epoch %4u MSE %.10f\n",
                (unsigned int)(epoch + 1u),
                loss /
                    (double)(
                        dataset->rows *
                        network->output_dimensions
                    )
            );
        }
    }

    return true;
}

bool fuzzy_neuron_model_save_csv(
    const fuzzy_neuron_network_t *network,
    const char *path
)
{
    FILE *file;
    size_t index;

    if (network == NULL ||
        path == NULL ||
        !network->compiled)
    {
        return false;
    }

    file = fopen(path, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf(
        file,
        "FNN2,%zu,%zu,%zu,%zu,%zu\n",
        network->raw_input_dimensions,
        network->output_dimensions,
        network->rule_count,
        network->layer_count,
        network->weight_count
    );

    fprintf(file, "LAYERS");

    for (index = 0u;
         index < network->layer_count;
         index++)
    {
        fprintf(
            file,
            ",%zu:%u",
            network->layers[index].count,
            (unsigned)network->layers[index].activation
        );
    }

    fprintf(file, "\n");
    fprintf(file, "WEIGHTS");

    for (index = 0u;
         index < network->weight_count;
         index++)
    {
        fprintf(
            file,
            ",%.9g",
            network->weights[index]
        );
    }

    fprintf(file, "\n");
    fprintf(file, "PREMISES");
    for (index = 0u; index < network->premise_parameter_count; index++) fprintf(file, ",%.9g", network->premise_parameters[index]);
    fprintf(file, "\n");
    fprintf(file, "BIASES");

    for (index = 0u;
         index < network->bias_count;
         index++)
    {
        fprintf(
            file,
            ",%.9g",
            network->biases[index]
        );
    }

    fprintf(file, "\n");
    fclose(file);

    return true;
}

bool fuzzy_neuron_model_load_csv(
    fuzzy_neuron_network_t *network,
    const char *path
)
{
    FILE *file;
    char line[65536];
    char *cursor;
    char *end;
    size_t index;

    if (network == NULL ||
        path == NULL ||
        !network->compiled)
    {
        return false;
    }

    file = fopen(path, "r");

    if (file == NULL)
    {
        return false;
    }

    if (fgets(line, sizeof(line), file) == NULL ||
        strncmp(line, "FNN2,", 5) != 0)
    {
        fclose(file);
        return false;
    }

    if (fgets(line, sizeof(line), file) == NULL)
    {
        fclose(file);
        return false;
    }

    if (fgets(line, sizeof(line), file) == NULL ||
        strncmp(line, "WEIGHTS", 7) != 0)
    {
        fclose(file);
        return false;
    }

    cursor = line + 7;

    for (index = 0u;
         index < network->weight_count;
         index++)
    {
        if (*cursor == ',')
        {
            cursor++;
        }

        network->weights[index] =
            strtof(cursor, &end);

        if (end == cursor)
        {
            fclose(file);
            return false;
        }

        cursor = end;
    }

    if (fgets(line, sizeof(line), file) == NULL || strncmp(line, "PREMISES", 8) != 0)
    {
        fclose(file);
        return false;
    }
    cursor = line + 8;
    for (index = 0u; index < network->premise_parameter_count; index++)
    {
        if (*cursor == ',') cursor++;
        network->premise_parameters[index] = strtof(cursor, &end);
        if (end == cursor) { fclose(file); return false; }
        cursor = end;
    }
    if (fgets(line, sizeof(line), file) == NULL ||
        strncmp(line, "BIASES", 6) != 0)
    {
        fclose(file);
        return false;
    }

    cursor = line + 6;

    for (index = 0u;
         index < network->bias_count;
         index++)
    {
        if (*cursor == ',')
        {
            cursor++;
        }

        network->biases[index] =
            strtof(cursor, &end);

        if (end == cursor)
        {
            fclose(file);
            return false;
        }

        cursor = end;
    }

    fclose(file);

    return true;
}

void fuzzy_neuron_free(
    fuzzy_neuron_network_t *network
)
{
    if (network == NULL)
    {
        return;
    }

#ifdef FUZZY_NEURON_OPENCL
    fuzzy_neuron_opencl_free(network);
#endif

    free(network->weights);
    free(network->biases);
    free(network->activations);
    free(network->deltas);
    free(network->flat_rule_inputs);

    memset(network, 0, sizeof(*network));
}

#ifdef FUZZY_NEURON_OPENCL

static char *fuzzy_neuron_read_text(
    const char *path
)
{
    FILE *file;
    long size;
    char *text;

    file = fopen(path, "rb");

    if (file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    text = malloc((size_t)size + 1u);

    if (text == NULL)
    {
        fclose(file);
        return NULL;
    }

    if (fread(
            text,
            1u,
            (size_t)size,
            file
        ) != (size_t)size)
    {
        free(text);
        fclose(file);
        return NULL;
    }

    text[size] = '\0';

    fclose(file);

    return text;
}

typedef struct fuzzy_neuron_opencl_premise_abi
{
    cl_uint input_index;
    cl_uint shape;
    cl_uint parameter_offset;
    cl_uint parameter_count;
    cl_uint trainable_mask;
    cl_uint reserved0;
    cl_float hedge;
    cl_float domain_minimum;
    cl_float domain_maximum;
    cl_float epsilon;
} fuzzy_neuron_opencl_premise_abi_t;

typedef struct fuzzy_neuron_opencl_expression_abi
{
    cl_uint kind;
    cl_uint left;
    cl_uint right;
    cl_uint value;
} fuzzy_neuron_opencl_expression_abi_t;

static void fuzzy_neuron_opencl_release(
    fuzzy_neuron_opencl_t *cl
)
{
    if (cl == NULL) return;
#define FUZZY_NEURON_RELEASE_MEM(member) do { if (cl->member != NULL) clReleaseMemObject(cl->member); } while (0)
#define FUZZY_NEURON_RELEASE_KERNEL(member) do { if (cl->member != NULL) clReleaseKernel(cl->member); } while (0)
    FUZZY_NEURON_RELEASE_MEM(d_best_premise_parameters);
    FUZZY_NEURON_RELEASE_MEM(d_best_biases);
    FUZZY_NEURON_RELEASE_MEM(d_best_weights);
    FUZZY_NEURON_RELEASE_MEM(d_best_updated);
    FUZZY_NEURON_RELEASE_MEM(d_best_loss);
    FUZZY_NEURON_RELEASE_MEM(d_epoch_loss);
    FUZZY_NEURON_RELEASE_MEM(d_loss_partials);
    FUZZY_NEURON_RELEASE_MEM(d_outputs);
    FUZZY_NEURON_RELEASE_MEM(d_dataset_targets);
    FUZZY_NEURON_RELEASE_MEM(d_dataset_inputs);
    FUZZY_NEURON_RELEASE_MEM(d_bias_second_moment);
    FUZZY_NEURON_RELEASE_MEM(d_bias_first_moment);
    FUZZY_NEURON_RELEASE_MEM(d_weight_second_moment);
    FUZZY_NEURON_RELEASE_MEM(d_weight_first_moment);
    FUZZY_NEURON_RELEASE_MEM(d_premise_second_moment);
    FUZZY_NEURON_RELEASE_MEM(d_premise_first_moment);
    FUZZY_NEURON_RELEASE_MEM(d_bias_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_weight_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_premise_parameter_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_membership_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_expression_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_raw_rule_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_normalized_rule_gradients);
    FUZZY_NEURON_RELEASE_MEM(d_raw_rules);
    FUZZY_NEURON_RELEASE_MEM(d_expression_values);
    FUZZY_NEURON_RELEASE_MEM(d_memberships);
    FUZZY_NEURON_RELEASE_MEM(d_rule_roots);
    FUZZY_NEURON_RELEASE_MEM(d_expressions);
    FUZZY_NEURON_RELEASE_MEM(d_premise_parameters);
    FUZZY_NEURON_RELEASE_MEM(d_premises);
    FUZZY_NEURON_RELEASE_MEM(d_raw_inputs);
    FUZZY_NEURON_RELEASE_MEM(d_losses);
    FUZZY_NEURON_RELEASE_MEM(d_deltas);
    FUZZY_NEURON_RELEASE_MEM(d_activations);
    FUZZY_NEURON_RELEASE_MEM(d_biases);
    FUZZY_NEURON_RELEASE_MEM(d_weights);
    FUZZY_NEURON_RELEASE_MEM(d_targets);
    FUZZY_NEURON_RELEASE_KERNEL(fuzzy_update_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(fuzzy_backward_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(layer_backward_update_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(hidden_delta_gemm_tiled_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(forward_gemm_tiled_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(gather_outputs_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(conditional_copy_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(best_model_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(loss_reduce_final_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(loss_reduce_stage_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(project_premises_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(adam_premises_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(adam_biases_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(adam_weights_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(apply_premises_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(apply_biases_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(apply_weights_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(premise_gradient_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(expression_backward_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(normalize_backward_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(input_delta_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(bias_gradient_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(weight_gradient_gemm_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(hidden_delta_gemm_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(output_delta_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(forward_gemm_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(normalize_rules_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(expression_forward_kernel);
    FUZZY_NEURON_RELEASE_KERNEL(premise_forward_kernel);
#undef FUZZY_NEURON_RELEASE_MEM
#undef FUZZY_NEURON_RELEASE_KERNEL
    if (cl->program != NULL) clReleaseProgram(cl->program);
    if (cl->queue != NULL) clReleaseCommandQueue(cl->queue);
    if (cl->context != NULL) clReleaseContext(cl->context);
    memset(cl, 0, sizeof(*cl));
}

static size_t fuzzy_neuron_opencl_layer_source_offset(
    const fuzzy_neuron_network_t *network,
    size_t layer
)
{
    size_t offset = 0u;
    size_t index;

    if (layer == 0u)
    {
        return 0u;
    }

    offset = network->rule_count;

    for (index = 0u; index + 1u < layer; ++index)
    {
        offset += network->layers[index].count;
    }

    return offset;
}

static size_t fuzzy_neuron_opencl_layer_destination_offset(
    const fuzzy_neuron_network_t *network,
    size_t layer
)
{
    return fuzzy_neuron_opencl_layer_source_offset(network, layer) +
        (layer == 0u ? network->rule_count : network->layers[layer - 1u].count);
}

static bool fuzzy_neuron_opencl_create_kernel(
    cl_program program,
    const char *name,
    cl_kernel *kernel
)
{
    cl_int error;

    *kernel = clCreateKernel(program, name, &error);
    if (error != CL_SUCCESS || *kernel == NULL)
    {
        fprintf(stderr, "OpenCL fail-fast: cannot create kernel %s: %d\n", name, error);
        *kernel = NULL;
        return false;
    }
    return true;
}

static bool fuzzy_neuron_opencl_reduction_local_size(
    fuzzy_neuron_opencl_t *cl,
    cl_kernel kernel,
    size_t item_count,
    size_t local_element_size,
    size_t *local_size
)
{
    size_t device_maximum;
    size_t kernel_maximum;
    size_t preferred_multiple;
    cl_ulong device_local_memory;
    cl_ulong kernel_static_local_memory;
    size_t limit;
    size_t selected;
    cl_int error;

    if (cl == NULL ||
        kernel == NULL ||
        item_count == 0u ||
        local_element_size == 0u ||
        local_size == NULL)
    {
        return false;
    }

    error = clGetDeviceInfo(
        cl->device,
        CL_DEVICE_MAX_WORK_GROUP_SIZE,
        sizeof(device_maximum),
        &device_maximum,
        NULL
    );

    error |= clGetDeviceInfo(
        cl->device,
        CL_DEVICE_LOCAL_MEM_SIZE,
        sizeof(device_local_memory),
        &device_local_memory,
        NULL
    );

    error |= clGetKernelWorkGroupInfo(
        kernel,
        cl->device,
        CL_KERNEL_WORK_GROUP_SIZE,
        sizeof(kernel_maximum),
        &kernel_maximum,
        NULL
    );

    error |= clGetKernelWorkGroupInfo(
        kernel,
        cl->device,
        CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE,
        sizeof(preferred_multiple),
        &preferred_multiple,
        NULL
    );

    error |= clGetKernelWorkGroupInfo(
        kernel,
        cl->device,
        CL_KERNEL_LOCAL_MEM_SIZE,
        sizeof(kernel_static_local_memory),
        &kernel_static_local_memory,
        NULL
    );

    if (error != CL_SUCCESS)
    {
        return false;
    }

    if (kernel_static_local_memory >= device_local_memory)
    {
        return false;
    }

    limit = item_count;

    if (limit > device_maximum)
    {
        limit = device_maximum;
    }

    if (limit > kernel_maximum)
    {
        limit = kernel_maximum;
    }

    {
        size_t local_memory_limit =
            (size_t)(
                (device_local_memory - kernel_static_local_memory) /
                (cl_ulong)local_element_size
            );

        if (limit > local_memory_limit)
        {
            limit = local_memory_limit;
        }
    }

    if (limit == 0u)
    {
        return false;
    }

    selected = 1u;

    while (selected <= limit / 2u)
    {
        selected *= 2u;
    }

    if (preferred_multiple > 1u &&
        selected >= preferred_multiple)
    {
        while (selected > 1u &&
               selected % preferred_multiple != 0u)
        {
            selected /= 2u;
        }
    }

    if (selected == 0u)
    {
        return false;
    }

    *local_size = selected;

    return true;
}

static bool fuzzy_neuron_opencl_tiled_local_size(
    fuzzy_neuron_opencl_t *cl,
    cl_kernel kernel,
    size_t first_count,
    size_t second_count,
    size_t *first_local,
    size_t *second_local
)
{
    size_t device_maximum;
    size_t kernel_maximum;
    cl_ulong device_local_memory;
    cl_ulong kernel_local_memory;
    size_t first;
    size_t second;
    cl_int error;

    if (cl == NULL || kernel == NULL || first_count == 0u || second_count == 0u || first_local == NULL || second_local == NULL)
    {
        return false;
    }

    error = clGetDeviceInfo(cl->device, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(device_maximum), &device_maximum, NULL);
    error |= clGetDeviceInfo(cl->device, CL_DEVICE_LOCAL_MEM_SIZE, sizeof(device_local_memory), &device_local_memory, NULL);
    error |= clGetKernelWorkGroupInfo(kernel, cl->device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(kernel_maximum), &kernel_maximum, NULL);
    error |= clGetKernelWorkGroupInfo(kernel, cl->device, CL_KERNEL_LOCAL_MEM_SIZE, sizeof(kernel_local_memory), &kernel_local_memory, NULL);
    if (error != CL_SUCCESS || kernel_local_memory >= device_local_memory)
    {
        return false;
    }

    first = 1u;
    second = 1u;
    for (;;)
    {
        size_t next_first = first;
        size_t next_second = second;
        size_t local_bytes;

        if ((first <= second && first < first_count) || second >= second_count)
        {
            next_first = first <= first_count / 2u ? first * 2u : first;
        }
        else
        {
            next_second = second <= second_count / 2u ? second * 2u : second;
        }

        if (next_first == first && next_second == second)
        {
            break;
        }
        if (next_first > device_maximum / next_second || next_first * next_second > kernel_maximum)
        {
            break;
        }

        local_bytes = (next_first * next_second + next_second * next_second) * sizeof(float);
        if ((cl_ulong)local_bytes > device_local_memory - kernel_local_memory)
        {
            break;
        }

        first = next_first;
        second = next_second;
    }

    *first_local = first;
    *second_local = second;
    return true;
}

bool fuzzy_neuron_opencl_init(
    fuzzy_neuron_network_t *network,
    size_t batch_capacity,
    const char *kernel_path
)
{
    fuzzy_neuron_opencl_t *cl;
    cl_int error;
    char *source;
    char *log = NULL;
    size_t log_size = 0u;
    cl_uint platform_count = 0u;
    cl_platform_id *platforms = NULL;
    cl_uint platform_index;
    bool required_device_found = false;

    if (network == NULL || !network->compiled || kernel_path == NULL || batch_capacity == 0u)
    {
        return false;
    }

    cl = &network->opencl;
    fuzzy_neuron_opencl_release(cl);
    cl->batch_capacity = batch_capacity;


    source = fuzzy_neuron_read_text(kernel_path);

    if (source == NULL)
    {
        return false;
    }

    error = clGetPlatformIDs(0u, NULL, &platform_count);

    if (error != CL_SUCCESS || platform_count == 0u)
    {
        fprintf(stderr, "OpenCL fail-fast: no OpenCL platform is available\n");
        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    platforms = malloc(platform_count * sizeof(*platforms));

    if (platforms == NULL)
    {
        fprintf(stderr, "OpenCL fail-fast: platform list allocation failed\n");
        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    error = clGetPlatformIDs(platform_count, platforms, NULL);

    if (error != CL_SUCCESS)
    {
        fprintf(stderr, "OpenCL fail-fast: platform enumeration failed: %d\n", error);
        free(platforms);
        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    {
        cl_ulong best_score = 0u;
        cl_ulong best_global_memory = 0u;
        cl_uint gpu_count = 0u;

        for (platform_index = 0u; platform_index < platform_count; ++platform_index)
        {
            cl_uint device_count = 0u;
            cl_device_id *devices = NULL;
            cl_uint device_index;

            error = clGetDeviceIDs(platforms[platform_index], CL_DEVICE_TYPE_GPU, 0u, NULL, &device_count);

            if (error == CL_DEVICE_NOT_FOUND || device_count == 0u)
            {
                continue;
            }

            if (error != CL_SUCCESS)
            {
                fprintf(stderr, "OpenCL fail-fast: GPU enumeration failed on platform %u: %d\n", platform_index, error);
                free(platforms);
                free(source);
                fuzzy_neuron_opencl_release(cl);
                return false;
            }

            devices = malloc(device_count * sizeof(*devices));

            if (devices == NULL)
            {
                fprintf(stderr, "OpenCL fail-fast: GPU device list allocation failed\n");
                free(platforms);
                free(source);
                fuzzy_neuron_opencl_release(cl);
                return false;
            }

            error = clGetDeviceIDs(platforms[platform_index], CL_DEVICE_TYPE_GPU, device_count, devices, NULL);

            if (error != CL_SUCCESS)
            {
                fprintf(stderr, "OpenCL fail-fast: GPU device enumeration failed: %d\n", error);
                free(devices);
                free(platforms);
                free(source);
                fuzzy_neuron_opencl_release(cl);
                return false;
            }

            for (device_index = 0u; device_index < device_count; ++device_index)
            {
                char device_name[256] = {0};
                char device_vendor[256] = {0};
                cl_device_type device_type = 0u;
                cl_bool device_available = CL_FALSE;
                cl_bool compiler_available = CL_FALSE;
                cl_uint compute_units = 0u;
                cl_uint clock_frequency = 0u;
                cl_ulong global_memory = 0u;
                cl_ulong score;

                if (clGetDeviceInfo(devices[device_index], CL_DEVICE_NAME, sizeof(device_name), device_name, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_VENDOR, sizeof(device_vendor), device_vendor, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_TYPE, sizeof(device_type), &device_type, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_AVAILABLE, sizeof(device_available), &device_available, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_COMPILER_AVAILABLE, sizeof(compiler_available), &compiler_available, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(compute_units), &compute_units, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(clock_frequency), &clock_frequency, NULL) != CL_SUCCESS ||
                    clGetDeviceInfo(devices[device_index], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(global_memory), &global_memory, NULL) != CL_SUCCESS)
                {
                    fprintf(stderr, "OpenCL fail-fast: GPU identity or capability query failed\n");
                    free(devices);
                    free(platforms);
                    free(source);
                    fuzzy_neuron_opencl_release(cl);
                    return false;
                }

                if ((device_type & CL_DEVICE_TYPE_GPU) == 0u || device_available != CL_TRUE || compiler_available != CL_TRUE)
                {
                    continue;
                }

                ++gpu_count;
                score = (cl_ulong)compute_units * (cl_ulong)clock_frequency;

                printf("OpenCL GPU candidate %u: %s | %s | compute units %u | clock %u MHz | memory %.2f MiB\n", gpu_count, device_vendor, device_name, compute_units, clock_frequency, (double)global_memory / 1048576.0);

                if (!required_device_found || score > best_score || (score == best_score && global_memory > best_global_memory))
                {
                    cl->platform = platforms[platform_index];
                    cl->device = devices[device_index];
                    best_score = score;
                    best_global_memory = global_memory;
                    required_device_found = true;
                }
            }

            free(devices);
        }

        free(platforms);

        if (!required_device_found)
        {
            fprintf(stderr, "OpenCL fail-fast: no available GPU with an OpenCL compiler was found; CPU/default/software fallback is forbidden\n");
            free(source);
            fuzzy_neuron_opencl_release(cl);
            return false;
        }

        printf("OpenCL GPU candidates discovered: %u\n", gpu_count);
    }

    {
        char platform_name[256] = {0};
        char device_name[256] = {0};
        char device_vendor[256] = {0};
        cl_uint compute_units = 0u;
        size_t maximum_work_group_size = 0u;

        if (clGetPlatformInfo(cl->platform, CL_PLATFORM_NAME, sizeof(platform_name), platform_name, NULL) != CL_SUCCESS ||
            clGetDeviceInfo(cl->device, CL_DEVICE_NAME, sizeof(device_name), device_name, NULL) != CL_SUCCESS ||
            clGetDeviceInfo(cl->device, CL_DEVICE_VENDOR, sizeof(device_vendor), device_vendor, NULL) != CL_SUCCESS ||
            clGetDeviceInfo(cl->device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(compute_units), &compute_units, NULL) != CL_SUCCESS ||
            clGetDeviceInfo(cl->device, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(maximum_work_group_size), &maximum_work_group_size, NULL) != CL_SUCCESS)
        {
            fprintf(stderr, "OpenCL fail-fast: selected GPU capabilities could not be queried\n");
            free(source);
            fuzzy_neuron_opencl_release(cl);
            return false;
        }

        printf("\n============================================================\n");
        printf("OpenCL Selected GPU\n");
        printf("============================================================\n");
        printf("Platform:                    %s\n", platform_name);
        printf("Device:                      %s\n", device_name);
        printf("Vendor:                      %s\n", device_vendor);
        printf("Type:                        GPU\n");
        printf("Compute units:               %u\n", compute_units);
        printf("Maximum work-group size:     %u\n", (unsigned int)maximum_work_group_size);
        printf("CPU/default fallback:        forbidden\n");
        printf("============================================================\n");
    }

    cl->context = clCreateContext(NULL, 1u, &cl->device, NULL, NULL, &error);

    if (error != CL_SUCCESS || cl->context == NULL)
    {
        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    cl->queue = clCreateCommandQueue(cl->context, cl->device, CL_QUEUE_PROFILING_ENABLE, &error);

    if (error != CL_SUCCESS || cl->queue == NULL)
    {
        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    cl->program = clCreateProgramWithSource(cl->context, 1u, (const char **)&source, NULL, &error);

    if (error != CL_SUCCESS || cl->program == NULL)
    {
        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    error = clBuildProgram(cl->program, 1u, &cl->device, "-cl-mad-enable", NULL, NULL);

    if (error != CL_SUCCESS)
    {
        clGetProgramBuildInfo(cl->program, cl->device, CL_PROGRAM_BUILD_LOG, 0u, NULL, &log_size);
        log = malloc(log_size + 1u);

        if (log != NULL)
        {
            clGetProgramBuildInfo(cl->program, cl->device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
            log[log_size] = '\0';
            fprintf(stderr, "%s\n", log);
            free(log);
        }

        free(source);
        fuzzy_neuron_opencl_release(cl);
        return false;
    }

    free(source);

if (!fuzzy_neuron_opencl_create_kernel(cl->program, "fn_premise_forward", &cl->premise_forward_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_expression_forward", &cl->expression_forward_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_normalize_rules", &cl->normalize_rules_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_forward_gemm", &cl->forward_gemm_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_output_delta", &cl->output_delta_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_hidden_delta_gemm", &cl->hidden_delta_gemm_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_input_delta", &cl->input_delta_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_normalize_backward", &cl->normalize_backward_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_expression_backward", &cl->expression_backward_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_premise_gradient", &cl->premise_gradient_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_weight_gradient_gemm", &cl->weight_gradient_gemm_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_bias_gradient", &cl->bias_gradient_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_apply_parameters", &cl->apply_weights_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_apply_parameters", &cl->apply_biases_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_apply_parameters", &cl->apply_premises_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_adam_apply", &cl->adam_weights_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_adam_apply", &cl->adam_biases_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_adam_apply", &cl->adam_premises_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_project_premises", &cl->project_premises_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_loss_reduce_stage", &cl->loss_reduce_stage_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_loss_reduce_final", &cl->loss_reduce_final_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_best_model", &cl->best_model_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_conditional_copy", &cl->conditional_copy_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_gather_outputs", &cl->gather_outputs_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_forward_gemm_tiled", &cl->forward_gemm_tiled_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_hidden_delta_gemm_tiled", &cl->hidden_delta_gemm_tiled_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_layer_backward_update", &cl->layer_backward_update_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_fuzzy_backward", &cl->fuzzy_backward_kernel) ||
    !fuzzy_neuron_opencl_create_kernel(cl->program, "fn_fuzzy_update", &cl->fuzzy_update_kernel))
{
    fuzzy_neuron_opencl_release(cl);
    return false;
}

    {
        fuzzy_neuron_opencl_premise_abi_t *premises;
        fuzzy_neuron_opencl_expression_abi_t *expressions;
        cl_uint *rule_roots;
        size_t index;
        premises = malloc(network->premise_count * sizeof(*premises));
        expressions = malloc(network->expression_count * sizeof(*expressions));
        rule_roots = malloc(network->rule_count * sizeof(*rule_roots));
        if (premises == NULL || expressions == NULL || rule_roots == NULL)
        {
            free(premises);
            free(expressions);
            free(rule_roots);
            goto failure;
        }
        for (index = 0u; index < network->premise_count; index++)
        {
            premises[index].input_index = (cl_uint)network->premises[index].input_index;
            premises[index].shape = (cl_uint)network->premises[index].shape;
            premises[index].parameter_offset = (cl_uint)network->premises[index].parameter_offset;
            premises[index].parameter_count = (cl_uint)network->premises[index].parameter_count;
            premises[index].trainable_mask = (cl_uint)network->premises[index].trainable_mask;
            premises[index].reserved0 = 0u;
            premises[index].hedge = network->premises[index].hedge;
            premises[index].domain_minimum = network->premises[index].domain_minimum;
            premises[index].domain_maximum = network->premises[index].domain_maximum;
            premises[index].epsilon = network->premises[index].epsilon;
        }
        for (index = 0u; index < network->expression_count; index++)
        {
            expressions[index].kind = (cl_uint)network->expressions[index].kind;
            expressions[index].left = (cl_uint)network->expressions[index].left;
            expressions[index].right = (cl_uint)network->expressions[index].right;
            expressions[index].value = (cl_uint)network->expressions[index].value;
        }
        for (index = 0u; index < network->rule_count; index++) rule_roots[index] = (cl_uint)network->rule_roots[index];
#define FUZZY_NEURON_CREATE_BUFFER(member, flags, bytes) do { cl->member = clCreateBuffer(cl->context, (flags), (bytes), NULL, &error); if (error != CL_SUCCESS || cl->member == NULL) { fprintf(stderr, "OpenCL fail-fast: buffer %s creation failed: %d\\n", #member, error); free(premises); free(expressions); free(rule_roots); goto failure; } } while (0)
        FUZZY_NEURON_CREATE_BUFFER(d_raw_inputs, CL_MEM_READ_ONLY, batch_capacity * network->raw_input_dimensions * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_premises, CL_MEM_READ_ONLY, network->premise_count * sizeof(*premises));
        FUZZY_NEURON_CREATE_BUFFER(d_premise_parameters, CL_MEM_READ_WRITE, network->premise_parameter_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_expressions, CL_MEM_READ_ONLY, network->expression_count * sizeof(*expressions));
        FUZZY_NEURON_CREATE_BUFFER(d_rule_roots, CL_MEM_READ_ONLY, network->rule_count * sizeof(*rule_roots));
        FUZZY_NEURON_CREATE_BUFFER(d_memberships, CL_MEM_READ_WRITE, batch_capacity * network->premise_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_expression_values, CL_MEM_READ_WRITE, batch_capacity * network->expression_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_raw_rules, CL_MEM_READ_WRITE, batch_capacity * network->rule_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_normalized_rule_gradients, CL_MEM_READ_WRITE, batch_capacity * network->rule_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_raw_rule_gradients, CL_MEM_READ_WRITE, batch_capacity * network->rule_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_expression_gradients, CL_MEM_READ_WRITE, batch_capacity * network->expression_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_membership_gradients, CL_MEM_READ_WRITE, batch_capacity * network->premise_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_premise_parameter_gradients, CL_MEM_READ_WRITE, network->premise_parameter_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_premise_first_moment, CL_MEM_READ_WRITE, network->premise_parameter_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_premise_second_moment, CL_MEM_READ_WRITE, network->premise_parameter_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_targets, CL_MEM_READ_ONLY, batch_capacity * network->output_dimensions * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_weights, CL_MEM_READ_WRITE, network->weight_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_biases, CL_MEM_READ_WRITE, network->bias_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_activations, CL_MEM_READ_WRITE, batch_capacity * network->neuron_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_deltas, CL_MEM_READ_WRITE, batch_capacity * network->neuron_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_losses, CL_MEM_READ_WRITE, batch_capacity * network->output_dimensions * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_weight_gradients, CL_MEM_READ_WRITE, network->weight_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_bias_gradients, CL_MEM_READ_WRITE, network->bias_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_weight_first_moment, CL_MEM_READ_WRITE, network->weight_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_weight_second_moment, CL_MEM_READ_WRITE, network->weight_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_bias_first_moment, CL_MEM_READ_WRITE, network->bias_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_bias_second_moment, CL_MEM_READ_WRITE, network->bias_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_outputs, CL_MEM_READ_WRITE, batch_capacity * network->output_dimensions * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_loss_partials, CL_MEM_READ_WRITE, batch_capacity * network->output_dimensions * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_epoch_loss, CL_MEM_READ_WRITE, sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_best_loss, CL_MEM_READ_WRITE, sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_best_updated, CL_MEM_READ_WRITE, sizeof(cl_uint));
        FUZZY_NEURON_CREATE_BUFFER(d_best_weights, CL_MEM_READ_WRITE, network->weight_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_best_biases, CL_MEM_READ_WRITE, network->bias_count * sizeof(float));
        FUZZY_NEURON_CREATE_BUFFER(d_best_premise_parameters, CL_MEM_READ_WRITE, network->premise_parameter_count * sizeof(float));
        cl->loss_partial_capacity = batch_capacity * network->output_dimensions;
#undef FUZZY_NEURON_CREATE_BUFFER
        error = CL_SUCCESS;
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_premises, CL_TRUE, 0u, network->premise_count * sizeof(*premises), premises, 0u, NULL, NULL);
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_premise_parameters, CL_TRUE, 0u, network->premise_parameter_count * sizeof(float), network->premise_parameters, 0u, NULL, NULL);
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_expressions, CL_TRUE, 0u, network->expression_count * sizeof(*expressions), expressions, 0u, NULL, NULL);
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_rule_roots, CL_TRUE, 0u, network->rule_count * sizeof(*rule_roots), rule_roots, 0u, NULL, NULL);
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_weights, CL_TRUE, 0u, network->weight_count * sizeof(float), network->weights, 0u, NULL, NULL);
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_biases, CL_TRUE, 0u, network->bias_count * sizeof(float), network->biases, 0u, NULL, NULL);
        free(premises);
        free(expressions);
        free(rule_roots);
        if (error != CL_SUCCESS) goto failure;
    }
    cl->optimizer_step = 0u;
    cl->ready = true;
    return true;

failure:
    fuzzy_neuron_opencl_release(cl);
    return false;
}

static bool fuzzy_neuron_opencl_enqueue_forward(
    fuzzy_neuron_network_t *network,
    cl_uint sample_count
)
{
    fuzzy_neuron_opencl_t *cl = &network->opencl;
    cl_uint input_count = (cl_uint)network->raw_input_dimensions;
    cl_uint premise_count = (cl_uint)network->premise_count;
    cl_uint expression_count = (cl_uint)network->expression_count;
    cl_uint rule_count = (cl_uint)network->rule_count;
    cl_uint neuron_count = (cl_uint)network->neuron_count;
    cl_uint logic_method = (cl_uint)network->logic_method;
    size_t premise_global_size[2] = {(size_t)sample_count, network->premise_count};
    size_t sample_global_size = (size_t)sample_count;
    size_t layer;
    cl_int error = CL_SUCCESS;

    error |= clSetKernelArg(cl->premise_forward_kernel, 0u, sizeof(cl_mem), &cl->d_raw_inputs);
    error |= clSetKernelArg(cl->premise_forward_kernel, 1u, sizeof(cl_mem), &cl->d_premises);
    error |= clSetKernelArg(cl->premise_forward_kernel, 2u, sizeof(cl_mem), &cl->d_premise_parameters);
    error |= clSetKernelArg(cl->premise_forward_kernel, 3u, sizeof(cl_mem), &cl->d_memberships);
    error |= clSetKernelArg(cl->premise_forward_kernel, 4u, sizeof(sample_count), &sample_count);
    error |= clSetKernelArg(cl->premise_forward_kernel, 5u, sizeof(input_count), &input_count);
    error |= clSetKernelArg(cl->premise_forward_kernel, 6u, sizeof(premise_count), &premise_count);
    if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->premise_forward_kernel, 2u, NULL, premise_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) return false;

    error = CL_SUCCESS;
    error |= clSetKernelArg(cl->expression_forward_kernel, 0u, sizeof(cl_mem), &cl->d_expressions);
    error |= clSetKernelArg(cl->expression_forward_kernel, 1u, sizeof(cl_mem), &cl->d_rule_roots);
    error |= clSetKernelArg(cl->expression_forward_kernel, 2u, sizeof(cl_mem), &cl->d_memberships);
    error |= clSetKernelArg(cl->expression_forward_kernel, 3u, sizeof(cl_mem), &cl->d_expression_values);
    error |= clSetKernelArg(cl->expression_forward_kernel, 4u, sizeof(cl_mem), &cl->d_raw_rules);
    error |= clSetKernelArg(cl->expression_forward_kernel, 5u, sizeof(sample_count), &sample_count);
    error |= clSetKernelArg(cl->expression_forward_kernel, 6u, sizeof(premise_count), &premise_count);
    error |= clSetKernelArg(cl->expression_forward_kernel, 7u, sizeof(expression_count), &expression_count);
    error |= clSetKernelArg(cl->expression_forward_kernel, 8u, sizeof(rule_count), &rule_count);
    error |= clSetKernelArg(cl->expression_forward_kernel, 9u, sizeof(logic_method), &logic_method);
    if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->expression_forward_kernel, 1u, NULL, &sample_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) return false;

    error = CL_SUCCESS;
    error |= clSetKernelArg(cl->normalize_rules_kernel, 0u, sizeof(cl_mem), &cl->d_raw_rules);
    error |= clSetKernelArg(cl->normalize_rules_kernel, 1u, sizeof(cl_mem), &cl->d_activations);
    error |= clSetKernelArg(cl->normalize_rules_kernel, 2u, sizeof(sample_count), &sample_count);
    error |= clSetKernelArg(cl->normalize_rules_kernel, 3u, sizeof(rule_count), &rule_count);
    error |= clSetKernelArg(cl->normalize_rules_kernel, 4u, sizeof(neuron_count), &neuron_count);
    if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->normalize_rules_kernel, 1u, NULL, &sample_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) return false;

    for (layer = 0u; layer < network->layer_count; ++layer)
    {
        const fuzzy_neuron_layer_t *current = &network->layers[layer];
        cl_uint source_offset = (cl_uint)fuzzy_neuron_opencl_layer_source_offset(network, layer);
        cl_uint source_count = (cl_uint)(layer == 0u ? network->rule_count : network->layers[layer - 1u].count);
        cl_uint destination_offset = (cl_uint)fuzzy_neuron_opencl_layer_destination_offset(network, layer);
        cl_uint destination_count = (cl_uint)current->count;
        cl_uint weight_offset = (cl_uint)current->weight_offset;
        cl_uint bias_offset = (cl_uint)current->bias_offset;
        cl_uint activation_kind = (cl_uint)current->activation;
        size_t local_size[2];
        size_t global_size[2];
        size_t input_tile_bytes;
        size_t weight_tile_bytes;

        if (!fuzzy_neuron_opencl_tiled_local_size(cl, cl->forward_gemm_tiled_kernel, sample_count, current->count, &local_size[0], &local_size[1]))
        {
            return false;
        }

        global_size[0] = ((size_t)sample_count + local_size[0] - 1u) / local_size[0] * local_size[0];
        global_size[1] = (current->count + local_size[1] - 1u) / local_size[1] * local_size[1];
        input_tile_bytes = local_size[0] * local_size[1] * sizeof(float);
        weight_tile_bytes = local_size[1] * local_size[1] * sizeof(float);

        error = CL_SUCCESS;
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 0u, sizeof(cl_mem), &cl->d_weights);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 1u, sizeof(cl_mem), &cl->d_biases);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 2u, sizeof(cl_mem), &cl->d_activations);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 3u, sizeof(sample_count), &sample_count);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 4u, sizeof(neuron_count), &neuron_count);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 5u, sizeof(source_offset), &source_offset);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 6u, sizeof(source_count), &source_count);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 7u, sizeof(destination_offset), &destination_offset);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 8u, sizeof(destination_count), &destination_count);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 9u, sizeof(weight_offset), &weight_offset);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 10u, sizeof(bias_offset), &bias_offset);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 11u, sizeof(activation_kind), &activation_kind);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 12u, input_tile_bytes, NULL);
        error |= clSetKernelArg(cl->forward_gemm_tiled_kernel, 13u, weight_tile_bytes, NULL);
        if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->forward_gemm_tiled_kernel, 2u, NULL, global_size, local_size, 0u, NULL, NULL) != CL_SUCCESS) return false;
    }
    return true;
}
double fuzzy_neuron_dataset_huber(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset)
{
    float *output;
    double loss = 0.0;
    const double delta = 10.0;
    size_t row;
    size_t target;

    output = malloc(network->output_dimensions * sizeof(*output));

    for (row = 0u; row < dataset->rows; row++)
    {
        const float *input = dataset->inputs + row * dataset->input_dimensions;
        const float *expected = dataset->targets + row * dataset->target_dimensions;

        fuzzy_neuron_predict(network, input, output);

        for (target = 0u; target < dataset->target_dimensions; target++)
        {
            double error = fabs((double)output[target] - expected[target]);

            if (error <= delta)
            {
                loss += 0.5 * error * error / delta;
            }
            else        
            {
                loss += error - 0.5 * delta;
           }
        }
    }

    free(output);

    return loss / ((double)dataset->rows * dataset->target_dimensions);
}

double fuzzy_neuron_dataset_mae(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset)
{
    float *output;
    double absolute_error = 0.0;
    size_t row;
    size_t target;

    output = malloc(network->output_dimensions * sizeof(*output));

    for (row = 0u; row < dataset->rows; row++)
    {
        const float *input = dataset->inputs + row * dataset->input_dimensions;
        const float *expected = dataset->targets + row * dataset->target_dimensions;

        fuzzy_neuron_predict(network, input, output);

        for (target = 0u; target < dataset->target_dimensions; target++)
        {
            absolute_error += fabs((double)output[target] - expected[target]);
        }
    }

    free(output);

    return (float)(absolute_error / ((double)dataset->rows * dataset->target_dimensions));
}

double fuzzy_neuron_dataset_mse(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset)
{
    double loss = 0.0;
    size_t row;
    size_t output;
    float *outputs = malloc(network->output_dimensions * sizeof(*outputs));

    for (row = 0u; row < dataset->rows; row++)
    {
        fuzzy_neuron_predict(network, dataset->inputs + row * dataset->input_dimensions, outputs);

        for (output = 0u; output < network->output_dimensions; output++)
        {
            float error = outputs[output] - dataset->targets[row * dataset->target_dimensions + output];
            loss += (double)error * error;
        }
    }

    free(outputs);
    return loss / (double)(dataset->rows * network->output_dimensions);
}

bool fuzzy_neuron_opencl_train(
    fuzzy_neuron_network_t *network,
    const fuzzy_neuron_dataset_t *dataset,
    const fuzzy_neuron_train_options_t *options,
    fuzzy_error_fn_t error_fn
)
{
    fuzzy_neuron_opencl_t *cl;
    size_t epoch;
    size_t batch_start;
    size_t layer;
    cl_uint loss_method;
    cl_float huber_delta = 10.0f;
    cl_float adam_beta1;
    cl_float adam_beta2;
    cl_float adam_epsilon;
    cl_int error;

    if (network == NULL || dataset == NULL || options == NULL || !network->opencl.ready || options->batch_size == 0u || options->batch_size > network->opencl.batch_capacity || dataset->input_dimensions != network->raw_input_dimensions || dataset->target_dimensions != network->output_dimensions || dataset->rows == 0u)
    {
        return false;
    }
    if (error_fn != MSE && error_fn != HUBER)
    {
        return false;
    }
    if (options->optimizer != FUZZY_NEURON_OPTIMIZER_SGD && options->optimizer != FUZZY_NEURON_OPTIMIZER_ADAM)
    {
        return false;
    }

    adam_beta1 = options->adam_beta1;
    adam_beta2 = options->adam_beta2;
    adam_epsilon = options->adam_epsilon;
    if (options->optimizer == FUZZY_NEURON_OPTIMIZER_ADAM && (!(adam_beta1 > 0.0f && adam_beta1 < 1.0f) || !(adam_beta2 > 0.0f && adam_beta2 < 1.0f) || !(adam_epsilon > 0.0f)))
    {
        return false;
    }

    cl = &network->opencl;
    loss_method = error_fn == HUBER ? 1u : 0u;

    if (options->optimizer == FUZZY_NEURON_OPTIMIZER_ADAM && options->reset_optimizer_state)
    {
        float zero = 0.0f;
        error = CL_SUCCESS;
        error |= clEnqueueFillBuffer(cl->queue, cl->d_weight_first_moment, &zero, sizeof(zero), 0u, network->weight_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueFillBuffer(cl->queue, cl->d_weight_second_moment, &zero, sizeof(zero), 0u, network->weight_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueFillBuffer(cl->queue, cl->d_bias_first_moment, &zero, sizeof(zero), 0u, network->bias_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueFillBuffer(cl->queue, cl->d_bias_second_moment, &zero, sizeof(zero), 0u, network->bias_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueFillBuffer(cl->queue, cl->d_premise_first_moment, &zero, sizeof(zero), 0u, network->premise_parameter_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueFillBuffer(cl->queue, cl->d_premise_second_moment, &zero, sizeof(zero), 0u, network->premise_parameter_count * sizeof(float), 0u, NULL, NULL);
        if (error != CL_SUCCESS) return false;
        cl->optimizer_step = 0u;
    }

    {
        float initial_best_loss = INFINITY;
        cl_uint enabled = 1u;
        error = CL_SUCCESS;
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_best_loss, CL_TRUE, 0u, sizeof(initial_best_loss), &initial_best_loss, 0u, NULL, NULL);
        error |= clEnqueueWriteBuffer(cl->queue, cl->d_best_updated, CL_TRUE, 0u, sizeof(enabled), &enabled, 0u, NULL, NULL);
        error |= clEnqueueCopyBuffer(cl->queue, cl->d_weights, cl->d_best_weights, 0u, 0u, network->weight_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueCopyBuffer(cl->queue, cl->d_biases, cl->d_best_biases, 0u, 0u, network->bias_count * sizeof(float), 0u, NULL, NULL);
        error |= clEnqueueCopyBuffer(cl->queue, cl->d_premise_parameters, cl->d_best_premise_parameters, 0u, 0u, network->premise_parameter_count * sizeof(float), 0u, NULL, NULL);
        if (error != CL_SUCCESS) return false;
    }

    for (epoch = 0u; epoch < options->epochs; ++epoch)
    {
        float zero_loss = 0.0f;
        error = clEnqueueWriteBuffer(cl->queue, cl->d_epoch_loss, CL_FALSE, 0u, sizeof(zero_loss), &zero_loss, 0u, NULL, NULL);
        if (error != CL_SUCCESS) goto train_failure;

        for (batch_start = 0u; batch_start < dataset->rows; batch_start += options->batch_size)
        {
            size_t batch_count = dataset->rows - batch_start;
            cl_uint sample_count;
            cl_uint output_count = (cl_uint)network->output_dimensions;
            cl_uint neuron_count = (cl_uint)network->neuron_count;
            cl_uint output_offset;
            cl_uint output_activation;
            cl_uint optimizer_kind = (cl_uint)options->optimizer;
            cl_float learning_rate = options->learning_rate;
            cl_float alpha = learning_rate;

            if (batch_count > options->batch_size) batch_count = options->batch_size;
            sample_count = (cl_uint)batch_count;
            output_offset = (cl_uint)fuzzy_neuron_opencl_layer_destination_offset(network, network->layer_count - 1u);
            output_activation = (cl_uint)network->layers[network->layer_count - 1u].activation;

            if (options->optimizer == FUZZY_NEURON_OPTIMIZER_ADAM)
            {
                ++cl->optimizer_step;
                alpha = learning_rate * sqrtf(1.0f - powf(adam_beta2, (float)cl->optimizer_step)) / (1.0f - powf(adam_beta1, (float)cl->optimizer_step));
            }

            error = clEnqueueWriteBuffer(cl->queue, cl->d_raw_inputs, CL_FALSE, 0u, batch_count * network->raw_input_dimensions * sizeof(float), dataset->inputs + batch_start * dataset->input_dimensions, 0u, NULL, NULL);
            error |= clEnqueueWriteBuffer(cl->queue, cl->d_targets, CL_FALSE, 0u, batch_count * network->output_dimensions * sizeof(float), dataset->targets + batch_start * dataset->target_dimensions, 0u, NULL, NULL);
            if (error != CL_SUCCESS || !fuzzy_neuron_opencl_enqueue_forward(network, sample_count)) goto train_failure;

            {
                size_t output_global_size = batch_count * network->output_dimensions;
                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->output_delta_kernel, 0u, sizeof(cl_mem), &cl->d_targets);
                error |= clSetKernelArg(cl->output_delta_kernel, 1u, sizeof(cl_mem), &cl->d_activations);
                error |= clSetKernelArg(cl->output_delta_kernel, 2u, sizeof(cl_mem), &cl->d_deltas);
                error |= clSetKernelArg(cl->output_delta_kernel, 3u, sizeof(cl_mem), &cl->d_losses);
                error |= clSetKernelArg(cl->output_delta_kernel, 4u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->output_delta_kernel, 5u, sizeof(output_count), &output_count);
                error |= clSetKernelArg(cl->output_delta_kernel, 6u, sizeof(neuron_count), &neuron_count);
                error |= clSetKernelArg(cl->output_delta_kernel, 7u, sizeof(output_offset), &output_offset);
                error |= clSetKernelArg(cl->output_delta_kernel, 8u, sizeof(output_activation), &output_activation);
                error |= clSetKernelArg(cl->output_delta_kernel, 9u, sizeof(loss_method), &loss_method);
                error |= clSetKernelArg(cl->output_delta_kernel, 10u, sizeof(huber_delta), &huber_delta);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->output_delta_kernel, 1u, NULL, &output_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
            }

            {
                size_t loss_count = batch_count * network->output_dimensions;
                size_t local_size;
                size_t group_count;
                size_t global_size;
                cl_uint gpu_loss_count = (cl_uint)loss_count;
                cl_uint partial_count;
                if (!fuzzy_neuron_opencl_reduction_local_size(cl, cl->loss_reduce_stage_kernel, loss_count, sizeof(float), &local_size)) goto train_failure;
                group_count = (loss_count + local_size - 1u) / local_size;
                if (group_count > cl->loss_partial_capacity) goto train_failure;
                global_size = group_count * local_size;
                partial_count = (cl_uint)group_count;
                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->loss_reduce_stage_kernel, 0u, sizeof(cl_mem), &cl->d_losses);
                error |= clSetKernelArg(cl->loss_reduce_stage_kernel, 1u, sizeof(cl_mem), &cl->d_loss_partials);
                error |= clSetKernelArg(cl->loss_reduce_stage_kernel, 2u, sizeof(gpu_loss_count), &gpu_loss_count);
                error |= clSetKernelArg(cl->loss_reduce_stage_kernel, 3u, local_size * sizeof(float), NULL);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->loss_reduce_stage_kernel, 1u, NULL, &global_size, &local_size, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
                if (!fuzzy_neuron_opencl_reduction_local_size(cl, cl->loss_reduce_final_kernel, group_count, sizeof(float), &local_size)) goto train_failure;
                global_size = local_size;
                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->loss_reduce_final_kernel, 0u, sizeof(cl_mem), &cl->d_loss_partials);
                error |= clSetKernelArg(cl->loss_reduce_final_kernel, 1u, sizeof(cl_mem), &cl->d_epoch_loss);
                error |= clSetKernelArg(cl->loss_reduce_final_kernel, 2u, sizeof(partial_count), &partial_count);
                error |= clSetKernelArg(cl->loss_reduce_final_kernel, 3u, local_size * sizeof(float), NULL);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->loss_reduce_final_kernel, 1u, NULL, &global_size, &local_size, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
            }

            for (layer = network->layer_count - 1u; layer-- > 0u;)
            {
                const fuzzy_neuron_layer_t *current = &network->layers[layer];
                const fuzzy_neuron_layer_t *next = &network->layers[layer + 1u];
                cl_uint current_offset = (cl_uint)fuzzy_neuron_opencl_layer_destination_offset(network, layer);
                cl_uint current_count = (cl_uint)current->count;
                cl_uint next_offset = (cl_uint)fuzzy_neuron_opencl_layer_destination_offset(network, layer + 1u);
                cl_uint next_count = (cl_uint)next->count;
                cl_uint next_weight_offset = (cl_uint)next->weight_offset;
                cl_uint current_activation_kind = (cl_uint)current->activation;
                size_t local_size[2];
                size_t global_size[2];
                size_t delta_tile_bytes;
                size_t weight_tile_bytes;
                if (!fuzzy_neuron_opencl_tiled_local_size(cl, cl->hidden_delta_gemm_tiled_kernel, batch_count, current->count, &local_size[0], &local_size[1])) goto train_failure;
                global_size[0] = (batch_count + local_size[0] - 1u) / local_size[0] * local_size[0];
                global_size[1] = (current->count + local_size[1] - 1u) / local_size[1] * local_size[1];
                delta_tile_bytes = local_size[0] * local_size[1] * sizeof(float);
                weight_tile_bytes = local_size[1] * local_size[1] * sizeof(float);
                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 0u, sizeof(cl_mem), &cl->d_weights);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 1u, sizeof(cl_mem), &cl->d_activations);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 2u, sizeof(cl_mem), &cl->d_deltas);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 3u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 4u, sizeof(neuron_count), &neuron_count);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 5u, sizeof(current_offset), &current_offset);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 6u, sizeof(current_count), &current_count);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 7u, sizeof(next_offset), &next_offset);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 8u, sizeof(next_count), &next_count);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 9u, sizeof(next_weight_offset), &next_weight_offset);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 10u, sizeof(current_activation_kind), &current_activation_kind);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 11u, delta_tile_bytes, NULL);
                error |= clSetKernelArg(cl->hidden_delta_gemm_tiled_kernel, 12u, weight_tile_bytes, NULL);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->hidden_delta_gemm_tiled_kernel, 2u, NULL, global_size, local_size, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
            }

            {
                cl_uint rule_count = (cl_uint)network->rule_count;
                cl_uint premise_count = (cl_uint)network->premise_count;
                cl_uint expression_count = (cl_uint)network->expression_count;
                cl_uint input_count = (cl_uint)network->raw_input_dimensions;
                cl_uint parameter_count = (cl_uint)network->premise_parameter_count;
                cl_uint first_destination_offset = (cl_uint)fuzzy_neuron_opencl_layer_destination_offset(network, 0u);
                cl_uint first_destination_count = (cl_uint)network->layers[0].count;
                cl_uint first_weight_offset = (cl_uint)network->layers[0].weight_offset;
                cl_uint logic_method = (cl_uint)network->logic_method;
                size_t sample_global_size = batch_count;
                size_t premise_gradient_local_size;
                size_t premise_gradient_global_size;
                size_t parameter_global_size = network->premise_parameter_count;
                size_t premise_global_size = network->premise_count;

                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 0u, sizeof(cl_mem), &cl->d_weights);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 1u, sizeof(cl_mem), &cl->d_deltas);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 2u, sizeof(cl_mem), &cl->d_raw_rules);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 3u, sizeof(cl_mem), &cl->d_normalized_rule_gradients);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 4u, sizeof(cl_mem), &cl->d_raw_rule_gradients);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 5u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 6u, sizeof(neuron_count), &neuron_count);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 7u, sizeof(rule_count), &rule_count);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 8u, sizeof(first_destination_offset), &first_destination_offset);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 9u, sizeof(first_destination_count), &first_destination_count);
                error |= clSetKernelArg(cl->fuzzy_backward_kernel, 10u, sizeof(first_weight_offset), &first_weight_offset);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->fuzzy_backward_kernel, 1u, NULL, &sample_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;

                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->expression_backward_kernel, 0u, sizeof(cl_mem), &cl->d_expressions);
                error |= clSetKernelArg(cl->expression_backward_kernel, 1u, sizeof(cl_mem), &cl->d_rule_roots);
                error |= clSetKernelArg(cl->expression_backward_kernel, 2u, sizeof(cl_mem), &cl->d_expression_values);
                error |= clSetKernelArg(cl->expression_backward_kernel, 3u, sizeof(cl_mem), &cl->d_raw_rule_gradients);
                error |= clSetKernelArg(cl->expression_backward_kernel, 4u, sizeof(cl_mem), &cl->d_expression_gradients);
                error |= clSetKernelArg(cl->expression_backward_kernel, 5u, sizeof(cl_mem), &cl->d_membership_gradients);
                error |= clSetKernelArg(cl->expression_backward_kernel, 6u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->expression_backward_kernel, 7u, sizeof(premise_count), &premise_count);
                error |= clSetKernelArg(cl->expression_backward_kernel, 8u, sizeof(expression_count), &expression_count);
                error |= clSetKernelArg(cl->expression_backward_kernel, 9u, sizeof(rule_count), &rule_count);
                error |= clSetKernelArg(cl->expression_backward_kernel, 10u, sizeof(logic_method), &logic_method);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->expression_backward_kernel, 1u, NULL, &sample_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;

                if (!fuzzy_neuron_opencl_reduction_local_size(cl, cl->premise_gradient_kernel, batch_count, sizeof(float), &premise_gradient_local_size)) goto train_failure;
                premise_gradient_global_size = network->premise_parameter_count * premise_gradient_local_size;
                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->premise_gradient_kernel, 0u, sizeof(cl_mem), &cl->d_raw_inputs);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 1u, sizeof(cl_mem), &cl->d_premises);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 2u, sizeof(cl_mem), &cl->d_premise_parameters);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 3u, sizeof(cl_mem), &cl->d_memberships);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 4u, sizeof(cl_mem), &cl->d_membership_gradients);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 5u, sizeof(cl_mem), &cl->d_premise_parameter_gradients);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 6u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 7u, sizeof(input_count), &input_count);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 8u, sizeof(premise_count), &premise_count);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 9u, sizeof(parameter_count), &parameter_count);
                error |= clSetKernelArg(cl->premise_gradient_kernel, 10u, premise_gradient_local_size * sizeof(float), NULL);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->premise_gradient_kernel, 1u, NULL, &premise_gradient_global_size, &premise_gradient_local_size, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;

                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 0u, sizeof(cl_mem), &cl->d_premise_parameter_gradients);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 1u, sizeof(cl_mem), &cl->d_premise_parameters);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 2u, sizeof(cl_mem), &cl->d_premise_first_moment);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 3u, sizeof(cl_mem), &cl->d_premise_second_moment);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 4u, sizeof(parameter_count), &parameter_count);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 5u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 6u, sizeof(optimizer_kind), &optimizer_kind);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 7u, sizeof(learning_rate), &learning_rate);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 8u, sizeof(alpha), &alpha);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 9u, sizeof(adam_beta1), &adam_beta1);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 10u, sizeof(adam_beta2), &adam_beta2);
                error |= clSetKernelArg(cl->fuzzy_update_kernel, 11u, sizeof(adam_epsilon), &adam_epsilon);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->fuzzy_update_kernel, 1u, NULL, &parameter_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;

                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->project_premises_kernel, 0u, sizeof(cl_mem), &cl->d_premises);
                error |= clSetKernelArg(cl->project_premises_kernel, 1u, sizeof(cl_mem), &cl->d_premise_parameters);
                error |= clSetKernelArg(cl->project_premises_kernel, 2u, sizeof(premise_count), &premise_count);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->project_premises_kernel, 1u, NULL, &premise_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
            }

            for (layer = 0u; layer < network->layer_count; ++layer)
            {
                const fuzzy_neuron_layer_t *current = &network->layers[layer];
                cl_uint source_offset = (cl_uint)fuzzy_neuron_opencl_layer_source_offset(network, layer);
                cl_uint source_count = (cl_uint)(layer == 0u ? network->rule_count : network->layers[layer - 1u].count);
                cl_uint destination_offset = (cl_uint)fuzzy_neuron_opencl_layer_destination_offset(network, layer);
                cl_uint destination_count = (cl_uint)current->count;
                cl_uint weight_offset = (cl_uint)current->weight_offset;
                cl_uint bias_offset = (cl_uint)current->bias_offset;
                size_t parameter_count = (size_t)source_count * destination_count + destination_count;
                size_t local_size;
                size_t global_size;
                if (!fuzzy_neuron_opencl_reduction_local_size(cl, cl->layer_backward_update_kernel, batch_count, sizeof(float), &local_size)) goto train_failure;
                global_size = parameter_count * local_size;
                error = CL_SUCCESS;
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 0u, sizeof(cl_mem), &cl->d_weights);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 1u, sizeof(cl_mem), &cl->d_biases);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 2u, sizeof(cl_mem), &cl->d_activations);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 3u, sizeof(cl_mem), &cl->d_deltas);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 4u, sizeof(cl_mem), &cl->d_weight_first_moment);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 5u, sizeof(cl_mem), &cl->d_weight_second_moment);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 6u, sizeof(cl_mem), &cl->d_bias_first_moment);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 7u, sizeof(cl_mem), &cl->d_bias_second_moment);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 8u, sizeof(sample_count), &sample_count);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 9u, sizeof(neuron_count), &neuron_count);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 10u, sizeof(source_offset), &source_offset);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 11u, sizeof(source_count), &source_count);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 12u, sizeof(destination_offset), &destination_offset);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 13u, sizeof(destination_count), &destination_count);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 14u, sizeof(weight_offset), &weight_offset);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 15u, sizeof(bias_offset), &bias_offset);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 16u, sizeof(optimizer_kind), &optimizer_kind);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 17u, sizeof(learning_rate), &learning_rate);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 18u, sizeof(alpha), &alpha);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 19u, sizeof(adam_beta1), &adam_beta1);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 20u, sizeof(adam_beta2), &adam_beta2);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 21u, sizeof(adam_epsilon), &adam_epsilon);
                error |= clSetKernelArg(cl->layer_backward_update_kernel, 22u, local_size * sizeof(float), NULL);
                if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->layer_backward_update_kernel, 1u, NULL, &global_size, &local_size, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
            }
        }

        {
            cl_uint normalization_count = (cl_uint)(dataset->rows * network->output_dimensions);
            size_t one = 1u;
            size_t weight_global = network->weight_count;
            size_t bias_global = network->bias_count;
            size_t premise_global = network->premise_parameter_count;
            cl_uint weight_count = (cl_uint)network->weight_count;
            cl_uint bias_count = (cl_uint)network->bias_count;
            cl_uint premise_count = (cl_uint)network->premise_parameter_count;

            error = CL_SUCCESS;
            error |= clSetKernelArg(cl->best_model_kernel, 0u, sizeof(cl_mem), &cl->d_epoch_loss);
            error |= clSetKernelArg(cl->best_model_kernel, 1u, sizeof(cl_mem), &cl->d_best_loss);
            error |= clSetKernelArg(cl->best_model_kernel, 2u, sizeof(cl_mem), &cl->d_best_updated);
            error |= clSetKernelArg(cl->best_model_kernel, 3u, sizeof(normalization_count), &normalization_count);
            if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->best_model_kernel, 1u, NULL, &one, NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;

#define FUZZY_NEURON_BEST_COPY(source_buffer, destination_buffer, count_value, global_value) do {                 error = CL_SUCCESS;                 error |= clSetKernelArg(cl->conditional_copy_kernel, 0u, sizeof(cl_mem), &(source_buffer));                 error |= clSetKernelArg(cl->conditional_copy_kernel, 1u, sizeof(cl_mem), &(destination_buffer));                 error |= clSetKernelArg(cl->conditional_copy_kernel, 2u, sizeof(cl_mem), &cl->d_best_updated);                 error |= clSetKernelArg(cl->conditional_copy_kernel, 3u, sizeof(count_value), &(count_value));                 if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->conditional_copy_kernel, 1u, NULL, &(global_value), NULL, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;             } while (0)
            FUZZY_NEURON_BEST_COPY(cl->d_weights, cl->d_best_weights, weight_count, weight_global);
            FUZZY_NEURON_BEST_COPY(cl->d_biases, cl->d_best_biases, bias_count, bias_global);
            FUZZY_NEURON_BEST_COPY(cl->d_premise_parameters, cl->d_best_premise_parameters, premise_count, premise_global);
#undef FUZZY_NEURON_BEST_COPY

            if (options->report_every != 0u && (((epoch + 1u) % options->report_every) == 0u || epoch + 1u == options->epochs))
            {
                float epoch_loss_sum;
                if (clEnqueueReadBuffer(cl->queue, cl->d_epoch_loss, CL_TRUE, 0u, sizeof(epoch_loss_sum), &epoch_loss_sum, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
                printf("Epoch %4u %s %.10f\n", (unsigned int)(epoch + 1u), error_fn == MSE ? "MSE" : "Huber", epoch_loss_sum / (float)normalization_count);
            }
        }
    }

    error = CL_SUCCESS;
    error |= clEnqueueCopyBuffer(cl->queue, cl->d_best_weights, cl->d_weights, 0u, 0u, network->weight_count * sizeof(float), 0u, NULL, NULL);
    error |= clEnqueueCopyBuffer(cl->queue, cl->d_best_biases, cl->d_biases, 0u, 0u, network->bias_count * sizeof(float), 0u, NULL, NULL);
    error |= clEnqueueCopyBuffer(cl->queue, cl->d_best_premise_parameters, cl->d_premise_parameters, 0u, 0u, network->premise_parameter_count * sizeof(float), 0u, NULL, NULL);
    error |= clEnqueueReadBuffer(cl->queue, cl->d_weights, CL_FALSE, 0u, network->weight_count * sizeof(float), network->weights, 0u, NULL, NULL);
    error |= clEnqueueReadBuffer(cl->queue, cl->d_biases, CL_FALSE, 0u, network->bias_count * sizeof(float), network->biases, 0u, NULL, NULL);
    error |= clEnqueueReadBuffer(cl->queue, cl->d_premise_parameters, CL_TRUE, 0u, network->premise_parameter_count * sizeof(float), network->premise_parameters, 0u, NULL, NULL);
    if (error != CL_SUCCESS) goto train_failure;

    {
        float best_loss;
        if (clEnqueueReadBuffer(cl->queue, cl->d_best_loss, CL_TRUE, 0u, sizeof(best_loss), &best_loss, 0u, NULL, NULL) != CL_SUCCESS) goto train_failure;
        printf("Best %s %.10f restored\n", error_fn == MSE ? "MSE" : "Huber", best_loss);
    }
    return true;

train_failure:
    return false;
}
bool fuzzy_neuron_opencl_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
)
{
    fuzzy_neuron_opencl_t *cl;
    size_t batch_start;
    size_t output_offset;
    cl_int error;

    if (network == NULL || raw_inputs == NULL || outputs == NULL || rows == 0u || !network->opencl.ready)
    {
        return false;
    }

    cl = &network->opencl;
    output_offset = fuzzy_neuron_opencl_layer_destination_offset(network, network->layer_count - 1u);

    for (batch_start = 0u; batch_start < rows; batch_start += cl->batch_capacity)
    {
        size_t batch_count = rows - batch_start;
        cl_uint sample_count;
        cl_uint neuron_count = (cl_uint)network->neuron_count;
        cl_uint gpu_output_offset = (cl_uint)output_offset;
        cl_uint output_count = (cl_uint)network->output_dimensions;
        size_t output_global_size;

        if (batch_count > cl->batch_capacity) batch_count = cl->batch_capacity;
        sample_count = (cl_uint)batch_count;
        output_global_size = batch_count * network->output_dimensions;

        error = clEnqueueWriteBuffer(cl->queue, cl->d_raw_inputs, CL_FALSE, 0u, batch_count * network->raw_input_dimensions * sizeof(float), raw_inputs + batch_start * network->raw_input_dimensions, 0u, NULL, NULL);
        if (error != CL_SUCCESS || !fuzzy_neuron_opencl_enqueue_forward(network, sample_count)) return false;

        error = CL_SUCCESS;
        error |= clSetKernelArg(cl->gather_outputs_kernel, 0u, sizeof(cl_mem), &cl->d_activations);
        error |= clSetKernelArg(cl->gather_outputs_kernel, 1u, sizeof(cl_mem), &cl->d_outputs);
        error |= clSetKernelArg(cl->gather_outputs_kernel, 2u, sizeof(sample_count), &sample_count);
        error |= clSetKernelArg(cl->gather_outputs_kernel, 3u, sizeof(neuron_count), &neuron_count);
        error |= clSetKernelArg(cl->gather_outputs_kernel, 4u, sizeof(gpu_output_offset), &gpu_output_offset);
        error |= clSetKernelArg(cl->gather_outputs_kernel, 5u, sizeof(output_count), &output_count);
        if (error != CL_SUCCESS || clEnqueueNDRangeKernel(cl->queue, cl->gather_outputs_kernel, 1u, NULL, &output_global_size, NULL, 0u, NULL, NULL) != CL_SUCCESS) return false;

        if (clEnqueueReadBuffer(cl->queue, cl->d_outputs, CL_TRUE, 0u, output_global_size * sizeof(float), outputs + batch_start * network->output_dimensions, 0u, NULL, NULL) != CL_SUCCESS) return false;
    }
    return true;
}
void fuzzy_neuron_opencl_free(fuzzy_neuron_network_t *network)
{
    if (network != NULL)
    {
        fuzzy_neuron_opencl_release(&network->opencl);
    }
}

bool fuzzy_neuron_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep,
    float value_minimum,
    float value_maximum
)
{
    if (sweep == NULL ||
        sweep->points == NULL ||
        sweep->point_count == 0u ||
        !(value_maximum > value_minimum))
    {
        return false;
    }

#ifdef FUZZY_OPENCL
    return fuzzy_gpu_interpolation_sweep_range(
        sweep,
        true,
        value_minimum,
        value_maximum
    );
#else
    fuzzy_cog_sweep_t shared_sweep;

    shared_sweep.filename = sweep->filename;
    shared_sweep.title = sweep->title;
    shared_sweep.value_name = "Membership";
    shared_sweep.dimensions = sweep->dimensions;
    shared_sweep.dimension_count = sweep->dimension_count;
    shared_sweep.cog_step = 0.0f;
    shared_sweep.evaluate = NULL;

    return fuzzy_sweep_generate(
        &shared_sweep,
        sweep->points,
        sweep->point_count,
        true,
        value_minimum,
        value_maximum
    );
#endif
}


typedef struct fuzzy_neuron_output_pipeline
{
    const fuzzy_output_function_t *memberships;
    size_t membership_count;
    float minimum;
    float maximum;
    float step;
    float gain;
    float bias;
} fuzzy_neuron_output_pipeline_t;

typedef struct fuzzy_neuron_output_cache
{
    float *activations;
    float *raw_predictions;
    size_t rows;
    size_t output_count;
} fuzzy_neuron_output_cache_t;

typedef struct fuzzy_neuron_checkpoint
{
    float *weights;
    float *biases;
    float *premises;
    void *extra;
    size_t extra_size;
    double loss;
    size_t epoch;
} fuzzy_neuron_checkpoint_t;

typedef struct fuzzy_neuron_history
{
    size_t *epochs;
    double *losses;
    size_t count;
    size_t capacity;
    double initial_loss;
} fuzzy_neuron_history_t;

#define FUZZY_NEURON_OUTPUT_PIPELINE(name, minimum_arg, maximum_arg, step_arg, ...) \
    static const fuzzy_output_function_t name##_memberships[] = {__VA_ARGS__}; \
    static fuzzy_neuron_output_pipeline_t name = {name##_memberships, sizeof(name##_memberships) / sizeof(name##_memberships[0]), (minimum_arg), (maximum_arg), (step_arg), 1.0f, 0.0f}

static float fuzzy_neuron_output_decode_raw(const fuzzy_neuron_output_pipeline_t *pipeline, const float activations[])
{
    fuzzy_rules_t rules;
    size_t index;
    rules.count = 0u;
    for (index = 0u; index < pipeline->membership_count; ++index)
        if (!FUZZY_RULE_ADD(&rules, activations[index], pipeline->memberships[index])) return NAN;
    return fuzzy_rules_defuzzify(&rules, pipeline->minimum, pipeline->maximum, pipeline->step, FUZZY_DEFUZZ_COG);
}

static float fuzzy_neuron_output_decode(const fuzzy_neuron_output_pipeline_t *pipeline, const float activations[])
{
    float raw = fuzzy_neuron_output_decode_raw(pipeline, activations);
    return fminf(pipeline->maximum, fmaxf(pipeline->minimum, pipeline->gain * raw + pipeline->bias));
}

static void fuzzy_neuron_output_encode(const fuzzy_neuron_output_pipeline_t *pipeline, float target, float activations[])
{
    size_t index;
    for (index = 0u; index < pipeline->membership_count; ++index) activations[index] = pipeline->memberships[index](target);
}

static bool fuzzy_neuron_dataset_encode_targets(fuzzy_neuron_dataset_t *destination, const fuzzy_neuron_dataset_t *source, const fuzzy_neuron_output_pipeline_t *pipeline)
{
    size_t row;
    FUZZY_NEURON_DATASET_ALLOCATE(*destination, source->rows, source->input_dimensions, pipeline->membership_count);
    if (destination->inputs == NULL || destination->targets == NULL) return false;
    memcpy(destination->inputs, source->inputs, source->rows * source->input_dimensions * sizeof(float));
    for (row = 0u; row < source->rows; ++row) fuzzy_neuron_output_encode(pipeline, source->targets[row], destination->targets + row * pipeline->membership_count);
    return true;
}

static void fuzzy_neuron_dataset_refresh_targets(fuzzy_neuron_dataset_t *destination, const fuzzy_neuron_dataset_t *source, const fuzzy_neuron_output_pipeline_t *pipeline)
{
    size_t row;
    for (row = 0u; row < source->rows; ++row) fuzzy_neuron_output_encode(pipeline, source->targets[row], destination->targets + row * pipeline->membership_count);
}

static bool fuzzy_neuron_output_cache_create(fuzzy_neuron_output_cache_t *cache, size_t rows, size_t output_count)
{
    cache->activations = malloc(rows * output_count * sizeof(float));
    cache->raw_predictions = malloc(rows * sizeof(float));
    cache->rows = rows;
    cache->output_count = output_count;
    return cache->activations != NULL && cache->raw_predictions != NULL;
}

static void fuzzy_neuron_output_cache_free(fuzzy_neuron_output_cache_t *cache)
{
    free(cache->activations);
    free(cache->raw_predictions);
    memset(cache, 0, sizeof(*cache));
}

static bool fuzzy_neuron_output_cache_refresh(fuzzy_neuron_output_cache_t *cache, fuzzy_neuron_network_t *model, const fuzzy_neuron_dataset_t *dataset, const fuzzy_neuron_output_pipeline_t *pipeline)
{
    size_t row;
    if (cache->rows != dataset->rows || cache->output_count != pipeline->membership_count) return false;
    if (!fuzzy_neuron_opencl_predict(model, dataset->inputs, dataset->rows, cache->activations)) return false;
    for (row = 0u; row < cache->rows; ++row) cache->raw_predictions[row] = fuzzy_neuron_output_decode_raw(pipeline, cache->activations + row * cache->output_count);
    return true;
}

static bool fuzzy_neuron_output_fit_affine(fuzzy_neuron_output_pipeline_t *pipeline, const fuzzy_neuron_output_cache_t *cache, const float targets[])
{
    double sx = 0.0, sy = 0.0, sxx = 0.0, sxy = 0.0, denominator;
    size_t row;
    for (row = 0u; row < cache->rows; ++row) { double x = cache->raw_predictions[row], y = targets[row]; sx += x; sy += y; sxx += x * x; sxy += x * y; }
    denominator = (double)cache->rows * sxx - sx * sx;
    if (!(denominator > 0.0)) return false;
    pipeline->gain = (float)(((double)cache->rows * sxy - sx * sy) / denominator);
    pipeline->bias = (float)((sy - pipeline->gain * sx) / (double)cache->rows);
    return isfinite(pipeline->gain) && isfinite(pipeline->bias);
}

static double fuzzy_neuron_output_cache_mse(const fuzzy_neuron_output_pipeline_t *pipeline, const fuzzy_neuron_output_cache_t *cache, const float targets[])
{
    double total = 0.0;
    size_t row;
    for (row = 0u; row < cache->rows; ++row) { double prediction = fmin(pipeline->maximum, fmax(pipeline->minimum, pipeline->gain * cache->raw_predictions[row] + pipeline->bias)); double error = prediction - targets[row]; total += error * error; }
    return total / (double)cache->rows;
}

static bool fuzzy_neuron_checkpoint_create(fuzzy_neuron_checkpoint_t *checkpoint, const fuzzy_neuron_network_t *model, size_t extra_size, double loss)
{
    checkpoint->weights = malloc(model->weight_count * sizeof(float));
    checkpoint->biases = malloc(model->bias_count * sizeof(float));
    checkpoint->premises = malloc(model->premise_parameter_count * sizeof(float));
    checkpoint->extra = extra_size == 0u ? NULL : malloc(extra_size);
    checkpoint->extra_size = extra_size;
    checkpoint->loss = loss;
    checkpoint->epoch = 0u;
    return checkpoint->weights != NULL && checkpoint->biases != NULL && checkpoint->premises != NULL && (extra_size == 0u || checkpoint->extra != NULL);
}

static void fuzzy_neuron_checkpoint_capture(fuzzy_neuron_checkpoint_t *checkpoint, const fuzzy_neuron_network_t *model, const void *extra, size_t epoch, double loss)
{
    memcpy(checkpoint->weights, model->weights, model->weight_count * sizeof(float));
    memcpy(checkpoint->biases, model->biases, model->bias_count * sizeof(float));
    memcpy(checkpoint->premises, model->premise_parameters, model->premise_parameter_count * sizeof(float));
    if (checkpoint->extra_size != 0u) memcpy(checkpoint->extra, extra, checkpoint->extra_size);
    checkpoint->epoch = epoch;
    checkpoint->loss = loss;
}

static void fuzzy_neuron_checkpoint_restore(const fuzzy_neuron_checkpoint_t *checkpoint, fuzzy_neuron_network_t *model, void *extra)
{
    memcpy(model->weights, checkpoint->weights, model->weight_count * sizeof(float));
    memcpy(model->biases, checkpoint->biases, model->bias_count * sizeof(float));
    memcpy(model->premise_parameters, checkpoint->premises, model->premise_parameter_count * sizeof(float));
    if (checkpoint->extra_size != 0u) memcpy(extra, checkpoint->extra, checkpoint->extra_size);
}

static void fuzzy_neuron_checkpoint_free(fuzzy_neuron_checkpoint_t *checkpoint)
{
    free(checkpoint->weights); free(checkpoint->biases); free(checkpoint->premises); free(checkpoint->extra); memset(checkpoint, 0, sizeof(*checkpoint));
}

static bool fuzzy_neuron_history_create(fuzzy_neuron_history_t *history, size_t capacity, double initial_loss)
{
    history->epochs = malloc(capacity * sizeof(size_t));
    history->losses = malloc(capacity * sizeof(double));
    history->count = 0u; history->capacity = capacity; history->initial_loss = initial_loss;
    return history->epochs != NULL && history->losses != NULL;
}

static bool fuzzy_neuron_history_push(fuzzy_neuron_history_t *history, size_t epoch, double loss)
{
    if (history->count >= history->capacity) return false;
    history->epochs[history->count] = epoch; history->losses[history->count++] = loss; return true;
}

static void fuzzy_neuron_history_free(fuzzy_neuron_history_t *history)
{
    free(history->epochs); free(history->losses); memset(history, 0, sizeof(*history));
}

#endif /* FUZZY_NEURON_OPENCL */
#endif /* FUZZY_NEURON_IMPLEMENTATION_ONCE */
#endif /* FUZZY_NEURON_IMPLEMENTATION */
#endif /* !FUZZY_8051 */

#endif /* FUZZY_H */
