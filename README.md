# fuzzy.h

A lightweight, single-header fuzzy-logic library written in C.

`fuzzy.h` provides type-1 membership functions, configurable linguistic hedges, multiple fuzzy AND/OR methods, Mamdani and Sugeno inference helpers, static rule storage, sampled defuzzification, directly callable defuzzification functions, N-dimensional scattered-point membership interpolation, native SVG plotting, CSV-backed multidimensional sweeps, interactive higher-dimensional slices, experimental desktop OpenCL GPU sweeps, GPU-trained fuzzy-neuron surrogates, portable model checkpoints, and a reduced 8051/8052 firmware path.

The Mamdani engine supports sampled Center of Gravity (COG), Bisector of Area (BOA), Center of Sums (COS), Mean of Maximum (MOM), Smallest of Maximum (SOM), and Largest of Maximum (LOM). Every method is available through the configurable wrapper and through a directly callable low-level function.

The ordinary desktop engine and SVG generator require no Python environment, MATLAB toolbox, plotting framework, or external runtime. PNG and PDF conversion are optional conveniences provided through `rsvg-convert`. OpenCL is optional and is linked only into the experimental GPU demonstrations and fuzzy-neuron trainer.

The implementation remains readable, editable, and contained primarily in one header. The build workflow lives directly in the `Makefile`; there is no repository-owned build-script dispatcher. The separate `setup_opencl.sh` utility exists only to install and verify the optional, hardware-specific Intel OpenCL environment.

> Built partly to learn fuzzy logic, partly to explore AI-assisted low-level development, and partly to annoy Python users.

## Contents

