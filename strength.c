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
 * Mixture content membership functions
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
 * Mamdani rule evaluation
 * ========================================================== */

static float evaluate_strength(
    float mixture_content,
    float temperature,
    float step
)
{
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

    fuzzy_rules_t rules = fuzzy_rules_create();

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Strength: Little",
        rule1,
        strength_little
    )) {
        fprintf(stderr, "Failed to add Rule 1.\n");
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Strength: Fair",
        rule2,
        strength_fair
    )) {
        fprintf(stderr, "Failed to add Rule 2.\n");
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Strength: Massive",
        rule3,
        strength_massive
    )) {
        fprintf(stderr, "Failed to add Rule 3.\n");
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    printf("\nRule activations:\n");
    fuzzy_rules_print(&rules);

    printf("\nAggregated output:\n");

    float result = fuzzy_rules_cog(
        &rules,
        30.0f,
        100.0f,
        step
    );

    if (!fuzzy_rules_plot_cog(
        &rules,
        "svg/cog",
        "Center of Gravity Defuzzification",
        result,
        30.0f,
        100.0f,
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

    printf(
        "\nGenerated all paint-system membership plots.\n"
    );

    return true;
}

/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    float temperature;
    float mixture_content;

    printf("\nPaint Strength Fuzzy System\n");
    printf("===========================\n");

    printf("Enter the temperature (C): ");

    if (scanf("%f", &temperature) != 1) {
        fprintf(
            stderr,
            "Invalid temperature input.\n"
        );

        return 1;
    }

    printf("Enter the mixture content: ");

    if (scanf("%f", &mixture_content) != 1) {
        fprintf(
            stderr,
            "Invalid mixture-content input.\n"
        );

        return 1;
    }

    float strength = evaluate_strength(
        mixture_content,
        temperature,
        1.0f
    );

    printf(
        "\nPaint strength: %.5f\n",
        strength
    );

    if (!plot_membership_functions()) {
        return 1;
    }

    return 0;
}