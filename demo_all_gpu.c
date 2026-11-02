/*
 * Complete fuzzy.h demonstration.
 *
 * This program exercises the largest practical portion of
 * the fuzzy.h public API using a five-input industrial
 * process-response system.
 *
 * Crisp inputs:
 *
 * 1. Temperature
 * 2. Humidity
 * 3. Vibration
 * 4. Pressure
 * 5. Material quality
 *
 * Crisp output:
 *
 * - Process response level
 *
 * Demonstrated features:
 *
 * - Ramp membership functions
 * - Triangle membership functions
 * - Trapezoid membership functions
 * - S-shaped membership functions
 * - Z-shaped membership functions
 * - Pi-shaped membership functions
 * - Gaussian membership functions
 * - Two-sided Gaussian membership functions
 * - Generalized bell membership functions
 * - Sigmoid membership functions
 * - Difference-of-sigmoids membership functions
 * - Product-of-sigmoids membership functions
 * - Five-dimensional sampled-membership interpolation
 * - Linguistic hedges
 * - Fuzzy AND
 * - Fuzzy OR
 * - Nested fuzzy expressions
 * - Minimum and product implication
 * - Maximum, algebraic, and bounded aggregation
 * - Mamdani rule aggregation
 * - COG defuzzification
 * - BOA defuzzification
 * - COS defuzzification
 * - MOM defuzzification
 * - SOM defuzzification
 * - LOM defuzzification
 * - Membership-function SVG plots
 * - Selected COG, BOA, COS, MOM, SOM, and LOM SVG plots
 * - Five-dimensional membership interpolation sweep CSV
 * - Interactive five-dimensional membership sweep SVG
 * - Five-dimensional COG sweep CSV
 * - Interactive five-dimensional COG sweep SVG
 * - Random crisp input generation
 */

#include <time.h>

#ifndef FUZZY_OPENCL
#define FUZZY_OPENCL
#endif

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"


/* ==========================================================
 * Output paths and numerical ranges
 * ========================================================== */

#define DEMO_DIRECTORY              "demo-gpu"

#define RESPONSE_LOWER              0.0f
#define RESPONSE_UPPER              100.0f

#define NORMAL_COG_STEP             0.1f
#define SWEEP_COG_STEP              1.0f


/* ==========================================================
 * User-defined linguistic hedge exponents
 * ========================================================== */

static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};

/* ==========================================================
 * Randomized membership-function parameters
 *
 * Parameters are generated once when the program starts.
 * They remain fixed during plotting, rule evaluation,
 * defuzzification, and the complete N-dimensional sweep.
 * ========================================================== */

typedef struct RandomFuzzyParameters {
    /*
     * Temperature.
     */
    float temperature_low[2];
    float temperature_medium[2];
    float temperature_high[2];

    /*
     * Humidity.
     */
    float humidity_low[2];
    float humidity_medium[4];
    float humidity_high[2];

    /*
     * Vibration.
     */
    float vibration_low[2];
    float vibration_medium[3];
    float vibration_high[2];

    /*
     * Pressure.
     */
    float pressure_low[2];
    float pressure_normal[3];
    float pressure_high[2];

    /*
     * Material quality.
     */
    float quality_poor[2];
    float quality_average[2];
    float quality_good[2];

    /*
     * Process response.
     */
    float response_minimal[2];
    float response_low[3];
    float response_moderate[4];
    float response_high[3];
    float response_critical[2];

    /*
     * Generic shape demonstration.
     */
    float shape_ramp[2];
    float shape_triangle[3];
    float shape_trapezoid[4];
    float shape_smf[2];
    float shape_zmf[2];
    float shape_pimf[4];
    float shape_gauss[2];
    float shape_gauss2[4];
    float shape_bell[3];
    float shape_sigmoid[2];
    float shape_dsigmoid[4];
    float shape_psigmoid[4];

    /*
     * Shared randomized trapezoid for hedge comparison.
     *
     * Every hedge must use the same base function so the
     * only visible difference is the hedge exponent.
     */
    float hedge_trapezoid[4];
} random_fuzzy_parameters_t;


static random_fuzzy_parameters_t parameters;

/* ==========================================================
 * GPU controller storage
 *
 * The original CPU demonstration remains unchanged. These
 * descriptor arrays are populated from the same randomized
 * parameters after randomize_membership_parameters(), then
 * consumed directly by the generic OpenCL backend in fuzzy.h.
 * ========================================================== */

/* ==========================================================
 * GPU controller storage
 * ========================================================== */

static fuzzy_gpu_variable_t process_gpu_variables[19];
static fuzzy_gpu_variable_t process_gpu_outputs[5];

/*
 * These identifiers must follow the exact order used when
 * process_gpu_variables[] is populated.
 */
enum {
    temperature_low_gpu_id,
    temperature_medium_gpu_id,
    temperature_high_gpu_id,

    humidity_low_gpu_id,
    humidity_medium_gpu_id,
    humidity_high_gpu_id,

    vibration_low_gpu_id,
    vibration_medium_gpu_id,
    vibration_high_gpu_id,

    pressure_low_gpu_id,
    pressure_normal_gpu_id,
    pressure_high_gpu_id,

    quality_poor_gpu_id,
    quality_average_gpu_id,
    quality_good_gpu_id,

    temperature_high_very_gpu_id,
    humidity_high_somewhat_gpu_id,
    pressure_high_extremely_gpu_id,
    quality_good_slightly_gpu_id
};

/*
 * These identifiers must follow the exact order used when
 * process_gpu_outputs[] is populated.
 */
enum {
    response_minimal_gpu_id,
    response_low_gpu_id,
    response_moderate_gpu_id,
    response_high_gpu_id,
    response_critical_gpu_id
};

static const fuzzy_gpu_rule_t process_gpu_rules[] = {
    FUZZY_GPU_RULE(
        temperature_low,
        FUZZY_OPERATOR_AND,
        humidity_medium,
        response_minimal
    ),

    FUZZY_GPU_RULE(
        temperature_medium,
        FUZZY_OPERATOR_AND,
        pressure_normal,
        response_low
    ),

    FUZZY_GPU_RULE(
        humidity_high,
        FUZZY_OPERATOR_OR,
        vibration_medium,
        response_moderate
    ),

    FUZZY_GPU_RULE(
        temperature_high,
        FUZZY_OPERATOR_AND,
        vibration_high,
        response_high
    ),

    FUZZY_GPU_RULE(
        pressure_high,
        FUZZY_OPERATOR_OR,
        vibration_high,
        response_high
    ),

    FUZZY_GPU_RULE(
        temperature_high_very,
        FUZZY_OPERATOR_AND,
        pressure_high,
        response_critical
    ),

    FUZZY_GPU_RULE(
        humidity_high_somewhat,
        FUZZY_OPERATOR_OR,
        pressure_high_extremely,
        response_critical
    ),

    FUZZY_GPU_RULE(
        temperature_medium,
        FUZZY_OPERATOR_AND,
        quality_good_slightly,
        response_high
    ),

    FUZZY_GPU_RULE(
        temperature_low,
        FUZZY_OPERATOR_OR,
        humidity_low,
        response_low
    ),

    FUZZY_GPU_RULE(
        pressure_high,
        FUZZY_OPERATOR_AND,
        quality_poor,
        response_critical
    ),

    FUZZY_GPU_RULE(
        vibration_low,
        FUZZY_OPERATOR_AND,
        quality_good,
        response_minimal
    )
};
FUZZY_GPU_CONTROLLER(
    process_gpu,
    process_gpu_variables,
    process_gpu_outputs,
    process_gpu_rules,
    FUZZY_LOGIC_STANDARD,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX,
    FUZZY_DEFUZZ_COG,
    RESPONSE_LOWER,
    RESPONSE_UPPER
);


