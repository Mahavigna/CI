#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

FUZZY_VAR(speed_low,          FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(speed_medium,       FUZZY_SHAPE_TRAPEZOID, 1.0f, 20.0f, 40.0f, 60.0f, 80.0f)
FUZZY_VAR(speed_high,         FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 80.0f, true)

FUZZY_VAR(distance_close,     FUZZY_SHAPE_RAMP,      1.0f, 10.0f, 20.0f, false)
FUZZY_VAR(distance_medium,    FUZZY_SHAPE_TRAPEZOID, 1.0f, 10.0f, 20.0f, 30.0f, 40.0f)
FUZZY_VAR(distance_far,       FUZZY_SHAPE_TRAPEZOID, 1.0f, 30.0f, 40.0f, 50.0f, 70.0f)

FUZZY_VAR(brake_force_low,    FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(brake_force_medium, FUZZY_SHAPE_TRAPEZOID, 1.0f, 20.0f, 40.0f, 60.0f, 80.0f)
FUZZY_VAR(brake_force_high,   FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 75.0f, true)

static float brake(float speed, float distance, const char *plot)
{
    fuzzy_rules_t system;
    fuzzy_rules_t *rules = &system;
    fuzzy_rules_create(rules);

    RULE("Low OR Far -> Low",       SOR(speed_low(speed), distance_far(distance)), brake_force_low);
    RULE("Low AND Medium -> Low",   SAND(speed_low(speed), distance_medium(distance)), brake_force_low);
    RULE("Low AND Close -> Medium", SAND(speed_low(speed), distance_close(distance)), brake_force_medium);

    RULE("Medium OR Far -> Low",       SOR(speed_medium(speed), distance_far(distance)), brake_force_low);
    RULE("Medium AND Medium -> Medium", SAND(speed_medium(speed), distance_medium(distance)), brake_force_medium);
    RULE("Medium AND Close -> High",    SAND(speed_medium(speed), distance_close(distance)), brake_force_high);

    RULE("High OR Far -> Medium", SAND(speed_high(speed), distance_far(distance)), brake_force_medium);
    RULE("High AND Medium -> High", SAND(speed_high(speed), distance_medium(distance)), brake_force_high);
    RULE("High AND Close -> High", SAND(speed_high(speed), distance_close(distance)), brake_force_high);

    float force = fuzzy_rules_defuzzify(rules, 0.0f, 100.0f, 1.0f, FUZZY_DEFUZZ_COG);
    fuzzy_rules_plot_cog(rules, plot, "Brake Force COG", force, 0.0f, 100.0f, 1.0f);
    fuzzy_rules_free(rules);
    return force;
}

int main(void)
{
    PLOT("braking/speed", "Speed Membership Functions", 100.0f, 1.0f,
        SERIES(speed_low, "#3b82f6"),
        SERIES(speed_medium, "#22c55e"),
        SERIES(speed_high, "#ef4444"));

    PLOT("braking/distance", "Distance Membership Functions", 70.0f, 1.0f,
        SERIES(distance_close, "#3b82f6"),
        SERIES(distance_medium, "#22c55e"),
        SERIES(distance_far, "#ef4444"));

    PLOT("braking/brake_force", "Brake Force Membership Functions", 100.0f, 1.0f,
        SERIES(brake_force_low, "#3b82f6"),
        SERIES(brake_force_medium, "#22c55e"),
        SERIES(brake_force_high, "#ef4444"));

    float force1 = brake(60.0f, 25.0f, "braking/scenario_1_cog");
    float force2 = brake(10.0f, 50.0f, "braking/scenario_2_cog");

    printf("Speed 60 km/h, distance 25 m: %.2f%%\n", force1);
    printf("Speed 10 km/h, distance 50 m: %.2f%%\n", force2);
}