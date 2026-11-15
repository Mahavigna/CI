#define _GNU_SOURCE
#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define OUTPUT_DIRECTORY "airfoil-standalone-trained"
#define DATASET_PATH "airfoil_self_noise.dat"

#define DATASET_ROWS 1503u
#define TRAIN_ROWS 1202u
#define TEST_ROWS 301u
#define INPUT_DIMENSIONS 5u
#define PARAMETER_COUNT 20u
#define GRADIENT_CANDIDATE_COUNT (PARAMETER_COUNT * 2u)

#define INPUT_MINIMUM 0.0f
#define INPUT_MAXIMUM 1.0f
#define INPUT_PLOT_STEP 0.01f

#define OUTPUT_MINIMUM 0.0f
#define OUTPUT_MAXIMUM 1.0f
#define OUTPUT_STEP 0.005f

#define TRAIN_EPOCHS 10000u
#define TRAIN_BATCH_SIZE 128u
#define TRAIN_REPORT_INTERVAL 100u
#define TRAIN_LEARNING_RATE 0.0002f
#define TRAIN_ADAM_BETA1 0.9f
#define TRAIN_ADAM_BETA2 0.999f
#define TRAIN_ADAM_EPSILON 0.00000001f
#define TRAIN_GRADIENT_EPSILON 0.0001f
#define TRAIN_SPLIT_SEED 42u
#define TRAIN_BATCH_SEED 42u

#define MEAN_MINIMUM 0.0f
#define MEAN_MAXIMUM 1.0f
#define SIGMA_MINIMUM 0.001f
#define SIGMA_MAXIMUM 1.0f

typedef struct airfoil_dataset
{
    float *inputs;
    float *targets;
    size_t rows;
} airfoil_dataset_t;

typedef struct airfoil_scale
{
    float input_minimum[INPUT_DIMENSIONS];
    float input_maximum[INPUT_DIMENSIONS];
    float target_minimum;
    float target_maximum;
} airfoil_scale_t;

static float airfoil_parameters[PARAMETER_COUNT] =
{
    0.25f,
    0.30f,
    0.75f,
    0.30f,

    0.25f,
    0.30f,
    0.75f,
    0.30f,

    0.25f,
    0.30f,
    0.75f,
    0.30f,

    0.25f,
    0.30f,
    0.75f,
    0.30f,

    0.25f,
    0.30f,
    0.75f,
    0.30f
};

static _Thread_local float airfoil_thread_parameters[PARAMETER_COUNT];

FUZZY_VAR(frequency_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[0], airfoil_thread_parameters[1])
FUZZY_VAR(frequency_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[2], airfoil_thread_parameters[3])

FUZZY_VAR(attack_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[4], airfoil_thread_parameters[5])
FUZZY_VAR(attack_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[6], airfoil_thread_parameters[7])

FUZZY_VAR(chord_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[8], airfoil_thread_parameters[9])
FUZZY_VAR(chord_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[10], airfoil_thread_parameters[11])

FUZZY_VAR(velocity_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[12], airfoil_thread_parameters[13])
FUZZY_VAR(velocity_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[14], airfoil_thread_parameters[15])

FUZZY_VAR(displacement_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[16], airfoil_thread_parameters[17])
FUZZY_VAR(displacement_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, airfoil_thread_parameters[18], airfoil_thread_parameters[19])

FUZZY_VAR(airfoil_output_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.150000000f, 0.200000000f)
FUZZY_VAR(airfoil_output_medium, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.500000000f, 0.200000000f)
FUZZY_VAR(airfoil_output_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.850000000f, 0.200000000f)

static void load_thread_parameters(void)
{
    memcpy(airfoil_thread_parameters, airfoil_parameters, sizeof(airfoil_parameters));
}

static float clamp_parameter(size_t parameter_index, float value)
{
    if ((parameter_index & 1u) == 0u)
    {
        if (value < MEAN_MINIMUM)
        {
            return MEAN_MINIMUM;
        }

        if (value > MEAN_MAXIMUM)
        {
            return MEAN_MAXIMUM;
        }

        return value;
    }

    if (value < SIGMA_MINIMUM)
    {
        return SIGMA_MINIMUM;
    }

    if (value > SIGMA_MAXIMUM)
    {
        return SIGMA_MAXIMUM;
    }

    return value;
}