/* ==========================================================
 * Randomized fuzzy-NOT rule
 *
 * One NOT-based rule is selected when the application starts.
 * The selection remains fixed throughout plotting, normal
 * evaluation, and the complete five-dimensional sweep.
 *
 * Random selection must not occur inside build_process_rules()
 * because every sweep point must use the same fuzzy system.
 * ========================================================== */

typedef enum RandomNotRule {
    RANDOM_NOT_TEMPERATURE_HIGH = 0,
    RANDOM_NOT_HUMIDITY_LOW,
    RANDOM_NOT_VIBRATION_LOW,
    RANDOM_NOT_PRESSURE_HIGH,
    RANDOM_NOT_QUALITY_GOOD,

    RANDOM_NOT_RULE_COUNT
} random_not_rule_t;


static random_not_rule_t random_not_rule = RANDOM_NOT_TEMPERATURE_HIGH;

static float random_float(float lower, float upper)
{
    return lower + (float)rand() / (float)RAND_MAX * (upper - lower);
}

static void random_ordered_2(float output[2], float lower, float upper, float gap)
{
    output[0] = random_float(lower, upper - gap);
    output[1] = random_float(output[0] + gap, upper);
}

static void random_ordered_3(float output[3], float lower, float upper, float gap)
{
    output[0] = random_float(lower, upper - 2.0f * gap);
    output[1] = random_float(output[0] + gap, upper - gap);
    output[2] = random_float(output[1] + gap, upper);
}

static void random_ordered_4(float output[4], float lower, float upper, float gap)
{
    output[0] = random_float(lower, upper - 3.0f * gap);
    output[1] = random_float(output[0] + gap, upper - 2.0f * gap);
    output[2] = random_float(output[1] + gap, upper - gap);
    output[3] = random_float(output[2] + gap, upper);
}


/*
 * Generate all membership-function parameters once.
 *
 * The ranges are constrained so linguistic terms remain
 * meaningful:
 *
 * - Low functions remain toward the lower region.
 * - Medium functions remain around the middle region.
 * - High functions remain toward the upper region.
 * - Triangle and trapezoid points remain strictly ordered.
 * - Gaussian deviation remains positive.
 * - Bell width and slope remain positive.
 */
static void randomize_membership_parameters(void)
{
    random_ordered_2(parameters.temperature_low, 10.0f, 48.0f, 8.0f);
    parameters.temperature_medium[0] = random_float(38.0f, 62.0f);
    parameters.temperature_medium[1] = random_float(8.0f, 20.0f);
    random_ordered_2(parameters.temperature_high, 52.0f, 95.0f, 8.0f);

    random_ordered_2(parameters.humidity_low, 10.0f, 48.0f, 8.0f);
    random_ordered_4(parameters.humidity_medium, 18.0f, 82.0f, 8.0f);
    parameters.humidity_high[0] = random_float(0.07f, 0.20f);
    parameters.humidity_high[1] = random_float(55.0f, 78.0f);

    random_ordered_2(parameters.vibration_low, 0.5f, 4.8f, 1.0f);
    parameters.vibration_medium[0] = random_float(3.0f, 6.5f);
    parameters.vibration_medium[1] = random_float(1.5f, 4.0f);
    parameters.vibration_medium[2] = random_float(3.5f, 6.5f);
    random_ordered_2(parameters.vibration_high, 5.0f, 9.8f, 1.0f);

    random_ordered_2(parameters.pressure_low, 20.0f, 95.0f, 20.0f);
    random_ordered_3(parameters.pressure_normal, 45.0f, 175.0f, 25.0f);
    parameters.pressure_high[0] = random_float(0.035f, 0.095f);
    parameters.pressure_high[1] = random_float(125.0f, 170.0f);

    random_ordered_2(parameters.quality_poor, 10.0f, 52.0f, 10.0f);
    parameters.quality_average[0] = random_float(42.0f, 65.0f);
    parameters.quality_average[1] = random_float(8.0f, 20.0f);
    random_ordered_2(parameters.quality_good, 50.0f, 96.0f, 10.0f);

    random_ordered_2(parameters.response_minimal, 5.0f, 35.0f, 8.0f);
    random_ordered_3(parameters.response_low, 5.0f, 55.0f, 10.0f);
    random_ordered_4(parameters.response_moderate, 22.0f, 76.0f, 8.0f);
    random_ordered_3(parameters.response_high, 48.0f, 95.0f, 8.0f);
    random_ordered_2(parameters.response_critical, 68.0f, 99.0f, 7.0f);

    random_ordered_2(parameters.shape_ramp, 10.0f, 90.0f, 20.0f);
    random_ordered_3(parameters.shape_triangle, 5.0f, 95.0f, 15.0f);
    random_ordered_4(parameters.shape_trapezoid, 5.0f, 95.0f, 12.0f);
    random_ordered_2(parameters.shape_smf, 10.0f, 90.0f, 20.0f);
    random_ordered_2(parameters.shape_zmf, 10.0f, 90.0f, 20.0f);
    random_ordered_4(parameters.shape_pimf, 5.0f, 95.0f, 12.0f);

    parameters.shape_gauss[0] = random_float(30.0f, 70.0f);
    parameters.shape_gauss[1] = random_float(8.0f, 22.0f);

    parameters.shape_gauss2[0] = random_float(20.0f, 40.0f);
    parameters.shape_gauss2[1] = random_float(6.0f, 15.0f);
    parameters.shape_gauss2[2] = random_float(60.0f, 80.0f);
    parameters.shape_gauss2[3] = random_float(6.0f, 15.0f);

    parameters.shape_bell[0] = random_float(20.0f, 55.0f);
    parameters.shape_bell[1] = random_float(1.5f, 4.0f);
    parameters.shape_bell[2] = random_float(30.0f, 70.0f);

    parameters.shape_sigmoid[0] = random_float(0.06f, 0.20f);
    parameters.shape_sigmoid[1] = random_float(30.0f, 70.0f);

    parameters.shape_dsigmoid[0] = random_float(0.08f, 0.20f);
    parameters.shape_dsigmoid[1] = random_float(20.0f, 40.0f);
    parameters.shape_dsigmoid[2] = random_float(0.08f, 0.20f);
    parameters.shape_dsigmoid[3] = random_float(60.0f, 80.0f);

    parameters.shape_psigmoid[0] = random_float(0.08f, 0.20f);
    parameters.shape_psigmoid[1] = random_float(20.0f, 40.0f);
    parameters.shape_psigmoid[2] = -random_float(0.08f, 0.20f);
    parameters.shape_psigmoid[3] = random_float(60.0f, 80.0f);

    random_ordered_4(parameters.hedge_trapezoid, 5.0f, 95.0f, 12.0f);
    random_not_rule = (random_not_rule_t)(rand() % RANDOM_NOT_RULE_COUNT);
}


