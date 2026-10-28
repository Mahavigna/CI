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


/* ==========================================================
 * Values retained for inspection
 * ========================================================== */

volatile unsigned char test_temperature = 0u;
volatile unsigned char test_pwm = 0u;
volatile float test_fan_speed = 0.0f;


/* ==========================================================
 * Hedge exponents
 * ========================================================== */

static const hedges_t hedges = {
    1u,
    2u,
    3u
};


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
        fuzzy_rules_cog(
            &rules,
            0.0f,
            100.0f,
            10.0f
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

void main(void)
{
    /*
     * Fixed verification input:
     *
     * 42 decimal = 0x2A
     */
    test_temperature = 42u;

    /*
     * Calculation started.
     */
    P0 = 0x55u;
    P1 = 0x00u;
    P2 = test_temperature;

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
    P1 = test_pwm;

    /*
     * Calculation completed.
     */
    P0 = 0xAAu;

    for (;;) {
        ;
    }
}
