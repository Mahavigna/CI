/*
 * Example paint-strength application for "fuzzy.h".
 *
 * This program determines paint strength from mixture content and
 * temperature. It also generates membership plots, a selected COG
 * plot, and a two-dimensional COG sweep in CSV and SVG formats.
 */

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

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
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        20.0f,
        40.0f,
        false
    );
}

static float mixture_content_huge(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        35.0f,
        65.0f,
        true
    );
}

/* ==========================================================
 * Temperature membership functions
 * ========================================================== */

static float temperature_low(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        20.0f,
        30.0f,
        false
    );
}

static float temperature_medium(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRIANGLE,
        value,
        hedges.none,
        20.0f,
        35.0f,
        65.0f
    );
}

static float temperature_high(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        40.0f,
        85.0f,
        true
    );
}

/* ==========================================================
 * Strength membership functions
 * ========================================================== */

static float strength_little(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        10.0f,
        35.0f,
        false
    );
}

static float strength_fair(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_TRAPEZOID,
        value,
        hedges.none,
        20.0f,
        40.0f,
        65.0f,
        80.0f
    );
}

static float strength_massive(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        60.0f,
        85.0f,
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
    float rule1;
    float rule2;
    float rule3;

    if (rules == NULL) {
        return false;
    }

    rule1 = fuzzy_and_method(
        FUZZY_LOGIC_STANDARD,
        mixture_content_small(mixture_content),
        temperature_low(temperature)
    );

    rule2 = fuzzy_and_method(
        FUZZY_LOGIC_STANDARD,
        mixture_content_huge(mixture_content),
        temperature_medium(temperature)
    );

    rule3 = fuzzy_or_method(
        FUZZY_LOGIC_STANDARD,
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
 * ========================================================== */

static float evaluate_strength(
    float mixture_content,
    float temperature,
    float step
)
{
    fuzzy_rules_t rules;
    float result;

    fuzzy_rules_create(&rules);

    if (!build_strength_rules(
        &rules,
        mixture_content,
        temperature
    )) {
        fprintf(
            stderr,
            "Failed to construct paint-strength rules.\n"
        );

        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    result = fuzzy_rules_defuzzify(
        &rules,
        30.0f,
        100.0f,
        step,
        FUZZY_DEFUZZ_COG
    );

    fuzzy_rules_free(&rules);
    return result;
}

/* ==========================================================
 * Selected COG plot
 * ========================================================== */

static bool plot_strength_cog(
    float mixture_content,
    float temperature,
    float step
)
{
    fuzzy_rules_t rules;
    float result;
    bool success;

    fuzzy_rules_create(&rules);

    if (!build_strength_rules(
        &rules,
        mixture_content,
        temperature
    )) {
        fprintf(
            stderr,
            "Failed to construct paint-strength rules.\n"
        );

        fuzzy_rules_free(&rules);
        return false;
    }

    printf("\nRule activations:\n");
    fuzzy_rules_print(&rules);

    result = fuzzy_rules_defuzzify(
        &rules,
        30.0f,
        100.0f,
        step,
        FUZZY_DEFUZZ_COG
    );

    success = fuzzy_rules_plot_cog(
        &rules,
        "strength/cog",
        "Paint Strength COG Defuzzification",
        result,
        30.0f,
        100.0f,
        step
    );

    fuzzy_rules_free(&rules);
    return success;
}

/* ==========================================================
 * Membership-function plots
 * ========================================================== */

static bool plot_mixture_content(void)
{
    return FUZZY_PLOT(
        "strength/mixture_content",
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
        "strength/temperature",
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
        "strength/strength",
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
        fprintf(
            stderr,
            "Failed to generate mixture-content plot.\n"
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

    if (!plot_strength()) {
        fprintf(
            stderr,
            "Failed to generate strength plot.\n"
        );
        return false;
    }

    printf("\nGenerated all paint-system membership plots.\n");
    return true;
}

/* ==========================================================
 * COG sweep
 * ========================================================== */

static float evaluate_strength_sweep(
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

    return evaluate_strength(
        inputs[0],
        inputs[1],
        cog_step
    );
}

static bool plot_strength_sweep(void)
{
    return FUZZY_COG_SWEEP(
        "strength/paint_strength_cog_sweep",
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
    float strength;

    const float cog_step = 1.0f;

    if (!plot_strength_sweep()) {
        fprintf(
            stderr,
            "Failed to generate paint-strength COG sweep.\n"
        );
        return 1;
    }

    printf(
        "\nGenerated paint-strength sweep files:\n"
        " strength/paint_strength_cog_sweep.csv\n"
        " strength/paint_strength_cog_sweep.svg\n"
    );

    if (!plot_membership_functions()) {
        return 1;
    }

    printf(
        "\nPaint Strength Fuzzy System\n"
        "===========================\n"
    );

    printf("Enter the mixture content: ");

    if (scanf("%f", &mixture_content) != 1) {
        fprintf(
            stderr,
            "Invalid mixture-content input.\n"
        );
        return 1;
    }

    printf("Enter the temperature (C): ");

    if (scanf("%f", &temperature) != 1) {
        fprintf(
            stderr,
            "Invalid temperature input.\n"
        );
        return 1;
    }

    strength = evaluate_strength(
        mixture_content,
        temperature,
        cog_step
    );

    printf(
        "\nPaint strength: %.5f\n",
        strength
    );

    if (!plot_strength_cog(
        mixture_content,
        temperature,
        cog_step
    )) {
        fprintf(
            stderr,
            "Failed to generate selected COG plot.\n"
        );
        return 1;
    }

    return 0;
}
