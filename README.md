# fuzzy.h

A lightweight, single-header fuzzy-logic library written in C.

`fuzzy.h` provides membership functions, linguistic hedges, fuzzy operators, static Mamdani rule storage, output aggregation, sampled center-of-gravity defuzzification, native SVG plotting, multidimensional COG sweeps, and a reduced 8051/8052 firmware profile.

The desktop fuzzy engine and SVG generator require no Python environment, MATLAB toolbox, plotting framework, or external runtime. PNG and PDF conversion are optional conveniences provided through `rsvg-convert`.

The complete fuzzy implementation remains readable, editable, and contained in one header.

> Built partly to learn fuzzy logic, partly to explore AI-assisted low-level development, and partly to annoy Python users.

## Contents

- [Why?](#why)
- [Current features](#current-features)
- [Supported membership functions](#supported-membership-functions)
- [Single-header setup](#single-header-setup)
- [Linguistic hedges](#linguistic-hedges)
- [Fuzzy operators](#fuzzy-operators)
- [Mamdani rule API](#mamdani-rule-api)
- [Complete rule example](#complete-rule-example)
- [Center-of-gravity defuzzification](#center-of-gravity-defuzzification)
- [COG visualization and sweeps](#cog-visualization-and-sweeps)
- [Optional SVG plotting](#optional-svg-plotting)
- [Included examples](#included-examples)
- [Build system](#build-system)
- [Quick start](#quick-start)
- [Command reference](#command-reference)
- [Output directories](#output-directories)
- [8051 and 8052 support](#8051-and-8052-support)
- [8051 firmware verification](#8051-firmware-verification)
- [Optional PNG and PDF conversion](#optional-png-and-pdf-conversion)
- [Opening generated plots](#opening-generated-plots)
- [Project flow](#project-flow)
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
- One header
- No Python environment
- No MATLAB toolbox
- No package manager for the core library
- No external plotting library for SVG generation
- User-defined membership functions
- Direct access to every calculation
- Optional SVG graph generation
- Desktop simulation and embedded experimentation
- A reduced 8051/8052 build profile

The objective is not to replace mature numerical-computing platforms. The objective is to make fuzzy-logic execution small, inspectable, modifiable, and easy to integrate into an ordinary C project.

The numerical fuzzy system works without plotting. SVG generation and COG sweeps are optional desktop APIs for visualizing membership functions and Mamdani outputs.

## Current features

### Core fuzzy engine

- Single-header implementation
- Variadic fuzzy AND using minimum
- Variadic fuzzy OR using maximum
- Linear rising and falling ramps
- Triangular membership functions
- Trapezoidal membership functions
- S-shaped membership functions
- Z-shaped membership functions
- Gaussian membership functions
- Generalized bell membership functions
- Sigmoid membership functions
- Generic membership-function dispatcher
- User-configurable linguistic hedges
- Mamdani output clipping
- Maximum output aggregation
- Sampled center-of-gravity defuzzification

### Rule system

- Compile-time rule capacity through `FUZZY_MAX_RULES`
- Static rule storage with no mandatory heap allocation
- Named rules on desktop builds
- Reduced unnamed rules on 8051 builds
- Rule activation printing on desktop builds
- Reusable rule containers

### Desktop visualization

- Multi-function SVG plotting
- Automatic graph axes and grid lines
- Colored curves and legends
- XML-safe graph titles and labels
- Aggregated Mamdani output plotting
- COG marker and calculated-value label
- N-dimensional COG sweep CSV generation
- One-dimensional sweep line graphs
- Two-dimensional sweep heatmaps
- Interactive slice controls for higher-dimensional sweeps
- Optional SVG-to-PNG conversion
- Optional SVG-to-PDF conversion

### Embedded support

- `FUZZY_8051` reduced backend
- `FUZZY_8051_MINIMAL` feature profile
- Static rule capacity
- No plotting or file I/O in firmware builds
- Integer hedge powers for constrained builds
- Direct `fuzzy_ramp()` use to avoid generic string dispatch
- SDCC build support for MCS-51 targets
- Intel HEX generation
- Assembly, listing, map, symbol, debug, and memory reports
- Desktop software-in-the-loop harness matching the 8051 controller

### Included applications

- Paint-strength fuzzy system
- Greenhouse watering-time system
- Complete API demonstration
- Desktop 8051 controller simulation
- AT89S52/8052 firmware example

## Supported membership functions

The generic desktop `fuzzy_function()` dispatcher supports:

- `ramp`
- `triangle`
- `trapezoid`
- `smf`
- `zmf`
- `gauss`
- `bell`
- `sigmoid`

Example:

```c
float result = fuzzy_function(
    "gauss",
    value,
    hedges.none,
    50.0,
    10.0
);
```

The arguments after the hedge depend on the selected shape.

### Ramp

```c
fuzzy_function(
    "ramp",
    value,
    hedge,
    lower_boundary,
    upper_boundary,
    ramp_up
);
```

Example:

```c
static float temperature_high(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        40.0,
        85.0,
        true
    );
}
```

For minimal 8051 builds, call the lightweight ramp API directly:

```c
static float temperature_high(float value)
{
    return fuzzy_ramp(
        NULL,
        30.0f,
        60.0f,
        value,
        true,
        hedges.none
    );
}
```

### Triangle

```c
fuzzy_function(
    "triangle",
    value,
    hedge,
    left,
    peak,
    right
);
```

### Trapezoid

```c
fuzzy_function(
    "trapezoid",
    value,
    hedge,
    left,
    top_left,
    top_right,
    right
);
```

### S-shaped function

```c
fuzzy_function(
    "smf",
    value,
    hedge,
    lower_boundary,
    upper_boundary
);
```

### Z-shaped function

```c
fuzzy_function(
    "zmf",
    value,
    hedge,
    lower_boundary,
    upper_boundary
);
```

### Gaussian function

```c
fuzzy_function(
    "gauss",
    value,
    hedge,
    mean,
    standard_deviation
);
```

### Generalized bell function

```c
fuzzy_function(
    "bell",
    value,
    hedge,
    width,
    slope,
    center
);
```

### Sigmoid function

```c
fuzzy_function(
    "sigmoid",
    value,
    hedge,
    slope,
    center
);
```

A positive sigmoid slope produces a rising sigmoid. A negative slope produces a falling sigmoid.

## Single-header setup

In exactly one C source file, define `FUZZY_IMPLEMENTATION` before including the header:

```c
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

Other source files should include the header normally:

```c
#include "fuzzy.h"
```

`FUZZY_IMPLEMENTATION` must only be defined in one translation unit per executable.

### 8051/8052 setup

For the reduced firmware backend:

```c
#define FUZZY_8051
#define FUZZY_8051_MINIMAL
#define FUZZY_MAX_RULES 2u

#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

For a source file that builds with both SDCC and Keil C51:

```c
#ifdef __SDCC
#include <8052.h>
#else
#include <REG51.H>
#endif
```

## Linguistic hedges

Desktop hedges use configurable floating-point exponents:

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

General behavior:

```text
hedge = 1.0   membership remains unchanged
hedge > 1.0   membership becomes more restrictive
hedge < 1.0   membership becomes less restrictive
```

The reduced 8051 backend uses integer powers:

```c
static const hedges_t hedges = {
    1u,
    2u,
    3u
};
```

Fractional hedges are unavailable in the reduced 8051 profile because roots and general exponentiation are intentionally excluded.

## Fuzzy operators

### AND

`fuzzy_and()` returns the minimum of all supplied memberships:

```c
float result = fuzzy_and(
    3,
    membership_a,
    membership_b,
    membership_c
);
```

### OR

`fuzzy_or()` returns the maximum of all supplied memberships:

```c
float result = fuzzy_or(
    3,
    membership_a,
    membership_b,
    membership_c
);
```

The first argument must match the number of supplied memberships:

```c
fuzzy_and(2, a, b);
fuzzy_or(3, a, b, c);
```

`FUZZY_8051_MINIMAL` can omit the variadic AND/OR implementations when a controller does not require them. This avoids unnecessary parameter storage and code generation on constrained toolchains.

## Mamdani rule API

Each rule stores:

- Its activation value
- Its output membership function
- An optional printable name on desktop builds

Create a rule collection:

```c
fuzzy_rules_t rules;

fuzzy_rules_create(
    &rules
);
```

Add a rule:

```c
FUZZY_RULE_ADD(
    &rules,
    rule1,
    strength_little
);
```

Or add a named desktop rule:

```c
FUZZY_RULE_ADD_NAMED(
    &rules,
    "Strength: Little",
    rule1,
    strength_little
);
```

Print registered rules on desktop builds:

```c
fuzzy_rules_print(
    &rules
);
```

Calculate the sampled center of gravity:

```c
float result = fuzzy_rules_cog(
    &rules,
    30.0f,
    100.0f,
    1.0f
);
```

Reset the reusable static container:

```c
fuzzy_rules_free(
    &rules
);
```

Rule capacity is controlled before including the implementation:

```c
#define FUZZY_MAX_RULES 10u
```

The rule API no longer depends on dynamic `realloc()` storage.

## Complete rule example

```c
static float evaluate_strength(
    float mixture_content,
    float temperature
)
{
    fuzzy_rules_t rules;
    float rule1;
    float rule2;
    float rule3;
    float result;

    rule1 = fuzzy_and(
        2,
        mixture_content_small(mixture_content),
        temperature_low(temperature)
    );

    rule2 = fuzzy_and(
        2,
        mixture_content_huge(mixture_content),
        temperature_medium(temperature)
    );

    rule3 = fuzzy_or(
        2,
        mixture_content_huge(mixture_content),
        temperature_high(temperature)
    );

    fuzzy_rules_create(
        &rules
    );

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Strength: Little",
        rule1,
        strength_little
    )) {
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Strength: Fair",
        rule2,
        strength_fair
    )) {
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD_NAMED(
        &rules,
        "Strength: Massive",
        rule3,
        strength_massive
    )) {
        fuzzy_rules_free(&rules);
        return 0.0f;
    }

    result = fuzzy_rules_cog(
        &rules,
        30.0f,
        100.0f,
        1.0f
    );

    fuzzy_rules_free(
        &rules
    );

    return result;
}
```

## Center-of-gravity defuzzification

For every sampled output value, the library:

1. Evaluates each rule's output membership function.
2. Clips the output membership using the rule activation.
3. Aggregates all clipped outputs using maximum.
4. Adds the output position and aggregated membership to the weighted sum.
5. Returns the sampled center of gravity.

```text
      sum(value * aggregated membership)
COG = ----------------------------------
          sum(aggregated membership)
```

The `step` argument controls output resolution:

```c
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 10.0f);
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 1.0f);
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 0.1f);
```

A smaller step provides a finer approximation but performs more membership evaluations. The lower and upper bounds must cover the complete output universe.

## COG visualization and sweeps

### Selected COG plot

```c
float result = fuzzy_rules_cog(
    &rules,
    0.0f,
    60.0f,
    1.0f
);

if (!fuzzy_rules_plot_cog(
    &rules,
    "greenhouse/cog",
    "Watering-Time COG Defuzzification",
    result,
    0.0f,
    60.0f,
    1.0f
)) {
    fprintf(stderr, "Failed to generate COG plot.\n");
}
```

The rule collection must remain valid until plotting finishes.

### N-dimensional sweep

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

A sweep generates both CSV and SVG output. Higher-dimensional sweeps use the first two dimensions for the heatmap and the remaining dimensions as interactive slices.

## Optional SVG plotting

Plotting is optional. Applications that only need numerical output do not need to call plotting functions.

```c
float output = evaluate_strength(
    mixture_content,
    temperature
);

printf("Output: %.5f\n", output);
```

Plot several functions at once:

```c
if (!FUZZY_PLOT(
    "svg/strength",
    "Paint Strength Membership Functions",
    0.0f,
    100.0f,
    1.0f,

    FUZZY_PLOT_FUNCTION_NAMED(
        "Little",
        "#ef4444",
        strength_little
    ),

    FUZZY_PLOT_FUNCTION_NAMED(
        "Fair",
        "#22c55e",
        strength_fair
    ),

    FUZZY_PLOT_FUNCTION_NAMED(
        "Massive",
        "#3b82f6",
        strength_massive
    )
)) {
    fprintf(stderr, "Failed to create strength.svg\n");
}
```

No external GUI, SVG, XML, plotting, or image library is required for SVG generation.

## Included examples

### Paint-strength system

`strength.c` demonstrates:

- Mixture content and temperature inputs
- Paint-strength output
- Mamdani rules
- Sampled COG defuzzification
- Membership SVGs
- COG sweep CSV and SVG

Run:

```bash
make run-strength
```

### Greenhouse watering-time system

`greenhouse.c` demonstrates:

- Temperature and humidity inputs
- Watering-time output
- Triangular and trapezoidal functions
- Mamdani aggregation
- Selected COG plotting
- Two-dimensional sweep generation

Run:

```bash
make run-greenhouse
```

### Complete API demonstration

`demo_all.c` exercises the widest practical portion of the desktop API, including all supported membership functions, hedges, nested rules, COG plotting, and a multidimensional sweep.

Run:

```bash
make run-demo
```

### Desktop 8051 simulation harness

`sim_8051.c` mirrors the embedded fan controller on the desktop and generates:

- Temperature membership SVG
- Fan-output membership SVG
- Temperature-to-fan CSV
- Temperature-to-fan SVG
- Console COG and PWM results

Run:

```bash
make run-sim-8051
```

### AT89S52/8052 firmware

`controller_8051.c` demonstrates the reduced firmware profile and generates an Intel HEX image through SDCC.

Build:

```bash
make embedded
```

## Build system

The repository intentionally separates responsibilities:

### Makefile

The Makefile is a thin command dispatcher. It does not contain compiler flags, package installation logic, directory management, conversion loops, or SDCC implementation details.

Examples:

```make
all:
	./scripts/build.sh all

embedded:
	./scripts/build.sh embedded

simulate-8051:
	./scripts/build.sh simulate-8051
```

### `scripts/build.sh`

The monolithic Bash script owns the complete end-user workflow:

- Dependency checking
- Optional dependency installation
- Directory creation
- GCC desktop builds
- Desktop example execution
- SDCC firmware compilation
- Intel HEX generation
- Assembly, debug, map, listing, symbol, and memory reports
- 8051/8052 simulation command discovery
- SVG-to-PNG conversion
- SVG-to-PDF conversion
- Cleaning generated artifacts
- Command help

This design deliberately hides build-system complexity from end users while keeping the entire workflow inspectable in one script.

## Quick start

### Install dependencies

On Debian, Ubuntu, or WSL:

```bash
make install-dependencies
```

The monolithic script installs the required build packages through `apt` when available.

### Build everything

```bash
make
```

This builds:

- All desktop executables
- The desktop 8051 simulation harness
- The SDCC 8051/8052 firmware
- Intel HEX output
- Embedded build reports

### Build only desktop programs

```bash
make desktop
```

### Build only embedded firmware

```bash
make embedded
```

### Show command help

```bash
make help
```

## Command reference

```text
make
    Build all desktop programs and embedded firmware.

make desktop
    Build all desktop executables.

make embedded
    Build the SDCC MCS-51 firmware.

make test
    Run available verification tasks and build firmware.

make run-strength
    Build and run the paint-strength example.

make run-greenhouse
    Build and run the greenhouse example.

make run-demo
    Build and run the complete API demonstration.

make run-sim-8051
    Build and run the desktop 8051 controller harness.

make simulate-8051
    Build and open the IHX firmware in uCsim.

make debug-8051
    Attempt source-level SDCDB debugging.
    This command is retained for experimentation but is not the
    recommended verification route on modern distributions.

make check-dependencies
    Report required and optional build tools.

make install-dependencies
    Install apt-based build and simulation dependencies.

make png
    Convert all generated desktop SVG files to PNG.

make pdf
    Convert all generated desktop SVG files to PDF.

make clean
    Remove all generated desktop and embedded artifacts.

make clean-desktop
    Remove only desktop artifacts.

make clean-embedded
    Remove only SDCC firmware artifacts.
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
    Desktop software-in-the-loop CSV and SVG output.

sim-8051/embedded/
    SDCC firmware and analysis output.
```

Embedded output includes files such as:

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

SDCC's MCS-51 backend produces Intel HEX firmware, not a conventional desktop ELF executable.

## 8051 and 8052 support

### Firmware profile

The embedded example uses:

```c
#define FUZZY_8051
#define FUZZY_8051_MINIMAL
#define FUZZY_MAX_RULES 2u
```

The minimal profile removes desktop-only features such as:

- SVG plotting
- CSV generation
- File I/O
- Dynamic plotting structures
- Generic string-based membership dispatch when unused
- Variadic AND/OR implementations when unused

The example uses `fuzzy_ramp()` directly and retains the same Mamdani COG structure used by desktop builds.

### Keil C51 limitation

The firmware can compile under Keil C51, but the free/evaluation toolchain is limited to 2 KB of code for compilation, linking, and debugging. The floating-point fuzzy controller exceeds that limit.

A successfully reduced Keil build reached approximately:

```text
DATA: 80 bytes
CODE: 3320 bytes
```

The AT89S52 itself has sufficient program Flash for this image, but the Keil evaluation debugger refuses programs larger than 2 KB. A full Keil licence, a smaller fixed-point backend, or SDCC is required for unrestricted firmware work.

### SDCC build

The working firmware path uses SDCC:

```bash
make embedded
```

The build script uses the MCS-51 backend, small memory model, code-size optimization, debug information, automatic stack storage, and 256-byte internal RAM configuration.

The generated `.mem` report must always be reviewed. Float-heavy calculations and `--stack-auto` can consume significant stack space.

### EdSim51 limitation

EdSim51 can load Intel HEX and partially execute the generated firmware. Input and output can be exposed through ports, for example:

```text
P2 = temperature input
P1 = rounded PWM output
P0 = execution status
```

However, the float-heavy SDCC firmware can exceed the practical internal stack model available in EdSim51. A typical failure symptom is:

```text
P0 remains 0x55
P1 remains 0x00
SP wraps to a low address
```

EdSim51 is therefore useful for small 8051 programs and basic port experiments, but it is not the preferred final verifier for this firmware.

### SDCDB limitation

SDCDB is experimental and can be unreliable with modern SDCC/uCsim packaging. Observed issues include:

- Expecting the historical `s51` executable while newer distributions provide `ucsim_51`
- Source-module parsing failures
- Rejected directory options
- Invalid source mapping
- Large amounts of runtime-environment noise
- Segmentation faults

The project may retain `make debug-8051` for experimentation, but raw IHX execution through uCsim is the recommended verification route.

## 8051 firmware verification

### Recommended simulator

Use the generated IHX with the 8052-class uCsim target:

```bash
ucsim_51 \
    -t 52 \
    -X 11.0592M \
    sim-8051/embedded/controller_8051.ihx
```

On distributions using the historical simulator name:

```bash
s51 \
    -t 52 \
    -X 11.0592M \
    sim-8051/embedded/controller_8051.ihx
```

The monolithic script detects `ucsim_51` or `s51` for:

```bash
make simulate-8051
```

### Verification firmware outputs

The verification program writes:

```text
P0 = controller status
P1 = rounded fan-speed/PWM percentage
P2 = temperature input
```

Status values:

```text
P0 = 0x55   calculation started
P0 = 0xAA   calculation completed
P0 = 0xF0   invalid input above 100
```

### Example verified result

For an input temperature of `42`:

```text
P2 = 0x2A = 42 decimal
P1 = 0x4D = 77 decimal
P0 = 0xAA = calculation complete
```

The simulated controller therefore produced:

```text
Temperature input: 42
Fuzzy fan speed:   approximately 76.67
Rounded PWM:       77%
```

### Exact uCsim verification sequence

Start the simulator:

```bash
make simulate-8051
```

At the simulator prompt:

```text
reset
step 2000000
ds 0x80 0xa0
```

Relevant 8051 SFR addresses:

```text
P0 = 0x80
P1 = 0x90
P2 = 0xA0
SP = 0x81
```

A successful dump for input `42` includes:

```text
0x80 aa ...
0x90 4d ...
0xa0 2a
```

Interpretation:

```text
P0 = 0xAA   completed
P1 = 0x4D   77% PWM
P2 = 0x2A   temperature 42
```

If execution stops at an instruction such as:

```text
SJMP 0x0D07
```

that is the intentional compiled form of the final infinite hold loop. The firmware has completed and is preserving the output ports.

### Desktop comparison

Run the software-in-the-loop harness:

```bash
make run-sim-8051
```

Compare the embedded port result against:

```text
sim-8051/desktop/sim_8051.csv
```

This provides the verification chain:

```text
Desktop GCC controller
    |
    v
Expected CSV and SVG response
    |
    v
SDCC-generated MCS-51 firmware
    |
    v
uCsim IHX execution
    |
    v
P0/P1/P2 result comparison
```

## Optional PNG and PDF conversion

`fuzzy.h` generates SVG files natively. Numerical evaluation and SVG plotting do not require an external converter.

Install the optional converter with:

```bash
make install-dependencies
```

Or install it directly on an apt-based system:

```bash
sudo apt install librsvg2-bin
```

Generate SVG files first, then convert:

```bash
make run-strength
make run-greenhouse
make run-demo
make run-sim-8051

make png
make pdf
```

Convert one output group:

```bash
make png-strength
make png-greenhouse
make png-demo
make png-sim-8051

make pdf-strength
make pdf-greenhouse
make pdf-demo
make pdf-sim-8051
```

Converted files are stored beside their original SVG files.

## Opening generated plots

SVG files can be opened in Firefox, Chromium, Chrome, Edge, Inkscape, VS Code, or another SVG-compatible application.

From WSL:

```bash
explorer.exe "$(wslpath -w "$PWD/sim-8051/desktop/sim_8051.svg")"
```

Use the optional PNG conversion targets if the preferred viewer does not display SVG files.

## Project flow

### Desktop fuzzy system

```text
Input values
    |
    v
Membership functions
    |
    v
Fuzzification
    |
    v
AND / OR rule evaluation
    |
    v
Static rule collection
    |
    v
Mamdani clipping
    |
    v
Maximum aggregation
    |
    v
COG defuzzification
    |
    v
Crisp numerical output
```

### Optional visualization

```text
Membership functions / aggregated output
    |
    v
SVG sampling
    |
    v
Axes, labels, curves, legends, and COG marker
    |
    v
SVG graph
    |
    +--> Optional PNG conversion
    +--> Optional PDF conversion
```

### Embedded verification

```text
controller_8051.c
    |
    v
SDCC MCS-51 compilation
    |
    +--> Intel IHX / HEX firmware
    +--> Assembly and listing
    +--> Map and memory reports
    |
    v
uCsim 8052 execution
    |
    v
P0 status, P1 output, P2 input
    |
    v
Compare against desktop CSV
```

## Project status

The desktop fuzzy engine, SVG plotting, COG visualization, multidimensional sweeps, software-in-the-loop 8051 harness, reduced firmware profile, SDCC build, and uCsim verification path are functional.

The API remains experimental and may change as the project develops.

## Safety and limitations

This is a learning-focused side project, not a production-hardened or safety-certified fuzzy-control framework.

Important limitations:

- The generic membership dispatcher uses variadic arguments.
- Variadic calls are not type-safe.
- A wrong shape name or incorrect argument list can produce invalid behavior.
- Parameters must be supplied in the exact order required by each shape.
- Counts supplied to `fuzzy_and()` and `fuzzy_or()` must match the supplied values.
- COG uses sampled numerical approximation.
- COG bounds must cover the complete output universe.
- The plotting API writes directly to files and is not hardened against every malformed input.
- Static rule capacity must be configured correctly with `FUZZY_MAX_RULES`.
- The floating-point 8051 backend is code-heavy and stack-heavy.
- Keil evaluation tools cannot debug the current firmware because of the 2 KB code limit.
- EdSim51 can overflow or misrepresent stack behavior for this firmware.
- SDCDB source-level debugging is experimental and unreliable on some modern systems.
- The embedded example has not undergone timing certification, hardware-in-the-loop testing, or long-duration stack analysis.
- The library has not undergone security auditing or formal verification.

Use the project for learning, experimentation, assignments, prototypes, and controlled systems where the code can be reviewed and tested.

## Planned work

### Visualization and desktop tooling

- Interactive graphical interface
- Live input adjustment
- Rule activation visualization
- Configurable graph dimensions and labels
- Additional plot themes
- Automated desktop-versus-embedded regression reports

### Fuzzy engine

- Additional defuzzification methods
- Additional membership-function shapes
- Typed alternatives to the variadic API
- Expanded automated testing
- Numerical comparison against reference implementations
- Additional compile-time feature selection

### Embedded work

- Fixed-point membership calculations
- Fixed-point COG defuzzification
- Reduced floating-point dependence
- Explicit stack-depth testing
- Smaller firmware profiles
- Timer-driven PWM output
- Sensor input examples
- Software-in-the-loop regression tests
- Hardware-in-the-loop validation
- ESP-class microcontroller support
- Additional 8051 compiler and simulator testing

Intended development path:

```text
Linux simulation and testing
    |
    v
Software-in-the-loop validation
    |
    v
SDCC MCS-51 firmware verification
    |
    v
Hardware flashing and port testing
    |
    v
Fixed-point reduced backend
    |
    v
Hardware-in-the-loop validation
```

## AI-assisted development

This project was built with AI-assisted iteration, debugging, API refactoring, documentation, and testing.

The goal is not to hide that fact. The project is also an experiment in whether AI-assisted development can contribute to low-level, inspectable software instead of only generating scripts around large frameworks.

Every generated or suggested component remains ordinary C or shell code that can be read, tested, modified, profiled, and replaced by the user.

## Joke

Even this README is AI generated because I reaaaaaaalllllly could not be bothered to type English essays here.

You are software engineers. You probably know more than my attempt at low-level development, so if something is wrong, report it and I can steal your better idea `(❁´◡`❁)`.

Thanks for trying it out, and support the noble cause of screwing with Python users.

## Contributing

The project is experimental and the API may change.

Issues, bug reports, test cases, fixes, documentation improvements, embedded ports, simulator notes, and alternative implementations are welcome.

Before submitting a change:

1. Run `make`.
2. Run the included desktop examples.
3. Confirm that the expected SVG and CSV files are generated.
4. Build the embedded firmware with `make embedded`.
5. Review the generated `.mem` report.
6. Run the IHX image through `make simulate-8051` when modifying the embedded path.
7. Clearly describe API, numerical, stack, memory, or firmware-behavior changes.

The implementation is intentionally visible and editable. Users are free to study the code, adapt it to their systems, replace components, or propose cleaner implementations, subject to the repository licence.

## License

See the repository's `LICENSE` file for the terms under which this project may be copied, modified, and distributed.

A permissive licence such as MIT is a practical fit when the intended usage is to copy `fuzzy.h` directly into other projects.

## Philosophy

Fuzzy logic and membership visualization do not inherently require a notebook, interpreter, virtual environment, hundreds of transitive dependencies, or proprietary software.

Sometimes the complete hosted fuzzy system can just be:

```c
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

And sometimes the reduced embedded system can be:

```c
#define FUZZY_8051
#define FUZZY_8051_MINIMAL
#define FUZZY_MAX_RULES 2u
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

No Python environment. No MATLAB toolbox. No plotting framework.

Just C, numerical output, native SVG graphs on desktop, and inspectable firmware artifacts for constrained targets.
