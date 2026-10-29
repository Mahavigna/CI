#ifdef SIMULATION

#define FUZZY_MAX_RULES 2u
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#else

#ifdef __SDCC
#include <8052.h>
#else
#include <REG51.H>
#endif

#define FUZZY_8051
#define FUZZY_8051_MINIMAL
#define FUZZY_MAX_RULES 2u

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#endif /* SIMULATION */


/* ==========================================================
 * Values retained for inspection
 * ========================================================== */

volatile unsigned char test_temperature = 0u;
volatile unsigned char test_pwm = 0u;
volatile float test_fan_speed = 0.0f;


/* ==========================================================
 * Hedge exponents
 * ========================================================== */

#ifdef SIMULATION

static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};

#else

static const hedges_t hedges = {
    1u,
    2u,
    3u
};

#endif /* SIMULATION */


/* ==========================================================
 * Temperature membership functions
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
 * Fuzzy fan controller
 * ========================================================== */

static float calculate_fan_speed(
    float temperature
)
{
    fuzzy_rules_t rules;
    float result;

    fuzzy_rules_create(
        &rules
    );

    if (!FUZZY_RULE_ADD(
        &rules,
        temperature_low(temperature),
        fan_slow
    )) {
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD(
        &rules,
        temperature_high(temperature),
        fan_fast
    )) {
        return 0.0f;
    }

result =
    fuzzy_rules_defuzzify(
        &rules,
        0.0f,
        100.0f,
        10.0f,
        FUZZY_DEFUZZ_MOM
    );

    fuzzy_rules_free(
        &rules
    );

    return result;
}


/* ==========================================================
 * Convert fuzzy output to PWM percentage
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
 * Program entry point
 *
 * P2 = temperature input from simulator switches
 * P1 = fuzzy fan-speed/PWM output
 * P0 = execution status
 *
 * P0 = 0x55 while calculating
 * P0 = 0xAA when output is ready
 * P0 = 0xF0 when P2 input is above 100
 * ========================================================== */

#ifndef SIMULATION

void main(void)
{
    /*
     * Fixed verification input:
     *
     * 42 decimal = 0x2A
     */
    test_temperature =
        42u;

    /*
     * Calculation started.
     */
    P0 =
        0x55u;

    P1 =
        0x00u;

    /*
    * Release P2 for external input, then read it.
    */
    // P2 = 0xFFu;
    test_temperature = P2;

    test_fan_speed =
        calculate_fan_speed(
            (float)test_temperature
        );

    test_pwm =
        fan_speed_to_pwm(
            test_fan_speed
        );

    /*
     * Final visible result.
     */
    P1 =
        test_pwm;

    /*
     * Calculation completed.
     */
    P0 =
        0xAAu;

    for (;;) {
        ;
    }
}

#else


/* ==========================================================
 * Desktop sweep adapter
 *
 * The third argument is supplied by the generic sweep API.
 * The Mamdani controller uses the fixed 10-unit COG step
 * inside calculate_fan_speed().
 * ========================================================== */

static float evaluate_fan_sweep(
    const float inputs[],
    size_t input_count,
    float unused_step
)
{
    (void)unused_step;

    if (
        inputs == NULL ||
        input_count != 1u
    ) {
        return 0.0f;
    }

    return calculate_fan_speed(
        inputs[0]
    );
}


/* ==========================================================
 * Desktop verification
 * ========================================================== */

static void print_verification(void)
{
    test_temperature =
        42u;

    test_fan_speed =
        calculate_fan_speed(
            (float)test_temperature
        );

    test_pwm =
        fan_speed_to_pwm(
            test_fan_speed
        );

    FUZZY_PRINTF(
        "\nMamdani 8052 verification\n"
        "=========================\n"
        "Temperature:     %u\n"
        "Low activation:  %.5f\n"
        "High activation: %.5f\n"
        "Fan speed:       %.5f\n"
        "PWM:             %u\n"
        "P0:              0xAA\n"
        "P1:              0x%02X\n"
        "P2:              0x%02X\n",
        (unsigned int)test_temperature,
        temperature_low(
            (float)test_temperature
        ),
        temperature_high(
            (float)test_temperature
        ),
        test_fan_speed,
        (unsigned int)test_pwm,
        (unsigned int)test_pwm,
        (unsigned int)test_temperature
    );
}


/* ==========================================================
 * Selected Mamdani COG plot
 * ========================================================== */

static bool plot_selected_cog(
    float temperature
)
{
    fuzzy_rules_t rules;
    float result;
    bool success;

    fuzzy_rules_create(
        &rules
    );

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Low temperature produces slow fan",
        temperature_low(
            temperature
        ),
        fan_slow
    )) {
        fuzzy_rules_free(
            &rules
        );

        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "High temperature produces fast fan",
        temperature_high(
            temperature
        ),
        fan_fast
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
            0.0f,
            100.0f,
            10.0f
        );

    success =
        fuzzy_rules_plot_cog(
            &rules,
            "mamdani_selected_cog",
            "Mamdani 8052 Fan Controller: Selected COG",
            result,
            0.0f,
            100.0f,
            10.0f
        );

    fuzzy_rules_free(
        &rules
    );

    return success;
}


/* ==========================================================
 * Membership-function plots
 * ========================================================== */

static bool plot_memberships(void)
{
    if (!FUZZY_PLOT(
        "mamdani_temperature",
        "Temperature Membership Functions",
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
    )) {
        return false;
    }

    return FUZZY_PLOT(
        "mamdani_fan",
        "Fan Output Membership Functions",
        0.0f,
        100.0f,
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
 * Temperature-to-fan sweep
 * ========================================================== */

static bool plot_controller_sweep(void)
{
    return FUZZY_COG_SWEEP(
        "mamdani_8052_sweep",
        "Mamdani 8052 Fan Controller",
        evaluate_fan_sweep,
        10.0f,

        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            100.0f,
            1.0f
        )
    );
}


/* ==========================================================
 * Desktop entry point
 * ========================================================== */

int main(void)
{
    print_verification();

    if (!plot_memberships()) {
        FUZZY_ERROR(
            "Failed to generate membership plots.\n"
        );

        return 1;
    }

    if (!plot_selected_cog(
        42.0f
    )) {
        FUZZY_ERROR(
            "Failed to generate selected COG plot.\n"
        );

        return 1;
    }

    if (!plot_controller_sweep()) {
        FUZZY_ERROR(
            "Failed to generate Mamdani response sweep.\n"
        );

        return 1;
    }

    FUZZY_PRINTF(
        "\nGenerated:\n"
        "  mamdani_temperature.svg\n"
        "  mamdani_fan.svg\n"
        "  mamdani_selected_cog.svg\n"
        "  mamdani_8052_sweep.csv\n"
        "  mamdani_8052_sweep.svg\n"
    );

    return 0;
}

#endif /* SIMULATION */
