#ifndef FUZZY_OPENCL
#define FUZZY_OPENCL
#endif

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#include <sys/stat.h>

#define GRID_SIZE 100u
#define INPUT_MIN 0.0f
#define INPUT_MAX 100.0f
#define INPUT_STEP ((INPUT_MAX - INPUT_MIN) / ((float)GRID_SIZE - 1.0f))

FUZZY_VAR(speed_ramp, FUZZY_SHAPE_RAMP, 1.0f, 20.0f, 80.0f, true)
FUZZY_VAR(speed_triangle, FUZZY_SHAPE_TRIANGLE, 1.0f, 10.0f, 50.0f, 90.0f)
FUZZY_VAR(speed_trapezoid, FUZZY_SHAPE_TRAPEZOID, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f)
FUZZY_VAR(speed_smf, FUZZY_SHAPE_SMF, 1.0f, 20.0f, 80.0f)
FUZZY_VAR(speed_zmf, FUZZY_SHAPE_ZMF, 1.0f, 20.0f, 80.0f)
FUZZY_VAR(speed_gaussian, FUZZY_SHAPE_GAUSSIAN, 1.0f, 50.0f, 15.0f)

FUZZY_VAR(distance_bell, FUZZY_SHAPE_BELL, 1.0f, 40.0f, 2.0f, 50.0f)
FUZZY_VAR(distance_sigmoid, FUZZY_SHAPE_SIGMOID, 1.0f, 0.15f, 50.0f)
FUZZY_VAR(distance_pimf, FUZZY_SHAPE_PIMF, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f)
FUZZY_VAR(distance_dsigmoid, FUZZY_SHAPE_DSIGMOID, 1.0f, 0.15f, 30.0f, 0.15f, 70.0f)
FUZZY_VAR(distance_psigmoid, FUZZY_SHAPE_PSIGMOID, 1.0f, 0.15f, 30.0f, -0.15f, 70.0f)
FUZZY_VAR(distance_gaussian2, FUZZY_SHAPE_GAUSSIAN2, 1.0f, 30.0f, 10.0f, 70.0f, 10.0f)

static float distance_piecewise(float value)
{
    return value <= 50.0f
        ? value / 50.0f
        : (100.0f - value) / 50.0f;
}

FUZZY_VAR(output_ramp, FUZZY_SHAPE_RAMP, 1.0f, 10.0f, 35.0f, false)
FUZZY_VAR(output_triangle, FUZZY_SHAPE_TRIANGLE, 1.0f, 5.0f, 25.0f, 45.0f)
FUZZY_VAR(output_trapezoid, FUZZY_SHAPE_TRAPEZOID, 1.0f, 15.0f, 30.0f, 50.0f, 65.0f)
FUZZY_VAR(output_smf, FUZZY_SHAPE_SMF, 1.0f, 25.0f, 75.0f)
FUZZY_VAR(output_zmf, FUZZY_SHAPE_ZMF, 1.0f, 25.0f, 75.0f)
FUZZY_VAR(output_gaussian, FUZZY_SHAPE_GAUSSIAN, 1.0f, 50.0f, 12.0f)
FUZZY_VAR(output_bell, FUZZY_SHAPE_BELL, 1.0f, 35.0f, 2.0f, 50.0f)
FUZZY_VAR(output_sigmoid, FUZZY_SHAPE_SIGMOID, 1.0f, 0.15f, 50.0f)
FUZZY_VAR(output_pimf, FUZZY_SHAPE_PIMF, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f)
FUZZY_VAR(output_dsigmoid, FUZZY_SHAPE_DSIGMOID, 1.0f, 0.15f, 30.0f, 0.15f, 70.0f)
FUZZY_VAR(output_psigmoid, FUZZY_SHAPE_PSIGMOID, 1.0f, 0.15f, 30.0f, -0.15f, 70.0f)
FUZZY_VAR(output_gaussian2, FUZZY_SHAPE_GAUSSIAN2, 1.0f, 30.0f, 10.0f, 70.0f, 10.0f)

static float output_piecewise(float value)
{
    return value <= 50.0f
        ? value / 50.0f
        : (100.0f - value) / 50.0f;
}

