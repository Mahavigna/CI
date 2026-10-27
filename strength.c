/*
 * Example paint-strength application for "fuzzy.h".
 *
 * This program determines paint strength from:
 *
 * - Mixture content
 * - Temperature
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
 * Mixture-content membership functions
 * ========================================================== */

static float mixture_content_small(float value)
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


static float mixture_content_huge(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        35.0,
        65.0,
        true
    );
}


/* ==========================================================
 * Temperature membership functions
 * ========================================================== */

static float temperature_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        30.0,
        false
    );
}


static float temperature_medium(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        20.0,
        35.0,
        65.0
    );
}


static float temperature_high(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        40.0,
        85.0,
        true
    );
}


/* ==========================================================
 * Strength membership functions
 * ========================================================== */

static float strength_little(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        10.0,
        35.0,
        false
    );
}


static float strength_fair(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        20.0,
        40.0,
        65.0,
        80.0
    );
}


static float strength_massive(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        60.0,
        85.0,
        true
    );
}


/* ==========================================================
 * Mamdani rule construction
 * ========================================================== */

static bool build_strength_rules(
    fuzzy_rules_t *rules,
    float mixture_content,
    float temperature
)
{
    if (rules == NULL) {
        return false;
    }

    /*
     * Rule 1:
     *
     * IF mixture content is small
     * AND temperature is low
     * THEN strength is little.
     */
    float rule1 = fuzzy_and(
        2,
        mixture_content_small(mixture_content),
        temperature_low(temperature)
    );

    /*
     * Rule 2:
     *
     * IF mixture content is huge
     * AND temperature is medium
     * THEN strength is fair.
     */
    float rule2 = fuzzy_and(
        2,
        mixture_content_huge(mixture_content),
        temperature_medium(temperature)
    );

    /*
     * Rule 3:
     *
     * IF mixture content is huge
     * OR temperature is high
     * THEN strength is massive.
     */
    float rule3 = fuzzy_or(
        2,
        mixture_content_huge(mixture_content),
        temperature_high(temperature)
    );

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Strength: Little",
        rule1,
        strength_little
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Strength: Fair",
        rule2,
        strength_fair
    )) {
        return false;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        rules,
        "Strength: Massive",
        rule3,
        strength_massive
    )) {
        return false;
    }

    return true;
}


/* ==========================================================
 * Pure COG evaluation
 *
 * This function performs no printing and creates no files.
 * It is safe for repeated use by FUZZY_COG_SWEEP().
 * ========================================================== */

static float evaluate_strength(
    float mixture_content,
    float temperature,
    float step
)
{
    fuzzy_rules_t rules =
        fuzzy_rules_create();

    if (!build_strength_rules(
        &rules,
        mixture_content,
        temperature
    )) {
        FUZZY_ERROR(
            "Failed to construct paint-strength rules.\n"
        );

        fuzzy_rules_free(&rules);

        return 0.0f;
    }

    float result = fuzzy_rules_cog(
        &rules,
        30.0f,
        100.0f,
        step
    );

    fuzzy_rules_free(&rules);

    return result;
}


/* ==========================================================
 * Plot one selected COG result
 *
 * This function is called only for the user's selected input.
 * It is not called during the complete COG sweep.
 * ========================================================== */

static bool plot_strength_cog(
    float mixture_content,
    float temperature,
    float step
)
{
    fuzzy_rules_t rules = fuzzy_rules_create();

    if (!build_strength_rules(
        &rules,
        mixture_content,
        temperature
    )) {
        FUZZY_ERROR(
            "Failed to construct paint-strength rules.\n"
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
        30.0f,
        100.0f,
        step
    );

    bool success = fuzzy_rules_plot_cog(
        &rules,
        "svg/cog",
        "Paint Strength COG Defuzzification",
        result,
        30.0f,
        100.0f,
        step
    );

    fuzzy_rules_free(
        &rules
    );

    return success;
}


/* ==========================================================
 * Membership-function plots
 * ========================================================== */

static bool plot_mixture_content(void)
{
    return FUZZY_PLOT(
        "svg/mixture_content",
        "Mixture Content Membership Functions",
        0.0f,
        100.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Small",
            "#ef4444",
            mixture_content_small
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Huge",
            "#3b82f6",
            mixture_content_huge
        )
    );
}


