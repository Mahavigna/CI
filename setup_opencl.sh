#!/usr/bin/env bash
set -Eeuo pipefail

# ============================================================
# Ubuntu / WSL2 Development Environment Setup
#
# Intel HD Graphics 620
#   - Intel OpenCL Legacy runtime
#   - OpenCL development tools
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

echo "======================================"
echo " Ubuntu / WSL2 Development Setup"
echo " OpenCL + ESP32"
echo "======================================"

# ============================================================
# 1. Environment checks
# ============================================================

[[ -f /etc/os-release ]] || fail "Cannot identify Linux distribution."
source /etc/os-release

info "Distribution: $PRETTY_NAME"
info "Kernel: $(uname -r)"

if ! grep -qi microsoft /proc/version; then
    info "Not running under WSL. Continuing anyway."
else
    pass "WSL detected."
fi

[[ -e /dev/dxg ]] || info "/dev/dxg not found."
[[ -e /dev/dri/renderD128 ]] || info "/dev/dri/renderD128 not found."

# ============================================================
# 2. Remove Mesa Rusticl OpenCL
# ============================================================

if dpkg -s mesa-opencl-icd >/dev/null 2>&1; then
    info "Removing Mesa Rusticl OpenCL..."
    sudo apt-get remove -y mesa-opencl-icd
    pass "Mesa Rusticl removed."
else
    pass "Mesa OpenCL package already absent."
fi

# ============================================================
# 3. Install common build dependencies
# ============================================================

info "Updating package lists..."
sudo apt-get update

info "Installing common development tools..."
sudo apt-get install -y \
    build-essential \
    curl \
    wget \
    xz-utils \
    tar \
    clinfo \
    ocl-icd-opencl-dev

pass "Common development tools installed."

# ============================================================
# 4. Install Intel OpenCL runtime
# ============================================================

info "Installing Intel legacy OpenCL runtime..."

sudo apt-get install -y \
    intel-opencl-icd-legacy

pass "Intel OpenCL runtime installed."

# ============================================================
# 5. Verify Intel ICD
# ============================================================

ICD="/etc/OpenCL/vendors/intel_legacy1.icd"

if [[ ! -f "$ICD" ]]; then
    echo "Available ICD files:"
    ls -la /etc/OpenCL/vendors/ || true
    fail "Intel legacy ICD file not found."
fi

pass "Intel ICD registered: $ICD"
cat "$ICD"

# ============================================================
# 6. Verify OpenCL GPU
# ============================================================

info "Checking OpenCL platforms and devices..."

clinfo -l

DEVICE_INFO=$(clinfo 2>/dev/null || true)

if ! grep -q "Intel(R) Graphics \[0x5916\]" <<< "$DEVICE_INFO"; then
    echo "$DEVICE_INFO" | grep -E \
        'Platform Name|Device Name|Device Vendor|Driver Version' || true

    fail "Intel HD Graphics 620 was not detected."
fi

pass "Intel HD Graphics 620 detected."

# ============================================================
# 7. Generate OpenCL test program
# ============================================================

cat > gpu_test.c <<'EOF'
#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024

#define CHECK(err, msg) do { \
    if ((err) != CL_SUCCESS) { \
        fprintf(stderr, "%s failed: OpenCL error %d\n", msg, err); \
        return 1; \
    } \
} while (0)

