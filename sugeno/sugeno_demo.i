#line 0 "sugeno_demo.c"
#line 0 "<built-in>"
#line 0 "<command-line>"
#line 1 "sugeno_demo.c"
#line 9 "sugeno_demo.c"
#line 1 "/usr/share/sdcc/include/mcs51/8052.h" 3 4
#line 32 "/usr/share/sdcc/include/mcs51/8052.h" 3 4
#line 1 "/usr/share/sdcc/include/mcs51/8051.h" 3 4
#line 33 "/usr/share/sdcc/include/mcs51/8051.h" 3 4
__sfr __at (0x80) P0 ;
__sfr __at (0x81) SP ;
__sfr __at (0x82) DPL ;
__sfr __at (0x83) DPH ;
__sfr __at (0x87) PCON ;
__sfr __at (0x88) TCON ;
__sfr __at (0x89) TMOD ;
__sfr __at (0x8A) TL0 ;
__sfr __at (0x8B) TL1 ;
__sfr __at (0x8C) TH0 ;
__sfr __at (0x8D) TH1 ;
__sfr __at (0x90) P1 ;
__sfr __at (0x98) SCON ;
__sfr __at (0x99) SBUF ;
__sfr __at (0xA0) P2 ;
__sfr __at (0xA8) IE ;
__sfr __at (0xB0) P3 ;
__sfr __at (0xB8) IP ;
__sfr __at (0xD0) PSW ;
__sfr __at (0xE0) ACC ;
__sfr __at (0xF0) B ;




__sbit __at (0x80) P0_0 ;
__sbit __at (0x81) P0_1 ;
__sbit __at (0x82) P0_2 ;
__sbit __at (0x83) P0_3 ;
__sbit __at (0x84) P0_4 ;
__sbit __at (0x85) P0_5 ;
__sbit __at (0x86) P0_6 ;
__sbit __at (0x87) P0_7 ;


__sbit __at (0x88) IT0 ;
__sbit __at (0x89) IE0 ;
__sbit __at (0x8A) IT1 ;
__sbit __at (0x8B) IE1 ;
__sbit __at (0x8C) TR0 ;
__sbit __at (0x8D) TF0 ;
__sbit __at (0x8E) TR1 ;
__sbit __at (0x8F) TF1 ;


__sbit __at (0x90) P1_0 ;
__sbit __at (0x91) P1_1 ;
__sbit __at (0x92) P1_2 ;
__sbit __at (0x93) P1_3 ;
__sbit __at (0x94) P1_4 ;
__sbit __at (0x95) P1_5 ;
__sbit __at (0x96) P1_6 ;
__sbit __at (0x97) P1_7 ;


__sbit __at (0x98) RI ;
__sbit __at (0x99) TI ;
__sbit __at (0x9A) RB8 ;
__sbit __at (0x9B) TB8 ;
__sbit __at (0x9C) REN ;
__sbit __at (0x9D) SM2 ;
__sbit __at (0x9E) SM1 ;
__sbit __at (0x9F) SM0 ;


__sbit __at (0xA0) P2_0 ;
__sbit __at (0xA1) P2_1 ;
__sbit __at (0xA2) P2_2 ;
__sbit __at (0xA3) P2_3 ;
__sbit __at (0xA4) P2_4 ;
__sbit __at (0xA5) P2_5 ;
__sbit __at (0xA6) P2_6 ;
__sbit __at (0xA7) P2_7 ;


__sbit __at (0xA8) EX0 ;
__sbit __at (0xA9) ET0 ;
__sbit __at (0xAA) EX1 ;
__sbit __at (0xAB) ET1 ;
__sbit __at (0xAC) ES ;
__sbit __at (0xAF) EA ;


__sbit __at (0xB0) P3_0 ;
__sbit __at (0xB1) P3_1 ;
__sbit __at (0xB2) P3_2 ;
__sbit __at (0xB3) P3_3 ;
__sbit __at (0xB4) P3_4 ;
__sbit __at (0xB5) P3_5 ;
__sbit __at (0xB6) P3_6 ;
__sbit __at (0xB7) P3_7 ;