static bool plot_temperature(void)
{
    return FUZZY_PLOT(
        "svg/temperature",
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
            "Medium",
            "#22c55e",
            temperature_medium
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "High",
            "#ef4444",
            temperature_high
        )
    );
}


static bool plot_strength(void)
{
    return FUZZY_PLOT(
        "svg/strength",
        "Paint Strength Membership Functions",
        0.0f,
        100.0f,
        1.0f,

        FUZZY_PLOT_FUNCTION_NAMED(
            "Little",
            "#ef4444",
            strength_little
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Fair",
            "#22c55e",
            strength_fair
        ),

        FUZZY_PLOT_FUNCTION_NAMED(
            "Massive",
            "#3b82f6",
            strength_massive
        )
    );
}


static bool plot_membership_functions(void)
{
    if (!plot_mixture_content()) {
        FUZZY_ERROR(
            "Failed to generate mixture-content plot.\n"
        );

        return false;
    }

    if (!plot_temperature()) {
        FUZZY_ERROR(
            "Failed to generate temperature plot.\n"
        );

        return false;
    }

    if (!plot_strength()) {
        FUZZY_ERROR(
            "Failed to generate strength plot.\n"
        );

        return false;
    }

    FUZZY_PRINTF(
        "\nGenerated all paint-system membership plots.\n"
    );

    return true;
}


/* ==========================================================
 * COG sweep evaluator
 *
 * The dimension order must match the order passed into
 * FUZZY_COG_SWEEP().
 *
 * inputs[0] = mixture content
 * inputs[1] = temperature
 * ========================================================== */

static float evaluate_strength_sweep(
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

    return evaluate_strength(
        inputs[0],
        inputs[1],
        cog_step
    );
}


/* ==========================================================
 * Complete COG sweep
 * ========================================================== */

static bool plot_strength_sweep(void)
{
    /*
     * This single call generates:
     *
     * svg/paint_strength_cog_sweep.csv
     * svg/paint_strength_cog_sweep.svg
     *
     * SVG heatmap:
     *
     * X axis = mixture content
     * Y axis = temperature
     * Colour = defuzzified paint strength
     */
    return FUZZY_COG_SWEEP(
        "svg/paint_strength_cog_sweep",
        "Paint Strength COG Sweep",
        evaluate_strength_sweep,
        1.0f,

        FUZZY_SWEEP_DIMENSION(
            "Mixture content",
            0.0f,
            100.0f,
            2.0f
        ),

        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            100.0f,
            2.0f
        )
    );
}


/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    float temperature;
    float mixture_content;

    const float cog_step =
        1.0f;

    /*
     * Generate the complete paint-strength surface.
     *
     * With ranges 0-100 and sweep steps of 2:
     *
     * 51 mixture samples x 51 temperature samples
     * = 2601 COG evaluations.
     */
    if (!plot_strength_sweep()) {
        FUZZY_ERROR(
            "Failed to generate paint-strength COG sweep.\n"
        );

        return 1;
    }

    FUZZY_PRINTF(
        "\nGenerated paint-strength sweep files:\n"
        "  svg/paint_strength_cog_sweep.csv\n"
        "  svg/paint_strength_cog_sweep.svg\n"
    );

    /*
     * The membership functions are fixed, so their SVG files
     * need to be generated only once.
     */
    if (!plot_membership_functions()) {
        return 1;
    }

    FUZZY_PRINTF(
        "\nPaint Strength Fuzzy System\n"
        "===========================\n"
    );

    FUZZY_PRINTF(
        "Enter the mixture content: "
    );

    if (scanf(
        "%f",
        &mixture_content
    ) != 1) {
        FUZZY_ERROR(
            "Invalid mixture-content input.\n"
        );

        return 1;
    }

    FUZZY_PRINTF(
        "Enter the temperature (C): "
    );

    if (scanf(
        "%f",
        &temperature
    ) != 1) {
        FUZZY_ERROR(
            "Invalid temperature input.\n"
        );

        return 1;
    }

    float strength = evaluate_strength(
        mixture_content,
        temperature,
        cog_step
    );

    FUZZY_PRINTF(
        "\nPaint strength: %.5f\n",
        strength
    );

    /*
     * Generate one aggregated-output COG graph for the
     * user's selected mixture and temperature values.
     */
    if (!plot_strength_cog(
        mixture_content,
        temperature,
        cog_step
    )) {
        FUZZY_ERROR(
            "Failed to generate selected COG plot.\n"
        );

        return 1;
    }

    return 0;
}