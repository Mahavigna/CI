/*
 * Desktop simulation and visualization harness for the
 * AT89S52/8052 fuzzy fan controller.
 *
 * This file preserves the embedded controller's:
 *
 * - Membership boundaries
 * - Hedge value
 * - Mamdani rules
 * - COG output range
 * - COG sampling step
 * - PWM conversion
 * - Fixed verification input
 *
 * The desktop-only API additionally generates:
 *
 * - Temperature membership-function SVG
 * - Fan membership-function SVG
 * - Selected COG SVG for temperature 42
 * - Full temperature sweep CSV
 * - Full temperature sweep SVG
 *
 * FUZZY_8051 and FUZZY_8051_MINIMAL are intentionally not
 * defined because plotting, CSV output, named rules, and
 * multidimensional sweeps are desktop-only features.
 */


#define FUZZY_MAX_RULES 2u

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"


/* ==========================================================
 * Controller configuration
 *
 * These values match controller_8051.c.
 * ========================================================== */

#define FAN_OUTPUT_LOWER       0.0f
#define FAN_OUTPUT_UPPER       100.0f
#define FAN_COG_STEP           10.0f
#define VERIFICATION_INPUT     42.0f


/* ==========================================================
 * Values retained for comparison with embedded firmware
 * ========================================================== */

static float test_temperature =
    VERIFICATION_INPUT;

static unsigned char test_pwm =
    0u;

static float test_fan_speed =
    0.0f;


/* ==========================================================
 * Hedge exponents
 *
 * The embedded implementation uses:
 *
 *     1u, 2u, 3u
 *
 * The desktop structure contains additional fractional
 * hedges, but this controller uses only hedges.none.
 * ========================================================== */

static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};


/* ==========================================================
 * Temperature membership functions
 *
 * These calls intentionally match controller_8051.c.
 * ========================================================== */

static float temperature_low(
    float value
)
{
    return fuzzy_ramp(
        NULL,
        20.0f,
        40.0f,
        value,
        false,
        hedges.none
    );
}


static float temperature_high(
    float value
)
{
    return fuzzy_ramp(
        NULL,
        30.0f,
        60.0f,
        value,
        true,
        hedges.none
    );
}


/* ==========================================================
 * Fan-output membership functions
 *
 * These calls intentionally match controller_8051.c.
 * ========================================================== */

static float fan_slow(
    float value
)
{
    return fuzzy_ramp(
        NULL,
        20.0f,
        50.0f,
        value,
        false,
        hedges.none
    );
}


static float fan_fast(
    float value
)
{
    return fuzzy_ramp(
        NULL,
        40.0f,
        80.0f,
        value,
        true,
        hedges.none
    );
}


/* ==========================================================
 * Rule construction
 *
 * Rule 1:
 *
 *     IF temperature is low
 *     THEN fan is slow.
 *
 * Rule 2:
 *
 *     IF temperature is high
 *     THEN fan is fast.
 *
 * The activation values and output functions match the
 * embedded controller exactly.
 * ========================================================== */

static bool build_fan_rules(
    fuzzy_rules_t *rules,
    float temperature
)
{
    if (rules == NULL) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Low temperature produces slow fan",
        temperature_low(temperature),
        fan_slow
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "High temperature produces fast fan",
        temperature_high(temperature),
        fan_fast
    )) {
        return false;
    }

    return true;
}


/* ==========================================================
 * Pure fuzzy-controller calculation
 *
 * This function performs no printing and creates no files.
 * It is safe to call repeatedly during the sweep.
 * ========================================================== */

static float calculate_fan_speed(
    float temperature,
    float cog_step
)
{
    fuzzy_rules_t rules;
    float result;

    fuzzy_rules_create(
        &rules
    );

    if (!build_fan_rules(
        &rules,
        temperature
    )) {
        fuzzy_rules_free(
            &rules
        );

        return 0.0f;
    }

    result =
        fuzzy_rules_cog(
            &rules,
            FAN_OUTPUT_LOWER,
            FAN_OUTPUT_UPPER,
            cog_step
        );

    fuzzy_rules_free(
        &rules
    );

    return result;
}


