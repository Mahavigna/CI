#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

/*
 * User-defined hedge exponents.
 */
static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};


/* ==========================================================
 * Mixture content
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
 * Temperature
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
    float rising = fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        35.0,
        true
    );

    float falling = fuzzy_function(
        "ramp",
        value,
        hedges.none,
        35.0,
        65.0,
        false
    );

    return fuzzy_and(
        2,
        rising,
        falling
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
 * Strength
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
    float rising = fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        40.0,
        true
    );

    float falling = fuzzy_function(
        "ramp",
        value,
        hedges.none,
        65.0,
        80.0,
        false
    );

    return fuzzy_and(
        2,
        rising,
        falling
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
 * Mamdani rules
 * ========================================================== */

static float fuzzy_rules(
    float mixture_content,
    float temperature,
    float step
)
{
    float rule1 = fuzzy_and(
        2,
        mixture_content_small(mixture_content),
        temperature_low(temperature)
    );

    float rule2 = fuzzy_and(
        2,
        mixture_content_huge(mixture_content),
        temperature_medium(temperature)
    );

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

    fuzzy_rules_free(&rules);

    return result;
}


/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    float temperature;
    float mixture_content;

    printf("\nPaint Strength Fuzzy System\n");
    printf("---------------------------\n");

    printf("Enter the temperature (C): ");

    if (scanf("%f", &temperature) != 1) {
        fprintf(stderr, "Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the mixture content: ");

    if (scanf("%f", &mixture_content) != 1) {
        fprintf(stderr, "Invalid mixture-content input.\n");
        return 1;
    }

    float strength = fuzzy_rules(
        mixture_content,
        temperature,
        1.0f
    );

    printf(
        "\nPaint strength: %.5f\n",
        strength
    );

    return 0;
}