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
 * - Gaussian membership functions
 * - Generalized bell membership functions
 * - Sigmoid membership functions
 * - Linguistic hedges
 * - Fuzzy AND
 * - Fuzzy OR
 * - Nested fuzzy expressions
 * - Mamdani rule aggregation
 * - COG defuzzification
 * - Membership-function SVG plots
 * - Selected COG SVG plot
 * - Five-dimensional COG sweep CSV
 * - Interactive five-dimensional sweep SVG
 * - Random crisp input generation
 */

#include <time.h>

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"


/* ==========================================================
 * Output paths and numerical ranges
 * ========================================================== */

#define DEMO_DIRECTORY              "demo-all"

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
    float shape_gauss[2];
    float shape_bell[3];
    float shape_sigmoid[2];

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

/* ==========================================================
 * Random-number helper
 * ========================================================== */

static float random_float(
    float lower,
    float upper
)
{
    if (lower >= upper) {
        return lower;
    }

    float ratio =
        (float)rand() /
        (float)RAND_MAX;

    return lower +
        ratio * (upper - lower);
}

/*
 * Generate two strictly ordered parameters:
 *
 * a < b
 */
static void random_ordered_2(
    float output[2],
    float lower,
    float upper,
    float minimum_gap
)
{
    if (
        output == NULL ||
        upper - lower < minimum_gap
    ) {
        return;
    }

    output[0] = random_float(
        lower,
        upper - minimum_gap
    );

    output[1] = random_float(
        output[0] + minimum_gap,
        upper
    );
}


/*
 * Generate three strictly ordered parameters:
 *
 * a < b < c
 */
static void random_ordered_3(
    float output[3],
    float lower,
    float upper,
    float minimum_gap
)
{
    if (
        output == NULL ||
        upper - lower < 2.0f * minimum_gap
    ) {
        return;
    }

    output[0] = random_float(
        lower,
        upper - 2.0f * minimum_gap
    );

    output[1] = random_float(
        output[0] + minimum_gap,
        upper - minimum_gap
    );

    output[2] = random_float(
        output[1] + minimum_gap,
        upper
    );
}


/*
 * Generate four strictly ordered parameters:
 *
 * a < b < c < d
 */
static void random_ordered_4(
    float output[4],
    float lower,
    float upper,
    float minimum_gap
)
{
    if (
        output == NULL ||
        upper - lower < 3.0f * minimum_gap
    ) {
        return;
    }

    output[0] = random_float(
        lower,
        upper - 3.0f * minimum_gap
    );

    output[1] = random_float(
        output[0] + minimum_gap,
        upper - 2.0f * minimum_gap
    );

    output[2] = random_float(
        output[1] + minimum_gap,
        upper - minimum_gap
    );

    output[3] = random_float(
        output[2] + minimum_gap,
        upper
    );
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
    /*
     * Temperature: 0 to 100.
     */
    random_ordered_2(
        parameters.temperature_low,
        10.0f,
        48.0f,
        8.0f
    );

    parameters.temperature_medium[0] =
        random_float(38.0f, 62.0f);

    parameters.temperature_medium[1] =
        random_float(8.0f, 20.0f);

    random_ordered_2(
        parameters.temperature_high,
        52.0f,
        95.0f,
        8.0f
    );

    /*
     * Humidity: 0 to 100.
     */
    random_ordered_2(
        parameters.humidity_low,
        10.0f,
        48.0f,
        8.0f
    );

    random_ordered_4(
        parameters.humidity_medium,
        18.0f,
        82.0f,
        8.0f
    );

    random_not_rule =
        (random_not_rule_t)(
            rand() %
            (int)RANDOM_NOT_RULE_COUNT
        );

    parameters.humidity_high[0] =
        random_float(0.07f, 0.20f);

    parameters.humidity_high[1] =
        random_float(55.0f, 78.0f);

    /*
     * Vibration: 0 to 10.
     */
    random_ordered_2(
        parameters.vibration_low,
        0.5f,
        4.8f,
        1.0f
    );

    parameters.vibration_medium[0] =
        random_float(3.0f, 6.5f);

    parameters.vibration_medium[1] =
        random_float(1.5f, 4.0f);

    parameters.vibration_medium[2] =
        random_float(3.5f, 6.5f);

    random_ordered_2(
        parameters.vibration_high,
        5.0f,
        9.8f,
        1.0f
    );

    /*
     * Pressure: 0 to 200.
     */
    random_ordered_2(
        parameters.pressure_low,
        20.0f,
        95.0f,
        20.0f
    );

    random_ordered_3(
        parameters.pressure_normal,
        45.0f,
        175.0f,
        25.0f
    );

    parameters.pressure_high[0] =
        random_float(0.035f, 0.095f);

    parameters.pressure_high[1] =
        random_float(125.0f, 170.0f);

    /*
     * Material quality: 0 to 100.
     */
    random_ordered_2(
        parameters.quality_poor,
        10.0f,
        52.0f,
        10.0f
    );

    parameters.quality_average[0] =
        random_float(42.0f, 65.0f);

    parameters.quality_average[1] =
        random_float(8.0f, 20.0f);

    random_ordered_2(
        parameters.quality_good,
        50.0f,
        96.0f,
        10.0f
    );

    /*
     * Process response: 0 to 100.
     */
    random_ordered_2(
        parameters.response_minimal,
        5.0f,
        35.0f,
        8.0f
    );

    random_ordered_3(
        parameters.response_low,
        5.0f,
        55.0f,
        10.0f
    );

    random_ordered_4(
        parameters.response_moderate,
        22.0f,
        76.0f,
        8.0f
    );

    random_ordered_3(
        parameters.response_high,
        48.0f,
        95.0f,
        8.0f
    );

    random_ordered_2(
        parameters.response_critical,
        68.0f,
        99.0f,
        7.0f
    );

    /*
     * Generic shape demonstration: 0 to 100.
     */
    random_ordered_2(
        parameters.shape_ramp,
        10.0f,
        90.0f,
        20.0f
    );

    random_ordered_3(
        parameters.shape_triangle,
        5.0f,
        95.0f,
        15.0f
    );

    random_ordered_4(
        parameters.shape_trapezoid,
        5.0f,
        95.0f,
        12.0f
    );

    random_ordered_2(
        parameters.shape_smf,
        10.0f,
        90.0f,
        20.0f
    );

    random_ordered_2(
        parameters.shape_zmf,
        10.0f,
        90.0f,
        20.0f
    );

    parameters.shape_gauss[0] =
        random_float(30.0f, 70.0f);

    parameters.shape_gauss[1] =
        random_float(8.0f, 22.0f);

    parameters.shape_bell[0] =
        random_float(20.0f, 55.0f);

    parameters.shape_bell[1] =
        random_float(1.5f, 4.0f);

    parameters.shape_bell[2] =
        random_float(30.0f, 70.0f);

    parameters.shape_sigmoid[0] =
        random_float(0.06f, 0.20f);

    parameters.shape_sigmoid[1] =
        random_float(30.0f, 70.0f);

    /*
     * Shared hedge demonstration trapezoid.
     */
    random_ordered_4(
        parameters.hedge_trapezoid,
        5.0f,
        95.0f,
        12.0f
    );
}


