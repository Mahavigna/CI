#!/usr/bin/env bash

set -euo pipefail


# ============================================================
# Project location
# ============================================================

SCRIPT_DIRECTORY="$(
    cd "$(dirname "${BASH_SOURCE[0]}")" &&
    pwd
)"

ROOT_DIRECTORY="$(
    cd "${SCRIPT_DIRECTORY}/.." &&
    pwd
)"

cd "${ROOT_DIRECTORY}"


# ============================================================
# User-selectable action
# ============================================================

ACTION="${1:-all}"


# ============================================================
# Desktop compiler configuration
# ============================================================

CC="${CC:-gcc}"

COMMON_CFLAGS=(
    -O3
    -Wall
    -Wextra
    -Wpedantic
    -std=c11
)

COMMON_LDFLAGS=()

COMMON_LDLIBS=(
    -lm
)


# ============================================================
# Optional desktop acceleration tools
# ============================================================

if command -v ccache >/dev/null 2>&1; then
    COMPILER_COMMAND=(
        ccache
        "${CC}"
    )
else
    COMPILER_COMMAND=(
        "${CC}"
    )
fi

if command -v mold >/dev/null 2>&1; then
    COMMON_LDFLAGS+=(
        -fuse-ld=mold
    )
fi


# ============================================================
# Desktop examples
# ============================================================

STRENGTH_TARGET="fuzzy"
STRENGTH_SOURCE="strength.c"
STRENGTH_OUTPUT="svg"

GREENHOUSE_TARGET="greenhouse-app"
GREENHOUSE_SOURCE="greenhouse.c"
GREENHOUSE_OUTPUT="greenhouse"

DEMO_TARGET="fuzzy-demo"
DEMO_SOURCE="demo_all.c"
DEMO_OUTPUT="demo-all"

SIM_8051_TARGET="sim-8051-app"
SIM_8051_SOURCE="sim_8051.c"
SIM_8051_ROOT="sim-8051"
SIM_8051_OUTPUT="${SIM_8051_ROOT}/desktop"


# ============================================================
# Embedded 8051 configuration
# ============================================================

EMBEDDED_SOURCE="${EMBEDDED_SOURCE:-controller_8051.c}"
EMBEDDED_OUTPUT="${EMBEDDED_OUTPUT:-${SIM_8051_ROOT}/embedded}"
EMBEDDED_BASENAME="controller_8051"

SDCC="${SDCC:-sdcc}"
PACKIHX="${PACKIHX:-packihx}"
if [ -n "${S51:-}" ]; then
    SIMULATOR_COMMAND="${S51}"
elif command -v ucsim_51 >/dev/null 2>&1; then
    SIMULATOR_COMMAND="ucsim_51"
elif command -v s51 >/dev/null 2>&1; then
    SIMULATOR_COMMAND="s51"
else
    SIMULATOR_COMMAND=""
fi
SDCDB="${SDCDB:-sdcdb}"


# ============================================================
# Conversion tools
# ============================================================

SVG_CONVERTER="${SVG_CONVERTER:-rsvg-convert}"


# ============================================================
# Terminal helpers
# ============================================================

print_heading()
{
    printf "\n"
    printf "============================================================\n"
    printf "%s\n" "$1"
    printf "============================================================\n"
}


print_item()
{
    printf "  %s\n" "$1"
}


command_exists()
{
    command -v "$1" >/dev/null 2>&1
}


require_command()
{
    local command_name="$1"

    if ! command_exists "${command_name}"; then
        echo "Error: required command not found: ${command_name}"
        echo
        echo "Install project dependencies with:"
        echo "  make install-dependencies"
        exit 1
    fi
}


require_file()
{
    local file_path="$1"

    if [ ! -f "${file_path}" ]; then
        echo "Error: required file not found:"
        echo "  ${file_path}"
        exit 1
    fi
}


show_file_if_present()
{
    local file_path="$1"

    if [ -f "${file_path}" ]; then
        ls -lh "${file_path}"
    fi
}


# ============================================================
# Dependency management
# ============================================================

