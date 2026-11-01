#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

FUZZY_VAR(
    speed_low,
    FUZZY_SHAPE_RAMP,
    1.0f,
    20.0f,
    40.0f,
    false
)

FUZZY_VAR(
    speed_medium,
    FUZZY_SHAPE_TRAPEZOID,
    1.0f,
    20.0f,
    40.0f,
    60.0f,
    80.0f
)

FUZZY_VAR(
    speed_high,
    FUZZY_SHAPE_RAMP,
    1.0f,
    60.0f,
    80.0f,
    true
)

FUZZY_VAR(
    distance_close,
    FUZZY_SHAPE_RAMP,
    1.0f,
    10.0f,
    20.0f,
    false
)

FUZZY_VAR(
    distance_medium,
    FUZZY_SHAPE_TRAPEZOID,
    1.0f,
    10.0f,
    20.0f,
    30.0f,
    40.0f
)

FUZZY_VAR(
    distance_far,
    FUZZY_SHAPE_TRAPEZOID,
    1.0f,
    30.0f,
    40.0f,
    50.0f,
    70.0f
)

FUZZY_VAR(
    brake_force_low,
    FUZZY_SHAPE_ZMF,
    1.0f,
    20.0f,
    40.0f
)

FUZZY_VAR(
    brake_force_medium,
    FUZZY_SHAPE_TRIANGLE,
    1.0f,
    30.0f,
    65.0f,
    90.0f
)

FUZZY_VAR(
    brake_force_high,
    FUZZY_SHAPE_SMF,
    1.0f,
    60.0f,
    75.0f
)

static float brake(
    float speed,
    float distance,
    int scenario,
    fuzzy_defuzz_method_t defuzz_method,
    float defuzz_step,
    const char *plot
)
{
    fuzzy_rules_t normal;
    fuzzy_rules_t emergency;
    fuzzy_rules_t *system;
    float force;

    normal.count = 0u;
    emergency.count = 0u;

    /*
     * Normal braking rule set.
     */

    RULE(
        normal,
        "Low AND Far -> Low",
        SAND(
            speed_low(speed),
            distance_far(distance)
        ),
        brake_force_low
    );

    RULE(
        normal,
        "Low AND Medium -> Low",
        SAND(
            speed_low(speed),
            distance_medium(distance)
        ),
        brake_force_low
    );

    RULE(
        normal,
        "Low AND Close -> Medium",
        SAND(
            speed_low(speed),
            distance_close(distance)
        ),
        brake_force_medium
    );

    RULE(
        normal,
        "Medium AND Far -> Low",
        SAND(
            speed_medium(speed),
            distance_far(distance)
        ),
        brake_force_low
    );

    RULE(
        normal,
        "Medium AND Medium -> Medium",
        SAND(
            speed_medium(speed),
            distance_medium(distance)
        ),
        brake_force_medium
    );

    RULE(
        normal,
        "Medium AND Close -> High",
        SAND(
            speed_medium(speed),
            distance_close(distance)
        ),
        brake_force_high
    );

    RULE(
        normal,
        "High AND Far -> Medium",
        SAND(
            speed_high(speed),
            distance_far(distance)
        ),
        brake_force_medium
    );

    RULE(
        normal,
        "High AND Medium -> High",
        SAND(
            speed_high(speed),
            distance_medium(distance)
        ),
        brake_force_high
    );

    RULE(
        normal,
        "High AND Close -> High",
        SAND(
            speed_high(speed),
            distance_close(distance)
        ),
        brake_force_high
    );

    /*
     * Emergency braking rule set.
     */

    RULE(
        emergency,
        "Any Low Speed -> Medium",
        speed_low(speed),
        brake_force_medium
    );

    RULE(
        emergency,
        "Any Medium Speed -> High",
        speed_medium(speed),
        brake_force_high
    );

    RULE(
        emergency,
        "Any High Speed -> High",
        speed_high(speed),
        brake_force_high
    );

    system =
        scenario == 1
            ? &normal
            : &emergency;

    if (plot != NULL) {
        fuzzy_rules_print(
            system
        );
    }

    switch (defuzz_method) {
        case FUZZY_DEFUZZ_COG:
            force =
                fuzzy_rules_defuzzify_cog(
                    system,
                    0.0f,
                    100.0f,
                    defuzz_step,
                    FUZZY_IMPLICATION_MIN,
                    FUZZY_AGGREGATION_MAX
                );
            break;

        case FUZZY_DEFUZZ_BOA:
            force =
                fuzzy_rules_defuzzify_boa(
                    system,
                    0.0f,
                    100.0f,
                    defuzz_step,
                    FUZZY_IMPLICATION_MIN,
                    FUZZY_AGGREGATION_MAX
                );
            break;

        case FUZZY_DEFUZZ_COS:
            force =
                fuzzy_rules_defuzzify_cos(
                    system,
                    0.0f,
                    100.0f,
                    defuzz_step,
                    FUZZY_IMPLICATION_MIN
                );
            break;

        case FUZZY_DEFUZZ_MOM:
            force =
                fuzzy_rules_defuzzify_mom(
                    system,
                    0.0f,
                    100.0f,
                    defuzz_step,
                    FUZZY_IMPLICATION_MIN,
                    FUZZY_AGGREGATION_MAX
                );
            break;

        case FUZZY_DEFUZZ_SOM:
            force =
                fuzzy_rules_defuzzify_som(
                    system,
                    0.0f,
                    100.0f,
                    defuzz_step,
                    FUZZY_IMPLICATION_MIN,
                    FUZZY_AGGREGATION_MAX
                );
            break;

        case FUZZY_DEFUZZ_LOM:
            force =
                fuzzy_rules_defuzzify_lom(
                    system,
                    0.0f,
                    100.0f,
                    defuzz_step,
                    FUZZY_IMPLICATION_MIN,
                    FUZZY_AGGREGATION_MAX
                );
            break;

        default:
            force =
                0.0f;
            break;
    }

    /*
     * The current direct-output plot function is specifically
     * named and labelled as COG, so only use it for COG.
     */
    if (
        plot != NULL &&
        defuzz_method == FUZZY_DEFUZZ_COG
    ) {
        fuzzy_rules_plot_cog(
            system,
            plot,
            "Brake Force COG",
            force,
            0.0f,
            100.0f,
            defuzz_step
        );
    }

    return force;
}


