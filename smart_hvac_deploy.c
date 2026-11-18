#define _GNU_SOURCE
#define FUZZY_OPENCL
#define FUZZY_SQLITE
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#ifdef USE_AUTOGEN_HEADER
#include "fuzzy-neuron-output/smart_hvac_autogen.h"
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEFAULT_DB_PATH "fuzzy-neuron-output/smart_hvac_tuner.db"
#define DEFAULT_AUTOGEN_PATH "fuzzy-neuron-output/smart_hvac_autogen.h"
#define DEFAULT_KERNEL_PATH "fuzzy_neuron_kernels.cl"

static double deploy_now_sec(void)
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1.0e-9;
}

static void print_scenario(const fuzzy_tuner_model_t *model, const char *label, const float inputs[5])
{
    float outputs[FUZZY_TUNER_MAX_OUTPUTS] = {0};
    fuzzy_tuner_inspection_t insp;
    size_t i;

    if (!fuzzy_tuner_predict_inspect(model, inputs, outputs, &insp))
    {
        fprintf(stderr, "Prediction failed for scenario '%s'.\n", label);
        return;
    }

    printf("\nScenario: %s\n", label);
    printf("  Inputs: ");
    for (i = 0u; i < model->input_count; ++i)
    {
        printf("%s=%.1f%s", model->inputs[i].name, inputs[i], i + 1u < model->input_count ? ", " : "\n");
    }
    printf("  Outputs:\n");
    for (i = 0u; i < model->output_count; ++i)
    {
        printf("    %-14s [%-11s] = %6.2f%%\n",
            model->outputs[i].name,
            model->outputs[i].defuzz_method == FUZZY_DEFUZZ_BOA ? "BOA" : "Mamdani-COG",
            outputs[i]);
    }
    printf("  Top Active Static Rules:\n");
    for (i = 0u; i < model->rule_count; ++i)
    {
        if (insp.rule_firings[i] >= 0.20f)
        {
            printf("    Rule %2zu (%.3f): %s\n", i + 1u, insp.rule_firings[i], model->rules[i].name);
        }
    }
}