- [Why?](#why)
- [Current features](#current-features)
- [Repository structure](#repository-structure)
- [Single-header setup](#single-header-setup)
- [Compressed syntax](#compressed-syntax)
- [Membership functions](#membership-functions)
- [N-dimensional sampled-membership interpolation](#n-dimensional-sampled-membership-interpolation)
- [Linguistic hedges](#linguistic-hedges)
- [Fuzzy operators](#fuzzy-operators)
- [Sugeno inference](#sugeno-inference)
- [Mamdani rule API](#mamdani-rule-api)
- [Defuzzification methods](#defuzzification-methods)
- [Desktop visualization](#desktop-visualization)
- [Experimental OpenCL GPU support](#experimental-opencl-gpu-support)
- [Experimental fuzzy-neuron training](#experimental-fuzzy-neuron-training)
- [Intel OpenCL setup](#intel-opencl-setup)
- [Included applications](#included-applications)
- [Build system](#build-system)
- [Quick start](#quick-start)
- [Command reference](#command-reference)
- [Output directories](#output-directories)
- [8051 and 8052 support](#8051-and-8052-support)
- [8051 firmware verification](#8051-firmware-verification)
- [Optional PNG and PDF conversion](#optional-png-and-pdf-conversion)
- [Opening generated plots](#opening-generated-plots)
- [Project status](#project-status)
- [Safety and limitations](#safety-and-limitations)
- [Planned work](#planned-work)
- [AI-assisted development](#ai-assisted-development)
- [Joke](#joke)
- [Contributing](#contributing)
- [License](#license)
- [Philosophy](#philosophy)

## Why?

Many fuzzy-logic examples immediately reach for Python libraries or MATLAB toolboxes. Those tools are useful, but they can hide the calculations behind frameworks, objects, plotting environments, package managers, and large dependency chains.

This project takes the opposite approach:

- Plain C
- One implementation header
- Reduced desktop library includes
- No Python environment for the core library
- No MATLAB toolbox
- No package manager for the core CPU library
- No external plotting library for native SVG generation
- Direct access to every calculation
- User-defined C functions for membership functions and Sugeno consequents
- Static Mamdani rule storage
- Directly callable defuzzification methods
- Desktop simulation and embedded experimentation
- A reduced 8051/8052 build path
- Optional experimental OpenCL acceleration for desktop sweeps
- Optional OpenCL mini-batch training for fuzzy-feature neural surrogates
- Portable fuzzy-neuron model checkpoints
- Runtime-loaded model definitions through `dlopen` and `dlsym`
- A Makefile-owned workflow with no separate build dispatcher

The objective is not to replace mature numerical-computing platforms, GPU frameworks, or machine-learning systems. The objective is to make fuzzy-logic execution small, inspectable, modifiable, and easy to integrate into an ordinary C project.

Users who already use CUDA, SYCL, Vulkan compute, established machine-learning frameworks, or another GPU workflow can continue using those systems. The experimental OpenCL support is a starting point for users who want an inspectable GPU path without first adopting a larger framework.

## Current features

### Core fuzzy engine

- Single-header implementation
- Reduced desktop library includes through minimal required declarations in `fuzzy.h`
- Membership clamping to `[0, 1]`
- Fuzzy NOT
- Count-free, variadic AND and OR macros
- Standard, algebraic, and bounded fuzzy logic
- Minimum and product Mamdani implication
- Maximum, algebraic, and bounded Mamdani aggregation
- Sugeno weighted-average inference
- Sugeno weighted-sum inference
- Zero-order Sugeno through constant consequents
- First-order and arbitrary-order Sugeno through user-defined C consequent functions
- COG, BOA, COS, MOM, SOM, and LOM sampled defuzzification
- Directly callable functions for every supported defuzzification method
- Configurable method-selection wrapper
- Independently selectable implication and aggregation methods
- N-dimensional scattered-point membership interpolation
- N-dimensional interpolation sweeps and per-dimension membership slices
- Floating-point desktop hedges
- Integer-power 8051 hedges
- Experimental desktop OpenCL sweep execution
- Experimental fuzzy-rule feature extraction for neural surrogate training
- Configurable dense fuzzy-neuron layers
- OpenCL forward propagation and backpropagation
- Real OpenCL mini-batch gradient updates
- Runtime epoch, batch-size, learning-rate, and reporting controls
- Post-epoch MSE evaluation
- Best-weight and best-bias restoration
- CSV model checkpoint saving and loading
- Dynamically loaded fuzzy-model plugins
- Single-input inference and complete-dataset comparison
- MSE, RMSE, MAE, maximum-error, and prediction CSV reporting

### Membership functions

Desktop builds currently provide:

- Rising and falling ramps
- Triangular membership functions
- Trapezoidal membership functions
- S-shaped membership functions
- Z-shaped membership functions
- Pi-shaped membership functions
- Gaussian membership functions
- Two-sided Gaussian membership functions
- Generalized bell membership functions
- Sigmoid membership functions
- Difference-of-sigmoids membership functions
- Product-of-sigmoids membership functions
- Enum-based membership dispatcher

The `FUZZY_8051` profile keeps the smaller ramp, triangle, and trapezoid path and excludes desktop-only transcendental functions.

### Rule system

- Fixed-capacity rule arrays
- No dynamic allocation for Mamdani rule storage
- `FUZZY_MAX_RULES` defaults to 32 on desktop and 16 on 8051
- Named rules
- Compressed `RULE(...)` adapter
- Rule activation printing on desktop
- Reusable rule containers
- Compatibility wrapper for existing `fuzzy_rules_cog()` calls
- User-controlled rule weighting through activation scaling
- Multiple outputs through ordinary composition of output functions or controllers

### Desktop visualization

- Multi-function SVG plotting
- Automatic graph axes and grid lines
- Colored curves and legends
- XML-safe graph titles and labels
- Aggregated Mamdani output plotting
- Defuzzified-value marker and label
- N-dimensional sweep CSV generation
- One-dimensional sweep line graphs
- Two-dimensional sweep heatmaps
- Interactive slices for higher-dimensional sweeps
- Continuous interpolation between precomputed higher-dimensional slices
- N-dimensional sampled-membership heatmaps
- Automatic one-dimensional membership slices for every interpolation dimension
- GPU-computed values rendered through the same CSV and SVG sweep path
- Optional SVG-to-PNG conversion
- Optional SVG-to-PDF conversion

### Experimental GPU support

- Compile-time `FUZZY_OPENCL` feature switch
- Desktop-only OpenCL 1.2 path
- N-dimensional Cartesian input generation inside `fuzzy.h`
- Generic flattened GPU input-buffer contract
- GPU context, queue, program, kernel, buffer, execution, and cleanup abstraction
- Runtime kernel compilation with build-log reporting
- `FUZZY_GPU_KERNEL_HEADER` reusable OpenCL membership primitives
- `FUZZY_GPU_SWEEP(...)` user-facing sweep wrapper
- GPU-generated CSV and SVG output
- `braking_gpu_demo.c` test harness
- `setup_opencl.sh` for the tested Intel HD Graphics 620 environment
- Makefile build, run, conversion, dependency-check, and cleanup targets

- Generic OpenCL dense-network forward kernel
- Generic OpenCL dense-network backward kernel
- Hidden-layer delta propagation
- Per-sample weight and bias gradient generation
- Mini-batch gradient averaging
- GPU-side weight and bias updates
- Configurable fuzzy-neuron layer metadata buffers
- Final partial-batch handling
- GPU-only training enforcement with no silent CPU fallback
- Post-epoch fixed-state evaluation
- Best-parameter checkpoint restoration
- `fuzzy_neuron_kernels.cl` dense-network kernel backend
- `fuzzy_neuron_train.c` interactive training and testing CLI

### Embedded support

- `FUZZY_8051` reduced backend
- Static rule storage
- No plotting, heap allocation, CSV generation, OpenCL, or file I/O in firmware builds
- Integer hedge powers
- Ramp, triangle, and trapezoid membership support
- Direct `fuzzy_ramp()` use for small controllers
- Mamdani and Sugeno controller examples
- User-defined first-order Sugeno consequents
- SDCC MCS-51 build support
- Intel IHX and HEX generation
- Assembly, listing, map, symbol, debug, and memory reports from SDCC
- Desktop software-in-the-loop build from the same controller source
- uCsim execution through `ucsim_51` or the historical `s51` name

## Repository structure

```text
.
├── fuzzy.h
├── strength.c
├── greenhouse.c
├── demo_all.c
├── demo_all_gpu.c
├── braking.c
├── braking_gpu_demo.c
├── controller_8051.c
├── sugeno_demo.c
├── fuzzy_neuron_train.c
├── fuzzy_neuron_kernels.cl
├── setup_opencl.sh
├── Makefile
├── strength/
├── greenhouse/
├── demo-all/
├── demo-gpu/
├── braking/
├── braking_gpu/
├── sugeno/
├── fuzzy-neuron-output/
└── sim-8051/
    ├── desktop/
    └── embedded/
```

`braking.c` is the compact-syntax CPU example. It demonstrates ordinary C rule definitions, all supported sampled defuzzification methods, direct low-level defuzzification calls, and CPU response sweeps.

`braking_gpu_demo.c` is the experimental desktop OpenCL harness. The application supplies the controller-specific kernel function while `fuzzy.h` owns Cartesian input generation, OpenCL setup, execution, readback, CSV output, SVG rendering, and cleanup.

`demo_all_gpu.c` exercises the generic GPU controller descriptors, OpenCL membership and COG sweeps, linguistic hedges, complete membership-shape coverage, and multidimensional GPU-generated SVG output.

`fuzzy_neuron_train.c` provides the experimental interactive fuzzy-neuron workflow. It loads a model definition through a shared-object plugin, trains configurable dense layers from normalized fuzzy-rule activations, saves model checkpoints, tests individual inputs, compares complete datasets, and generates learned response surfaces.

`fuzzy_neuron_kernels.cl` contains the generic OpenCL dense-network kernels used for fuzzy-neuron forward propagation, backpropagation, gradient generation, and mini-batch parameter updates.

`setup_opencl.sh` installs and validates the tested Intel OpenCL environment. It is not the repository build system and is not required by ordinary CPU or embedded builds.

The shared embedded examples can be compiled in two modes:

```text
Desktop GCC build
    -DSIMULATION
    full desktop fuzzy.h API
    console verification, SVG plots, and sweeps

SDCC firmware build
    FUZZY_8051
    reduced embedded fuzzy.h API
    inspectable firmware output and port-level verification
```

## Single-header setup

In exactly one C source file, define `FUZZY_IMPLEMENTATION` before including the header:

```c
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

Other translation units should include the header normally:

```c
#include "fuzzy.h"
```

`FUZZY_IMPLEMENTATION` must be defined in only one translation unit per executable.

### Reduced desktop includes

The desktop branch declares the small set of C runtime functions and types that the implementation uses instead of requiring every application to include a large collection of standard headers before `fuzzy.h`.

The header still links against the ordinary C library and math library. Reduced includes do not mean that libc or libm have been reimplemented; the declarations are kept in the header so the public setup stays compact.

Typical CPU build:

```sh
gcc -O3 -Wall -Wextra -Wpedantic -std=c11 application.c -o application -lm
```

### OpenCL desktop setup

The optional OpenCL path is enabled with `FUZZY_OPENCL`:

```c
#define FUZZY_OPENCL
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

The Makefile may define `FUZZY_OPENCL` instead:

```sh
gcc -O3 -Wall -Wextra -Wpedantic -std=c11 \
    -DFUZZY_OPENCL \
    braking_gpu_demo.c \
    -o braking-gpu \
    -lOpenCL \
    -lm
```

OpenCL support is desktop-only. Do not define `FUZZY_OPENCL` for an SDCC or `FUZZY_8051` firmware build.

### 8051/8052 setup

Include the device definitions, select the embedded backend, and then include `fuzzy.h`:

```c
#ifdef __SDCC
#include <8052.h>
#else
#include <REG51.H>
#endif

#define FUZZY_8051
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

The current header sets rule capacity internally:

```text
Desktop: FUZZY_MAX_RULES = 32
8051:    FUZZY_MAX_RULES = 16
```

## Compressed syntax

The library includes optional adapters that reduce boilerplate without introducing a second runtime or object system:

```c
#define SAND(...) fuzzy_and_method(FUZZY_LOGIC_STANDARD, __VA_ARGS__)
#define SOR(...)  fuzzy_or_method(FUZZY_LOGIC_STANDARD, __VA_ARGS__)
#define AAND(...) fuzzy_and_method(FUZZY_LOGIC_ALGEBRAIC, __VA_ARGS__)
#define AOR(...)  fuzzy_or_method(FUZZY_LOGIC_ALGEBRAIC, __VA_ARGS__)
#define BAND(...) fuzzy_and_method(FUZZY_LOGIC_BOUNDED, __VA_ARGS__)
#define BOR(...)  fuzzy_or_method(FUZZY_LOGIC_BOUNDED, __VA_ARGS__)

#define RULE(rule_var, name, activation, output) \
    FUZZY_RULE_ADD_NAMED(&(rule_var), name, activation, output)

#define OPERATOR(name, operation, method) \
    static float name(float x) { return operation(method, x, 0.5f); }

#define FUZZY_VAR(name, shape, hedge, ...) \
    static float name(float x) { \
        return fuzzy_function(shape, x, hedge, __VA_ARGS__); \
    }

#define SERIES(fn, color) FUZZY_PLOT_FUNCTION_NAMED(#fn, color, fn)

#define PLOT(path, title, max, step, ...) \
    FUZZY_PLOT(path, title, 0.0f, max, step, __VA_ARGS__)
```

Example:

```c
FUZZY_VAR(
    speed_fast,
    FUZZY_SHAPE_RAMP,
    1.0f,
    40.0f,
    80.0f,
    true
)

RULE(
    rules,
    "Hard braking",
    SAND(
        speed_fast(speed),
        obstacle_near(distance)
    ),
    brake_hard
);
```

`braking.c` demonstrates this compressed style as a complete application rather than as isolated macro snippets. The macros expand into the same array-based engine and remain compatible with the intended 8051 build profile when the selected membership functions and features are available in that profile.

GPU usage remains explicit because an arbitrary C controller function cannot be automatically converted into OpenCL C source by the C preprocessor. The host-side OpenCL commands are hidden by `fuzzy.h`, while the application supplies the controller-specific kernel function.

## Membership functions

The generic dispatcher uses `fuzzy_shape_t` rather than string comparisons:

```c
float membership = fuzzy_function(
    FUZZY_SHAPE_GAUSSIAN,
    value,
    hedges.none,
    50.0f,
    10.0f
);
```

The public macro creates the temporary parameter array and determines its length automatically.

### Supported desktop shapes

```text
FUZZY_SHAPE_RAMP        lower, upper, ramp_up
FUZZY_SHAPE_TRIANGLE    left, peak, right
FUZZY_SHAPE_TRAPEZOID   left, top_left, top_right, right
FUZZY_SHAPE_SMF         lower, upper
FUZZY_SHAPE_ZMF         lower, upper
FUZZY_SHAPE_PIMF        a, b, c, d
FUZZY_SHAPE_GAUSSIAN    mean, standard_deviation
FUZZY_SHAPE_GAUSSIAN2   mean_1, deviation_1, mean_2, deviation_2
FUZZY_SHAPE_BELL        width, slope, center
FUZZY_SHAPE_SIGMOID     slope, center
FUZZY_SHAPE_DSIGMOID    slope_1, center_1, slope_2, center_2
FUZZY_SHAPE_PSIGMOID    slope_1, center_1, slope_2, center_2
```

Example ramp:

```c
static float temperature_high(float value)
{
    return fuzzy_function(
        FUZZY_SHAPE_RAMP,
        value,
        hedges.none,
        30.0f,
        60.0f,
        true
    );
}
```

For a reduced controller, the direct ramp API avoids the generic dispatcher:

```c
static float temperature_high(float value)
{
    return fuzzy_ramp(
        30.0f,
        60.0f,
        value,
        true,
        hedges.none
    );
}
```

### Embedded shape availability

The current `FUZZY_8051` branch supports:

- Ramp
- Triangle
- Trapezoid

The desktop-only SMF, ZMF, Pi, Gaussian, Gaussian2, bell, sigmoid, difference-of-sigmoids, and product-of-sigmoids dispatcher cases return zero in the reduced embedded build.

### OpenCL kernel membership primitives

When `FUZZY_OPENCL` is enabled, `FUZZY_GPU_KERNEL_HEADER` supplies compact OpenCL C implementations of:

```text
fuzzy_ramp()
fuzzy_triangle()
fuzzy_trapezoid()
```

The primitives are concatenated into the user-provided kernel source:

```c
static const char *controller_gpu_kernel(void)
{
    return
        FUZZY_GPU_KERNEL_HEADER

        "__kernel void controller(...) {\n"
        "    /* controller-specific kernel */\n"
        "}\n";
}
```

This avoids repeating the basic membership implementations in every GPU demonstration while keeping the controller-specific inference logic explicit.

## N-dimensional sampled-membership interpolation

A sampled point stores a coordinate vector, its dimension count, and a membership value:

```c
fuzzy_point_t point = FUZZY_POINT(
    0.75f,
    temperature,
    humidity,
    pressure
);
```

Interpolate a membership from arbitrary N-dimensional sampled points:

```c
float membership = fuzzy_interpolate_membership(
    FUZZY_INPUTS(42.0f, 65.0f, 100.0f),
    FUZZY_POINT(0.10f, 0.0f, 0.0f, 0.0f),
    FUZZY_POINT(0.65f, 50.0f, 50.0f, 100.0f),
    FUZZY_POINT(1.00f, 100.0f, 100.0f, 200.0f)
);
```

Generate a CSV and interactive SVG sweep from the same sampled data:

```c
FUZZY_INTERPOLATION_SWEEP(
    "demo-all/sampled_interpolation",
    "Sampled Membership Interpolation",
    sampled_membership_points,
    FUZZY_SWEEP_DIMENSION(
        "Temperature",
        0.0f,
        100.0f,
        20.0f
    ),
    FUZZY_SWEEP_DIMENSION(
        "Humidity",
        0.0f,
        100.0f,
        20.0f
    ),
    FUZZY_SWEEP_DIMENSION(
        "Pressure",
        0.0f,
        200.0f,
        10.0f
    )
);
```

Generate one ordinary membership-versus-input SVG slice for every dimension while holding the other dimensions at their midpoints:

```c
FUZZY_INTERPOLATION_SLICES(
    "demo-all/sampled_membership_slice",
    "Sampled Membership",
    sampled_membership_points,
    FUZZY_SWEEP_DIMENSION(
        "Temperature",
        0.0f,
        100.0f,
        0.5f
    ),
    FUZZY_SWEEP_DIMENSION(
        "Humidity",
        0.0f,
        100.0f,
        0.5f
    ),
    FUZZY_SWEEP_DIMENSION(
        "Pressure",
        0.0f,
        200.0f,
        1.0f
    )
);
```

The dimensionality is determined by the number of supplied dimensions. The interpolation and sweep engines are not limited to two, three, or five dimensions. Available memory and the Cartesian sample-count product are the practical limits.

## Linguistic hedges

Desktop hedges use floating-point exponents:

```c
static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};
```

The desktop implementation applies:

```text
hedged membership = membership ^ hedge
```

The reduced 8051 backend uses integer powers:

```c
static const hedges_t hedges = {
    1u,
    2u,
    3u
};
```

Fractional hedges are unavailable in the current 8051 profile.

## Fuzzy operators

### NOT

```c
float result = fuzzy_not(membership);
```

The result is `1 - membership` after the input is clamped to `[0, 1]`.

### AND

```c
float result = fuzzy_and_method(
    FUZZY_LOGIC_STANDARD,
    membership_a,
    membership_b,
    membership_c
);
```

Supported methods:

```text
FUZZY_LOGIC_STANDARD    minimum
FUZZY_LOGIC_ALGEBRAIC   product
FUZZY_LOGIC_BOUNDED     max(0, a + b - 1), applied repeatedly
```

### OR

```c
float result = fuzzy_or_method(
    FUZZY_LOGIC_ALGEBRAIC,
    membership_a,
    membership_b,
    membership_c
);
```

Supported methods:

```text
FUZZY_LOGIC_STANDARD    maximum
FUZZY_LOGIC_ALGEBRAIC   a + b - a*b, applied repeatedly
FUZZY_LOGIC_BOUNDED     min(1, a + b), applied repeatedly
```

The public macros calculate the number of values automatically. There is no manual count argument.

## Sugeno inference

Sugeno helpers accept alternating `firing_strength, consequent` pairs.

### Weighted average

```c
float output = fuzzy_sugeno_weighted_average(
    firing_a, consequent_a,
    firing_b, consequent_b,
    firing_c, consequent_c
);
```

The calculation is:

```text
sum(firing_strength * consequent)
---------------------------------
       sum(firing_strength)
```

### Weighted sum

```c
float output = fuzzy_sugeno_weighted_sum(
    firing_a, consequent_a,
    firing_b, consequent_b
);
```

The calculation is:

```text
sum(firing_strength * consequent)
```

An empty list, null array, odd number of values, or zero total firing strength produces `0.0f`.

### First-order and arbitrary consequents

The library does not restrict a Sugeno consequent to a stored constant or coefficient object. A consequent is simply evaluated by user code before being passed into the weighted-average or weighted-sum helper.

A first-order consequent can therefore remain an ordinary C function:

```c
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
```

Use the evaluated result directly:

```c
return fuzzy_sugeno_weighted_average(
    rule_idle,
    response_idle(
        temperature,
        load,
        vibration
    ),

    rule_cooling,
    response_cooling(
        temperature,
        load,
        vibration
    ),

    rule_protection,
    response_protection(
        temperature,
        load,
        vibration
    )
);
```

This supports zero-order, first-order, higher-order, piecewise, or otherwise custom consequents without adding a separate consequent parser or runtime object model.

### Rule weights

Rule weights can be expressed directly by scaling the activation before inference:

```c
float weighted_activation = activation * rule_weight;
```

The inference path clamps memberships and activations where required. A dedicated weight object is unnecessary unless separate activation and weight values are needed for tracing or model import/export.

### Multiple outputs

Multiple outputs are composed from ordinary controller functions:

```c
outputs.fan_speed =
    calculate_fan_speed(
        temperature,
        load,
        vibration
    );

outputs.valve_position =
    calculate_valve_position(
        temperature,
        pressure
    );

outputs.alarm_level =
    calculate_alarm_level(
        temperature,
        vibration,
        pressure
    );
```

Shared fuzzified values can be calculated once and reused by each output path. A large multi-output object model is not required for runtime inference.

## Mamdani rule API

Create a static rule collection:

```c
fuzzy_rules_t rules;
rules.count = 0u;
```

Add a rule using the output function name automatically:

```c
FUZZY_RULE_ADD(
    &rules,
    activation,
    fan_fast
);
```

Add a custom printable name:

```c
FUZZY_RULE_ADD_NAMED(
    &rules,
    "High temperature produces fast fan",
    activation,
    fan_fast
);
```

Or use the compressed adapter:

```c
RULE(
    rules,
    "High temperature produces fast fan",
    activation,
    fan_fast
);
```

Print rules on desktop:

```c
fuzzy_rules_print(&rules);
```

The rule array is stored directly inside `fuzzy_rules_t`. Resetting the container only requires:

```c
rules.count = 0u;
```

There is no rule-container heap allocation to release.

## Defuzzification methods

Use the general API to select a Mamdani defuzzification method:

```c
float output = fuzzy_rules_defuzzify(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_DEFUZZ_COG
);
```

Available methods:

```text
FUZZY_DEFUZZ_COG    sampled center of gravity
FUZZY_DEFUZZ_BOA    sampled bisector of area
FUZZY_DEFUZZ_COS    sampled center of sums
FUZZY_DEFUZZ_MOM    mean of sampled maximum positions
FUZZY_DEFUZZ_SOM    smallest sampled maximum position
FUZZY_DEFUZZ_LOM    largest sampled maximum position
```

### Center of Gravity

COG first produces the final aggregated Mamdani output and then calculates its sampled balance point:

```text
sum(output_position * aggregated_height)
----------------------------------------
        sum(aggregated_height)
```

COG uses the final aggregated output. With maximum aggregation, overlapping implied rule outputs are counted once through the strongest contribution at each sampled output position.

### Bisector of Area

BOA finds the sampled output position where accumulated aggregated area first reaches half of the complete aggregated area:

```text
accumulated_area >= total_area / 2
```

BOA is not COG calculated over half of the shape. It finds the vertical cutting position that divides the final aggregated fuzzy area into equal left and right portions.

The implementation performs two passes:

1. Sum the complete sampled aggregated area.
2. Walk from the lower bound toward the upper bound until the accumulated area reaches half of the total.

### Center of Sums

COS calculates a centroid while accumulating every implied rule output independently:

```text
sum(rule_output_position * implied_rule_height)
------------------------------------------------
        sum(implied_rule_height)
```

COS intentionally does not max-aggregate the implied rule outputs before calculating the centroid. If several rules support the same output region, the overlap is counted once for each contributing rule.

This differs from ordinary max-aggregated COG:

```text
COG    strongest implied contribution at each position
COS    sum of every rule contribution at each position
```

### Mean, Smallest, and Largest of Maximum

MOM, SOM, and LOM share the sampled maximum-position search:

```text
MOM    arithmetic mean of all sampled maximum positions
SOM    smallest sampled maximum position
LOM    largest sampled maximum position
```

### Directly callable defuzzification functions

Every method has a direct public function.

COG:

```c
float cog = fuzzy_rules_defuzzify_cog(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX
);
```

BOA:

```c
float boa = fuzzy_rules_defuzzify_boa(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX
);
```

COS:

```c
float cos = fuzzy_rules_defuzzify_cos(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_IMPLICATION_MIN
);
```

COS has no aggregation-method argument because aggregation is intentionally not used.

MOM:

```c
float mom = fuzzy_rules_defuzzify_mom(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX
);
```

SOM:

```c
float som = fuzzy_rules_defuzzify_som(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX
);
```

LOM:

```c
float lom = fuzzy_rules_defuzzify_lom(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_IMPLICATION_MIN,
    FUZZY_AGGREGATION_MAX
);
```

### Configurable wrapper

Select defuzzification, implication, and aggregation independently:

```c
float output = fuzzy_rules_defuzzify_method(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_DEFUZZ_COG,
    FUZZY_IMPLICATION_PRODUCT,
    FUZZY_AGGREGATION_ALGEBRAIC
);
```

The simpler wrapper uses minimum implication and maximum aggregation:

```c
float output = fuzzy_rules_defuzzify(
    &rules,
    0.0f,
    100.0f,
    1.0f,
    FUZZY_DEFUZZ_BOA
);
```

The compatibility wrapper remains available:

```c
float output = fuzzy_rules_cog(
    &rules,
    0.0f,
    100.0f,
    1.0f
);
```

The `step` controls sampling resolution. A smaller step evaluates more output positions and usually gives a finer approximation at increased execution cost.

## Desktop visualization

### Membership plots

```c
PLOT(
    "strength/strength",
    "Paint Strength Membership Functions",
    100.0f,
    1.0f,
    SERIES(
        strength_little,
        "#ef4444"
    ),
    SERIES(
        strength_fair,
        "#22c55e"
    )
);
```

The full `FUZZY_PLOT(...)` and `FUZZY_PLOT_FUNCTION_NAMED(...)` forms remain available when explicit lower bounds or labels are needed.

### Selected defuzzification plot

```c
float cog = fuzzy_rules_cog(
    &rules,
    0.0f,
    100.0f,
    1.0f
);

fuzzy_rules_plot_cog(
    &rules,
    "strength/selected_cog",
    "Selected Mamdani Output",
    cog,
    0.0f,
    100.0f,
    1.0f
);
```

The current selected-output plot helper is specifically named and labelled for COG. BOA, COS, MOM, SOM, and LOM can be calculated and swept, but should not be passed into a plot that is labelled as COG unless the label and helper are extended.

### N-dimensional controller sweeps

```c
return FUZZY_COG_SWEEP(
    "greenhouse/greenhouse_cog_sweep",
    "Greenhouse Watering-Time COG Sweep",
    evaluate_time_sweep,
    0.1f,
    FUZZY_SWEEP_DIMENSION(
        "Temperature",
        0.0f,
        30.0f,
        1.0f
    ),
    FUZZY_SWEEP_DIMENSION(
        "Humidity",
        0.0f,
        30.0f,
        1.0f
    )
);
```

A sweep writes CSV and SVG from the same calculated values. The CSV is not reopened or parsed, and the controller is not reevaluated for the SVG.

Higher-dimensional SVG heatmaps use the first two dimensions as visible axes. Remaining dimensions receive interactive sliders, with continuous interpolation between precomputed samples.

Although the compatibility macro remains named `FUZZY_COG_SWEEP`, the evaluator controls the returned value. An evaluator can therefore return BOA, COS, MOM, SOM, or LOM to create comparison surfaces, provided that the output title and value label accurately identify the method.

## Experimental OpenCL GPU support

The optional OpenCL path accelerates large Cartesian controller sweeps. Each GPU work item evaluates one complete input combination and writes one crisp output. `fuzzy.h` then writes the returned values through the same CSV and SVG sweep renderer used by CPU-generated results.

## Experimental fuzzy-neuron training

The experimental fuzzy-neuron path trains a compact neural surrogate from the normalized activations of fixed fuzzy rules.

The current architecture is better described as a **fuzzy-feature neural surrogate** than canonical ANFIS:

```text
Raw controller inputs
    -> fixed membership functions
    -> fixed fuzzy-rule activations
    -> normalized rule-feature vector
    -> configurable dense neural layers
    -> continuous output
```

```c
FUZZY_NEURON_RULE(
    cooling,
    SAND(
        temperature_high(x[0]),
        load_high(x[1])
    )
)

FUZZY_NEURON_BIND((*model), idle);
FUZZY_NEURON_BIND((*model), economy);
FUZZY_NEURON_BIND((*model), balanced);
FUZZY_NEURON_BIND((*model), cooling);
FUZZY_NEURON_BIND((*model), heavy_load);
FUZZY_NEURON_BIND((*model), protection);

FUZZY_NEURON_LAYER(
    (*model),
    10u,
    FUZZY_NEURON_SIGMOID
);

FUZZY_NEURON_LAYER(
    (*model),
    10u,
    FUZZY_NEURON_SIGMOID
);

FUZZY_NEURON_OUTPUT(
    (*model),
    FUZZY_NEURON_LINEAR
);

//Training Network Setup
fuzzy_neuron_train_options_t options =
    FUZZY_NEURON_TRAIN_OPTIONS(
        epochs,
        batch_size,
        learning_rate,
        report_interval
    );

FUZZY_NEURON_LINEAR
FUZZY_NEURON_SIGMOID
FUZZY_NEURON_TANH
FUZZY_NEURON_RELU
```

### User-facing GPU sweep

```c
bool sweep_success = FUZZY_GPU_SWEEP(
    "braking_gpu/gpu_sweep",
    "GPU Braking Controller",
    "COG",
    braking_gpu_kernel,
    "braking_sweep",
    0.25f,
    FUZZY_SWEEP_DIMENSION(
        "Speed",
        0.0f,
        100.0f,
        1.0f
    ),
    FUZZY_SWEEP_DIMENSION(
        "Distance",
        0.0f,
        100.0f,
        1.0f
    )
);
```

The application does not directly manage:

```text
cl_context
cl_command_queue
cl_program
cl_kernel
cl_mem
clCreateBuffer()
clSetKernelArg()
clEnqueueNDRangeKernel()
clEnqueueReadBuffer()
clReleaseMemObject()
```

`fuzzy.h` handles:

- N-dimensional Cartesian input generation
- Flattened input-array construction
- OpenCL platform selection
- GPU device selection
- Context creation
- Command-queue creation
- Program creation
- Runtime kernel compilation
- Kernel build-log reporting
- Input and output buffer creation
- Kernel argument binding
- Kernel execution
- GPU synchronization
- Output readback
- CSV generation
- SVG generation
- OpenCL cleanup
- Host-memory cleanup

### Kernel contract

The GPU sweep harness expects the kernel interface:

```c
__kernel void controller(
    __global const float *inputs,
    __global float *outputs,
    const uint point_count,
    const uint dimension_count,
    const float defuzz_step
)
```

Inputs are flattened by point:

```text
point 0: input 0, input 1, ... input N
point 1: input 0, input 1, ... input N
point 2: input 0, input 1, ... input N
```

The controller-specific kernel obtains one point with:

```c
uint id = get_global_id(0);
uint base = id * dimension_count;

float input_0 = inputs[base];
float input_1 = inputs[base + 1u];
```

### Controller-specific kernel function

The application still supplies the controller-specific OpenCL C source because the C preprocessor cannot inspect an arbitrary CPU function and translate that function into a GPU kernel.

```c
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
        "    const uint id=get_global_id(0);\n"
        "    if(id>=point_count)return;\n"
        "    const uint base=id*dimension_count;\n"
        "    const float speed=inputs[base];\n"
        "    const float distance=inputs[base+1u];\n"
        "    /* controller-specific fuzzification, rules, and COG */\n"
        "}\n";
}
```

`FUZZY_GPU_KERNEL_HEADER` supplies reusable OpenCL implementations of ramp, triangle, and trapezoid membership functions.

### Experimental scope and AI-assisted development intent

The OpenCL path is deliberately experimental. The purpose is to explore an inspectable GPU execution model that fits the project's AI-assisted development theme, especially while GPU-oriented AI and machine-learning workflows are becoming common.

The feature is not intended to replace established machine-learning stacks or claim that OpenCL is the best interface for every GPU. Users who already have a CUDA, SYCL, Vulkan compute, vendor framework, or ML workflow can use that approach directly.

For users who do not already have a GPU framework, the current OpenCL harness is a starting point:

```text
CPU fuzzy controller
    -> equivalent explicit OpenCL kernel
    -> N-dimensional GPU batch execution
    -> CSV output
    -> native SVG visualization
```

The implementation keeps the mechanism visible rather than generating a hidden graph or requiring a large external runtime.

### Desktop-only limitation

OpenCL support is desktop-only. It is not compiled into:

- `FUZZY_8051`
- SDCC MCS-51 builds
- AT89S52 firmware
- Embedded simulation profiles that use the reduced backend

The embedded path continues to use ordinary CPU inference.

### Tested Intel environment

The currently tested OpenCL route is specifically:

```text
GPU:         Intel HD Graphics 620
Device:      Intel(R) Graphics [0x5916]
Runtime:     Intel OpenCL Legacy 24.35
API:         OpenCL 1.2
Environment: Ubuntu / WSL2
```

The Intel runtime used here is a legacy runtime. The setup is hardware-specific and should not be presented as a universal OpenCL installation process.

Other Intel GPUs, AMD GPUs, NVIDIA GPUs, Mesa ICDs, native Linux installations, native Windows installations, and different WSL configurations may require different runtimes, packages, kernel interfaces, or device selection.

## Intel OpenCL setup

`setup_opencl.sh` installs and verifies the OpenCL environment used by `braking_gpu_demo.c` on the tested Intel HD Graphics 620 system.

The script performs:

1. Linux distribution and kernel checks.
2. WSL detection information.
3. `/dev/dxg` and DRM render-node checks.
4. Removal of `mesa-opencl-icd` for the tested configuration.
5. Package-list update.
6. Installation of the Intel legacy runtime and development tools.
7. Intel ICD-file verification.
8. `clinfo` platform and device inspection.
9. Exact detection of `Intel(R) Graphics [0x5916]`.
10. Generation of a standalone OpenCL vector-addition test.
11. Test compilation with `-lOpenCL`.
12. Kernel execution and numerical verification.

Run:

```sh
chmod +x setup_opencl.sh
./setup_opencl.sh
```

The installed packages are:

```text
intel-opencl-icd-legacy
ocl-icd-opencl-dev
clinfo
build-essential
```

The script expects the Intel legacy ICD file:

```text
/etc/OpenCL/vendors/intel_legacy1.icd
```

The script then generates:

```text
gpu_test.c
gpu_test
```

and verifies a 1024-element GPU vector addition.

### Important setup warning

`setup_opencl.sh`:

- Uses `sudo`
- Uses `apt-get`
- Removes `mesa-opencl-icd` when installed
- Installs an Intel legacy OpenCL runtime
- Checks for one specific Intel device identifier
- Was written for Ubuntu or WSL2

Review the script before running it on another GPU or distribution. Users with another working OpenCL ICD should not blindly replace that environment with the Intel-specific setup.

## Included applications

### Paint-strength system

`strength.c` demonstrates Mamdani rules, paint-strength output, membership plots, selected defuzzification, and response sweeps.

```sh
make run-strength
```

### Greenhouse watering-time system

`greenhouse.c` demonstrates temperature and humidity inputs, watering-time output, membership functions, Mamdani aggregation, defuzzification plotting, and a two-dimensional sweep.

```sh
make run-greenhouse
```

### Complete API demonstration

`demo_all.c` exercises the broad desktop API, including membership shapes, hedges, logic families, implication and aggregation methods, Mamdani rules, Sugeno helpers, N-dimensional sampled interpolation, interpolation slices, plotting, and interactive sweeps.

```sh
make run-demo
```

### Complex Sugeno fan controller

`sugeno_demo.c` demonstrates:

- User-defined first-order Sugeno consequents
- Temperature, load, and vibration inputs
- Weighted-average inference
- Desktop verification
- Membership plots
- Three-dimensional response sweeps
- Shared desktop and AT89S52 source structure

```sh
make run-sugeno
make embedded-sugeno
```

### Compressed braking controller

`braking.c` demonstrates the compact adapters in a complete controller:

- `FUZZY_VAR(...)`
- `SAND(...)`, `SOR(...)`, `AAND(...)`, `AOR(...)`, `BAND(...)`, and `BOR(...)`
- `RULE(...)`
- `SERIES(...)`
- `PLOT(...)`
- COG, BOA, COS, MOM, SOM, and LOM
- Direct low-level defuzzification calls
- Defuzzification comparison output
- Separate response sweeps for different methods or scenarios

The braking example is also useful for comparing the semantics of the six sampled methods on one rule base.

### Experimental GPU braking controller

`braking_gpu_demo.c` is the OpenCL test harness and demonstration application.

The application contains:

- The original CPU membership functions
- A CPU braking controller for selected-point verification
- A controller-specific OpenCL kernel function
- `FUZZY_GPU_KERNEL_HEADER`
- A single `FUZZY_GPU_SWEEP(...)` call
- Membership SVG generation
- GPU-generated CSV and heatmap output

The application does not contain the low-level OpenCL setup and buffer-management commands. Those commands are wrapped by the optional `fuzzy.h` GPU implementation.

```sh
./setup_opencl.sh
make run-gpu
```

Generated files are written to:

```text
braking_gpu/
```

### Shared desktop and 8051 controller

`controller_8051.c` builds as both:

- `sim-8051-app` with GCC and `-DSIMULATION`
- `controller_8051.ihx` and `controller_8051.hex` with SDCC

```sh
make run-sim-8051
make embedded
```

## Build system

The main build workflow is implemented directly in the `Makefile`. `setup_opencl.sh` is an optional environment-setup utility, not a replacement build dispatcher.

The Makefile performs:

- Optional `ccache` detection
- Optional `mold` detection
- GCC desktop builds
- Desktop example execution
- OpenCL GPU build with `-DFUZZY_OPENCL`
- OpenCL linking with `-lOpenCL`
- `make run-gpu`
- OpenCL header and loader checks
- GPU output-directory creation
- GPU SVG-to-PNG and SVG-to-PDF conversion targets
- GPU executable and generated-output cleanup
- SDCC firmware compilation
- Intel HEX packing
- uCsim command discovery
- 8051 host-branch testing
- Optional SVG-to-PNG and SVG-to-PDF conversion
- Dependency checking and apt-based installation
- Desktop and embedded cleanup

OpenCL is linked only into `braking-gpu`. Ordinary CPU applications and embedded firmware do not depend on OpenCL.

Make recipes still use normal POSIX shell commands such as `mkdir`, `rm`, `find`, loops, and conditionals. This is standard Make recipe execution and does not require a repository-owned build-script dispatcher.

## Quick start

### Check dependencies

```sh
make check-dependencies
```

### Install ordinary dependencies on Debian, Ubuntu, or WSL

```sh
make install-dependencies
```

### Configure the tested Intel OpenCL environment

```sh
chmod +x setup_opencl.sh
./setup_opencl.sh
```

This step is optional and required only for the tested Intel GPU path.

### Build everything

```sh
make
```

If the OpenCL development files are unavailable, build individual CPU and embedded targets instead of the GPU-inclusive desktop group.

### Build only desktop programs

```sh
make desktop
```

### Build only embedded firmware

```sh
make embedded
```

### Run the GPU demonstration

```sh
make run-gpu
```

### Show command help

```sh
make help
```

## Command reference

```text
make
    Build all desktop programs and embedded firmware.

make desktop
    Build all desktop executables, including braking-gpu.

make embedded
    Build Mamdani and Sugeno SDCC firmware.

make build-8051
    Build the Mamdani SDCC MCS-51 firmware and pack Intel HEX output.

make build-sugeno-8051
    Build the Sugeno SDCC MCS-51 firmware and pack Intel HEX output.

make run-strength
    Build and run the paint-strength example.

make run-greenhouse
    Build and run the greenhouse example.

make run-demo
    Build and run the complete API demonstration.

make run-sugeno
    Build and run the desktop Sugeno controller demonstration.

make run-gpu
    Build braking_gpu_demo.c with FUZZY_OPENCL and run the OpenCL sweep.

make run-sim-8051
    Build controller_8051.c with -DSIMULATION and run it from
    sim-8051/desktop/.

make embedded-mamdani
    Build controller_8051.c as AT89S52 firmware.

make embedded-sugeno
    Build sugeno_demo.c as AT89S52 firmware.

make simulate-8051
    Build the Mamdani firmware and load its IHX image into uCsim.

make simulate-sugeno
    Build the Sugeno firmware and load its IHX image into uCsim.

make debug-8051
    Prepare source and simulator compatibility paths, then launch SDCDB.

make check-dependencies
    Report required tools, OpenCL headers and loader, and optional tools.

make install-dependencies
    Install apt-based build, conversion, simulation, and OpenCL
    development dependencies.

make png
make pdf
    Convert all generated SVG groups.

make png-gpu
make pdf-gpu
    Convert braking_gpu SVG output.

make clean
    Remove generated desktop and embedded artifacts.

make clean-desktop
    Remove desktop executables and generated SVG, PNG, PDF, and CSV output,
    including braking-gpu and braking_gpu/ output.

make clean-embedded
    Remove generated Mamdani and Sugeno firmware artifacts.
```

## Output directories

```text
strength/
    Paint-strength SVG, CSV, PNG, and PDF output.

greenhouse/
    Greenhouse SVG, CSV, PNG, and PDF output.

demo-all/
    Complete API demonstration output.

sugeno/
    Sugeno desktop plots, response sweeps, and embedded output.

braking_gpu/
    Experimental OpenCL braking-controller CSV, SVG, PNG, and PDF output.

sim-8051/desktop/
    Desktop controller CSV, SVG, PNG, and PDF output.

sim-8051/embedded/
    SDCC Mamdani firmware and analysis output.
```

Typical embedded files include:

```text
controller_8051.ihx
controller_8051.hex
controller_8051.asm
controller_8051.cdb
controller_8051.lst
controller_8051.map
controller_8051.mem
controller_8051.rst
controller_8051.sym
```

The Sugeno embedded directory similarly contains files based on `sugeno_8051`.

SDCC's MCS-51 backend produces Intel HEX firmware rather than a conventional desktop executable.

## 8051 and 8052 support

The embedded path uses `FUZZY_8051`, excludes desktop I/O, plotting, heap allocation, CSV generation, and OpenCL, and retains the reduced fuzzy-logic runtime.

The current Mamdani firmware command is equivalent to:

```sh
sdcc -mmcs51 \
    --model-small \
    --opt-code-size \
    --debug \
    --stack-auto \
    --iram-size 256 \
    --stack-loc 0x80 \
    -I../.. \
    -o controller_8051.ihx \
    ../../controller_8051.c
```

SDCC currently warns that `--stack-loc` is deprecated. The build still completes, but the option should be reviewed against the installed SDCC version before relying on it long-term.

Always inspect generated `.mem`, `.map`, and `.lst` files. Floating-point arithmetic and automatic stack storage are expensive on MCS-51 targets.

### Keil C51 note

A floating-point controller can exceed the code-size restriction of the free Keil C51 evaluation toolchain even when the target device has enough program storage. SDCC is the unrestricted firmware build path used by this repository.

### Simulator notes

- uCsim is the recommended firmware execution path.
- SDCDB remains available for experimentation but may be unreliable with modern package layouts.
- EdSim51 is useful for smaller port tests but may not accurately accommodate a float-heavy stack profile.
- OpenCL is unrelated to the embedded path and is not available on the AT89S52 target.

## 8051 firmware verification

Start the simulator through the Makefile:

```sh
make simulate-8051
```

The Makefile selects `ucsim_51`, falls back to `s51`, or accepts an explicit simulator through `S51`.

A controller may expose values through ports such as:

```text
P0 = execution status
P1 = rounded controller output
P2 = test input
```

Example status values:

```text
P0 = 0x55    calculation started
P0 = 0xAA    calculation completed
```

At the uCsim prompt:

```text
reset
set memory sfr 0xA0 0x2A
step 1000000
dump sfr 0x80 0x80
dump sfr 0x90 0x90
dump sfr 0xA0 0xA0
```

Relevant SFR addresses:

```text
P0 = 0x80
P1 = 0x90
P2 = 0xA0
SP = 0x81
```

If execution stops on a self-jump such as `SJMP`, that is commonly the compiled final hold loop:

```c
for (;;) {
    ;
}
```

The firmware has completed and is preserving output ports.

## Optional PNG and PDF conversion

`fuzzy.h` writes SVG directly. Numerical evaluation and SVG generation do not require `rsvg-convert`.

Install the optional converter:

```sh
sudo apt-get install librsvg2-bin
```

Generate plots and convert them:

```sh
make run-strength
make run-greenhouse
make run-demo
make run-sugeno
make run-gpu
make run-sim-8051
make png
make pdf
```

Convert only GPU output:

```sh
make png-gpu
make pdf-gpu
```

Converted files are stored beside their source SVG files.

## Opening generated plots

SVG files can be opened in Firefox, Chromium, Chrome, Edge, Inkscape, VS Code, or another SVG-compatible application.

From WSL:

```sh
explorer.exe "$(wslpath -w "$PWD/demo-all/sampled_interpolation.svg")"
```

Open the GPU heatmap from WSL:

```sh
explorer.exe "$(wslpath -w "$PWD/braking_gpu/gpu_sweep.svg")"
```

Use PNG conversion targets when the preferred native image viewer does not display SVG files.

## Project status

The following paths are functional:

- Desktop fuzzy inference
- Twelve documented desktop membership shapes
- Ramp, triangle, and trapezoid shapes on 8051
- Standard, algebraic, and bounded fuzzy operators
- Minimum and product implication
- Maximum, algebraic, and bounded aggregation
- Zero-order, first-order, and arbitrary user-defined Sugeno consequents
- Sugeno weighted average and weighted sum
- Static Mamdani rules
- COG, BOA, COS, MOM, SOM, and LOM defuzzification
- Direct low-level defuzzification functions
- General configurable defuzzification wrapper
- Native SVG plotting
- N-dimensional sampled-membership interpolation
- N-dimensional controller and interpolation sweeps
- Interactive higher-dimensional SVG slices
- Automatic per-dimension interpolation slice plots
- Shared desktop and embedded controller source
- Compressed syntax in `braking.c`
- Complex Sugeno controller in `sugeno_demo.c`
- Experimental OpenCL harness in `fuzzy.h`
- OpenCL braking demonstration in `braking_gpu_demo.c`
- Intel setup and verification in `setup_opencl.sh`
- GPU-computed CSV and SVG sweep output
- SDCC IHX and HEX generation
- uCsim port-level verification

The API remains experimental and may change as the project develops. The OpenCL path is more experimental than the ordinary CPU and embedded paths and is currently verified only on the documented Intel environment.

## Safety and limitations

This is a learning-focused side project, not a production-hardened or safety-certified control framework.

Important limitations:

- Macro arguments must follow the documented order.
- `fuzzy_function()` parameters are packed into a temporary float array.
- Invalid shapes or parameter counts return zero.
- Sugeno calls require alternating firing-strength and consequent pairs.
- Rule capacity is fixed at compile time.
- Mamdani defuzzification is a sampled numerical approximation.
- Defuzzification bounds must cover the complete output universe.
- A smaller defuzzification step increases work and memory pressure in large sweeps.
- BOA returns the first sampled position where accumulated area reaches half of the total.
- COS counts overlapping implied outputs once for every contributing rule.
- Exact floating-point equality is used when collecting sampled maxima.
- N-dimensional sweep memory grows with the product of every dimension's sample count.
- Higher-dimensional SVGs embed calculated output data and JavaScript.
- Scattered-point interpolation currently uses inverse squared Euclidean-distance weighting without automatic dimension normalization.
- Dimensions with very different physical scales can dominate interpolation distance unless the application normalizes them or chooses points carefully.
- Interpolation slices hold non-varying dimensions at their midpoint.
- Plotting writes directly to files and is not hardened against every malformed input.
- The selected-output plot helper is currently COG-specific.
- The OpenCL path requires a controller-specific kernel implementation.
- The C preprocessor cannot automatically convert an arbitrary CPU controller function into OpenCL C.
- OpenCL kernels compile at runtime and can fail because of device-specific compiler behavior.
- CPU and GPU floating-point results can differ slightly because of compiler, device, and operation-order differences.
- The GPU implementation currently selects an OpenCL GPU device and does not provide a mature cross-vendor device-selection policy.
- The tested GPU path uses OpenCL 1.2 and the Intel legacy runtime.
- `setup_opencl.sh` is specific to Intel HD Graphics 620 on the documented Ubuntu or WSL2 environment.
- The setup script removes `mesa-opencl-icd` in the tested configuration and should be reviewed before use elsewhere.
- OpenCL support is desktop-only and is excluded from `FUZZY_8051`.
- The 8051 backend intentionally excludes several desktop membership shapes.
- Floating-point 8051 firmware is code-heavy, stack-heavy, and slow compared with a fixed-point implementation.
- `--stack-loc` is deprecated by current SDCC versions.
- SDCDB behavior varies across distributions.
- The embedded examples have not undergone timing certification, hardware-in-the-loop validation, long-duration stack analysis, security auditing, or formal verification.
- The GPU experiment has not undergone cross-vendor validation, long-duration load testing, or production driver qualification.

Use the project for learning, experiments, assignments, prototypes, and controlled systems where the code can be reviewed and tested.

## Planned work

The project intentionally keeps parsing, model storage, heavy data tooling, and mandatory GPU frameworks outside the core inference path unless a feature can remain small and inspectable.

### Core numerical work

- Max-min fuzzy relation composition
- Max-product fuzzy relation composition
- Cartesian fuzzy relation helpers
- Generic batch evaluation over arbitrary input rows
- Reference numerical tests against established implementations
- Desktop-versus-8051 fixed-vector regression tests
- CPU-versus-GPU fixed-vector regression tests
- Better tolerance handling for sampled maxima
- Optional normalized-distance interpolation
- Compile-time feature selection
- Additional defuzzification plot labelling

### GPU work

- More portable OpenCL platform and device selection
- Optional CPU-device fallback through OpenCL
- Explicit kernel timing through OpenCL profiling events
- GPU build and execution diagnostics
- CPU/GPU error reports in the demo harness
- Additional membership primitives in `FUZZY_GPU_KERNEL_HEADER`
- More defuzzification methods in example kernels
- Vendor testing beyond the Intel legacy implementation
- Optional support for other GPU backends without making them core dependencies
- Generated kernel experiments only if generation remains inspectable

The OpenCL work is exploratory. Users already working in established ML or GPU environments can map the same fuzzy calculations into their own preferred runtime.

### Data-driven fuzzy tools

- Fuzzy C-means clustering
- Fuzzy C-means prediction
- Subtractive clustering
- Cluster-derived membership initialization
- Automatic Sugeno rule generation
- Dataset-driven first-order Sugeno coefficient generation
- Parameter tuning through simple inspectable optimizers
- Loss-function and training callbacks

Parameter tuning is deliberately listed as later work because it requires parameter bounds, invalid-shape prevention, dataset handling, objective functions, stopping rules, and overfitting controls.

### Model and data exchange

- Optional CSV loader for N-dimensional sampled points and datasets
- Optional JSON conversion tooling outside the core header
- Optional MATLAB-compatible FIS conversion tooling
- Generated C headers as the preferred embedded deployment format
- No mandatory runtime JSON parser in `fuzzy.h`

A likely workflow is:

```text
CSV, JSON, or FIS model
    -> optional host-side converter
    -> generated C arrays and functions
    -> fuzzy.h application
```

### Desktop and visualization

- Interactive graphical interface
- Live input adjustment
- Rule activation visualization
- Configurable graph dimensions and labels
- Additional plot themes
- Automated regression reports
- Batch dataset plots
- Cluster and generated-rule visualization
- Direct BOA, COS, MOM, SOM, and LOM selected-output plot labels
- GPU execution summaries inside generated reports

### Embedded work

- Fixed-point membership calculations
- Fixed-point Mamdani defuzzification
- Fixed-point Sugeno helpers
- Reduced floating-point dependence
- Explicit stack-depth testing
- Smaller firmware profiles
- Timer-driven PWM output
- Sensor input examples
- Software-in-the-loop regression tests
- Hardware-in-the-loop validation
- ESP-class microcontroller support
- Additional 8051 compiler and simulator testing

### Advanced ideas

These are possible future directions, not current commitments:

- Interval type-2 fuzzy sets
- Type reduction
- Tsukamoto inference
- ANFIS-style training
- Connected fuzzy subsystems or fuzzy trees

## AI-assisted development

This project was built with AI-assisted iteration, debugging, API refactoring, documentation, and testing.

The point is not to hide that fact. The project is also an experiment in whether AI-assisted development can contribute to low-level, inspectable software instead of only generating scripts around large frameworks.

The experimental OpenCL path extends that question into GPU execution. GPU computation is common in AI and machine-learning systems, but this project keeps the path explicit:

```text
ordinary C host code
ordinary OpenCL C kernel source
explicit membership calculations
explicit rule activations
explicit sampled defuzzification
native CSV and SVG output
```

The GPU extension is a starting point for users who want to explore accelerated fuzzy sweeps without first adopting a large ML framework. Users already comfortable with machine-learning frameworks, CUDA, SYCL, Vulkan compute, or vendor-specific tooling should use whichever approach fits their environment.

Every generated or suggested component remains ordinary C, OpenCL C, shell, or Make code that can be read, tested, modified, profiled, and replaced.

## Joke

Even this README is AI generated because I reaaaaaaalllllly could not be bothered to type English essays here.

You are software engineers. You probably know more than my attempt at low-level development, so if something is wrong, report it and I can steal your better idea `(❁´◡`❁)`.

Thanks for trying it out, and support the noble cause of screwing with Python users.

## Contributing

Issues, bug reports, test cases, fixes, documentation improvements, embedded ports, simulator notes, OpenCL notes, and alternative implementations are welcome.

Before submitting a change:

1. Run `make`.
2. Run the included desktop examples.
3. Run the compressed `braking.c` example.
4. Confirm that COG, BOA, COS, MOM, SOM, and LOM produce expected values.
5. Confirm that expected SVG and CSV files are generated.
6. Run the desktop Sugeno example.
7. Build the firmware with `make embedded`.
8. Confirm that shared controller sources still compile through the intended 8051 path.
9. Review generated `.mem`, `.map`, and `.lst` reports.
10. Run the IHX image through `make simulate-8051` when modifying the embedded path.
11. When modifying OpenCL support, run `setup_opencl.sh` on the tested Intel environment.
12. Run `make run-gpu` and compare representative GPU values against the CPU controller.
13. Clearly describe API, numerical, stack, memory, firmware, GPU-kernel, runtime, and driver assumptions.

## License

See the repository's `LICENSE` file for the terms under which this project may be copied, modified, and distributed.

A permissive licence such as MIT is a practical fit when the intended use is to copy `fuzzy.h` directly into other projects.

## Philosophy

Fuzzy logic and membership visualization do not inherently require a notebook, interpreter, virtual environment, hundreds of transitive dependencies, or proprietary software.

Sometimes the complete desktop fuzzy system can be:

```c
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

Sometimes the experimental GPU-enabled desktop system can be:

```c
#define FUZZY_OPENCL
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

And sometimes the embedded system can be:

```c
#define FUZZY_8051
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

No Python environment. No MATLAB toolbox. No plotting framework for the ordinary CPU path. No mandatory machine-learning runtime.

Just C, Make, inspectable numerical output, native SVG graphs on desktop, optional experimental OpenCL acceleration for the tested Intel environment, and inspectable firmware artifacts for constrained targets.
