#define FUZZY_OPENCL
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#include <sys/stat.h>


#define GRID_SIZE 100u

#define INPUT_MIN 0.0f
#define INPUT_MAX 100.0f

#define INPUT_STEP \
    ((INPUT_MAX - INPUT_MIN) / ((float)GRID_SIZE - 1.0f))


/* ==========================================================
 * Braking controller membership functions
 * ========================================================== */

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
    FUZZY_SHAPE_RAMP,
    1.0f,
    20.0f,
    40.0f,
    false
)

FUZZY_VAR(
    brake_force_medium,
    FUZZY_SHAPE_TRAPEZOID,
    1.0f,
    20.0f,
    40.0f,
    60.0f,
    80.0f
)

FUZZY_VAR(
    brake_force_high,
    FUZZY_SHAPE_RAMP,
    1.0f,
    60.0f,
    75.0f,
    true
)


/* ==========================================================
 * Original CPU braking controller
 * ========================================================== */

static float brake(
    float speed,
    float distance,
    const char *plot
)
{
    fuzzy_rules_t system;

    system.count =
        0u;

    RULE(
        system,
        "Low OR Far -> Low",
        SOR(
            speed_low(speed),
            distance_far(distance)
        ),
        brake_force_low
    );

    RULE(
        system,
        "Low AND Medium -> Low",
        SAND(
            speed_low(speed),
            distance_medium(distance)
        ),
        brake_force_low
    );

    RULE(
        system,
        "Low AND Close -> Medium",
        SAND(
            speed_low(speed),
            distance_close(distance)
        ),
        brake_force_medium
    );

    RULE(
        system,
        "Medium OR Far -> Low",
        SOR(
            speed_medium(speed),
            distance_far(distance)
        ),
        brake_force_low
    );

    RULE(
        system,
        "Medium AND Medium -> Medium",
        SAND(
            speed_medium(speed),
            distance_medium(distance)
        ),
        brake_force_medium
    );

    RULE(
        system,
        "Medium AND Close -> High",
        SAND(
            speed_medium(speed),
            distance_close(distance)
        ),
        brake_force_high
    );

    RULE(
        system,
        "High OR Far -> Medium",
        SOR(
            speed_high(speed),
            distance_far(distance)
        ),
        brake_force_medium
    );

    RULE(
        system,
        "High AND Medium -> High",
        SAND(
            speed_high(speed),
            distance_medium(distance)
        ),
        brake_force_high
    );

    RULE(
        system,
        "High AND Close -> High",
        SAND(
            speed_high(speed),
            distance_close(distance)
        ),
        brake_force_high
    );

    float force =
        fuzzy_rules_defuzzify(
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
            "Braking COG",
            force,
            0.0f,
            100.0f,
            0.25f
        );
    }

    return force;
}


/* ==========================================================
 * GPU braking-controller kernel
 *
 * fuzzy.h supplies:
 *
 *     fuzzy_ramp()
 *     fuzzy_triangle()
 *     fuzzy_trapezoid()
 *
 * Kernel interface required by FUZZY_GPU_SWEEP:
 *
 * Argument 0:
 *     Flattened N-dimensional inputs.
 *
 * Argument 1:
 *     Output values.
 *
 * Argument 2:
 *     Sweep point count.
 *
 * Argument 3:
 *     Input dimension count.
 *
 * Argument 4:
 *     Defuzzification sampling step.
 * ========================================================== */

