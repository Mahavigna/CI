#!/usr/bin/env bash
set -Eeuo pipefail

# ============================================================
# Ubuntu / WSL2 Development Environment Setup
#
# OpenCL
#   - Vendor-agnostic ICD loader and development headers
#   - Detects an already exposed Intel, AMD, NVIDIA, or Mesa GPU
#   - Installs an Ubuntu-packaged runtime only when no GPU exists
#   - Never accepts a CPU OpenCL fallback
#
# ESP32
#   - Espressif standalone Xtensa GCC toolchain
#   - Espressif standalone RISC-V GCC toolchain
#   - Espressif ESP32 emulator
#
# No Arduino
# No ESP-IDF project setup
# No CMake
# No Ninja
# ============================================================

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

pass() { echo -e "${GREEN}[PASS]${NC} $*"; }
fail() { echo -e "${RED}[FAIL]${NC} $*" >&2; exit 1; }
info() { echo -e "${YELLOW}[INFO]${NC} $*"; }

package_exists()
{
    apt-cache show "$1" >/dev/null 2>&1
}

opencl_gpu_exists()
{
    clinfo 2>/dev/null | grep -Eq 'Device Type[[:space:]]+GPU'
}

detect_gpu_vendor()
{
    local text=""

    if grep -qi microsoft /proc/version && command -v powershell.exe >/dev/null 2>&1; then
        text=$(powershell.exe -NoProfile -Command "Get-CimInstance Win32_VideoController | ForEach-Object { \$_.Name }" 2>/dev/null | tr -d '\r' || true)
    fi

    if [[ -z "$text" ]] && command -v lspci >/dev/null 2>&1; then
        text=$(lspci -nn 2>/dev/null | grep -Ei 'VGA|3D|Display' || true)
    fi

    if grep -Eqi 'Intel' <<< "$text"; then
        printf '%s\n' intel
        return 0
    fi

    if grep -Eqi 'AMD|ATI|Advanced Micro Devices' <<< "$text"; then
        printf '%s\n' amd
        return 0
    fi

    if grep -Eqi 'NVIDIA' <<< "$text"; then
        printf '%s\n' nvidia
        return 0
    fi

    printf '%s\n' unknown
}

echo "======================================"
echo " Ubuntu / WSL2 Development Setup"
echo " Vendor-agnostic OpenCL + ESP32"
echo "======================================"

# ============================================================
# 1. Environment checks
# ============================================================

[[ -f /etc/os-release ]] || fail "Cannot identify Linux distribution."
source /etc/os-release
[[ "${ID:-}" == "ubuntu" ]] || fail "This setup requires Ubuntu. Detected: ${PRETTY_NAME:-unknown}."

info "Distribution: $PRETTY_NAME"
info "Kernel: $(uname -r)"

if grep -qi microsoft /proc/version; then
    pass "WSL detected."
    [[ -e /dev/dxg ]] || fail "WSL2 GPU bridge /dev/dxg is missing. GPU OpenCL setup cannot continue."
    pass "WSL2 GPU bridge detected: /dev/dxg"
else
    pass "Native Ubuntu detected."
    [[ -e /dev/dri/renderD128 ]] || fail "GPU render device /dev/dri/renderD128 is missing."
    pass "GPU render device detected: /dev/dri/renderD128"
fi

# ============================================================
# 2. Install vendor-neutral OpenCL and build dependencies
# ============================================================

info "Updating package lists..."
sudo apt-get update

info "Installing vendor-neutral OpenCL loader, headers, and tools..."
sudo apt-get install -y \
    build-essential \
    curl \
    wget \
    xz-utils \
    tar \
    pciutils \
    clinfo \
    ocl-icd-libopencl1 \
    ocl-icd-opencl-dev \
    opencl-c-headers \
    opencl-clhpp-headers

pass "Vendor-neutral OpenCL development stack installed."

# ============================================================
# 3. Install a vendor runtime only when no GPU is exposed
# ============================================================

if opencl_gpu_exists; then
    pass "An OpenCL GPU runtime is already available. No vendor runtime was replaced."
else
    GPU_VENDOR=$(detect_gpu_vendor)
    info "Detected GPU vendor: $GPU_VENDOR"

    case "$GPU_VENDOR" in
        intel)
            package_exists intel-opencl-icd || fail "Ubuntu does not provide intel-opencl-icd for this release."
            sudo apt-get install -y intel-opencl-icd
            ;;
        amd)
            if package_exists rocm-opencl-icd; then
                sudo apt-get install -y rocm-opencl-icd
            elif package_exists mesa-opencl-icd; then
                sudo apt-get install -y mesa-opencl-icd
            else
                fail "No Ubuntu-packaged AMD OpenCL runtime is available. Install AMD ROCm OpenCL for this Ubuntu release."
            fi
            ;;
        nvidia)
            fail "No OpenCL GPU was exposed by the installed NVIDIA driver. Install or repair the matching Windows/NVIDIA driver first; this script will not guess or replace a GPU driver."
            ;;
        *)
            fail "GPU vendor could not be identified and no OpenCL GPU is available."
            ;;
    esac