/* ==========================================================
 * Normal rule-set sweep evaluators
 * ========================================================== */

SWEEP_EVALUATOR(
    normal_cog_evaluator,
    brake,
    inputs[0],
    inputs[1],
    1,
    FUZZY_DEFUZZ_COG,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    normal_boa_evaluator,
    brake,
    inputs[0],
    inputs[1],
    1,
    FUZZY_DEFUZZ_BOA,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    normal_cos_evaluator,
    brake,
    inputs[0],
    inputs[1],
    1,
    FUZZY_DEFUZZ_COS,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    normal_mom_evaluator,
    brake,
    inputs[0],
    inputs[1],
    1,
    FUZZY_DEFUZZ_MOM,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    normal_som_evaluator,
    brake,
    inputs[0],
    inputs[1],
    1,
    FUZZY_DEFUZZ_SOM,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    normal_lom_evaluator,
    brake,
    inputs[0],
    inputs[1],
    1,
    FUZZY_DEFUZZ_LOM,
    cog_step,
    NULL
)


/* ==========================================================
 * Emergency rule-set sweep evaluators
 * ========================================================== */

SWEEP_EVALUATOR(
    emergency_cog_evaluator,
    brake,
    inputs[0],
    inputs[1],
    2,
    FUZZY_DEFUZZ_COG,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    emergency_boa_evaluator,
    brake,
    inputs[0],
    inputs[1],
    2,
    FUZZY_DEFUZZ_BOA,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    emergency_cos_evaluator,
    brake,
    inputs[0],
    inputs[1],
    2,
    FUZZY_DEFUZZ_COS,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    emergency_mom_evaluator,
    brake,
    inputs[0],
    inputs[1],
    2,
    FUZZY_DEFUZZ_MOM,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    emergency_som_evaluator,
    brake,
    inputs[0],
    inputs[1],
    2,
    FUZZY_DEFUZZ_SOM,
    cog_step,
    NULL
)

SWEEP_EVALUATOR(
    emergency_lom_evaluator,
    brake,
    inputs[0],
    inputs[1],
    2,
    FUZZY_DEFUZZ_LOM,
    cog_step,
    NULL
)