static void initialize_process_gpu_controller(void)
{
    process_gpu_variables[0] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        0,
        FUZZY_SHAPE_ZMF,
        hedges.none,
        parameters.temperature_low[0],
        parameters.temperature_low[1]
    );

    process_gpu_variables[1] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        0,
        FUZZY_SHAPE_GAUSSIAN,
        hedges.none,
        parameters.temperature_medium[0],
        parameters.temperature_medium[1]
    );

    process_gpu_variables[2] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        0,
        FUZZY_SHAPE_SMF,
        hedges.none,
        parameters.temperature_high[0],
        parameters.temperature_high[1]
    );

    process_gpu_variables[3] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        1,
        FUZZY_SHAPE_RAMP,
        hedges.none,
        parameters.humidity_low[0],
        parameters.humidity_low[1],
        0.0f
    );

    process_gpu_variables[4] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        1,
        FUZZY_SHAPE_TRAPEZOID,
        hedges.none,
        parameters.humidity_medium[0],
        parameters.humidity_medium[1],
        parameters.humidity_medium[2],
        parameters.humidity_medium[3]
    );

    process_gpu_variables[5] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        1,
        FUZZY_SHAPE_SIGMOID,
        hedges.none,
        parameters.humidity_high[0],
        parameters.humidity_high[1]
    );

    process_gpu_variables[6] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        2,
        FUZZY_SHAPE_ZMF,
        hedges.none,
        parameters.vibration_low[0],
        parameters.vibration_low[1]
    );

    process_gpu_variables[7] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        2,
        FUZZY_SHAPE_BELL,
        hedges.none,
        parameters.vibration_medium[0],
        parameters.vibration_medium[1],
        parameters.vibration_medium[2]
    );

    process_gpu_variables[8] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        2,
        FUZZY_SHAPE_SMF,
        hedges.none,
        parameters.vibration_high[0],
        parameters.vibration_high[1]
    );

    process_gpu_variables[9] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        3,
        FUZZY_SHAPE_RAMP,
        hedges.none,
        parameters.pressure_low[0],
        parameters.pressure_low[1],
        0.0f
    );

    process_gpu_variables[10] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        3,
        FUZZY_SHAPE_TRIANGLE,
        hedges.none,
        parameters.pressure_normal[0],
        parameters.pressure_normal[1],
        parameters.pressure_normal[2]
    );

    process_gpu_variables[11] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        3,
        FUZZY_SHAPE_SIGMOID,
        hedges.none,
        parameters.pressure_high[0],
        parameters.pressure_high[1]
    );

    process_gpu_variables[12] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        4,
        FUZZY_SHAPE_ZMF,
        hedges.none,
        parameters.quality_poor[0],
        parameters.quality_poor[1]
    );

    process_gpu_variables[13] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        4,
        FUZZY_SHAPE_GAUSSIAN,
        hedges.none,
        parameters.quality_average[0],
        parameters.quality_average[1]
    );

    process_gpu_variables[14] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        4,
        FUZZY_SHAPE_SMF,
        hedges.none,
        parameters.quality_good[0],
        parameters.quality_good[1]
    );

    process_gpu_variables[15] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        0,
        FUZZY_SHAPE_SMF,
        hedges.very,
        parameters.temperature_high[0],
        parameters.temperature_high[1]
    );

    process_gpu_variables[16] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        2,
        FUZZY_SHAPE_SMF,
        hedges.extremely,
        parameters.vibration_high[0],
        parameters.vibration_high[1]
    );

    process_gpu_variables[17] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        4,
        FUZZY_SHAPE_ZMF,
        hedges.very,
        parameters.quality_poor[0],
        parameters.quality_poor[1]
    );

    process_gpu_variables[18] = (fuzzy_gpu_variable_t)FUZZY_GPU_VARIABLE(
        1,
        FUZZY_SHAPE_SIGMOID,
        hedges.somewhat,
        parameters.humidity_high[0],
        parameters.humidity_high[1]
    );

    process_gpu_outputs[0] = (fuzzy_gpu_variable_t)FUZZY_GPU_OUTPUT(
        FUZZY_SHAPE_ZMF,
        hedges.none,
        parameters.response_minimal[0],
        parameters.response_minimal[1]
    );

    process_gpu_outputs[1] = (fuzzy_gpu_variable_t)FUZZY_GPU_OUTPUT(
        FUZZY_SHAPE_TRIANGLE,
        hedges.none,
        parameters.response_low[0],
        parameters.response_low[1],
        parameters.response_low[2]
    );

    process_gpu_outputs[2] = (fuzzy_gpu_variable_t)FUZZY_GPU_OUTPUT(
        FUZZY_SHAPE_TRAPEZOID,
        hedges.none,
        parameters.response_moderate[0],
        parameters.response_moderate[1],
        parameters.response_moderate[2],
        parameters.response_moderate[3]
    );

    process_gpu_outputs[3] = (fuzzy_gpu_variable_t)FUZZY_GPU_OUTPUT(
        FUZZY_SHAPE_TRIANGLE,
        hedges.none,
        parameters.response_high[0],
        parameters.response_high[1],
        parameters.response_high[2]
    );

    process_gpu_outputs[4] = (fuzzy_gpu_variable_t)FUZZY_GPU_OUTPUT(
        FUZZY_SHAPE_SMF,
        hedges.none,
        parameters.response_critical[0],
        parameters.response_critical[1]
    );
}

static void print_process_gpu_hedges(void)
{
    printf(
        "\nGPU linguistic hedge configuration\n"
        "==================================\n"
        "Variable 15: very temperature high      exponent %.2f\n"
        "Variable 16: extremely vibration high  exponent %.2f\n"
        "Variable 17: very material quality poor exponent %.2f\n"
        "Variable 18: somewhat humidity high    exponent %.2f\n",
        process_gpu_variables[15].hedge,
        process_gpu_variables[16].hedge,
        process_gpu_variables[17].hedge,
        process_gpu_variables[18].hedge
    );
}

