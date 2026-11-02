#include <math.h>
#include <stdio.h>
#include <string.h>

#define FUZZY_STRINGIFY_RAW(...) #__VA_ARGS__
#define FUZZY_STRINGIFY(...) FUZZY_STRINGIFY_RAW(__VA_ARGS__)

static float clamp_membership(float value)
{
    return value < 0.0f ? 0.0f : value > 1.0f ? 1.0f : value;
}

static float speed_low(float value)
{
    return clamp_membership((60.0f - value) / 60.0f);
}

static float speed_high(float value)
{
    return clamp_membership((value - 40.0f) / 60.0f);
}

static float distance_near(float value)
{
    return clamp_membership((60.0f - value) / 60.0f);
}

static float distance_far(float value)
{
    return clamp_membership((value - 40.0f) / 60.0f);
}

static float output_soft(float value)
{
    return clamp_membership((50.0f - value) / 50.0f);
}

static float output_hard(float value)
{
    return clamp_membership((value - 50.0f) / 50.0f);
}

typedef float (*output_function_t)(float);

typedef struct {
    float activation[8];
    output_function_t output[8];
    unsigned count;
} fuzzy_rules_t;

#define SAND(left, right) fminf((left), (right))
#define SOR(left, right) fmaxf((left), (right))
#define fuzzy_not(value) (1.0f - (value))
#define RULE(system, name, activation_value, output_function) \
    do { \
        (void)(name); \
        (system).activation[(system).count] = (activation_value); \
        (system).output[(system).count] = (output_function); \
        (system).count++; \
    } while (0)

#define BRAKE_RULES(RULE_, AND_, OR_, NOT_, HEDGE_, system, speed, distance) \
    RULE_(system, "Low speed OR far distance -> soft", \
        OR_(speed_low(speed), distance_far(distance)), output_soft); \
    RULE_(system, "High speed AND somewhat near -> hard", \
        AND_(speed_high(speed), HEDGE_(distance_near(distance), 0.5f)), output_hard); \
    RULE_(system, "NOT low speed AND near -> hard", \
        AND_(NOT_(speed_low(speed)), distance_near(distance)), output_hard)

#define FUZZY_CPU_RULE(system, name, activation, output) \
    RULE(system, name, activation, output)
#define FUZZY_CPU_AND(left, right) SAND(left, right)
#define FUZZY_CPU_OR(left, right) SOR(left, right)
#define FUZZY_CPU_NOT(value) fuzzy_not(value)
#define FUZZY_CPU_HEDGE(value, exponent) \
    powf(clamp_membership(value), (exponent) > 0.0f ? (exponent) : 1.0f)

static float brake_controller_cpu(float speed, float distance)
{
    fuzzy_rules_t system = {0};
    float weighted_sum = 0.0f;
    float membership_sum = 0.0f;

    BRAKE_RULES(
        FUZZY_CPU_RULE,
        FUZZY_CPU_AND,
        FUZZY_CPU_OR,
        FUZZY_CPU_NOT,
        FUZZY_CPU_HEDGE,
        system,
        speed,
        distance
    );

    for (unsigned sample = 0; sample <= 100; sample++) {
        float value = (float)sample;
        float aggregate = 0.0f;

        for (unsigned rule = 0; rule < system.count; rule++) {
            float implied = fminf(
                system.activation[rule],
                system.output[rule](value)
            );
            aggregate = fmaxf(aggregate, implied);
        }

        weighted_sum += value * aggregate;
        membership_sum += aggregate;
    }

    return membership_sum > 0.0f ? weighted_sum / membership_sum : 0.0f;
}

#define FUZZY_OPENCL_AND(left, right) \
    fuzzy_gpu_and(logic_method, (left), (right))
#define FUZZY_OPENCL_OR(left, right) \
    fuzzy_gpu_or(logic_method, (left), (right))
#define FUZZY_OPENCL_NOT(value) (1.0f - (value))
#define FUZZY_OPENCL_HEDGE(value, exponent) \
    pow(clamp((value), 0.0f, 1.0f), \
        (exponent) > 0.0f ? (float)(exponent) : 1.0f)
#define FUZZY_OPENCL_RULE(system, name, activation, output) \
    activations[rule_count] = (activation); \
    output_ids[rule_count] = output##_gpu_id; \
    rule_count++

#define BRAKE_OPENCL_BODY \
    BRAKE_RULES( \
        FUZZY_OPENCL_RULE, \
        FUZZY_OPENCL_AND, \
        FUZZY_OPENCL_OR, \
        FUZZY_OPENCL_NOT, \
        FUZZY_OPENCL_HEDGE, \
        system, \
        speed, \
        distance \
    )

static const char brake_opencl_rule_source[] =
    FUZZY_STRINGIFY(BRAKE_OPENCL_BODY);

int main(void)
{
    const float speed = 75.0f;
    const float distance = 25.0f;

    printf("CPU result: %.6f\n\n", brake_controller_cpu(speed, distance));
    puts("Host-expanded OpenCL rule source:");
    puts(brake_opencl_rule_source);

    if (strstr(brake_opencl_rule_source, "BRAKE_RULES") != NULL ||
        strstr(brake_opencl_rule_source, "FUZZY_OPENCL_") != NULL) {
        puts("\nPIPELINE FAILED: an original controller macro survived stringization.");
        return 1;
    }

    puts("\nPIPELINE PASSED: wrappers expanded before stringization.");
    return 0;
}
