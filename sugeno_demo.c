#ifdef SIMULATION

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#else

#ifdef __SDCC
#include <8052.h>
#else
#include <REG51.H>
#endif

#define FUZZY_8051
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#endif /* SIMULATION */


/* ==========================================================
 * Verification values retained for debugger inspection
 * ========================================================== */

volatile unsigned char test_temperature = 42u;
volatile unsigned char test_load = 65u;
volatile unsigned char test_vibration = 4u;

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
 * Temperature memberships: 0 to 100
 * ========================================================== */

static float temperature_low(float value)
{
    return fuzzy_ramp(
        15.0f,
        40.0f,
        value,
        false,
        hedges.none
    );
}


static float temperature_high(float value)
{
    return fuzzy_ramp(
        35.0f,
        75.0f,
        value,
        true,
        hedges.none
    );
}


/* ==========================================================
 * Load memberships: 0 to 100
 * ========================================================== */

static float load_low(float value)
{
    return fuzzy_ramp(
        20.0f,
        50.0f,
        value,
        false,
        hedges.none
    );
}


static float load_high(float value)
{
    return fuzzy_ramp(
        45.0f,
        85.0f,
        value,
        true,
        hedges.none
    );
}


/* ==========================================================
 * Vibration memberships: 0 to 10
 * ========================================================== */

static float vibration_low(float value)
{
    return fuzzy_ramp(
        1.0f,
        4.0f,
        value,
        false,
        hedges.none
    );
}


static float vibration_high(float value)
{
    return fuzzy_ramp(
        3.0f,
        8.0f,
        value,
        true,
        hedges.none
    );
}


/* ==========================================================
 * User-defined first-order Sugeno consequents
 * ========================================================== */

static float response_idle(
    float temperature,
    float load,
    float vibration
)
{
    return
        8.0f +
        0.20f * temperature +
        0.08f * load +
        0.50f * vibration;
}


static float response_economy(
    float temperature,
    float load,
    float vibration
)
{
    return
        12.0f +
        0.30f * temperature +
        0.18f * load +
        0.80f * vibration;
}


static float response_balanced(
    float temperature,
    float load,
    float vibration
)
{
    return
        15.0f +
        0.42f * temperature +
        0.25f * load +
        1.20f * vibration;
}


static float response_cooling(
    float temperature,
    float load,
    float vibration
)
{
    return
        20.0f +
        0.65f * temperature +
        0.12f * load +
        1.50f * vibration;
}


static float response_heavy_load(
    float temperature,
    float load,
    float vibration
)
{
    return
        18.0f +
        0.30f * temperature +
        0.55f * load +
        1.00f * vibration;
}


static float response_protection(
    float temperature,
    float load,
    float vibration
)
{
    return
        35.0f +
        0.45f * temperature +
        0.30f * load +
        2.50f * vibration;
}


/* ==========================================================
 * Complex Sugeno controller
 *
 * Rule 1:
 * Low temperature AND low load AND low vibration.
 *
 * Rule 2:
 * NOT high temperature AND high load.
 *
 * Rule 3:
 * High temperature OR high vibration.
 *
 * Rule 4:
 * High temperature AND high load.
 *
 * Rule 5:
 * High load AND NOT high vibration.
 *
 * Rule 6:
 * (High temperature AND high vibration)
 * OR
 * (High load AND high vibration).
 * ========================================================== */

static float calculate_fan_speed(
    float temperature,
    float load,
    float vibration
)
{
    float temperature_low_value;
    float temperature_high_value;

    float load_low_value;
    float load_high_value;

    float vibration_low_value;
    float vibration_high_value;

    float rule1;
    float rule2;
    float rule3;
    float rule4;
    float rule5;
    float rule6;

    float rule6_thermal;
    float rule6_mechanical;

    temperature_low_value =
        temperature_low(
            temperature
        );

    temperature_high_value =
        temperature_high(
            temperature
        );

    load_low_value =
        load_low(
            load
        );

    load_high_value =
        load_high(
            load
        );

    vibration_low_value =
        vibration_low(
            vibration
        );

    vibration_high_value =
        vibration_high(
            vibration
        );

    rule1 =
        fuzzy_and_method(
            FUZZY_LOGIC_STANDARD,
            temperature_low_value,
            load_low_value,
            vibration_low_value
        );

    rule2 =
        fuzzy_and_method(
            FUZZY_LOGIC_STANDARD,
            fuzzy_not(
                temperature_high_value
            ),
            load_high_value
        );

    rule3 =
        fuzzy_or_method(
            FUZZY_LOGIC_STANDARD,
            temperature_high_value,
            vibration_high_value
        );

    rule4 =
        fuzzy_and_method(
            FUZZY_LOGIC_STANDARD,
            temperature_high_value,
            load_high_value
        );

    rule5 =
        fuzzy_and_method(
            FUZZY_LOGIC_STANDARD,
            load_high_value,
            fuzzy_not(
                vibration_high_value
            )
        );

    rule6_thermal =
        fuzzy_and_method(
            FUZZY_LOGIC_STANDARD,
            temperature_high_value,
            vibration_high_value
        );

    rule6_mechanical =
        fuzzy_and_method(
            FUZZY_LOGIC_STANDARD,
            load_high_value,
            vibration_high_value
        );

    rule6 =
        fuzzy_or_method(
            FUZZY_LOGIC_STANDARD,
            rule6_thermal,
            rule6_mechanical
        );

    return fuzzy_sugeno_weighted_average(
        rule1,
        response_idle(
            temperature,
            load,
            vibration
        ),

        rule2,
        response_economy(
            temperature,
            load,
            vibration
        ),

        rule3,
        response_balanced(
            temperature,
            load,
            vibration
        ),

        rule4,
        response_cooling(
            temperature,
            load,
            vibration
        ),

        rule5,
        response_heavy_load(
            temperature,
            load,
            vibration
        ),

        rule6,
        response_protection(
            temperature,
            load,
            vibration
        )
    );
}