/* ==========================================================
 * Randomized temperature membership functions
 * ========================================================== */
FUZZY_VAR(temperature_low, FUZZY_SHAPE_ZMF, hedges.none, parameters.temperature_low[0], parameters.temperature_low[1])

FUZZY_VAR(temperature_medium, FUZZY_SHAPE_GAUSSIAN, hedges.none, parameters.temperature_medium[0], parameters.temperature_medium[1])

FUZZY_VAR(temperature_high, FUZZY_SHAPE_SMF, hedges.none, parameters.temperature_high[0], parameters.temperature_high[1])

FUZZY_VAR(humidity_low, FUZZY_SHAPE_RAMP, hedges.none, parameters.humidity_low[0], parameters.humidity_low[1], false)

FUZZY_VAR(humidity_medium, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.humidity_medium[0], parameters.humidity_medium[1], parameters.humidity_medium[2], parameters.humidity_medium[3])

FUZZY_VAR(humidity_high, FUZZY_SHAPE_SIGMOID, hedges.none, parameters.humidity_high[0], parameters.humidity_high[1])

FUZZY_VAR(vibration_low, FUZZY_SHAPE_ZMF, hedges.none, parameters.vibration_low[0], parameters.vibration_low[1])

FUZZY_VAR(vibration_medium, FUZZY_SHAPE_BELL, hedges.none, parameters.vibration_medium[0], parameters.vibration_medium[1], parameters.vibration_medium[2])

FUZZY_VAR(vibration_high, FUZZY_SHAPE_SMF, hedges.none, parameters.vibration_high[0], parameters.vibration_high[1])

FUZZY_VAR(pressure_low, FUZZY_SHAPE_RAMP, hedges.none, parameters.pressure_low[0], parameters.pressure_low[1], false)

FUZZY_VAR(pressure_normal, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.pressure_normal[0], parameters.pressure_normal[1], parameters.pressure_normal[2])

FUZZY_VAR(pressure_high, FUZZY_SHAPE_SIGMOID, hedges.none, parameters.pressure_high[0], parameters.pressure_high[1])

FUZZY_VAR(quality_poor, FUZZY_SHAPE_ZMF, hedges.none, parameters.quality_poor[0], parameters.quality_poor[1])

FUZZY_VAR(quality_average, FUZZY_SHAPE_GAUSSIAN, hedges.none, parameters.quality_average[0], parameters.quality_average[1])

FUZZY_VAR(quality_good, FUZZY_SHAPE_SMF, hedges.none, parameters.quality_good[0], parameters.quality_good[1])

FUZZY_VAR(response_minimal, FUZZY_SHAPE_ZMF, hedges.none, parameters.response_minimal[0], parameters.response_minimal[1])

FUZZY_VAR(response_low, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.response_low[0], parameters.response_low[1], parameters.response_low[2])

FUZZY_VAR(response_moderate, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.response_moderate[0], parameters.response_moderate[1], parameters.response_moderate[2], parameters.response_moderate[3])

FUZZY_VAR(response_high, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.response_high[0], parameters.response_high[1], parameters.response_high[2])

FUZZY_VAR(response_critical, FUZZY_SHAPE_SMF, hedges.none, parameters.response_critical[0], parameters.response_critical[1])

FUZZY_VAR(hedge_none_demo, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_very_demo, FUZZY_SHAPE_TRAPEZOID, hedges.very, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_extremely_demo, FUZZY_SHAPE_TRAPEZOID, hedges.extremely, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_somewhat_demo, FUZZY_SHAPE_TRAPEZOID, hedges.somewhat, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_slightly_demo, FUZZY_SHAPE_TRAPEZOID, hedges.slightly, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(shape_ramp_demo, FUZZY_SHAPE_RAMP, hedges.none, parameters.shape_ramp[0], parameters.shape_ramp[1], true)

FUZZY_VAR(shape_triangle_demo, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.shape_triangle[0], parameters.shape_triangle[1], parameters.shape_triangle[2])

FUZZY_VAR(shape_trapezoid_demo, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.shape_trapezoid[0], parameters.shape_trapezoid[1], parameters.shape_trapezoid[2], parameters.shape_trapezoid[3])

FUZZY_VAR(shape_smf_demo, FUZZY_SHAPE_SMF, hedges.none, parameters.shape_smf[0], parameters.shape_smf[1])

FUZZY_VAR(shape_zmf_demo, FUZZY_SHAPE_ZMF, hedges.none, parameters.shape_zmf[0], parameters.shape_zmf[1])

FUZZY_VAR(shape_pimf_demo, FUZZY_SHAPE_PIMF, hedges.none, parameters.shape_pimf[0], parameters.shape_pimf[1], parameters.shape_pimf[2], parameters.shape_pimf[3])

FUZZY_VAR(shape_gauss_demo, FUZZY_SHAPE_GAUSSIAN, hedges.none, parameters.shape_gauss[0], parameters.shape_gauss[1])

FUZZY_VAR(shape_gauss2_demo, FUZZY_SHAPE_GAUSSIAN2, hedges.none, parameters.shape_gauss2[0], parameters.shape_gauss2[1], parameters.shape_gauss2[2], parameters.shape_gauss2[3])

FUZZY_VAR(shape_bell_demo, FUZZY_SHAPE_BELL, hedges.none, parameters.shape_bell[0], parameters.shape_bell[1], parameters.shape_bell[2])

FUZZY_VAR(shape_sigmoid_demo, FUZZY_SHAPE_SIGMOID, hedges.none, parameters.shape_sigmoid[0], parameters.shape_sigmoid[1])

FUZZY_VAR(shape_dsigmoid_demo, FUZZY_SHAPE_DSIGMOID, hedges.none, parameters.shape_dsigmoid[0], parameters.shape_dsigmoid[1], parameters.shape_dsigmoid[2], parameters.shape_dsigmoid[3])

FUZZY_VAR(shape_psigmoid_demo, FUZZY_SHAPE_PSIGMOID, hedges.none, parameters.shape_psigmoid[0], parameters.shape_psigmoid[1], parameters.shape_psigmoid[2], parameters.shape_psigmoid[3])

/* ==========================================================
 * Five-dimensional sampled-membership interpolation
 *
 * Axis order:
 *
 * 1. Temperature
 * 2. Humidity
 * 3. Vibration
 * 4. Pressure
 * 5. Material quality
 * ========================================================== */

static float sampled_membership_coordinates[5][5];
static fuzzy_point_t sampled_membership_points[5];



/* ==========================================================
 * Randomized fuzzy-NOT rule evaluation
 *
 * The selected rule remains fixed for the complete run.
 *
 * Possible rules:
 *
 * 1. IF temperature is NOT high
 *    AND pressure is normal
 *    THEN response is low.
 *
 * 2. IF humidity is NOT low
 *    AND vibration is medium
 *    THEN response is moderate.
 *
 * 3. IF vibration is NOT low
 *    AND pressure is high
 *    THEN response is high.
 *
 * 4. IF pressure is NOT high
 *    AND quality is good
 *    THEN response is minimal.
 *
 * 5. IF quality is NOT good
 *    OR temperature is high
 *    THEN response is high.
 * ========================================================== */

static float evaluate_random_not_rule(float temperature, float humidity, float vibration, float pressure, float quality, fuzzy_logic_method_t method)
{
    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            return fuzzy_and_method(method, fuzzy_not(temperature_high(temperature)), pressure_normal(pressure));

        case RANDOM_NOT_HUMIDITY_LOW:
            return fuzzy_and_method(method, fuzzy_not(humidity_low(humidity)), vibration_medium(vibration));

        case RANDOM_NOT_VIBRATION_LOW:
            return fuzzy_and_method(method, fuzzy_not(vibration_low(vibration)), pressure_high(pressure));

        case RANDOM_NOT_PRESSURE_HIGH:
            return fuzzy_and_method(method, fuzzy_not(pressure_high(pressure)), quality_good(quality));

        default:
            return fuzzy_or_method(method, fuzzy_not(quality_good(quality)), temperature_high(temperature));
    }
}

