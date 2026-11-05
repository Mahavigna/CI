#define FUZZY_ESP32
#define FUZZY_IMPLEMENTATION

#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u

#include "fuzzy.h"

typedef struct FuzzyEsp32Result {
    float temperature;
    float load;
    float vibration;
    float temperature_cold;
    float temperature_warm;
    float temperature_hot;
    float load_light;
    float load_medium;
    float load_heavy;
    float vibration_low;
    float vibration_high;
    float rule_low;
    float rule_medium;
    float rule_high;
    float cog;
    float boa;
    float cos;
    float mom;
    float som;
    float lom;
    float sugeno_average;
    float sugeno_sum;
    unsigned int rule_count;
} fuzzy_esp32_result_t;

FUZZY_VAR(temperature_cold, FUZZY_SHAPE_RAMP, 1.0f, 0.0f, 50.0f, 0.0f)
FUZZY_VAR(temperature_warm, FUZZY_SHAPE_TRIANGLE, 1.0f, 20.0f, 50.0f, 80.0f)
FUZZY_VAR(temperature_hot, FUZZY_SHAPE_RAMP, 1.0f, 50.0f, 100.0f, 1.0f)

FUZZY_VAR(load_light, FUZZY_SHAPE_RAMP, 1.0f, 0.0f, 50.0f, 0.0f)
FUZZY_VAR(load_medium, FUZZY_SHAPE_TRIANGLE, 1.0f, 20.0f, 50.0f, 80.0f)
FUZZY_VAR(load_heavy, FUZZY_SHAPE_RAMP, 1.0f, 50.0f, 100.0f, 1.0f)

FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, 1.0f, 0.0f, 6.0f, 0.0f)
FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, 1.0f, 4.0f, 10.0f, 1.0f)

FUZZY_VAR(fan_low, FUZZY_SHAPE_TRAPEZOID, 1.0f, 0.0f, 1.0f, 20.0f, 45.0f)
FUZZY_VAR(fan_medium, FUZZY_SHAPE_TRIANGLE, 1.0f, 25.0f, 50.0f, 75.0f)
FUZZY_VAR(fan_high, FUZZY_SHAPE_TRAPEZOID, 1.0f, 55.0f, 80.0f, 99.0f, 100.0f)

FUZZY_VAR(full_smf_test, FUZZY_SHAPE_SMF, 1.0f, 20.0f, 80.0f)
FUZZY_VAR(full_zmf_test, FUZZY_SHAPE_ZMF, 1.0f, 20.0f, 80.0f)
FUZZY_VAR(full_gaussian_test, FUZZY_SHAPE_GAUSSIAN, 1.0f, 50.0f, 15.0f)
FUZZY_VAR(full_bell_test, FUZZY_SHAPE_BELL, 1.0f, 40.0f, 3.0f, 50.0f)
FUZZY_VAR(full_sigmoid_test, FUZZY_SHAPE_SIGMOID, 1.0f, 0.15f, 50.0f)
FUZZY_VAR(full_pimf_test, FUZZY_SHAPE_PIMF, 1.0f, 10.0f, 30.0f, 70.0f, 90.0f)
FUZZY_VAR(full_dsigmoid_test, FUZZY_SHAPE_DSIGMOID, 1.0f, 0.20f, 30.0f, 0.20f, 70.0f)
FUZZY_VAR(full_psigmoid_test, FUZZY_SHAPE_PSIGMOID, 1.0f, 0.20f, 30.0f, -0.20f, 70.0f)
FUZZY_VAR(full_gaussian2_test, FUZZY_SHAPE_GAUSSIAN2, 1.0f, 30.0f, 10.0f, 70.0f, 10.0f)

static float fuzzy_esp32_absolute(float value)
{
    return value < 0.0f ? -value : value;
}

static bool fuzzy_esp32_close(float left, float right, float tolerance)
{
    return fuzzy_esp32_absolute(left - right) <= tolerance;
}

