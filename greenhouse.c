/*
 * Example application for the fuzzy logic library "fuzzy.h".
 *
 * This program determines paint strength from:
 *
 * - Mixture content
 * - Temperature
 *
 * Use this file as a template for developing other fuzzy systems.
 */

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

/*
 * User-defined linguistic hedge exponents.
 */
static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};


/* ==========================================================
 * Temperature membership functions
 * ========================================================== */

static float temp_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        10.0,
        15.0,
        false
    );
}

static float temp_medium(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        5.0,
        15.0,
        25.0
    );
}

static float temp_high(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        15.0,
        25.0,
        true
    );
}


/* ==========================================================
 * Temperature membership functions
 * ========================================================== */

static float humidity_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        5.0,
        10.0,
        false
    );
}

static float humidity_medium(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        5.0,
        10.0,
        20.0,
        25.0
    );
}

static float humidity_high(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        15.0,
        25.0,
        true
    );
}


/* ==========================================================
 * Time membership functions
 * ========================================================== */

static float time_short(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        0.0,
        10.0,
        20.0,
        30.0
    );
}

static float time_medium(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        15.0,
        30.0,
        45.0
    );
}

static float time_long(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        30.0,
        40.0,
        50.0,
        60.0
    );
}


/* ==========================================================
 * Mamdani rule evaluation
 * ========================================================== */

static float evaluate_time(float temperature, float humidity, float step)
{
    /*
     * Rule 1:
     *
     * IF mixture content is small
     * AND temperature is low
     * THEN time is short.
     */
    float rule1 = fuzzy_or(
        2,
        temp_low(temperature),
        humidity_medium(humidity)
    );

    /*
     * Rule 2:
     *
     * IF mixture content is huge
     * AND temperature is medium
     * THEN time is medium. 
     */
    float rule2 = fuzzy_and(
        2,
        humidity_medium(humidity),
        temp_medium(temperature)
    );

    /*
     * Rule 3:
     *
     * IF mixture content is huge
     * OR temperature is high
     * THEN time is long.
     */
    float rule3 = fuzzy_or(
        2,
        humidity_low(humidity),
        temp_high(temperature)
    );

    fuzzy_rules_t rules = fuzzy_rules_create();

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Time: Short",
        rule1,
        time_short
    )) {
        fprintf(stderr, "Failed to add Rule 1.\n");
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Time: Medium",
        rule2,
        time_medium
    )) {
        fprintf(stderr, "Failed to add Rule 2.\n");
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Time: Long",
        rule3,
        time_long
    )) {
        fprintf(stderr, "Failed to add Rule 3.\n");
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    FUZZY_PRINTF("\nRule activations:\n");
    fuzzy_rules_print(&rules);

    FUZZY_PRINTF("\nAggregated output:\n");

    float result = fuzzy_rules_cog(
        &rules,
        0.0f,
        60.0f,
        step
    );

    if (!fuzzy_rules_plot_cog(
        &rules,
        "svg/cog",
        "Center of Gravity Defuzzification",
        result,
        0.0f,
        60.0f,
        step
    )) {
        fprintf(
            stderr,
            "Failed to generate COG plot.\n"
        );
    }

    fuzzy_rules_free(&rules);

    return result;

}


/* ==========================================================
 * Optional membership-function plots
 * ========================================================== */

static bool plot_humidity(void)
{
    return FUZZY_PLOT(
        "svg/humidity",
        "Humidity Membership Functions",
        0.0f,
        30.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Small",
            "#ef4444",
            humidity_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Huge",
            "#3b82f6",
            humidity_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Huge",
            "#70f63b",
            humidity_high
        )
    );
}

static bool plot_temperature(void)
{
    return FUZZY_PLOT(
        "svg/temperature",
        "Temperature Membership Functions",
        0.0f,
        30.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#3b82f6",
            temp_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Medium",
            "#22c55e",
            temp_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            temp_high
        )
    );
}

static bool plot_time(void)
{
    return FUZZY_PLOT(
        "svg/time",
        "Watering-Time Membership Functions",
        0.0f,
        60.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Short",
            "#ef4444",
            time_short
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Medium",
            "#22c55e",
            time_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Long",
            "#3b82f6",
            time_long
        )
    );
}

static bool plot_membership_functions(void)
{
    if (!plot_humidity()) {
        fprintf(
            stderr,
            "Failed to generate humidity plot.\n"
        );

        return false;
    }

    if (!plot_temperature()) {
        fprintf(
            stderr,
            "Failed to generate temperature plot.\n"
        );

        return false;
    }

    if (!plot_time()) {
        fprintf(
            stderr,
            "Failed to generate time plot.\n"
        );

        return false;
    }

    FUZZY_PRINTF(
        "\nGenerated all water-time membership plots.\n"
    );

    return true;
}

/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    float temperature;
    float humidity;
    char prompt;
    float step = 0.01f;
    do {
        FUZZY_PRINTF("\nWater Time Fuzzy System\n");
        FUZZY_PRINTF("=======================\n");

        FUZZY_PRINTF("Enter the temperature (C): ");

        if (scanf("%f", &temperature) != 1) {
            fprintf(
                stderr,
                "Invalid temperature input.\n"
            );

            return 1;
        }

        FUZZY_PRINTF("Enter the humidity (%%): ");

        if (scanf("%f", &humidity) != 1) {
            fprintf(
                stderr,
                "Invalid humidity input.\n"
            );

            return 1;
        }

        float time = evaluate_time(
            temperature,
            humidity,
            step
        );

        printf(
            "\nWater time: %.5f\n",
            time
        );

        if (!plot_membership_functions()) {
            return 1;
        }

        FUZZY_PRINTF("\nPress Q to exit or any other key to continue(): ");

        if (scanf(" %c", &prompt) != 1) {
            fprintf(
                stderr,
                "Invalid menu input.\n"
            );

            return 1;
        }

    } while (
        prompt != 'q' &&
        prompt != 'Q'
    );

    FUZZY_PRINTF("\nProgram closed.\n");

    return 0;
}