/*
 * Example greenhouse watering application for "fuzzy.h".
 *
 * This program determines watering time from:
 *
 * - Temperature
 * - Humidity
 *
 * The application also generates:
 *
 * - Membership-function SVG plots
 * - A selected COG SVG plot
 * - An N-dimensional COG sweep CSV
 * - An N-dimensional COG sweep SVG
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
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        10.0f,
        15.0f,
        false
    );
}

static float temp_medium(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRIANGLE,
        value,
        hedges.none,
        5.0f,
        15.0f,
        25.0f
    );
}

static float temp_high(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        15.0f,
        25.0f,
        true
    );
}

/* ==========================================================
 * Humidity membership functions
 * ========================================================== */

static float humidity_low(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        5.0f,
        10.0f,
        false
    );
}

static float humidity_medium(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRAPEZOID,
        value,
        hedges.none,
        5.0f,
        10.0f,
        20.0f,
        25.0f
    );
}

static float humidity_high(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        15.0f,
        25.0f,
        true
    );
}

/* ==========================================================
 * Watering-time membership functions
 * ========================================================== */

static float time_short(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRAPEZOID,
        value,
        hedges.none,
        0.0f,
        10.0f,
        20.0f,
        30.0f
    );
}

static float time_medium(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRIANGLE,
        value,
        hedges.none,
        15.0f,
        30.0f,
        45.0f
    );
}

static float time_long(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRAPEZOID,
        value,
        hedges.none,
        30.0f,
        40.0f,
        50.0f,
        60.0f
    );
}

/* ==========================================================
 * Mamdani rule construction
 * ========================================================== */

static bool build_time_rules(
    fuzzy_rules_t *rules,
    float temperature,
    float humidity
)
{
    float rule1;
    float rule2;
    float rule3;

    if (rules == NULL) {
        return false;
    }

    rule1 = fuzzy_or_method(
        FUZZY_LOGIC_STANDARD,
        temp_low(temperature),
        humidity_medium(humidity)
    );

    rule2 = fuzzy_and_method(
        FUZZY_LOGIC_STANDARD,
        humidity_medium(humidity),
        temp_medium(temperature)
    );

    rule3 = fuzzy_or_method(
        FUZZY_LOGIC_STANDARD,
        humidity_low(humidity),
        temp_high(temperature)
    );

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Time: Short",
        rule1,
        time_short
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Time: Medium",
        rule2,
        time_medium
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Time: Long",
        rule3,
        time_long
    )) {
        return false;
    }

    return true;
}

/* ==========================================================
 * Pure COG evaluation
 *
 * This function does not print rules or create files, so it
 * can be called repeatedly by the sweep evaluator.
 * ========================================================== */

static float evaluate_time(
    float temperature,
    float humidity,
    float step
)
{
    fuzzy_rules_t rules;
    float result;

    fuzzy_rules_create(&rules);

    if (!build_time_rules(
        &rules,
        temperature,
        humidity
    )) {
        fprintf(
            stderr,
            "Failed to construct watering-time rules.\n"
        );

        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    result = fuzzy_rules_defuzzify(
        &rules,
        0.0f,
        60.0f,
        step,
        FUZZY_DEFUZZ_COG
    );

    fuzzy_rules_free(&rules);
    return result;
}

/* ==========================================================
 * Plot one selected COG result
 * ========================================================== */

static bool plot_time_cog(
    float temperature,
    float humidity,
    float step
)
{
    fuzzy_rules_t rules;
    float result;
    bool success;

    fuzzy_rules_create(&rules);

    if (!build_time_rules(
        &rules,
        temperature,
        humidity
    )) {
        fprintf(
            stderr,
            "Failed to construct watering-time rules.\n"
        );

        fuzzy_rules_free(&rules);
        return false;
    }

    printf("\nRule activations:\n");
    fuzzy_rules_print(&rules);

    result = fuzzy_rules_defuzzify(
        &rules,
        0.0f,
        60.0f,
        step,
        FUZZY_DEFUZZ_COG
    );

    success = fuzzy_rules_plot_cog(
        &rules,
        "greenhouse/cog",
        "Center of Gravity Defuzzification",
        result,
        0.0f,
        60.0f,
        step
    );

    fuzzy_rules_free(&rules);
    return success;
}

/* ==========================================================
 * Membership-function plots
 * ========================================================== */

static bool plot_humidity(void)
{
    return FUZZY_PLOT(
        "greenhouse/humidity",
        "Humidity Membership Functions",
        0.0f,
        30.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Low",
            "#ef4444",
            humidity_low
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Medium",
            "#3b82f6",
            humidity_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#70f63b",
            humidity_high
        )
    );
}

static bool plot_temperature(void)
{
    return FUZZY_PLOT(
        "greenhouse/temperature",
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
        "greenhouse/time",
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
            "Failed to generate watering-time plot.\n"
        );
        return false;
    }

    printf(
        "\nGenerated all watering-time membership plots.\n"
    );

    return true;
}

/* ==========================================================
 * N-dimensional sweep adapter
 * ========================================================== */

static float evaluate_time_sweep(
    const float inputs[],
    size_t input_count,
    float cog_step
)
{
    if (
        inputs == NULL ||
        input_count != 2u
    ) {
        return 0.0f;
    }

    return evaluate_time(
        inputs[0],
        inputs[1],
        cog_step
    );
}

static bool plot_sweep(void)
{
    return FUZZY_COG_SWEEP(
        "greenhouse/greenhouse_cog_sweep",
        "Greenhouse Watering-Time COG Sweep",
        evaluate_time_sweep,
        0.1f,

        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            30.0f,
            1.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Humidity",
            0.0f,
            30.0f,
            1.0f
        )
    );
}

/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    float temperature;
    float humidity;
    float watering_time;
    char prompt;

    const float step = 0.01f;

    if (!plot_sweep()) {
        fprintf(
            stderr,
            "Failed to generate greenhouse COG sweep.\n"
        );
        return 1;
    }

    if (!plot_membership_functions()) {
        fprintf(
            stderr,
            "Failed to generate greenhouse membership functions.\n"
        );
        return 1;
    }

    do {
        printf(
            "\nWater Time Fuzzy System\n"
            "=======================\n"
        );

        printf("Enter the temperature (C): ");

        if (scanf("%f", &temperature) != 1) {
            fprintf(
                stderr,
                "Invalid temperature input.\n"
            );
            return 1;
        }

        printf("Enter the humidity (%%): ");

        if (scanf("%f", &humidity) != 1) {
            fprintf(
                stderr,
                "Invalid humidity input.\n"
            );
            return 1;
        }

        watering_time = evaluate_time(
            temperature,
            humidity,
            step
        );

        printf(
            "\nWatering-time COG: %.5f\n",
            watering_time
        );

        if (!plot_time_cog(
            temperature,
            humidity,
            step
        )) {
            fprintf(
                stderr,
                "Failed to generate COG plot.\n"
            );
            return 1;
        }

        printf(
            "\nPress Q to exit or any other "
            "character to continue: "
        );

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

    printf("\nProgram closed.\n");
    return 0;
}