int main(void)
{
    /*
     * Normal braking defuzzification sweeps.
     */

    FUZZY_COG_SWEEP(
        "braking/normal_cog_sweep",
        "Normal Braking - COG",
        normal_cog_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/normal_boa_sweep",
        "Normal Braking - BOA",
        normal_boa_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/normal_cos_sweep",
        "Normal Braking - COS",
        normal_cos_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/normal_mom_sweep",
        "Normal Braking - MOM",
        normal_mom_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/normal_som_sweep",
        "Normal Braking - SOM",
        normal_som_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/normal_lom_sweep",
        "Normal Braking - LOM",
        normal_lom_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );


    /*
     * Emergency braking defuzzification sweeps.
     */

    FUZZY_COG_SWEEP(
        "braking/emergency_cog_sweep",
        "Emergency Braking - COG",
        emergency_cog_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/emergency_boa_sweep",
        "Emergency Braking - BOA",
        emergency_boa_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/emergency_cos_sweep",
        "Emergency Braking - COS",
        emergency_cos_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/emergency_mom_sweep",
        "Emergency Braking - MOM",
        emergency_mom_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/emergency_som_sweep",
        "Emergency Braking - SOM",
        emergency_som_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );

    FUZZY_COG_SWEEP(
        "braking/emergency_lom_sweep",
        "Emergency Braking - LOM",
        emergency_lom_evaluator,
        0.1f,
        FUZZY_SWEEP_DIMENSION(
            "Speed",
            0.0f,
            100.0f,
            1.0f
        ),
        FUZZY_SWEEP_DIMENSION(
            "Distance",
            0.0f,
            100.0f,
            1.0f
        )
    );


    /*
     * Membership-function plots.
     */

    PLOT(
        "braking/speed",
        "Speed Membership Functions",
        100.0f,
        1.0f,
        SERIES(
            speed_low,
            "#3b82f6"
        ),
        SERIES(
            speed_medium,
            "#22c55e"
        ),
        SERIES(
            speed_high,
            "#ef4444"
        )
    );

    PLOT(
        "braking/distance",
        "Distance Membership Functions",
        70.0f,
        1.0f,
        SERIES(
            distance_close,
            "#3b82f6"
        ),
        SERIES(
            distance_medium,
            "#22c55e"
        ),
        SERIES(
            distance_far,
            "#ef4444"
        )
    );

    PLOT(
        "braking/brake_force",
        "Brake Force Membership Functions",
        100.0f,
        1.0f,
        SERIES(
            brake_force_low,
            "#3b82f6"
        ),
        SERIES(
            brake_force_medium,
            "#22c55e"
        ),
        SERIES(
            brake_force_high,
            "#ef4444"
        )
    );


    /*
     * Normal braking scenario results.
     */

    float normal_cog =
        brake(
            60.0f,
            25.0f,
            1,
            FUZZY_DEFUZZ_COG,
            1.0f,
            "braking/scenario_1_cog"
        );

    float normal_boa =
        brake(
            60.0f,
            25.0f,
            1,
            FUZZY_DEFUZZ_BOA,
            1.0f,
            NULL
        );

    float normal_cos =
        brake(
            60.0f,
            25.0f,
            1,
            FUZZY_DEFUZZ_COS,
            1.0f,
            NULL
        );

    float normal_mom =
        brake(
            60.0f,
            25.0f,
            1,
            FUZZY_DEFUZZ_MOM,
            1.0f,
            NULL
        );

    float normal_som =
        brake(
            60.0f,
            25.0f,
            1,
            FUZZY_DEFUZZ_SOM,
            1.0f,
            NULL
        );

    float normal_lom =
        brake(
            60.0f,
            25.0f,
            1,
            FUZZY_DEFUZZ_LOM,
            1.0f,
            NULL
        );


    /*
     * Emergency braking scenario results.
     */

    float emergency_cog =
        brake(
            10.0f,
            50.0f,
            2,
            FUZZY_DEFUZZ_COG,
            1.0f,
            "braking/scenario_2_cog"
        );

    float emergency_boa =
        brake(
            10.0f,
            50.0f,
            2,
            FUZZY_DEFUZZ_BOA,
            1.0f,
            NULL
        );

    float emergency_cos =
        brake(
            10.0f,
            50.0f,
            2,
            FUZZY_DEFUZZ_COS,
            1.0f,
            NULL
        );

    float emergency_mom =
        brake(
            10.0f,
            50.0f,
            2,
            FUZZY_DEFUZZ_MOM,
            1.0f,
            NULL
        );

    float emergency_som =
        brake(
            10.0f,
            50.0f,
            2,
            FUZZY_DEFUZZ_SOM,
            1.0f,
            NULL
        );

    float emergency_lom =
        brake(
            10.0f,
            50.0f,
            2,
            FUZZY_DEFUZZ_LOM,
            1.0f,
            NULL
        );


    printf(
        "\nNormal braking rule set\n"
        "Speed: 60 km/h\n"
        "Distance: 25 m\n"
        "========================\n"
        "COG: %.2f%%\n"
        "BOA: %.2f%%\n"
        "COS: %.2f%%\n"
        "MOM: %.2f%%\n"
        "SOM: %.2f%%\n"
        "LOM: %.2f%%\n",
        normal_cog,
        normal_boa,
        normal_cos,
        normal_mom,
        normal_som,
        normal_lom
    );

    printf(
        "\nEmergency braking rule set\n"
        "Speed: 10 km/h\n"
        "Distance: 50 m\n"
        "===========================\n"
        "COG: %.2f%%\n"
        "BOA: %.2f%%\n"
        "COS: %.2f%%\n"
        "MOM: %.2f%%\n"
        "SOM: %.2f%%\n"
        "LOM: %.2f%%\n",
        emergency_cog,
        emergency_boa,
        emergency_cos,
        emergency_mom,
        emergency_som,
        emergency_lom
    );

    return 0;
}