/* ==========================================================
 * Randomized temperature membership functions
 * ========================================================== */

static float temperature_low(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        (double)parameters.temperature_low[0],
        (double)parameters.temperature_low[1]
    );
}


static float temperature_medium(float value)
{
    return fuzzy_function(
        "gauss",
        value,
        hedges.none,
        (double)parameters.temperature_medium[0],
        (double)parameters.temperature_medium[1]
    );
}


static float temperature_high(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        (double)parameters.temperature_high[0],
        (double)parameters.temperature_high[1]
    );
}


/* ==========================================================
 * Randomized humidity membership functions
 * ========================================================== */

static float humidity_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        (double)parameters.humidity_low[0],
        (double)parameters.humidity_low[1],
        false
    );
}


static float humidity_medium(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        (double)parameters.humidity_medium[0],
        (double)parameters.humidity_medium[1],
        (double)parameters.humidity_medium[2],
        (double)parameters.humidity_medium[3]
    );
}


static float humidity_high(float value)
{
    return fuzzy_function(
        "sigmoid",
        value,
        hedges.none,
        (double)parameters.humidity_high[0],
        (double)parameters.humidity_high[1]
    );
}


/* ==========================================================
 * Randomized vibration membership functions
 * ========================================================== */

static float vibration_low(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        (double)parameters.vibration_low[0],
        (double)parameters.vibration_low[1]
    );
}


static float vibration_medium(float value)
{
    return fuzzy_function(
        "bell",
        value,
        hedges.none,
        (double)parameters.vibration_medium[0],
        (double)parameters.vibration_medium[1],
        (double)parameters.vibration_medium[2]
    );
}


static float vibration_high(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        (double)parameters.vibration_high[0],
        (double)parameters.vibration_high[1]
    );
}


/* ==========================================================
 * Randomized pressure membership functions
 * ========================================================== */

static float pressure_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        (double)parameters.pressure_low[0],
        (double)parameters.pressure_low[1],
        false
    );
}


static float pressure_normal(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        (double)parameters.pressure_normal[0],
        (double)parameters.pressure_normal[1],
        (double)parameters.pressure_normal[2]
    );
}


static float pressure_high(float value)
{
    return fuzzy_function(
        "sigmoid",
        value,
        hedges.none,
        (double)parameters.pressure_high[0],
        (double)parameters.pressure_high[1]
    );
}


/* ==========================================================
 * Randomized quality membership functions
 * ========================================================== */

static float quality_poor(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        (double)parameters.quality_poor[0],
        (double)parameters.quality_poor[1]
    );
}


static float quality_average(float value)
{
    return fuzzy_function(
        "gauss",
        value,
        hedges.none,
        (double)parameters.quality_average[0],
        (double)parameters.quality_average[1]
    );
}


static float quality_good(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        (double)parameters.quality_good[0],
        (double)parameters.quality_good[1]
    );
}


/* ==========================================================
 * Randomized response membership functions
 * ========================================================== */

static float response_minimal(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        (double)parameters.response_minimal[0],
        (double)parameters.response_minimal[1]
    );
}


