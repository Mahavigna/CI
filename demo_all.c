/*
 * Complete fuzzy.h demonstration.
 *
 * This program exercises the largest practical portion of
 * the fuzzy.h public API using a five-input industrial
 * process-response system.
 *
 * Crisp inputs:
 *
 * 1. Temperature
 * 2. Humidity
 * 3. Vibration
 * 4. Pressure
 * 5. Material quality
 *
 * Crisp output:
 *
 * - Process response level
 *
 * Demonstrated features:
 *
 * - Ramp membership functions
 * - Triangle membership functions
 * - Trapezoid membership functions
 * - S-shaped membership functions
 * - Z-shaped membership functions
 * - Pi-shaped membership functions
 * - Gaussian membership functions
 * - Two-sided Gaussian membership functions
 * - Generalized bell membership functions
 * - Sigmoid membership functions
 * - Difference-of-sigmoids membership functions
 * - Product-of-sigmoids membership functions
 * - Five-dimensional sampled-membership interpolation
 * - Linguistic hedges
 * - Fuzzy AND
 * - Fuzzy OR
 * - Nested fuzzy expressions
 * - Minimum and product implication
 * - Maximum, algebraic, and bounded aggregation
 * - Mamdani rule aggregation
 * - COG defuzzification
 * - Membership-function SVG plots
 * - Selected COG SVG plot
 * - Five-dimensional membership interpolation sweep CSV
 * - Interactive five-dimensional membership sweep SVG
 * - Five-dimensional COG sweep CSV
 * - Interactive five-dimensional COG sweep SVG
 * - Random crisp input generation
 */

#include <time.h>

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"


/* ==========================================================
 * Output paths and numerical ranges
 * ========================================================== */

#define DEMO_DIRECTORY              "demo-all"

#define RESPONSE_LOWER              0.0f
#define RESPONSE_UPPER              100.0f

#define NORMAL_COG_STEP             0.1f
#define SWEEP_COG_STEP              1.0f


/* ==========================================================
 * User-defined linguistic hedge exponents
 * ========================================================== */

static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};

/* ==========================================================
 * Randomized membership-function parameters
 *
 * Parameters are generated once when the program starts.
 * They remain fixed during plotting, rule evaluation,
 * defuzzification, and the complete N-dimensional sweep.
 * ========================================================== */

typedef struct RandomFuzzyParameters {
    /*
     * Temperature.
     */
    float temperature_low[2];
    float temperature_medium[2];
    float temperature_high[2];

    /*
     * Humidity.
     */
    float humidity_low[2];
    float humidity_medium[4];
    float humidity_high[2];

    /*
     * Vibration.
     */
    float vibration_low[2];
    float vibration_medium[3];
    float vibration_high[2];

    /*
     * Pressure.
     */
    float pressure_low[2];
    float pressure_normal[3];
    float pressure_high[2];

    /*
     * Material quality.
     */
    float quality_poor[2];
    float quality_average[2];
    float quality_good[2];

    /*
     * Process response.
     */
    float response_minimal[2];
    float response_low[3];
    float response_moderate[4];
    float response_high[3];
    float response_critical[2];

    /*
     * Generic shape demonstration.
     */
    float shape_ramp[2];
    float shape_triangle[3];
    float shape_trapezoid[4];
    float shape_smf[2];
    float shape_zmf[2];
    float shape_pimf[4];
    float shape_gauss[2];
    float shape_gauss2[4];
    float shape_bell[3];
    float shape_sigmoid[2];
    float shape_dsigmoid[4];
    float shape_psigmoid[4];

    /*
     * Shared randomized trapezoid for hedge comparison.
     *
     * Every hedge must use the same base function so the
     * only visible difference is the hedge exponent.
     */
    float hedge_trapezoid[4];
} random_fuzzy_parameters_t;


static random_fuzzy_parameters_t parameters;

/* ==========================================================
 * Randomized fuzzy-NOT rule
 *
 * One NOT-based rule is selected when the application starts.
 * The selection remains fixed throughout plotting, normal
 * evaluation, and the complete five-dimensional sweep.
 *
 * Random selection must not occur inside build_process_rules()
 * because every sweep point must use the same fuzzy system.
 * ========================================================== */

typedef enum RandomNotRule {
    RANDOM_NOT_TEMPERATURE_HIGH = 0,
    RANDOM_NOT_HUMIDITY_LOW,
    RANDOM_NOT_VIBRATION_LOW,
    RANDOM_NOT_PRESSURE_HIGH,
    RANDOM_NOT_QUALITY_GOOD,

    RANDOM_NOT_RULE_COUNT
} random_not_rule_t;


static random_not_rule_t random_not_rule = RANDOM_NOT_TEMPERATURE_HIGH;

static float random_float(float lower, float upper)
{
    return lower + (float)rand() / (float)RAND_MAX * (upper - lower);
}

static void random_ordered_2(float output[2], float lower, float upper, float gap)
{
    output[0] = random_float(lower, upper - gap);
    output[1] = random_float(output[0] + gap, upper);
}

static void random_ordered_3(float output[3], float lower, float upper, float gap)
{
    output[0] = random_float(lower, upper - 2.0f * gap);
    output[1] = random_float(output[0] + gap, upper - gap);
    output[2] = random_float(output[1] + gap, upper);
}

static void random_ordered_4(float output[4], float lower, float upper, float gap)
{
    output[0] = random_float(lower, upper - 3.0f * gap);
    output[1] = random_float(output[0] + gap, upper - 2.0f * gap);
    output[2] = random_float(output[1] + gap, upper - gap);
    output[3] = random_float(output[2] + gap, upper);
}


