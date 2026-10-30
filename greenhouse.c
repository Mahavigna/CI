#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

FUZZY_VAR(temp_low,    FUZZY_SHAPE_RAMP,     1.0f, 10.0f, 15.0f, false)
FUZZY_VAR(temp_medium, FUZZY_SHAPE_TRIANGLE, 1.0f, 5.0f, 15.0f, 25.0f)
FUZZY_VAR(temp_high,   FUZZY_SHAPE_RAMP,     1.0f, 15.0f, 25.0f, true)

FUZZY_VAR(humidity_low,    FUZZY_SHAPE_RAMP,      1.0f, 5.0f, 10.0f, false)
FUZZY_VAR(humidity_medium, FUZZY_SHAPE_TRAPEZOID, 1.0f, 5.0f, 10.0f, 20.0f, 25.0f)
FUZZY_VAR(humidity_high,   FUZZY_SHAPE_RAMP,      1.0f, 15.0f, 25.0f, true)

FUZZY_VAR(time_short,  FUZZY_SHAPE_TRAPEZOID, 1.0f, 0.0f, 10.0f, 20.0f, 30.0f)
FUZZY_VAR(time_medium, FUZZY_SHAPE_TRIANGLE,  1.0f, 15.0f, 30.0f, 45.0f)
FUZZY_VAR(time_long,   FUZZY_SHAPE_TRAPEZOID, 1.0f, 30.0f, 40.0f, 50.0f, 60.0f)

static void build_rules(fuzzy_rules_t *rules, float temperature, float humidity)
{
    RULE("Time: Short", SOR(temp_low(temperature), humidity_medium(humidity)), time_short);
    RULE("Time: Medium", SAND(humidity_medium(humidity), temp_medium(temperature)), time_medium);
    RULE("Time: Long", SOR(humidity_low(humidity), temp_high(temperature)), time_long);
}

static float watering(float temperature, float humidity, float step, const char *plot)
{
    fuzzy_rules_t system;
    fuzzy_rules_t *rules = &system;
    fuzzy_rules_create(rules);
    build_rules(rules, temperature, humidity);

    float result = fuzzy_rules_defuzzify(rules, 0.0f, 60.0f, step, FUZZY_DEFUZZ_COG);

    if (plot) {
        fuzzy_rules_print(rules);
        fuzzy_rules_plot_cog(
            rules, plot, "Center of Gravity Defuzzification",
            result, 0.0f, 60.0f, step
        );
    }

    fuzzy_rules_free(rules);
    return result;
}

static float sweep(const float inputs[], size_t count, float step)
{
    (void)count;
    return watering(inputs[0], inputs[1], step, NULL);
}

int main(void)
{
    float temperature, humidity;

    PLOT("greenhouse/humidity", "Humidity Membership Functions", 30.0f, 1.0f,
        SERIES(humidity_low, "#ef4444"),
        SERIES(humidity_medium, "#3b82f6"),
        SERIES(humidity_high, "#70f63b"));

    PLOT("greenhouse/temperature", "Temperature Membership Functions", 30.0f, 1.0f,
        SERIES(temp_low, "#3b82f6"),
        SERIES(temp_medium, "#22c55e"),
        SERIES(temp_high, "#ef4444"));

    PLOT("greenhouse/time", "Watering-Time Membership Functions", 60.0f, 1.0f,
        SERIES(time_short, "#ef4444"),
        SERIES(time_medium, "#22c55e"),
        SERIES(time_long, "#3b82f6"));

    FUZZY_COG_SWEEP(
        "greenhouse/greenhouse_cog_sweep",
        "Greenhouse Watering-Time COG Sweep",
        sweep,
        0.1f,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 30.0f, 1.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 30.0f, 1.0f)
    );

        printf("\nWater Time Fuzzy System\n=======================\n");
        printf("Enter the temperature (C): ");
        scanf("%f", &temperature);

        printf("Enter the humidity (%%): ");
        scanf("%f", &humidity);

        float result = watering(temperature, humidity, 0.01f, "greenhouse/cog");
        printf("\nWatering-time COG: %.5f\n", result);


    printf("\nProgram closed.\n");
}