int main(int argc, char **argv)
{
    const char *db_path = DEFAULT_DB_PATH;
    bool interactive = false;
    bool run_autogen = false;
    fuzzy_tuner_model_t *model = NULL;
    static const float scenarios[4][5] = {
        {17.0f, 35.0f, 25.0f, 10.0f, 12.0f},  /* Cool & empty morning */
        {24.0f, 50.0f, 45.0f, 45.0f, 24.0f},  /* Mild occupied office */
        {29.0f, 68.0f, 72.0f, 75.0f, 34.0f},  /* Warm crowded afternoon */
        {38.0f, 82.0f, 90.0f, 92.0f, 41.0f}   /* Peak heatwave & high CO2 */
    };
    static const char *scenario_names[4] = {
        "Cool & Empty Morning",
        "Mild Occupied Office",
        "Warm Crowded Afternoon",
        "Peak Heatwave & High CO2"
    };
    size_t s;
    int argi;

    for (argi = 1; argi < argc; ++argi)
    {
        if (strcmp(argv[argi], "--interactive") == 0)
        {
            interactive = true;
        }
        else if (strcmp(argv[argi], "--autogen") == 0)
        {
            run_autogen = true;
        }
        else
        {
            db_path = argv[argi];
        }
    }

    printf("======================================================================\n");
    printf("Seamless Deployment Demo: Zero-Boilerplate SQLite Autoload & Autogen\n");
    printf("======================================================================\n");

    /* 1. Seamlessly auto-load & reconstruct the complete network directly from SQLite */
    model = FUZZY_TUNER_DB_AUTOLOAD(db_path);
    if (model == NULL)
    {
        fprintf(stderr, "Failed to auto-load model from %s. Run './fuzzy-neuron --verify' first.\n", db_path);
        return EXIT_FAILURE;
    }

    fuzzy_tuner_print_summary(model);

    if (run_autogen)
    {
        if (!FUZZY_TUNER_AUTOGEN_C(db_path, DEFAULT_AUTOGEN_PATH, "smart_hvac_autogen"))
        {
            fprintf(stderr, "Failed to auto-generate C header %s.\n", DEFAULT_AUTOGEN_PATH);
            fuzzy_tuner_destroy(model);
            return EXIT_FAILURE;
        }
    }

    /* 2. Run deployment scenario inference on CPU */
    for (s = 0u; s < 4u; ++s)
    {
        print_scenario(model, scenario_names[s], scenarios[s]);
    }

    /* 3. Verify OpenCL GPU deployment parity & throughput directly on auto-loaded model */
    if (fuzzy_tuner_opencl_init(model, 1024u, DEFAULT_KERNEL_PATH))
    {
        const size_t n = 1024u;
        float *batch_in = (float *)malloc(n * model->input_count * sizeof(float));
        float *cpu_out = (float *)malloc(n * model->output_count * sizeof(float));
        float *gpu_out = (float *)malloc(n * model->output_count * sizeof(float));
        double t0, t1, cpu_ms, gpu_ms;
        float max_diff = 0.0f;
        size_t i;

        for (i = 0u; i < n; ++i)
        {
            memcpy(batch_in + i * model->input_count, scenarios[i % 4u], model->input_count * sizeof(float));
        }

        /* Warmup */
        fuzzy_tuner_predict_batch_mt(model, batch_in, n, cpu_out);
        fuzzy_tuner_opencl_predict(model, batch_in, n, gpu_out);

        t0 = deploy_now_sec();
        fuzzy_tuner_predict_batch_mt(model, batch_in, n, cpu_out);
        t1 = deploy_now_sec();
        cpu_ms = (t1 - t0) * 1000.0;

        t0 = deploy_now_sec();
        fuzzy_tuner_opencl_predict(model, batch_in, n, gpu_out);
        t1 = deploy_now_sec();
        gpu_ms = (t1 - t0) * 1000.0;

        for (i = 0u; i < n * model->output_count; ++i)
        {
            float d = fabsf(cpu_out[i] - gpu_out[i]);
            if (d > max_diff) max_diff = d;
        }

        printf("\nDeployment Batch Inference (%zu samples):\n", n);
        printf("  CPU Multi-Thread (%zu threads): %.2f ms\n", fuzzy_cpu_thread_count(), cpu_ms);
        printf("  OpenCL GPU (%u CUs):           %.2f ms (max CPU-vs-GPU diff: %.6f)\n",
            model->opencl.device_compute_units, gpu_ms, max_diff);

        free(batch_in);
        free(cpu_out);
        free(gpu_out);
    }

#ifdef USE_AUTOGEN_HEADER
    /* 4. Verify bit-exact parity against standalone zero-SQLite auto-generated C network */
    {
        fuzzy_tuner_model_t *autogen_model = smart_hvac_autogen_create_autogen();
        float max_autogen_diff = 0.0f;

        if (autogen_model == NULL)
        {
            fprintf(stderr, "FAIL: Could not construct standalone auto-generated C network.\n");
            fuzzy_tuner_destroy(model);
            return EXIT_FAILURE;
        }

        for (s = 0u; s < 4u; ++s)
        {
            float out_db[FUZZY_TUNER_MAX_OUTPUTS] = {0};
            float out_gen[FUZZY_TUNER_MAX_OUTPUTS] = {0};
            size_t o;
            fuzzy_tuner_predict(model, scenarios[s], out_db);
            fuzzy_tuner_predict(autogen_model, scenarios[s], out_gen);
            for (o = 0u; o < model->output_count; ++o)
            {
                float d = fabsf(out_db[o] - out_gen[o]);
                if (d > max_autogen_diff) max_autogen_diff = d;
            }
        }

        printf("\nStandalone Auto-Generated C Network Verification:\n");
        printf("  Max diff (SQLite autoload vs smart_hvac_autogen.h): %.8f\n", max_autogen_diff);
        if (max_autogen_diff > 1.0e-5f)
        {
            fprintf(stderr, "  FAIL: Auto-generated C network diverged from SQLite model!\n");
            fuzzy_tuner_destroy(autogen_model);
            fuzzy_tuner_destroy(model);
            return EXIT_FAILURE;
        }
        printf("  PASS: Auto-generated standalone C network matches SQLite model bit-for-bit!\n");
        fuzzy_tuner_destroy(autogen_model);
    }
#endif

    if (interactive)
    {
        float user_in[FUZZY_TUNER_MAX_INPUTS] = {0};
        size_t i;
        printf("\nInteractive Deployment Mode\n---------------------------\n");
        for (i = 0u; i < model->input_count; ++i)
        {
            printf("  %s [%.1f, %.1f]: ", model->inputs[i].name, model->inputs[i].minimum, model->inputs[i].maximum);
            fflush(stdout);
            if (scanf("%f", &user_in[i]) != 1)
            {
                break;
            }
        }
        print_scenario(model, "Operator Input", user_in);
    }

    fuzzy_tuner_destroy(model);
    return EXIT_SUCCESS;
}