static const char *random_not_rule_name(void)
{
    static const char *names[] = {
        "Rule 11: NOT high temperature response",
        "Rule 11: NOT low humidity response",
        "Rule 11: NOT low vibration response",
        "Rule 11: NOT high pressure response",
        "Rule 11: NOT good quality response"
    };

    return names[random_not_rule];
}

static fuzzy_output_function_t random_not_output(void)
{
    static fuzzy_output_function_t outputs[] = {
        response_low,
        response_moderate,
        response_high,
        response_minimal,
        response_high
    };

    return outputs[random_not_rule];
}

/* ==========================================================
 * Complex Mamdani rule construction
 * ========================================================== */

/* ==========================================================
 * Complex Mamdani rule construction
 *
 * Rules 1 through 11 use the selected operator family:
 *
 *     AND = minimum
 *     OR  = maximum
 *
 * The same rule base is evaluated with standard, algebraic,
 * and bounded operator families.
 * ========================================================== */

static void build_process_rules(
    fuzzy_rules_t *rules,
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    fuzzy_logic_method_t method
)
{
    RULE(
        *rules,
        "Rule 1: Minimal response",
        fuzzy_and_method(
            method,
            temperature_low(temperature),
            humidity_medium(humidity),
            vibration_low(vibration),
            pressure_normal(pressure),
            quality_good(quality)
        ),
        response_minimal
    );

    RULE(
        *rules,
        "Rule 2: Low response",
        fuzzy_and_method(
            method,
            temperature_medium(temperature),
            pressure_normal(pressure),
            quality_average(quality)
        ),
        response_low
    );

    RULE(
        *rules,
        "Rule 3: Moderate response",
        fuzzy_or_method(
            method,
            humidity_high(humidity),
            vibration_medium(vibration),
            quality_poor(quality)
        ),
        response_moderate
    );

    RULE(
        *rules,
        "Rule 4: High thermal-vibration response",
        fuzzy_and_method(
            method,
            temperature_high(temperature),
            vibration_high(vibration)
        ),
        response_high
    );

    RULE(
        *rules,
        "Rule 5: High machine response",
        fuzzy_or_method(
            method,
            pressure_high(pressure),
            vibration_high(vibration),
            temperature_high(temperature)
        ),
        response_high
    );

    RULE(
        *rules,
        "Rule 6: Critical heat-pressure response",
        fuzzy_and_method(
            method,
            powf(
                temperature_high(temperature),
                hedges.very
            ),
            pressure_high(pressure)
        ),
        response_critical
    );

    RULE(
        *rules,
        "Rule 7: Critical vibration-quality response",
        fuzzy_or_method(
            method,
            powf(
                vibration_high(vibration),
                hedges.extremely
            ),
            powf(
                quality_poor(quality),
                hedges.very
            )
        ),
        response_critical
    );

    RULE(
        *rules,
        "Rule 8: High compound response",
        fuzzy_or_method(
            method,

            fuzzy_and_method(
                method,
                temperature_medium(temperature),
                powf(
                    humidity_high(humidity),
                    hedges.somewhat
                )
            ),

            fuzzy_and_method(
                method,
                pressure_high(pressure),
                quality_poor(quality)
            )
        ),
        response_high
    );

    RULE(
        *rules,
        "Rule 9: Low stable-process response",
        fuzzy_and_method(
            method,

            fuzzy_or_method(
                method,
                temperature_low(temperature),
                humidity_low(humidity)
            ),

            fuzzy_or_method(
                method,
                vibration_low(vibration),
                pressure_normal(pressure)
            ),

            quality_good(quality)
        ),
        response_low
    );

    RULE(
        *rules,
        "Rule 10: Critical combined response",
        fuzzy_and_method(
            method,
            temperature_high(temperature),
            humidity_high(humidity),
            vibration_high(vibration),
            pressure_high(pressure),
            quality_poor(quality)
        ),
        response_critical
    );

    RULE(
        *rules,
        random_not_rule_name(),
        evaluate_random_not_rule(
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            method
        ),
        random_not_output()
    );
}

 /* ==========================================================
 * Pure process-response evaluation
 *
 * Safe for repeated sweep evaluations.
 * ========================================================== */

static float evaluate_process_response_method(
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    float defuzz_step,
    fuzzy_logic_method_t logic_method,
    fuzzy_implication_method_t implication_method,
    fuzzy_aggregation_method_t aggregation_method,
    fuzzy_defuzz_method_t defuzz_method
)
{
    fuzzy_rules_t rules;

    rules.count = 0;

    build_process_rules(
        &rules,
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        logic_method
    );

    return fuzzy_rules_defuzzify_method(
        &rules,
        RESPONSE_LOWER,
        RESPONSE_UPPER,
        defuzz_step,
        defuzz_method,
        implication_method,
        aggregation_method
    );
}

static float evaluate_process_response(float temperature, float humidity, float vibration, float pressure, float quality, float cog_step, fuzzy_logic_method_t method)
{
    fuzzy_rules_t rules;
    rules.count = 0;

    build_process_rules(&rules, temperature, humidity, vibration, pressure, quality, method);

    float result = fuzzy_rules_defuzzify(&rules, RESPONSE_LOWER, RESPONSE_UPPER, cog_step, FUZZY_DEFUZZ_COG);
    
    return result;
}

