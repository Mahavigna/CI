#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

FUZZY_VAR(speed_low,    FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(speed_medium, FUZZY_SHAPE_TRAPEZOID, 1.0f, 20.0f, 40.0f, 60.0f, 80.0f)
FUZZY_VAR(speed_high,   FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 80.0f, true)

FUZZY_VAR(distance_close,  FUZZY_SHAPE_RAMP,      1.0f, 10.0f, 20.0f, false)
FUZZY_VAR(distance_medium, FUZZY_SHAPE_TRAPEZOID, 1.0f, 10.0f, 20.0f, 30.0f, 40.0f)
FUZZY_VAR(distance_far,    FUZZY_SHAPE_TRAPEZOID, 1.0f, 30.0f, 40.0f, 50.0f, 70.0f)

FUZZY_VAR(brake_force_low,    FUZZY_SHAPE_ZMF,      1.0f, 20.0f, 40.0f)
FUZZY_VAR(brake_force_medium, FUZZY_SHAPE_TRIANGLE, 1.0f, 30.0f, 65.0f, 90.0f)
FUZZY_VAR(brake_force_high,   FUZZY_SHAPE_SMF,      1.0f, 60.0f, 75.0f)

static float brake(float speed, float distance, int scenario, const char *plot)
{
    fuzzy_rules_t normal;
    fuzzy_rules_t emergency;

    normal.count = 0;
    emergency.count = 0;

    /* Normal braking: 9 rules */

    RULE(normal, "Low AND Far -> Low",
        SAND(speed_low(speed), distance_far(distance)),
        brake_force_low);

    RULE(normal, "Low AND Medium -> Low",
        SAND(speed_low(speed), distance_medium(distance)),
        brake_force_low);

    RULE(normal, "Low AND Close -> Medium",
        SAND(speed_low(speed), distance_close(distance)),
        brake_force_medium);

    RULE(normal, "Medium AND Far -> Low",
        SAND(speed_medium(speed), distance_far(distance)),
        brake_force_low);

    RULE(normal, "Medium AND Medium -> Medium",
        SAND(speed_medium(speed), distance_medium(distance)),
        brake_force_medium);

    RULE(normal, "Medium AND Close -> High",
        SAND(speed_medium(speed), distance_close(distance)),
        brake_force_high);

    RULE(normal, "High AND Far -> Medium",
        SAND(speed_high(speed), distance_far(distance)),
        brake_force_medium);

    RULE(normal, "High AND Medium -> High",
        SAND(speed_high(speed), distance_medium(distance)),
        brake_force_high);

    RULE(normal, "High AND Close -> High",
        SAND(speed_high(speed), distance_close(distance)),
        brake_force_high);


    /* Emergency braking: only 3 aggressive rules */

    RULE(emergency, "Any Low Speed -> Medium",
        speed_low(speed),
        brake_force_medium);

    RULE(emergency, "Any Medium Speed -> High",
        speed_medium(speed),
        brake_force_high);

    RULE(emergency, "Any High Speed -> High",
        speed_high(speed),
        brake_force_high);

    //Smart Lightweight Switching between normal and emergency braking based on scenario, Only for ppl who get C!
    fuzzy_rules_t *system = scenario == 1 ? &normal : &emergency;

    if (plot)
        fuzzy_rules_print(system);

    float force = fuzzy_rules_defuzzify(
        system,
        0.0f,
        100.0f,
        1.0f,
        FUZZY_DEFUZZ_COG);

    fuzzy_rules_plot_cog(
        system,
        plot,
        "Brake Force COG",
        force,
        0.0f,
        100.0f,
        1.0f);

    return force;
}

SWEEP_EVALUATOR(brake_sweep_evaluator, brake, inputs[0], inputs[1], 1, NULL)
SWEEP_EVALUATOR(brake_sweep_evaluator_2, brake, inputs[0], inputs[1], 2, NULL)


int main(void)
{

    FUZZY_COG_SWEEP(
        "braking/_braking_process_sweep",
        "Speed, Distance vs Brake Force Output",
        brake_sweep_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION("Speed", 0.0f, 100.0f, 1.0f),
        FUZZY_SWEEP_DIMENSION("Distance", 0.0f, 100.0f, 1.0f),);
    
    FUZZY_COG_SWEEP(
        "braking/_braking_process_sweep_2",
        "Speed, Distance vs Brake Force Output",
        brake_sweep_evaluator_2,
        0.1f,
        FUZZY_SWEEP_DIMENSION("Speed", 0.0f, 100.0f, 1.0f),
        FUZZY_SWEEP_DIMENSION("Distance", 0.0f, 100.0f, 1.0f),);

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

    float force1 = brake(60.0f, 25.0f, 1, "braking/scenario_1_cog");
    float force2 = brake(10.0f, 50.0f, 2, "braking/scenario_2_cog");

    printf("Speed 60 km/h, distance 25 m: %.2f%%\n", force1);
    printf("Speed 10 km/h, distance 50 m: %.2f%%\n", force2);
}