void fuzzy_esp32_evaluate(float temperature, float load, float vibration, fuzzy_esp32_result_t *result)
{
    fuzzy_rules_t rules = {0};

    float cold = temperature_cold(temperature);
    float warm = temperature_warm(temperature);
    float hot = temperature_hot(temperature);

    float light = load_light(load);
    float medium = load_medium(load);
    float heavy = load_heavy(load);

    float stable = vibration_low(vibration);
    float unstable = vibration_high(vibration);

    float low_rule_1 = SAND(cold, light, stable);
    float low_rule_2 = SAND(cold, medium, stable);
    float low_rule_3 = SAND(warm, light, stable);

    float medium_rule_1 = SAND(warm, medium, stable);
    float medium_rule_2 = SAND(cold, heavy, stable);
    float medium_rule_3 = SAND(hot, light, stable);
    float medium_rule_4 = SAND(cold, light, unstable);

    float high_rule_1 = SOR(hot, heavy);
    float high_rule_2 = SAND(warm, heavy);
    float high_rule_3 = SAND(hot, medium);
    float high_rule_4 = SAND(warm, medium, unstable);
    float high_rule_5 = SAND(hot, heavy, unstable);

    RULE(rules, "cold_light_stable", low_rule_1, fan_low);
    RULE(rules, "cold_medium_stable", low_rule_2, fan_low);
    RULE(rules, "warm_light_stable", low_rule_3, fan_low);

    RULE(rules, "warm_medium_stable", medium_rule_1, fan_medium);
    RULE(rules, "cold_heavy_stable", medium_rule_2, fan_medium);
    RULE(rules, "hot_light_stable", medium_rule_3, fan_medium);
    RULE(rules, "cold_light_unstable", medium_rule_4, fan_medium);

    RULE(rules, "hot_or_heavy", high_rule_1, fan_high);
    RULE(rules, "warm_heavy", high_rule_2, fan_high);
    RULE(rules, "hot_medium", high_rule_3, fan_high);
    RULE(rules, "warm_medium_unstable", high_rule_4, fan_high);
    RULE(rules, "hot_heavy_unstable", high_rule_5, fan_high);

    result->temperature = temperature;
    result->load = load;
    result->vibration = vibration;

    result->temperature_cold = cold;
    result->temperature_warm = warm;
    result->temperature_hot = hot;

    result->load_light = light;
    result->load_medium = medium;
    result->load_heavy = heavy;

    result->vibration_low = stable;
    result->vibration_high = unstable;

    result->rule_low = SOR(low_rule_1, low_rule_2, low_rule_3);
    result->rule_medium = SOR(medium_rule_1, medium_rule_2, medium_rule_3, medium_rule_4);
    result->rule_high = SOR(high_rule_1, high_rule_2, high_rule_3, high_rule_4, high_rule_5);

    result->cog = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 0.25f, FUZZY_DEFUZZ_COG);
    result->boa = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 0.25f, FUZZY_DEFUZZ_BOA);
    result->cos = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 0.25f, FUZZY_DEFUZZ_COS);
    result->mom = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 0.25f, FUZZY_DEFUZZ_MOM);
    result->som = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 0.25f, FUZZY_DEFUZZ_SOM);
    result->lom = fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 0.25f, FUZZY_DEFUZZ_LOM);

    result->sugeno_average = fuzzy_sugeno_weighted_average(result->rule_low, 20.0f, result->rule_medium, 50.0f, result->rule_high, 85.0f);
    result->sugeno_sum = fuzzy_sugeno_weighted_sum(result->rule_low, 20.0f, result->rule_medium, 50.0f, result->rule_high, 85.0f);

    result->rule_count = (unsigned int)rules.count;
}

unsigned int fuzzy_esp32_logic_test(void)
{
    unsigned int passed = 0u;

    if (fuzzy_esp32_close(SAND(0.25f, 0.50f, 0.75f), 0.25f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(SOR(0.25f, 0.50f, 0.75f), 0.75f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(AAND(0.25f, 0.50f, 0.75f), 0.09375f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(AOR(0.25f, 0.50f, 0.75f), 0.90625f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(BAND(0.75f, 0.75f), 0.50f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(BOR(0.75f, 0.75f), 1.0f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(fuzzy_not(0.25f), 0.75f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(SAND(0.90f, 0.80f, 0.70f, 0.60f, 0.50f, 0.40f, 0.30f, 0.20f), 0.20f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(SOR(0.10f, 0.20f, 0.30f, 0.40f, 0.50f, 0.60f, 0.70f, 0.80f), 0.80f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(AAND(0.50f, 0.50f, 0.50f, 0.50f), 0.0625f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(AOR(0.50f, 0.50f, 0.50f, 0.50f), 0.9375f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(BAND(0.90f, 0.80f, 0.70f), 0.40f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(BOR(0.20f, 0.30f, 0.40f), 0.90f, 0.0001f)) {
        ++passed;
    }

    return passed;
}

unsigned int fuzzy_esp32_logic_test_count(void)
{
    return 13u;
}

unsigned int fuzzy_esp32_shape_test(void)
{
    unsigned int passed = 0u;

    if (fuzzy_esp32_close(temperature_warm(50.0f), 1.0f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(fan_medium(50.0f), 1.0f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_smf_test(50.0f), 0.5f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_zmf_test(50.0f), 0.5f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_gaussian_test(50.0f), 1.0f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_bell_test(50.0f), 1.0f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_sigmoid_test(50.0f), 0.5f, 0.0001f)) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_pimf_test(50.0f), 1.0f, 0.0001f)) {
        ++passed;
    }

    if (full_dsigmoid_test(50.0f) > 0.0f) {
        ++passed;
    }

    if (full_psigmoid_test(50.0f) > 0.0f) {
        ++passed;
    }

    if (fuzzy_esp32_close(full_gaussian2_test(50.0f), 1.0f, 0.0001f)) {
        ++passed;
    }

    return passed;
}

unsigned int fuzzy_esp32_shape_test_count(void)
{
    return 11u;
}

float fuzzy_esp32_stress_test(unsigned int iterations)
{
    fuzzy_esp32_result_t result;
    float checksum = 0.0f;
    unsigned int index;

    if (iterations == 0u) {
        iterations = 1u;
    }

    for (index = 0u; index < iterations; ++index) {
        float temperature = (float)(index % 101u);
        float load = (float)((index * 37u) % 101u);
        float vibration = (float)((index * 13u) % 101u) / 10.0f;

        fuzzy_esp32_evaluate(temperature, load, vibration, &result);

        checksum += result.cog * 0.001f;
        checksum += result.boa * 0.0001f;
        checksum += result.cos * 0.00001f;
        checksum += result.mom * 0.000001f;
        checksum += result.som * 0.0000001f;
        checksum += result.lom * 0.00000001f;
        checksum += result.sugeno_average * 0.0001f;
        checksum += result.sugeno_sum * 0.000001f;

        if (checksum > 100000.0f) {
            checksum *= 0.001f;
        }
    }

    return checksum;
}