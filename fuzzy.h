#ifndef FUZZY_H
#define FUZZY_H

#ifdef FUZZY_8051

#include <stddef.h>
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
typedef struct FuzzyHedges { fuzzy_hedge_t none; fuzzy_hedge_t very; fuzzy_hedge_t extremely; } hedges_t;
typedef enum FuzzyLogicMethod { FUZZY_LOGIC_STANDARD = 0, FUZZY_LOGIC_ALGEBRAIC, FUZZY_LOGIC_BOUNDED } fuzzy_logic_method_t;
typedef enum FuzzyImplicationMethod { FUZZY_IMPLICATION_MIN = 0, FUZZY_IMPLICATION_PRODUCT } fuzzy_implication_method_t;
typedef enum FuzzyAggregationMethod { FUZZY_AGGREGATION_MAX = 0, FUZZY_AGGREGATION_ALGEBRAIC, FUZZY_AGGREGATION_BOUNDED } fuzzy_aggregation_method_t;
typedef enum FuzzyShape { FUZZY_SHAPE_RAMP = 0, FUZZY_SHAPE_TRIANGLE, FUZZY_SHAPE_TRAPEZOID, FUZZY_SHAPE_SMF, FUZZY_SHAPE_ZMF, FUZZY_SHAPE_GAUSSIAN, FUZZY_SHAPE_BELL, FUZZY_SHAPE_SIGMOID, FUZZY_SHAPE_PIMF, FUZZY_SHAPE_DSIGMOID, FUZZY_SHAPE_PSIGMOID, FUZZY_SHAPE_GAUSSIAN2, FUZZY_SHAPE_PIECEWISE } fuzzy_shape_t;
typedef enum FuzzyDefuzzMethod { FUZZY_DEFUZZ_COG = 0, FUZZY_DEFUZZ_BOA, FUZZY_DEFUZZ_COS, FUZZY_DEFUZZ_MOM, FUZZY_DEFUZZ_SOM, FUZZY_DEFUZZ_LOM } fuzzy_defuzz_method_t;

typedef struct FuzzyVariable8051 { uint8_t shape; fuzzy_hedge_t hedge; float parameters[4]; } fuzzy_variable_8051_t;
typedef struct FuzzyRule { float value; const fuzzy_variable_8051_t *output; } fuzzy_rule_t;
typedef struct FuzzyRules { fuzzy_rule_t rules[FUZZY_MAX_RULES]; uint8_t count; } fuzzy_rules_t;

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


static float fuzzy_8051_and2(fuzzy_logic_method_t method, float a, float b) { if (method == FUZZY_LOGIC_ALGEBRAIC) return a * b; if (method == FUZZY_LOGIC_BOUNDED) { float value = a + b - 1.0f; return value > 0.0f ? value : 0.0f; } return a < b ? a : b; }
static float fuzzy_8051_and3(fuzzy_logic_method_t method, float a, float b, float c) { return fuzzy_8051_and2(method, fuzzy_8051_and2(method, a, b), c); }
static float fuzzy_8051_or2(fuzzy_logic_method_t method, float a, float b) { if (method == FUZZY_LOGIC_ALGEBRAIC) return a + b - a * b; if (method == FUZZY_LOGIC_BOUNDED) { float value = a + b; return value < 1.0f ? value : 1.0f; } return a > b ? a : b; }
static float fuzzy_8051_or3(fuzzy_logic_method_t method, float a, float b, float c) { return fuzzy_8051_or2(method, fuzzy_8051_or2(method, a, b), c); }
#define FUZZY_8051_SELECT_3(_1, _2, _3, NAME, ...) NAME
#define fuzzy_and_method(method, ...) FUZZY_8051_SELECT_3(__VA_ARGS__, fuzzy_8051_and3, fuzzy_8051_and2)((method), __VA_ARGS__)
#define fuzzy_or_method(method, ...) FUZZY_8051_SELECT_3(__VA_ARGS__, fuzzy_8051_or3, fuzzy_8051_or2)((method), __VA_ARGS__)
#define fuzzy_sugeno_weighted_average(w1,z1,w2,z2,w3,z3,w4,z4,w5,z5,w6,z6) ((((w1)*(z1))+((w2)*(z2))+((w3)*(z3))+((w4)*(z4))+((w5)*(z5))+((w6)*(z6)))/((w1)+(w2)+(w3)+(w4)+(w5)+(w6)))
#define fuzzy_sugeno_weighted_sum(w1,z1,w2,z2,w3,z3,w4,z4,w5,z5,w6,z6) (((w1)*(z1))+((w2)*(z2))+((w3)*(z3))+((w4)*(z4))+((w5)*(z5))+((w6)*(z6)))