/* ==========================================================
 * Plot one selected process-response COG
 * ========================================================== */

/* ==========================================================
 * Plot the selected process response using every supported
 * Mamdani defuzzification method.
 *
 * The same aggregated Mamdani output is used for:
 *
 * - COG
 * - MOM
 * - SOM
 * - LOM
 *
 * Each result is passed separately to the existing
 * fuzzy_rules_plot_cog() plotting function.
 * ========================================================== */

static bool plot_selected_process_cog(
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    float defuzz_step
)
{
    const fuzzy_logic_method_t logic_methods[] = {
        FUZZY_LOGIC_STANDARD,
        FUZZY_LOGIC_ALGEBRAIC,
        FUZZY_LOGIC_BOUNDED
    };

    const char *logic_names[] = {
        "Standard Zadeh",
        "Algebraic",
        "Bounded Lukasiewicz"
    };

    const char *logic_paths[] = {
        "standard",
        "algebraic",
        "bounded"
    };

    const fuzzy_defuzz_method_t defuzz_methods[] = {
        FUZZY_DEFUZZ_COG,
        FUZZY_DEFUZZ_BOA,
        FUZZY_DEFUZZ_COS,
        FUZZY_DEFUZZ_MOM,
        FUZZY_DEFUZZ_SOM,
        FUZZY_DEFUZZ_LOM
    };

    const char *defuzz_names[] = {
        "COG",
        "BOA",
        "COS",
        "MOM",
        "SOM",
        "LOM"
    };

    const char *defuzz_paths[] = {
        "cog",
        "boa",
        "cos",
        "mom",
        "som",
        "lom"
    };

    const size_t logic_count =
        sizeof(logic_methods) /
        sizeof(logic_methods[0]);

    const size_t defuzz_count =
        sizeof(defuzz_methods) /
        sizeof(defuzz_methods[0]);

    size_t logic_index;
    size_t defuzz_index;

    for (
        logic_index = 0u;
        logic_index < logic_count;
        logic_index++
    ) {
        fuzzy_rules_t rules;

        char filename[256];
        char title[256];

        rules.count = 0;

        build_process_rules(
            &rules,
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            logic_methods[logic_index]
        );

        printf(
            "\n%s controller rule activations\n"
            "========================================\n",
            logic_names[logic_index]
        );

        fuzzy_rules_print(&rules);

        printf(
            "\n%s controller defuzzification results\n"
            "========================================\n",
            logic_names[logic_index]
        );

        for (
            defuzz_index = 0u;
            defuzz_index < defuzz_count;
            defuzz_index++
        ) {
            float result = fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                defuzz_methods[defuzz_index]
            );

            printf(
                "%s: %.5f\n",
                defuzz_names[defuzz_index],
                result
            );

            snprintf(
                filename,
                sizeof(filename),
                DEMO_DIRECTORY "/selected_%s_%s",
                logic_paths[logic_index],
                defuzz_paths[defuzz_index]
            );

            snprintf(
                title,
                sizeof(title),
                "%s Controller - %s",
                logic_names[logic_index],
                defuzz_names[defuzz_index]
            );

            if (!fuzzy_rules_plot_cog(
                &rules,
                filename,
                title,
                result,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            )) {
                fprintf(
                    stderr,
                    "Failed to plot %s controller %s result.\n",
                    logic_names[logic_index],
                    defuzz_names[defuzz_index]
                );

                return false;
            }
        }
    }

    return true;
}

 /* ==========================================================
 * T-norm and T-conorm curve demonstrations
 *
 * The first operand varies from 0 to 1.
 * The second operand remains fixed at 0.5.
 *
 * This produces direct comparisons of:
 *
 * T-norms:
 *     - Standard minimum
 *     - Algebraic product
 *     - Bounded difference
 *
 * T-conorms:
 *     - Standard maximum
 *     - Algebraic probabilistic sum
 *     - Bounded sum
 * ========================================================== */

OPERATOR(operator_and_standard, fuzzy_and_method, FUZZY_LOGIC_STANDARD)
OPERATOR(operator_and_algebraic, fuzzy_and_method, FUZZY_LOGIC_ALGEBRAIC)
OPERATOR(operator_and_bounded, fuzzy_and_method, FUZZY_LOGIC_BOUNDED)

OPERATOR(operator_or_standard, fuzzy_or_method, FUZZY_LOGIC_STANDARD)
OPERATOR(operator_or_algebraic, fuzzy_or_method, FUZZY_LOGIC_ALGEBRAIC)
OPERATOR(operator_or_bounded, fuzzy_or_method, FUZZY_LOGIC_BOUNDED)