static void constrain_parameters(void)
{
    size_t parameter_index;

    for (parameter_index = 0u; parameter_index < PARAMETER_COUNT; ++parameter_index)
    {
        airfoil_parameters[parameter_index] = clamp_parameter(parameter_index, airfoil_parameters[parameter_index]);
    }
}

static void capture_parameters(float destination[PARAMETER_COUNT])
{
    size_t parameter_index;

    if (destination == NULL)
    {
        fprintf(stderr, "Invalid parameter capture destination.\n");
        exit(EXIT_FAILURE);
    }

    for (parameter_index = 0u; parameter_index < PARAMETER_COUNT; ++parameter_index)
    {
        destination[parameter_index] = airfoil_parameters[parameter_index];
    }
}

static void restore_parameters(const float source[PARAMETER_COUNT])
{
    size_t parameter_index;

    if (source == NULL)
    {
        fprintf(stderr, "Invalid parameter restoration source.\n");
        exit(EXIT_FAILURE);
    }

    for (parameter_index = 0u; parameter_index < PARAMETER_COUNT; ++parameter_index)
    {
        airfoil_parameters[parameter_index] = source[parameter_index];
    }

    constrain_parameters();
}

static float airfoil_sound_pressure(const float inputs[INPUT_DIMENSIONS], float step)
{
    fuzzy_rules_t rules;
    float result;

    if (inputs == NULL || !(step > 0.0f) || !isfinite(step))
    {
        fprintf(stderr, "Invalid standalone fuzzy evaluation request.\n");
        exit(EXIT_FAILURE);
    }

    rules.count = 0u;

    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Low operating region", SAND(frequency_low(inputs[0]), attack_low(inputs[1]), chord_low(inputs[2]), velocity_low(inputs[3]), displacement_low(inputs[4])), airfoil_output_low);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Frequency dominated region", SAND(frequency_high(inputs[0]), attack_low(inputs[1]), chord_low(inputs[2])), airfoil_output_medium);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Attack or displacement dominated region", SOR(attack_high(inputs[1]), displacement_high(inputs[4])), airfoil_output_high);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Chord and velocity dominated region", SAND(chord_high(inputs[2]), velocity_high(inputs[3])), airfoil_output_high);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Combined high-energy region", SOR(SAND(frequency_high(inputs[0]), velocity_high(inputs[3])), SAND(attack_high(inputs[1]), displacement_high(inputs[4]))), airfoil_output_high);

    result = fuzzy_rules_defuzzify(&rules, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, step, FUZZY_DEFUZZ_COG);

    if (!isfinite(result))
    {
        fprintf(stderr, "Standalone fuzzy COG output is not finite.\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

static float airfoil_sound_pressure_plot(const float inputs[INPUT_DIMENSIONS], float step, const char *plot)
{
    fuzzy_rules_t rules;
    float result;

    if (inputs == NULL || plot == NULL || !(step > 0.0f) || !isfinite(step))
    {
        fprintf(stderr, "Invalid standalone fuzzy plotting request.\n");
        exit(EXIT_FAILURE);
    }

    load_thread_parameters();
    rules.count = 0u;

    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Low operating region", SAND(frequency_low(inputs[0]), attack_low(inputs[1]), chord_low(inputs[2]), velocity_low(inputs[3]), displacement_low(inputs[4])), airfoil_output_low);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Frequency dominated region", SAND(frequency_high(inputs[0]), attack_low(inputs[1]), chord_low(inputs[2])), airfoil_output_medium);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Attack or displacement dominated region", SOR(attack_high(inputs[1]), displacement_high(inputs[4])), airfoil_output_high);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Chord and velocity dominated region", SAND(chord_high(inputs[2]), velocity_high(inputs[3])), airfoil_output_high);
    CATCH_FAILS(FUZZY_RULE_ADD_NAMED, &rules, "Combined high-energy region", SOR(SAND(frequency_high(inputs[0]), velocity_high(inputs[3])), SAND(attack_high(inputs[1]), displacement_high(inputs[4]))), airfoil_output_high);

    result = fuzzy_rules_defuzzify(&rules, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, step, FUZZY_DEFUZZ_COG);

    if (!isfinite(result))
    {
        fprintf(stderr, "Standalone fuzzy COG output is not finite.\n");
        exit(EXIT_FAILURE);
    }

    fuzzy_rules_print(&rules);
    CATCH_FAILS(fuzzy_rules_plot_cog, &rules, plot, "Locally Trained Airfoil COG Defuzzification", result, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, step);

    return result;
}