/*
 * Generate all membership-function parameters once.
 *
 * The ranges are constrained so linguistic terms remain
 * meaningful:
 *
 * - Low functions remain toward the lower region.
 * - Medium functions remain around the middle region.
 * - High functions remain toward the upper region.
 * - Triangle and trapezoid points remain strictly ordered.
 * - Gaussian deviation remains positive.
 * - Bell width and slope remain positive.
 */
static void randomize_membership_parameters(void)
{
    random_ordered_2(parameters.temperature_low, 10.0f, 48.0f, 8.0f);
    parameters.temperature_medium[0] = random_float(38.0f, 62.0f);
    parameters.temperature_medium[1] = random_float(8.0f, 20.0f);
    random_ordered_2(parameters.temperature_high, 52.0f, 95.0f, 8.0f);

    random_ordered_2(parameters.humidity_low, 10.0f, 48.0f, 8.0f);
    random_ordered_4(parameters.humidity_medium, 18.0f, 82.0f, 8.0f);
    parameters.humidity_high[0] = random_float(0.07f, 0.20f);
    parameters.humidity_high[1] = random_float(55.0f, 78.0f);

    random_ordered_2(parameters.vibration_low, 0.5f, 4.8f, 1.0f);
    parameters.vibration_medium[0] = random_float(3.0f, 6.5f);
    parameters.vibration_medium[1] = random_float(1.5f, 4.0f);
    parameters.vibration_medium[2] = random_float(3.5f, 6.5f);
    random_ordered_2(parameters.vibration_high, 5.0f, 9.8f, 1.0f);

    random_ordered_2(parameters.pressure_low, 20.0f, 95.0f, 20.0f);
    random_ordered_3(parameters.pressure_normal, 45.0f, 175.0f, 25.0f);
    parameters.pressure_high[0] = random_float(0.035f, 0.095f);
    parameters.pressure_high[1] = random_float(125.0f, 170.0f);

    random_ordered_2(parameters.quality_poor, 10.0f, 52.0f, 10.0f);
    parameters.quality_average[0] = random_float(42.0f, 65.0f);
    parameters.quality_average[1] = random_float(8.0f, 20.0f);
    random_ordered_2(parameters.quality_good, 50.0f, 96.0f, 10.0f);

    random_ordered_2(parameters.response_minimal, 5.0f, 35.0f, 8.0f);
    random_ordered_3(parameters.response_low, 5.0f, 55.0f, 10.0f);
    random_ordered_4(parameters.response_moderate, 22.0f, 76.0f, 8.0f);
    random_ordered_3(parameters.response_high, 48.0f, 95.0f, 8.0f);
    random_ordered_2(parameters.response_critical, 68.0f, 99.0f, 7.0f);

    random_ordered_2(parameters.shape_ramp, 10.0f, 90.0f, 20.0f);
    random_ordered_3(parameters.shape_triangle, 5.0f, 95.0f, 15.0f);
    random_ordered_4(parameters.shape_trapezoid, 5.0f, 95.0f, 12.0f);
    random_ordered_2(parameters.shape_smf, 10.0f, 90.0f, 20.0f);
    random_ordered_2(parameters.shape_zmf, 10.0f, 90.0f, 20.0f);
    random_ordered_4(parameters.shape_pimf, 5.0f, 95.0f, 12.0f);

    parameters.shape_gauss[0] = random_float(30.0f, 70.0f);
    parameters.shape_gauss[1] = random_float(8.0f, 22.0f);

    parameters.shape_gauss2[0] = random_float(20.0f, 40.0f);
    parameters.shape_gauss2[1] = random_float(6.0f, 15.0f);
    parameters.shape_gauss2[2] = random_float(60.0f, 80.0f);
    parameters.shape_gauss2[3] = random_float(6.0f, 15.0f);

    parameters.shape_bell[0] = random_float(20.0f, 55.0f);
    parameters.shape_bell[1] = random_float(1.5f, 4.0f);
    parameters.shape_bell[2] = random_float(30.0f, 70.0f);

    parameters.shape_sigmoid[0] = random_float(0.06f, 0.20f);
    parameters.shape_sigmoid[1] = random_float(30.0f, 70.0f);

    parameters.shape_dsigmoid[0] = random_float(0.08f, 0.20f);
    parameters.shape_dsigmoid[1] = random_float(20.0f, 40.0f);
    parameters.shape_dsigmoid[2] = random_float(0.08f, 0.20f);
    parameters.shape_dsigmoid[3] = random_float(60.0f, 80.0f);

    parameters.shape_psigmoid[0] = random_float(0.08f, 0.20f);
    parameters.shape_psigmoid[1] = random_float(20.0f, 40.0f);
    parameters.shape_psigmoid[2] = -random_float(0.08f, 0.20f);
    parameters.shape_psigmoid[3] = random_float(60.0f, 80.0f);

    random_ordered_4(parameters.hedge_trapezoid, 5.0f, 95.0f, 12.0f);
    random_not_rule = (random_not_rule_t)(rand() % RANDOM_NOT_RULE_COUNT);
}

/* ==========================================================
 * Randomized temperature membership functions
 * ========================================================== */
FUZZY_VAR(temperature_low, FUZZY_SHAPE_ZMF, hedges.none, parameters.temperature_low[0], parameters.temperature_low[1])

