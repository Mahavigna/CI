#include "fuzzy.h"

int greenhouse_main(void);

/* Temperature */

static float temperature_low(float value)
{
    return fuzzy_ramp(
        "Temperature: Low",
        10.0f,
        15.0f,
        value,
        false
    );
}

static float temperature_medium(float value)
{
    float rising = fuzzy_ramp(
        "Temperature: Medium Rising",
        5.0f,
        15.0f,
        value,
        true
    );

    float falling = fuzzy_ramp(
        "Temperature: Medium Falling",
        15.0f,
        25.0f,
        value,
        false
    );

    return fuzzy_and(rising, falling);
}

static float temperature_high(float value)
{
    return fuzzy_ramp(
        "Temperature: High",
        15.0f,
        25.0f,
        value,
        true
    );
}

/* Humidity */

static float humidity_low(float value)
{
    return fuzzy_ramp(
        "Humidity: Low",
        5.0f,
        10.0f,
        value,
        false
    );
}

static float humidity_medium(float value)
{
    float rising = fuzzy_ramp(
        "Humidity: Medium Rising",
        5.0f,
        10.0f,
        value,
        true
    );

    float falling = fuzzy_ramp(
        "Humidity: Medium Falling",
        20.0f,
        25.0f,
        value,
        false
    );

    return fuzzy_and(rising, falling);
}

static float humidity_high(float value)
{
    return fuzzy_ramp(
        "Humidity: High",
        15.0f,
        25.0f,
        value,
        true
    );
}

/* Watering time */

static float watering_time_short(float value)
{
    float rising = fuzzy_ramp(
        "Watering Time: Short Rising",
        0.0f,
        10.0f,
        value,
        true
    );

    float falling = fuzzy_ramp(
        "Watering Time: Short Falling",
        20.0f,
        30.0f,
        value,
        false
    );

    return fuzzy_and(rising, falling);
}

static float watering_time_medium(float value)
{
    float rising = fuzzy_ramp(
        "Watering Time: Medium Rising",
        15.0f,
        30.0f,
        value,
        true
    );

    float falling = fuzzy_ramp(
        "Watering Time: Medium Falling",
        30.0f,
        45.0f,
        value,
        false
    );

    return fuzzy_and(rising, falling);
}

static float watering_time_long(float value)
{
    float rising = fuzzy_ramp(
        "Watering Time: Long Rising",
        30.0f,
        40.0f,
        value,
        true
    );

    float falling = fuzzy_ramp(
        "Watering Time: Long Falling",
        50.0f,
        60.0f,
        value,
        false
    );

    return fuzzy_and(rising, falling);
}

/* Mamdani rules and simplified COG */

static float fuzzy_rules(float temperature, float humidity)
{
    float rule_values[] = {
        fuzzy_or(
            temperature_low(temperature),
            humidity_medium(humidity)
        ),
        fuzzy_and(
            temperature_medium(temperature),
            humidity_medium(humidity)
        ),
        fuzzy_or(
            temperature_high(temperature),
            humidity_low(humidity)
        )
    };

    float (*output_functions[])(float) = {
        watering_time_short,
        watering_time_medium,
        watering_time_long
    };

    printf("\nRule 1: %.5f\n", rule_values[0]);
    printf("Rule 2: %.5f\n", rule_values[1]);
    printf("Rule 3: %.5f\n", rule_values[2]);

    return fuzzy_cog(
        rule_values,
        output_functions,
        3,
        0.0f,
        60.0f,
        10.0f
    );
}

int greenhouse_main(void)
{
    float temperature;
    float humidity;

    printf("Enter temperature (C): ");

    if (scanf("%f", &temperature) != 1) {
        return 1;
    }

    printf("Enter relative humidity (%%): ");

    if (scanf("%f", &humidity) != 1) {
        return 1;
    }

    float watering_time = fuzzy_rules(
        temperature,
        humidity
    );

    printf(
        "\nWatering time: %.5f\n",
        watering_time
    );

    return 0;
}