static float stress_controller(
    float speed,
    float distance,
    const char *plot
)
{
    fuzzy_rules_t system;

    system.count = 0u;

    RULE(
        system,
        "Ramp OR Bell -> Ramp",
        SOR(
            speed_ramp(speed),
            distance_bell(distance)
        ),
        output_ramp
    );

    RULE(
        system,
        "Triangle AND Sigmoid -> Triangle",
        SAND(
            speed_triangle(speed),
            distance_sigmoid(distance)
        ),
        output_triangle
    );

    RULE(
        system,
        "Trapezoid OR PIMF -> Trapezoid",
        SOR(
            speed_trapezoid(speed),
            distance_pimf(distance)
        ),
        output_trapezoid
    );

    RULE(
        system,
        "SMF AND DSigmoid -> SMF",
        SAND(
            speed_smf(speed),
            distance_dsigmoid(distance)
        ),
        output_smf
    );

    RULE(
        system,
        "ZMF OR PSigmoid -> ZMF",
        SOR(
            speed_zmf(speed),
            distance_psigmoid(distance)
        ),
        output_zmf
    );

    RULE(
        system,
        "Gaussian AND Gaussian2 -> Gaussian",
        SAND(
            speed_gaussian(speed),
            distance_gaussian2(distance)
        ),
        output_gaussian
    );

    RULE(
        system,
        "Ramp AND Piecewise -> Bell",
        SAND(
            speed_ramp(speed),
            distance_piecewise(distance)
        ),
        output_bell
    );

    RULE(
        system,
        "Triangle OR Bell -> Sigmoid",
        SOR(
            speed_triangle(speed),
            distance_bell(distance)
        ),
        output_sigmoid
    );

    RULE(
        system,
        "Trapezoid AND Sigmoid -> PIMF",
        SAND(
            speed_trapezoid(speed),
            distance_sigmoid(distance)
        ),
        output_pimf
    );

    RULE(
        system,
        "SMF OR PIMF -> DSigmoid",
        SOR(
            speed_smf(speed),
            distance_pimf(distance)
        ),
        output_dsigmoid
    );

    RULE(
        system,
        "ZMF AND PSigmoid -> PSigmoid",
        SAND(
            speed_zmf(speed),
            distance_psigmoid(distance)
        ),
        output_psigmoid
    );

    RULE(
        system,
        "Gaussian OR Gaussian2 -> Gaussian2",
        SOR(
            speed_gaussian(speed),
            distance_gaussian2(distance)
        ),
        output_gaussian2
    );

    RULE(
        system,
        "Piecewise AND Triangle -> Piecewise",
        SAND(
            distance_piecewise(distance),
            speed_triangle(speed)
        ),
        output_piecewise
    );

    float result = fuzzy_rules_defuzzify(
        &system,
        0.0f,
        100.0f,
        0.25f,
        FUZZY_DEFUZZ_COG
    );

    if (plot != NULL) {
        fuzzy_rules_print(
            &system
        );

        fuzzy_rules_plot_cog(
            &system,
            plot,
            "GPU Full-Shape Stress COG",
            result,
            0.0f,
            100.0f,
            0.25f
        );
    }

    return result;
}

enum {
    speed_ramp_gpu_id,
    speed_triangle_gpu_id,
    speed_trapezoid_gpu_id,
    speed_smf_gpu_id,
    speed_zmf_gpu_id,
    speed_gaussian_gpu_id,
    distance_bell_gpu_id,
    distance_sigmoid_gpu_id,
    distance_pimf_gpu_id,
    distance_dsigmoid_gpu_id,
    distance_psigmoid_gpu_id,
    distance_gaussian2_gpu_id,
    distance_piecewise_gpu_id
};

static const fuzzy_gpu_variable_t stress_variables[] = {
    FUZZY_GPU_VARIABLE(0, FUZZY_SHAPE_RAMP, 1.0f, 20.0f, 80.0f, 1.0f),
    FUZZY_GPU_VARIABLE(0, FUZZY_SHAPE_TRIANGLE, 1.0f, 10.0f, 50.0f, 90.0f),
    FUZZY_GPU_VARIABLE(0, FUZZY_SHAPE_TRAPEZOID, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f),
    FUZZY_GPU_VARIABLE(0, FUZZY_SHAPE_SMF, 1.0f, 20.0f, 80.0f),
    FUZZY_GPU_VARIABLE(0, FUZZY_SHAPE_ZMF, 1.0f, 20.0f, 80.0f),
    FUZZY_GPU_VARIABLE(0, FUZZY_SHAPE_GAUSSIAN, 1.0f, 50.0f, 15.0f),

    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_BELL, 1.0f, 40.0f, 2.0f, 50.0f),
    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_SIGMOID, 1.0f, 0.15f, 50.0f),
    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_PIMF, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f),
    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_DSIGMOID, 1.0f, 0.15f, 30.0f, 0.15f, 70.0f),
    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_PSIGMOID, 1.0f, 0.15f, 30.0f, -0.15f, 70.0f),
    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_GAUSSIAN2, 1.0f, 30.0f, 10.0f, 70.0f, 10.0f),
    FUZZY_GPU_VARIABLE(1, FUZZY_SHAPE_PIECEWISE, 1.0f, 0.0f, 50.0f, 100.0f)
};

