#include <Arduino.h>

extern "C" {

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

void fuzzy_esp32_evaluate(
    float temperature,
    float load,
    float vibration,
    fuzzy_esp32_result_t *result
);

unsigned int fuzzy_esp32_logic_test(void);

unsigned int fuzzy_esp32_logic_test_count(void);

unsigned int fuzzy_esp32_shape_test(void);

unsigned int fuzzy_esp32_shape_test_count(void);

float fuzzy_esp32_stress_test(
    unsigned int iterations
);

}

static void print_header(
    const char *title
)
{
    Serial.println();

    Serial.println(
        "============================================================"
    );

    Serial.println(
        title
    );

    Serial.println(
        "============================================================"
    );
}

static void print_result(
    const fuzzy_esp32_result_t *result
)
{
    Serial.println();

    Serial.println(
        "------------------------------------------------------------"
    );

    Serial.printf(
        "Inputs: temperature=%.2f load=%.2f vibration=%.2f\n",
        result->temperature,
        result->load,
        result->vibration
    );

    Serial.printf(
        "Temperature: cold=%.5f warm=%.5f hot=%.5f\n",
        result->temperature_cold,
        result->temperature_warm,
        result->temperature_hot
    );

    Serial.printf(
        "Load:        light=%.5f medium=%.5f heavy=%.5f\n",
        result->load_light,
        result->load_medium,
        result->load_heavy
    );

    Serial.printf(
        "Vibration:   low=%.5f high=%.5f\n",
        result->vibration_low,
        result->vibration_high
    );

    Serial.printf(
        "Rule groups: low=%.5f medium=%.5f high=%.5f\n",
        result->rule_low,
        result->rule_medium,
        result->rule_high
    );

    Serial.printf(
        "Mamdani COG: %.5f\n",
        result->cog
    );

    Serial.printf(
        "Mamdani BOA: %.5f\n",
        result->boa
    );

    Serial.printf(
        "Mamdani COS: %.5f\n",
        result->cos
    );

    Serial.printf(
        "Mamdani MOM: %.5f\n",
        result->mom
    );

    Serial.printf(
        "Mamdani SOM: %.5f\n",
        result->som
    );

    Serial.printf(
        "Mamdani LOM: %.5f\n",
        result->lom
    );

    Serial.printf(
        "Sugeno average: %.5f\n",
        result->sugeno_average
    );

    Serial.printf(
        "Sugeno sum:     %.5f\n",
        result->sugeno_sum
    );

    Serial.printf(
        "Rules stored: %u\n",
        result->rule_count
    );
}

static bool result_is_valid(
    const fuzzy_esp32_result_t *result
)
{
    return
        result->rule_count == 12u &&
        result->cog == result->cog &&
        result->boa == result->boa &&
        result->cos == result->cos &&
        result->mom == result->mom &&
        result->som == result->som &&
        result->lom == result->lom &&
        result->sugeno_average == result->sugeno_average &&
        result->sugeno_sum == result->sugeno_sum;
}

static bool run_controller_case(
    const char *name,
    float temperature,
    float load,
    float vibration
)
{
    fuzzy_esp32_result_t result = {};

    Serial.println();

    Serial.printf(
        "Controller case: %s\n",
        name
    );

    fuzzy_esp32_evaluate(
        temperature,
        load,
        vibration,
        &result
    );

    print_result(
        &result
    );

    if (result_is_valid(&result)) {
        Serial.println(
            "[PASS] Controller result is valid"
        );

        return true;
    }

    Serial.println(
        "[FAIL] Controller result is invalid"
    );

    return false;
}

static bool run_controller_cases(void)
{
    bool passed = true;

    print_header(
        "Full fuzzy controller cases"
    );

    if (!run_controller_case(
        "Cold, light and stable",
        10.0f,
        10.0f,
        1.0f
    )) {
        passed = false;
    }

    if (!run_controller_case(
        "Warm, medium and transitional vibration",
        50.0f,
        50.0f,
        5.0f
    )) {
        passed = false;
    }

    if (!run_controller_case(
        "Hot, heavy and unstable",
        90.0f,
        90.0f,
        9.0f
    )) {
        passed = false;
    }

    if (!run_controller_case(
        "Hot-biased, light-medium and unstable",
        70.0f,
        30.0f,
        8.0f
    )) {
        passed = false;
    }

    if (!run_controller_case(
        "Cold-biased, heavy and stable",
        30.0f,
        80.0f,
        2.0f
    )) {
        passed = false;
    }

    if (!run_controller_case(
        "Warm, heavy and unstable",
        60.0f,
        75.0f,
        7.0f
    )) {
        passed = false;
    }

    return passed;
}

static bool run_logic_tests(void)
{
    unsigned int passed;
    unsigned int total;

    passed =
        fuzzy_esp32_logic_test();

    total =
        fuzzy_esp32_logic_test_count();

    print_header(
        "Full CPU logic operator tests"
    );

    Serial.printf(
        "Passed: %u/%u\n",
        passed,
        total
    );

    Serial.println(
        "Operators:"
    );

    Serial.println(
        "  SAND standard minimum"
    );

    Serial.println(
        "  SOR standard maximum"
    );

    Serial.println(
        "  AAND algebraic product"
    );

    Serial.println(
        "  AOR algebraic sum"
    );

    Serial.println(
        "  BAND bounded product"
    );

    Serial.println(
        "  BOR bounded sum"
    );

    Serial.println(
        "  fuzzy_not complement"
    );

    Serial.println(
        "  Multi-value full-backend operations"
    );

    if (passed == total) {
        Serial.println(
            "[PASS] All full CPU logic operator tests passed"
        );

        return true;
    }

    Serial.println(
        "[FAIL] One or more full CPU logic operator tests failed"
    );

    return false;
}