fi

# ============================================================
# 4. Verify ICD registrations and GPU-only OpenCL exposure
# ============================================================

[[ -d /etc/OpenCL/vendors ]] || fail "OpenCL ICD directory /etc/OpenCL/vendors is missing."
compgen -G '/etc/OpenCL/vendors/*.icd' >/dev/null || fail "No OpenCL ICD registration files were found."

info "Registered OpenCL ICD files:"
for icd in /etc/OpenCL/vendors/*.icd; do
    printf '  %s: ' "$icd"
    cat "$icd"
done

info "OpenCL platforms and devices:"
clinfo -l

DEVICE_INFO=$(clinfo 2>/dev/null) || fail "clinfo failed."
grep -Eq 'Device Type[[:space:]]+GPU' <<< "$DEVICE_INFO" || fail "No OpenCL GPU device was found. CPU fallback is forbidden."
grep -Eq 'Device Available[[:space:]]+Yes' <<< "$DEVICE_INFO" || fail "No available OpenCL device was reported."

pass "At least one available OpenCL GPU was detected."
echo "$DEVICE_INFO" | grep -E 'Platform Name|Device Name|Device Vendor|Device Vendor ID|Device Type|Device Available' || true

# ============================================================
# 5. Generate vendor-agnostic GPU test program
# ============================================================

cat > gpu_test.c <<'C_EOF'
#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1024

#define CHECK(err, msg) do { if ((err) != CL_SUCCESS) { fprintf(stderr, "%s failed: OpenCL error %d\n", msg, err); return 1; } } while (0)

int main(void)
{
    cl_int err;
    cl_uint platform_count = 0u;
    cl_platform_id *platforms = NULL;
    cl_platform_id selected_platform = NULL;
    cl_device_id selected_device = NULL;
    cl_ulong best_score = 0u;
    cl_ulong best_memory = 0u;
    cl_uint candidate_count = 0u;
    cl_uint platform_index;

    err = clGetPlatformIDs(0u, NULL, &platform_count);
    CHECK(err, "clGetPlatformIDs count");
    if (platform_count == 0u) { fprintf(stderr, "No OpenCL platforms found.\n"); return 1; }

    platforms = calloc(platform_count, sizeof(*platforms));
    if (platforms == NULL) { fprintf(stderr, "Platform allocation failed.\n"); return 1; }
    err = clGetPlatformIDs(platform_count, platforms, NULL);
    CHECK(err, "clGetPlatformIDs list");

    for (platform_index = 0u; platform_index < platform_count; ++platform_index)
    {
        cl_uint device_count = 0u;
        cl_device_id *devices = NULL;
        cl_uint device_index;

        err = clGetDeviceIDs(platforms[platform_index], CL_DEVICE_TYPE_GPU, 0u, NULL, &device_count);
        if (err == CL_DEVICE_NOT_FOUND || device_count == 0u) continue;
        CHECK(err, "clGetDeviceIDs count");

        devices = calloc(device_count, sizeof(*devices));
        if (devices == NULL) { fprintf(stderr, "Device allocation failed.\n"); free(platforms); return 1; }
        err = clGetDeviceIDs(platforms[platform_index], CL_DEVICE_TYPE_GPU, device_count, devices, NULL);
        CHECK(err, "clGetDeviceIDs list");

        for (device_index = 0u; device_index < device_count; ++device_index)
        {
            char name[256] = {0};
            char vendor[256] = {0};
            cl_bool available = CL_FALSE;
            cl_bool compiler = CL_FALSE;
            cl_uint units = 0u;
            cl_uint clock = 0u;
            cl_ulong memory = 0u;
            cl_ulong score;

            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_NAME, sizeof(name), name, NULL), "CL_DEVICE_NAME");
            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_VENDOR, sizeof(vendor), vendor, NULL), "CL_DEVICE_VENDOR");
            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_AVAILABLE, sizeof(available), &available, NULL), "CL_DEVICE_AVAILABLE");
            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_COMPILER_AVAILABLE, sizeof(compiler), &compiler, NULL), "CL_DEVICE_COMPILER_AVAILABLE");
            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(units), &units, NULL), "CL_DEVICE_MAX_COMPUTE_UNITS");
            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(clock), &clock, NULL), "CL_DEVICE_MAX_CLOCK_FREQUENCY");
            CHECK(clGetDeviceInfo(devices[device_index], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(memory), &memory, NULL), "CL_DEVICE_GLOBAL_MEM_SIZE");

            if (available != CL_TRUE || compiler != CL_TRUE) continue;
            ++candidate_count;
            score = (cl_ulong)units * (cl_ulong)clock;
            printf("GPU candidate %u: %s | %s | %u compute units | %u MHz | %.2f MiB\n", candidate_count, vendor, name, units, clock, (double)memory / 1048576.0);

            if (selected_device == NULL || score > best_score || (score == best_score && memory > best_memory))
            {
                selected_platform = platforms[platform_index];
                selected_device = devices[device_index];
                best_score = score;
                best_memory = memory;
            }
        }
        free(devices);
    }

    free(platforms);
    if (selected_device == NULL || selected_platform == NULL) { fprintf(stderr, "No available OpenCL GPU with a compiler was found. CPU fallback is forbidden.\n"); return 1; }

    {
        char name[256] = {0};
        char vendor[256] = {0};
        cl_context context;
        cl_command_queue queue;
        cl_program program;
        cl_kernel kernel;
        cl_mem A;
        cl_mem B;
        cl_mem C;
        float a[N], b[N], c[N];
        size_t global = N;
        int i;
        const char *source = "__kernel void add(__global const float *a,__global const float *b,__global float *c){size_t i=get_global_id(0);c[i]=a[i]+b[i];}";

        CHECK(clGetDeviceInfo(selected_device, CL_DEVICE_NAME, sizeof(name), name, NULL), "selected CL_DEVICE_NAME");
        CHECK(clGetDeviceInfo(selected_device, CL_DEVICE_VENDOR, sizeof(vendor), vendor, NULL), "selected CL_DEVICE_VENDOR");
        printf("Selected GPU: %s | %s\n", vendor, name);

        context = clCreateContext(NULL, 1u, &selected_device, NULL, NULL, &err);
        CHECK(err, "clCreateContext");
        queue = clCreateCommandQueue(context, selected_device, 0u, &err);
        CHECK(err, "clCreateCommandQueue");
        program = clCreateProgramWithSource(context, 1u, &source, NULL, &err);
        CHECK(err, "clCreateProgramWithSource");
        err = clBuildProgram(program, 1u, &selected_device, NULL, NULL, NULL);
        if (err != CL_SUCCESS)
        {
            size_t size = 0u;
            char *log;
            clGetProgramBuildInfo(program, selected_device, CL_PROGRAM_BUILD_LOG, 0u, NULL, &size);
            log = calloc(size + 1u, 1u);
            if (log != NULL) { clGetProgramBuildInfo(program, selected_device, CL_PROGRAM_BUILD_LOG, size, log, NULL); fprintf(stderr, "Build log:\n%s\n", log); free(log); }
            fprintf(stderr, "Kernel compilation failed: %d\n", err);
            return 1;
        }

        for (i = 0; i < N; ++i) { a[i] = (float)i; b[i] = (float)(i * 2); }
        A = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(a), a, &err); CHECK(err, "Buffer A");
        B = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(b), b, &err); CHECK(err, "Buffer B");
        C = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(c), NULL, &err); CHECK(err, "Buffer C");
        kernel = clCreateKernel(program, "add", &err); CHECK(err, "clCreateKernel");
        CHECK(clSetKernelArg(kernel, 0u, sizeof(A), &A), "Argument A");
        CHECK(clSetKernelArg(kernel, 1u, sizeof(B), &B), "Argument B");
        CHECK(clSetKernelArg(kernel, 2u, sizeof(C), &C), "Argument C");
        CHECK(clEnqueueNDRangeKernel(queue, kernel, 1u, NULL, &global, NULL, 0u, NULL, NULL), "Kernel execution");
        CHECK(clEnqueueReadBuffer(queue, C, CL_TRUE, 0u, sizeof(c), c, 0u, NULL, NULL), "Readback");

        for (i = 0; i < N; ++i) if (fabsf(c[i] - (a[i] + b[i])) > 0.0001f) { fprintf(stderr, "Mismatch at %d: %f\n", i, c[i]); return 1; }
        printf("Test: %d elements\n", N);
        printf("Example: %.1f + %.1f = %.1f\n", a[100], b[100], c[100]);
        printf("GPU computation PASSED.\n");

        clReleaseKernel(kernel);
        clReleaseMemObject(A);
        clReleaseMemObject(B);
        clReleaseMemObject(C);
        clReleaseProgram(program);
        clReleaseCommandQueue(queue);
        clReleaseContext(context);
    }

    return 0;
}
C_EOF

pass "Generated gpu_test.c"

# ============================================================
# 6. Compile and execute OpenCL GPU test
# ============================================================

info "Compiling OpenCL test..."
gcc -O2 -Wall -Wextra -Wpedantic -std=c11 gpu_test.c -o gpu_test -lOpenCL -lm
pass "OpenCL compilation successful."

info "Executing GPU kernel..."
./gpu_test
pass "Vendor-agnostic OpenCL GPU setup and computation verified."

# ============================================================
# 7. ESP32 configuration
# ============================================================

ESP_TOOLS="$HOME/.local/esp"
XTENSA_VERSION="16.1.0_20260609"
RISCV_VERSION="16.1.0_20260609"
mkdir -p "$ESP_TOOLS"

# ============================================================
# 8. Install Xtensa ESP32 GCC
# ============================================================

XTENSA_DIR="$ESP_TOOLS/xtensa-esp-elf"
if [[ ! -x "$XTENSA_DIR/bin/xtensa-esp-elf-gcc" ]]; then
    info "Installing Xtensa ESP32 GCC toolchain..."
    XTENSA_ARCHIVE="/tmp/xtensa-esp-elf.tar.xz"
    wget -q --show-progress -O "$XTENSA_ARCHIVE" "https://github.com/espressif/crosstool-NG/releases/download/esp-${XTENSA_VERSION}/xtensa-esp-elf-${XTENSA_VERSION}-x86_64-linux-gnu.tar.xz"
    tar -xJf "$XTENSA_ARCHIVE" -C "$ESP_TOOLS"
    rm -f "$XTENSA_ARCHIVE"
    pass "Xtensa ESP32 GCC installed."
else
    pass "Xtensa ESP32 GCC already installed."
fi

# ============================================================
# 9. Install RISC-V ESP32 GCC
# ============================================================

RISCV_DIR="$ESP_TOOLS/riscv32-esp-elf"
if [[ ! -x "$RISCV_DIR/bin/riscv32-esp-elf-gcc" ]]; then
    info "Installing RISC-V ESP32 GCC toolchain..."
    RISCV_ARCHIVE="/tmp/riscv32-esp-elf.tar.xz"
    wget -q --show-progress -O "$RISCV_ARCHIVE" "https://github.com/espressif/crosstool-NG/releases/download/esp-${RISCV_VERSION}/riscv32-esp-elf-${RISCV_VERSION}-x86_64-linux-gnu.tar.xz"
    tar -xJf "$RISCV_ARCHIVE" -C "$ESP_TOOLS"
    rm -f "$RISCV_ARCHIVE"
    pass "RISC-V ESP32 GCC installed."
else
    pass "RISC-V ESP32 GCC already installed."
fi

# ============================================================
# 10. Add ESP32 toolchains to PATH
# ============================================================

ESP_PATH="$XTENSA_DIR/bin:$RISCV_DIR/bin"
export PATH="$ESP_PATH:$HOME/.local/bin:$PATH"
pass "ESP32 toolchains added to current PATH."

# ============================================================
# 11. Install official ESP32 emulator
# ============================================================

ESP_EMU="$HOME/.local/bin/esp-emu"
mkdir -p "$HOME/.local/bin"
if [[ ! -x "$ESP_EMU" ]]; then
    info "Installing official Espressif ESP32 emulator..."
    curl -fsSL https://raw.githubusercontent.com/espressif/esp-emulator/main/install.sh | sh
    pass "ESP32 emulator installed."
else
    pass "ESP32 emulator already installed."
fi

# ============================================================
# 12. Make ESP32 tools permanent
# ============================================================

PROFILE="$HOME/.bashrc"
ESP_EXPORT="export PATH=\"$ESP_PATH:\$HOME/.local/bin:\$PATH\""
if ! grep -Fq "$ESP_EXPORT" "$PROFILE" 2>/dev/null; then
    printf '\n# ESP32 standalone toolchains\n%s\n' "$ESP_EXPORT" >> "$PROFILE"
    pass "ESP32 PATH added to ~/.bashrc."
else
    pass "ESP32 PATH already present in ~/.bashrc."
fi

# ============================================================
# 13. Verify ESP32 tools
# ============================================================

command -v xtensa-esp-elf-gcc >/dev/null 2>&1 || fail "xtensa-esp-elf-gcc not found."
xtensa-esp-elf-gcc --version | head -n 1
pass "Xtensa ESP32 compiler verified."

command -v riscv32-esp-elf-gcc >/dev/null 2>&1 || fail "riscv32-esp-elf-gcc not found."
riscv32-esp-elf-gcc --version | head -n 1
pass "RISC-V ESP32 compiler verified."

command -v esp-emu >/dev/null 2>&1 || fail "esp-emu not found."
esp-emu --version
pass "ESP32 emulator verified."

# ============================================================
# 14. Final summary
# ============================================================

echo ""
echo "======================================"
echo " ALL CHECKS PASSED"
echo "======================================"
echo ""
echo "OpenCL GPU discovery, selection, compilation, execution, and readback passed."
echo "ESP32 Xtensa compiler, RISC-V compiler, and emulator passed."
echo "Restart the shell or run: source ~/.bashrc"
echo "======================================"