int main(void)
{
    cl_int err;
    cl_uint count = 0;
    cl_platform_id platform;
    cl_device_id device;

    err = clGetPlatformIDs(1, &platform, &count);
    CHECK(err, "clGetPlatformIDs");

    if (count == 0) {
        fprintf(stderr, "No OpenCL platforms found.\n");
        return 1;
    }

    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU,
                         1, &device, NULL);
    CHECK(err, "clGetDeviceIDs");

    char name[256] = {0};

    clGetDeviceInfo(device,
                    CL_DEVICE_NAME,
                    sizeof(name),
                    name,
                    NULL);

    printf("Selected GPU: %s\n", name);

    cl_context context =
        clCreateContext(NULL, 1, &device,
                        NULL, NULL, &err);

    CHECK(err, "clCreateContext");

    cl_command_queue queue =
        clCreateCommandQueue(context,
                              device,
                              0,
                              &err);

    CHECK(err, "clCreateCommandQueue");

    const char *source =
        "__kernel void add("
        "__global const float *a,"
        "__global const float *b,"
        "__global float *c) {"
        "size_t i = get_global_id(0);"
        "c[i] = a[i] + b[i];"
        "}";

    cl_program program =
        clCreateProgramWithSource(context,
                                  1,
                                  &source,
                                  NULL,
                                  &err);

    CHECK(err, "clCreateProgramWithSource");

    err = clBuildProgram(program,
                          1,
                          &device,
                          NULL,
                          NULL,
                          NULL);

    if (err != CL_SUCCESS) {
        size_t size = 0;

        clGetProgramBuildInfo(
            program,
            device,
            CL_PROGRAM_BUILD_LOG,
            0,
            NULL,
            &size);

        char *log = calloc(size + 1, 1);

        if (log) {
            clGetProgramBuildInfo(
                program,
                device,
                CL_PROGRAM_BUILD_LOG,
                size,
                log,
                NULL);

            fprintf(stderr,
                    "Build log:\n%s\n",
                    log);

            free(log);
        }

        fprintf(stderr,
                "Kernel compilation failed: %d\n",
                err);

        return 1;
    }

    float a[N], b[N], c[N];

    for (int i = 0; i < N; i++) {
        a[i] = (float)i;
        b[i] = (float)(i * 2);
    }

    cl_mem A =
        clCreateBuffer(context,
                       CL_MEM_READ_ONLY |
                       CL_MEM_COPY_HOST_PTR,
                       sizeof(a),
                       a,
                       &err);

    CHECK(err, "Buffer A");

    cl_mem B =
        clCreateBuffer(context,
                       CL_MEM_READ_ONLY |
                       CL_MEM_COPY_HOST_PTR,
                       sizeof(b),
                       b,
                       &err);

    CHECK(err, "Buffer B");

    cl_mem C =
        clCreateBuffer(context,
                       CL_MEM_WRITE_ONLY,
                       sizeof(c),
                       NULL,
                       &err);

    CHECK(err, "Buffer C");

    cl_kernel kernel =
        clCreateKernel(program,
                       "add",
                       &err);

    CHECK(err, "clCreateKernel");

    CHECK(clSetKernelArg(kernel,
                         0,
                         sizeof(A),
                         &A),
          "Argument A");

    CHECK(clSetKernelArg(kernel,
                         1,
                         sizeof(B),
                         &B),
          "Argument B");

    CHECK(clSetKernelArg(kernel,
                         2,
                         sizeof(C),
                         &C),
          "Argument C");

    size_t global = N;

    err = clEnqueueNDRangeKernel(
        queue,
        kernel,
        1,
        NULL,
        &global,
        NULL,
        0,
        NULL,
        NULL);

    CHECK(err, "Kernel execution");

    err = clEnqueueReadBuffer(
        queue,
        C,
        CL_TRUE,
        0,
        sizeof(c),
        c,
        0,
        NULL,
        NULL);

    CHECK(err, "Readback");

    int correct = 1;

    for (int i = 0; i < N; i++) {
        if (fabsf(c[i] - (a[i] + b[i])) > 0.0001f) {
            correct = 0;

            fprintf(stderr,
                    "Mismatch at %d: %f\n",
                    i,
                    c[i]);

            break;
        }
    }

    printf("Test: %d elements\n", N);

    printf("Example: %.1f + %.1f = %.1f\n",
           a[100],
           b[100],
           c[100]);

    clReleaseKernel(kernel);
    clReleaseMemObject(A);
    clReleaseMemObject(B);
    clReleaseMemObject(C);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    if (!correct) {
        fprintf(stderr,
                "GPU computation FAILED.\n");

        return 1;
    }

    printf("GPU computation PASSED.\n");

    return 0;
}
EOF

pass "Generated gpu_test.c"

# ============================================================
# 8. Compile OpenCL test
# ============================================================

info "Compiling OpenCL test..."

gcc -O2 \
    gpu_test.c \
    -o gpu_test \
    -lOpenCL

pass "OpenCL compilation successful."

# ============================================================
# 9. Execute OpenCL test
# ============================================================

info "Executing GPU kernel..."

./gpu_test

pass "Intel OpenCL setup and computation verified."

# ============================================================
# 10. ESP32 configuration
# ============================================================

ESP_TOOLS="$HOME/.local/esp"

XTENSA_VERSION="16.1.0_20260609"
RISCV_VERSION="16.1.0_20260609"

mkdir -p "$ESP_TOOLS"

# ============================================================
# 11. Install Xtensa ESP32 GCC
# ============================================================

XTENSA_DIR="$ESP_TOOLS/xtensa-esp-elf-$XTENSA_VERSION"

if [[ ! -x "$XTENSA_DIR/bin/xtensa-esp-elf-gcc" ]]; then

    info "Installing Xtensa ESP32 GCC toolchain..."

    XTENSA_ARCHIVE="/tmp/xtensa-esp-elf.tar.xz"

    wget -q --show-progress \
        -O "$XTENSA_ARCHIVE" \
        "https://github.com/espressif/crosstool-NG/releases/download/esp-${XTENSA_VERSION}/xtensa-esp-elf-${XTENSA_VERSION}-x86_64-linux-gnu.tar.xz"

    tar -xJf "$XTENSA_ARCHIVE" \
        -C "$ESP_TOOLS"

    rm -f "$XTENSA_ARCHIVE"

    pass "Xtensa ESP32 GCC installed."

