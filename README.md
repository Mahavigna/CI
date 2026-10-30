# fuzzy.h

A lightweight, single-header fuzzy-logic library written in C.

`fuzzy.h` provides type-1 membership functions, configurable linguistic hedges, multiple fuzzy AND/OR methods, Mamdani and Sugeno inference helpers, static rule storage, sampled defuzzification, N-dimensional scattered-point membership interpolation, native SVG plotting, CSV-backed multidimensional sweeps, interactive higher-dimensional slices, and a reduced 8051/8052 firmware path.

The desktop engine and SVG generator require no Python environment, MATLAB toolbox, plotting framework, or external runtime. PNG and PDF conversion are optional conveniences provided through `rsvg-convert`.

The implementation remains readable, editable, and contained in one header. The build workflow lives directly in the `Makefile`; there is no repository-owned build-script dispatcher.

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
- [Included applications](#included-applications)
- [Build system](#build-system)
- [Quick start](#quick-start)
- [Command reference](#command-reference)
- [Output directories](#output-directories)
- [8051 and 8052 support](#8051-and-8052-support)
- [8051 firmware verification](#8051-firmware-verification)
- [Optional PNG and PDF conversion](#optional-png-and-pdf-conversion)
- [Project status](#project-status)
- [Safety and limitations](#safety-and-limitations)
- [Planned work](#planned-work)
- [AI-assisted development](#ai-assisted-development)
- [Contributing](#contributing)
- [License](#license)
- [Philosophy](#philosophy)

## Why?

Many fuzzy-logic examples immediately reach for Python libraries or MATLAB toolboxes. Those tools are useful, but they can hide the calculations behind frameworks, objects, plotting environments, package managers, and large dependency chains.

This project takes the opposite approach:

- Plain C
- One implementation header
- No Python environment
- No MATLAB toolbox
- No package manager for the core library
- No external plotting library for native SVG generation
- Direct access to every calculation
- User-defined C functions for membership functions and Sugeno consequents
- Static Mamdani rule storage
- Desktop simulation and embedded experimentation
- A reduced 8051/8052 build path
- A Makefile-owned workflow with no separate build script

The objective is not to replace mature numerical-computing platforms. The objective is to make fuzzy-logic execution small, inspectable, modifiable, and easy to integrate into an ordinary C project.

## Current features

### Core fuzzy engine

- Single-header implementation
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
- COG, MOM, SOM, and LOM sampled defuzzification
- N-dimensional scattered-point membership interpolation
- N-dimensional interpolation sweeps and per-dimension membership slices
- Floating-point desktop hedges
- Integer-power 8051 hedges

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
- Optional SVG-to-PNG conversion
- Optional SVG-to-PDF conversion

### Embedded support

- `FUZZY_8051` reduced backend
- Static rule storage
- No plotting, heap allocation, CSV generation, or file I/O in firmware builds
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
├── braking.c
├── controller_8051.c
├── Makefile
├── svg/
├── greenhouse/
├── demo-all/
└── sim-8051/
    ├── desktop/
    ├── embedded/
    └── test_8051_host.c
```

`braking.c` is the compact-syntax example. It demonstrates that the short adapters remain ordinary C and still compile through the reduced 8051 path.

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

#define RULE(name, activation, output) \
    FUZZY_RULE_ADD_NAMED(rules, name, activation, output)

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
FUZZY_VAR(speed_fast, FUZZY_SHAPE_RAMP, hedges.none, 40.0f, 80.0f, true)

RULE(
    "Hard braking",
    SAND(speed_fast(speed), obstacle_near(distance)),
    brake_hard
);
```

`braking.c` demonstrates this compressed style as a complete application rather than as isolated macro snippets. The macros expand into the same array-based engine and remain compatible with the intended 8051 build profile when the selected membership functions and features are available in that profile.

Build and run the desktop form:

```sh
make run-braking
```

Build the embedded form through the repository's 8051 target:

```sh
make braking-8051
```

If the local Makefile uses a different target name, run `make help` for the exact braking and embedded targets.

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
    FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 20.0f),
    FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 20.0f),
    FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 10.0f)
);
```

Generate one ordinary membership-versus-input SVG slice for every dimension while holding the other dimensions at their midpoints:

```c
FUZZY_INTERPOLATION_SLICES(
    "demo-all/sampled_membership_slice",
    "Sampled Membership",
    sampled_membership_points,
    FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 100.0f, 0.5f),
    FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 100.0f, 0.5f),
    FUZZY_SWEEP_DIMENSION("Pressure", 0.0f, 200.0f, 1.0f)
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
    rule_idle, response_idle(temperature, load, vibration),
    rule_cooling, response_cooling(temperature, load, vibration),
    rule_protection, response_protection(temperature, load, vibration)
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
outputs.fan_speed = calculate_fan_speed(temperature, load, vibration);
outputs.valve_position = calculate_valve_position(temperature, pressure);
outputs.alarm_level = calculate_alarm_level(temperature, vibration, pressure);
```

Shared fuzzified values can be calculated once and reused by each output path. A large multi-output object model is not required for runtime inference.

## Mamdani rule API

Create a static rule collection:

```c
fuzzy_rules_t rules;
fuzzy_rules_create(&rules);
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

Or use the compressed adapter when the local rule container is named `rules`:

```c
RULE(
    "High temperature produces fast fan",
    activation,
    fan_fast
);
```

Print rules on desktop:

```c
fuzzy_rules_print(&rules);
```

Reset the container after use:

```c
fuzzy_rules_free(&rules);
```

`fuzzy_rules_free()` does not release heap memory. It resets the count because the rule array is stored directly inside `fuzzy_rules_t`.

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
FUZZY_DEFUZZ_MOM    mean of sampled maximum positions
FUZZY_DEFUZZ_SOM    smallest sampled maximum position
FUZZY_DEFUZZ_LOM    largest sampled maximum position
```

Select implication and aggregation independently:

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

The compatibility wrapper remains available:

```c
float output = fuzzy_rules_cog(
    &rules,
    0.0f,
    100.0f,
    1.0f
);
```

The `step` controls sampling resolution. A smaller step evaluates more points and usually gives a finer approximation at increased execution cost.

## Desktop visualization

### Membership plots

```c
PLOT(
    "svg/strength",
    "Paint Strength Membership Functions",
    100.0f,
    1.0f,
    SERIES(strength_little, "#ef4444"),
    SERIES(strength_fair, "#22c55e")
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
    "svg/selected_cog",
    "Selected Mamdani Output",
    cog,
    0.0f,
    100.0f,
    1.0f
);
```

### N-dimensional controller sweeps

```c
return FUZZY_COG_SWEEP(
    "greenhouse/greenhouse_cog_sweep",
    "Greenhouse Watering-Time COG Sweep",
    evaluate_time_sweep,
    0.1f,
    FUZZY_SWEEP_DIMENSION("Temperature", 0.0f, 30.0f, 1.0f),
    FUZZY_SWEEP_DIMENSION("Humidity", 0.0f, 30.0f, 1.0f)
);
```

A sweep writes CSV and SVG from the same calculated values. The CSV is not reopened or parsed, and the controller is not reevaluated for the SVG.

Higher-dimensional SVG heatmaps use the first two dimensions as visible axes. Remaining dimensions receive interactive sliders, with continuous interpolation between precomputed samples.

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

### Compressed braking controller

`braking.c` demonstrates the compact adapters in a complete controller:

- `FUZZY_VAR(...)`
- `SAND(...)`, `SOR(...)`, `AAND(...)`, `AOR(...)`, `BAND(...)`, and `BOR(...)`
- `RULE(...)`
- `SERIES(...)`
- `PLOT(...)`
- Shared desktop and embedded source structure
- Reduced 8051 compilation

```sh
make run-braking
make braking-8051
```

Use `make help` if the local Makefile exposes the braking firmware through a combined embedded target rather than `braking-8051`.

### Shared desktop and 8051 controller

`controller_8051.c` builds as both:

- `sim-8051-app` with GCC and `-DSIMULATION`
- `controller_8051.ihx` and `controller_8051.hex` with SDCC

```sh
make run-sim-8051
make embedded
```

## Build system

The build workflow is implemented directly in the `Makefile`. There is no separate Bash build script.

The Makefile performs:

- Optional `ccache` detection
- Optional `mold` detection
- GCC desktop builds
- Desktop example execution
- SDCC firmware compilation
- Intel HEX packing
- uCsim command discovery
- 8051 host-branch testing
- Optional SVG-to-PNG and SVG-to-PDF conversion
- Dependency checking and apt-based installation
- Desktop and embedded cleanup

Make recipes still use normal POSIX shell commands such as `mkdir`, `rm`, `find`, loops, and conditionals. This is standard Make recipe execution and does not require a repository-owned `.sh` script.

## Quick start

### Check dependencies

```sh
make check-dependencies
```

### Install dependencies on Debian, Ubuntu, or WSL

```sh
make install-dependencies
```

### Build everything

```sh
make
```

### Build only desktop programs

```sh
make desktop
```

### Build only embedded firmware

```sh
make embedded
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
    Build all desktop executables.

make embedded
make build-8051
    Build the SDCC MCS-51 firmware and pack Intel HEX output.

make test
    Run the FUZZY_8051 host test and build the firmware.

make test-8051
    Compile and run the desktop host test for the FUZZY_8051 branch.
    Also inspect preprocessed output for forbidden desktop-only calls.

make run-strength
    Build and run the paint-strength example.

make run-greenhouse
    Build and run the greenhouse example.

make run-demo
    Build and run the complete API demonstration.

make run-braking
    Build and run the compressed-syntax braking example.

make braking-8051
    Build the compressed braking example for the 8051 target when
    exposed as a dedicated Make target.

make run-sim-8051
    Build controller_8051.c with -DSIMULATION and run it from
    sim-8051/desktop/.

make simulate-8051
    Build the firmware and load its IHX image into uCsim.

make debug-8051
    Prepare the source and compatibility simulator name, then launch SDCDB.

make check-dependencies
    Report required and optional tools.

make install-dependencies
    Install apt-based build, conversion, and simulation dependencies.

make png
make pdf
    Convert all generated SVG groups.

make clean
    Remove generated desktop and embedded artifacts.

make clean-desktop
    Remove desktop executables, tests, SVG, PNG, PDF, and CSV output.

make clean-embedded
    Remove generated files from sim-8051/embedded/.
```

## Output directories

```text
svg/
    Paint-strength SVG, CSV, PNG, and PDF output.

greenhouse/
    Greenhouse SVG, CSV, PNG, and PDF output.

demo-all/
    Complete API demonstration output.

sim-8051/desktop/
    Desktop controller CSV, SVG, PNG, and PDF output.

sim-8051/embedded/
    SDCC firmware and analysis output.
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

SDCC's MCS-51 backend produces Intel HEX firmware rather than a conventional desktop executable.

## 8051 and 8052 support

The embedded path uses `FUZZY_8051`, excludes desktop I/O and plotting, and retains the reduced fuzzy-logic runtime.

The current firmware command is equivalent to:

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
make run-sim-8051
make png
make pdf
```

Converted files are stored beside their source SVG files.

## Opening generated plots

SVG files can be opened in Firefox, Chromium, Chrome, Edge, Inkscape, VS Code, or another SVG-compatible application.

From WSL:

```sh
explorer.exe "$(wslpath -w "$PWD/demo-all/sampled_interpolation.svg")"
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
- COG, MOM, SOM, and LOM defuzzification
- Native SVG plotting
- N-dimensional sampled-membership interpolation
- N-dimensional controller and interpolation sweeps
- Interactive higher-dimensional SVG slices
- Automatic per-dimension interpolation slice plots
- Shared desktop and embedded controller source
- Compressed syntax in `braking.c`
- SDCC IHX and HEX generation
- uCsim port-level verification

The API remains experimental and may change as the project develops.

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
- Exact floating-point equality is used when collecting sampled maxima.
- N-dimensional sweep memory grows with the product of every dimension's sample count.
- Higher-dimensional SVGs embed calculated output data and JavaScript.
- Scattered-point interpolation currently uses inverse squared Euclidean-distance weighting without automatic dimension normalization.
- Dimensions with very different physical scales can dominate interpolation distance unless the application normalizes them or chooses points carefully.
- Interpolation slices hold non-varying dimensions at their midpoint.
- Plotting writes directly to files and is not hardened against every malformed input.
- The 8051 backend intentionally excludes several desktop membership shapes.
- Floating-point 8051 firmware is code-heavy, stack-heavy, and slow compared with a fixed-point implementation.
- `--stack-loc` is deprecated by current SDCC versions.
- SDCDB behavior varies across distributions.
- The embedded examples have not undergone timing certification, hardware-in-the-loop validation, long-duration stack analysis, security auditing, or formal verification.

Use the project for learning, experiments, assignments, prototypes, and controlled systems where the code can be reviewed and tested.

## Planned work

The project intentionally keeps parsing, model storage, and heavy data tooling outside the core inference path unless a feature can remain small and inspectable.

### Core numerical work

- Max-min fuzzy relation composition
- Max-product fuzzy relation composition
- Cartesian fuzzy relation helpers
- Generic batch evaluation over arbitrary input rows
- Reference numerical tests against established implementations
- Desktop-versus-8051 fixed-vector regression tests
- Better tolerance handling for sampled maxima
- Optional normalized-distance interpolation
- Compile-time feature selection

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

Every generated or suggested component remains ordinary C or Make code that can be read, tested, modified, profiled, and replaced.

## Joke

Even this README is AI generated because I reaaaaaaalllllly could not be bothered to type English essays here.

You are software engineers. You probably know more than my attempt at low-level development, so if something is wrong, report it and I can steal your better idea `(❁´◡`❁)`.

Thanks for trying it out, and support the noble cause of screwing with Python users.

## Contributing

Issues, bug reports, test cases, fixes, documentation improvements, embedded ports, simulator notes, and alternative implementations are welcome.

Before submitting a change:

1. Run `make`.
2. Run the included desktop examples.
3. Run the compressed `braking.c` example.
4. Confirm that expected SVG and CSV files are generated.
5. Run `make test-8051`.
6. Build the firmware with `make embedded`.
7. Confirm that `braking.c` still compiles through the intended 8051 path.
8. Review generated `.mem`, `.map`, and `.lst` reports.
9. Run the IHX image through `make simulate-8051` when modifying the embedded path.
10. Clearly describe API, numerical, stack, memory, or firmware-behavior changes.

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

And sometimes the embedded system can be:

```c
#define FUZZY_8051
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

No Python environment. No MATLAB toolbox. No plotting framework. No repository-owned Bash build script.

Just C, Make, numerical output, native SVG graphs on desktop, and inspectable firmware artifacts for constrained targets.
