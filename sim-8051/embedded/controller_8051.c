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


volatile unsigned char test_temperature = 42u;
volatile unsigned char test_pwm = 0u;
volatile float test_fan_speed = 0.0f;


static const hedges_t hedges = {
    1u,
    2u,
    3u
};


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


void main(void)
{
    for (;;) {
        test_fan_speed =
            calculate_fan_speed(
                (float)test_temperature
            );

        test_pwm =
            fan_speed_to_pwm(
                test_fan_speed
            );
    }
}