static float response_low(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        (double)parameters.response_low[0],
        (double)parameters.response_low[1],
        (double)parameters.response_low[2]
    );
}


static float response_moderate(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        (double)parameters.response_moderate[0],
        (double)parameters.response_moderate[1],
        (double)parameters.response_moderate[2],
        (double)parameters.response_moderate[3]
    );
}


static float response_high(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        (double)parameters.response_high[0],
        (double)parameters.response_high[1],
        (double)parameters.response_high[2]
    );
}


static float response_critical(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        (double)parameters.response_critical[0],
        (double)parameters.response_critical[1]
    );
}


/* ==========================================================
 * Randomized hedge demonstration
 * ========================================================== */

static float hedge_none_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        (double)parameters.hedge_trapezoid[0],
        (double)parameters.hedge_trapezoid[1],
        (double)parameters.hedge_trapezoid[2],
        (double)parameters.hedge_trapezoid[3]
    );
}


static float hedge_very_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.very,
        (double)parameters.hedge_trapezoid[0],
        (double)parameters.hedge_trapezoid[1],
        (double)parameters.hedge_trapezoid[2],
        (double)parameters.hedge_trapezoid[3]
    );
}


static float hedge_extremely_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.extremely,
        (double)parameters.hedge_trapezoid[0],
        (double)parameters.hedge_trapezoid[1],
        (double)parameters.hedge_trapezoid[2],
        (double)parameters.hedge_trapezoid[3]
    );
}


static float hedge_somewhat_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.somewhat,
        (double)parameters.hedge_trapezoid[0],
        (double)parameters.hedge_trapezoid[1],
        (double)parameters.hedge_trapezoid[2],
        (double)parameters.hedge_trapezoid[3]
    );
}


static float hedge_slightly_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.slightly,
        (double)parameters.hedge_trapezoid[0],
        (double)parameters.hedge_trapezoid[1],
        (double)parameters.hedge_trapezoid[2],
        (double)parameters.hedge_trapezoid[3]
    );
}

/* ==========================================================
 * Individual membership-shape demonstration functions
 *
 * These place every supported shape on one SVG graph.
 * ========================================================== */

static float shape_ramp_demo(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        80.0,
        true
    );
}


static float shape_triangle_demo(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        10.0,
        50.0,
        90.0
    );
}


static float shape_trapezoid_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        10.0,
        30.0,
        70.0,
        90.0
    );
}


static float shape_smf_demo(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        20.0,
        80.0
    );
}


static float shape_zmf_demo(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        20.0,
        80.0
    );
}


static float shape_gauss_demo(float value)
{
    return fuzzy_function(
        "gauss",
        value,
        hedges.none,
        50.0,
        15.0
    );
}


static float shape_bell_demo(float value)
{
    return fuzzy_function(
        "bell",
        value,
        hedges.none,
        40.0,
        2.0,
        50.0
    );
}


static float shape_sigmoid_demo(float value)
{
    return fuzzy_function(
        "sigmoid",
        value,
        hedges.none,
        0.12,
        50.0
    );
}

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

static float evaluate_random_not_rule(
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    fuzzy_logic_method_t method
)
{
    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            return fuzzy_and_method(
                method,
                2,
                fuzzy_not(
                    temperature_high(
                        temperature
                    )
                ),
                pressure_normal(
                    pressure
                )
            );

        case RANDOM_NOT_HUMIDITY_LOW:
            return fuzzy_and_method(
                method,
                2,
                fuzzy_not(
                    humidity_low(
                        humidity
                    )
                ),
                vibration_medium(
                    vibration
                )
            );

        case RANDOM_NOT_VIBRATION_LOW:
            return fuzzy_and_method(
                method,
                2,
                fuzzy_not(
                    vibration_low(
                        vibration
                    )
                ),
                pressure_high(
                    pressure
                )
            );

        case RANDOM_NOT_PRESSURE_HIGH:
            return fuzzy_and_method(
                method,
                2,
                fuzzy_not(
                    pressure_high(
                        pressure
                    )
                ),
                quality_good(
                    quality
                )
            );

        case RANDOM_NOT_QUALITY_GOOD:
            return fuzzy_or_method(
                method,
                2,
                fuzzy_not(
                    quality_good(
                        quality
                    )
                ),
                temperature_high(
                    temperature
                )
            );

        default:
            return LEVEL_LO;
    }
}

static const char *random_not_rule_name(void)
{
    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            return
                "Rule 11: NOT high temperature response";

        case RANDOM_NOT_HUMIDITY_LOW:
            return
                "Rule 11: NOT low humidity response";

        case RANDOM_NOT_VIBRATION_LOW:
            return
                "Rule 11: NOT low vibration response";

        case RANDOM_NOT_PRESSURE_HIGH:
            return
                "Rule 11: NOT high pressure response";

        case RANDOM_NOT_QUALITY_GOOD:
            return
                "Rule 11: NOT good quality response";

        default:
            return
                "Rule 11: Random fuzzy-NOT response";
    }
}

