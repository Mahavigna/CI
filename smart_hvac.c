#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

/* ============================================================================
 * 5 Membership Inputs
 * ============================================================================ */

/* Input 1: Indoor Temperature (0 - 50 C) */
FUZZY_VAR(temp_cold,        FUZZY_SHAPE_RAMP,      1.0f, 15.0f, 22.0f, false)
FUZZY_VAR(temp_comfortable, FUZZY_SHAPE_TRIANGLE,  1.0f, 18.0f, 24.0f, 30.0f)
FUZZY_VAR(temp_hot,         FUZZY_SHAPE_RAMP,      1.0f, 26.0f, 35.0f, true)

/* Input 2: Indoor Humidity (0 - 100 %) */
FUZZY_VAR(humidity_dry,     FUZZY_SHAPE_RAMP,      1.0f, 25.0f, 40.0f, false)
FUZZY_VAR(humidity_optimal, FUZZY_SHAPE_TRAPEZOID, 1.0f, 30.0f, 45.0f, 55.0f, 70.0f)
FUZZY_VAR(humidity_humid,   FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 80.0f, true)

/* Input 3: CO2 Concentration Index (0 - 100 %) */
FUZZY_VAR(co2_low,          FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(co2_moderate,     FUZZY_SHAPE_TRIANGLE,  1.0f, 30.0f, 50.0f, 70.0f)
FUZZY_VAR(co2_high,         FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 85.0f, true)

/* Input 4: Room Occupancy (0 - 100 %) */
FUZZY_VAR(occupancy_empty,    FUZZY_SHAPE_RAMP,      1.0f, 10.0f, 30.0f, false)
FUZZY_VAR(occupancy_moderate, FUZZY_SHAPE_TRAPEZOID, 1.0f, 20.0f, 40.0f, 60.0f, 80.0f)
FUZZY_VAR(occupancy_crowded,  FUZZY_SHAPE_RAMP,      1.0f, 65.0f, 85.0f, true)

/* Input 5: Outside Temperature (0 - 50 C) */
FUZZY_VAR(outside_cold,     FUZZY_SHAPE_RAMP,      1.0f, 10.0f, 20.0f, false)
FUZZY_VAR(outside_mild,     FUZZY_SHAPE_TRIANGLE,  1.0f, 15.0f, 25.0f, 35.0f)
FUZZY_VAR(outside_hot,      FUZZY_SHAPE_RAMP,      1.0f, 30.0f, 40.0f, true)

/* ============================================================================
 * 3 Membership Outputs
 * ============================================================================ */

/* Output 1: Fan Speed (0 - 100 %) */
FUZZY_VAR(fan_low,          FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(fan_medium,       FUZZY_SHAPE_TRAPEZOID, 1.0f, 25.0f, 40.0f, 60.0f, 75.0f)
FUZZY_VAR(fan_high,         FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 85.0f, true)

/* Output 2: Cooling Power (0 - 100 %) */
FUZZY_VAR(cooling_low,      FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(cooling_medium,   FUZZY_SHAPE_TRIANGLE,  1.0f, 25.0f, 50.0f, 75.0f)
FUZZY_VAR(cooling_high,     FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 85.0f, true)

/* Output 3: Fresh-Air Ventilation Damper (0 - 100 %) */
FUZZY_VAR(vent_low,         FUZZY_SHAPE_RAMP,      1.0f, 20.0f, 40.0f, false)
FUZZY_VAR(vent_medium,      FUZZY_SHAPE_TRAPEZOID, 1.0f, 25.0f, 40.0f, 60.0f, 75.0f)
FUZZY_VAR(vent_high,        FUZZY_SHAPE_RAMP,      1.0f, 60.0f, 85.0f, true)

/* ============================================================================
 * Inference & Defuzzification Functions (Mamdani COG and BOA)
 * ============================================================================ */

static float eval_fan_speed(
    float temp,
    float humidity,
    float co2,
    float occupancy,
    float outside,
    float step,
    fuzzy_defuzz_method_t method,
    const char *plot,
    const char *plot_title
)
{
    fuzzy_rules_t rules;
    rules.count = 0;

    RULE(rules, "Fan Low: Cold & Empty",
        SAND(temp_cold(temp), occupancy_empty(occupancy)),
        fan_low);
    RULE(rules, "Fan Low: Comfortable & Optimal Humidity & Low CO2",
        SAND(temp_comfortable(temp), humidity_optimal(humidity), co2_low(co2)),
        fan_low);
    RULE(rules, "Fan Medium: Comfortable & Moderate Occupancy",
        SAND(temp_comfortable(temp), occupancy_moderate(occupancy)),
        fan_medium);
    RULE(rules, "Fan Medium: Humid OR Moderate CO2",
        SOR(humidity_humid(humidity), co2_moderate(co2)),
        fan_medium);
    RULE(rules, "Fan High: Hot OR High CO2",
        SOR(temp_hot(temp), co2_high(co2)),
        fan_high);
    RULE(rules, "Fan High: Crowded & Outside Hot",
        SAND(occupancy_crowded(occupancy), outside_hot(outside)),
        fan_high);

    float result = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, step, method);

    if (plot) {
        fuzzy_rules_print(&rules);
        fuzzy_rules_plot_cog(&rules, plot, plot_title, result, 0.0f, 100.0f, step);
    }

    return result;
}

static float eval_cooling_power(
    float temp,
    float humidity,
    float co2,
    float occupancy,
    float outside,
    float step,
    fuzzy_defuzz_method_t method,
    const char *plot,
    const char *plot_title
)
{
    fuzzy_rules_t rules;
    rules.count = 0;

    RULE(rules, "Cooling Low: Cold OR Outside Cold",
        SOR(temp_cold(temp), outside_cold(outside)),
        cooling_low);
    RULE(rules, "Cooling Low: Comfortable & Empty",
        SAND(temp_comfortable(temp), occupancy_empty(occupancy)),
        cooling_low);
    RULE(rules, "Cooling Medium: Comfortable & Humid",
        SAND(temp_comfortable(temp), humidity_humid(humidity)),
        cooling_medium);
    RULE(rules, "Cooling Medium: Mild Outside & Moderate Occupancy",
        SAND(outside_mild(outside), occupancy_moderate(occupancy)),
        cooling_medium);
    RULE(rules, "Cooling High: Hot & (Outside Hot OR Crowded)",
        SAND(temp_hot(temp), SOR(outside_hot(outside), occupancy_crowded(occupancy))),
        cooling_high);
    RULE(rules, "Cooling High: Hot & Humid & High CO2",
        SAND(temp_hot(temp), humidity_humid(humidity), co2_high(co2)),
        cooling_high);

    float result = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, step, method);

    if (plot) {
        fuzzy_rules_print(&rules);
        fuzzy_rules_plot_cog(&rules, plot, plot_title, result, 0.0f, 100.0f, step);
    }

    return result;
}

static float eval_ventilation(
    float temp,
    float humidity,
    float co2,
    float occupancy,
    float outside,
    float step,
    fuzzy_defuzz_method_t method,
    const char *plot,
    const char *plot_title
)
{
    fuzzy_rules_t rules;
    rules.count = 0;

    RULE(rules, "Vent Low: Low CO2 & Empty",
        SAND(co2_low(co2), occupancy_empty(occupancy)),
        vent_low);
    RULE(rules, "Vent Low: Dry & Outside Cold",
        SAND(humidity_dry(humidity), outside_cold(outside)),
        vent_low);
    RULE(rules, "Vent Medium: Moderate CO2 & Moderate Occupancy",
        SAND(co2_moderate(co2), occupancy_moderate(occupancy)),
        vent_medium);
    RULE(rules, "Vent Medium: Outside Mild & Comfortable",
        SAND(outside_mild(outside), temp_comfortable(temp)),
        vent_medium);
    RULE(rules, "Vent High: High CO2 OR Crowded",
        SOR(co2_high(co2), occupancy_crowded(occupancy)),
        vent_high);
    RULE(rules, "Vent High: Humid & Hot",
        SAND(humidity_humid(humidity), temp_hot(temp)),
        vent_high);

    float result = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, step, method);

    if (plot) {
        fuzzy_rules_print(&rules);
        fuzzy_rules_plot_cog(&rules, plot, plot_title, result, 0.0f, 100.0f, step);
    }

    return result;
}