__sbit __at (0xB0) RXD ;
__sbit __at (0xB1) TXD ;
__sbit __at (0xB2) INT0 ;
__sbit __at (0xB3) INT1 ;
__sbit __at (0xB4) T0 ;
__sbit __at (0xB5) T1 ;
__sbit __at (0xB6) WR ;
__sbit __at (0xB7) RD ;


__sbit __at (0xB8) PX0 ;
__sbit __at (0xB9) PT0 ;
__sbit __at (0xBA) PX1 ;
__sbit __at (0xBB) PT1 ;
__sbit __at (0xBC) PS ;


__sbit __at (0xD0) P ;
__sbit __at (0xD1) F1 ;
__sbit __at (0xD2) OV ;
__sbit __at (0xD3) RS0 ;
__sbit __at (0xD4) RS1 ;
__sbit __at (0xD5) F0 ;
__sbit __at (0xD6) AC ;
__sbit __at (0xD7) CY ;
#line 33 "/usr/share/sdcc/include/mcs51/8052.h" 3 4
#line 41 "/usr/share/sdcc/include/mcs51/8052.h" 3 4
__sfr __at (0xC8) T2CON ;


__sfr __at (0xCA) RCAP2L ;
__sfr __at (0xCB) RCAP2H ;
__sfr __at (0xCC) TL2 ;
__sfr __at (0xCD) TH2 ;


__sbit __at (0xAD) ET2 ;


__sbit __at (0xBD) PT2 ;


__sbit __at (0xC8) T2CON_0 ;
__sbit __at (0xC9) T2CON_1 ;
__sbit __at (0xCA) T2CON_2 ;
__sbit __at (0xCB) T2CON_3 ;
__sbit __at (0xCC) T2CON_4 ;
__sbit __at (0xCD) T2CON_5 ;
__sbit __at (0xCE) T2CON_6 ;
__sbit __at (0xCF) T2CON_7 ;

__sbit __at (0xC8) CP_RL2 ;
__sbit __at (0xC9) C_T2 ;
__sbit __at (0xCA) TR2 ;
__sbit __at (0xCB) EXEN2 ;
__sbit __at (0xCC) TCLK ;
__sbit __at (0xCD) RCLK ;
__sbit __at (0xCE) EXF2 ;
__sbit __at (0xCF) TF2 ;
#line 10 "sugeno_demo.c"






#line 1 "fuzzy.h"



#line 1 "/usr/share/sdcc/include/stddef.h" 3 4
#line 40 "/usr/share/sdcc/include/stddef.h" 3 4
  typedef long int ptrdiff_t;







  typedef unsigned int size_t;



  typedef unsigned char max_align_t;




  typedef unsigned long int wchar_t;
#line 77 "/usr/share/sdcc/include/stddef.h" 3 4
void __builtin_unreachable(void);
#line 5 "fuzzy.h"







typedef unsigned char bool;
typedef unsigned char uint8_t;






typedef uint8_t fuzzy_hedge_t;

typedef struct FuzzyHedges {
    fuzzy_hedge_t none;
    fuzzy_hedge_t very;
    fuzzy_hedge_t extremely;
} hedges_t;
#line 96 "fuzzy.h"
static float fuzzy_values_buffer[16u];





static float *fuzzy_values_initialize(void)
{
    size_t index;

    for (
        index = 0u;
        index < 16u;
        index++
    ) {
        fuzzy_values_buffer[index] =
            0.0f;
    }

    return fuzzy_values_buffer;
}
#line 228 "fuzzy.h"
typedef float (*fuzzy_output_function_t)(float);

typedef enum FuzzyLogicMethod {
    FUZZY_LOGIC_STANDARD = 0,
    FUZZY_LOGIC_ALGEBRAIC,
    FUZZY_LOGIC_BOUNDED
} fuzzy_logic_method_t;




typedef enum FuzzyShape {
    FUZZY_SHAPE_RAMP = 0,
    FUZZY_SHAPE_TRIANGLE,
    FUZZY_SHAPE_TRAPEZOID,
    FUZZY_SHAPE_SMF,
    FUZZY_SHAPE_ZMF,
    FUZZY_SHAPE_GAUSSIAN,
    FUZZY_SHAPE_BELL,
    FUZZY_SHAPE_SIGMOID
} fuzzy_shape_t;