static fuzzy_output_function_t random_not_output(void)
{
    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            return response_low;

        case RANDOM_NOT_HUMIDITY_LOW:
            return response_moderate;

        case RANDOM_NOT_VIBRATION_LOW:
            return response_high;

        case RANDOM_NOT_PRESSURE_HIGH:
            return response_minimal;

        case RANDOM_NOT_QUALITY_GOOD:
            return response_high;

        default:
            return response_moderate;
    }
}

/* ==========================================================
 * Complex Mamdani rule construction
 * ========================================================== */

/* ==========================================================
 * Complex Mamdani rule construction
 *
 * Rules 1 through 11 use the standard Zadeh operators:
 *
 *     AND = minimum
 *     OR  = maximum
 *
 * Rule 12 demonstrates algebraic AND.
 * Rule 13 demonstrates bounded OR.
 * ========================================================== */

static bool build_process_rules(
    fuzzy_rules_t *rules,
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    fuzzy_logic_method_t method
)
{
    float rule1;
    float rule2;
    float rule3;
    float rule4;
    float rule5;
    float rule6;
    float rule7;
    float rule8;
    float rule9;
    float rule10;
    float rule11;

    float very_high_temperature;
    float extremely_high_vibration;
    float very_poor_quality;
    float somewhat_high_humidity;

    float rule8_left;
    float rule8_right;

    float rule9_environment;
    float rule9_machine;

    if (rules == NULL) {
        return false;
    }

    /*
     * Rule 1:
     *
     * IF temperature is low
     * AND humidity is medium
     * AND vibration is low
     * AND pressure is normal
     * AND quality is good
     * THEN response is minimal.
     */
    rule1 =
        fuzzy_and_method(
            method,
            5,
            temperature_low(
                temperature
            ),
            humidity_medium(
                humidity
            ),
            vibration_low(
                vibration
            ),
            pressure_normal(
                pressure
            ),
            quality_good(
                quality
            )
        );

    /*
     * Rule 2:
     *
     * IF temperature is medium
     * AND pressure is normal
     * AND quality is average
     * THEN response is low.
     */
    rule2 =
        fuzzy_and_method(
            method,
            3,
            temperature_medium(
                temperature
            ),
            pressure_normal(
                pressure
            ),
            quality_average(
                quality
            )
        );

    /*
     * Rule 3:
     *
     * IF humidity is high
     * OR vibration is medium
     * OR quality is poor
     * THEN response is moderate.
     */
    rule3 =
        fuzzy_or_method(
            method,
            3,
            humidity_high(
                humidity
            ),
            vibration_medium(
                vibration
            ),
            quality_poor(
                quality
            )
        );

    /*
     * Rule 4:
     *
     * IF temperature is high
     * AND vibration is high
     * THEN response is high.
     */
    rule4 =
        fuzzy_and_method(
            method,
            2,
            temperature_high(
                temperature
            ),
            vibration_high(
                vibration
            )
        );

    /*
     * Rule 5:
     *
     * IF pressure is high
     * OR vibration is high
     * OR temperature is high
     * THEN response is high.
     */
    rule5 =
        fuzzy_or_method(
            method,
            3,
            pressure_high(
                pressure
            ),
            vibration_high(
                vibration
            ),
            temperature_high(
                temperature
            )
        );

    /*
     * Rule 6:
     *
     * IF temperature is very high
     * AND pressure is high
     * THEN response is critical.
     */
    very_high_temperature =
        powf(
            temperature_high(
                temperature
            ),
            hedges.very
        );

    rule6 =
        fuzzy_and_method(
            method,
            2,
            very_high_temperature,
            pressure_high(
                pressure
            )
        );

    /*
     * Rule 7:
     *
     * IF vibration is extremely high
     * OR quality is very poor
     * THEN response is critical.
     */
    extremely_high_vibration =
        powf(
            vibration_high(
                vibration
            ),
            hedges.extremely
        );

    very_poor_quality =
        powf(
            quality_poor(
                quality
            ),
            hedges.very
        );

    rule7 =
        fuzzy_or_method(
            method,
            2,
            extremely_high_vibration,
            very_poor_quality
        );

    /*
     * Rule 8:
     *
     * IF
     *     temperature is medium
     *     AND humidity is somewhat high
     *
     * OR
     *
     *     pressure is high
     *     AND quality is poor
     *
     * THEN response is high.
     *
     * Every nested operator uses the same selected family.
     */
    somewhat_high_humidity =
        powf(
            humidity_high(
                humidity
            ),
            hedges.somewhat
        );

    rule8_left =
        fuzzy_and_method(
            method,
            2,
            temperature_medium(
                temperature
            ),
            somewhat_high_humidity
        );

    rule8_right =
        fuzzy_and_method(
            method,
            2,
            pressure_high(
                pressure
            ),
            quality_poor(
                quality
            )
        );

    rule8 =
        fuzzy_or_method(
            method,
            2,
            rule8_left,
            rule8_right
        );

    /*
     * Rule 9:
     *
     * IF
     *     temperature is low
     *     OR humidity is low
     *
     * AND
     *
     *     vibration is low
     *     OR pressure is normal
     *
     * AND quality is good
     *
     * THEN response is low.
     *
     * Every nested operator uses the same selected family.
     */
    rule9_environment =
        fuzzy_or_method(
            method,
            2,
            temperature_low(
                temperature
            ),
            humidity_low(
                humidity
            )
        );

    rule9_machine =
        fuzzy_or_method(
            method,
            2,
            vibration_low(
                vibration
            ),
            pressure_normal(
                pressure
            )
        );

    rule9 =
        fuzzy_and_method(
            method,
            3,
            rule9_environment,
            rule9_machine,
            quality_good(
                quality
            )
        );

    /*
     * Rule 10:
     *
     * IF temperature is high
     * AND humidity is high
     * AND vibration is high
     * AND pressure is high
     * AND quality is poor
     * THEN response is critical.
     */
    rule10 =
        fuzzy_and_method(
            method,
            5,
            temperature_high(
                temperature
            ),
            humidity_high(
                humidity
            ),
            vibration_high(
                vibration
            ),
            pressure_high(
                pressure
            ),
            quality_poor(
                quality
            )
        );

    /*
     * Rule 11:
     *
     * The selected NOT rule also uses the same AND/OR
     * operator family.
     */
    rule11 =
        evaluate_random_not_rule(
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            method
        );

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 1: Minimal response",
        rule1,
        response_minimal
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 2: Low response",
        rule2,
        response_low
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 3: Moderate response",
        rule3,
        response_moderate
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 4: High thermal-vibration response",
        rule4,
        response_high
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 5: High machine response",
        rule5,
        response_high
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 6: Critical heat-pressure response",
        rule6,
        response_critical
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 7: Critical vibration-quality response",
        rule7,
        response_critical
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 8: High compound response",
        rule8,
        response_high
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 9: Low stable-process response",
        rule9,
        response_low
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Rule 10: Critical combined response",
        rule10,
        response_critical
    )) {
        return false;
    }

    if (!fuzzy_rules_add(
        rules,
        random_not_rule_name(),
        rule11,
        random_not_output()
    )) {
        return false;
    }

    return true;
}