/* ============================================================================
 * 5-Input Sweep Evaluators (Mamdani COG and BOA for all 3 outputs)
 * ============================================================================ */

SWEEP_EVALUATOR(
    fan_mamdani_sweep,
    eval_fan_speed,
    inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
    cog_step, FUZZY_DEFUZZ_COG, NULL, NULL
)

SWEEP_EVALUATOR(
    fan_boa_sweep,
    eval_fan_speed,
    inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
    cog_step, FUZZY_DEFUZZ_BOA, NULL, NULL
)

SWEEP_EVALUATOR(
    cooling_mamdani_sweep,
    eval_cooling_power,
    inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
    cog_step, FUZZY_DEFUZZ_COG, NULL, NULL
)

SWEEP_EVALUATOR(
    cooling_boa_sweep,
    eval_cooling_power,
    inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
    cog_step, FUZZY_DEFUZZ_BOA, NULL, NULL
)

SWEEP_EVALUATOR(
    vent_mamdani_sweep,
    eval_ventilation,
    inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
    cog_step, FUZZY_DEFUZZ_COG, NULL, NULL
)

SWEEP_EVALUATOR(
    vent_boa_sweep,
    eval_ventilation,
    inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
    cog_step, FUZZY_DEFUZZ_BOA, NULL, NULL
)