enum {
    output_ramp_gpu_id,
    output_triangle_gpu_id,
    output_trapezoid_gpu_id,
    output_smf_gpu_id,
    output_zmf_gpu_id,
    output_gaussian_gpu_id,
    output_bell_gpu_id,
    output_sigmoid_gpu_id,
    output_pimf_gpu_id,
    output_dsigmoid_gpu_id,
    output_psigmoid_gpu_id,
    output_gaussian2_gpu_id,
    output_piecewise_gpu_id
};

static const fuzzy_gpu_variable_t stress_outputs[] = {
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_RAMP, 1.0f, 10.0f, 35.0f, 0.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_TRIANGLE, 1.0f, 5.0f, 25.0f, 45.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_TRAPEZOID, 1.0f, 15.0f, 30.0f, 50.0f, 65.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_SMF, 1.0f, 25.0f, 75.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_ZMF, 1.0f, 25.0f, 75.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_GAUSSIAN, 1.0f, 50.0f, 12.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_BELL, 1.0f, 35.0f, 2.0f, 50.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_SIGMOID, 1.0f, 0.15f, 50.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_PIMF, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_DSIGMOID, 1.0f, 0.15f, 30.0f, 0.15f, 70.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_PSIGMOID, 1.0f, 0.15f, 30.0f, -0.15f, 70.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_GAUSSIAN2, 1.0f, 30.0f, 10.0f, 70.0f, 10.0f),
    FUZZY_GPU_OUTPUT(FUZZY_SHAPE_PIECEWISE, 1.0f, 0.0f, 50.0f, 100.0f)
};

FUZZY_GPU_RULES(
    stress_controller_gpu,
    stress_variables,
    stress_outputs,
    FUZZY_LOGIC_STANDARD,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX,
    FUZZY_DEFUZZ_COG,
    0.0f,
    100.0f,
    FUZZY_GPU_RULE(speed_ramp, FUZZY_OPERATOR_OR, distance_bell, output_ramp),
    FUZZY_GPU_RULE(speed_triangle, FUZZY_OPERATOR_AND, distance_sigmoid, output_triangle),
    FUZZY_GPU_RULE(speed_trapezoid, FUZZY_OPERATOR_OR, distance_pimf, output_trapezoid),
    FUZZY_GPU_RULE(speed_smf, FUZZY_OPERATOR_AND, distance_dsigmoid, output_smf),
    FUZZY_GPU_RULE(speed_zmf, FUZZY_OPERATOR_OR, distance_psigmoid, output_zmf),
    FUZZY_GPU_RULE(speed_gaussian, FUZZY_OPERATOR_AND, distance_gaussian2, output_gaussian),
    FUZZY_GPU_RULE(speed_ramp, FUZZY_OPERATOR_AND, distance_piecewise, output_bell),
    FUZZY_GPU_RULE(speed_triangle, FUZZY_OPERATOR_OR, distance_bell, output_sigmoid),
    FUZZY_GPU_RULE(speed_trapezoid, FUZZY_OPERATOR_AND, distance_sigmoid, output_pimf),
    FUZZY_GPU_RULE(speed_smf, FUZZY_OPERATOR_OR, distance_pimf, output_dsigmoid),
    FUZZY_GPU_RULE(speed_zmf, FUZZY_OPERATOR_AND, distance_psigmoid, output_psigmoid),
    FUZZY_GPU_RULE(speed_gaussian, FUZZY_OPERATOR_OR, distance_gaussian2, output_gaussian2),
    FUZZY_GPU_RULE(distance_piecewise, FUZZY_OPERATOR_AND, speed_triangle, output_piecewise)
);