/* ==========================================================
 * Convert fuzzy output to PWM percentage
 *
 * This function matches controller_8051.c exactly.
 * ========================================================== */

static unsigned char fan_speed_to_pwm(
    float fan_speed
)
{
    if (fan_speed <= 0.0f) {
        return 0u;
    }

    if (fan_speed >= 100.0f) {
        return 100u;
    }

    return (unsigned char)(
        fan_speed + 0.5f
    );
}


/* ==========================================================
 * Selected-input COG plot
 *
 * This generates the aggregated Mamdani output for one input.
 *
 * For the default verification:
 *
 *     temperature = 42
 *
 * Output:
 *
 *     sim_8051_selected_cog.svg
 * ========================================================== */

static bool plot_selected_cog(
    float temperature,
    float cog_step
)
{
    fuzzy_rules_t rules;
    float result;
    bool success;

    fuzzy_rules_create(
        &rules
    );

    if (!build_fan_rules(
        &rules,
        temperature
    )) {
        fuzzy_rules_free(
            &rules
        );

        return false;
    }

    FUZZY_PRINTF(
        "\nSelected-input rule activations:\n"
    );

    fuzzy_rules_print(
        &rules
    );

    result =
        fuzzy_rules_cog(
            &rules,
            FAN_OUTPUT_LOWER,
            FAN_OUTPUT_UPPER,
            cog_step
        );

    success =
        fuzzy_rules_plot_cog(
            &rules,
            "sim_8051_selected_cog",
            "8051 Fan Controller: Selected COG Output",
            result,
            FAN_OUTPUT_LOWER,
            FAN_OUTPUT_UPPER,
            cog_step
        );

    fuzzy_rules_free(
        &rules
    );

    return success;
}


/* ==========================================================
 * Sweep adapter
 *
 * FUZZY_COG_SWEEP requires:
 *
 *     inputs[0] = temperature
 * ========================================================== */

static float evaluate_fan_sweep(
    const float inputs[],
    size_t input_count,
    float cog_step
)
{
    if (
        inputs == NULL ||
        input_count != 1u
    ) {
        return 0.0f;
    }

    return calculate_fan_speed(
        inputs[0],
        cog_step
    );
}


/* ==========================================================
 * Embedded-verification result
 *
 * This performs the equivalent of the embedded main():
 *
 *     P2 = temperature input
 *     P1 = rounded PWM output
 *     P0 = 0xAA when complete
 *
 * The desktop harness prints equivalent values.
 * ========================================================== */

static void run_embedded_verification(void)
{
    unsigned char simulated_p0;
    unsigned char simulated_p1;
    unsigned char simulated_p2;

    simulated_p0 =
        0x55u;

    test_temperature =
        VERIFICATION_INPUT;

    simulated_p2 =
        (unsigned char)test_temperature;

    test_fan_speed =
        calculate_fan_speed(
            test_temperature,
            FAN_COG_STEP
        );

    test_pwm =
        fan_speed_to_pwm(
            test_fan_speed
        );

    simulated_p1 =
        test_pwm;

    simulated_p0 =
        0xAAu;

    FUZZY_PRINTF(
        "\nEmbedded verification\n"
        "=====================\n"
    );

    FUZZY_PRINTF(
        "Temperature input: %.0f\n",
        test_temperature
    );

    FUZZY_PRINTF(
        "Fuzzy fan speed:   %.5f\n",
        test_fan_speed
    );

    FUZZY_PRINTF(
        "Rounded PWM:       %u%%\n",
        (unsigned int)test_pwm
    );

    FUZZY_PRINTF(
        "\nExpected embedded ports:\n"
    );

    FUZZY_PRINTF(
        "P0 = 0x%02X  status complete\n",
        (unsigned int)simulated_p0
    );

    FUZZY_PRINTF(
        "P1 = 0x%02X  PWM output = %u\n",
        (unsigned int)simulated_p1,
        (unsigned int)simulated_p1
    );

    FUZZY_PRINTF(
        "P2 = 0x%02X  temperature input = %u\n",
        (unsigned int)simulated_p2,
        (unsigned int)simulated_p2
    );
}


/* ==========================================================
 * Complete console table
 *
 * This prints the controller response over the complete
 * temperature universe.
 * ========================================================== */