int main(void)
{
    /* 1. Plot all 5 Input Membership Functions */
    PLOT("smart_hvac/input_1_temperature", "Indoor Temperature Membership Functions", 50.0f, 0.5f,
        SERIES(temp_cold, "#3b82f6"),
        SERIES(temp_comfortable, "#22c55e"),
        SERIES(temp_hot, "#ef4444"));

    PLOT("smart_hvac/input_2_humidity", "Indoor Humidity Membership Functions", 100.0f, 1.0f,
        SERIES(humidity_dry, "#f59e0b"),
        SERIES(humidity_optimal, "#22c55e"),
        SERIES(humidity_humid, "#3b82f6"));

    PLOT("smart_hvac/input_3_co2", "CO2 Concentration Index Membership Functions", 100.0f, 1.0f,
        SERIES(co2_low, "#22c55e"),
        SERIES(co2_moderate, "#f59e0b"),
        SERIES(co2_high, "#ef4444"));

    PLOT("smart_hvac/input_4_occupancy", "Room Occupancy Membership Functions", 100.0f, 1.0f,
        SERIES(occupancy_empty, "#3b82f6"),
        SERIES(occupancy_moderate, "#22c55e"),
        SERIES(occupancy_crowded, "#ef4444"));

    PLOT("smart_hvac/input_5_outside_temp", "Outside Temperature Membership Functions", 50.0f, 0.5f,
        SERIES(outside_cold, "#3b82f6"),
        SERIES(outside_mild, "#22c55e"),
        SERIES(outside_hot, "#ef4444"));

    /* 2. Plot all 3 Output Membership Functions */
    PLOT("smart_hvac/output_1_fan_speed", "Fan Speed Membership Functions", 100.0f, 1.0f,
        SERIES(fan_low, "#3b82f6"),
        SERIES(fan_medium, "#22c55e"),
        SERIES(fan_high, "#ef4444"));

    PLOT("smart_hvac/output_2_cooling_power", "Cooling Power Membership Functions", 100.0f, 1.0f,
        SERIES(cooling_low, "#3b82f6"),
        SERIES(cooling_medium, "#22c55e"),
        SERIES(cooling_high, "#ef4444"));

    PLOT("smart_hvac/output_3_ventilation", "Fresh-Air Ventilation Membership Functions", 100.0f, 1.0f,
        SERIES(vent_low, "#3b82f6"),
        SERIES(vent_medium, "#22c55e"),
        SERIES(vent_high, "#ef4444"));

    /* 3. Sweeps of all 5 inputs for all 3 outputs (Mamdani COG and BOA) */
    FUZZY_COG_SWEEP(
        "smart_hvac/sweep_fan_mamdani_cog",
        "Fan Speed 5-Input Sweep (Mamdani COG)",
        fan_mamdani_sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Indoor Temp", 0.0f, 50.0f, 25.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("CO2 Index", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Occupancy", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Outside Temp", 0.0f, 50.0f, 25.0f)
    );

    FUZZY_COG_SWEEP(
        "smart_hvac/sweep_fan_boa",
        "Fan Speed 5-Input Sweep (BOA)",
        fan_boa_sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Indoor Temp", 0.0f, 50.0f, 25.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("CO2 Index", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Occupancy", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Outside Temp", 0.0f, 50.0f, 25.0f)
    );

    FUZZY_COG_SWEEP(
        "smart_hvac/sweep_cooling_mamdani_cog",
        "Cooling Power 5-Input Sweep (Mamdani COG)",
        cooling_mamdani_sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Indoor Temp", 0.0f, 50.0f, 25.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("CO2 Index", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Occupancy", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Outside Temp", 0.0f, 50.0f, 25.0f)
    );

    FUZZY_COG_SWEEP(
        "smart_hvac/sweep_cooling_boa",
        "Cooling Power 5-Input Sweep (BOA)",
        cooling_boa_sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Indoor Temp", 0.0f, 50.0f, 25.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("CO2 Index", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Occupancy", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Outside Temp", 0.0f, 50.0f, 25.0f)
    );

    FUZZY_COG_SWEEP(
        "smart_hvac/sweep_vent_mamdani_cog",
        "Ventilation 5-Input Sweep (Mamdani COG)",
        vent_mamdani_sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Indoor Temp", 0.0f, 50.0f, 25.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("CO2 Index", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Occupancy", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Outside Temp", 0.0f, 50.0f, 25.0f)
    );

    FUZZY_COG_SWEEP(
        "smart_hvac/sweep_vent_boa",
        "Ventilation 5-Input Sweep (BOA)",
        vent_boa_sweep,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Indoor Temp", 0.0f, 50.0f, 25.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("CO2 Index", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Occupancy", 0.0f, 100.0f, 50.0f),
        FUZZY_SWEEP_DIMENSION("Outside Temp", 0.0f, 50.0f, 25.0f)
    );

    /* 4. Scenario Evaluation comparing Mamdani COG vs BOA */
    float temp      = 29.0f;
    float humidity  = 68.0f;
    float co2       = 72.0f;
    float occupancy = 75.0f;
    float outside   = 34.0f;

    printf("\nSmart HVAC 5-Input / 3-Output Fuzzy System\n");
    printf("==========================================\n");
    printf("Inputs: Temp=%.1f C, Humidity=%.1f%%, CO2=%.1f%%, Occupancy=%.1f%%, Outside=%.1f C\n\n",
        temp, humidity, co2, occupancy, outside);

    float fan_cog = eval_fan_speed(
        temp, humidity, co2, occupancy, outside, 0.5f,
        FUZZY_DEFUZZ_COG, "smart_hvac/scenario_fan_mamdani_cog", "Fan Speed (Mamdani COG)");
    float fan_boa = eval_fan_speed(
        temp, humidity, co2, occupancy, outside, 0.5f,
        FUZZY_DEFUZZ_BOA, "smart_hvac/scenario_fan_boa", "Fan Speed (BOA)");

    float cool_cog = eval_cooling_power(
        temp, humidity, co2, occupancy, outside, 0.5f,
        FUZZY_DEFUZZ_COG, "smart_hvac/scenario_cooling_mamdani_cog", "Cooling Power (Mamdani COG)");
    float cool_boa = eval_cooling_power(
        temp, humidity, co2, occupancy, outside, 0.5f,
        FUZZY_DEFUZZ_BOA, "smart_hvac/scenario_cooling_boa", "Cooling Power (BOA)");

    float vent_cog = eval_ventilation(
        temp, humidity, co2, occupancy, outside, 0.5f,
        FUZZY_DEFUZZ_COG, "smart_hvac/scenario_vent_mamdani_cog", "Ventilation (Mamdani COG)");
    float vent_boa = eval_ventilation(
        temp, humidity, co2, occupancy, outside, 0.5f,
        FUZZY_DEFUZZ_BOA, "smart_hvac/scenario_vent_boa", "Ventilation (BOA)");

    printf("\nDefuzzification Comparison:\n");
    printf("  Fan Speed     -> Mamdani COG: %6.2f%% | BOA: %6.2f%%\n", fan_cog, fan_boa);
    printf("  Cooling Power -> Mamdani COG: %6.2f%% | BOA: %6.2f%%\n", cool_cog, cool_boa);
    printf("  Ventilation   -> Mamdani COG: %6.2f%% | BOA: %6.2f%%\n", vent_cog, vent_boa);

    return 0;
}