/* ==========================================================
 * Convert crisp Sugeno output to PWM percentage
 * ========================================================== */

static unsigned char fan_speed_to_pwm(float fan_speed)
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
 * 8052 entry point
 *
 * Fixed verification inputs:
 *
 * Temperature = 42
 * Load        = 65
 * Vibration   = 4
 *
 * Visible ports:
 *
 * P2 = temperature
 * P1 = final PWM
 *
 * P0 = 0x55 while calculating
 * P0 = 0xAA when complete
 * ========================================================== */

#ifndef SIMULATION

void main(void)
{
    P0 =
        0x55u;

    P1 =
        0x00u;

    P2 =
        test_temperature;

    test_fan_speed =
        calculate_fan_speed(
            (float)test_temperature,
            (float)test_load,
            (float)test_vibration
        );

    test_pwm =
        fan_speed_to_pwm(
            test_fan_speed
        );

    P1 =
        test_pwm;

    P0 =
        0xAAu;

    for (;;) {
        ;
    }
}

#else


/* ==========================================================
 * Desktop sweep adapter
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
        input_count != 3u
    ) {
        return 0.0f;
    }

    return calculate_fan_speed(
        inputs[0],
        inputs[1],
        inputs[2]
    );
}


/* ==========================================================
 * Desktop verification
 * ========================================================== */

static void print_verification(void)
{
    float fan_speed;
    unsigned char pwm;

    fan_speed =
        calculate_fan_speed(
            (float)test_temperature,
            (float)test_load,
            (float)test_vibration
        );

    pwm =
        fan_speed_to_pwm(
            fan_speed
        );

    test_fan_speed =
        fan_speed;

    test_pwm =
        pwm;

    printf(
        "\nComplex Sugeno verification\n"
        "===========================\n"
        "Temperature: %u\n"
        "Load:        %u\n"
        "Vibration:   %u\n"
        "Fan speed:   %.5f\n"
        "PWM:         %u\n",
        (unsigned int)test_temperature,
        (unsigned int)test_load,
        (unsigned int)test_vibration,
        fan_speed,
        (unsigned int)pwm
    );
}


/* ==========================================================
 * Desktop membership plots
 * ========================================================== */

static bool plot_memberships(void)
{
    if (!FUZZY_PLOT(
        "sugeno_temperature",
        "Temperature Membership Functions",
        0.0f,
        100.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#3b82f6",
            temperature_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            temperature_high
        )
    )) {
        return false;
    }

    if (!FUZZY_PLOT(
        "sugeno_load",
        "Load Membership Functions",
        0.0f,
        100.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#22c55e",
            load_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#f97316",
            load_high
        )
    )) {
        return false;
    }

    return FUZZY_PLOT(
        "sugeno_vibration",
        "Vibration Membership Functions",
        0.0f,
        10.0f,
        0.1f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#06b6d4",
            vibration_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#a855f7",
            vibration_high
        )
    );
}


/* ==========================================================
 * Desktop three-dimensional response sweep
 * ========================================================== */

static bool plot_controller_sweep(void)
{
    return FUZZY_COG_SWEEP(
        "sugeno_complex_sweep",
        "Complex Sugeno Fan Controller",
        evaluate_fan_sweep,
        1.0f,

        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            100.0f,
            2.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Load",
            0.0f,
            100.0f,
            2.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Vibration",
            0.0f,
            10.0f,
            0.5f
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
        fprintf(
            stderr,
            "Failed to generate membership plots.\n"
        );

        return 1;
    }

    if (!plot_controller_sweep()) {
        fprintf(
            stderr,
            "Failed to generate Sugeno response sweep.\n"
        );

        return 1;
    }

    printf(
        "\nGenerated:\n"
        "  sugeno_temperature.svg\n"
        "  sugeno_load.svg\n"
        "  sugeno_vibration.svg\n"
        "  sugeno_complex_sweep.csv\n"
        "  sugeno_complex_sweep.svg\n"
    );

    return 0;
}

#endif /* SIMULATION */