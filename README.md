# fuzzy.h

A lightweight, single-header fuzzy-logic library written in C.

`fuzzy.h` provides membership functions, linguistic hedges, fuzzy operators, dynamic Mamdani rule storage, output aggregation, sampled center-of-gravity defuzzification, and optional dependency-free SVG plotting.

No Python environment, MATLAB toolbox, external runtime, plotting framework, or dependency-heavy package chain is required.

The complete implementation is readable, editable, and contained in one header.

> Built partly to learn fuzzy logic, partly to explore AI-assisted low-level development, and partly to annoy Python users.

## Why?

Many fuzzy-logic examples immediately reach for Python libraries or MATLAB toolboxes. Those tools are useful, but they can hide the actual calculations behind frameworks, objects, plotting environments, package managers, and large dependency chains.

This project takes the opposite approach:

- Plain C
- One header
- No external runtime
- No Python environment
- No MATLAB toolbox
- No package manager
- No external plotting library
- User-defined membership functions
- Direct access to every calculation
- Optional SVG graph generation
- Suitable for small systems and embedded experimentation

The objective is not to replace mature numerical-computing platforms. The objective is to make fuzzy-logic execution small, inspectable, modifiable, and easy to integrate into an ordinary C project.

The numerical fuzzy system works without plotting. SVG generation is an optional API for visualizing membership functions.

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
- Optional multi-function SVG plotting
- Automatic graph axes and grid lines
- Colored curves and legends
- Automatic SVG filename generation
- XML-safe graph titles and labels
- Built-in SVG demonstration mode
- No dependencies beyond the C standard library and `libm`

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

For example:

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

Hedges can be applied to ramps, triangles, trapezoids, Gaussian functions, bell functions, sigmoids, and the other supported shapes.

The hedge values are intentionally editable. Users may change the exponents or extend `hedges_t` to fit the linguistic interpretation required by a particular fuzzy system.

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

The internal rule array automatically allocates and expands as rules are added.

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
      Σ(value × aggregated membership)
COG = --------------------------------
          Σ(aggregated membership)
```

The `step` argument controls the output sampling resolution:

```c
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 10.0f);
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 1.0f);
fuzzy_rules_cog(&rules, 0.0f, 100.0f, 0.1f);
```

A smaller step provides a finer approximation but performs more membership-function evaluations.

## Optional SVG plotting

Plotting is optional. The fuzzy calculations continue to work normally without generating any graph.

The core system can simply print numerical results:

```c
float output = evaluate_strength(
    mixture_content,
    temperature
);