int main(void)
{
    mkdir("braking_gpu",0777
    );

    printf(
        "\n====================================\n"
        " FUZZY GPU FULL-SHAPE STRESS TEST\n"
        "====================================\n"
        "Grid: %u x %u\n"
        "Controller evaluations: %zu\n"
        "Rules: %zu\n"
        "Input membership variables: %zu\n"
        "Output membership variables: %zu\n"
        "COG step: 0.25\n\n",
        GRID_SIZE,
        GRID_SIZE,
        (size_t)GRID_SIZE *
        (size_t)GRID_SIZE,
        stress_controller_gpu.rule_count,
        sizeof(stress_variables) /
        sizeof(stress_variables[0]),
        sizeof(stress_outputs) /
        sizeof(stress_outputs[0])
    );

    PLOT(
        "braking_gpu/input_shapes_a",
        "GPU Stress Input Shapes A",
        100.0f,
        0.25f,
        SERIES(speed_ramp, "#3b82f6"),
        SERIES(speed_triangle, "#22c55e"),
        SERIES(speed_trapezoid, "#ef4444"),
        SERIES(speed_smf, "#a855f7"),
        SERIES(speed_zmf, "#f59e0b"),
        SERIES(speed_gaussian, "#06b6d4")
    );

    PLOT(
        "braking_gpu/input_shapes_b",
        "GPU Stress Input Shapes B",
        100.0f,
        0.25f,
        SERIES(distance_bell, "#3b82f6"),
        SERIES(distance_sigmoid, "#22c55e"),
        SERIES(distance_pimf, "#ef4444"),
        SERIES(distance_dsigmoid, "#a855f7"),
        SERIES(distance_psigmoid, "#f59e0b"),
        SERIES(distance_gaussian2, "#06b6d4"),
        SERIES(distance_piecewise, "#111827")
    );

    PLOT(
        "braking_gpu/output_shapes_a",
        "GPU Stress Output Shapes A",
        100.0f,
        0.25f,
        SERIES(output_ramp, "#3b82f6"),
        SERIES(output_triangle, "#22c55e"),
        SERIES(output_trapezoid, "#ef4444"),
        SERIES(output_smf, "#a855f7"),
        SERIES(output_zmf, "#f59e0b"),
        SERIES(output_gaussian, "#06b6d4")
    );

    PLOT(
        "braking_gpu/output_shapes_b",
        "GPU Stress Output Shapes B",
        100.0f,
        0.25f,
        SERIES(output_bell, "#3b82f6"),
        SERIES(output_sigmoid, "#22c55e"),
        SERIES(output_pimf, "#ef4444"),
        SERIES(output_dsigmoid, "#a855f7"),
        SERIES(output_psigmoid, "#f59e0b"),
        SERIES(output_gaussian2, "#06b6d4"),
        SERIES(output_piecewise, "#111827")
    );

    float selected_force =
        stress_controller(
            60.0f,
            25.0f,
            "braking_gpu/stress_selected_cog"
        );

    printf(
        "Selected CPU verification:\n"
        "Speed:       60.00\n"
        "Distance:    25.00\n"
        "Output:      %.5f\n\n",
        selected_force
    );

    bool sweep_success =
        FUZZY_GPU_SWEEP(
            "braking_gpu/full_shape_gpu_sweep",
            "GPU Full-Shape Fuzzy Stress Test",
            "COG",
            stress_controller_gpu,
            0.25f,

            FUZZY_SWEEP_DIMENSION(
                "Speed",
                INPUT_MIN,
                INPUT_MAX,
                INPUT_STEP
            ),

            FUZZY_SWEEP_DIMENSION(
                "Distance",
                INPUT_MIN,
                INPUT_MAX,
                INPUT_STEP
            )
        );

    if (!sweep_success) {
        fprintf(
            stderr,
            "GPU stress sweep failed.\n"
        );

        return 1;
    }

    printf(
        "\nGenerated:\n"
        "  braking_gpu/input_shapes_a.svg\n"
        "  braking_gpu/input_shapes_b.svg\n"
        "  braking_gpu/output_shapes_a.svg\n"
        "  braking_gpu/output_shapes_b.svg\n"
        "  braking_gpu/stress_selected_cog.svg\n"
        "  braking_gpu/full_shape_gpu_sweep.csv\n"
        "  braking_gpu/full_shape_gpu_sweep.svg\n"
    );

    return 0;
}