FUZZY_VAR(temperature_medium, FUZZY_SHAPE_GAUSSIAN, hedges.none, parameters.temperature_medium[0], parameters.temperature_medium[1])

FUZZY_VAR(temperature_high, FUZZY_SHAPE_SMF, hedges.none, parameters.temperature_high[0], parameters.temperature_high[1])

FUZZY_VAR(humidity_low, FUZZY_SHAPE_RAMP, hedges.none, parameters.humidity_low[0], parameters.humidity_low[1], false)

FUZZY_VAR(humidity_medium, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.humidity_medium[0], parameters.humidity_medium[1], parameters.humidity_medium[2], parameters.humidity_medium[3])

FUZZY_VAR(humidity_high, FUZZY_SHAPE_SIGMOID, hedges.none, parameters.humidity_high[0], parameters.humidity_high[1])

FUZZY_VAR(vibration_low, FUZZY_SHAPE_ZMF, hedges.none, parameters.vibration_low[0], parameters.vibration_low[1])

FUZZY_VAR(vibration_medium, FUZZY_SHAPE_BELL, hedges.none, parameters.vibration_medium[0], parameters.vibration_medium[1], parameters.vibration_medium[2])

FUZZY_VAR(vibration_high, FUZZY_SHAPE_SMF, hedges.none, parameters.vibration_high[0], parameters.vibration_high[1])

FUZZY_VAR(pressure_low, FUZZY_SHAPE_RAMP, hedges.none, parameters.pressure_low[0], parameters.pressure_low[1], false)

FUZZY_VAR(pressure_normal, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.pressure_normal[0], parameters.pressure_normal[1], parameters.pressure_normal[2])

FUZZY_VAR(pressure_high, FUZZY_SHAPE_SIGMOID, hedges.none, parameters.pressure_high[0], parameters.pressure_high[1])

FUZZY_VAR(quality_poor, FUZZY_SHAPE_ZMF, hedges.none, parameters.quality_poor[0], parameters.quality_poor[1])

FUZZY_VAR(quality_average, FUZZY_SHAPE_GAUSSIAN, hedges.none, parameters.quality_average[0], parameters.quality_average[1])

FUZZY_VAR(quality_good, FUZZY_SHAPE_SMF, hedges.none, parameters.quality_good[0], parameters.quality_good[1])

FUZZY_VAR(response_minimal, FUZZY_SHAPE_ZMF, hedges.none, parameters.response_minimal[0], parameters.response_minimal[1])

FUZZY_VAR(response_low, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.response_low[0], parameters.response_low[1], parameters.response_low[2])

FUZZY_VAR(response_moderate, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.response_moderate[0], parameters.response_moderate[1], parameters.response_moderate[2], parameters.response_moderate[3])

FUZZY_VAR(response_high, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.response_high[0], parameters.response_high[1], parameters.response_high[2])

FUZZY_VAR(response_critical, FUZZY_SHAPE_SMF, hedges.none, parameters.response_critical[0], parameters.response_critical[1])