static bool run_shape_tests(void)
{
    unsigned int passed;
    unsigned int total;

    passed =
        fuzzy_esp32_shape_test();

    total =
        fuzzy_esp32_shape_test_count();

    print_header(
        "Full CPU membership shape tests"
    );

    Serial.printf(
        "Passed: %u/%u\n",
        passed,
        total
    );

    Serial.println(
        "Shapes:"
    );

    Serial.println(
        "  Triangle"
    );

    Serial.println(
        "  Trapezoid"
    );

    Serial.println(
        "  SMF"
    );

    Serial.println(
        "  ZMF"
    );

    Serial.println(
        "  Gaussian"
    );

    Serial.println(
        "  Bell"
    );

    Serial.println(
        "  Sigmoid"
    );

    Serial.println(
        "  PIMF"
    );

    Serial.println(
        "  Difference sigmoid"
    );

    Serial.println(
        "  Product sigmoid"
    );

    Serial.println(
        "  Gaussian2"
    );

    if (passed == total) {
        Serial.println(
            "[PASS] All full CPU membership shape tests passed"
        );

        return true;
    }

    Serial.println(
        "[FAIL] One or more full CPU membership shape tests failed"
    );

    return false;
}

static bool run_stress_test(
    unsigned int iterations
)
{
    unsigned long start_us;
    unsigned long elapsed_us;
    float checksum;
    float evaluations_per_second;
    float microseconds_per_evaluation;

    if (iterations == 0u) {
        iterations = 1u;
    }

    print_header(
        "ESP32 full CPU fuzzy controller stress test"
    );

    Serial.printf(
        "Iterations: %u\n",
        iterations
    );

    Serial.println(
        "Executing all six Mamdani methods and both Sugeno methods"
    );

    start_us =
        micros();

    checksum =
        fuzzy_esp32_stress_test(
            iterations
        );

    elapsed_us =
        micros() -
        start_us;

    if (elapsed_us == 0u) {
        elapsed_us = 1u;
    }

    evaluations_per_second =
        (
            (float)iterations *
            1000000.0f
        ) /
        (float)elapsed_us;

    microseconds_per_evaluation =
        (float)elapsed_us /
        (float)iterations;

    Serial.printf(
        "Elapsed: %lu us\n",
        elapsed_us
    );

    Serial.printf(
        "Average: %.3f us/controller evaluation\n",
        microseconds_per_evaluation
    );

    Serial.printf(
        "Throughput: %.2f controller evaluations/second\n",
        evaluations_per_second
    );

    Serial.printf(
        "Checksum: %.6f\n",
        checksum
    );

    if (
        checksum == checksum &&
        checksum != 0.0f
    ) {
        Serial.println(
            "[PASS] Stress test completed"
        );

        return true;
    }

    Serial.println(
        "[FAIL] Invalid stress-test checksum"
    );

    return false;
}

void setup()
{
    bool logic_passed;
    bool shapes_passed;
    bool controllers_passed;
    bool stress_passed;

    Serial.begin(
        115200
    );

    delay(
        500
    );

    Serial.println();

    Serial.println(
        "============================================================"
    );

    Serial.println(
        "fuzzy.h full CPU backend on ESP32-S3"
    );

    Serial.println(
        "============================================================"
    );

    Serial.println(
        "Backend: FUZZY_ESP32 full CPU backend"
    );

    Serial.println(
        "Implementation language: C"
    );

    Serial.println(
        "Arduino interface language: C++"
    );

    Serial.println(
        "Integration: extern C wrapper"
    );

    Serial.println(
        "DSL: FUZZY_VAR and RULE"
    );

    Serial.println(
        "Logic: SAND, SOR, AAND, AOR, BAND and BOR"
    );

    Serial.println(
        "Mamdani: COG, BOA, COS, MOM, SOM and LOM"
    );

    Serial.println(
        "Sugeno: weighted average and weighted sum"
    );

    Serial.println(
        "Memberships: full CPU shape implementation"
    );

    logic_passed =
        run_logic_tests();

    shapes_passed =
        run_shape_tests();

    controllers_passed =
        run_controller_cases();

    stress_passed =
        run_stress_test(
            25u
        );

    print_header(
        "Final ESP32-S3 fuzzy.h result"
    );

    Serial.printf(
        "Logic operators:       %s\n",
        logic_passed
            ? "PASS"
            : "FAIL"
    );

    Serial.printf(
        "Membership shapes:     %s\n",
        shapes_passed
            ? "PASS"
            : "FAIL"
    );

    Serial.printf(
        "Controller cases:      %s\n",
        controllers_passed
            ? "PASS"
            : "FAIL"
    );

    Serial.printf(
        "Full stress test 25:   %s\n",
        stress_passed
            ? "PASS"
            : "FAIL"
    );

    if (
        logic_passed &&
        shapes_passed &&
        controllers_passed &&
        stress_passed
    ) {
        Serial.println();

        Serial.println(
            "[PASS] fuzzy.h full CPU DSL completed on ESP32-S3"
        );
    }
    else {
        Serial.println();

        Serial.println(
            "[FAIL] One or more fuzzy.h ESP32-S3 tests failed"
        );
    }

    Serial.println(
        "============================================================"
    );
}

void loop()
{
    delay(
        1000
    );
}