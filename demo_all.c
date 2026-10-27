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
#define SWEEP_COG_STEP              0.25f


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


/* ==========================================================
 * Temperature membership functions
 *
 * Range: 0 to 100 degrees Celsius
 *
 * Shapes demonstrated:
 *
 * - ZMF
 * - Gaussian
 * - SMF
 * ========================================================== */

static float temperature_low(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        20.0,
        45.0
    );
}


static float temperature_medium(float value)
{
    return fuzzy_function(
        "gauss",
        value,
        hedges.none,
        50.0,
        14.0
    );
}


static float temperature_high(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        55.0,
        85.0
    );
}


/* ==========================================================
 * Humidity membership functions
 *
 * Range: 0 to 100 percent
 *
 * Shapes demonstrated:
 *
 * - Ramp
 * - Trapezoid
 * - Sigmoid
 * ========================================================== */

static float humidity_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        45.0,
        false
    );
}


static float humidity_medium(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        25.0,
        40.0,
        60.0,
        75.0
    );
}


static float humidity_high(float value)
{
    return fuzzy_function(
        "sigmoid",
        value,
        hedges.none,
        0.14,
        65.0
    );
}


/* ==========================================================
 * Vibration membership functions
 *
 * Range: 0 to 10 arbitrary vibration units
 *
 * Shapes demonstrated:
 *
 * - ZMF
 * - Generalized bell
 * - SMF
 * ========================================================== */

static float vibration_low(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        1.0,
        4.0
    );
}


static float vibration_medium(float value)
{
    return fuzzy_function(
        "bell",
        value,
        hedges.none,
        5.0,
        2.5,
        5.0
    );
}


static float vibration_high(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        5.5,
        9.0
    );
}


/* ==========================================================
 * Pressure membership functions
 *
 * Range: 0 to 200 pressure units
 *
 * Shapes demonstrated:
 *
 * - Ramp
 * - Triangle
 * - Sigmoid
 * ========================================================== */

static float pressure_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        40.0,
        90.0,
        false
    );
}


static float pressure_normal(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        60.0,
        110.0,
        160.0
    );
}


static float pressure_high(float value)
{
    return fuzzy_function(
        "sigmoid",
        value,
        hedges.none,
        0.07,
        145.0
    );
}


/* ==========================================================
 * Material-quality membership functions
 *
 * Range: 0 to 100 quality units
 *
 * Shapes demonstrated:
 *
 * - ZMF
 * - Gaussian
 * - SMF
 * ========================================================== */

static float quality_poor(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        20.0,
        50.0
    );
}


static float quality_average(float value)
{
    return fuzzy_function(
        "gauss",
        value,
        hedges.none,
        55.0,
        15.0
    );
}


static float quality_good(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        55.0,
        90.0
    );
}


/* ==========================================================
 * Process-response output membership functions
 *
 * Range: 0 to 100 response units
 *
 * These functions are used as Mamdani consequents.
 * ========================================================== */

static float response_minimal(float value)
{
    return fuzzy_function(
        "zmf",
        value,
        hedges.none,
        10.0,
        30.0
    );
}


static float response_low(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        10.0,
        30.0,
        50.0
    );
}


static float response_moderate(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        30.0,
        45.0,
        55.0,
        70.0
    );
}


static float response_high(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        55.0,
        75.0,
        90.0
    );
}


static float response_critical(float value)
{
    return fuzzy_function(
        "smf",
        value,
        hedges.none,
        75.0,
        95.0
    );
}


/* ==========================================================
 * Hedge demonstration functions
 *
 * All five curves use the same trapezoidal membership
 * function with different linguistic hedge exponents.
 * ========================================================== */

static float hedge_none_demo(float value)
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


static float hedge_very_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.very,
        10.0,
        30.0,
        70.0,
        90.0
    );
}


static float hedge_extremely_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.extremely,
        10.0,
        30.0,
        70.0,
        90.0
    );
}


static float hedge_somewhat_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.somewhat,
        10.0,
        30.0,
        70.0,
        90.0
    );
}


