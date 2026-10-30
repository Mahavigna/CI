#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

FUZZY_VAR(mixture_content_small, FUZZY_SHAPE_RAMP, 1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(mixture_content_huge,  FUZZY_SHAPE_RAMP, 1.0f, 35.0f, 65.0f, true)

FUZZY_VAR(temperature_low,    FUZZY_SHAPE_RAMP,     1.0f, 20.0f, 30.0f, false)
FUZZY_VAR(temperature_medium, FUZZY_SHAPE_TRIANGLE, 1.0f, 20.0f, 35.0f, 65.0f)
FUZZY_VAR(temperature_high,   FUZZY_SHAPE_RAMP,     1.0f, 40.0f, 85.0f, true)

FUZZY_VAR(strength_little,  FUZZY_SHAPE_RAMP,      1.0f, 10.0f, 35.0f, false)
FUZZY_VAR(strength_fair,    FUZZY_SHAPE_TRAPEZOID, 1.0f, 20.0f, 40.0f, 65.0f, 80.0f)
FUZZY_VAR(strength_massive, FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 85.0f, true)

static void build_rules(fuzzy_rules_t *rules, float mixture, float temperature)
{
    RULE("Strength: Little",
        SAND(mixture_content_small(mixture), temperature_low(temperature)),
        strength_little);

    RULE("Strength: Fair",
        SAND(mixture_content_huge(mixture), temperature_medium(temperature)),
        strength_fair);

    RULE("Strength: Massive",
        SOR(mixture_content_huge(mixture), temperature_high(temperature)),
        strength_massive);
}

static float paint_strength(float mixture, float temperature, float step, const char *plot)
{
    fuzzy_rules_t system;
    fuzzy_rules_t *rules = &system;
    fuzzy_rules_create(rules);
    build_rules(rules, mixture, temperature);

    float result = fuzzy_rules_defuzzify(
        rules, 30.0f, 100.0f, step, FUZZY_DEFUZZ_COG
    );

    if (plot) {
        fuzzy_rules_print(rules);
        fuzzy_rules_plot_cog(
            rules, plot, "Paint Strength COG Defuzzification",
            result, 30.0f, 100.0f, step
        );
    }

    fuzzy_rules_free(rules);
    return result;
}

static float sweep(const float inputs[], size_t count, float step)
{
    (void)count;
    return paint_strength(inputs[0], inputs[1], step, NULL);
}

int main(void)
{
    float mixture, temperature;

    PLOT("strength/mixture_content", "Mixture Content Membership Functions", 100.0f, 1.0f,
        SERIES(mixture_content_small, "#ef4444"),
        SERIES(mixture_content_huge, "#3b82f6"));

    PLOT("strength/temperature", "Temperature Membership Functions", 100.0f, 1.0f,
        SERIES(temperature_low, "#3b82f6"),
        SERIES(temperature_medium, "#22c55e"),
        SERIES(temperature_high, "#ef4444"));

    PLOT("strength/strength", "Paint Strength Membership Functions", 100.0f, 1.0f,
        SERIES(strength_little, "#ef4444"),
        SERIES(strength_fair, "#22c55e"),
        SERIES(strength_massive, "#3b82f6"));

    FUZZY_COG_SWEEP(
        "strength/paint_strength_cog_sweep",
        "Paint Strength COG Sweep",
        sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Mixture content", 0.0f, 100.0f, 2.0f),
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 2.0f)
    );

    printf("\nPaint Strength Fuzzy System\n===========================\n");
    printf("Enter the mixture content: ");
    scanf("%f", &mixture);

    printf("Enter the temperature (C): ");
    scanf("%f", &temperature);

    float result = paint_strength(mixture, temperature, 1.0f, "strength/cog");
    printf("\nPaint strength: %.5f\n", result);
}