FUZZY_VAR(hedge_none_demo, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_very_demo, FUZZY_SHAPE_TRAPEZOID, hedges.very, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_extremely_demo, FUZZY_SHAPE_TRAPEZOID, hedges.extremely, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_somewhat_demo, FUZZY_SHAPE_TRAPEZOID, hedges.somewhat, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(hedge_slightly_demo, FUZZY_SHAPE_TRAPEZOID, hedges.slightly, parameters.hedge_trapezoid[0], parameters.hedge_trapezoid[1], parameters.hedge_trapezoid[2], parameters.hedge_trapezoid[3])

FUZZY_VAR(shape_ramp_demo, FUZZY_SHAPE_RAMP, hedges.none, parameters.shape_ramp[0], parameters.shape_ramp[1], true)

FUZZY_VAR(shape_triangle_demo, FUZZY_SHAPE_TRIANGLE, hedges.none, parameters.shape_triangle[0], parameters.shape_triangle[1], parameters.shape_triangle[2])

FUZZY_VAR(shape_trapezoid_demo, FUZZY_SHAPE_TRAPEZOID, hedges.none, parameters.shape_trapezoid[0], parameters.shape_trapezoid[1], parameters.shape_trapezoid[2], parameters.shape_trapezoid[3])

FUZZY_VAR(shape_smf_demo, FUZZY_SHAPE_SMF, hedges.none, parameters.shape_smf[0], parameters.shape_smf[1])

FUZZY_VAR(shape_zmf_demo, FUZZY_SHAPE_ZMF, hedges.none, parameters.shape_zmf[0], parameters.shape_zmf[1])

FUZZY_VAR(shape_pimf_demo, FUZZY_SHAPE_PIMF, hedges.none, parameters.shape_pimf[0], parameters.shape_pimf[1], parameters.shape_pimf[2], parameters.shape_pimf[3])

FUZZY_VAR(shape_gauss_demo, FUZZY_SHAPE_GAUSSIAN, hedges.none, parameters.shape_gauss[0], parameters.shape_gauss[1])

FUZZY_VAR(shape_gauss2_demo, FUZZY_SHAPE_GAUSSIAN2, hedges.none, parameters.shape_gauss2[0], parameters.shape_gauss2[1], parameters.shape_gauss2[2], parameters.shape_gauss2[3])

FUZZY_VAR(shape_bell_demo, FUZZY_SHAPE_BELL, hedges.none, parameters.shape_bell[0], parameters.shape_bell[1], parameters.shape_bell[2])

FUZZY_VAR(shape_sigmoid_demo, FUZZY_SHAPE_SIGMOID, hedges.none, parameters.shape_sigmoid[0], parameters.shape_sigmoid[1])

FUZZY_VAR(shape_dsigmoid_demo, FUZZY_SHAPE_DSIGMOID, hedges.none, parameters.shape_dsigmoid[0], parameters.shape_dsigmoid[1], parameters.shape_dsigmoid[2], parameters.shape_dsigmoid[3])

FUZZY_VAR(shape_psigmoid_demo, FUZZY_SHAPE_PSIGMOID, hedges.none, parameters.shape_psigmoid[0], parameters.shape_psigmoid[1], parameters.shape_psigmoid[2], parameters.shape_psigmoid[3])

/* ==========================================================
 * Five-dimensional sampled-membership interpolation
 *
 * Axis order:
 *
 * 1. Temperature
 * 2. Humidity
 * 3. Vibration
 * 4. Pressure
 * 5. Material quality
 * ========================================================== */

static float sampled_membership_coordinates[5][5];
static fuzzy_point_t sampled_membership_points[5];



/* ==========================================================
 * Randomized fuzzy-NOT rule evaluation
 *
 * The selected rule remains fixed for the complete run.
 *
 * Possible rules:
 *
 * 1. IF temperature is NOT high
 *    AND pressure is normal
 *    THEN response is low.
 *
 * 2. IF humidity is NOT low
 *    AND vibration is medium
 *    THEN response is moderate.
 *
 * 3. IF vibration is NOT low
 *    AND pressure is high
 *    THEN response is high.
 *
 * 4. IF pressure is NOT high
 *    AND quality is good
 *    THEN response is minimal.
 *
 * 5. IF quality is NOT good
 *    OR temperature is high
 *    THEN response is high.
 * ========================================================== */

static float evaluate_random_not_rule(float temperature, float humidity, float vibration, float pressure, float quality, fuzzy_logic_method_t method)
{
    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            return fuzzy_and_method(method, fuzzy_not(temperature_high(temperature)), pressure_normal(pressure));

        case RANDOM_NOT_HUMIDITY_LOW:
            return fuzzy_and_method(method, fuzzy_not(humidity_low(humidity)), vibration_medium(vibration));

        case RANDOM_NOT_VIBRATION_LOW:
            return fuzzy_and_method(method, fuzzy_not(vibration_low(vibration)), pressure_high(pressure));

        case RANDOM_NOT_PRESSURE_HIGH:
            return fuzzy_and_method(method, fuzzy_not(pressure_high(pressure)), quality_good(quality));

        default:
            return fuzzy_or_method(method, fuzzy_not(quality_good(quality)), temperature_high(temperature));
    }
}

static const char *random_not_rule_name(void)
{
    static const char *names[] = {
        "Rule 11: NOT high temperature response",
        "Rule 11: NOT low humidity response",
        "Rule 11: NOT low vibration response",
        "Rule 11: NOT high pressure response",
        "Rule 11: NOT good quality response"
    };

    return names[random_not_rule];
}

static fuzzy_output_function_t random_not_output(void)
{
    static fuzzy_output_function_t outputs[] = {
        response_low,
        response_moderate,
        response_high,
        response_minimal,
        response_high
    };

    return outputs[random_not_rule];
}

/* ==========================================================
 * Complex Mamdani rule construction
 * ========================================================== */

/* ==========================================================
 * Complex Mamdani rule construction
 *
 * Rules 1 through 11 use the selected operator family:
 *
 *     AND = minimum
 *     OR  = maximum
 *
 * The same rule base is evaluated with standard, algebraic,
 * and bounded operator families.
 * ========================================================== */

static void build_process_rules(fuzzy_rules_t *rules, float temperature, float humidity,
                                float vibration, float pressure, float quality,
                                fuzzy_logic_method_t method)
{
    RULE("Rule 1: Minimal response", fuzzy_and_method(method, temperature_low(temperature), humidity_medium(humidity), vibration_low(vibration), pressure_normal(pressure), quality_good(quality)), response_minimal);

    RULE("Rule 2: Low response", fuzzy_and_method(method, temperature_medium(temperature), pressure_normal(pressure), quality_average(quality)), response_low);

    RULE("Rule 3: Moderate response", fuzzy_or_method(method, humidity_high(humidity), vibration_medium(vibration), quality_poor(quality)), response_moderate);

    RULE("Rule 4: High thermal-vibration response", fuzzy_and_method(method, temperature_high(temperature), vibration_high(vibration)), response_high);

    RULE("Rule 5: High machine response", fuzzy_or_method(method, pressure_high(pressure), vibration_high(vibration), temperature_high(temperature)), response_high);

    RULE("Rule 6: Critical heat-pressure response", fuzzy_and_method(method, powf(temperature_high(temperature), hedges.very), pressure_high(pressure)), response_critical);

    RULE("Rule 7: Critical vibration-quality response", fuzzy_or_method(method, powf(vibration_high(vibration), hedges.extremely), powf(quality_poor(quality), hedges.very)), response_critical);

    RULE("Rule 8: High compound response", fuzzy_or_method(method, fuzzy_and_method(method, temperature_medium(temperature), powf(humidity_high(humidity), hedges.somewhat)), fuzzy_and_method(method, pressure_high(pressure), quality_poor(quality))), response_high);
 
    RULE("Rule 9: Low stable-process response", fuzzy_and_method(method, fuzzy_or_method(method, temperature_low(temperature), humidity_low(humidity)), fuzzy_or_method(method, vibration_low(vibration), pressure_normal(pressure)), quality_good(quality)), response_low);

    RULE("Rule 10: Critical combined response", fuzzy_and_method(method, temperature_high(temperature), humidity_high(humidity), vibration_high(vibration), pressure_high(pressure), quality_poor(quality)), response_critical);

    RULE(random_not_rule_name(), evaluate_random_not_rule( temperature, humidity, vibration, pressure, quality, method), random_not_output());
}

 /* ==========================================================
 * Pure process-response evaluation
 *
 * Safe for repeated sweep evaluations.
 * ========================================================== */

