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
 * Humidity membership functions
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
 * Mamdani rule construction
 * ========================================================== */

static bool build_time_rules(
    fuzzy_rules_t *rules,
    float temperature,
    float humidity
)
{
    if (rules == NULL) {
        return false;
    }

    float rule1 = fuzzy_or(
        2,
        temp_low(temperature),
        humidity_medium(humidity)
    );

    float rule2 = fuzzy_and(
        2,
        humidity_medium(humidity),
        temp_medium(temperature)
    );

    float rule3 = fuzzy_or(
        2,
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
 * This function does not print rules and does not create SVG
 * files, so it is safe to call repeatedly during a sweep.
 * ========================================================== */

static float evaluate_time(
    float temperature,
    float humidity,
    float step
)
{
    fuzzy_rules_t rules =
        fuzzy_rules_create();

    if (!build_time_rules(
        &rules,
        temperature,
        humidity
    )) {
        FUZZY_ERROR(
            "Failed to construct watering-time rules.\n"
        );

        fuzzy_rules_free(&rules);

        return 0.0f;
    }

    float result = fuzzy_rules_cog(
        &rules,
        0.0f,
        60.0f,
        step
    );

    fuzzy_rules_free(&rules);

    return result;
}


/* ==========================================================
 * Plot one selected COG result
 *
 * This is called only for the values entered by the user.
 * It is not called by the multidimensional sweep.
 * ========================================================== */

static bool plot_time_cog(
    float temperature,
    float humidity,
    float step
)
{
    fuzzy_rules_t rules =
        fuzzy_rules_create();

    if (!build_time_rules(
        &rules,
        temperature,
        humidity
    )) {
        FUZZY_ERROR(
            "Failed to construct watering-time rules.\n"
        );

        fuzzy_rules_free(&rules);

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
        0.0f,
        60.0f,
        step
    );

    bool success = fuzzy_rules_plot_cog(
        &rules,
        "greenhouse/cog",
        "Center of Gravity Defuzzification",
        result,
        0.0f,
        60.0f,
        step
    );

    fuzzy_rules_free(
        &rules
    );

    return success;
}


/* ==========================================================
 * Optional membership-function plots
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
            "Failed to generate time plot.\n"
        );

        return false;
    }

    FUZZY_PRINTF(
        "\nGenerated all water-time membership plots.\n"
    );

    return true;
}

static float evaluate_time_sweep(
    const float inputs[],
    size_t input_count,
    float cog_step
)
{
    if (
        inputs == NULL ||
        input_count != 2
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
 * ========================================================== 
 * */


int main(void)
{
    float temperature;
    float humidity;
    char prompt;

    const float step = 0.01f;

    /*
     * Generate the complete temperature/humidity sweep once.
     */
    if (!plot_sweep()) {
        FUZZY_ERROR(
            "Failed to generate greenhouse COG sweep.\n"
        );

        return 1;
    }

    /*
     * Membership functions are fixed, so generate these
     * plots once instead of rewriting them every loop.
     */
    if (!plot_membership_functions()) {
        FUZZY_ERROR("Failed to generate greenhouse memebership fucntions`.\n");
        return 1;
    }

    do {
        FUZZY_PRINTF(
            "\nWater Time Fuzzy System\n"
            "=======================\n"
        );

        FUZZY_PRINTF(
            "Enter the temperature (C): "
        );

        if (scanf("%f", &temperature) != 1) {
            FUZZY_ERROR(
                "Invalid temperature input.\n"
            );

            return 1;
        }

        FUZZY_PRINTF(
            "Enter the humidity (%%): "
        );

        if (scanf("%f", &humidity) != 1) {
            FUZZY_ERROR(
                "Invalid humidity input.\n"
            );

            return 1;
        }

        float watering_time = evaluate_time(
            temperature,
            humidity,
            step
        );

        FUZZY_PRINTF(
            "\nWatering-time COG: %.5f\n",
            watering_time
        );

        /*
         * Generate one COG graph for the values entered
         * by the user, not for every sweep point.
         */
        if (!plot_time_cog(
            temperature,
            humidity,
            step
        )) {
            FUZZY_ERROR(
                "Failed to generate COG plot.\n"
            );

            return 1;
        }

        FUZZY_PRINTF(
            "\nPress Q to exit or any other "
            "character to continue: "
        );

        if (scanf(" %c", &prompt) != 1) {
            FUZZY_ERROR(
                "Invalid menu input.\n"
            );

            return 1;
        }

    } while (
        prompt != 'q' &&
        prompt != 'Q'
    );

    FUZZY_PRINTF(
        "\nProgram closed.\n"
    );

    return 0;
}