/* ==========================================================
 * Pure process-response evaluation
 *
 * Safe for repeated sweep evaluations.
 * ========================================================== */

static float evaluate_process_response(
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    float cog_step,
    fuzzy_logic_method_t method
)
{
    fuzzy_rules_t rules;
    float result;

    fuzzy_rules_create(
        &rules
    );

    if (!build_process_rules(
        &rules,
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        method
    )) {
        FUZZY_ERROR(
            "Failed to construct process-response rules.\n"
        );

        fuzzy_rules_free(
            &rules
        );

        return 0.0f;
    }

    result =
        fuzzy_rules_defuzzify(
            &rules,
            RESPONSE_LOWER,
            RESPONSE_UPPER,
            cog_step,
            FUZZY_DEFUZZ_COG
        );

    fuzzy_rules_free(
        &rules
    );

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
    const fuzzy_logic_method_t methods[] = {
        FUZZY_LOGIC_STANDARD,
        FUZZY_LOGIC_ALGEBRAIC,
        FUZZY_LOGIC_BOUNDED
    };

    const char *method_names[] = {
        "Standard Zadeh",
        "Algebraic",
        "Bounded Lukasiewicz"
    };

    const char *cog_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_cog",
        DEMO_DIRECTORY "/selected_algebraic_cog",
        DEMO_DIRECTORY "/selected_bounded_cog"
    };

    const char *mom_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_mom",
        DEMO_DIRECTORY "/selected_algebraic_mom",
        DEMO_DIRECTORY "/selected_bounded_mom"
    };

    const char *som_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_som",
        DEMO_DIRECTORY "/selected_algebraic_som",
        DEMO_DIRECTORY "/selected_bounded_som"
    };

    const char *lom_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_lom",
        DEMO_DIRECTORY "/selected_algebraic_lom",
        DEMO_DIRECTORY "/selected_bounded_lom"
    };

    const char *cog_titles[] = {
        "Standard Min-Max Controller - COG",
        "Algebraic Product-Sum Controller - COG",
        "Bounded Lukasiewicz Controller - COG"
    };

    const char *mom_titles[] = {
        "Standard Min-Max Controller - MOM",
        "Algebraic Product-Sum Controller - MOM",
        "Bounded Lukasiewicz Controller - MOM"
    };

    const char *som_titles[] = {
        "Standard Min-Max Controller - SOM",
        "Algebraic Product-Sum Controller - SOM",
        "Bounded Lukasiewicz Controller - SOM"
    };

    const char *lom_titles[] = {
        "Standard Min-Max Controller - LOM",
        "Algebraic Product-Sum Controller - LOM",
        "Bounded Lukasiewicz Controller - LOM"
    };

    const size_t method_count =
        sizeof(methods) /
        sizeof(methods[0]);

    size_t method_index;

    for (
        method_index = 0;
        method_index < method_count;
        method_index++
    ) {
        fuzzy_rules_t rules;

        float cog;
        float mom;
        float som;
        float lom;

        bool cog_success;
        bool mom_success;
        bool som_success;
        bool lom_success;

        fuzzy_rules_create(
            &rules
        );

        /*
         * Rebuild the same complete controller using only
         * the currently selected AND/OR operator family.
         */
        if (!build_process_rules(
            &rules,
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            methods[method_index]
        )) {
            FUZZY_ERROR(
                "Failed to construct %s controller.\n",
                method_names[method_index]
            );

            fuzzy_rules_free(
                &rules
            );

            return false;
        }

        FUZZY_PRINTF(
            "\n%s controller rule activations\n"
            "========================================\n",
            method_names[method_index]
        );

        fuzzy_rules_print(
            &rules
        );

        cog =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_COG
            );

        mom =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_MOM
            );

        som =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_SOM
            );

        lom =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_LOM
            );

        FUZZY_PRINTF(
            "\n%s controller results\n"
            "========================================\n"
            "COG: %.5f\n"
            "MOM: %.5f\n"
            "SOM: %.5f\n"
            "LOM: %.5f\n",
            method_names[method_index],
            cog,
            mom,
            som,
            lom
        );

        cog_success =
            fuzzy_rules_plot_cog(
                &rules,
                cog_filenames[method_index],
                cog_titles[method_index],
                cog,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        mom_success =
            fuzzy_rules_plot_cog(
                &rules,
                mom_filenames[method_index],
                mom_titles[method_index],
                mom,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        som_success =
            fuzzy_rules_plot_cog(
                &rules,
                som_filenames[method_index],
                som_titles[method_index],
                som,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        lom_success =
            fuzzy_rules_plot_cog(
                &rules,
                lom_filenames[method_index],
                lom_titles[method_index],
                lom,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        fuzzy_rules_free(
            &rules
        );

        if (
            !cog_success ||
            !mom_success ||
            !som_success ||
            !lom_success
        ) {
            FUZZY_ERROR(
                "Failed to plot %s controller results.\n",
                method_names[method_index]
            );

            return false;
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

static float operator_and_standard(
    float value
)
{
    return fuzzy_and_method(
        FUZZY_LOGIC_STANDARD,
        2,
        value,
        0.5f
    );
}


static float operator_and_algebraic(
    float value
)
{
    return fuzzy_and_method(
        FUZZY_LOGIC_ALGEBRAIC,
        2,
        value,
        0.5f
    );
}


static float operator_and_bounded(
    float value
)
{
    return fuzzy_and_method(
        FUZZY_LOGIC_BOUNDED,
        2,
        value,
        0.5f
    );
}


static float operator_or_standard(
    float value
)
{
    return fuzzy_or_method(
        FUZZY_LOGIC_STANDARD,
        2,
        value,
        0.5f
    );
}


static float operator_or_algebraic(
    float value
)
{
    return fuzzy_or_method(
        FUZZY_LOGIC_ALGEBRAIC,
        2,
        value,
        0.5f
    );
}


static float operator_or_bounded(
    float value
)
{
    return fuzzy_or_method(
        FUZZY_LOGIC_BOUNDED,
        2,
        value,
        0.5f
    );
}


/* ==========================================================
 * Plot every supported T-norm on one SVG.
 * ========================================================== */

static bool plot_t_norms(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/t_norms",
        "T-Norm Comparison: Second Operand = 0.5",
        0.0f,
        1.0f,
        0.01f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Standard AND: min(a, 0.5)",
            "#2563eb",
            operator_and_standard
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Algebraic AND: a * 0.5",
            "#16a34a",
            operator_and_algebraic
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Bounded AND: max(0, a - 0.5)",
            "#ef4444",
            operator_and_bounded
        )
    );
}


/* ==========================================================
 * Plot every supported T-conorm on one SVG.
 * ========================================================== */

static bool plot_t_conorms(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/t_conorms",
        "T-Conorm Comparison: Second Operand = 0.5",
        0.0f,
        1.0f,
        0.01f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Standard OR: max(a, 0.5)",
            "#2563eb",
            operator_or_standard
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Algebraic OR: a + 0.5 - 0.5a",
            "#16a34a",
            operator_or_algebraic
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Bounded OR: min(1, a + 0.5)",
            "#ef4444",
            operator_or_bounded
        )
    );
}

static bool plot_all_shapes(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/all_shapes",
        "All Supported Membership Shapes",
        0.0f,
        100.0f,
        0.5f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Ramp",
            "#ef4444",
            shape_ramp_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Triangle",
            "#f97316",
            shape_triangle_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Trapezoid",
            "#eab308",
            shape_trapezoid_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "SMF",
            "#22c55e",
            shape_smf_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "ZMF",
            "#3b82f6",
            shape_zmf_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Gaussian",
            "#8b5cf6",
            shape_gauss_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Bell",
            "#ec4899",
            shape_bell_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Sigmoid",
            "#06b6d4",
            shape_sigmoid_demo
        )
    );
}