static float evaluate_process_response_method(float temperature, float humidity, float vibration, float pressure, float quality, float cog_step, fuzzy_logic_method_t logic_method, fuzzy_implication_method_t implication_method, fuzzy_aggregation_method_t aggregation_method)
{
    fuzzy_rules_t rules;
    fuzzy_rules_create(&rules);
    build_process_rules(&rules, temperature, humidity, vibration, pressure, quality, logic_method);

    float result = fuzzy_rules_defuzzify_method(&rules, RESPONSE_LOWER, RESPONSE_UPPER, cog_step, FUZZY_DEFUZZ_COG, implication_method, aggregation_method);

    fuzzy_rules_free(&rules);
    return result;
}

static float evaluate_process_response(float temperature, float humidity, float vibration, float pressure, float quality, float cog_step, fuzzy_logic_method_t method)
{
    fuzzy_rules_t rules;
    fuzzy_rules_create(&rules);
    build_process_rules(&rules, temperature, humidity, vibration, pressure, quality, method);

    float result = fuzzy_rules_defuzzify(&rules, RESPONSE_LOWER, RESPONSE_UPPER, cog_step, FUZZY_DEFUZZ_COG);

    fuzzy_rules_free(&rules);
    return result;
}

/* ==========================================================
 * Plot one selected process-response COG
 * ========================================================== */

/* ==========================================================
 * Plot the selected process response using every supported
 * Mamdani defuzzification method.
 *
 * The same aggregated Mamdani output is used for:
 *
 * - COG
 * - MOM
 * - SOM
 * - LOM
 *
 * Each result is passed separately to the existing
 * fuzzy_rules_plot_cog() plotting function.
 * ========================================================== */

