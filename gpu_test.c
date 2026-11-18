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