check_dependencies()
{
    local missing=0
    local command_name

    print_heading "Checking dependencies"

    for command_name in \
        gcc \
        make \
        bash \
        sdcc \
        packihx
    do
        if command_exists "${command_name}"; then
            printf "[OK]      %s\n" "${command_name}"
        else
            printf "[MISSING] %s\n" "${command_name}"
            missing=1
        fi
    done

    echo

    for command_name in \
        ccache \
        mold \
        rsvg-convert \
        sdcdb
    do
        if command_exists "${command_name}"; then
            printf "[OK]       %s\n" "${command_name}"
        else
            printf "[OPTIONAL] %s\n" "${command_name}"
        fi
    done

    echo

    if command -v ucsim_51 >/dev/null 2>&1; then
        printf "[OK]       %-14s %s\n" \
            "8051 simulator:" \
            "$(command -v ucsim_51)"
    elif command -v s51 >/dev/null 2>&1; then
        printf "[OK]       %-14s %s\n" \
            "8051 simulator:" \
            "$(command -v s51)"
    else
        printf "[OPTIONAL] %-14s %s\n" \
            "8051 simulator:" \
            "ucsim_51 or s51"
    fi


    if [ "${missing}" -ne 0 ]; then
        echo
        echo "Install required dependencies with:"
        echo "  make install-dependencies"
        return 1
    fi

    echo
    echo "Required dependencies are available."
}


install_dependencies()
{
    print_heading "Installing project dependencies"

    if ! command_exists apt-get; then
        echo "Error: automatic installation currently supports apt-based systems."
        echo
        echo "Required packages:"
        echo "  build-essential"
        echo "  gcc"
        echo "  make"
        echo "  ccache"
        echo "  mold"
        echo "  sdcc"
        echo "  sdcc-ucsim"
        echo "  librsvg2-bin"
        exit 1
    fi

    local sudo_command=()

    if [ "$(id -u)" -ne 0 ]; then
        require_command sudo
        sudo_command=(sudo)
    fi

    "${sudo_command[@]}" apt-get update

    "${sudo_command[@]}" apt-get install -y \
        build-essential \
        gcc \
        make \
        ccache \
        mold \
        sdcc \
        librsvg2-bin

    if ! command -v s51 >/dev/null 2>&1; then
        echo
        echo "Installing the 8051 simulator..."

        if apt-cache show sdcc-ucsim >/dev/null 2>&1; then
            "${sudo_command[@]}" apt-get install -y sdcc-ucsim
        elif apt-cache show ucsim >/dev/null 2>&1; then
            "${sudo_command[@]}" apt-get install -y ucsim
        else
            echo "Error: neither sdcc-ucsim nor ucsim is available."
            echo "Check that the Ubuntu Universe repository is enabled."
            exit 1
        fi
    fi

    echo
    echo "Dependency installation complete."

    check_dependencies
}


# ============================================================
# Directory creation
# ============================================================

create_directories()
{
    mkdir -p \
        "${STRENGTH_OUTPUT}" \
        "${GREENHOUSE_OUTPUT}" \
        "${DEMO_OUTPUT}" \
        "${SIM_8051_OUTPUT}" \
        "${EMBEDDED_OUTPUT}"
}


# ============================================================
# Desktop compilation
# ============================================================

build_desktop_target()
{
    local source_file="$1"
    local output_file="$2"

    require_command "${CC}"
    require_file "${source_file}"
    require_file "fuzzy.h"

    echo
    echo "Building ${output_file} from ${source_file}..."

    "${COMPILER_COMMAND[@]}" \
        "${COMMON_CFLAGS[@]}" \
        "${source_file}" \
        "${COMMON_LDFLAGS[@]}" \
        -o "${output_file}" \
        "${COMMON_LDLIBS[@]}"

    echo "[OK] Built ${output_file}"
}


build_strength()
{
    build_desktop_target \
        "${STRENGTH_SOURCE}" \
        "${STRENGTH_TARGET}"
}


build_greenhouse()
{
    build_desktop_target \
        "${GREENHOUSE_SOURCE}" \
        "${GREENHOUSE_TARGET}"
}


build_demo()
{
    build_desktop_target \
        "${DEMO_SOURCE}" \
        "${DEMO_TARGET}"
}