static void plot_all_membership_functions(void)
{
    PLOT(DEMO_DIRECTORY "/t_norms", "T-Norm Comparison: Second Operand = 0.5", 1.0f, 0.01f,
        SERIES(operator_and_standard, "#2563eb"),
        SERIES(operator_and_algebraic, "#16a34a"),
        SERIES(operator_and_bounded, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/t_conorms", "T-Conorm Comparison: Second Operand = 0.5", 1.0f, 0.01f,
        SERIES(operator_or_standard, "#2563eb"),
        SERIES(operator_or_algebraic, "#16a34a"),
        SERIES(operator_or_bounded, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/all_shapes", "All Supported Membership Shapes", 100.0f, 0.5f,
        SERIES(shape_ramp_demo, "#ef4444"),
        SERIES(shape_triangle_demo, "#f97316"),
        SERIES(shape_trapezoid_demo, "#eab308"),
        SERIES(shape_smf_demo, "#22c55e"),
        SERIES(shape_zmf_demo, "#3b82f6"),    
        SERIES(shape_gauss_demo, "#8b5cf6"));

    PLOT(DEMO_DIRECTORY "/all_shapes_extended", "All Supported Membership Shapes Extended", 100.0f, 0.5f,
        SERIES(shape_gauss2_demo, "#6366f1"),
        SERIES(shape_bell_demo, "#ec4899"),
        SERIES(shape_sigmoid_demo, "#06b6d4"),
        SERIES(shape_dsigmoid_demo, "#84cc16"),
        SERIES(shape_psigmoid_demo, "#f43f5e"),
        SERIES(shape_pimf_demo, "#14b8a6"));



    PLOT(DEMO_DIRECTORY "/all_hedges", "All Linguistic Hedge Exponents", 100.0f, 0.5f,
        SERIES(hedge_none_demo, "#111827"),
        SERIES(hedge_very_demo, "#ef4444"),
        SERIES(hedge_extremely_demo, "#a855f7"),
        SERIES(hedge_somewhat_demo, "#22c55e"),
        SERIES(hedge_slightly_demo, "#3b82f6"));

    PLOT(DEMO_DIRECTORY "/temperature", "Temperature Membership Functions", 100.0f, 0.5f,
        SERIES(temperature_low, "#3b82f6"),
        SERIES(temperature_medium, "#22c55e"),
        SERIES(temperature_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/humidity", "Humidity Membership Functions", 100.0f, 0.5f,
        SERIES(humidity_low, "#3b82f6"),
        SERIES(humidity_medium, "#22c55e"),
        SERIES(humidity_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/vibration", "Vibration Membership Functions", 10.0f, 0.05f,
        SERIES(vibration_low, "#3b82f6"),
        SERIES(vibration_medium, "#22c55e"),
        SERIES(vibration_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/pressure", "Pressure Membership Functions", 200.0f, 1.0f,
        SERIES(pressure_low, "#3b82f6"),
        SERIES(pressure_normal, "#22c55e"),
        SERIES(pressure_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/quality", "Material-Quality Membership Functions", 100.0f, 0.5f,
        SERIES(quality_poor, "#ef4444"),
        SERIES(quality_average, "#eab308"),
        SERIES(quality_good, "#22c55e"));

    PLOT(DEMO_DIRECTORY "/response", "Process-Response Membership Functions", 100.0f, 0.5f,
        SERIES(response_minimal, "#3b82f6"),
        SERIES(response_low, "#06b6d4"),
        SERIES(response_moderate, "#22c55e"),
        SERIES(response_high, "#f97316"),
        SERIES(response_critical, "#ef4444"));
}

/* ==========================================================
 * Five-dimensional sampled-membership sweep
 *
 * Temperature and humidity form the heatmap.
 *
 * Vibration, pressure, and material quality use the
 * existing interactive SVG slider dimensions.
 * ========================================================== */

static bool plot_sampled_membership_sweep(void)
{
    bool sweep_success;
    bool slices_success;

    sweep_success = FUZZY_GPU_INTERPOLATION_SWEEP(
        DEMO_DIRECTORY "/sampled_interpolation_gpu",
        "Five-Dimensional GPU Sampled Membership Interpolation",
        sampled_membership_points,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 10.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 5.0f)
    );

    slices_success = FUZZY_INTERPOLATION_SLICES(
        DEMO_DIRECTORY "/sampled_membership_slice",
        "Sampled Membership",
        sampled_membership_points,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.05f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 1.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 0.5f)
    );

    return sweep_success && slices_success;
}




static float evaluate_process_sweep(const float inputs[], size_t input_count, float cog_step)
{
    (void)input_count;
    return evaluate_process_response(
        inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
        cog_step, FUZZY_LOGIC_STANDARD
    );
}

/* ==========================================================
 * Five-dimensional COG sweep
 * ========================================================== */

static bool plot_process_sweep(void)
{
    /*
     * High-resolution five-dimensional stress demonstration.
     *
     * Sample counts:
     *
     * Temperature:
     *     0 to 100, step 20
     *     6 samples
     *
     * Humidity:
     *     0 to 100, step 20
     *     6 samples
     *
     * Vibration:
     *     0 to 10, step 0.5
     *     21 samples
     *
     * Pressure:
     *     0 to 200, step 10
     *     21 samples
     *
     * Material quality:
     *     0 to 100, step 5
     *     21 samples
     *
     * Total sweep points:
     *
     *     6 x 6 x 21 x 21 x 21
     *     = 333,396 COG evaluations
     *
     * SVG structure:
     *
     *     X axis  = Temperature
     *     Y axis  = Humidity
     *     Colour  = Defuzzified process-response COG
     *
     * Interactive slider dimensions:
     *
     *     Vibration:
     *         0.0, 0.5, 1.0, ..., 10.0f
     *
     *     Pressure:
     *         0, 10, 20, ..., 200
     *
     *     Material quality:
     *         0, 5, 10, ..., 100
     *
     * The public API call remains unchanged regardless of
     * dimensionality. fuzzy.h handles:
     *
     *     - N-dimensional Cartesian iteration
     *     - COG evaluation
     *     - CSV generation
     *     - A randomly selected but deterministic fuzzy-NOT rule
     *     - SVG generation
     *     - Interactive SVG slice selection
     *     - Internal allocation and cleanup
     */

    FUZZY_COG_SWEEP(
        DEMO_DIRECTORY "/process_sweep",
        "High-Resolution Five-Dimensional Process Sweep",
        evaluate_process_sweep,
        SWEEP_COG_STEP,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 10.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 5.0f));

    return true;
}



/* ==========================================================
 * Five-dimensional OpenCL GPU COG sweep
 *
 * This runs alongside the unchanged CPU demonstration and
 * uses the same randomized membership parameters.
 * ========================================================== */

static bool plot_process_gpu_sweep(void)
{
    return FUZZY_GPU_SWEEP(
        DEMO_DIRECTORY "/process_gpu_sweep",
        "High-Resolution Five-Dimensional GPU Process Sweep",
        "COG",
        process_gpu,
        SWEEP_COG_STEP,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 10.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 5.0f)
    );
}

/* ==========================================================
 * Random-input demonstration
 * ========================================================== */

static bool run_random_demonstration(void)
{
    float temperature;
    float humidity;
    float vibration;
    float pressure;
    float quality;

    float standard_cog;
    float algebraic_cog;
    float bounded_cog;

    float min_max_cog;
    float product_max_cog;
    float min_algebraic_cog;
    float product_algebraic_cog;
    float min_bounded_cog;
    float product_bounded_cog;

    float standard_boa;
    float standard_cos;
    float standard_mom;
    float standard_som;
    float standard_lom;

    float interpolated_membership;

    temperature =
        random_float(
            0.0f,
            100.0f
        );

    humidity =
        random_float(
            0.0f,
            100.0f
        );

    vibration =
        random_float(
            0.0f,
            10.0f
        );

    pressure =
        random_float(
            0.0f,
            200.0f
        );

    quality =
        random_float(
            0.0f,
            100.0f
        );

    printf(
        "\nRandom crisp inputs\n"
        "===================\n"
        "Temperature:      %8.3f\n"
        "Humidity:         %8.3f\n"
        "Vibration:        %8.3f\n"
        "Pressure:         %8.3f\n"
        "Material quality: %8.3f\n",
        temperature,
        humidity,
        vibration,
        pressure,
        quality
    );

    fuzzy_point_t sampled_inputs = FUZZY_INPUTS(temperature, humidity, vibration, pressure, quality);

    interpolated_membership = fuzzy_interpolate_membership_array(
        sampled_inputs.coordinates,
        sampled_inputs.dimension_count,
        sampled_membership_points,
        sizeof(sampled_membership_points) / sizeof(sampled_membership_points[0])
    );

    printf("\nFive-dimensional sampled-membership interpolation\n"
           "=================================================\n"
           "Temperature:             %.5f\n"
           "Humidity:                %.5f\n"
           "Vibration:               %.5f\n"
           "Pressure:                %.5f\n"
           "Material quality:        %.5f\n"
           "Interpolated membership: %.5f\n",
           temperature,
           humidity,
           vibration,
           pressure,
           quality,
           interpolated_membership);

    /*
     * Evaluate the same controller three times.
     *
     * The crisp inputs, membership functions, rule
     * definitions and consequents remain identical.
     *
     * Only the T-norm and T-conorm family changes.
     */
    standard_cog = evaluate_process_response(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD);
    algebraic_cog = evaluate_process_response(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_ALGEBRAIC);
    bounded_cog = evaluate_process_response(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_BOUNDED);

    standard_boa = evaluate_process_response_method(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP,
        FUZZY_LOGIC_STANDARD,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX,
        FUZZY_DEFUZZ_BOA
    );

    standard_cos = evaluate_process_response_method(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP,
        FUZZY_LOGIC_STANDARD,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX,
        FUZZY_DEFUZZ_COS
    );

    standard_mom = evaluate_process_response_method(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP,
        FUZZY_LOGIC_STANDARD,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX,
        FUZZY_DEFUZZ_MOM
    );

    standard_som = evaluate_process_response_method(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP,
        FUZZY_LOGIC_STANDARD,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX,
        FUZZY_DEFUZZ_SOM
    );

    standard_lom = evaluate_process_response_method(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP,
        FUZZY_LOGIC_STANDARD,
        FUZZY_IMPLICATION_MIN,
        FUZZY_AGGREGATION_MAX,
        FUZZY_DEFUZZ_LOM
    );

    printf(
        "\nOperator-family COG comparison\n"
        "==============================\n"
        "Standard Zadeh:      %.5f\n"
        "Algebraic:           %.5f\n"
        "Bounded Lukasiewicz: %.5f\n",
        standard_cog,
        algebraic_cog,
        bounded_cog
    );

    printf(
        "\nStandard-controller defuzzification comparison\n"
        "=============================================\n"
        "COG: %.5f\n"
        "BOA: %.5f\n"
        "COS: %.5f\n"
        "MOM: %.5f\n"
        "SOM: %.5f\n"
        "LOM: %.5f\n",
        standard_cog,
        standard_boa,
        standard_cos,
        standard_mom,
        standard_som,
        standard_lom
    );

    min_max_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_MIN, FUZZY_AGGREGATION_MAX, FUZZY_DEFUZZ_COG);
    product_max_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_PRODUCT, FUZZY_AGGREGATION_MAX, FUZZY_DEFUZZ_COG);
    min_algebraic_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_MIN, FUZZY_AGGREGATION_ALGEBRAIC, FUZZY_DEFUZZ_COG);
    product_algebraic_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_PRODUCT, FUZZY_AGGREGATION_ALGEBRAIC, FUZZY_DEFUZZ_COG);
    min_bounded_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_MIN, FUZZY_AGGREGATION_BOUNDED, FUZZY_DEFUZZ_COG);
    product_bounded_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_PRODUCT, FUZZY_AGGREGATION_BOUNDED, FUZZY_DEFUZZ_COG);

    printf(
        "\nImplication and aggregation comparison\n"
        "======================================\n"
        "MIN implication + MAX aggregation:               %.5f\n"
        "PRODUCT implication + MAX aggregation:           %.5f\n"
        "MIN implication + ALGEBRAIC aggregation:         %.5f\n"
        "PRODUCT implication + ALGEBRAIC aggregation:     %.5f\n"
        "MIN implication + BOUNDED aggregation:           %.5f\n"
        "PRODUCT implication + BOUNDED aggregation:       %.5f\n",
        min_max_cog,
        product_max_cog,
        min_algebraic_cog,
        product_algebraic_cog,
        min_bounded_cog,
        product_bounded_cog
    );

    if (!plot_selected_process_cog(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP
    )) {
        fprintf(stderr, 
            "Failed to generate selected operator-family "
            "defuzzification plots.\n"
        );

        return false;
    }

    return true;
}