printf("Output: %.5f\n", output);
```

When visualization is useful, `fuzzy.h` can generate dependency-free SVG graphs using standard C file operations.

The plotter supports:

- Multiple membership functions per graph
- Automatic input-axis scaling
- Membership axis from `0.0` to `1.0`
- Grid lines
- Numeric tick labels
- Graph titles
- Axis labels
- Colored membership curves
- Automatic legends
- XML-safe graph titles and labels
- SVG output viewable in a browser

No GUI, SVG, XML, plotting, or image library is required.

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

This creates:

```text
strength.svg
```

### Automatic legend names

The shorter macro uses the C function name as the legend label:

```c
FUZZY_PLOT_FUNCTION(
    strength_little,
    "#ef4444"
)
```

### Custom legend names

Use the named form for a cleaner label:

```c
FUZZY_PLOT_FUNCTION_NAMED(
    "Little",
    "#ef4444",
    strength_little
)
```

### Visualizing hedges

The built-in demo includes multiple hedged versions of the same trapezoidal membership function.

For example:

```c
static float trapezoid_normal(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        1.0f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float trapezoid_very(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        2.0f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}

static float trapezoid_somewhat(float value)
{
    return fuzzy_function(
        "trapezoid",
        value,
        0.5f,
        10.0,
        30.0,
        70.0,
        90.0
    );
}
```

These can be displayed on one SVG graph to compare the effect of each linguistic hedge.

## Built-in demonstration

The header includes an optional demonstration mode that generates SVG examples for the supported membership functions.

The demo currently generates:

```text
ramp.svg
triangle.svg
trapezoid.svg
smf.svg
zmf.svg
gauss.svg
bell.svg
sigmoid.svg
trapezoid_hedges.svg
```

The hedge comparison includes:

- Normal
- Very
- Extremely
- Somewhat
- Slightly

To enable the built-in demo:

```c
#define FUZZY_IMPLEMENTATION
#define FUZZY_DEMO

#include "fuzzy.h"

int main(void)
{
    return fuzzy_demo() ? 0 : 1;
}
```

## Building

The project is primarily developed and tested on Linux. Other platforms may work because the library mainly uses standard C facilities, but Linux is currently the preferred environment.

The library uses math functions such as:

- `powf()`
- `expf()`
- `fabsf()`
- `ceilf()`

Link against `libm`:

```bash
gcc -O3 -Wall -Wextra -Wpedantic \
    strength.c -lm -o fuzzy
```

The provided Makefile uses `ccache` and `mold`:

```makefile
CC       := ccache gcc
CFLAGS   := -O3 -Wall -Wextra -Wpedantic
LDFLAGS  := -fuse-ld=mold -s
LDLIBS   := -lm

TARGET      := fuzzy
SOURCE      := strength.c
DEMO_TARGET := fuzzy-demo
DEMO_SOURCE := fuzzy.c

.PHONY: all run demo clean

all: $(TARGET)

$(TARGET): $(SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(TARGET) $(LDLIBS)

$(DEMO_TARGET): $(DEMO_SOURCE) fuzzy.h
	$(CC) $(CFLAGS) $(DEMO_SOURCE) $(LDFLAGS) -o $(DEMO_TARGET) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

clean:
	rm -f $(TARGET) $(DEMO_TARGET) svg/*.svg
```

Makefile recipe lines must begin with a real tab.

### Build the example fuzzy system

```bash
make
```

### Build and run the example

```bash
make run
```

### Build and run the SVG demonstration

```bash
make demo
```

### Remove generated executables and SVG plots

```bash
make clean
```

`ccache` and `mold` are optional. A normal GCC build is sufficient:

```bash
gcc -O3 -Wall -Wextra -Wpedantic \
    fuzzy.c -lm -o fuzzy-demo
```

## Opening generated plots

Generated SVG files can be opened in Firefox, Chromium, Chrome, Edge, Inkscape, or another SVG-compatible application.

From WSL:

```bash
explorer.exe "$(wslpath -w "$PWD/svg/trapezoid_hedges.svg")"
```

Plot generation is separate from fuzzy evaluation. Applications that only need numerical output do not need to call any plotting function.

## Example project flow

```text
Input values
    ↓
Membership functions
    ↓
Fuzzification
    ↓
AND / OR rule evaluation
    ↓
Dynamic rule collection
    ↓
Mamdani clipping
    ↓
Maximum aggregation
    ↓
COG defuzzification
    ↓
Crisp numerical output
```

Optional visualization:

```text
Membership functions
    ↓
SVG sampling
    ↓
Axes, labels, curves, and legends
    ↓
Browser-readable graph
```

## Project status

The core fuzzy-logic execution and SVG visualization paths are functional.

Current capabilities include:

- Defining input and output membership functions
- Applying configurable linguistic hedges
- Evaluating variable-length AND and OR expressions
- Building dynamically sized Mamdani rule collections
- Aggregating clipped output membership functions
- Producing crisp outputs using sampled COG
- Plotting one or more membership functions into SVG files
- Generating built-in demonstration graphs

The API remains experimental and may change as the project develops.

## Safety and limitations

This is a learning-focused side project, not a production-hardened fuzzy-control framework.

The project is currently developed by an Electrical Engineering student exploring fuzzy logic, C programming, embedded-oriented design, visualization, and AI-assisted development.

Important limitations:

- The string-based membership dispatcher uses variadic arguments.
- Variadic calls are not type-safe.
- A wrong shape name or incorrect argument list can produce invalid behavior.
- The caller must provide arguments in the exact order expected by each shape.
- The caller must ensure the count supplied to `fuzzy_and()` and `fuzzy_or()` matches the number of arguments.
- The plotting API writes directly to files and is not hardened against every possible malformed input.
- Dynamic rules use heap allocation through `realloc()`.
- The current COG implementation uses sampled numerical approximation.
- The library has not undergone security auditing or formal verification.

Use the project for learning, experimentation, assignments, prototypes, and controlled systems where the code can be reviewed and tested.

Do not treat the current version as safety-certified control software.

## Planned work

- Interactive graphical interface
- Live input adjustment
- Live membership-function updates
- Rule activation visualization
- Aggregated output graph
- COG marker on output graphs
- Custom graph dimensions and axis labels
- Configurable plot themes
- Additional defuzzification methods
- Additional membership-function shapes
- More input validation
- Cleaner error reporting
- Separate optional modules
- Embedded-oriented build examples
- Additional tests and validation

## AI-assisted development

This project was built with AI-assisted iteration, debugging, API refactoring, and testing.

The goal is not to hide that fact. The project is also an experiment in whether AI-assisted development can contribute to low-level, inspectable software instead of only generating scripts around large frameworks.

Every generated or suggested component remains ordinary C that can be read, tested, modified, profiled, and replaced by the user.

## Philosophy

Fuzzy logic and membership-function visualization do not inherently require a notebook, interpreter, virtual environment, hundreds of transitive dependencies, or proprietary software.

Sometimes the complete fuzzy system and graphing interface can just be:

```c
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
```

No Python environment. No MATLAB toolbox. No plotting framework.

Just C, `libm`, numerical output, and optional SVG graphs.