build_sim_8051()
{
    build_desktop_target \
        "${SIM_8051_SOURCE}" \
        "${SIM_8051_TARGET}"
}


build_desktop()
{
    print_heading "Building desktop programs"

    create_directories

    build_strength
    build_greenhouse
    build_demo
    build_sim_8051

    echo
    echo "Desktop build complete."
}


# ============================================================
# Desktop execution
# ============================================================

run_strength()
{
    create_directories
    build_strength

    print_heading "Running paint-strength example"

    "./${STRENGTH_TARGET}"
}


run_greenhouse()
{
    create_directories
    build_greenhouse

    print_heading "Running greenhouse example"

    "./${GREENHOUSE_TARGET}"
}


run_demo()
{
    create_directories
    build_demo

    print_heading "Running complete fuzzy.h demonstration"

    "./${DEMO_TARGET}"
}


run_sim_8051()
{
    create_directories
    build_sim_8051

    print_heading "Running desktop 8051 simulation harness"

    (
        cd "${SIM_8051_OUTPUT}"
        "../../${SIM_8051_TARGET}"
    )
}


# ============================================================
# Embedded SDCC build
# ============================================================

clean_embedded_files()
{
    rm -f \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.asm" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.cdb" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.hex" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.ihx" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.lk" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.lst" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.map" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.mem" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.rel" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.rst" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.sym"
}


build_embedded()
{
    require_command "${SDCC}"
    require_command "${PACKIHX}"

    require_file "${EMBEDDED_SOURCE}"
    require_file "fuzzy.h"

    create_directories
    clean_embedded_files

    print_heading "Building AT89S52 firmware with SDCC"

    echo "Source:"
    print_item "${ROOT_DIRECTORY}/${EMBEDDED_SOURCE}"

    echo
    echo "Output:"
    print_item "${ROOT_DIRECTORY}/${EMBEDDED_OUTPUT}"

    echo

    (
        cd "${EMBEDDED_OUTPUT}"

        "${SDCC}" \
            -mmcs51 \
            --model-small \
            --opt-code-size \
            --debug \
            --stack-auto \
            --iram-size 256 \
            --stack-loc 0x80 \
            -I"${ROOT_DIRECTORY}" \
            -o "${EMBEDDED_BASENAME}.ihx" \
            "${ROOT_DIRECTORY}/${EMBEDDED_SOURCE}"

        if [ ! -f "${EMBEDDED_BASENAME}.ihx" ]; then
            echo
            echo "Error: SDCC did not generate ${EMBEDDED_BASENAME}.ihx"
            exit 1
        fi

        "${PACKIHX}" \
            "${EMBEDDED_BASENAME}.ihx" \
            > "${EMBEDDED_BASENAME}.hex"
    )

    echo
    echo "SDCC build complete."

    print_heading "Firmware files"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.ihx"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.hex"

    print_heading "Debug and analysis files"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.asm"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.cdb"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.lst"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.map"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.mem"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.rst"

    show_file_if_present \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.sym"

    print_heading "Memory report"

    if [ -f "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.mem" ]; then
        cat "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.mem"
    else
        echo "No memory report was generated."
    fi

    echo
    echo "Generated embedded firmware:"
    print_item "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.ihx"
    print_item "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.hex"
}


# ============================================================
# Embedded simulation and debugging
# ============================================================
simulate_8051()
{
    build_embedded

    local simulator=""

    if command -v ucsim_51 >/dev/null 2>&1; then
        simulator="ucsim_51"
    elif command -v s51 >/dev/null 2>&1; then
        simulator="s51"
    else
        echo "Error: no 8051 simulator was found."
        exit 1
    fi

    print_heading "Starting 8051 simulator"

    echo "Simulator:"
    print_item "${simulator}"

    echo
    echo "Firmware:"
    print_item "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.ihx"

    echo

    "${simulator}" \
        -t 52 \
        -X 11.0592M \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.ihx"
}