static float airfoil_sweep(const float inputs[], size_t input_count, float cog_step)
{
    if (inputs == NULL || input_count != INPUT_DIMENSIONS)
    {
        fprintf(stderr, "Invalid airfoil sweep input.\n");
        exit(EXIT_FAILURE);
    }

    load_thread_parameters();
    return airfoil_sound_pressure(inputs, cog_step);
}

static void dataset_allocate(airfoil_dataset_t *dataset, size_t rows)
{
    if (dataset == NULL || rows == 0u)
    {
        fprintf(stderr, "Invalid dataset allocation request.\n");
        exit(EXIT_FAILURE);
    }

    dataset->inputs = malloc(rows * INPUT_DIMENSIONS * sizeof(*dataset->inputs));
    dataset->targets = malloc(rows * sizeof(*dataset->targets));
    dataset->rows = rows;

    if (dataset->inputs == NULL || dataset->targets == NULL)
    {
        free(dataset->inputs);
        free(dataset->targets);

        dataset->inputs = NULL;
        dataset->targets = NULL;
        dataset->rows = 0u;

        fprintf(stderr, "Dataset allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

static void dataset_free(airfoil_dataset_t *dataset)
{
    if (dataset == NULL)
    {
        return;
    }

    free(dataset->inputs);
    free(dataset->targets);

    dataset->inputs = NULL;
    dataset->targets = NULL;
    dataset->rows = 0u;
}

static void load_dataset(airfoil_dataset_t *dataset)
{
    FILE *file;
    size_t row;

    dataset_allocate(dataset, DATASET_ROWS);

    file = fopen(DATASET_PATH, "r");

    if (file == NULL)
    {
        dataset_free(dataset);
        fprintf(stderr, "Failed to open %s.\n", DATASET_PATH);
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        float *input = dataset->inputs + row * INPUT_DIMENSIONS;

        if (fscanf(file, "%f %f %f %f %f %f", &input[0], &input[1], &input[2], &input[3], &input[4], &dataset->targets[row]) != 6)
        {
            fclose(file);
            dataset_free(dataset);
            fprintf(stderr, "Invalid dataset row %zu.\n", row);
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(file) != 0)
    {
        dataset_free(dataset);
        fprintf(stderr, "Failed to close %s.\n", DATASET_PATH);
        exit(EXIT_FAILURE);
    }
}

static void split_dataset(const airfoil_dataset_t *source, airfoil_dataset_t *training, airfoil_dataset_t *test)
{
    size_t order[DATASET_ROWS];
    unsigned int state = TRAIN_SPLIT_SEED;
    size_t row;

    if (source == NULL || source->rows != DATASET_ROWS || training == NULL || test == NULL)
    {
        fprintf(stderr, "Invalid dataset split request.\n");
        exit(EXIT_FAILURE);
    }

    dataset_allocate(training, TRAIN_ROWS);
    dataset_allocate(test, TEST_ROWS);

    for (row = 0u; row < DATASET_ROWS; ++row)
    {
        order[row] = row;
    }

    for (row = DATASET_ROWS; row > 1u; --row)
    {
        size_t selected;
        size_t temporary;

        state = state * 1664525u + 1013904223u;
        selected = (size_t)state % row;

        temporary = order[row - 1u];
        order[row - 1u] = order[selected];
        order[selected] = temporary;
    }

    for (row = 0u; row < TRAIN_ROWS; ++row)
    {
        memcpy(training->inputs + row * INPUT_DIMENSIONS, source->inputs + order[row] * INPUT_DIMENSIONS, INPUT_DIMENSIONS * sizeof(float));
        training->targets[row] = source->targets[order[row]];
    }

    for (row = 0u; row < TEST_ROWS; ++row)
    {
        size_t source_row = order[TRAIN_ROWS + row];

        memcpy(test->inputs + row * INPUT_DIMENSIONS, source->inputs + source_row * INPUT_DIMENSIONS, INPUT_DIMENSIONS * sizeof(float));
        test->targets[row] = source->targets[source_row];
    }
}

static void normalize_datasets(airfoil_dataset_t *training, airfoil_dataset_t *test, airfoil_scale_t *scale)
{
    size_t row;
    size_t dimension;
    float target_range;

    if (training == NULL || test == NULL || scale == NULL || training->rows == 0u)
    {
        fprintf(stderr, "Invalid normalization request.\n");
        exit(EXIT_FAILURE);
    }

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        scale->input_minimum[dimension] = training->inputs[dimension];
        scale->input_maximum[dimension] = training->inputs[dimension];
    }

    scale->target_minimum = training->targets[0];
    scale->target_maximum = training->targets[0];

    for (row = 0u; row < training->rows; ++row)
    {
        for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
        {
            float value = training->inputs[row * INPUT_DIMENSIONS + dimension];

            scale->input_minimum[dimension] = fminf(scale->input_minimum[dimension], value);
            scale->input_maximum[dimension] = fmaxf(scale->input_maximum[dimension], value);
        }

        scale->target_minimum = fminf(scale->target_minimum, training->targets[row]);
        scale->target_maximum = fmaxf(scale->target_maximum, training->targets[row]);
    }

    target_range = scale->target_maximum - scale->target_minimum;

    if (!(target_range > 0.0f))
    {
        fprintf(stderr, "Target normalization range is invalid.\n");
        exit(EXIT_FAILURE);
    }

    for (row = 0u; row < training->rows; ++row)
    {
        for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
        {
            size_t index = row * INPUT_DIMENSIONS + dimension;
            float range = scale->input_maximum[dimension] - scale->input_minimum[dimension];

            if (!(range > 0.0f))
            {
                fprintf(stderr, "Input dimension %zu has no normalization range.\n", dimension);
                exit(EXIT_FAILURE);
            }

            training->inputs[index] = (training->inputs[index] - scale->input_minimum[dimension]) / range;
        }

        training->targets[row] = (training->targets[row] - scale->target_minimum) / target_range;
    }

    for (row = 0u; row < test->rows; ++row)
    {
        for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
        {
            size_t index = row * INPUT_DIMENSIONS + dimension;
            float range = scale->input_maximum[dimension] - scale->input_minimum[dimension];

            if (!(range > 0.0f))
            {
                fprintf(stderr, "Input dimension %zu has no normalization range.\n", dimension);
                exit(EXIT_FAILURE);
            }

            test->inputs[index] = (test->inputs[index] - scale->input_minimum[dimension]) / range;
        }

        test->targets[row] = (test->targets[row] - scale->target_minimum) / target_range;
    }
}

static double dataset_mse(const airfoil_dataset_t *dataset)
{
    double total = 0.0;
    size_t row;

    if (dataset == NULL || dataset->rows == 0u)
    {
        fprintf(stderr, "Invalid MSE request.\n");
        exit(EXIT_FAILURE);
    }

    #pragma omp parallel reduction(+:total)
    {
        load_thread_parameters();

        #pragma omp for schedule(static)
        for (row = 0u; row < dataset->rows; ++row)
        {
            float prediction = airfoil_sound_pressure(dataset->inputs + row * INPUT_DIMENSIONS, OUTPUT_STEP);
            double error = (double)prediction - dataset->targets[row];

            total += error * error;
        }
    }

    return total / (double)dataset->rows;
}

static void select_batch(size_t batch_indices[TRAIN_BATCH_SIZE], unsigned int *state)
{
    size_t index;

    if (batch_indices == NULL || state == NULL)
    {
        fprintf(stderr, "Invalid batch selection request.\n");
        exit(EXIT_FAILURE);
    }

    for (index = 0u; index < TRAIN_BATCH_SIZE; ++index)
    {
        *state = *state * 1664525u + 1013904223u;
        batch_indices[index] = (size_t)(*state) % TRAIN_ROWS;
    }
}

static void numerical_gradients(const airfoil_dataset_t *training, const size_t batch_indices[TRAIN_BATCH_SIZE], float gradients[PARAMETER_COUNT])
{
    double candidate_losses[GRADIENT_CANDIDATE_COUNT];
    size_t candidate_index;
    size_t parameter_index;

    if (training == NULL || batch_indices == NULL || gradients == NULL)
    {
        fprintf(stderr, "Invalid gradient request.\n");
        exit(EXIT_FAILURE);
    }

    #pragma omp parallel for schedule(static)
    for (candidate_index = 0u; candidate_index < GRADIENT_CANDIDATE_COUNT; ++candidate_index)
    {
        size_t candidate_parameter = candidate_index / 2u;
        size_t batch_index;
        float direction = (candidate_index & 1u) == 0u ? 1.0f : -1.0f;
        double total = 0.0;

        load_thread_parameters();
        airfoil_thread_parameters[candidate_parameter] = clamp_parameter(candidate_parameter, airfoil_thread_parameters[candidate_parameter] + direction * TRAIN_GRADIENT_EPSILON);

        for (batch_index = 0u; batch_index < TRAIN_BATCH_SIZE; ++batch_index)
        {
            size_t row = batch_indices[batch_index];
            float prediction = airfoil_sound_pressure(training->inputs + row * INPUT_DIMENSIONS, OUTPUT_STEP);
            double error = (double)prediction - training->targets[row];

            total += error * error;
        }

        candidate_losses[candidate_index] = total / (double)TRAIN_BATCH_SIZE;
    }

    for (parameter_index = 0u; parameter_index < PARAMETER_COUNT; ++parameter_index)
    {
        float positive = clamp_parameter(parameter_index, airfoil_parameters[parameter_index] + TRAIN_GRADIENT_EPSILON);
        float negative = clamp_parameter(parameter_index, airfoil_parameters[parameter_index] - TRAIN_GRADIENT_EPSILON);
        float denominator = positive - negative;

        if (!(denominator > 0.0f))
        {
            gradients[parameter_index] = 0.0f;
            continue;
        }

        gradients[parameter_index] = (float)((candidate_losses[parameter_index * 2u] - candidate_losses[parameter_index * 2u + 1u]) / (double)denominator);

        if (!isfinite(gradients[parameter_index]))
        {
            fprintf(stderr, "Gradient %zu is not finite.\n", parameter_index);
            exit(EXIT_FAILURE);
        }
    }
}

static void train_memberships(const airfoil_dataset_t *training)
{
    float first_moment[PARAMETER_COUNT] = {0};
    float second_moment[PARAMETER_COUNT] = {0};
    float gradients[PARAMETER_COUNT];
    float best_parameters[PARAMETER_COUNT];
    size_t batch_indices[TRAIN_BATCH_SIZE];
    unsigned int batch_state = TRAIN_BATCH_SEED;
    double best_mse;
    size_t best_epoch = 0u;
    size_t epoch;
    size_t parameter_index;

    if (training == NULL || training->rows != TRAIN_ROWS)
    {
        fprintf(stderr, "Invalid membership training dataset.\n");
        exit(EXIT_FAILURE);
    }

    constrain_parameters();

    best_mse = dataset_mse(training);
    capture_parameters(best_parameters);

    printf("epoch=0 training_mse=%.12g best_mse=%.12g\n", best_mse, best_mse);
    fflush(stdout);

    for (epoch = 1u; epoch <= TRAIN_EPOCHS; ++epoch)
    {
        float beta1_power;
        float beta2_power;

        select_batch(batch_indices, &batch_state);
        numerical_gradients(training, batch_indices, gradients);

        beta1_power = powf(TRAIN_ADAM_BETA1, (float)epoch);
        beta2_power = powf(TRAIN_ADAM_BETA2, (float)epoch);

        for (parameter_index = 0u; parameter_index < PARAMETER_COUNT; ++parameter_index)
        {
            float corrected_first;
            float corrected_second;
            float update;

            first_moment[parameter_index] = TRAIN_ADAM_BETA1 * first_moment[parameter_index] + (1.0f - TRAIN_ADAM_BETA1) * gradients[parameter_index];
            second_moment[parameter_index] = TRAIN_ADAM_BETA2 * second_moment[parameter_index] + (1.0f - TRAIN_ADAM_BETA2) * gradients[parameter_index] * gradients[parameter_index];

            corrected_first = first_moment[parameter_index] / (1.0f - beta1_power);
            corrected_second = second_moment[parameter_index] / (1.0f - beta2_power);
            update = TRAIN_LEARNING_RATE * corrected_first / (sqrtf(corrected_second) + TRAIN_ADAM_EPSILON);

            airfoil_parameters[parameter_index] = clamp_parameter(parameter_index, airfoil_parameters[parameter_index] - update);
        }

        constrain_parameters();

        if (epoch % TRAIN_REPORT_INTERVAL == 0u || epoch == TRAIN_EPOCHS)
        {
            double training_mse = dataset_mse(training);

            if (training_mse < best_mse)
            {
                best_mse = training_mse;
                best_epoch = epoch;
                capture_parameters(best_parameters);
            }

            printf("epoch=%zu training_mse=%.12g best_epoch=%zu best_mse=%.12g\n", epoch, training_mse, best_epoch, best_mse);
            fflush(stdout);
        }
    }

    restore_parameters(best_parameters);

    printf("restored_best_epoch=%zu\n", best_epoch);
    printf("restored_best_training_mse=%.12g\n", best_mse);
    fflush(stdout);
}

static void print_trained_memberships(void)
{
    printf("\n");
    printf("FUZZY_VAR(frequency_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[0], airfoil_parameters[1]);
    printf("FUZZY_VAR(frequency_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[2], airfoil_parameters[3]);

    printf("\n");
    printf("FUZZY_VAR(attack_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[4], airfoil_parameters[5]);
    printf("FUZZY_VAR(attack_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[6], airfoil_parameters[7]);

    printf("\n");
    printf("FUZZY_VAR(chord_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[8], airfoil_parameters[9]);
    printf("FUZZY_VAR(chord_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[10], airfoil_parameters[11]);

    printf("\n");
    printf("FUZZY_VAR(velocity_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[12], airfoil_parameters[13]);
    printf("FUZZY_VAR(velocity_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[14], airfoil_parameters[15]);

    printf("\n");
    printf("FUZZY_VAR(displacement_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[16], airfoil_parameters[17]);
    printf("FUZZY_VAR(displacement_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, %.9ff, %.9ff)\n", airfoil_parameters[18], airfoil_parameters[19]);

    printf("\n");
    printf("FUZZY_VAR(airfoil_output_low, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.150000000f, 0.200000000f)\n");
    printf("FUZZY_VAR(airfoil_output_medium, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.500000000f, 0.200000000f)\n");
    printf("FUZZY_VAR(airfoil_output_high, FUZZY_SHAPE_GAUSSIAN, 1.000000000f, 0.850000000f, 0.200000000f)\n");
    printf("\n");

    fflush(stdout);
}

static void plot_trained_system(void)
{
    load_thread_parameters();

    CATCH_FAILS(PLOT, OUTPUT_DIRECTORY "/frequency_memberships", "Locally Trained Frequency Membership Functions", INPUT_MAXIMUM, INPUT_PLOT_STEP, SERIES(frequency_low, "#3b82f6"), SERIES(frequency_high, "#ef4444"));
    CATCH_FAILS(PLOT, OUTPUT_DIRECTORY "/attack_memberships", "Locally Trained Attack Membership Functions", INPUT_MAXIMUM, INPUT_PLOT_STEP, SERIES(attack_low, "#3b82f6"), SERIES(attack_high, "#ef4444"));
    CATCH_FAILS(PLOT, OUTPUT_DIRECTORY "/chord_memberships", "Locally Trained Chord Membership Functions", INPUT_MAXIMUM, INPUT_PLOT_STEP, SERIES(chord_low, "#3b82f6"), SERIES(chord_high, "#ef4444"));
    CATCH_FAILS(PLOT, OUTPUT_DIRECTORY "/velocity_memberships", "Locally Trained Velocity Membership Functions", INPUT_MAXIMUM, INPUT_PLOT_STEP, SERIES(velocity_low, "#3b82f6"), SERIES(velocity_high, "#ef4444"));
    CATCH_FAILS(PLOT, OUTPUT_DIRECTORY "/displacement_memberships", "Locally Trained Displacement Membership Functions", INPUT_MAXIMUM, INPUT_PLOT_STEP, SERIES(displacement_low, "#3b82f6"), SERIES(displacement_high, "#ef4444"));
    CATCH_FAILS(PLOT, OUTPUT_DIRECTORY "/output_memberships", "Fixed Airfoil Output Membership Functions", OUTPUT_MAXIMUM, OUTPUT_STEP, SERIES(airfoil_output_low, "#3b82f6"), SERIES(airfoil_output_medium, "#22c55e"), SERIES(airfoil_output_high, "#ef4444"));
    CATCH_FAILS(FUZZY_COG_SWEEP_RANGE, OUTPUT_DIRECTORY "/airfoil_cog_sweep", "Locally Trained Standalone Airfoil COG Sweep", airfoil_sweep, OUTPUT_STEP, OUTPUT_MINIMUM, OUTPUT_MAXIMUM, FUZZY_SWEEP_DIMENSION("Frequency", INPUT_MINIMUM, INPUT_MAXIMUM, 0.10f), FUZZY_SWEEP_DIMENSION("Attack", INPUT_MINIMUM, INPUT_MAXIMUM, 0.10f), FUZZY_SWEEP_DIMENSION("Chord", INPUT_MINIMUM, INPUT_MAXIMUM, 0.10f), FUZZY_SWEEP_DIMENSION("Velocity", INPUT_MINIMUM, INPUT_MAXIMUM, 0.10f), FUZZY_SWEEP_DIMENSION("Displacement", INPUT_MINIMUM, INPUT_MAXIMUM, 0.10f));
}

static float normalize_input_value(const airfoil_scale_t *scale, size_t dimension, float value)
{
    float range;
    float normalized;

    if (scale == NULL || dimension >= INPUT_DIMENSIONS || !isfinite(value))
    {
        fprintf(stderr, "Invalid input normalization request.\n");
        exit(EXIT_FAILURE);
    }

    range = scale->input_maximum[dimension] - scale->input_minimum[dimension];

    if (!(range > 0.0f) || !isfinite(range))
    {
        fprintf(stderr, "Input dimension %zu has an invalid normalization range.\n", dimension);
        exit(EXIT_FAILURE);
    }

    normalized = (value - scale->input_minimum[dimension]) / range;

    if (!isfinite(normalized))
    {
        fprintf(stderr, "Normalized input dimension %zu is not finite.\n", dimension);
        exit(EXIT_FAILURE);
    }

    return normalized;
}

static float denormalize_target_value(const airfoil_scale_t *scale, float normalized)
{
    float range;
    float result;

    if (scale == NULL || !isfinite(normalized))
    {
        fprintf(stderr, "Invalid target denormalization request.\n");
        exit(EXIT_FAILURE);
    }

    range = scale->target_maximum - scale->target_minimum;

    if (!(range > 0.0f) || !isfinite(range))
    {
        fprintf(stderr, "Target denormalization range is invalid.\n");
        exit(EXIT_FAILURE);
    }

    result = scale->target_minimum + normalized * range;

    if (!isfinite(result))
    {
        fprintf(stderr, "Denormalized target is not finite.\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

static void predict_interactively(const airfoil_scale_t *scale)
{
    static const char *input_names[INPUT_DIMENSIONS] =
    {
        "Frequency (Hz)",
        "Attack angle (degrees)",
        "Chord length (m)",
        "Velocity (m/s)",
        "Displacement thickness (m)"
    };

    float raw_inputs[INPUT_DIMENSIONS];
    float normalized_inputs[INPUT_DIMENSIONS];
    float normalized_result;
    float physical_result;
    size_t dimension;

    if (scale == NULL)
    {
        fprintf(stderr, "Interactive prediction scale is missing.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("Locally Trained Standalone Airfoil Fuzzy System\n");
    printf("===============================================\n");
    printf("Enter raw physical input values.\n");
    printf("\n");

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        printf("%s [%.9g, %.9g]: ", input_names[dimension], scale->input_minimum[dimension], scale->input_maximum[dimension]);
        fflush(stdout);

        if (scanf("%f", &raw_inputs[dimension]) != 1 || !isfinite(raw_inputs[dimension]))
        {
            fprintf(stderr, "Invalid %s input.\n", input_names[dimension]);
            exit(EXIT_FAILURE);
        }

        if (raw_inputs[dimension] < scale->input_minimum[dimension] || raw_inputs[dimension] > scale->input_maximum[dimension])
        {
            fprintf(stderr, "%s must be within the training range [%.9g, %.9g].\n", input_names[dimension], scale->input_minimum[dimension], scale->input_maximum[dimension]);
            exit(EXIT_FAILURE);
        }

        normalized_inputs[dimension] = normalize_input_value(scale, dimension, raw_inputs[dimension]);

        if (normalized_inputs[dimension] < INPUT_MINIMUM || normalized_inputs[dimension] > INPUT_MAXIMUM)
        {
            fprintf(stderr, "Normalized %s input is outside [0, 1].\n", input_names[dimension]);
            exit(EXIT_FAILURE);
        }
    }

    normalized_result = airfoil_sound_pressure_plot(normalized_inputs, OUTPUT_STEP, OUTPUT_DIRECTORY "/cog");

    if (normalized_result < OUTPUT_MINIMUM || normalized_result > OUTPUT_MAXIMUM)
    {
        fprintf(stderr, "Normalized fuzzy output %.9g is outside [%.9g, %.9g].\n", normalized_result, OUTPUT_MINIMUM, OUTPUT_MAXIMUM);
        exit(EXIT_FAILURE);
    }

    physical_result = denormalize_target_value(scale, normalized_result);

    printf("\n");
    printf("Normalized inputs:\n");

    for (dimension = 0u; dimension < INPUT_DIMENSIONS; ++dimension)
    {
        printf("  %s: %.9f\n", input_names[dimension], normalized_inputs[dimension]);
    }

    printf("\n");
    printf("Normalized fuzzy output: %.9f\n", normalized_result);
    printf("Predicted sound pressure level: %.9f dB\n", physical_result);
}

int main(void)
{
    airfoil_dataset_t complete = {0};
    airfoil_dataset_t training = {0};
    airfoil_dataset_t test = {0};
    airfoil_scale_t scale;
    double initial_training_mse;
    double initial_test_mse;
    double final_training_mse;
    double final_test_mse;

    int processor_count = omp_get_num_procs();
    int worker_count = processor_count;

    if (worker_count < 1)
    {
        fprintf(stderr, "OpenMP reported no available processors.\n");
        return EXIT_FAILURE;
    }

    if (worker_count > (int)GRADIENT_CANDIDATE_COUNT)
    {
        worker_count = (int)GRADIENT_CANDIDATE_COUNT;
    }

    omp_set_dynamic(0);
    omp_set_num_threads(worker_count);
    omp_set_max_active_levels(1);

    printf("openmp_processors=%d openmp_workers=%d gradient_jobs=%u\n", processor_count, worker_count, (unsigned int)GRADIENT_CANDIDATE_COUNT);
    fflush(stdout);

    load_dataset(&complete);
    split_dataset(&complete, &training, &test);
    normalize_datasets(&training, &test, &scale);

    initial_training_mse = dataset_mse(&training);
    initial_test_mse = dataset_mse(&test);

    printf("initial_training_mse=%.12g\n", initial_training_mse);
    printf("initial_test_mse=%.12g\n", initial_test_mse);

    train_memberships(&training);

    final_training_mse = dataset_mse(&training);
    final_test_mse = dataset_mse(&test);

    printf("final_training_mse=%.12g\n", final_training_mse);
    printf("final_test_mse=%.12g\n", final_test_mse);

    print_trained_memberships();
    plot_trained_system();
    predict_interactively(&scale);

    dataset_free(&complete);
    dataset_free(&training);
    dataset_free(&test);

    return EXIT_SUCCESS;
}