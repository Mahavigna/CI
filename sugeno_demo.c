#define FUZZY_MAX_VALUES 12u

#ifdef SIMULATION
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
#else
#ifdef __SDCC
#include <8052.h>
#else
#include <REG51.H>
#endif
#define FUZZY_8051
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
#endif

volatile unsigned char test_temperature = 0u;
volatile unsigned char test_load = 0u;
volatile unsigned char test_vibration = 0u;
volatile unsigned char test_pwm = 0u;
volatile float test_fan_speed = 0.0f;

#ifdef SIMULATION
#define HEDGE_NONE 1.0f
#else
#define HEDGE_NONE 1u
#endif

FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 15.0f, 40.0f, false)
FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 35.0f, 75.0f, true)
FUZZY_VAR(load_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
FUZZY_VAR(load_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 45.0f, 85.0f, true)
FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, HEDGE_NONE, 1.0f, 4.0f, false)
FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 3.0f, 8.0f, true)

static float response_idle(float temperature, float load, float vibration) { return 8.0f + 0.20f * temperature + 0.08f * load + 0.50f * vibration; }
static float response_economy(float temperature, float load, float vibration) { return 12.0f + 0.30f * temperature + 0.18f * load + 0.80f * vibration; }
static float response_balanced(float temperature, float load, float vibration) { return 15.0f + 0.42f * temperature + 0.25f * load + 1.20f * vibration; }
static float response_cooling(float temperature, float load, float vibration) { return 20.0f + 0.65f * temperature + 0.12f * load + 1.50f * vibration; }
static float response_heavy_load(float temperature, float load, float vibration) { return 18.0f + 0.30f * temperature + 0.55f * load + 1.00f * vibration; }
static float response_protection(float temperature, float load, float vibration) { return 35.0f + 0.45f * temperature + 0.30f * load + 2.50f * vibration; }

static float calculate_fan_speed(float temperature, float load, float vibration)
{
    float temperature_low_value = temperature_low(temperature);
    float temperature_high_value = temperature_high(temperature);
    float load_low_value = load_low(load);
    float load_high_value = load_high(load);
    float vibration_low_value = vibration_low(vibration);
    float vibration_high_value = vibration_high(vibration);

    float rule1 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_low_value, load_low_value, vibration_low_value);
    float rule2 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, fuzzy_not(temperature_high_value), load_high_value);
    float rule3 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value);
    float rule4 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, load_high_value);
    float rule5 = fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, fuzzy_not(vibration_high_value));
    float rule6 = fuzzy_or_method(FUZZY_LOGIC_STANDARD, fuzzy_and_method(FUZZY_LOGIC_STANDARD, temperature_high_value, vibration_high_value), fuzzy_and_method(FUZZY_LOGIC_STANDARD, load_high_value, vibration_high_value));

    return fuzzy_sugeno_weighted_average(rule1, response_idle(temperature, load, vibration), rule2, response_economy(temperature, load, vibration), rule3, response_balanced(temperature, load, vibration), rule4, response_cooling(temperature, load, vibration), rule5, response_heavy_load(temperature, load, vibration), rule6, response_protection(temperature, load, vibration));
}

static unsigned char fan_speed_to_pwm(float fan_speed)
{
    if (fan_speed <= 0.0f) return 0u;
    if (fan_speed >= 100.0f) return 100u;
    return (unsigned char)(fan_speed + 0.5f);
}

static void update_controller(unsigned char temperature, unsigned char load, unsigned char vibration)
{
    test_temperature = temperature;
    test_load = load;
    test_vibration = vibration;
    test_fan_speed = calculate_fan_speed((float)test_temperature, (float)test_load, (float)test_vibration);
    test_pwm = fan_speed_to_pwm(test_fan_speed);
}

#ifndef SIMULATION

void main(void)
{
    P1 = 0x00u;

    for (;;) {
        test_vibration = P0;
        test_temperature = P2;
        test_load = P3;

        if (test_temperature > 100u || test_load > 100u || test_vibration > 10u) {
            P1 = 0x00u;
            continue;
        }

        update_controller(
            test_temperature,
            test_load,
            test_vibration
        );

        P1 = test_pwm;
    }
}

#else

static float evaluate_fan_sweep(const float inputs[], size_t input_count, float unused_step)
{
    (void)unused_step;
    if (inputs == NULL || input_count != 3u) return 0.0f;
    return calculate_fan_speed(inputs[0], inputs[1], inputs[2]);
}

int main(void)
{
    update_controller(42u, 65u, 4u);

    printf("\nComplex Sugeno 8052 verification\n================================\nTemperature:      %u\nLoad:             %u\nVibration:        %u\nTemperature low:  %.5f\nTemperature high: %.5f\nLoad low:         %.5f\nLoad high:        %.5f\nVibration low:    %.5f\nVibration high:   %.5f\nFan speed:        %.5f\nPWM:              %u\nP0:               0xAA\nP1:               0x%02X\nP2:               0x%02X\nP3:               0x%02X\n", (unsigned int)test_temperature, (unsigned int)test_load, (unsigned int)test_vibration, temperature_low((float)test_temperature), temperature_high((float)test_temperature), load_low((float)test_load), load_high((float)test_load), vibration_low((float)test_vibration), vibration_high((float)test_vibration), test_fan_speed, (unsigned int)test_pwm, (unsigned int)test_pwm, (unsigned int)test_temperature, (unsigned int)test_load);

    PLOT("sugeno_temperature", "Temperature Membership Functions", 100.0f, 1.0f, SERIES(temperature_low, "#3b82f6"), SERIES(temperature_high, "#ef4444"));
    PLOT("sugeno_load", "Load Membership Functions", 100.0f, 1.0f, SERIES(load_low, "#22c55e"), SERIES(load_high, "#f97316"));
    PLOT("sugeno_vibration", "Vibration Membership Functions", 10.0f, 0.1f, SERIES(vibration_low, "#06b6d4"), SERIES(vibration_high, "#a855f7"));

    FUZZY_COG_SWEEP("sugeno_complex_sweep", "Complex Sugeno Fan Controller", evaluate_fan_sweep, 1.0f, FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 2.0f), FUZZY_SWEEP_DIMENSION("Load", 0.0f, 100.0f, 2.0f), FUZZY_SWEEP_DIMENSION("Vibration", 0.0f, 10.0f, 0.5f));

    printf("\nGenerated:\n  sugeno_temperature.svg\n  sugeno_load.svg\n  sugeno_vibration.svg\n  sugeno_complex_sweep.csv\n  sugeno_complex_sweep.svg\n");

    return 0;
}

#endif