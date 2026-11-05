#!/usr/bin/env bash
set -Eeuo pipefail

# Intel HD Graphics 620 - Ubuntu / WSL2 OpenCL setup
# Runtime: Intel OpenCL Legacy 24.35
# Compute API: OpenCL

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

pass() { echo -e "${GREEN}[PASS]${NC} $*"; }
fail() { echo -e "${RED}[FAIL]${NC} $*" >&2; exit 1; }
info() { echo -e "${YELLOW}[INFO]${NC} $*"; }

echo "======================================"
echo " Intel OpenCL GPU Setup for Ubuntu"
echo "======================================"

# 1. Environment checks
[[ -f /etc/os-release ]] || fail "Cannot identify Linux distribution."
source /etc/os-release

info "Distribution: $PRETTY_NAME"
info "Kernel: $(uname -r)"

if ! grep -qi microsoft /proc/version; then
    info "Not running under WSL. Continuing anyway."
fi

[[ -e /dev/dxg ]] || info "/dev/dxg not found."
[[ -e /dev/dri/renderD128 ]] || info "DRM render node not found."

# 2. Remove Mesa Rusticl OpenCL only
if dpkg -s mesa-opencl-icd >/dev/null 2>&1; then
    info "Removing Mesa Rusticl OpenCL..."
    sudo apt-get remove -y mesa-opencl-icd
else
    pass "Mesa OpenCL package already absent."
fi

# 3. Install Intel OpenCL runtime and development tools
info "Updating package lists..."
sudo apt-get update

info "Installing Intel legacy OpenCL runtime..."
sudo apt-get install -y \
    intel-opencl-icd-legacy \
    ocl-icd-opencl-dev \
    clinfo \
    build-essential\
    time\
    cdecl

pass "Packages installed."

# 4. Verify Intel ICD
ICD="/etc/OpenCL/vendors/intel_legacy1.icd"

if [[ ! -f "$ICD" ]]; then
    echo "Available ICD files:"
    ls -la /etc/OpenCL/vendors/ || true
    fail "Intel legacy ICD file not found."
fi

pass "Intel ICD registered: $ICD"
cat "$ICD"

# 5. Verify GPU detection
info "Checking OpenCL platforms and devices..."
clinfo -l

DEVICE_INFO=$(clinfo 2>/dev/null || true)

if ! grep -q "Intel(R) Graphics \[0x5916\]" <<< "$DEVICE_INFO"; then
    echo "$DEVICE_INFO" | grep -E \
        'Platform Name|Device Name|Device Vendor|Driver Version' || true
    fail "Intel HD Graphics 620 was not detected."
fi

pass "Intel HD Graphics 620 detected."

# 6. Generate OpenCL test program
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
    clGetDeviceInfo(device, CL_DEVICE_NAME,
                    sizeof(name), name, NULL);

    printf("Selected GPU: %s\n", name);

    cl_context context = clCreateContext(
        NULL, 1, &device, NULL, NULL, &err);
    CHECK(err, "clCreateContext");

    cl_command_queue queue =
        clCreateCommandQueue(context, device, 0, &err);
    CHECK(err, "clCreateCommandQueue");

    const char *source =
        "__kernel void add("
        "__global const float *a,"
        "__global const float *b,"
        "__global float *c) {"
        "size_t i = get_global_id(0);"
        "c[i] = a[i] + b[i];"
        "}";

    cl_program program = clCreateProgramWithSource(
        context, 1, &source, NULL, &err);
    CHECK(err, "clCreateProgramWithSource");

    err = clBuildProgram(program, 1, &device, NULL, NULL, NULL);

    if (err != CL_SUCCESS) {
        size_t size = 0;
        clGetProgramBuildInfo(program, device,
            CL_PROGRAM_BUILD_LOG, 0, NULL, &size);

        char *log = calloc(size + 1, 1);
        if (log) {
            clGetProgramBuildInfo(program, device,
                CL_PROGRAM_BUILD_LOG, size, log, NULL);
            fprintf(stderr, "Build log:\n%s\n", log);
            free(log);
        }
        fprintf(stderr, "Kernel compilation failed: %d\n", err);
        return 1;
    }

    float a[N], b[N], c[N];

    for (int i = 0; i < N; i++) {
        a[i] = (float)i;
        b[i] = (float)(i * 2);
    }

    cl_mem A = clCreateBuffer(context,
        CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
        sizeof(a), a, &err);
    CHECK(err, "Buffer A");

    cl_mem B = clCreateBuffer(context,
        CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
        sizeof(b), b, &err);
    CHECK(err, "Buffer B");

    cl_mem C = clCreateBuffer(context,
        CL_MEM_WRITE_ONLY, sizeof(c), NULL, &err);
    CHECK(err, "Buffer C");

    cl_kernel kernel = clCreateKernel(program, "add", &err);
    CHECK(err, "clCreateKernel");

    CHECK(clSetKernelArg(kernel, 0, sizeof(A), &A), "Argument A");
    CHECK(clSetKernelArg(kernel, 1, sizeof(B), &B), "Argument B");
    CHECK(clSetKernelArg(kernel, 2, sizeof(C), &C), "Argument C");

    size_t global = N;

    err = clEnqueueNDRangeKernel(
        queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
    CHECK(err, "Kernel execution");

    err = clEnqueueReadBuffer(
        queue, C, CL_TRUE, 0, sizeof(c), c, 0, NULL, NULL);
    CHECK(err, "Readback");

    int correct = 1;

    for (int i = 0; i < N; i++) {
        if (fabsf(c[i] - (a[i] + b[i])) > 0.0001f) {
            correct = 0;
            fprintf(stderr, "Mismatch at %d: %f\n", i, c[i]);
            break;
        }
    }

    printf("Test: %d elements\n", N);
    printf("Example: %.1f + %.1f = %.1f\n",
           a[100], b[100], c[100]);

    clReleaseKernel(kernel);
    clReleaseMemObject(A);
    clReleaseMemObject(B);
    clReleaseMemObject(C);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    if (!correct) {
        fprintf(stderr, "GPU computation FAILED.\n");
        return 1;
    }

    printf("GPU computation PASSED.\n");
    return 0;
}
EOF

pass "Generated gpu_test.c"

# 7. Compile
info "Compiling OpenCL test..."
gcc -O2 gpu_test.c -o gpu_test -lOpenCL

pass "Compilation successful."

# 8. Execute
info "Executing GPU kernel..."
./gpu_test

pass "Intel OpenCL setup and computation verified."

echo "======================================"
echo " ALL CHECKS PASSED"
echo "======================================"