typedef enum FuzzyDefuzzMethod {
    FUZZY_DEFUZZ_COG = 0,
    FUZZY_DEFUZZ_MOM,
    FUZZY_DEFUZZ_SOM,
    FUZZY_DEFUZZ_LOM
} fuzzy_defuzz_method_t;


typedef struct FuzzyRule {
    const char *name;
    float value;
    fuzzy_output_function_t output_function;
} fuzzy_rule_t;




typedef struct FuzzyRules {
    fuzzy_rule_t rules[16u];
    size_t count;
} fuzzy_rules_t;
#line 309 "fuzzy.h"
float fuzzy_not(
    float membership
);







float fuzzy_and_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
);

float fuzzy_or_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
);
#line 374 "fuzzy.h"
float fuzzy_sugeno_weighted_average_array(
    size_t value_count,
    const float *values
);

float fuzzy_sugeno_weighted_sum_array(
    size_t value_count,
    const float *values
);
#line 400 "fuzzy.h"
float fuzzy_ramp(
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    fuzzy_hedge_t hedge
);



float fuzzy_function_array(
    fuzzy_shape_t shape,
    float value,
    fuzzy_hedge_t hedge,
    size_t parameter_count,
    const float *parameters
);
#line 429 "fuzzy.h"
void fuzzy_rules_create(
    fuzzy_rules_t *rules
);

bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
);
#line 457 "fuzzy.h"
float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
);







float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
);

void fuzzy_rules_free(
    fuzzy_rules_t *rules
);
#line 681 "fuzzy.h"
static float fuzzy_clamp(float value)
{
    if (value < 0.0f) {
        return 0.0f;
    }

    if (value > 1.0f) {
        return 1.0f;
    }

    return value;
}




float fuzzy_not(
    float membership
)
{
    return 1.0f -
        fuzzy_clamp(
            membership
        );
}
#line 715 "fuzzy.h"
static float fuzzy_apply_hedge(
    float membership,
    fuzzy_hedge_t hedge
)
{
    membership =
        fuzzy_clamp(
            membership
        );



    float result =
        1.0f;

    if (hedge == 0u) {
        hedge =
            1u;
    }

    while (hedge > 0u) {
        result *=
            membership;

        hedge--;
    }

    return fuzzy_clamp(
        result
    );
#line 759 "fuzzy.h"
}
#line 773 "fuzzy.h"
float fuzzy_and_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
)
{
    float result;
    float next;
    size_t index;

    if (
        args == ((void *)0) ||
        count == 0u
    ) {
        return 1.0f;
    }

    if (
        method != FUZZY_LOGIC_STANDARD &&
        method != FUZZY_LOGIC_ALGEBRAIC &&
        method != FUZZY_LOGIC_BOUNDED
    ) {
        return 0.0f;
    }

    result =
        fuzzy_clamp(
            args[0]
        );

    for (
        index = 1u;
        index < count;
        index++
    ) {
        next =
            fuzzy_clamp(
                args[index]
            );

        switch (method) {
            case FUZZY_LOGIC_STANDARD:
                if (next < result) {
                    result = next;
                }
                break;

            case FUZZY_LOGIC_ALGEBRAIC:
                result *=
                    next;
                break;

            case FUZZY_LOGIC_BOUNDED:
                result =
                    result +
                    next -
                    1.0f;

                if (result < 0.0f) {
                    result = 0.0f;
                }
                break;

            default:
                return 0.0f;
        }
    }

    return fuzzy_clamp(
        result
    );
}
#line 859 "fuzzy.h"
float fuzzy_or_array(
    fuzzy_logic_method_t method,
    size_t count,
    const float *args
)
{
    float result;
    float next;
    size_t index;

    if (
        args == ((void *)0) ||
        count == 0u
    ) {
        return 0.0f;
    }

    if (
        method != FUZZY_LOGIC_STANDARD &&
        method != FUZZY_LOGIC_ALGEBRAIC &&
        method != FUZZY_LOGIC_BOUNDED
    ) {
        return 0.0f;
    }

    result =
        fuzzy_clamp(
            args[0]
        );

    for (
        index = 1u;
        index < count;
        index++
    ) {
        next =
            fuzzy_clamp(
                args[index]
            );

        switch (method) {
            case FUZZY_LOGIC_STANDARD:
                if (next > result) {
                    result = next;
                }
                break;

            case FUZZY_LOGIC_ALGEBRAIC:
                result =
                    result +
                    next -
                    result * next;
                break;

            case FUZZY_LOGIC_BOUNDED:
                result +=
                    next;

                if (result > 1.0f) {
                    result = 1.0f;
                }
                break;

            default:
                return 0.0f;
        }
    }

    return fuzzy_clamp(
        result
    );
}
#line 941 "fuzzy.h"
float fuzzy_sugeno_weighted_average_array(
    size_t value_count,
    const float *values
)
{
    float weighted_sum;
    float firing_sum;
    float firing_strength;
    float consequent;

    size_t index;

    if (
        values == ((void *)0) ||
        value_count == 0u ||
        value_count % 2u != 0u
    ) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    firing_sum =
        0.0f;

    for (
        index = 0u;
        index < value_count;
        index += 2u
    ) {
        firing_strength =
            fuzzy_clamp(
                values[index]
            );

        consequent =
            values[index + 1u];


        weighted_sum +=
            firing_strength *
            consequent;

        firing_sum +=
            firing_strength;
    }

    if (firing_sum <= 0.0f) {
        return 0.0f;
    }

    return weighted_sum /
        firing_sum;
}
#line 1005 "fuzzy.h"
float fuzzy_sugeno_weighted_sum_array(
    size_t value_count,
    const float *values
)
{
    float weighted_sum;
    float firing_strength;
    float consequent;

    size_t index;

    if (
        values == ((void *)0) ||
        value_count == 0u ||
        value_count % 2u != 0u
    ) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    for (
        index = 0u;
        index < value_count;
        index += 2u
    ) {
        firing_strength =
            fuzzy_clamp(
                values[index]
            );

        consequent =
            values[index + 1u];


        weighted_sum +=
            firing_strength *
            consequent;
    }

    return weighted_sum;
}