static void print_controller_results(void)
{
    int temperature;
    float fan_speed;
    unsigned char pwm;

    FUZZY_PRINTF(
        "\n8051 Fan Controller PC Simulation\n"
        "=================================\n"
    );

    FUZZY_PRINTF(
        "Temperature,FanSpeed,PWM\n"
    );

    for (
        temperature = 0;
        temperature <= 100;
        temperature += 5
    ) {
        fan_speed =
            calculate_fan_speed(
                (float)temperature,
                FAN_COG_STEP
            );

        pwm =
            fan_speed_to_pwm(
                fan_speed
            );

        FUZZY_PRINTF(
            "%d,%.5f,%u\n",
            temperature,
            fan_speed,
            (unsigned int)pwm
        );
    }
}


/* ==========================================================
 * Temperature membership-function plot
 *
 * Output:
 *
 *     sim_8051_temperature.svg
 * ========================================================== */

static bool plot_temperature_functions(void)
{
    return FUZZY_PLOT(
        "sim_8051_temperature",
        "8051 Fan Controller: Temperature Memberships",
        0.0f,
        100.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Temperature low",
            "#3b82f6",
            temperature_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Temperature high",
            "#ef4444",
            temperature_high
        )
    );
}


/* ==========================================================
 * Fan membership-function plot
 *
 * Output:
 *
 *     sim_8051_fan.svg
 * ========================================================== */

static bool plot_fan_functions(void)
{
    return FUZZY_PLOT(
        "sim_8051_fan",
        "8051 Fan Controller: Fan Memberships",
        FAN_OUTPUT_LOWER,
        FAN_OUTPUT_UPPER,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Fan slow",
            "#22c55e",
            fan_slow
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Fan fast",
            "#a855f7",
            fan_fast
        )
    );
}


/* ==========================================================
 * Complete temperature-to-fan sweep
 *
 * Outputs:
 *
 *     sim_8051.csv
 *     sim_8051.svg
 *
 * Sweep input step:
 *
 *     1 degree
 *
 * COG output step:
 *
 *     10 units
 *
 * These settings match the embedded controller.
 * ========================================================== */

static bool plot_fan_controller_sweep(void)
{
    return FUZZY_COG_SWEEP(
        "sim_8051",
        "8051 Fan Controller Simulation",
        evaluate_fan_sweep,
        FAN_COG_STEP,

        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            100.0f,
            1.0f
        )
    );
}


/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    /*
     * Perform the direct equivalent of the embedded
     * verification build.
     */
    run_embedded_verification();

    /*
     * Print the complete temperature response table.
     */
    print_controller_results();

    /*
     * Generate:
     *
     *     sim_8051_temperature.svg
     */
    if (!plot_temperature_functions()) {
        FUZZY_ERROR(
            "Failed to generate "
            "sim_8051_temperature.svg\n"
        );

        return 1;
    }

    /*
     * Generate:
     *
     *     sim_8051_fan.svg
     */
    if (!plot_fan_functions()) {
        FUZZY_ERROR(
            "Failed to generate "
            "sim_8051_fan.svg\n"
        );

        return 1;
    }

    /*
     * Generate:
     *
     *     sim_8051_selected_cog.svg
     */
    if (!plot_selected_cog(
        VERIFICATION_INPUT,
        FAN_COG_STEP
    )) {
        FUZZY_ERROR(
            "Failed to generate "
            "sim_8051_selected_cog.svg\n"
        );

        return 1;
    }

    /*
     * Generate:
     *
     *     sim_8051.csv
     *     sim_8051.svg
     */
    if (!plot_fan_controller_sweep()) {
        FUZZY_ERROR(
            "Failed to generate the 8051 "
            "fan-controller sweep.\n"
        );

        return 1;
    }

    FUZZY_PRINTF(
        "\n8051 controller simulation complete.\n"
        "\nGenerated files:\n"
        "  sim_8051_temperature.svg\n"
        "  sim_8051_fan.svg\n"
        "  sim_8051_selected_cog.svg\n"
        "  sim_8051.csv\n"
        "  sim_8051.svg\n"
    );

    return 0;
}