static bool plot_all_hedges(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/all_hedges",
        "All Linguistic Hedge Exponents",
        0.0f,
        100.0f,
        0.5f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "None",
            "#111827",
            hedge_none_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Very",
            "#ef4444",
            hedge_very_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Extremely",
            "#a855f7",
            hedge_extremely_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Somewhat",
            "#22c55e",
            hedge_somewhat_demo
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Slightly",
            "#3b82f6",
            hedge_slightly_demo
        )
    );
}


static bool plot_temperature_functions(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/temperature",
        "Temperature Membership Functions",
        0.0f,
        100.0f,
        0.5f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#3b82f6",
            temperature_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Medium",
            "#22c55e",
            temperature_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            temperature_high
        )
    );
}


static bool plot_humidity_functions(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/humidity",
        "Humidity Membership Functions",
        0.0f,
        100.0f,
        0.5f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#3b82f6",
            humidity_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Medium",
            "#22c55e",
            humidity_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            humidity_high
        )
    );
}


static bool plot_vibration_functions(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/vibration",
        "Vibration Membership Functions",
        0.0f,
        10.0f,
        0.05f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#3b82f6",
            vibration_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Medium",
            "#22c55e",
            vibration_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            vibration_high
        )
    );
}


static bool plot_pressure_functions(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/pressure",
        "Pressure Membership Functions",
        0.0f,
        200.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#3b82f6",
            pressure_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Normal",
            "#22c55e",
            pressure_normal
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            pressure_high
        )
    );
}