#ifdef FUZZY_IMPLEMENTATION
static float fuzzy_8051_clamp(float value) { if (value < 0.0f) return 0.0f; if (value > 1.0f) return 1.0f; return value; }
static float fuzzy_8051_hedge(float value, fuzzy_hedge_t hedge) { float result; value = fuzzy_8051_clamp(value); if (hedge == 0u) hedge = 1u; result = 1.0f; while (hedge != 0u) { result *= value; --hedge; } return fuzzy_8051_clamp(result); }
float fuzzy_not(float membership) { return 1.0f - fuzzy_8051_clamp(membership); }
float fuzzy_ramp(float a, float b, float x, bool up, fuzzy_hedge_t hedge) { float result; if (a >= b) return 0.0f; if (x <= a) result = up ? 0.0f : 1.0f; else if (x >= b) result = up ? 1.0f : 0.0f; else { result = (x - a) / (b - a); if (!up) result = 1.0f - result; } return fuzzy_8051_hedge(result, hedge); }
float fuzzy_triangle(float a, float b, float c, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b >= c || x <= a || x >= c) result = 0.0f; else if (x == b) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (c - x) / (c - b); return fuzzy_8051_hedge(result, hedge); }
float fuzzy_trapezoid(float a, float b, float c, float d, float x, fuzzy_hedge_t hedge) { float result; if (a >= b || b > c || c >= d || x <= a || x >= d) result = 0.0f; else if (x >= b && x <= c) result = 1.0f; else if (x < b) result = (x - a) / (b - a); else result = (d - x) / (d - c); return fuzzy_8051_hedge(result, hedge); }
static float fuzzy_8051_eval(const fuzzy_variable_8051_t *v, float x) { if (v->shape == FUZZY_SHAPE_RAMP) return fuzzy_ramp(v->parameters[0], v->parameters[1], x, v->parameters[2] != 0.0f, v->hedge); if (v->shape == FUZZY_SHAPE_TRIANGLE) return fuzzy_triangle(v->parameters[0], v->parameters[1], v->parameters[2], x, v->hedge); if (v->shape == FUZZY_SHAPE_TRAPEZOID) return fuzzy_trapezoid(v->parameters[0], v->parameters[1], v->parameters[2], v->parameters[3], x, v->hedge); return 0.0f; }
bool fuzzy_rules_add_8051(fuzzy_rules_t *rules, float value, const fuzzy_variable_8051_t *output) { uint8_t index; if (rules->count >= FUZZY_MAX_RULES) return false; index = rules->count; rules->rules[index].value = fuzzy_8051_clamp(value); rules->rules[index].output = output; rules->count = index + 1u; return true; }
static float fuzzy_8051_height(const fuzzy_rules_t *rules, float x) { uint8_t i; float aggregate; float membership; float implied; aggregate = 0.0f; for (i = 0u; i < rules->count; ++i) { membership = fuzzy_8051_eval(rules->rules[i].output, x); implied = rules->rules[i].value < membership ? rules->rules[i].value : membership; if (implied > aggregate) aggregate = implied; } return aggregate; }
float fuzzy_rules_defuzzify(const fuzzy_rules_t *rules, float lower, float upper, float step, fuzzy_defuzz_method_t method) { float x; float h; float weighted; float sum; float maximum; float maximum_sum; float smallest; float largest; unsigned int maximum_count; if (rules->count == 0u || lower > upper || step <= 0.0f) return 0.0f; weighted = 0.0f; sum = 0.0f; maximum = -1.0f; maximum_sum = 0.0f; maximum_count = 0u; smallest = lower; largest = lower; for (x = lower; x <= upper; x += step) { h = fuzzy_8051_height(rules, x); weighted += x * h; sum += h; if (h > maximum) { maximum = h; maximum_sum = x; maximum_count = 1u; smallest = x; largest = x; } else if (h == maximum) { maximum_sum += x; ++maximum_count; largest = x; } } if (method == FUZZY_DEFUZZ_MOM) return maximum > 0.0f ? maximum_sum / (float)maximum_count : 0.0f; if (method == FUZZY_DEFUZZ_SOM) return maximum > 0.0f ? smallest : 0.0f; if (method == FUZZY_DEFUZZ_LOM) return maximum > 0.0f ? largest : 0.0f; return sum > 0.0f ? weighted / sum : 0.0f; }
float fuzzy_rules_cog(const fuzzy_rules_t *rules, float lower, float upper, float step) { return fuzzy_rules_defuzzify(rules, lower, upper, step, FUZZY_DEFUZZ_COG); }
#endif