debug_8051()
{
    build_embedded
    require_command "${SDCDB}"

    mkdir -p "${EMBEDDED_OUTPUT}/tools"

    if command -v s51 >/dev/null 2>&1; then
        :
    elif command -v ucsim_51 >/dev/null 2>&1; then
        ln -sf \
            "$(command -v ucsim_51)" \
            "${EMBEDDED_OUTPUT}/tools/s51"
    else
        echo "Error: no 8051 simulator was found."
        echo
        echo "Install it with:"
        echo "  sudo apt-get install -y sdcc-ucsim"
        exit 1
    fi

    cp \
        "${ROOT_DIRECTORY}/${EMBEDDED_SOURCE}" \
        "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.c"

    cp \
        "${ROOT_DIRECTORY}/fuzzy.h" \
        "${EMBEDDED_OUTPUT}/fuzzy.h"

    print_heading "Starting 8051 source-level debugger"

    echo "Debug module:"
    print_item "${EMBEDDED_BASENAME}"

    echo
    echo "Watch variables:"
    print_item "test_temperature"
    print_item "test_fan_speed"
    print_item "test_pwm"

    echo
    echo "Enter:"
    print_item "break main"
    print_item "run"
    print_item "print test_temperature"
    print_item "next"
    print_item "next"
    print_item "print test_fan_speed"
    print_item "print test_pwm"
    print_item "quit"

    echo

    (
        cd "${EMBEDDED_OUTPUT}"

        PATH="${PWD}/tools:${PATH}" \
            "${SDCDB}" \
                -cpu 8052 \
                "${EMBEDDED_BASENAME}"
    )
}



# ============================================================
# 8051 branch host testing
# ============================================================

test_8051()
{
    require_command "${CC}"
    require_file "fuzzy.h"

    create_directories

    local test_source="${SIM_8051_ROOT}/test_8051_host.c"
    local test_binary="${SIM_8051_ROOT}/test-8051-host"

    print_heading "Testing FUZZY_8051 branch with desktop GCC"

    cat > "${test_source}" <<'EOF'
#define FUZZY_8051
#define FUZZY_MAX_RULES 4u
#define FUZZY_IMPLEMENTATION

#include "../fuzzy.h"


static const hedges_t hedges = {
    1u,
    2u,
    3u
};


static float temperature_low(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        40.0,
        false
    );
}


static float temperature_high(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        30.0,
        60.0,
        true
    );
}


static float fan_slow(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        20.0,
        50.0,
        false
    );
}


static float fan_fast(float value)
{
    return fuzzy_function(
        "ramp",
        value,
        hedges.none,
        40.0,
        80.0,
        true
    );
}


static float calculate_fan_speed(float temperature)
{
    fuzzy_rules_t rules;
    float result;

    rules =
        fuzzy_rules_create();

    if (!FUZZY_RULE_ADD(
        &rules,
        temperature_low(temperature),
        fan_slow
    )) {
        return 0.0f;
    }

    if (!FUZZY_RULE_ADD(
        &rules,
        temperature_high(temperature),
        fan_fast
    )) {
        return 0.0f;
    }

    result =
        fuzzy_rules_cog(
            &rules,
            0.0f,
            100.0f,
            5.0f
        );

    fuzzy_rules_free(
        &rules
    );

    return result;
}


int main(void)
{
    int temperature;

    for (
        temperature = 0;
        temperature <= 100;
        temperature += 5
    ) {
        float fan_speed =
            calculate_fan_speed(
                (float)temperature
            );

        if (
            fan_speed < 0.0f ||
            fan_speed > 100.0f
        ) {
            return 1;
        }
    }

    return 0;
}
EOF

    "${CC}" \
        -std=c11 \
        -O2 \
        -Wall \
        -Wextra \
        -Wpedantic \
        "${test_source}" \
        -o "${test_binary}"

    "${test_binary}"

    echo "[OK] FUZZY_8051 branch passed the host execution test."

    print_heading "Checking embedded preprocessed output"

    "${CC}" \
        -std=c11 \
        -E \
        "${test_source}" \
        > "${SIM_8051_ROOT}/test_8051_host.i"

    if grep -E \
        'fopen|fprintf|calloc|malloc|realloc|powf|expf|ceilf' \
        "${SIM_8051_ROOT}/test_8051_host.i" \
        >/dev/null 2>&1
    then
        echo "Warning: desktop-only symbols appear in preprocessed output."
        echo
        grep -n -E \
            'fopen|fprintf|calloc|malloc|realloc|powf|expf|ceilf' \
            "${SIM_8051_ROOT}/test_8051_host.i" \
            | head -n 20
    else
        echo "[OK] No forbidden desktop-only calls found."
    fi
}


