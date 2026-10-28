/*
 * PC simulation harness for the Keil 8051 fan controller.
 *
 * This example demonstrates how an embedded fuzzy controller
 * can be copied into a desktop test harness before flashing
 * the target microcontroller.
 *
 * The membership functions, rules, COG range, and COG step
 * match the Keil 8051 example.
 *
 * The desktop-only fuzzy.h tooling generates:
 *
 * - Input membership-function SVG
 * - Output membership-function SVG
 * - Controller sweep CSV
 * - Controller sweep SVG
 *
 * FUZZY_8051 is intentionally not defined because the
 * plotting and sweep API is available only on desktop builds.
 */


#define FUZZY_MAX_RULES 2u

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"


/* ==========================================================
 * Controller configuration
 * ========================================================== */

#define FAN_OUTPUT_LOWER  0.0f
#define FAN_OUTPUT_UPPER  100.0f
#define FAN_COG_STEP      10.0f


/*
 * Desktop hedge configuration.
 *
 * The Keil 8051 example uses integer hedge powers:
 *
 *     1, 2, 3
 *
 * The desktop implementation additionally supports
 * fractional hedge exponents.
 */
static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};


/* ==========================================================
 * Input membership functions
 *
 * These match the Keil 8051 controller.
 * ========================================================== */

static float temperature_low(
    float value
)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        40.0,
        false
    );
}


static float temperature_high(
    float value
)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        30.0,
        60.0,
        true
    );
}


/* ==========================================================
 * Output membership functions
 *
 * These match the Keil 8051 controller.
 * ========================================================== */

static float fan_slow(
    float value
)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        50.0,
        false
    );
}


static float fan_fast(
    float value
)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        40.0,
        80.0,
        true
    );
}


/* ==========================================================
 * Fuzzy fan controller
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
 * This is the same rule structure used by the Keil example.
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

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Low temperature produces slow fan",
        temperature_low(temperature),
        fan_slow
    )) {
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "High temperature produces fast fan",
        temperature_high(temperature),
        fan_fast
    )) {
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
 * Convert the fuzzy output to an integer PWM percentage
 *
 * This matches the conversion performed by the embedded
 * controller after COG defuzzification.
 * ========================================================== */

static unsigned char fan_speed_to_pwm(
    float fan_speed
)
{
    if (fan_speed <= FAN_OUTPUT_LOWER) {
        return 0u;
    }

    if (fan_speed >= FAN_OUTPUT_UPPER) {
        return 100u;
    }

    return (unsigned char)(
        fan_speed + 0.5f
    );
}


/* ==========================================================
 * Sweep adapter
 *
 * FUZZY_COG_SWEEP requires an evaluator with this signature:
 *
 *     float evaluator(
 *         const float inputs[],
 *         size_t input_count,
 *         float cog_step
 *     );
 *
 * This controller has one input:
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
 * Console demonstration
 *
 * This allows users to compare the fuzzy COG result against
 * the integer PWM value that would be used by the 8051.
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
 * Input membership-function plot
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
 * Output membership-function plot
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
 * Complete controller sweep
 *
 * Outputs:
 *
 *     sim_8051.csv
 *     sim_8051.svg
 *
 * The temperature sweep uses one-degree input increments.
 * Each controller evaluation uses the same 10-unit COG step
 * as the Keil example.
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
     * Show the numerical COG and PWM results directly in the
     * terminal.
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
        "  sim_8051.csv\n"
        "  sim_8051.svg\n"
    );

    return 0;
}