static bool plot_quality_functions(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/quality",
        "Material-Quality Membership Functions",
        0.0f,
        100.0f,
        0.5f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Poor",
            "#ef4444",
            quality_poor
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Average",
            "#eab308",
            quality_average
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Good",
            "#22c55e",
            quality_good
        )
    );
}


static bool plot_response_functions(void)
{
    return FUZZY_PLOT(
        DEMO_DIRECTORY "/response",
        "Process-Response Membership Functions",
        RESPONSE_LOWER,
        RESPONSE_UPPER,
        0.5f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Minimal",
            "#3b82f6",
            response_minimal
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#06b6d4",
            response_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Moderate",
            "#22c55e",
            response_moderate
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#f97316",
            response_high
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Critical",
            "#ef4444",
            response_critical
        )
    );
}

static bool plot_all_membership_functions(void)
{
    if (!plot_all_shapes()) {
        FUZZY_ERROR(
            "Failed to generate all-shapes plot.\n"
        );

        return false;
    }

    if (!plot_all_hedges()) {
        FUZZY_ERROR(
            "Failed to generate hedge plot.\n"
        );

        return false;
    }

    if (!plot_temperature_functions()) {
        FUZZY_ERROR(
            "Failed to generate temperature plot.\n"
        );

        return false;
    }

    if (!plot_humidity_functions()) {
        FUZZY_ERROR(
            "Failed to generate humidity plot.\n"
        );

        return false;
    }

    if (!plot_vibration_functions()) {
        FUZZY_ERROR(
            "Failed to generate vibration plot.\n"
        );

        return false;
    }

    if (!plot_pressure_functions()) {
        FUZZY_ERROR(
            "Failed to generate pressure plot.\n"
        );

        return false;
    }

    if (!plot_quality_functions()) {
        FUZZY_ERROR(
            "Failed to generate quality plot.\n"
        );

        return false;
    }

    if (!plot_response_functions()) {
        FUZZY_ERROR(
            "Failed to generate response plot.\n"
        );

        return false;
    }

    if (!plot_t_norms()) {
        FUZZY_ERROR(
            "Failed to generate T-norm comparison plot.\n"
        );

        return false;
    }

    if (!plot_t_conorms()) {
        FUZZY_ERROR(
            "Failed to generate T-conorm comparison plot.\n"
        );

        return false;
    }

    FUZZY_PRINTF(
        "\nGenerated all membership-function "
        "and fuzzy-operator plots.\n"
    );

    return true;
}

/* ==========================================================
 * Five-dimensional sweep adapter
 *
 * Dimension order:
 *
 * inputs[0] = temperature
 * inputs[1] = humidity
 * inputs[2] = vibration
 * inputs[3] = pressure
 * inputs[4] = material quality
 * ========================================================== */