float fuzzy_ramp(
    float lower_boundary,
    float upper_boundary,
    float value,
    bool ramp_up,
    fuzzy_hedge_t hedge
)
{
    float result;
    float normalized;

    if (lower_boundary >= upper_boundary) {
        return 0.0f;
    }

    if (value <= lower_boundary) {
        result =
            ramp_up
                ? 0.0f
                : 1.0f;
    }
    else if (value >= upper_boundary) {
        result =
            ramp_up
                ? 1.0f
                : 0.0f;
    }
    else {
        normalized =
            (value - lower_boundary) /
            (upper_boundary - lower_boundary);

        result =
            ramp_up
                ? normalized
                : 1.0f - normalized;
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}
#line 1135 "fuzzy.h"
float fuzzy_function_array(
    fuzzy_shape_t shape,
    float value,
    fuzzy_hedge_t hedge,
    size_t parameter_count,
    const float *parameters
)
{
    float result = 0.0f;
    float parameter_1;
    float parameter_2;
    float parameter_3;
    float parameter_4;
    bool ramp_up;
#line 1157 "fuzzy.h"
    if (parameters == ((void *)0)) {
        return 0.0f;
    }

    switch (shape) {
        case FUZZY_SHAPE_RAMP:
            if (parameter_count != 3u) {
                return 0.0f;
            }

            parameter_1 = parameters[0];
            parameter_2 = parameters[1];
            ramp_up = parameters[2] != 0.0f;

            return fuzzy_ramp(
                parameter_1,
                parameter_2,
                value,
                ramp_up,
                hedge
            );

        case FUZZY_SHAPE_TRIANGLE:
            if (parameter_count != 3u) {
                return 0.0f;
            }

            parameter_1 = parameters[0];
            parameter_2 = parameters[1];
            parameter_3 = parameters[2];

            if (
                parameter_1 >= parameter_2 ||
                parameter_2 >= parameter_3 ||
                value <= parameter_1 ||
                value >= parameter_3
            ) {
                result = 0.0f;
            }
            else if (value == parameter_2) {
                result = 1.0f;
            }
            else if (value < parameter_2) {
                result =
                    (value - parameter_1) /
                    (parameter_2 - parameter_1);
            }
            else {
                result =
                    (parameter_3 - value) /
                    (parameter_3 - parameter_2);
            }
            break;

        case FUZZY_SHAPE_TRAPEZOID:
            if (parameter_count != 4u) {
                return 0.0f;
            }

            parameter_1 = parameters[0];
            parameter_2 = parameters[1];
            parameter_3 = parameters[2];
            parameter_4 = parameters[3];

            if (
                parameter_1 >= parameter_2 ||
                parameter_2 > parameter_3 ||
                parameter_3 >= parameter_4 ||
                value <= parameter_1 ||
                value >= parameter_4
            ) {
                result = 0.0f;
            }
            else if (
                value >= parameter_2 &&
                value <= parameter_3
            ) {
                result = 1.0f;
            }
            else if (value < parameter_2) {
                result =
                    (value - parameter_1) /
                    (parameter_2 - parameter_1);
            }
            else {
                result =
                    (parameter_4 - value) /
                    (parameter_4 - parameter_3);
            }
            break;
#line 1388 "fuzzy.h"
        case FUZZY_SHAPE_SMF:
        case FUZZY_SHAPE_ZMF:
        case FUZZY_SHAPE_GAUSSIAN:
        case FUZZY_SHAPE_BELL:
        case FUZZY_SHAPE_SIGMOID:
            return 0.0f;



        default:
            return 0.0f;
    }

    return fuzzy_apply_hedge(
        result,
        hedge
    );
}


void fuzzy_rules_create(
    fuzzy_rules_t *rules
)
{
    if (rules == ((void *)0)) {
        return;
    }

    rules->count = 0;
}


bool fuzzy_rules_add(
    fuzzy_rules_t *rules,
    const char *name,
    float value,
    fuzzy_output_function_t output_function
)
{
    size_t index;

    if (
        rules == ((void *)0) ||
        output_function == ((void *)0)
    ) {
        return 0u;
    }

    if (rules->count >= 16u) {
        return 0u;
    }

    index =
        rules->count;

    rules->rules[index].name =
        name;

    rules->rules[index].value =
        fuzzy_clamp(value);

    rules->rules[index].output_function =
        output_function;

    rules->count++;

    return 1u;
}
#line 1503 "fuzzy.h"
float fuzzy_rules_defuzzify(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step,
    fuzzy_defuzz_method_t method
)
{
    float weighted_sum;
    float height_sum;

    float maximum_height;
    float maximum_position_sum;

    float smallest_maximum;
    float largest_maximum;

    float value;
    float aggregated_height;
    float output_membership;
    float clipped_height;

    size_t maximum_count;
    size_t i;

    bool maximum_found;

    if (
        rules == ((void *)0) ||
        rules->count == 0 ||
        lower > upper ||
        step <= 0.0f
    ) {
        return 0.0f;
    }

    if (
        method != FUZZY_DEFUZZ_COG &&
        method != FUZZY_DEFUZZ_MOM &&
        method != FUZZY_DEFUZZ_SOM &&
        method != FUZZY_DEFUZZ_LOM
    ) {
        return 0.0f;
    }

    weighted_sum =
        0.0f;

    height_sum =
        0.0f;

    maximum_height =
        0.0f;

    maximum_position_sum =
        0.0f;

    smallest_maximum =
        lower;

    largest_maximum =
        lower;

    maximum_count =
        0u;

    maximum_found =
        0u;

    for (
        value = lower;
        value <= upper;
        value += step
    ) {
        aggregated_height =
            0.0f;







        for (
            i = 0;
            i < rules->count;
            i++
        ) {
            output_membership =
                rules->rules[i]
                    .output_function(
                        value
                    );

            output_membership =
                fuzzy_clamp(
                    output_membership
                );

            clipped_height =
                rules->rules[i].value <
                output_membership
                    ? rules->rules[i].value
                    : output_membership;

            aggregated_height =
                aggregated_height >
                clipped_height
                    ? aggregated_height
                    : clipped_height;
        }

        aggregated_height =
            fuzzy_clamp(
                aggregated_height
            );




        weighted_sum +=
            value *
            aggregated_height;

        height_sum +=
            aggregated_height;






        if (
            !maximum_found ||
            aggregated_height > maximum_height
        ) {
            maximum_height =
                aggregated_height;

            smallest_maximum =
                value;

            largest_maximum =
                value;

            maximum_position_sum =
                value;

            maximum_count =
                1u;

            maximum_found =
                1u;
        }
        else if (
            aggregated_height == maximum_height
        ) {
            largest_maximum =
                value;

            maximum_position_sum +=
                value;

            maximum_count++;
        }
    }




    if (
        !maximum_found ||
        maximum_height <= 0.0f ||
        height_sum <= 0.0f
    ) {
        return 0.0f;
    }

    switch (method) {
        case FUZZY_DEFUZZ_COG:
            return weighted_sum /
                height_sum;

        case FUZZY_DEFUZZ_MOM:
            if (maximum_count == 0u) {
                return 0.0f;
            }

            return maximum_position_sum /
                (float)maximum_count;

        case FUZZY_DEFUZZ_SOM:
            return smallest_maximum;

        case FUZZY_DEFUZZ_LOM:
            return largest_maximum;

        default:
            return 0.0f;
    }
}





float fuzzy_rules_cog(
    const fuzzy_rules_t *rules,
    float lower,
    float upper,
    float step
)
{
    return fuzzy_rules_defuzzify(
        rules,
        lower,
        upper,
        step,
        FUZZY_DEFUZZ_COG
    );
}

void fuzzy_rules_free(
    fuzzy_rules_t *rules
)
{
    if (rules == ((void *)0)) {
        return;
    }






    rules->count = 0;
}
#line 17 "sugeno_demo.c"
#line 25 "sugeno_demo.c"
volatile unsigned char test_temperature = 42u;
volatile unsigned char test_load = 65u;
volatile unsigned char test_vibration = 4u;

volatile unsigned char test_pwm = 0u;
volatile float test_fan_speed = 0.0f;
#line 49 "sugeno_demo.c"
static const hedges_t hedges = {
    1u,
    2u,
    3u
};
#line 62 "sugeno_demo.c"
static float temperature_low(float value)
{
    return fuzzy_ramp(
        15.0f,
        40.0f,
        value,
        0u,
        hedges.none
    );
}


static float temperature_high(float value)
{
    return fuzzy_ramp(
        35.0f,
        75.0f,
        value,
        1u,
        hedges.none
    );
}






static float load_low(float value)
{
    return fuzzy_ramp(
        20.0f,
        50.0f,
        value,
        0u,
        hedges.none
    );
}


static float load_high(float value)
{
    return fuzzy_ramp(
        45.0f,
        85.0f,
        value,
        1u,
        hedges.none
    );
}






static float vibration_low(float value)
{
    return fuzzy_ramp(
        1.0f,
        4.0f,
        value,
        0u,
        hedges.none
    );
}


static float vibration_high(float value)
{
    return fuzzy_ramp(
        3.0f,
        8.0f,
        value,
        1u,
        hedges.none
    );
}






static float response_idle(
    float temperature,
    float load,
    float vibration
)
{
    return
        8.0f +
        0.20f * temperature +
        0.08f * load +
        0.50f * vibration;
}


static float response_economy(
    float temperature,
    float load,
    float vibration
)
{
    return
        12.0f +
        0.30f * temperature +
        0.18f * load +
        0.80f * vibration;
}


static float response_balanced(
    float temperature,
    float load,
    float vibration
)
{
    return
        15.0f +
        0.42f * temperature +
        0.25f * load +
        1.20f * vibration;
}


static float response_cooling(
    float temperature,
    float load,
    float vibration
)
{
    return
        20.0f +
        0.65f * temperature +
        0.12f * load +
        1.50f * vibration;
}


static float response_heavy_load(
    float temperature,
    float load,
    float vibration
)
{
    return
        18.0f +
        0.30f * temperature +
        0.55f * load +
        1.00f * vibration;
}


static float response_protection(
    float temperature,
    float load,
    float vibration
)
{
    return
        35.0f +
        0.45f * temperature +
        0.30f * load +
        2.50f * vibration;
}
#line 254 "sugeno_demo.c"
static float calculate_fan_speed(
    float temperature,
    float load,
    float vibration
)
{
    float temperature_low_value;
    float temperature_high_value;

    float load_low_value;
    float load_high_value;

    float vibration_low_value;
    float vibration_high_value;

    float rule1;
    float rule2;
    float rule3;
    float rule4;
    float rule5;
    float rule6;

    float rule6_thermal;
    float rule6_mechanical;

    temperature_low_value =
        temperature_low(
            temperature
        );

    temperature_high_value =
        temperature_high(
            temperature
        );

    load_low_value =
        load_low(
            load
        );

    load_high_value =
        load_high(
            load
        );

    vibration_low_value =
        vibration_low(
            vibration
        );

    vibration_high_value =
        vibration_high(
            vibration
        );

    rule1 =
        fuzzy_and_array( (FUZZY_LOGIC_STANDARD), 3u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(temperature_low_value), fuzzy_values_buffer[1] = (float)(load_low_value), fuzzy_values_buffer[2] = (float)(vibration_low_value), fuzzy_values_buffer ) );






    rule2 =
        fuzzy_and_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(fuzzy_not( temperature_high_value )), fuzzy_values_buffer[1] = (float)(load_high_value), fuzzy_values_buffer ) );







    rule3 =
        fuzzy_or_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(temperature_high_value), fuzzy_values_buffer[1] = (float)(vibration_high_value), fuzzy_values_buffer ) );





    rule4 =
        fuzzy_and_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(temperature_high_value), fuzzy_values_buffer[1] = (float)(load_high_value), fuzzy_values_buffer ) );





    rule5 =
        fuzzy_and_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(load_high_value), fuzzy_values_buffer[1] = (float)(fuzzy_not( vibration_high_value )), fuzzy_values_buffer ) );







    rule6_thermal =
        fuzzy_and_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(temperature_high_value), fuzzy_values_buffer[1] = (float)(vibration_high_value), fuzzy_values_buffer ) );





    rule6_mechanical =
        fuzzy_and_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(load_high_value), fuzzy_values_buffer[1] = (float)(vibration_high_value), fuzzy_values_buffer ) );





    rule6 =
        fuzzy_or_array( (FUZZY_LOGIC_STANDARD), 2u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(rule6_thermal), fuzzy_values_buffer[1] = (float)(rule6_mechanical), fuzzy_values_buffer ) );





    return fuzzy_sugeno_weighted_average_array( 12u, ( fuzzy_values_initialize(), fuzzy_values_buffer[0] = (float)(rule1), fuzzy_values_buffer[1] = (float)(response_idle( temperature, load, vibration )), fuzzy_values_buffer[2] = (float)(rule2), fuzzy_values_buffer[3] = (float)(response_economy( temperature, load, vibration )), fuzzy_values_buffer[4] = (float)(rule3), fuzzy_values_buffer[5] = (float)(response_balanced( temperature, load, vibration )), fuzzy_values_buffer[6] = (float)(rule4), fuzzy_values_buffer[7] = (float)(response_cooling( temperature, load, vibration )), fuzzy_values_buffer[8] = (float)(rule5), fuzzy_values_buffer[9] = (float)(response_heavy_load( temperature, load, vibration )), fuzzy_values_buffer[10] = (float)(rule6), fuzzy_values_buffer[11] = (float)(response_protection( temperature, load, vibration )), fuzzy_values_buffer ) );
#line 413 "sugeno_demo.c"
}






static unsigned char fan_speed_to_pwm(float fan_speed)
{
    if (fan_speed <= 0.0f) {
        return 0u;
    }

    if (fan_speed >= 100.0f) {
        return 100u;
    }

    return (unsigned char)(
        fan_speed + 0.5f
    );
}
#line 456 "sugeno_demo.c"
void main(void)
{
    P0 =
        0x55u;

    P1 =
        0x00u;

    P2 =
        test_temperature;

    test_fan_speed =
        calculate_fan_speed(
            (float)test_temperature,
            (float)test_load,
            (float)test_vibration
        );

    test_pwm =
        fan_speed_to_pwm(
            test_fan_speed
        );

    P1 =
        test_pwm;

    P0 =
        0xAAu;

    for (;;) {
        ;
    }
}