else

    pass "Xtensa ESP32 GCC already installed."

fi

# ============================================================
# 12. Install RISC-V ESP32 GCC
# ============================================================

RISCV_DIR="$ESP_TOOLS/riscv32-esp-elf-$RISCV_VERSION"

if [[ ! -x "$RISCV_DIR/bin/riscv32-esp-elf-gcc" ]]; then

    info "Installing RISC-V ESP32 GCC toolchain..."

    RISCV_ARCHIVE="/tmp/riscv32-esp-elf.tar.xz"

    wget -q --show-progress \
        -O "$RISCV_ARCHIVE" \
        "https://github.com/espressif/crosstool-NG/releases/download/esp-${RISCV_VERSION}/riscv32-esp-elf-${RISCV_VERSION}-x86_64-linux-gnu.tar.xz"

    tar -xJf "$RISCV_ARCHIVE" \
        -C "$ESP_TOOLS"

    rm -f "$RISCV_ARCHIVE"

    pass "RISC-V ESP32 GCC installed."

else

    pass "RISC-V ESP32 GCC already installed."

fi

# ============================================================
# 13. Add ESP32 toolchains to PATH
# ============================================================

ESP_PATH="$XTENSA_DIR/bin:$RISCV_DIR/bin"

export PATH="$ESP_PATH:$HOME/.local/bin:$PATH"

pass "ESP32 toolchains added to current PATH."

# ============================================================
# 14. Install official ESP32 emulator
# ============================================================

ESP_EMU="$HOME/.local/bin/esp-emu"

mkdir -p "$HOME/.local/bin"

if [[ ! -x "$ESP_EMU" ]]; then

    info "Installing official Espressif ESP32 emulator..."

    curl -fsSL \
        https://raw.githubusercontent.com/espressif/esp-emulator/main/install.sh \
        | sh

    pass "ESP32 emulator installed."

else

    pass "ESP32 emulator already installed."

fi

# ============================================================
# 15. Make ESP32 tools permanent
# ============================================================

PROFILE="$HOME/.bashrc"

ESP_EXPORT="export PATH=\"$ESP_PATH:\$HOME/.local/bin:\$PATH\""

if ! grep -Fq "$ESP_EXPORT" "$PROFILE" 2>/dev/null; then
    echo "" >> "$PROFILE"
    echo "# ESP32 standalone toolchains" >> "$PROFILE"
    echo "$ESP_EXPORT" >> "$PROFILE"

    pass "ESP32 PATH added to ~/.bashrc."
else
    pass "ESP32 PATH already present in ~/.bashrc."
fi

# ============================================================
# 16. Verify ESP32 toolchains
# ============================================================

info "Checking Xtensa compiler..."

if ! command -v xtensa-esp-elf-gcc >/dev/null 2>&1; then
    fail "xtensa-esp-elf-gcc not found."
fi

xtensa-esp-elf-gcc --version | head -n 1

pass "Xtensa ESP32 compiler verified."

info "Checking RISC-V compiler..."

if ! command -v riscv32-esp-elf-gcc >/dev/null 2>&1; then
    fail "riscv32-esp-elf-gcc not found."
fi

riscv32-esp-elf-gcc --version | head -n 1

pass "RISC-V ESP32 compiler verified."

# ============================================================
# 17. Verify ESP32 emulator
# ============================================================

info "Checking ESP32 emulator..."

if ! command -v esp-emu >/dev/null 2>&1; then
    fail "esp-emu not found."
fi

esp-emu --version

pass "ESP32 emulator verified."

# ============================================================
# 18. Final summary
# ============================================================

echo ""
echo "======================================"
echo " ALL CHECKS PASSED"
echo "======================================"

echo ""
echo "Available tools:"
echo ""

echo "  OpenCL:"
echo "    gcc"
echo "    clinfo"
echo "    Intel OpenCL"
echo ""

echo "  ESP32 Xtensa:"
echo "    xtensa-esp-elf-gcc"
echo "    xtensa-esp-elf-objcopy"
echo ""

echo "  ESP32 RISC-V:"
echo "    riscv32-esp-elf-gcc"
echo "    riscv32-esp-elf-objcopy"
echo ""

echo "  ESP32 emulator:"
echo "    esp-emu"
echo ""

echo "Restart your shell or run:"
echo ""
echo "  source ~/.bashrc"
echo ""
echo "======================================"
