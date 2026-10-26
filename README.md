# fuzzy.h

A lightweight, single-header fuzzy-logic library written in C.

`fuzzy.h` provides membership functions, linguistic hedges, fuzzy operators, dynamic Mamdani rule storage, output aggregation, and sampled center-of-gravity defuzzification without requiring Python, MATLAB, external runtimes, or dependency-heavy frameworks.

The entire implementation is readable, editable, and contained in one header.

> Built partly to learn fuzzy logic, partly to test AI-assisted low-level development, and partly to annoy Python users.

## Why?

Many fuzzy-logic examples immediately reach for Python libraries or MATLAB toolboxes. Those tools are useful, but they can hide the actual calculations behind frameworks, objects, and plotting environments.

This project takes the opposite approach:

- Plain C
- One header
- No external runtime
- No Python environment
- No MATLAB toolbox
- No package manager
- User-defined membership functions
- Direct access to every calculation
- Suitable for small systems and embedded experimentation

The objective is not to replace mature numerical computing platforms. The objective is to make fuzzy-logic execution small, inspectable, modifiable, and easy to integrate into an ordinary C project.

## Current features

- Single-header implementation
- Variadic fuzzy AND using minimum
- Variadic fuzzy OR using maximum
- Linear rising and falling ramps
- Generic membership-function dispatcher
- Linguistic hedge support
- Dynamic Mamdani rule storage
- Automatic rule-array resizing
- Mamdani output clipping
- Maximum output aggregation
- Sampled center-of-gravity defuzzification
- Named rule printing
- Debugging utilities
- No dependencies beyond the C standard library and `libm`

## Supported membership functions

The generic `fuzzy_function()` wrapper currently supports:

- `ramp`
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