#else

#include <stddef.h>

/* ==========================================================
 * Platform configuration
 * ========================================================== */

#ifdef FUZZY_8051

typedef unsigned char bool;
typedef unsigned char uint8_t;

#define false 0u
#define true 1u

#ifndef FUZZY_MAX_RULES
#define FUZZY_MAX_RULES 16u
#endif

typedef uint8_t fuzzy_hedge_t;

typedef struct FuzzyHedges {
    fuzzy_hedge_t none;
    fuzzy_hedge_t very;
    fuzzy_hedge_t extremely;
} hedges_t;

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

/* ==========================================================
 * Desktop configuration
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

#endif /* FUZZY_8051 */

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

bool fuzzy_gpu_sweep(const fuzzy_gpu_sweep_t *sweep);

bool fuzzy_gpu_interpolation_sweep(const fuzzy_interpolation_sweep_t *sweep);

#endif /* FUZZY_OPENCL */

#define FUZZY_INTERPOLATION_SWEEP(filename_arg, title_arg, points_arg, ...) fuzzy_interpolation_sweep(&(const fuzzy_interpolation_sweep_t){.filename = (filename_arg), .title = (title_arg), .dimensions = (const fuzzy_sweep_dimension_t[]){__VA_ARGS__}, .dimension_count = sizeof((const fuzzy_sweep_dimension_t[]){__VA_ARGS__}) / sizeof(fuzzy_sweep_dimension_t), .points = (points_arg), .point_count = sizeof(points_arg) / sizeof((points_arg)[0])})

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
            outputs
        );

    free(sample_counts);
    free(indices);
    free(inputs);
    free(outputs);

    return success;
}