run_all_tests()
{
    test_8051
    build_embedded
}


# ============================================================
# SVG conversion
# ============================================================

require_converter()
{
    require_command "${SVG_CONVERTER}"
}


convert_svg_directory()
{
    local directory="$1"
    local format="$2"
    local found=0
    local input_file
    local output_file

    require_converter

    if [ ! -d "${directory}" ]; then
        echo "No directory found: ${directory}"
        return 0
    fi

    shopt -s nullglob

    for input_file in "${directory}"/*.svg; do
        found=1
        output_file="${input_file%.svg}.${format}"

        echo "[${format^^}] ${input_file} -> ${output_file}"

        if [ "${format}" = "pdf" ]; then
            "${SVG_CONVERTER}" \
                --format=pdf \
                --output="${output_file}" \
                "${input_file}"
        else
            "${SVG_CONVERTER}" \
                --output="${output_file}" \
                "${input_file}"
        fi
    done

    shopt -u nullglob

    if [ "${found}" -eq 0 ]; then
        echo "No SVG files found in ${directory}"
    fi
}


convert_all_png()
{
    print_heading "Converting all SVG files to PNG"

    convert_svg_directory "${STRENGTH_OUTPUT}" png
    convert_svg_directory "${GREENHOUSE_OUTPUT}" png
    convert_svg_directory "${DEMO_OUTPUT}" png
    convert_svg_directory "${SIM_8051_OUTPUT}" png
}


convert_all_pdf()
{
    print_heading "Converting all SVG files to PDF"

    convert_svg_directory "${STRENGTH_OUTPUT}" pdf
    convert_svg_directory "${GREENHOUSE_OUTPUT}" pdf
    convert_svg_directory "${DEMO_OUTPUT}" pdf
    convert_svg_directory "${SIM_8051_OUTPUT}" pdf
}


# ============================================================
# Cleanup
# ============================================================

remove_generated_directory_files()
{
    local directory="$1"

    if [ ! -d "${directory}" ]; then
        return
    fi

    find "${directory}" \
        -maxdepth 1 \
        -type f \
        \( \
            -name '*.svg' \
            -o -name '*.png' \
            -o -name '*.pdf' \
            -o -name '*.csv' \
        \) \
        -delete
}


clean_desktop()
{
    print_heading "Cleaning desktop outputs"

    rm -f \
        "${STRENGTH_TARGET}" \
        "${GREENHOUSE_TARGET}" \
        "${DEMO_TARGET}" \
        "${SIM_8051_TARGET}" \
        "${SIM_8051_ROOT}/test-8051-host" \
        "${SIM_8051_ROOT}/test_8051_host.c" \
        "${SIM_8051_ROOT}/test_8051_host.i"

    remove_generated_directory_files \
        "${STRENGTH_OUTPUT}"

    remove_generated_directory_files \
        "${GREENHOUSE_OUTPUT}"

    remove_generated_directory_files \
        "${DEMO_OUTPUT}"

    remove_generated_directory_files \
        "${SIM_8051_OUTPUT}"

    echo "Desktop outputs removed."
}


clean_embedded()
{
    print_heading "Cleaning embedded outputs"

    if [ -d "${EMBEDDED_OUTPUT}" ]; then
        rm -rf \
            "${EMBEDDED_OUTPUT:?}/"*
    fi

    echo "Embedded outputs removed."
}


clean_all()
{
    clean_desktop
    clean_embedded

    echo
    echo "All generated outputs removed."
}


# ============================================================
# Complete build
# ============================================================

build_all()
{
    check_dependencies
    create_directories
    build_desktop
    build_embedded

    print_heading "Complete build finished"

    echo "Desktop executables:"
    print_item "${STRENGTH_TARGET}"
    print_item "${GREENHOUSE_TARGET}"
    print_item "${DEMO_TARGET}"
    print_item "${SIM_8051_TARGET}"

    echo
    echo "Embedded firmware:"
    print_item "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.ihx"
    print_item "${EMBEDDED_OUTPUT}/${EMBEDDED_BASENAME}.hex"
}


# ============================================================
# Help
# ============================================================

show_help()
{
    cat <<'EOF'
fuzzy.h monolithic build system

Basic commands:

  make
      Build all desktop programs and the embedded 8051 firmware.

  make desktop
      Build all desktop programs.

  make embedded
      Build 8051.ihx and 8051.hex with SDCC.

  make test
      Run the FUZZY_8051 host test and build the firmware.


Desktop examples:

  make run-strength
  make run-greenhouse
  make run-demo
  make run-sim-8051


8051 commands:

  make build-8051
      Build the SDCC firmware.

  make simulate-8051
      Build and open the firmware in s51.

  make debug-8051
      Build and open the SDCC debugger.

  make test-8051
      Compile and execute the FUZZY_8051 branch using desktop GCC.


Dependency commands:

  make check-dependencies
  make install-dependencies


Image conversion:

  make png
  make png-strength
  make png-greenhouse
  make png-demo
  make png-sim-8051

  make pdf
  make pdf-strength
  make pdf-greenhouse
  make pdf-demo
  make pdf-sim-8051


Cleanup:

  make clean
  make clean-desktop
  make clean-embedded


Output locations:

  Paint strength:
      svg/

  Greenhouse:
      greenhouse/

  Complete demonstration:
      demo-all/

  Desktop 8051 simulation:
      sim-8051/desktop/

  Embedded 8051 firmware:
      sim-8051/embedded/


Override embedded source or output directory:

  EMBEDDED_SOURCE=my_controller.c make embedded

  EMBEDDED_OUTPUT=build/8051 make embedded


Direct script usage:

  ./scripts/build.sh all
  ./scripts/build.sh desktop
  ./scripts/build.sh embedded
  ./scripts/build.sh run-demo
  ./scripts/build.sh simulate-8051
  ./scripts/build.sh clean
EOF
}


# ============================================================
# Action dispatcher
# ============================================================

case "${ACTION}" in
    all)
        build_all
        ;;

    desktop)
        build_desktop
        ;;

    embedded|build-8051)
        build_embedded
        ;;

    test)
        run_all_tests
        ;;

    test-8051)
        test_8051
        ;;

    run-strength)
        run_strength
        ;;

    run-greenhouse)
        run_greenhouse
        ;;

    run-demo)
        run_demo
        ;;

    run-sim-8051)
        run_sim_8051
        ;;

    simulate-8051)
        simulate_8051
        ;;

    debug-8051)
        debug_8051
        ;;

    check-dependencies)
        check_dependencies
        ;;

    install-dependencies)
        install_dependencies
        ;;

    png)
        convert_all_png
        ;;

    png-strength)
        convert_svg_directory "${STRENGTH_OUTPUT}" png
        ;;

    png-greenhouse)
        convert_svg_directory "${GREENHOUSE_OUTPUT}" png
        ;;

    png-demo)
        convert_svg_directory "${DEMO_OUTPUT}" png
        ;;

    png-sim-8051)
        convert_svg_directory "${SIM_8051_OUTPUT}" png
        ;;

    pdf)
        convert_all_pdf
        ;;

    pdf-strength)
        convert_svg_directory "${STRENGTH_OUTPUT}" pdf
        ;;

    pdf-greenhouse)
        convert_svg_directory "${GREENHOUSE_OUTPUT}" pdf
        ;;

    pdf-demo)
        convert_svg_directory "${DEMO_OUTPUT}" pdf
        ;;

    pdf-sim-8051)
        convert_svg_directory "${SIM_8051_OUTPUT}" pdf
        ;;

    clean)
        clean_all
        ;;

    clean-desktop)
        clean_desktop
        ;;

    clean-embedded)
        clean_embedded
        ;;

    help|-h|--help)
        show_help
        ;;

    *)
        echo "Error: unknown action: ${ACTION}"
        echo
        show_help
        exit 1
        ;;
esac