/* ==========================================================
 * Print the randomly selected NOT rule
 * ========================================================== */

static void print_random_not_rule(void)
{
    printf(
        "\nRandomized fuzzy-NOT rule\n"
        "=========================\n"
    );

    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            printf(
                "IF temperature is NOT high\n"
                "AND pressure is normal\n"
                "THEN response is low.\n"
            );
            break;

        case RANDOM_NOT_HUMIDITY_LOW:
            printf(
                "IF humidity is NOT low\n"
                "AND vibration is medium\n"
                "THEN response is moderate.\n"
            );
            break;

        case RANDOM_NOT_VIBRATION_LOW:
            printf(
                "IF vibration is NOT low\n"
                "AND pressure is high\n"
                "THEN response is high.\n"
            );
            break;

        case RANDOM_NOT_PRESSURE_HIGH:
            printf(
                "IF pressure is NOT high\n"
                "AND material quality is good\n"
                "THEN response is minimal.\n"
            );
            break;

        case RANDOM_NOT_QUALITY_GOOD:
            printf(
                "IF material quality is NOT good\n"
                "OR temperature is high\n"
                "THEN response is high.\n"
            );
            break;

        default:
            printf(
                "No valid fuzzy-NOT rule selected.\n"
            );
            break;
    }
}


/* ==========================================================
 * Program entry point
 * ========================================================== */
int main(void)
{
    srand((unsigned int)time(NULL));

    for (size_t index = 0u; index < sizeof(sampled_membership_points) / sizeof(sampled_membership_points[0]); index++) {
        sampled_membership_coordinates[index][0] = random_float(0.0f, 100.0f);
        sampled_membership_coordinates[index][1] = random_float(0.0f, 100.0f);
        sampled_membership_coordinates[index][2] = random_float(0.0f, 10.0f);
        sampled_membership_coordinates[index][3] = random_float(0.0f, 200.0f);
        sampled_membership_coordinates[index][4] = random_float(0.0f, 100.0f);

        sampled_membership_points[index].coordinates = sampled_membership_coordinates[index];
        sampled_membership_points[index].dimension_count = 5u;
        sampled_membership_points[index].membership = random_float(0.0f, 1.0f);
    }
    randomize_membership_parameters();
    initialize_process_gpu_controller();

    printf("\nfuzzy.h Complete API Demonstration\n");
    printf("==================================\n");

    print_process_gpu_hedges();
    print_random_not_rule();
    plot_all_membership_functions();
    plot_sampled_membership_sweep();

    if (!plot_process_gpu_sweep()) {
        fprintf(stderr, "GPU process sweep failed.\n");
        return 1;
    }

    run_random_demonstration();

    printf("\nComplete fuzzy.h demonstration finished.\n");
    return 0;
}