static float evaluate_process_sweep(
    const float inputs[],
    size_t input_count,
    float cog_step
)
{
    if (
        inputs == NULL ||
        input_count != 5
    ) {
        return 0.0f;
    }

    return evaluate_process_response(
        inputs[0],
        inputs[1],
        inputs[2],
        inputs[3],
        inputs[4],
        cog_step,
        FUZZY_LOGIC_STANDARD
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
     *         0.0, 0.5, 1.0, ..., 10.0
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
     *     - CSV parsing
     *     - A randomly selected but deterministic fuzzy-NOT rule
     *     - SVG generation
     *     - Interactive SVG slice selection
     *     - Internal allocation and cleanup
     */
    return FUZZY_COG_SWEEP(
        DEMO_DIRECTORY "/process_sweep",
        "High-Resolution Five-Dimensional Process Sweep",
        evaluate_process_sweep,
        SWEEP_COG_STEP,

        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            100.0f,
            20.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Humidity",
            0.0f,
            100.0f,
            20.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Vibration",
            0.0f,
            10.0f,
            0.5f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Pressure",
            0.0f,
            200.0f,
            10.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Material quality",
            0.0f,
            100.0f,
            5.0f
        )
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

    FUZZY_PRINTF(
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

    /*
     * Evaluate the same controller three times.
     *
     * The crisp inputs, membership functions, rule
     * definitions and consequents remain identical.
     *
     * Only the T-norm and T-conorm family changes.
     */
    standard_cog =
        evaluate_process_response(
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            NORMAL_COG_STEP,
            FUZZY_LOGIC_STANDARD
        );

    algebraic_cog =
        evaluate_process_response(
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            NORMAL_COG_STEP,
            FUZZY_LOGIC_ALGEBRAIC
        );

    bounded_cog =
        evaluate_process_response(
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            NORMAL_COG_STEP,
            FUZZY_LOGIC_BOUNDED
        );

    FUZZY_PRINTF(
        "\nOperator-family COG comparison\n"
        "==============================\n"
        "Standard Zadeh:      %.5f\n"
        "Algebraic:           %.5f\n"
        "Bounded Lukasiewicz: %.5f\n",
        standard_cog,
        algebraic_cog,
        bounded_cog
    );

    if (!plot_selected_process_cog(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP
    )) {
        FUZZY_ERROR(
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
    FUZZY_PRINTF(
        "\nRandomized fuzzy-NOT rule\n"
        "=========================\n"
    );

    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            FUZZY_PRINTF(
                "IF temperature is NOT high\n"
                "AND pressure is normal\n"
                "THEN response is low.\n"
            );
            break;

        case RANDOM_NOT_HUMIDITY_LOW:
            FUZZY_PRINTF(
                "IF humidity is NOT low\n"
                "AND vibration is medium\n"
                "THEN response is moderate.\n"
            );
            break;

        case RANDOM_NOT_VIBRATION_LOW:
            FUZZY_PRINTF(
                "IF vibration is NOT low\n"
                "AND pressure is high\n"
                "THEN response is high.\n"
            );
            break;

        case RANDOM_NOT_PRESSURE_HIGH:
            FUZZY_PRINTF(
                "IF pressure is NOT high\n"
                "AND material quality is good\n"
                "THEN response is minimal.\n"
            );
            break;

        case RANDOM_NOT_QUALITY_GOOD:
            FUZZY_PRINTF(
                "IF material quality is NOT good\n"
                "OR temperature is high\n"
                "THEN response is high.\n"
            );
            break;

        default:
            FUZZY_PRINTF(
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
    /*
     * Seed the pseudorandom generator once.
     */
    srand(
        (unsigned int)time(NULL)
    );

    /*
     * Generate one randomized fuzzy system for this run.
     *
     * All subsequent plots, rules, COG evaluations, and
     * sweep points use these same parameters.
     */
    randomize_membership_parameters();

    FUZZY_PRINTF(
        "\nfuzzy.h Complete API Demonstration\n"
        "==================================\n"
    );

    print_random_not_rule();

    /*
     * Generate:
     *
     * - Membership-function plots
     * - Hedge comparison plot
     * - T-norm comparison plot
     * - T-conorm comparison plot
     */
    if (!plot_all_membership_functions()) {
        return 1;
    }

    FUZZY_PRINTF(
        "\nGenerated fuzzy-operator comparison plots:\n"
        "  " DEMO_DIRECTORY "/t_norms.svg\n"
        "  " DEMO_DIRECTORY "/t_conorms.svg\n"
    );

    /*
     * Generate:
     *
     * demo-all/process_sweep.csv
     * demo-all/process_sweep.svg
     */
    if (!plot_process_sweep()) {
        FUZZY_ERROR(
            "Failed to generate five-dimensional "
            "COG sweep.\n"
        );

        return 1;
    }

    FUZZY_PRINTF(
        "\nGenerated five-dimensional sweep files:\n"
        "  " DEMO_DIRECTORY "/process_sweep.csv\n"
        "  " DEMO_DIRECTORY "/process_sweep.svg\n"
    );

    /*
     * Evaluate one randomly generated operating condition,
     * print all thirteen rule activations, and generate
     * separate COG, MOM, SOM, and LOM plots.
     */
    if (!run_random_demonstration()) {
        return 1;
    }

    FUZZY_PRINTF(
        "\nGenerated complete operator-family controller plots:\n"

        "\nStandard Zadeh controller:\n"
        "  " DEMO_DIRECTORY "/selected_standard_cog.svg\n"
        "  " DEMO_DIRECTORY "/selected_standard_mom.svg\n"
        "  " DEMO_DIRECTORY "/selected_standard_som.svg\n"
        "  " DEMO_DIRECTORY "/selected_standard_lom.svg\n"

        "\nAlgebraic controller:\n"
        "  " DEMO_DIRECTORY "/selected_algebraic_cog.svg\n"
        "  " DEMO_DIRECTORY "/selected_algebraic_mom.svg\n"
        "  " DEMO_DIRECTORY "/selected_algebraic_som.svg\n"
        "  " DEMO_DIRECTORY "/selected_algebraic_lom.svg\n"

        "\nBounded Lukasiewicz controller:\n"
        "  " DEMO_DIRECTORY "/selected_bounded_cog.svg\n"
        "  " DEMO_DIRECTORY "/selected_bounded_mom.svg\n"
        "  " DEMO_DIRECTORY "/selected_bounded_som.svg\n"
        "  " DEMO_DIRECTORY "/selected_bounded_lom.svg\n"

        "\nComplete fuzzy.h demonstration finished.\n"
    );

    return 0;
}