static const char *braking_gpu_kernel(void)
{
    return
        FUZZY_GPU_KERNEL_HEADER

        "__kernel void braking_sweep(\n"
        "    __global const float *inputs,\n"
        "    __global float *outputs,\n"
        "    const uint point_count,\n"
        "    const uint dimension_count,\n"
        "    const float cog_step)\n"
        "{\n"
        "    const uint id = get_global_id(0);\n"
        "\n"
        "    if (id >= point_count) return;\n"
        "\n"
        "    const uint base = id * dimension_count;\n"
        "\n"
        "    const float speed = inputs[base];\n"
        "    const float distance = inputs[base + 1u];\n"
        "\n"
        "    const float speed_low =\n"
        "        fuzzy_ramp(\n"
        "            speed,\n"
        "            20.0f,\n"
        "            40.0f,\n"
        "            0\n"
        "        );\n"
        "\n"
        "    const float speed_medium =\n"
        "        fuzzy_trapezoid(\n"
        "            speed,\n"
        "            20.0f,\n"
        "            40.0f,\n"
        "            60.0f,\n"
        "            80.0f\n"
        "        );\n"
        "\n"
        "    const float speed_high =\n"
        "        fuzzy_ramp(\n"
        "            speed,\n"
        "            60.0f,\n"
        "            80.0f,\n"
        "            1\n"
        "        );\n"
        "\n"
        "    const float distance_close =\n"
        "        fuzzy_ramp(\n"
        "            distance,\n"
        "            10.0f,\n"
        "            20.0f,\n"
        "            0\n"
        "        );\n"
        "\n"
        "    const float distance_medium =\n"
        "        fuzzy_trapezoid(\n"
        "            distance,\n"
        "            10.0f,\n"
        "            20.0f,\n"
        "            30.0f,\n"
        "            40.0f\n"
        "        );\n"
        "\n"
        "    const float distance_far =\n"
        "        fuzzy_trapezoid(\n"
        "            distance,\n"
        "            30.0f,\n"
        "            40.0f,\n"
        "            50.0f,\n"
        "            70.0f\n"
        "        );\n"
        "\n"
        "    float rules[9];\n"
        "\n"
        "    rules[0] = fmax(\n"
        "        speed_low,\n"
        "        distance_far\n"
        "    );\n"
        "\n"
        "    rules[1] = fmin(\n"
        "        speed_low,\n"
        "        distance_medium\n"
        "    );\n"
        "\n"
        "    rules[2] = fmin(\n"
        "        speed_low,\n"
        "        distance_close\n"
        "    );\n"
        "\n"
        "    rules[3] = fmax(\n"
        "        speed_medium,\n"
        "        distance_far\n"
        "    );\n"
        "\n"
        "    rules[4] = fmin(\n"
        "        speed_medium,\n"
        "        distance_medium\n"
        "    );\n"
        "\n"
        "    rules[5] = fmin(\n"
        "        speed_medium,\n"
        "        distance_close\n"
        "    );\n"
        "\n"
        "    rules[6] = fmax(\n"
        "        speed_high,\n"
        "        distance_far\n"
        "    );\n"
        "\n"
        "    rules[7] = fmin(\n"
        "        speed_high,\n"
        "        distance_medium\n"
        "    );\n"
        "\n"
        "    rules[8] = fmin(\n"
        "        speed_high,\n"
        "        distance_close\n"
        "    );\n"
        "\n"
        "    float weighted_sum = 0.0f;\n"
        "    float height_sum = 0.0f;\n"
        "\n"
        "    for (\n"
        "        float value = 0.0f;\n"
        "        value <= 100.0f;\n"
        "        value += cog_step\n"
        "    ) {\n"
        "        const float output_low =\n"
        "            fuzzy_ramp(\n"
        "                value,\n"
        "                20.0f,\n"
        "                40.0f,\n"
        "                0\n"
        "            );\n"
        "\n"
        "        const float output_medium =\n"
        "            fuzzy_trapezoid(\n"
        "                value,\n"
        "                20.0f,\n"
        "                40.0f,\n"
        "                60.0f,\n"
        "                80.0f\n"
        "            );\n"
        "\n"
        "        const float output_high =\n"
        "            fuzzy_ramp(\n"
        "                value,\n"
        "                60.0f,\n"
        "                75.0f,\n"
        "                1\n"
        "            );\n"
        "\n"
        "        float aggregated = 0.0f;\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[0], output_low)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[1], output_low)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[2], output_medium)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[3], output_low)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[4], output_medium)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[5], output_high)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[6], output_medium)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[7], output_high)\n"
        "        );\n"
        "\n"
        "        aggregated = fmax(\n"
        "            aggregated,\n"
        "            fmin(rules[8], output_high)\n"
        "        );\n"
        "\n"
        "        weighted_sum +=\n"
        "            value *\n"
        "            aggregated;\n"
        "\n"
        "        height_sum +=\n"
        "            aggregated;\n"
        "    }\n"
        "\n"
        "    outputs[id] =\n"
        "        height_sum > 0.0f\n"
        "            ? weighted_sum / height_sum\n"
        "            : 0.0f;\n"
        "}\n";
}


/* ==========================================================
 * Program entry point
 * ========================================================== */

int main(void)
{
    mkdir(
        "braking_gpu",
        0777
    );

    printf(
        "\n====================================\n"
        " FUZZY GPU SWEEP\n"
        "====================================\n"
        "Grid: %u x %u\n"
        "Controller evaluations: %zu\n"
        "COG step: 0.25\n\n",
        GRID_SIZE,
        GRID_SIZE,
        (size_t)GRID_SIZE *
        (size_t)GRID_SIZE
    );


    /*
     * Native fuzzy.h membership plots.
     */

    PLOT(
        "braking_gpu/speed_membership",
        "Speed Membership Functions",
        100.0f,
        0.25f,
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
        "braking_gpu/distance_membership",
        "Distance Membership Functions",
        100.0f,
        0.25f,
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
        "braking_gpu/brake_membership",
        "Brake Force Membership Functions",
        100.0f,
        0.25f,
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
     * Selected CPU controller result for direct verification.
     */

    float selected_force =
        brake(
            60.0f,
            25.0f,
            "braking_gpu/selected_cog"
        );

    printf(
        "Selected CPU result:\n"
        "Speed:       60.00\n"
        "Distance:    25.00\n"
        "Brake force: %.5f\n\n",
        selected_force
    );


    /*
     * Complete GPU sweep.
     *
     * fuzzy.h handles:
     *
     * - N-dimensional Cartesian input generation
     * - OpenCL platform and device selection
     * - Context and command-queue creation
     * - Kernel compilation
     * - Input and output buffers
     * - Kernel arguments
     * - Kernel execution
     * - GPU output retrieval
     * - CSV generation
     * - SVG generation
     * - OpenCL cleanup
     * - Host-memory cleanup
     */

    bool sweep_success =
        FUZZY_GPU_SWEEP(
            "braking_gpu/gpu_sweep",
            "GPU Braking Controller",
            "COG",
            braking_gpu_kernel,
            "braking_sweep",
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
            "GPU sweep failed.\n"
        );

        return 1;
    }

    printf(
        "\nGenerated:\n"
        "  braking_gpu/speed_membership.svg\n"
        "  braking_gpu/distance_membership.svg\n"
        "  braking_gpu/brake_membership.svg\n"
        "  braking_gpu/selected_cog.svg\n"
        "  braking_gpu/gpu_sweep.csv\n"
        "  braking_gpu/gpu_sweep.svg\n"
    );

    return 0;
}