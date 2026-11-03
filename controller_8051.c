#define FUZZY_MAX_RULES 2u
#define FUZZY_MAX_VALUES 3u

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

static fuzzy_rules_t rules;

volatile unsigned char test_temperature = 0u;
volatile unsigned char test_pwm = 0u;
volatile float test_fan_speed = 0.0f;

#ifdef SIMULATION
#define HEDGE_NONE 1.0f
#else
#define HEDGE_NONE 1u
#endif

FUZZY_VAR(temperature_low,  FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 40.0f, false)
FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, HEDGE_NONE, 30.0f, 60.0f, true)
FUZZY_VAR(fan_slow,         FUZZY_SHAPE_RAMP, HEDGE_NONE, 20.0f, 50.0f, false)
FUZZY_VAR(fan_fast,         FUZZY_SHAPE_RAMP, HEDGE_NONE, 40.0f, 80.0f, true)

static float calculate_fan_speed(float temperature)
{
    rules.count = 0u;

    RULE(rules, "Low temperature produces slow fan", temperature_low(temperature), fan_slow);

    RULE(rules, "High temperature produces fast fan", temperature_high(temperature), fan_fast);

    return fuzzy_rules_defuzzify(&rules, 0.0f, 100.0f, 10.0f, FUZZY_DEFUZZ_BOA);
}

static unsigned char fan_speed_to_pwm(float fan_speed)
{
    if (fan_speed <= 0.0f)
        return 0u;

    if (fan_speed >= 100.0f)
        return 100u;

    return (unsigned char)(fan_speed + 0.5f);
}

static void update_controller(unsigned char temperature)
{
    test_temperature = temperature;
    test_fan_speed = calculate_fan_speed((float)test_temperature);
    test_pwm = fan_speed_to_pwm(test_fan_speed);
}

#ifndef SIMULATION

void main(void)
{
    P0 = 0x00u;
    P1 = 0x00u;

    for (;;) {
        P0 = 0x55u;

        test_temperature = P2;

        if (test_temperature > 100u) {
            P1 = 0x00u;
            P0 = 0xF0u;
            continue;
        }

        P0 = 0x60u;
        update_controller(test_temperature);
        P0 = 0x70u;
        P1 = test_pwm;
        P0 = 0xAAu;
    }
}

#else

SWEEP_EVALUATOR(
    evaluate_fan_sweep,
    calculate_fan_speed,
    inputs[0]
)

int main(void)
{
    update_controller(42u);

    printf(
        "\n"
        "Mamdani 8052 verification\n"
        "=========================\n"
        "Temperature:     %u\n"
        "Low activation:  %.5f\n"
        "High activation: %.5f\n"
        "Fan speed:       %.5f\n"
        "PWM:             %u\n"
        "P0:              0xAA\n"
        "P1:              0x%02X\n"
        "P2:              0x%02X\n",
        (unsigned int)test_temperature,
        temperature_low((float)test_temperature),
        temperature_high((float)test_temperature),
        test_fan_speed,
        (unsigned int)test_pwm,
        (unsigned int)test_pwm,
        (unsigned int)test_temperature
    );

    printf("\nSelected-input rule activations:\n");
    fuzzy_rules_print(&rules);

    fuzzy_rules_plot_cog(
        &rules,
        "mamdani_selected_output",
        "Mamdani 8052 Fan Controller: Selected MOM Output",
        test_fan_speed,
        0.0f,
        100.0f,
        10.0f
    );

    PLOT(
        "mamdani_temperature",
        "Temperature Membership Functions",
        100.0f,
        1.0f,
        SERIES(temperature_low,  "#3b82f6"),
        SERIES(temperature_high, "#ef4444")
    );

    PLOT(
        "mamdani_fan",
        "Fan Output Membership Functions",
        100.0f,
        1.0f,
        SERIES(fan_slow, "#22c55e"),
        SERIES(fan_fast, "#a855f7")
    );

    FUZZY_COG_SWEEP(
        "mamdani_8052_sweep",
        "Mamdani 8052 Fan Controller",
        evaluate_fan_sweep,
        10.0f,
        FUZZY_SWEEP_DIMENSION(
            "Temperature",
            0.0f,
            100.0f,
            1.0f
        )
    );

    printf(
        "\n"
        "Generated:\n"
        "  mamdani_temperature.svg\n"
        "  mamdani_fan.svg\n"
        "  mamdani_selected_output.svg\n"
        "  mamdani_8052_sweep.csv\n"
        "  mamdani_8052_sweep.svg\n"
    );

    return 0;
}

#endif