static bool plot_selected_process_cog(
    float temperature,
    float humidity,
    float vibration,
    float pressure,
    float quality,
    float defuzz_step
)
{
    const fuzzy_logic_method_t methods[] = { FUZZY_LOGIC_STANDARD, FUZZY_LOGIC_ALGEBRAIC, FUZZY_LOGIC_BOUNDED
    };

    const char *method_names[] = { "Standard Zadeh", "Algebraic", "Bounded Lukasiewicz"
    };

    const char *cog_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_cog",
        DEMO_DIRECTORY "/selected_algebraic_cog",
        DEMO_DIRECTORY "/selected_bounded_cog"
    };

    const char *mom_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_mom",
        DEMO_DIRECTORY "/selected_algebraic_mom",
        DEMO_DIRECTORY "/selected_bounded_mom"
    };

    const char *som_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_som",
        DEMO_DIRECTORY "/selected_algebraic_som",
        DEMO_DIRECTORY "/selected_bounded_som"
    };

    const char *lom_filenames[] = {
        DEMO_DIRECTORY "/selected_standard_lom",
        DEMO_DIRECTORY "/selected_algebraic_lom",
        DEMO_DIRECTORY "/selected_bounded_lom"
    };

    const char *cog_titles[] = {
        "Standard Min-Max Controller - COG",
        "Algebraic Product-Sum Controller - COG",
        "Bounded Lukasiewicz Controller - COG"
    };

    const char *mom_titles[] = {
        "Standard Min-Max Controller - MOM",
        "Algebraic Product-Sum Controller - MOM",
        "Bounded Lukasiewicz Controller - MOM"
    };

    const char *som_titles[] = {
        "Standard Min-Max Controller - SOM",
        "Algebraic Product-Sum Controller - SOM",
        "Bounded Lukasiewicz Controller - SOM"
    };

    const char *lom_titles[] = {
        "Standard Min-Max Controller - LOM",
        "Algebraic Product-Sum Controller - LOM",
        "Bounded Lukasiewicz Controller - LOM"
    };

    const size_t method_count =
        sizeof(methods) /
        sizeof(methods[0]);

    size_t method_index;

    for (
        method_index = 0;
        method_index < method_count;
        method_index++
    ) {
        fuzzy_rules_t rules;

        float cog;
        float mom;
        float som;
        float lom;

        bool cog_success;
        bool mom_success;
        bool som_success;
        bool lom_success;

        fuzzy_rules_create(
            &rules
        );

        /*
         * Rebuild the same complete controller using only
         * the currently selected AND/OR operator family.
         */
        build_process_rules(&rules, temperature, humidity, vibration,pressure, quality, methods[method_index]);
        
        printf(
            "\n%s controller rule activations\n"
            "========================================\n",
            method_names[method_index]
        );

        fuzzy_rules_print(
            &rules
        );

        cog =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_COG
            );

        mom =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_MOM
            );

        som =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_SOM
            );

        lom =
            fuzzy_rules_defuzzify(
                &rules,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step,
                FUZZY_DEFUZZ_LOM
            );

        printf(
            "\n%s controller results\n"
            "========================================\n"
            "COG: %.5f\n"
            "MOM: %.5f\n"
            "SOM: %.5f\n"
            "LOM: %.5f\n",
            method_names[method_index],
            cog,
            mom,
            som,
            lom
        );

        cog_success =
            fuzzy_rules_plot_cog(
                &rules,
                cog_filenames[method_index],
                cog_titles[method_index],
                cog,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        mom_success =
            fuzzy_rules_plot_cog(
                &rules,
                mom_filenames[method_index],
                mom_titles[method_index],
                mom,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        som_success =
            fuzzy_rules_plot_cog(
                &rules,
                som_filenames[method_index],
                som_titles[method_index],
                som,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        lom_success =
            fuzzy_rules_plot_cog(
                &rules,
                lom_filenames[method_index],
                lom_titles[method_index],
                lom,
                RESPONSE_LOWER,
                RESPONSE_UPPER,
                defuzz_step
            );

        fuzzy_rules_free(
            &rules
        );

        if (
            !cog_success ||
            !mom_success ||
            !som_success ||
            !lom_success
        ) {
            fprintf(stderr, 
                "Failed to plot %s controller results.\n",
                method_names[method_index]
            );

            return false;
        }
    }

    return true;
}

/* ==========================================================
 * T-norm and T-conorm curve demonstrations
 *
 * The first operand varies from 0 to 1.
 * The second operand remains fixed at 0.5.
 *
 * This produces direct comparisons of:
 *
 * T-norms:
 *     - Standard minimum
 *     - Algebraic product
 *     - Bounded difference
 *
 * T-conorms:
 *     - Standard maximum
 *     - Algebraic probabilistic sum
 *     - Bounded sum
 * ========================================================== */

OPERATOR(operator_and_standard, fuzzy_and_method, FUZZY_LOGIC_STANDARD)
OPERATOR(operator_and_algebraic, fuzzy_and_method, FUZZY_LOGIC_ALGEBRAIC)
OPERATOR(operator_and_bounded, fuzzy_and_method, FUZZY_LOGIC_BOUNDED)

OPERATOR(operator_or_standard, fuzzy_or_method, FUZZY_LOGIC_STANDARD)
OPERATOR(operator_or_algebraic, fuzzy_or_method, FUZZY_LOGIC_ALGEBRAIC)
OPERATOR(operator_or_bounded, fuzzy_or_method, FUZZY_LOGIC_BOUNDED)

static void plot_all_membership_functions(void)
{
    PLOT(DEMO_DIRECTORY "/t_norms", "T-Norm Comparison: Second Operand = 0.5", 1.0f, 0.01f,
        SERIES(operator_and_standard, "#2563eb"),
        SERIES(operator_and_algebraic, "#16a34a"),
        SERIES(operator_and_bounded, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/t_conorms", "T-Conorm Comparison: Second Operand = 0.5", 1.0f, 0.01f,
        SERIES(operator_or_standard, "#2563eb"),
        SERIES(operator_or_algebraic, "#16a34a"),
        SERIES(operator_or_bounded, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/all_shapes", "All Supported Membership Shapes", 100.0f, 0.5f,
        SERIES(shape_ramp_demo, "#ef4444"),
        SERIES(shape_triangle_demo, "#f97316"),
        SERIES(shape_trapezoid_demo, "#eab308"),
        SERIES(shape_smf_demo, "#22c55e"),
        SERIES(shape_zmf_demo, "#3b82f6"),    
        SERIES(shape_gauss_demo, "#8b5cf6"));

    PLOT(DEMO_DIRECTORY "/all_shapes_extended", "All Supported Membership Shapes Extended", 100.0f, 0.5f,
        SERIES(shape_gauss2_demo, "#6366f1"),
        SERIES(shape_bell_demo, "#ec4899"),
        SERIES(shape_sigmoid_demo, "#06b6d4"),
        SERIES(shape_dsigmoid_demo, "#84cc16"),
        SERIES(shape_psigmoid_demo, "#f43f5e"),
        SERIES(shape_pimf_demo, "#14b8a6"));



    PLOT(DEMO_DIRECTORY "/all_hedges", "All Linguistic Hedge Exponents", 100.0f, 0.5f,
        SERIES(hedge_none_demo, "#111827"),
        SERIES(hedge_very_demo, "#ef4444"),
        SERIES(hedge_extremely_demo, "#a855f7"),
        SERIES(hedge_somewhat_demo, "#22c55e"),
        SERIES(hedge_slightly_demo, "#3b82f6"));

    PLOT(DEMO_DIRECTORY "/temperature", "Temperature Membership Functions", 100.0f, 0.5f,
        SERIES(temperature_low, "#3b82f6"),
        SERIES(temperature_medium, "#22c55e"),
        SERIES(temperature_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/humidity", "Humidity Membership Functions", 100.0f, 0.5f,
        SERIES(humidity_low, "#3b82f6"),
        SERIES(humidity_medium, "#22c55e"),
        SERIES(humidity_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/vibration", "Vibration Membership Functions", 10.0f, 0.05f,
        SERIES(vibration_low, "#3b82f6"),
        SERIES(vibration_medium, "#22c55e"),
        SERIES(vibration_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/pressure", "Pressure Membership Functions", 200.0f, 1.0f,
        SERIES(pressure_low, "#3b82f6"),
        SERIES(pressure_normal, "#22c55e"),
        SERIES(pressure_high, "#ef4444"));

    PLOT(DEMO_DIRECTORY "/quality", "Material-Quality Membership Functions", 100.0f, 0.5f,
        SERIES(quality_poor, "#ef4444"),
        SERIES(quality_average, "#eab308"),
        SERIES(quality_good, "#22c55e"));

    PLOT(DEMO_DIRECTORY "/response", "Process-Response Membership Functions", 100.0f, 0.5f,
        SERIES(response_minimal, "#3b82f6"),
        SERIES(response_low, "#06b6d4"),
        SERIES(response_moderate, "#22c55e"),
        SERIES(response_high, "#f97316"),
        SERIES(response_critical, "#ef4444"));
}

/* ==========================================================
 * Five-dimensional sampled-membership sweep
 *
 * Temperature and humidity form the heatmap.
 *
 * Vibration, pressure, and material quality use the
 * existing interactive SVG slider dimensions.
 * ========================================================== */

static bool plot_sampled_membership_sweep(void)
{
    bool sweep_success;
    bool slices_success;

    sweep_success = FUZZY_INTERPOLATION_SWEEP(
        DEMO_DIRECTORY "/sampled_interpolation",
        "Five-Dimensional Sampled Membership Interpolation",
        sampled_membership_points,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 10.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 5.0f)
    );

    slices_success = FUZZY_INTERPOLATION_SLICES(
        DEMO_DIRECTORY "/sampled_membership_slice",
        "Sampled Membership",
        sampled_membership_points,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.05f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 1.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 0.5f)
    );

    return sweep_success && slices_success;
}




static float evaluate_process_sweep(const float inputs[], size_t input_count, float cog_step)
{
    (void)input_count;
    return evaluate_process_response(
        inputs[0], inputs[1], inputs[2], inputs[3], inputs[4],
        cog_step, FUZZY_LOGIC_STANDARD
    );
}

/* ==========================================================
 * Five-dimensional COG sweep
 * ========================================================== */

static bool plot_process_sweep(void)
{
    /*
     * High-resolution five-dimensional stress demonstration.
     *
     * Sample counts:
     *
     * Temperature:
     *     0 to 100, step 20
     *     6 samples
     *
     * Humidity:
     *     0 to 100, step 20
     *     6 samples
     *
     * Vibration:
     *     0 to 10, step 0.5
     *     21 samples
     *
     * Pressure:
     *     0 to 200, step 10
     *     21 samples
     *
     * Material quality:
     *     0 to 100, step 5
     *     21 samples
     *
     * Total sweep points:
     *
     *     6 x 6 x 21 x 21 x 21
     *     = 333,396 COG evaluations
     *
     * SVG structure:
     *
     *     X axis  = Temperature
     *     Y axis  = Humidity
     *     Colour  = Defuzzified process-response COG
     *
     * Interactive slider dimensions:
     *
     *     Vibration:
     *         0.0, 0.5, 1.0, ..., 10.0f
     *
     *     Pressure:
     *         0, 10, 20, ..., 200
     *
     *     Material quality:
     *         0, 5, 10, ..., 100
     *
     * The public API call remains unchanged regardless of
     * dimensionality. fuzzy.h handles:
     *
     *     - N-dimensional Cartesian iteration
     *     - COG evaluation
     *     - CSV generation
     *     - A randomly selected but deterministic fuzzy-NOT rule
     *     - SVG generation
     *     - Interactive SVG slice selection
     *     - Internal allocation and cleanup
     */

    FUZZY_COG_SWEEP(
        DEMO_DIRECTORY "/process_sweep",
        "High-Resolution Five-Dimensional Process Sweep",
        evaluate_process_sweep,
        SWEEP_COG_STEP,
        FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 20.0f),
        FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f),
        FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 10.0f),
        FUZZY_SWEEP_DIMENSION("Material quality", 0.0f, 100.0f, 5.0f));

    return true;
}


/* ==========================================================
 * Random-input demonstration
 * ========================================================== */

static bool run_random_demonstration(void)
{
    float temperature;
    float humidity;
    float vibration;
    float pressure;
    float quality;

     float standard_cog;
    float algebraic_cog;
    float bounded_cog;

    float min_max_cog;
    float product_max_cog;
    float min_algebraic_cog;
    float product_algebraic_cog;
    float min_bounded_cog;
    float product_bounded_cog;

    float interpolated_membership;

    temperature =
        random_float(
            0.0f,
            100.0f
        );

    humidity =
        random_float(
            0.0f,
            100.0f
        );

    vibration =
        random_float(
            0.0f,
            10.0f
        );

    pressure =
        random_float(
            0.0f,
            200.0f
        );

    quality =
        random_float(
            0.0f,
            100.0f
        );

    printf(
        "\nRandom crisp inputs\n"
        "===================\n"
        "Temperature:      %8.3f\n"
        "Humidity:         %8.3f\n"
        "Vibration:        %8.3f\n"
        "Pressure:         %8.3f\n"
        "Material quality: %8.3f\n",
        temperature,
        humidity,
        vibration,
        pressure,
        quality
    );

    fuzzy_point_t sampled_inputs = FUZZY_INPUTS(temperature, humidity, vibration, pressure, quality);

    interpolated_membership = fuzzy_interpolate_membership_array(
        sampled_inputs.coordinates,
        sampled_inputs.dimension_count,
        sampled_membership_points,
        sizeof(sampled_membership_points) / sizeof(sampled_membership_points[0])
    );

    printf("\nFive-dimensional sampled-membership interpolation\n"
           "=================================================\n"
           "Temperature:             %.5f\n"
           "Humidity:                %.5f\n"
           "Vibration:               %.5f\n"
           "Pressure:                %.5f\n"
           "Material quality:        %.5f\n"
           "Interpolated membership: %.5f\n",
           temperature,
           humidity,
           vibration,
           pressure,
           quality,
           interpolated_membership);

    /*
     * Evaluate the same controller three times.
     *
     * The crisp inputs, membership functions, rule
     * definitions and consequents remain identical.
     *
     * Only the T-norm and T-conorm family changes.
     */
    standard_cog = evaluate_process_response(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD);
    algebraic_cog = evaluate_process_response(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_ALGEBRAIC);
    bounded_cog = evaluate_process_response(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_BOUNDED);

    printf(
        "\nOperator-family COG comparison\n"
        "==============================\n"
        "Standard Zadeh:      %.5f\n"
        "Algebraic:           %.5f\n"
        "Bounded Lukasiewicz: %.5f\n",
        standard_cog,
        algebraic_cog,
        bounded_cog
    );

    min_max_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_MIN, FUZZY_AGGREGATION_MAX);
    product_max_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_PRODUCT, FUZZY_AGGREGATION_MAX);
    min_algebraic_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_MIN, FUZZY_AGGREGATION_ALGEBRAIC);
    product_algebraic_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_PRODUCT, FUZZY_AGGREGATION_ALGEBRAIC);
    min_bounded_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_MIN, FUZZY_AGGREGATION_BOUNDED);
    product_bounded_cog = evaluate_process_response_method(temperature, humidity, vibration, pressure, quality, NORMAL_COG_STEP, FUZZY_LOGIC_STANDARD, FUZZY_IMPLICATION_PRODUCT, FUZZY_AGGREGATION_BOUNDED);

    printf(
        "\nImplication and aggregation comparison\n"
        "======================================\n"
        "MIN implication + MAX aggregation:               %.5f\n"
        "PRODUCT implication + MAX aggregation:           %.5f\n"
        "MIN implication + ALGEBRAIC aggregation:         %.5f\n"
        "PRODUCT implication + ALGEBRAIC aggregation:     %.5f\n"
        "MIN implication + BOUNDED aggregation:           %.5f\n"
        "PRODUCT implication + BOUNDED aggregation:       %.5f\n",
        min_max_cog,
        product_max_cog,
        min_algebraic_cog,
        product_algebraic_cog,
        min_bounded_cog,
        product_bounded_cog
    );

    if (!plot_selected_process_cog(
        temperature,
        humidity,
        vibration,
        pressure,
        quality,
        NORMAL_COG_STEP
    )) {
        fprintf(stderr, 
            "Failed to generate selected operator-family "
            "defuzzification plots.\n"
        );

        return false;
    }

    return true;
}