static float hedge_slightly_demo(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.slightly,
        10.0,
        30.0,
        70.0,
        90.0
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
 * Complex Mamdani rule construction
 * ========================================================== */

static bool build_process_rules(
    fuzzy_rules_t *rules,
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality
)
{
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
    float rule1 = fuzzy_and(
        5,
        temperature_low(temperature),
        humidity_medium(humidity),
        vibration_low(vibration),
        pressure_normal(pressure),
        quality_good(quality)
    );

    /*
     * Rule 2:
     *
     * IF temperature is medium
     * AND pressure is normal
     * AND quality is average
     * THEN response is low.
     */
    float rule2 = fuzzy_and(
        3,
        temperature_medium(temperature),
        pressure_normal(pressure),
        quality_average(quality)
    );

    /*
     * Rule 3:
     *
     * IF humidity is high
     * OR vibration is medium
     * OR quality is poor
     * THEN response is moderate.
     */
    float rule3 = fuzzy_or(
        3,
        humidity_high(humidity),
        vibration_medium(vibration),
        quality_poor(quality)
    );

    /*
     * Rule 4:
     *
     * IF temperature is high
     * AND vibration is high
     * THEN response is high.
     */
    float rule4 = fuzzy_and(
        2,
        temperature_high(temperature),
        vibration_high(vibration)
    );

    /*
     * Rule 5:
     *
     * IF pressure is high
     * OR vibration is high
     * OR temperature is high
     * THEN response is high.
     */
    float rule5 = fuzzy_or(
        3,
        pressure_high(pressure),
        vibration_high(vibration),
        temperature_high(temperature)
    );

    /*
     * Rule 6:
     *
     * IF temperature is very high
     * AND pressure is high
     * THEN response is critical.
     *
     * The hedge is applied explicitly using the configured
     * exponent because the temperature-high membership
     * function itself uses the neutral hedge.
     */
    float very_high_temperature =
        powf(
            temperature_high(temperature),
            hedges.very
        );

    float rule6 = fuzzy_and(
        2,
        very_high_temperature,
        pressure_high(pressure)
    );

    /*
     * Rule 7:
     *
     * IF vibration is extremely high
     * OR quality is very poor
     * THEN response is critical.
     */
    float extremely_high_vibration =
        powf(
            vibration_high(vibration),
            hedges.extremely
        );

    float very_poor_quality =
        powf(
            quality_poor(quality),
            hedges.very
        );

    float rule7 = fuzzy_or(
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
     */
    float somewhat_high_humidity =
        powf(
            humidity_high(humidity),
            hedges.somewhat
        );

    float rule8_left = fuzzy_and(
        2,
        temperature_medium(temperature),
        somewhat_high_humidity
    );

    float rule8_right = fuzzy_and(
        2,
        pressure_high(pressure),
        quality_poor(quality)
    );

    float rule8 = fuzzy_or(
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
     */
    float rule9_environment = fuzzy_or(
        2,
        temperature_low(temperature),
        humidity_low(humidity)
    );

    float rule9_machine = fuzzy_or(
        2,
        vibration_low(vibration),
        pressure_normal(pressure)
    );

    float rule9 = fuzzy_and(
        3,
        rule9_environment,
        rule9_machine,
        quality_good(quality)
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
    float rule10 = fuzzy_and(
        5,
        temperature_high(temperature),
        humidity_high(humidity),
        vibration_high(vibration),
        pressure_high(pressure),
        quality_poor(quality)
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
    float cog_step
)
{
    fuzzy_rules_t rules =
        fuzzy_rules_create();

    if (!build_process_rules(
        &rules,
        temperature,
        humidity,
        vibration,
        pressure,
        quality
    )) {
        FUZZY_ERROR(
            "Failed to construct process-response rules.\n"
        );

        fuzzy_rules_free(
            &rules
        );

        return 0.0f;
    }

    float result = fuzzy_rules_cog(
        &rules,
        RESPONSE_LOWER,
        RESPONSE_UPPER,
        cog_step
    );

    fuzzy_rules_free(
        &rules
    );

    return result;
}


/* ==========================================================
 * Plot one selected process-response COG
 * ========================================================== */

static bool plot_selected_process_cog(
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    float cog_step
)
{
    fuzzy_rules_t rules =
        fuzzy_rules_create();

    if (!build_process_rules(
        &rules,
        temperature,
        humidity,
        vibration,
        pressure,
        quality
    )) {
        FUZZY_ERROR(
            "Failed to construct process-response rules.\n"
        );

        fuzzy_rules_free(
            &rules
        );

        return false;
    }

    FUZZY_PRINTF(
        "\nRule activations:\n"
    );

    fuzzy_rules_print(
        &rules
    );

    float result = fuzzy_rules_cog(
        &rules,
        RESPONSE_LOWER,
        RESPONSE_UPPER,
        cog_step
    );

    bool success = fuzzy_rules_plot_cog(
        &rules,
        DEMO_DIRECTORY "/selected_cog",
        "Selected Process-Response COG",
        result,
        RESPONSE_LOWER,
        RESPONSE_UPPER,
        cog_step
    );

    fuzzy_rules_free(
        &rules
    );

    return success;
}


/* ==========================================================
 * Membership-function plot helpers
 * ========================================================== */

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

    FUZZY_PRINTF(
        "\nGenerated all membership-function plots.\n"
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
        cog_step
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
    float temperature =
        random_float(
            0.0f,
            100.0f
        );

    float humidity =
        random_float(
            0.0f,
            100.0f
        );

    float vibration =
        random_float(
            0.0f,
            10.0f
        );

    float pressure =
        random_float(
            0.0f,
            200.0f
        );

    float quality =
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

    float response =
        evaluate_process_response(
            temperature,
            humidity,
            vibration,
            pressure,
            quality,
            NORMAL_COG_STEP
        );

    FUZZY_PRINTF(
        "\nDefuzzified process-response COG: %.5f\n",
        response
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
            "Failed to generate selected COG plot.\n"
        );

        return false;
    }

    return true;
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

    FUZZY_PRINTF(
        "\nfuzzy.h Complete API Demonstration\n"
        "==================================\n"
    );

    /*
     * Generate plots for every supported membership shape,
     * every configured hedge, each input variable, and the
     * output variable.
     */
    if (!plot_all_membership_functions()) {
        return 1;
    }

    /*
     * Generate:
     *
     * demo-all/process_sweep.csv
     * demo-all/process_sweep.svg
     */
    if (!plot_process_sweep()) {
        FUZZY_ERROR(
            "Failed to generate five-dimensional COG sweep.\n"
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
     * print all rule activations, and generate one selected
     * aggregated-output COG plot.
     */
    if (!run_random_demonstration()) {
        return 1;
    }

    FUZZY_PRINTF(
        "\nComplete fuzzy.h demonstration finished.\n"
    );

    return 0;
}