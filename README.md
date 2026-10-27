# fuzzy.h

A lightweight, single-header fuzzy-logic library written in C.

`fuzzy.h` provides membership functions, linguistic hedges, fuzzy operators, dynamic Mamdani rule storage, output aggregation, sampled center-of-gravity defuzzification, COG visualization, and optional dependency-free SVG plotting.

The fuzzy engine and SVG generator require no Python environment, MATLAB toolbox, plotting framework, external runtime, or dependency-heavy package chain. PNG and PDF conversion are available as optional Makefile conveniences through an external SVG converter.

The complete fuzzy-logic implementation is readable, editable, and contained in one header.

> Built partly to learn fuzzy logic, partly to explore AI-assisted low-level development, and partly to annoy Python users.

## Contents

- [Why?](#why)
- [Current features](#current-features)
- [Supported membership functions](#supported-membership-functions)
- [Single-header setup](#single-header-setup)
- [Linguistic hedges](#linguistic-hedges)
- [Fuzzy operators](#fuzzy-operators)
- [Dynamic Mamdani rule API](#dynamic-mamdani-rule-api)
- [Complete rule example](#complete-rule-example)
- [Center-of-gravity defuzzification](#center-of-gravity-defuzzification)
- [COG visualization](#cog-visualization)
- [Optional SVG plotting](#optional-svg-plotting)
- [Built-in demonstration](#built-in-demonstration)
- [Included examples](#included-examples)
- [Building](#building)
- [Command help](#command-help)
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
- No external runtime
- No Python environment
- No MATLAB toolbox
- No package manager for the core library
- No external plotting library for SVG generation
- User-defined membership functions
- Direct access to every calculation
- Optional SVG graph generation
- Suitable for small systems and embedded experimentation

The objective is not to replace mature numerical-computing platforms. The objective is to make fuzzy-logic execution small, inspectable, modifiable, and easy to integrate into an ordinary C project.

The numerical fuzzy system works without plotting. SVG generation is an optional API for visualizing membership functions and aggregated Mamdani outputs.

## Current features

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
- Hedge application to all supported shapes
- Dynamic Mamdani rule storage
- Automatic rule-array resizing
- Named rule registration and printing
- Mamdani output clipping
- Maximum output aggregation
- Sampled center-of-gravity defuzzification
- Multi-function SVG plotting
- Automatic graph axes and grid lines
- Colored curves and legends
- XML-safe graph titles and labels
- Aggregated Mamdani output plotting
- COG marker and calculated-value label
- Built-in SVG demonstration mode
- Paint-strength fuzzy-system example
- Greenhouse watering-time example
- Optional SVG-to-PNG conversion
- Optional SVG-to-PDF conversion
- Makefile automation for building, running, converting, and cleaning
- No core dependencies beyond the C standard library and `libm`

## Supported membership functions

The generic `fuzzy_function()` dispatcher currently supports:

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

The arguments after the hedge depend on the selected membership-function shape.

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

Example:

```c
static float temperature_medium(float value)
{
    return fuzzy_function(
        "triangle",
        value,
        hedges.none,
        20.0,
        35.0,
        65.0
    );
}
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

Example:

```c
static float strength_fair(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        hedges.none,
        20.0,
        40.0,
        65.0,
        80.0
    );
}
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

`FUZZY_IMPLEMENTATION` must only be defined in one translation unit for each executable.

## Linguistic hedges

Hedges are represented as user-configurable exponents:

```c
static const hedges_t hedges = {
    .none      = 1.0f,
    .very      = 2.0f,
    .extremely = 3.0f,
    .somewhat  = 0.5f,
    .slightly  = 0.75f
};
```

The library applies a hedge using:

```text
hedged membership = membership ^ hedge
```

General behavior:

```text
hedge = 1.0    membership remains unchanged
hedge > 1.0    membership becomes more restrictive
hedge < 1.0    membership becomes less restrictive
```

Example:

```c
static float temperature_very_high(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.very,
        40.0,
        85.0,
        true
    );
}
```

The hedge values are intentionally editable. Users may change the exponents or extend `hedges_t` to match the linguistic interpretation required by a particular fuzzy system.

## Fuzzy operators

### AND

`fuzzy_and()` returns the minimum of all supplied membership values:

```c
float result = fuzzy_and(
    3,
    membership_a,
    membership_b,
    membership_c
);
```

### OR

`fuzzy_or()` returns the maximum of all supplied membership values:

```c
float result = fuzzy_or(
    3,
    membership_a,
    membership_b,
    membership_c
);
```

The first argument must match the number of membership values supplied:

```c
fuzzy_and(2, a, b);
fuzzy_or(3, a, b, c);
```

## Dynamic Mamdani rule API

Each rule stores:

- A printable rule name
- Its calculated activation value
- Its corresponding output membership function

Create a dynamic rule collection:

```c
fuzzy_rules_t rules = fuzzy_rules_create();
```

Add a rule using the output function name automatically:

```c
FUZZY_RULE_ADD(
    &rules,
    rule1,
    strength_little
);
```

Or provide a custom display name:

```c
FUZZY_RULE_ADD_NAMED(
    &rules,
    "Strength: Little",
    rule1,
    strength_little
);
```

Print the registered rules:

```c
fuzzy_rules_print(&rules);
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

Release the internal dynamic array:

```c
fuzzy_rules_free(&rules);
```

## Complete rule example

```c
static float evaluate_strength(
    float mixture_content,
    float temperature
)
{
    float rule1 = fuzzy_and(
        2,
        mixture_content_small(mixture_content),
        temperature_low(temperature)
    );

    float rule2 = fuzzy_and(
        2,
        mixture_content_huge(mixture_content),
        temperature_medium(temperature)
    );

    float rule3 = fuzzy_or(
        2,
        mixture_content_huge(mixture_content),
        temperature_high(temperature)
    );

    fuzzy_rules_t rules = fuzzy_rules_create();

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

    fuzzy_rules_print(&rules);

    float result = fuzzy_rules_cog(
        &rules,
        30.0f,
        100.0f,
        1.0f
    );

    fuzzy_rules_free(&rules);

    return result;
}
```

## Center-of-gravity defuzzification

For every sampled output value, the library:

1. Evaluates each rule's output membership function.
2. Clips the membership using the rule activation value.
3. Aggregates all clipped outputs using maximum.
4. Adds the output position and aggregated membership to the weighted sum.
5. Returns the sampled center of gravity.

The calculation is:

```text
      sum(value * aggregated membership)
COG = ----------------------------------
          sum(aggregated membership)
```

The `step` argument controls the output sampling resolution:

```c
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 10.0f);
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 1.0f);
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 0.1f);
```

A smaller step provides a finer approximation but performs more membership-function evaluations.

The lower and upper bounds must cover the complete output universe. Incorrect bounds produce the centroid of a truncated output region.

## COG visualization

The library can generate an SVG containing the aggregated Mamdani output and the calculated center of gravity:

```c
float result = fuzzy_rules_cog(
    &rules,
    0.0f,
    60.0f,
    1.0f
);

if (!fuzzy_rules_plot_cog(
    &rules,
    "greenhouse-svg/cog",
    "Watering-Time COG Defuzzification",
    result,
    0.0f,
    60.0f,
    1.0f
)) {
    fprintf(stderr, "Failed to generate COG plot.\n");
}
```

The graph includes:

- The clipped and aggregated Mamdani output
- The complete output universe
- A vertical COG marker
- The calculated crisp output value
- Axes, grid lines, title, and legend

The rule collection must remain valid while the COG graph is generated. Call `fuzzy_rules_free()` only after plotting.

## Optional SVG plotting

Plotting is optional. Applications that only need numerical output do not need to call any plotting function.

```c
float output = evaluate_strength(
    mixture_content,
    temperature
);

printf("Output: %.5f\n", output);
```

When visualization is useful, `fuzzy.h` can generate SVG graphs using standard C file operations.

The SVG plotter supports:

- Multiple membership functions per graph
- Automatic input-axis scaling
- Membership axis from `0.0` to `1.0`
- Grid lines and numeric tick labels
- Graph titles and axis labels
- Colored membership curves
- Automatic legends
- XML-safe graph titles and labels
- Aggregated Mamdani output plotting
- COG marker and calculated-value label

No GUI, SVG, XML, plotting, or image library is required for SVG generation.

### Plot several functions at once

```c
if (!FUZZY_PLOT(
    "strength",
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

This creates `strength.svg`.

### Automatic legend names

```c
FUZZY_PLOT_FUNCTION(
    strength_little,
    "#ef4444"
)
```

### Custom legend names

```c
FUZZY_PLOT_FUNCTION_NAMED(
    "Little",
    "#ef4444",
    strength_little
)
```

## Built-in demonstration

The header includes an optional demonstration mode that generates SVG examples for:

```text
ramp
triangle
trapezoid
smf
zmf
gauss
bell
sigmoid
trapezoid hedges
```

The hedge comparison includes normal, very, extremely, somewhat, and slightly.

Enable the built-in demo with:

```c
#define FUZZY_IMPLEMENTATION
#define FUZZY_DEMO
#include "fuzzy.h"

int main(void)
{
    return fuzzy_demo() ? 0 : 1;
}
```

## Included examples

### Paint-strength system

`strength.c` demonstrates:

- Mixture content as an input
- Temperature as an input
- Paint strength as the output
- Dynamic rule registration
- Sampled COG defuzzification
- Membership-function SVG plots
- Aggregated-output and COG visualization

Run it with:

```bash
make run-strength
```

### Greenhouse watering-time system

`greenhouse.c` demonstrates:

- Temperature membership functions
- Humidity membership functions
- Watering-time output functions
- Triangular and trapezoidal shapes
- Mamdani rule aggregation
- Watering-time COG calculation
- Membership-function and COG plots

Run it with:

```bash
make run-greenhouse
```

### Built-in shape demonstration

`fuzzy.c` enables `FUZZY_DEMO` and generates the built-in shape graphs.

Run it with:

```bash
make run-demo
```

## Building

The project is primarily developed and tested on Linux. Other platforms may work because the fuzzy engine mainly uses standard C facilities, but Linux is currently the preferred development environment.

The library uses functions from `libm`, including `powf()`, `expf()`, `fabsf()`, and `ceilf()`.

Build directly with GCC:

```bash
gcc -O3 -Wall -Wextra -Wpedantic \
    strength.c -lm -o fuzzy
```

The supplied Makefile builds three executables:

```text
fuzzy         Paint-strength example
greenhouse    Greenhouse watering-time example
fuzzy-demo    Built-in membership-function demonstration
```

Build all executables:

```bash
make
```

Run each example:

```bash
make run-strength
make run-greenhouse
make run-demo
```

Generated plots are placed in separate directories:

```text
svg/               Paint-strength plots
greenhouse-svg/    Greenhouse plots
demo-svg/          Built-in demonstrations
```

Remove generated executables and plot files:

```bash
make clean
```

The supplied Makefile uses `ccache` and `mold` for faster development builds. These are conveniences, not requirements. Makefile recipe lines must begin with a real tab.

## Command help

Display all available Makefile commands:

```bash
make help
```

Common commands:

```text
make                  Build all executables

make run-strength     Run the paint-strength example
make run-greenhouse   Run the greenhouse example
make run-demo         Run the built-in shape demo

make png              Convert all generated SVG files to PNG
make png-strength     Convert paint-strength SVG files to PNG
make png-greenhouse   Convert greenhouse SVG files to PNG
make png-demo         Convert demo SVG files to PNG

make pdf              Convert all generated SVG files to PDF
make pdf-strength     Convert paint-strength SVG files to PDF
make pdf-greenhouse   Convert greenhouse SVG files to PDF
make pdf-demo         Convert demo SVG files to PDF

make check-converter  Check for rsvg-convert
make install-converter
                      Install librsvg2-bin on Debian/Ubuntu

make clean            Remove executables and generated plots
```

## Optional PNG and PDF conversion

`fuzzy.h` generates SVG files natively. Numerical fuzzy evaluation and SVG plotting do not depend on an external converter.

Some native image viewers do not display SVG files directly. For convenience, the Makefile can optionally use `rsvg-convert` to create PNG and PDF copies.

Check converter availability:

```bash
make check-converter
```

Install it on Debian or Ubuntu:

```bash
make install-converter
```

This runs:

```bash
sudo apt install librsvg2-bin
```

The user must authorize and complete the system package installation. The project does not silently install system software.

Generate the SVG files first, then convert them:

```bash
make run-strength
make run-greenhouse
make run-demo
make png
make pdf
```

Convert only one group:

```bash
make png-strength
make png-greenhouse
make png-demo

make pdf-strength
make pdf-greenhouse
make pdf-demo
```

Converted files are stored beside the original SVG files:

```text
svg/strength.svg
svg/strength.png
svg/strength.pdf

greenhouse-svg/cog.svg
greenhouse-svg/cog.png
greenhouse-svg/cog.pdf

demo-svg/trapezoid.svg
demo-svg/trapezoid.png
demo-svg/trapezoid.pdf
```

The conversion targets are quality-of-life shortcuts only. Users may modify the Makefile, replace `rsvg-convert`, or use any compatible SVG conversion tool.

## Opening generated plots

SVG files can be opened in Firefox, Chromium, Chrome, Edge, Inkscape, VS Code, or another SVG-compatible application.

From WSL:

```bash
explorer.exe "$(wslpath -w "$PWD/greenhouse-svg/cog.svg")"
```

Use the optional PNG conversion targets if the preferred native image viewer does not display SVG files.

## Project flow

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
Dynamic rule collection
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

Optional visualization:

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

## Project status

The core fuzzy-logic execution and SVG visualization paths are functional. The API remains experimental and may change as the project develops.

## Safety and limitations

This is a learning-focused side project, not a production-hardened or safety-certified fuzzy-control framework.

The project is developed by an Electrical Engineering student exploring fuzzy logic, C programming, embedded-oriented design, visualization, and AI-assisted development.

Important limitations:

- The string-based membership dispatcher uses variadic arguments.
- Variadic calls are not type-safe.
- A wrong shape name or incorrect argument list can produce invalid behavior.
- Arguments must be supplied in the exact order expected by each shape.
- Counts supplied to `fuzzy_and()` and `fuzzy_or()` must match the supplied values.
- The plotting API writes directly to files and is not hardened against every malformed input.
- Dynamic rules use heap allocation through `realloc()`.
- COG uses sampled numerical approximation.
- COG bounds must cover the complete output universe.
- The library has not undergone security auditing or formal verification.

Use the project for learning, experimentation, assignments, prototypes, and controlled systems where the code can be reviewed and tested.

## Planned work

### Visualization and desktop tooling

- Interactive graphical interface
- Live input adjustment
- Live membership-function updates
- Rule activation visualization
- Configurable graph dimensions and axis labels
- Additional plot themes and formats

### Fuzzy engine

- Additional defuzzification methods
- Additional membership-function shapes
- More input validation
- Cleaner diagnostics
- Typed alternatives to the variadic API
- Expanded automated testing
- Numerical comparison against reference implementations

### Embedded and microcontroller support

A future objective is a reduced fuzzy core that does not require a hosted `libc` or full `libm` environment.

Planned embedded work includes:

- Compile-time feature selection
- Plotting removal for firmware builds
- Static-capacity rule storage
- No mandatory `realloc()`
- No mandatory file I/O
- Replaceable allocation functions
- Fixed-point membership calculations
- Lookup tables or approximations for expensive math operations
- Reduced floating-point dependence
- Software-in-the-loop testing
- Hardware-in-the-loop validation
- ESP-class microcontroller support
- Investigation of constrained 8-bit targets, including 8051-class systems

The current version is a hosted C implementation and still uses `stdio`, heap allocation, floating-point math, `libc`, and `libm`. Supporting highly constrained systems will require separating the numerical core from plotting, file handling, and dynamic allocation.

Intended development path:

```text
Linux simulation and testing
    |
    v
Software-in-the-loop validation
    |
    v
ESP firmware
    |
    v
Hardware-in-the-loop testing
    |
    v
Reduced freestanding fuzzy core
    |
    v
Constrained 8-bit targets
```

## AI-assisted development

This project was built with AI-assisted iteration, debugging, API refactoring, and testing.

The goal is not to hide that fact. The project is also an experiment in whether AI-assisted development can contribute to low-level, inspectable software instead of only generating scripts around large frameworks.

Every generated or suggested component remains ordinary C that can be read, tested, modified, profiled, and replaced by the user.

# Joke
Even this README is AI generated cuz I reaaaaaaalllllly couldnt be bothered to type english essays here!

You guys are SWE know more than my attempt at low-level so any complaints do inform so I can take your ideas(❁´◡`❁)

But thanks again for trying it out, and support to screw python!

## Contributing

The project is experimental and the API may change.

Issues, bug reports, test cases, fixes, documentation improvements, embedded ports, and alternative implementations are welcome.

Before submitting a change:

1. Build all targets.
2. Run the included examples.
3. Confirm that the expected SVG files are generated.
4. Compile with the warning flags supplied by the Makefile.
5. Clearly describe any API or numerical-behavior changes.

The implementation is intentionally visible and editable. Users are free to study the code, adapt it to their systems, replace components, or propose cleaner implementations, subject to the repository license.

## License

See the repository's `LICENSE` file for the terms under which this project may be copied, modified, and distributed.

A permissive license such as MIT is a practical fit if the intended usage is to copy `fuzzy.h` directly into other projects.

## Philosophy

Fuzzy logic and membership-function visualization do not inherently require a notebook, interpreter, virtual environment, hundreds of transitive dependencies, or proprietary software.

Sometimes the complete hosted fuzzy system can just be:

```c
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

No Python environment. No MATLAB toolbox. No plotting framework.

Just C, `libm`, numerical output, and native SVG graphs.

PNG and PDF copies are optional conveniences. Users may convert SVG files manually, use their preferred conversion software, or use the Makefile shortcuts supplied with the project.

The longer-term objective is to reduce the core further so the same fuzzy-system logic can move from Linux simulations and test harnesses into ESP-class systems and, eventually, carefully configured 8-bit microcontroller targets.