/* ==========================================================
 * Print the randomly selected NOT rule
 * ========================================================== */

static void print_random_not_rule(void)
{
    printf(
        "\nRandomized fuzzy-NOT rule\n"
        "=========================\n"
    );

    switch (random_not_rule) {
        case RANDOM_NOT_TEMPERATURE_HIGH:
            printf(
                "IF temperature is NOT high\n"
                "AND pressure is normal\n"
                "THEN response is low.\n"
            );
            break;

        case RANDOM_NOT_HUMIDITY_LOW:
            printf(
                "IF humidity is NOT low\n"
                "AND vibration is medium\n"
                "THEN response is moderate.\n"
            );
            break;

        case RANDOM_NOT_VIBRATION_LOW:
            printf(
                "IF vibration is NOT low\n"
                "AND pressure is high\n"
                "THEN response is high.\n"
            );
            break;

        case RANDOM_NOT_PRESSURE_HIGH:
            printf(
                "IF pressure is NOT high\n"
                "AND material quality is good\n"
                "THEN response is minimal.\n"
            );
            break;

        case RANDOM_NOT_QUALITY_GOOD:
            printf(
                "IF material quality is NOT good\n"
                "OR temperature is high\n"
                "THEN response is high.\n"
            );
            break;

        default:
            printf(
                "No valid fuzzy-NOT rule selected.\n"
            );
            break;
    }
}


/* ==========================================================
 * Program entry point
 * ========================================================== */
int main(void)
{
    srand((unsigned int)time(NULL));

    for (size_t index = 0u; index < sizeof(sampled_membership_points) / sizeof(sampled_membership_points[0]); index++) {
        sampled_membership_coordinates[index][0] = random_float(0.0f, 100.0f);
        sampled_membership_coordinates[index][1] = random_float(0.0f, 100.0f);
        sampled_membership_coordinates[index][2] = random_float(0.0f, 10.0f);
        sampled_membership_coordinates[index][3] = random_float(0.0f, 200.0f);
        sampled_membership_coordinates[index][4] = random_float(0.0f, 100.0f);

        sampled_membership_points[index].coordinates = sampled_membership_coordinates[index];
        sampled_membership_points[index].dimension_count = 5u;
        sampled_membership_points[index].membership = random_float(0.0f, 1.0f);
    }
    randomize_membership_parameters();

    printf("\nfuzzy.h Complete API Demonstration\n");
    printf("==================================\n");

    print_random_not_rule();
    plot_all_membership_functions();
    plot_sampled_membership_sweep();
    plot_process_sweep();
    run_random_demonstration();

    printf("\nComplete fuzzy.h demonstration finished.\n");
    return 0;
}