bool fuzzy_gpu_interpolation_sweep(
    const fuzzy_interpolation_sweep_t *sweep
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
            outputs
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
        sweep->point_count
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

typedef struct fuzzy_neuron_train_options
{
    size_t epochs;
    size_t batch_size;
    float learning_rate;
    size_t report_every;
} fuzzy_neuron_train_options_t;

#ifdef FUZZY_NEURON_OPENCL

typedef struct fuzzy_neuron_opencl
{
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;

    cl_kernel forward_kernel;
    cl_kernel backward_kernel;
    cl_kernel update_kernel;

    cl_mem d_rules;
    cl_mem d_targets;
    cl_mem d_weights;
    cl_mem d_biases;
    cl_mem d_activations;
    cl_mem d_deltas;
    cl_mem d_weight_gradients;
    cl_mem d_bias_gradients;
    cl_mem d_layer_counts;
    cl_mem d_weight_offsets;
    cl_mem d_bias_offsets;
    cl_mem d_activation_kinds;

    size_t batch_capacity;
    bool ready;
} fuzzy_neuron_opencl_t;

#endif

typedef struct fuzzy_neuron_network
{
    size_t raw_input_dimensions;
    size_t output_dimensions;

    fuzzy_neuron_rule_t rules[FUZZY_NEURON_MAX_RULES];
    size_t rule_count;

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
    ((fuzzy_neuron_train_options_t){(epoch_count), (batch_count), (rate), (report)})

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

#define FUZZY_NEURON_MODEL(symbol, input_dimensions, output_dimensions, ...) \
    static fuzzy_neuron_network_t *symbol##_create(void) \
    { \
        fuzzy_neuron_network_t *model = malloc(sizeof(*model)); \
        fuzzy_neuron_init(model, (input_dimensions), (output_dimensions)); \
        __VA_ARGS__ \
        fuzzy_neuron_compile(model); \
        return model; \
    } \
    static void symbol##_destroy(fuzzy_neuron_network_t *model) \
    { \
        fuzzy_neuron_free(model); \
        free(model); \
    }

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

void fuzzy_neuron_init(
    fuzzy_neuron_network_t *network,
    size_t raw_input_dimensions,
    size_t output_dimensions
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
    const fuzzy_neuron_train_options_t *options
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

void fuzzy_neuron_init(
    fuzzy_neuron_network_t *network,
    size_t raw_input_dimensions,
    size_t output_dimensions
)
{
    memset(network, 0, sizeof(*network));

    network->raw_input_dimensions = raw_input_dimensions;
    network->output_dimensions = output_dimensions;
    network->random_state = 0x12345678u;
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

static void fuzzy_neuron_rules(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    float values[]
)
{
    size_t rule;

    for (rule = 0u; rule < network->rule_count; rule++)
    {
        values[rule] =
            network->rules[rule].evaluate(
                raw_inputs,
                network->raw_input_dimensions,
                network->rules[rule].user
            );
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
        "FNN1,%zu,%zu,%zu,%zu,%zu\n",
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
        strncmp(line, "FNN1,", 5) != 0)
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

static void fuzzy_neuron_opencl_release(
    fuzzy_neuron_opencl_t *cl
)
{
    if (!cl->ready)
    {
        return;
    }

    clReleaseMemObject(cl->d_activation_kinds);
    clReleaseMemObject(cl->d_bias_offsets);
    clReleaseMemObject(cl->d_weight_offsets);
    clReleaseMemObject(cl->d_layer_counts);
    clReleaseMemObject(cl->d_bias_gradients);
    clReleaseMemObject(cl->d_weight_gradients);
    clReleaseMemObject(cl->d_deltas);
    clReleaseMemObject(cl->d_activations);
    clReleaseMemObject(cl->d_biases);
    clReleaseMemObject(cl->d_weights);
    clReleaseMemObject(cl->d_targets);
    clReleaseMemObject(cl->d_rules);
    clReleaseKernel(cl->update_kernel);
    clReleaseKernel(cl->backward_kernel);
    clReleaseKernel(cl->forward_kernel);
    clReleaseProgram(cl->program);
    clReleaseCommandQueue(cl->queue);
    clReleaseContext(cl->context);
    memset(cl, 0, sizeof(*cl));
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
    char *log;
    size_t log_size;
    cl_uint *layer_counts;
    cl_uint *weight_offsets;
    cl_uint *bias_offsets;
    cl_uint *activation_kinds;
    size_t layer;

    if (network == NULL || !network->compiled || kernel_path == NULL || batch_capacity == 0u)
    {
        return false;
    }

    cl = &network->opencl;
    memset(cl, 0, sizeof(*cl));
    cl->batch_capacity = batch_capacity;
    source = fuzzy_neuron_read_text(kernel_path);

    if (source == NULL)
    {
        return false;
    }

    if (clGetPlatformIDs(1, &cl->platform, NULL) != CL_SUCCESS || clGetDeviceIDs(cl->platform, CL_DEVICE_TYPE_GPU, 1, &cl->device, NULL) != CL_SUCCESS)
    {
        free(source);
        return false;
    }

    cl->context = clCreateContext(NULL, 1, &cl->device, NULL, NULL, &error);
    cl->queue = clCreateCommandQueue(cl->context, cl->device, 0, &error);
    cl->program = clCreateProgramWithSource(cl->context, 1, (const char **)&source, NULL, &error);
    free(source);
    error = clBuildProgram(cl->program, 1, &cl->device, "-cl-fast-relaxed-math", NULL, NULL);

    if (error != CL_SUCCESS)
    {
        clGetProgramBuildInfo(cl->program, cl->device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
        log = malloc(log_size + 1u);
        clGetProgramBuildInfo(cl->program, cl->device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
        log[log_size] = '\0';
        fprintf(stderr, "%s\n", log);
        free(log);
        return false;
    }

    cl->forward_kernel = clCreateKernel(cl->program, "fn_forward", &error);
    cl->backward_kernel = clCreateKernel(cl->program, "fn_backward", &error);
    cl->update_kernel = clCreateKernel(cl->program, "fn_update", &error);
    layer_counts = malloc(network->layer_count * sizeof(*layer_counts));
    weight_offsets = malloc(network->layer_count * sizeof(*weight_offsets));
    bias_offsets = malloc(network->layer_count * sizeof(*bias_offsets));
    activation_kinds = malloc(network->layer_count * sizeof(*activation_kinds));

    for (layer = 0u; layer < network->layer_count; layer++)
    {
        layer_counts[layer] = (cl_uint)network->layers[layer].count;
        weight_offsets[layer] = (cl_uint)network->layers[layer].weight_offset;
        bias_offsets[layer] = (cl_uint)network->layers[layer].bias_offset;
        activation_kinds[layer] = (cl_uint)network->layers[layer].activation;
    }

    cl->d_rules = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, batch_capacity * network->rule_count * sizeof(float), NULL, &error);
    cl->d_targets = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, batch_capacity * network->output_dimensions * sizeof(float), NULL, &error);
    cl->d_weights = clCreateBuffer(cl->context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, network->weight_count * sizeof(float), network->weights, &error);
    cl->d_biases = clCreateBuffer(cl->context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, network->bias_count * sizeof(float), network->biases, &error);
    cl->d_activations = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, batch_capacity * network->neuron_count * sizeof(float), NULL, &error);
    cl->d_deltas = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, batch_capacity * network->neuron_count * sizeof(float), NULL, &error);
    cl->d_weight_gradients = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, batch_capacity * network->weight_count * sizeof(float), NULL, &error);
    cl->d_bias_gradients = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, batch_capacity * network->bias_count * sizeof(float), NULL, &error);
    cl->d_layer_counts = clCreateBuffer(cl->context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, network->layer_count * sizeof(cl_uint), layer_counts, &error);
    cl->d_weight_offsets = clCreateBuffer(cl->context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, network->layer_count * sizeof(cl_uint), weight_offsets, &error);
    cl->d_bias_offsets = clCreateBuffer(cl->context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, network->layer_count * sizeof(cl_uint), bias_offsets, &error);
    cl->d_activation_kinds = clCreateBuffer(cl->context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, network->layer_count * sizeof(cl_uint), activation_kinds, &error);
    free(layer_counts);
    free(weight_offsets);
    free(bias_offsets);
    free(activation_kinds);

    if (error != CL_SUCCESS)
    {
        return false;
    }

    cl->ready = true;
    return true;
}

static double fuzzy_neuron_dataset_mse(fuzzy_neuron_network_t *network, const fuzzy_neuron_dataset_t *dataset)
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
    const fuzzy_neuron_train_options_t *options
)
{
    fuzzy_neuron_opencl_t *cl;
    float *batch_rules;
    float *best_weights;
    float *best_biases;
    double best_loss = -1.0;
    size_t epoch;
    size_t batch_start;
    size_t batch_count;
    size_t sample;
    size_t rule;
    size_t global_size;
    cl_uint sample_count;
    cl_uint rule_count = (cl_uint)network->rule_count;
    cl_uint output_count = (cl_uint)network->output_dimensions;
    cl_uint layer_count = (cl_uint)network->layer_count;
    cl_uint neuron_count = (cl_uint)network->neuron_count;
    cl_uint weight_count = (cl_uint)network->weight_count;
    cl_uint bias_count = (cl_uint)network->bias_count;
    cl_float learning_rate = (cl_float)options->learning_rate;
    cl_int error;

    if (network == NULL || dataset == NULL || options == NULL || !network->opencl.ready || options->batch_size == 0u || options->batch_size > network->opencl.batch_capacity)
    {
        return false;
    }

    cl = &network->opencl;
    batch_rules = malloc(options->batch_size * network->rule_count * sizeof(*batch_rules));
    best_weights = malloc(network->weight_count * sizeof(*best_weights));
    best_biases = malloc(network->bias_count * sizeof(*best_biases));

    for (epoch = 0u; epoch < options->epochs; epoch++)
    {
        for (batch_start = 0u; batch_start < dataset->rows; batch_start += options->batch_size)
        {
            batch_count = options->batch_size;

            if (batch_start + batch_count > dataset->rows)
            {
                batch_count = dataset->rows - batch_start;
            }

            for (sample = 0u; sample < batch_count; sample++)
            {
                float total = 0.0f;
                fuzzy_neuron_rules(network, dataset->inputs + (batch_start + sample) * dataset->input_dimensions, batch_rules + sample * network->rule_count);

                for (rule = 0u; rule < network->rule_count; rule++)
                {
                    total += batch_rules[sample * network->rule_count + rule];
                }

                if (total > 1.0e-12f)
                {
                    for (rule = 0u; rule < network->rule_count; rule++)
                    {
                        batch_rules[sample * network->rule_count + rule] /= total;
                    }
                }
            }

            sample_count = (cl_uint)batch_count;
            error = clEnqueueWriteBuffer(cl->queue, cl->d_rules, CL_TRUE, 0, batch_count * network->rule_count * sizeof(float), batch_rules, 0, NULL, NULL);
            error |= clEnqueueWriteBuffer(cl->queue, cl->d_targets, CL_TRUE, 0, batch_count * network->output_dimensions * sizeof(float), dataset->targets + batch_start * dataset->target_dimensions, 0, NULL, NULL);
            error |= clSetKernelArg(cl->forward_kernel, 0, sizeof(cl_mem), &cl->d_rules);
            error |= clSetKernelArg(cl->forward_kernel, 1, sizeof(cl_mem), &cl->d_weights);
            error |= clSetKernelArg(cl->forward_kernel, 2, sizeof(cl_mem), &cl->d_biases);
            error |= clSetKernelArg(cl->forward_kernel, 3, sizeof(cl_mem), &cl->d_activations);
            error |= clSetKernelArg(cl->forward_kernel, 4, sizeof(cl_mem), &cl->d_layer_counts);
            error |= clSetKernelArg(cl->forward_kernel, 5, sizeof(cl_mem), &cl->d_weight_offsets);
            error |= clSetKernelArg(cl->forward_kernel, 6, sizeof(cl_mem), &cl->d_bias_offsets);
            error |= clSetKernelArg(cl->forward_kernel, 7, sizeof(cl_mem), &cl->d_activation_kinds);
            error |= clSetKernelArg(cl->forward_kernel, 8, sizeof(sample_count), &sample_count);
            error |= clSetKernelArg(cl->forward_kernel, 9, sizeof(rule_count), &rule_count);
            error |= clSetKernelArg(cl->forward_kernel, 10, sizeof(layer_count), &layer_count);
            error |= clSetKernelArg(cl->forward_kernel, 11, sizeof(neuron_count), &neuron_count);
            global_size = batch_count;
            error |= clEnqueueNDRangeKernel(cl->queue, cl->forward_kernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);
            error |= clSetKernelArg(cl->backward_kernel, 0, sizeof(cl_mem), &cl->d_targets);
            error |= clSetKernelArg(cl->backward_kernel, 1, sizeof(cl_mem), &cl->d_weights);
            error |= clSetKernelArg(cl->backward_kernel, 2, sizeof(cl_mem), &cl->d_activations);
            error |= clSetKernelArg(cl->backward_kernel, 3, sizeof(cl_mem), &cl->d_deltas);
            error |= clSetKernelArg(cl->backward_kernel, 4, sizeof(cl_mem), &cl->d_weight_gradients);
            error |= clSetKernelArg(cl->backward_kernel, 5, sizeof(cl_mem), &cl->d_bias_gradients);
            error |= clSetKernelArg(cl->backward_kernel, 6, sizeof(cl_mem), &cl->d_layer_counts);
            error |= clSetKernelArg(cl->backward_kernel, 7, sizeof(cl_mem), &cl->d_weight_offsets);
            error |= clSetKernelArg(cl->backward_kernel, 8, sizeof(cl_mem), &cl->d_bias_offsets);
            error |= clSetKernelArg(cl->backward_kernel, 9, sizeof(cl_mem), &cl->d_activation_kinds);
            error |= clSetKernelArg(cl->backward_kernel, 10, sizeof(sample_count), &sample_count);
            error |= clSetKernelArg(cl->backward_kernel, 11, sizeof(rule_count), &rule_count);
            error |= clSetKernelArg(cl->backward_kernel, 12, sizeof(output_count), &output_count);
            error |= clSetKernelArg(cl->backward_kernel, 13, sizeof(layer_count), &layer_count);
            error |= clSetKernelArg(cl->backward_kernel, 14, sizeof(neuron_count), &neuron_count);
            error |= clSetKernelArg(cl->backward_kernel, 15, sizeof(weight_count), &weight_count);
            error |= clSetKernelArg(cl->backward_kernel, 16, sizeof(bias_count), &bias_count);
            error |= clEnqueueNDRangeKernel(cl->queue, cl->backward_kernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);
            error |= clSetKernelArg(cl->update_kernel, 0, sizeof(cl_mem), &cl->d_weights);
            error |= clSetKernelArg(cl->update_kernel, 1, sizeof(cl_mem), &cl->d_weight_gradients);
            error |= clSetKernelArg(cl->update_kernel, 2, sizeof(weight_count), &weight_count);
            error |= clSetKernelArg(cl->update_kernel, 3, sizeof(sample_count), &sample_count);
            error |= clSetKernelArg(cl->update_kernel, 4, sizeof(learning_rate), &learning_rate);
            global_size = network->weight_count;
            error |= clEnqueueNDRangeKernel(cl->queue, cl->update_kernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);
            error |= clSetKernelArg(cl->update_kernel, 0, sizeof(cl_mem), &cl->d_biases);
            error |= clSetKernelArg(cl->update_kernel, 1, sizeof(cl_mem), &cl->d_bias_gradients);
            error |= clSetKernelArg(cl->update_kernel, 2, sizeof(bias_count), &bias_count);
            global_size = network->bias_count;
            error |= clEnqueueNDRangeKernel(cl->queue, cl->update_kernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);

            if (error != CL_SUCCESS)
            {
                free(batch_rules);
                free(best_weights);
                free(best_biases);
                return false;
            }
        }

        if (options->report_every && (epoch % options->report_every == 0u || epoch + 1u == options->epochs))
        {
            double loss;
            clFinish(cl->queue);
            clEnqueueReadBuffer(cl->queue, cl->d_weights, CL_TRUE, 0, network->weight_count * sizeof(float), network->weights, 0, NULL, NULL);
            clEnqueueReadBuffer(cl->queue, cl->d_biases, CL_TRUE, 0, network->bias_count * sizeof(float), network->biases, 0, NULL, NULL);
            loss = fuzzy_neuron_dataset_mse(network, dataset);
            printf("Epoch %4u MSE %.10f\n", (unsigned int)(epoch + 1u), loss);

            if (best_loss < 0.0 || loss < best_loss)
            {
                best_loss = loss;
                size_t index;
                for (index = 0u; index < network->weight_count; index++) best_weights[index] = network->weights[index];
                for (index = 0u; index < network->bias_count; index++) best_biases[index] = network->biases[index];
            }
        }
    }

    if (best_loss >= 0.0)
    {
        size_t index;
        for (index = 0u; index < network->weight_count; index++) network->weights[index] = best_weights[index];
        for (index = 0u; index < network->bias_count; index++) network->biases[index] = best_biases[index];
        clEnqueueWriteBuffer(cl->queue, cl->d_weights, CL_TRUE, 0, network->weight_count * sizeof(float), network->weights, 0, NULL, NULL);
        clEnqueueWriteBuffer(cl->queue, cl->d_biases, CL_TRUE, 0, network->bias_count * sizeof(float), network->biases, 0, NULL, NULL);
        printf("Best MSE %.10f restored\n", best_loss);
    }

    free(batch_rules);
    free(best_weights);
    free(best_biases);
    return true;
}

bool fuzzy_neuron_opencl_predict(
    fuzzy_neuron_network_t *network,
    const float raw_inputs[],
    size_t rows,
    float outputs[]
)
{
    if (network == NULL ||
        !network->opencl.ready)
    {
        return false;
    }

    return fuzzy_neuron_predict_batch(
        network,
        raw_inputs,
        rows,
        outputs
    );
}

void fuzzy_neuron_opencl_free(
    fuzzy_neuron_network_t *network
)
{
    if (network != NULL)
    {
        fuzzy_neuron_opencl_release(
            &network->opencl
        );
    }
}

#endif /* FUZZY_NEURON_OPENCL */
#endif /* FUZZY_NEURON_IMPLEMENTATION_ONCE */
#endif /* FUZZY_NEURON_IMPLEMENTATION */
#endif /* FUZZY_8051 */

#endif /* FUZZY_H */
