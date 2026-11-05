#define _GNU_SOURCE
#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define IMAGE_SIDE 28u
#define PIXEL_COUNT 784u
#define CLASS_COUNT 10u
#define FILTER_COUNT 8u
#define KERNEL_SIDE 3u
#define CONV_SIDE 26u
#define POOL_SIDE 13u
#define CONV_COUNT (FILTER_COUNT * CONV_SIDE * CONV_SIDE)
#define POOL_COUNT (FILTER_COUNT * POOL_SIDE * POOL_SIDE)
#define CONV_WEIGHT_COUNT (FILTER_COUNT * KERNEL_SIDE * KERNEL_SIDE)
#define DENSE_WEIGHT_COUNT (CLASS_COUNT * POOL_COUNT)
#define DEFAULT_DATASET "train.csv"
#define DEFAULT_MODEL "mnist_cnn_model.bin"
#define DEFAULT_EPOCHS 20u
#define DEFAULT_BATCH_SIZE 256u
#define DEFAULT_LEARNING_RATE 0.01f
#define VALIDATION_DIVISOR 5u
#define CHECK_CL(call) do { cl_int check_cl_status = (call); if (check_cl_status != CL_SUCCESS) { fprintf(stderr, "OpenCL error %d at %s:%d: %s\n", check_cl_status, __FILE__, __LINE__, #call); exit(EXIT_FAILURE); } } while (0)

typedef struct mnist_dataset
{
    float *pixels;
    unsigned char *labels;
    size_t count;
} mnist_dataset_t;

typedef struct mnist_model
{
    float conv_weights[CONV_WEIGHT_COUNT];
    float conv_biases[FILTER_COUNT];
    float dense_weights[DENSE_WEIGHT_COUNT];
    float dense_biases[CLASS_COUNT];
} mnist_model_t;

typedef struct opencl_state
{
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;
    cl_kernel forward_kernel;
    cl_kernel backward_kernel;
    cl_kernel update_kernel;
    cl_mem pixels;
    cl_mem labels;
    cl_mem conv_weights;
    cl_mem conv_biases;
    cl_mem dense_weights;
    cl_mem dense_biases;
    cl_mem conv_activations;
    cl_mem pool_activations;
    cl_mem probabilities;
    cl_mem conv_weight_gradients;
    cl_mem conv_bias_gradients;
    cl_mem dense_weight_gradients;
    cl_mem dense_bias_gradients;
    size_t batch_capacity;
} opencl_state_t;

static const char *kernel_source =
"#define IMAGE_SIDE 28u\n"
"#define CLASS_COUNT 10u\n"
"#define FILTER_COUNT 8u\n"
"#define KERNEL_SIDE 3u\n"
"#define CONV_SIDE 26u\n"
"#define POOL_SIDE 13u\n"
"#define CONV_COUNT (FILTER_COUNT * CONV_SIDE * CONV_SIDE)\n"
"#define POOL_COUNT (FILTER_COUNT * POOL_SIDE * POOL_SIDE)\n"
"#define CONV_WEIGHT_COUNT (FILTER_COUNT * KERNEL_SIDE * KERNEL_SIDE)\n"
"#define DENSE_WEIGHT_COUNT (CLASS_COUNT * POOL_COUNT)\n"
"__kernel void mnist_forward(__global const float *pixels, __global const float *conv_weights, __global const float *conv_biases, __global const float *dense_weights, __global const float *dense_biases, __global float *conv_activations, __global float *pool_activations, __global float *probabilities, uint batch_count)\n"
"{\n"
"    uint sample = get_global_id(0);\n"
"    if (sample >= batch_count) return;\n"
"    __global const float *image = pixels + sample * IMAGE_SIDE * IMAGE_SIDE;\n"
"    __global float *conv = conv_activations + sample * CONV_COUNT;\n"
"    __global float *pool = pool_activations + sample * POOL_COUNT;\n"
"    __global float *prob = probabilities + sample * CLASS_COUNT;\n"
"    for (uint filter = 0u; filter < FILTER_COUNT; filter++)\n"
"    {\n"
"        for (uint y = 0u; y < CONV_SIDE; y++)\n"
"        {\n"
"            for (uint x = 0u; x < CONV_SIDE; x++)\n"
"            {\n"
"                float sum = conv_biases[filter];\n"
"                for (uint ky = 0u; ky < KERNEL_SIDE; ky++)\n"
"                {\n"
"                    for (uint kx = 0u; kx < KERNEL_SIDE; kx++)\n"
"                    {\n"
"                        sum += image[(y + ky) * IMAGE_SIDE + x + kx] * conv_weights[filter * KERNEL_SIDE * KERNEL_SIDE + ky * KERNEL_SIDE + kx];\n"
"                    }\n"
"                }\n"
"                conv[filter * CONV_SIDE * CONV_SIDE + y * CONV_SIDE + x] = fmax(sum, 0.0f);\n"
"            }\n"
"        }\n"
"    }\n"
"    for (uint filter = 0u; filter < FILTER_COUNT; filter++)\n"
"    {\n"
"        for (uint y = 0u; y < POOL_SIDE; y++)\n"
"        {\n"
"            for (uint x = 0u; x < POOL_SIDE; x++)\n"
"            {\n"
"                uint base = filter * CONV_SIDE * CONV_SIDE + (y * 2u) * CONV_SIDE + x * 2u;\n"
"                pool[filter * POOL_SIDE * POOL_SIDE + y * POOL_SIDE + x] = 0.25f * (conv[base] + conv[base + 1u] + conv[base + CONV_SIDE] + conv[base + CONV_SIDE + 1u]);\n"
"            }\n"
"        }\n"
"    }\n"
"    float maximum = -3.402823466e+38f;\n"
"    for (uint output = 0u; output < CLASS_COUNT; output++)\n"
"    {\n"
"        float sum = dense_biases[output];\n"
"        for (uint source = 0u; source < POOL_COUNT; source++) sum += pool[source] * dense_weights[output * POOL_COUNT + source];\n"
"        prob[output] = sum;\n"
"        maximum = fmax(maximum, sum);\n"
"    }\n"
"    float total = 0.0f;\n"
"    for (uint output = 0u; output < CLASS_COUNT; output++)\n"
"    {\n"
"        prob[output] = exp(prob[output] - maximum);\n"
"        total += prob[output];\n"
"    }\n"
"    for (uint output = 0u; output < CLASS_COUNT; output++) prob[output] /= total;\n"
"}\n"
"__kernel void mnist_backward(__global const float *pixels, __global const uchar *labels, __global const float *conv_weights, __global const float *dense_weights, __global const float *conv_activations, __global const float *pool_activations, __global const float *probabilities, __global float *conv_weight_gradients, __global float *conv_bias_gradients, __global float *dense_weight_gradients, __global float *dense_bias_gradients, uint batch_count)\n"
"{\n"
"    uint sample = get_global_id(0);\n"
"    if (sample >= batch_count) return;\n"
"    __global const float *image = pixels + sample * IMAGE_SIDE * IMAGE_SIDE;\n"
"    __global const float *conv = conv_activations + sample * CONV_COUNT;\n"
"    __global const float *pool = pool_activations + sample * POOL_COUNT;\n"
"    __global const float *prob = probabilities + sample * CLASS_COUNT;\n"
"    __global float *cwg = conv_weight_gradients + sample * CONV_WEIGHT_COUNT;\n"
"    __global float *cbg = conv_bias_gradients + sample * FILTER_COUNT;\n"
"    __global float *dwg = dense_weight_gradients + sample * DENSE_WEIGHT_COUNT;\n"
"    __global float *dbg = dense_bias_gradients + sample * CLASS_COUNT;\n"
"    float pool_delta[POOL_COUNT];\n"
"    for (uint source = 0u; source < POOL_COUNT; source++) pool_delta[source] = 0.0f;\n"
"    for (uint output = 0u; output < CLASS_COUNT; output++)\n"
"    {\n"
"        float delta = prob[output] - (labels[sample] == output ? 1.0f : 0.0f);\n"
"        dbg[output] = delta;\n"
"        for (uint source = 0u; source < POOL_COUNT; source++)\n"
"        {\n"
"            dwg[output * POOL_COUNT + source] = delta * pool[source];\n"
"            pool_delta[source] += dense_weights[output * POOL_COUNT + source] * delta;\n"
"        }\n"
"    }\n"
"    for (uint index = 0u; index < CONV_WEIGHT_COUNT; index++) cwg[index] = 0.0f;\n"
"    for (uint filter = 0u; filter < FILTER_COUNT; filter++) cbg[filter] = 0.0f;\n"
"    for (uint filter = 0u; filter < FILTER_COUNT; filter++)\n"
"    {\n"
"        for (uint y = 0u; y < CONV_SIDE; y++)\n"
"        {\n"
"            for (uint x = 0u; x < CONV_SIDE; x++)\n"
"            {\n"
"                uint conv_index = filter * CONV_SIDE * CONV_SIDE + y * CONV_SIDE + x;\n"
"                uint pool_index = filter * POOL_SIDE * POOL_SIDE + (y / 2u) * POOL_SIDE + x / 2u;\n"
"                float delta = conv[conv_index] > 0.0f ? 0.25f * pool_delta[pool_index] : 0.0f;\n"
"                cbg[filter] += delta;\n"
"                for (uint ky = 0u; ky < KERNEL_SIDE; ky++)\n"
"                {\n"
"                    for (uint kx = 0u; kx < KERNEL_SIDE; kx++) cwg[filter * KERNEL_SIDE * KERNEL_SIDE + ky * KERNEL_SIDE + kx] += delta * image[(y + ky) * IMAGE_SIDE + x + kx];\n"
"                }\n"
"            }\n"
"        }\n"
"    }\n"
"}\n"
"__kernel void mnist_update(__global float *parameters, __global const float *gradients, uint parameter_count, uint batch_count, float learning_rate)\n"
"{\n"
"    uint parameter = get_global_id(0);\n"
"    if (parameter >= parameter_count) return;\n"
"    float sum = 0.0f;\n"
"    for (uint sample = 0u; sample < batch_count; sample++) sum += gradients[sample * parameter_count + parameter];\n"
"    parameters[parameter] -= learning_rate * sum / (float)batch_count;\n"
"}\n";

static void *checked_malloc(size_t bytes)
{
    void *memory = malloc(bytes);
    if (memory == NULL)
    {
        fprintf(stderr, "Allocation failed for %zu bytes\n", bytes);
        exit(EXIT_FAILURE);
    }
    return memory;
}

static float random_uniform(uint32_t *state, float minimum, float maximum)
{
    *state = *state * 1664525u + 1013904223u;
    return minimum + (maximum - minimum) * (float)(*state & 0x00ffffffu) / 16777215.0f;
}

static void initialize_model(mnist_model_t *model)
{
    uint32_t state = 0x12345678u;
    float conv_limit = sqrtf(6.0f / 9.0f);
    float dense_limit = sqrtf(6.0f / (float)POOL_COUNT);
    size_t index;
    for (index = 0u; index < CONV_WEIGHT_COUNT; index++) model->conv_weights[index] = random_uniform(&state, -conv_limit, conv_limit);
    for (index = 0u; index < FILTER_COUNT; index++) model->conv_biases[index] = 0.0f;
    for (index = 0u; index < DENSE_WEIGHT_COUNT; index++) model->dense_weights[index] = random_uniform(&state, -dense_limit, dense_limit);
    for (index = 0u; index < CLASS_COUNT; index++) model->dense_biases[index] = 0.0f;
}

static bool parse_csv_row(char *line, unsigned char *label, float *pixels)
{
    char *cursor = line;
    char *end;
    unsigned long parsed_label = strtoul(cursor, &end, 10);
    size_t pixel;
    if (end == cursor || parsed_label >= CLASS_COUNT) return false;
    *label = (unsigned char)parsed_label;
    cursor = end;
    for (pixel = 0u; pixel < PIXEL_COUNT; pixel++)
    {
        unsigned long value;
        if (*cursor != ',') return false;
        cursor++;
        value = strtoul(cursor, &end, 10);
        if (end == cursor || value > 255u) return false;
        pixels[pixel] = (float)value / 255.0f;
        cursor = end;
    }
    return true;
}

static mnist_dataset_t load_dataset(const char *path)
{
    mnist_dataset_t dataset = {0};
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t capacity = 1024u;
    size_t line_capacity = 0u;
    ssize_t length;
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open %s: %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    dataset.pixels = checked_malloc(capacity * PIXEL_COUNT * sizeof(*dataset.pixels));
    dataset.labels = checked_malloc(capacity * sizeof(*dataset.labels));
    length = getline(&line, &line_capacity, file);
    if (length <= 0 || strncmp(line, "label,pixel0", 12u) != 0)
    {
        fprintf(stderr, "Expected Kaggle Digit Recognizer header label,pixel0,...,pixel783\n");
        exit(EXIT_FAILURE);
    }
    while ((length = getline(&line, &line_capacity, file)) > 0)
    {
        if (dataset.count == capacity)
        {
            capacity *= 2u;
            dataset.pixels = realloc(dataset.pixels, capacity * PIXEL_COUNT * sizeof(*dataset.pixels));
            dataset.labels = realloc(dataset.labels, capacity * sizeof(*dataset.labels));
            if (dataset.pixels == NULL || dataset.labels == NULL)
            {
                fprintf(stderr, "Dataset reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
        if (!parse_csv_row(line, &dataset.labels[dataset.count], dataset.pixels + dataset.count * PIXEL_COUNT))
        {
            fprintf(stderr, "Invalid CSV row %zu\n", dataset.count + 2u);
            exit(EXIT_FAILURE);
        }
        dataset.count++;
    }
    free(line);
    fclose(file);
    if (dataset.count < 100u)
    {
        fprintf(stderr, "Dataset contains too few rows: %zu\n", dataset.count);
        exit(EXIT_FAILURE);
    }
    return dataset;
}

static void release_dataset(mnist_dataset_t *dataset)
{
    free(dataset->pixels);
    free(dataset->labels);
    memset(dataset, 0, sizeof(*dataset));
}

static void print_build_log(cl_program program, cl_device_id device)
{
    size_t size = 0u;
    CHECK_CL(clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0u, NULL, &size));
    if (size > 1u)
    {
        char *log = checked_malloc(size);
        CHECK_CL(clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, size, log, NULL));
        fprintf(stderr, "%s\n", log);
        free(log);
    }
}

static cl_device_id select_gpu(cl_platform_id *selected_platform)
{
    cl_uint platform_count = 0u;
    cl_platform_id *platforms;
    cl_uint platform_index;
    CHECK_CL(clGetPlatformIDs(0u, NULL, &platform_count));
    if (platform_count == 0u)
    {
        fprintf(stderr, "No OpenCL platforms found\n");
        exit(EXIT_FAILURE);
    }
    platforms = checked_malloc(platform_count * sizeof(*platforms));
    CHECK_CL(clGetPlatformIDs(platform_count, platforms, NULL));
    for (platform_index = 0u; platform_index < platform_count; platform_index++)
    {
        cl_device_id device;
        cl_int status = clGetDeviceIDs(platforms[platform_index], CL_DEVICE_TYPE_GPU, 1u, &device, NULL);
        if (status == CL_SUCCESS)
        {
            char name[256];
            CHECK_CL(clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(name), name, NULL));
            *selected_platform = platforms[platform_index];
            printf("Selected OpenCL GPU: %s\n", name);
            free(platforms);
            return device;
        }
    }
    free(platforms);
    fprintf(stderr, "No OpenCL GPU found; CPU fallback is forbidden\n");
    exit(EXIT_FAILURE);
}

static cl_mem make_buffer(opencl_state_t *state, cl_mem_flags flags, size_t bytes)
{
    cl_int status;
    cl_mem buffer = clCreateBuffer(state->context, flags, bytes, NULL, &status);
    CHECK_CL(status);
    return buffer;
}

static void initialize_opencl(opencl_state_t *state, const mnist_model_t *model, size_t batch_capacity)
{
    cl_int status;
    size_t source_length = strlen(kernel_source);
    memset(state, 0, sizeof(*state));
    state->batch_capacity = batch_capacity;
    state->device = select_gpu(&state->platform);
    state->context = clCreateContext(NULL, 1u, &state->device, NULL, NULL, &status);
    CHECK_CL(status);
    state->queue = clCreateCommandQueue(state->context, state->device, 0u, &status);
    CHECK_CL(status);
    state->program = clCreateProgramWithSource(state->context, 1u, &kernel_source, &source_length, &status);
    CHECK_CL(status);
    status = clBuildProgram(state->program, 1u, &state->device, "-cl-std=CL1.2", NULL, NULL);
    if (status != CL_SUCCESS)
    {
        print_build_log(state->program, state->device);
        CHECK_CL(status);
    }
    state->forward_kernel = clCreateKernel(state->program, "mnist_forward", &status);
    CHECK_CL(status);
    state->backward_kernel = clCreateKernel(state->program, "mnist_backward", &status);
    CHECK_CL(status);
    state->update_kernel = clCreateKernel(state->program, "mnist_update", &status);
    CHECK_CL(status);
    state->pixels = make_buffer(state, CL_MEM_READ_ONLY, batch_capacity * PIXEL_COUNT * sizeof(float));
    state->labels = make_buffer(state, CL_MEM_READ_ONLY, batch_capacity * sizeof(unsigned char));
    state->conv_weights = make_buffer(state, CL_MEM_READ_WRITE, sizeof(model->conv_weights));
    state->conv_biases = make_buffer(state, CL_MEM_READ_WRITE, sizeof(model->conv_biases));
    state->dense_weights = make_buffer(state, CL_MEM_READ_WRITE, sizeof(model->dense_weights));
    state->dense_biases = make_buffer(state, CL_MEM_READ_WRITE, sizeof(model->dense_biases));
    state->conv_activations = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * CONV_COUNT * sizeof(float));
    state->pool_activations = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * POOL_COUNT * sizeof(float));
    state->probabilities = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * CLASS_COUNT * sizeof(float));
    state->conv_weight_gradients = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * CONV_WEIGHT_COUNT * sizeof(float));
    state->conv_bias_gradients = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * FILTER_COUNT * sizeof(float));
    state->dense_weight_gradients = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * DENSE_WEIGHT_COUNT * sizeof(float));
    state->dense_bias_gradients = make_buffer(state, CL_MEM_READ_WRITE, batch_capacity * CLASS_COUNT * sizeof(float));
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->conv_weights, CL_TRUE, 0u, sizeof(model->conv_weights), model->conv_weights, 0u, NULL, NULL));
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->conv_biases, CL_TRUE, 0u, sizeof(model->conv_biases), model->conv_biases, 0u, NULL, NULL));
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->dense_weights, CL_TRUE, 0u, sizeof(model->dense_weights), model->dense_weights, 0u, NULL, NULL));
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->dense_biases, CL_TRUE, 0u, sizeof(model->dense_biases), model->dense_biases, 0u, NULL, NULL));
}

static void set_forward_arguments(opencl_state_t *state, cl_uint batch_count)
{
    CHECK_CL(clSetKernelArg(state->forward_kernel, 0u, sizeof(cl_mem), &state->pixels));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 1u, sizeof(cl_mem), &state->conv_weights));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 2u, sizeof(cl_mem), &state->conv_biases));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 3u, sizeof(cl_mem), &state->dense_weights));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 4u, sizeof(cl_mem), &state->dense_biases));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 5u, sizeof(cl_mem), &state->conv_activations));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 6u, sizeof(cl_mem), &state->pool_activations));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 7u, sizeof(cl_mem), &state->probabilities));
    CHECK_CL(clSetKernelArg(state->forward_kernel, 8u, sizeof(cl_uint), &batch_count));
}

static void set_backward_arguments(opencl_state_t *state, cl_uint batch_count)
{
    CHECK_CL(clSetKernelArg(state->backward_kernel, 0u, sizeof(cl_mem), &state->pixels));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 1u, sizeof(cl_mem), &state->labels));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 2u, sizeof(cl_mem), &state->conv_weights));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 3u, sizeof(cl_mem), &state->dense_weights));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 4u, sizeof(cl_mem), &state->conv_activations));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 5u, sizeof(cl_mem), &state->pool_activations));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 6u, sizeof(cl_mem), &state->probabilities));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 7u, sizeof(cl_mem), &state->conv_weight_gradients));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 8u, sizeof(cl_mem), &state->conv_bias_gradients));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 9u, sizeof(cl_mem), &state->dense_weight_gradients));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 10u, sizeof(cl_mem), &state->dense_bias_gradients));
    CHECK_CL(clSetKernelArg(state->backward_kernel, 11u, sizeof(cl_uint), &batch_count));
}

static void update_parameters(opencl_state_t *state, cl_mem parameters, cl_mem gradients, cl_uint parameter_count, cl_uint batch_count, float learning_rate)
{
    size_t global_size = parameter_count;
    CHECK_CL(clSetKernelArg(state->update_kernel, 0u, sizeof(cl_mem), &parameters));
    CHECK_CL(clSetKernelArg(state->update_kernel, 1u, sizeof(cl_mem), &gradients));
    CHECK_CL(clSetKernelArg(state->update_kernel, 2u, sizeof(cl_uint), &parameter_count));
    CHECK_CL(clSetKernelArg(state->update_kernel, 3u, sizeof(cl_uint), &batch_count));
    CHECK_CL(clSetKernelArg(state->update_kernel, 4u, sizeof(float), &learning_rate));
    CHECK_CL(clEnqueueNDRangeKernel(state->queue, state->update_kernel, 1u, NULL, &global_size, NULL, 0u, NULL, NULL));
}

static void train_batch(opencl_state_t *state, const float *pixels, const unsigned char *labels, size_t batch_count, float learning_rate)
{
    cl_uint count = (cl_uint)batch_count;
    size_t global_size = batch_count;
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->pixels, CL_FALSE, 0u, batch_count * PIXEL_COUNT * sizeof(float), pixels, 0u, NULL, NULL));
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->labels, CL_FALSE, 0u, batch_count * sizeof(unsigned char), labels, 0u, NULL, NULL));
    set_forward_arguments(state, count);
    CHECK_CL(clEnqueueNDRangeKernel(state->queue, state->forward_kernel, 1u, NULL, &global_size, NULL, 0u, NULL, NULL));
    set_backward_arguments(state, count);
    CHECK_CL(clEnqueueNDRangeKernel(state->queue, state->backward_kernel, 1u, NULL, &global_size, NULL, 0u, NULL, NULL));
    update_parameters(state, state->conv_weights, state->conv_weight_gradients, CONV_WEIGHT_COUNT, count, learning_rate);
    update_parameters(state, state->conv_biases, state->conv_bias_gradients, FILTER_COUNT, count, learning_rate);
    update_parameters(state, state->dense_weights, state->dense_weight_gradients, DENSE_WEIGHT_COUNT, count, learning_rate);
    update_parameters(state, state->dense_biases, state->dense_bias_gradients, CLASS_COUNT, count, learning_rate);
    CHECK_CL(clFinish(state->queue));
}

static void run_forward(opencl_state_t *state, const float *pixels, size_t batch_count, float *probabilities)
{
    cl_uint count = (cl_uint)batch_count;
    size_t global_size = batch_count;
    CHECK_CL(clEnqueueWriteBuffer(state->queue, state->pixels, CL_FALSE, 0u, batch_count * PIXEL_COUNT * sizeof(float), pixels, 0u, NULL, NULL));
    set_forward_arguments(state, count);
    CHECK_CL(clEnqueueNDRangeKernel(state->queue, state->forward_kernel, 1u, NULL, &global_size, NULL, 0u, NULL, NULL));
    CHECK_CL(clEnqueueReadBuffer(state->queue, state->probabilities, CL_TRUE, 0u, batch_count * CLASS_COUNT * sizeof(float), probabilities, 0u, NULL, NULL));
}

static void evaluate(opencl_state_t *state, const mnist_dataset_t *dataset, size_t start, size_t count, size_t batch_size, double *loss, double *accuracy)
{
    float *probabilities = checked_malloc(batch_size * CLASS_COUNT * sizeof(*probabilities));
    size_t offset;
    size_t correct = 0u;
    double total_loss = 0.0;
    for (offset = 0u; offset < count; offset += batch_size)
    {
        size_t current = count - offset < batch_size ? count - offset : batch_size;
        size_t sample;
        run_forward(state, dataset->pixels + (start + offset) * PIXEL_COUNT, current, probabilities);
        for (sample = 0u; sample < current; sample++)
        {
            unsigned int predicted = 0u;
            unsigned int output;
            unsigned char label = dataset->labels[start + offset + sample];
            float best = probabilities[sample * CLASS_COUNT];
            float target_probability = probabilities[sample * CLASS_COUNT + label];
            if (target_probability < 1.0e-20f) target_probability = 1.0e-20f;
            total_loss -= log((double)target_probability);
            for (output = 1u; output < CLASS_COUNT; output++)
            {
                float value = probabilities[sample * CLASS_COUNT + output];
                if (value > best)
                {
                    best = value;
                    predicted = output;
                }
            }
            if (predicted == label) correct++;
        }
    }
    free(probabilities);
    *loss = total_loss / (double)count;
    *accuracy = 100.0 * (double)correct / (double)count;
}

static void read_model(opencl_state_t *state, mnist_model_t *model)
{
    CHECK_CL(clEnqueueReadBuffer(state->queue, state->conv_weights, CL_TRUE, 0u, sizeof(model->conv_weights), model->conv_weights, 0u, NULL, NULL));
    CHECK_CL(clEnqueueReadBuffer(state->queue, state->conv_biases, CL_TRUE, 0u, sizeof(model->conv_biases), model->conv_biases, 0u, NULL, NULL));
    CHECK_CL(clEnqueueReadBuffer(state->queue, state->dense_weights, CL_TRUE, 0u, sizeof(model->dense_weights), model->dense_weights, 0u, NULL, NULL));
    CHECK_CL(clEnqueueReadBuffer(state->queue, state->dense_biases, CL_TRUE, 0u, sizeof(model->dense_biases), model->dense_biases, 0u, NULL, NULL));
}

static void save_model(const char *path, const mnist_model_t *model)
{
    FILE *file = fopen(path, "wb");
    const char magic[8] = {'F','N','M','N','I','S','T','1'};
    if (file == NULL)
    {
        fprintf(stderr, "Cannot create %s: %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (fwrite(magic, sizeof(magic), 1u, file) != 1u || fwrite(model, sizeof(*model), 1u, file) != 1u)
    {
        fprintf(stderr, "Cannot write %s\n", path);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}


static void release_opencl(opencl_state_t *state);

static bool load_model(const char *path, mnist_model_t *model)
{
    FILE *file = fopen(path, "rb");
    char magic[8];
    const char expected[8] = {'F','N','M','N','I','S','T','1'};

    if (file == NULL)
    {
        fprintf(stderr, "Cannot open model %s: %s\n", path, strerror(errno));
        return false;
    }

    if (fread(magic, sizeof(magic), 1u, file) != 1u || memcmp(magic, expected, sizeof(expected)) != 0)
    {
        fprintf(stderr, "Invalid or incompatible model file: %s\n", path);
        fclose(file);
        return false;
    }

    if (fread(model, sizeof(*model), 1u, file) != 1u)
    {
        fprintf(stderr, "Cannot read model parameters: %s\n", path);
        fclose(file);
        return false;
    }

    if (fgetc(file) != EOF)
    {
        fprintf(stderr, "Model file has unexpected trailing data: %s\n", path);
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}

static bool parse_unlabeled_csv_row(char *line, float *pixels)
{
    char *cursor = line;
    char *end;
    size_t pixel;

    for (pixel = 0u; pixel < PIXEL_COUNT; pixel++)
    {
        unsigned long value = strtoul(cursor, &end, 10);

        if (end == cursor || value > 255u)
        {
            return false;
        }

        pixels[pixel] = (float)value / 255.0f;
        cursor = end;

        if (pixel + 1u < PIXEL_COUNT)
        {
            if (*cursor != ',')
            {
                return false;
            }

            cursor++;
        }
    }

    return *cursor == '\0' || *cursor == '\n' || *cursor == '\r';
}

static mnist_dataset_t load_unlabeled_dataset(const char *path)
{
    mnist_dataset_t dataset = {0};
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t capacity = 1024u;
    size_t line_capacity = 0u;
    ssize_t length;

    if (file == NULL)
    {
        fprintf(stderr, "Cannot open %s: %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    dataset.pixels = checked_malloc(capacity * PIXEL_COUNT * sizeof(*dataset.pixels));
    length = getline(&line, &line_capacity, file);

    if (length <= 0 || strncmp(line, "pixel0,pixel1", 13u) != 0)
    {
        fprintf(stderr, "Expected Kaggle test header pixel0,pixel1,...,pixel783\n");
        free(line);
        fclose(file);
        free(dataset.pixels);
        exit(EXIT_FAILURE);
    }

    while ((length = getline(&line, &line_capacity, file)) > 0)
    {
        if (dataset.count == capacity)
        {
            float *resized;
            capacity *= 2u;
            resized = realloc(dataset.pixels, capacity * PIXEL_COUNT * sizeof(*dataset.pixels));

            if (resized == NULL)
            {
                fprintf(stderr, "Unlabeled dataset reallocation failed\n");
                free(line);
                fclose(file);
                free(dataset.pixels);
                exit(EXIT_FAILURE);
            }

            dataset.pixels = resized;
        }

        if (!parse_unlabeled_csv_row(line, dataset.pixels + dataset.count * PIXEL_COUNT))
        {
            fprintf(stderr, "Invalid unlabeled CSV row %zu\n", dataset.count + 2u);
            free(line);
            fclose(file);
            free(dataset.pixels);
            exit(EXIT_FAILURE);
        }

        dataset.count++;
    }

    free(line);
    fclose(file);

    if (dataset.count == 0u)
    {
        fprintf(stderr, "Unlabeled dataset contains no rows: %s\n", path);
        free(dataset.pixels);
        exit(EXIT_FAILURE);
    }

    return dataset;
}

static unsigned int predicted_class(const float *probabilities)
{
    unsigned int best_class = 0u;
    unsigned int output;

    for (output = 1u; output < CLASS_COUNT; output++)
    {
        if (probabilities[output] > probabilities[best_class])
        {
            best_class = output;
        }
    }

    return best_class;
}

static int run_training(const char *dataset_path, unsigned int epochs, unsigned int batch_size, float learning_rate)
{
    mnist_dataset_t dataset;
    mnist_model_t model;
    opencl_state_t opencl;
    size_t validation_count;
    size_t training_count;
    unsigned int epoch;
    double best_accuracy = -1.0;

    dataset = load_dataset(dataset_path);
    validation_count = dataset.count / VALIDATION_DIVISOR;
    training_count = dataset.count - validation_count;
    initialize_model(&model);
    initialize_opencl(&opencl, &model, batch_size);
    printf("Kaggle rows: %zu\n", dataset.count);
    printf("Training rows: %zu\n", training_count);
    printf("Validation rows: %zu\n", validation_count);
    printf("Topology: 28x28 -> conv 8x3x3 -> avgpool 2x2 -> softmax 10\n");
    printf("Epochs: %u\n", epochs);
    printf("Batch size: %u\n", batch_size);
    printf("Learning rate: %.9f\n", learning_rate);

    for (epoch = 1u; epoch <= epochs; epoch++)
    {
        size_t offset;
        double validation_loss;
        double validation_accuracy;

        for (offset = 0u; offset < training_count; offset += batch_size)
        {
            size_t current = training_count - offset < batch_size ? training_count - offset : batch_size;
            train_batch(&opencl, dataset.pixels + offset * PIXEL_COUNT, dataset.labels + offset, current, learning_rate);
        }

        evaluate(&opencl, &dataset, training_count, validation_count, batch_size, &validation_loss, &validation_accuracy);
        printf("Epoch %3u validation cross-entropy %.8f accuracy %.4f%%\n", epoch, validation_loss, validation_accuracy);

        if (validation_accuracy > best_accuracy)
        {
            best_accuracy = validation_accuracy;
            read_model(&opencl, &model);
            save_model(DEFAULT_MODEL, &model);
            printf("Saved best model: %s\n", DEFAULT_MODEL);
        }
    }

    printf("Best validation accuracy: %.4f%%\n", best_accuracy);
    printf("Model: %s\n", DEFAULT_MODEL);
    release_opencl(&opencl);
    release_dataset(&dataset);
    return EXIT_SUCCESS;
}

static int run_validation(const char *dataset_path, const char *model_path, size_t batch_size)
{
    mnist_dataset_t dataset = load_dataset(dataset_path);
    mnist_model_t model;
    opencl_state_t opencl;
    size_t validation_count = dataset.count / VALIDATION_DIVISOR;
    size_t validation_start = dataset.count - validation_count;
    double loss;
    double accuracy;

    if (!load_model(model_path, &model))
    {
        release_dataset(&dataset);
        return EXIT_FAILURE;
    }

    initialize_opencl(&opencl, &model, batch_size);
    evaluate(&opencl, &dataset, validation_start, validation_count, batch_size, &loss, &accuracy);
    printf("Loaded model: %s\n", model_path);
    printf("Held-out rows: %zu through %zu\n", validation_start, dataset.count - 1u);
    printf("Validation cross-entropy: %.8f\n", loss);
    printf("Validation accuracy: %.4f%%\n", accuracy);
    release_opencl(&opencl);
    release_dataset(&dataset);
    return EXIT_SUCCESS;
}

static int run_submission(const char *dataset_path, const char *model_path, const char *output_path, size_t batch_size)
{
    mnist_dataset_t dataset = load_unlabeled_dataset(dataset_path);
    mnist_model_t model;
    opencl_state_t opencl;
    float *probabilities = checked_malloc(batch_size * CLASS_COUNT * sizeof(*probabilities));
    FILE *output;
    size_t offset;

    if (!load_model(model_path, &model))
    {
        release_dataset(&dataset);
        free(probabilities);
        return EXIT_FAILURE;
    }

    output = fopen(output_path, "w");

    if (output == NULL)
    {
        fprintf(stderr, "Cannot create %s: %s\n", output_path, strerror(errno));
        release_dataset(&dataset);
        free(probabilities);
        return EXIT_FAILURE;
    }

    initialize_opencl(&opencl, &model, batch_size);
    fprintf(output, "ImageId,Label\n");

    for (offset = 0u; offset < dataset.count; offset += batch_size)
    {
        size_t current = dataset.count - offset < batch_size ? dataset.count - offset : batch_size;
        size_t sample;
        run_forward(&opencl, dataset.pixels + offset * PIXEL_COUNT, current, probabilities);

        for (sample = 0u; sample < current; sample++)
        {
            fprintf(output, "%zu,%u\n", offset + sample + 1u, predicted_class(probabilities + sample * CLASS_COUNT));
        }
    }

    fclose(output);
    printf("Loaded model: %s\n", model_path);
    printf("Predicted test images: %zu\n", dataset.count);
    printf("Kaggle submission: %s\n", output_path);
    release_opencl(&opencl);
    release_dataset(&dataset);
    free(probabilities);
    return EXIT_SUCCESS;
}

static int run_prediction(const char *dataset_path, const char *model_path, size_t image_id)
{
    mnist_dataset_t dataset = load_unlabeled_dataset(dataset_path);
    mnist_model_t model;
    opencl_state_t opencl;
    float probabilities[CLASS_COUNT];
    unsigned int output;
    unsigned int prediction;

    if (image_id == 0u || image_id > dataset.count)
    {
        fprintf(stderr, "ImageId must be between 1 and %zu\n", dataset.count);
        release_dataset(&dataset);
        return EXIT_FAILURE;
    }

    if (!load_model(model_path, &model))
    {
        release_dataset(&dataset);
        return EXIT_FAILURE;
    }

    initialize_opencl(&opencl, &model, 1u);
    run_forward(&opencl, dataset.pixels + (image_id - 1u) * PIXEL_COUNT, 1u, probabilities);
    prediction = predicted_class(probabilities);
    printf("Loaded model: %s\n", model_path);
    printf("ImageId: %zu\n", image_id);

    for (output = 0u; output < CLASS_COUNT; output++)
    {
        printf("Digit %u probability: %.8f\n", output, probabilities[output]);
    }

    printf("Predicted digit: %u\n", prediction);
    printf("Confidence: %.4f%%\n", probabilities[prediction] * 100.0f);
    release_opencl(&opencl);
    release_dataset(&dataset);
    return EXIT_SUCCESS;
}

static void print_usage(const char *program)
{
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "  %s train <train.csv> [epochs] [batch_size] [learning_rate]\n", program);
    fprintf(stderr, "  %s validate <train.csv> <model.bin> [batch_size]\n", program);
    fprintf(stderr, "  %s submit <test.csv> <model.bin> <submission.csv> [batch_size]\n", program);
    fprintf(stderr, "  %s predict <test.csv> <model.bin> <ImageId>\n", program);
}

static void release_opencl(opencl_state_t *state)
{
    if (state->dense_bias_gradients) clReleaseMemObject(state->dense_bias_gradients);
    if (state->dense_weight_gradients) clReleaseMemObject(state->dense_weight_gradients);
    if (state->conv_bias_gradients) clReleaseMemObject(state->conv_bias_gradients);
    if (state->conv_weight_gradients) clReleaseMemObject(state->conv_weight_gradients);
    if (state->probabilities) clReleaseMemObject(state->probabilities);
    if (state->pool_activations) clReleaseMemObject(state->pool_activations);
    if (state->conv_activations) clReleaseMemObject(state->conv_activations);
    if (state->dense_biases) clReleaseMemObject(state->dense_biases);
    if (state->dense_weights) clReleaseMemObject(state->dense_weights);
    if (state->conv_biases) clReleaseMemObject(state->conv_biases);
    if (state->conv_weights) clReleaseMemObject(state->conv_weights);
    if (state->labels) clReleaseMemObject(state->labels);
    if (state->pixels) clReleaseMemObject(state->pixels);
    if (state->update_kernel) clReleaseKernel(state->update_kernel);
    if (state->backward_kernel) clReleaseKernel(state->backward_kernel);
    if (state->forward_kernel) clReleaseKernel(state->forward_kernel);
    if (state->program) clReleaseProgram(state->program);
    if (state->queue) clReleaseCommandQueue(state->queue);
    if (state->context) clReleaseContext(state->context);
    memset(state, 0, sizeof(*state));
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "train") == 0)
    {
        const char *dataset_path;
        unsigned int epochs;
        unsigned int batch_size;
        float learning_rate;

        if (argc < 3 || argc > 6)
        {
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }

        dataset_path = argv[2];
        epochs = argc > 3 ? (unsigned int)strtoul(argv[3], NULL, 10) : DEFAULT_EPOCHS;
        batch_size = argc > 4 ? (unsigned int)strtoul(argv[4], NULL, 10) : DEFAULT_BATCH_SIZE;
        learning_rate = argc > 5 ? strtof(argv[5], NULL) : DEFAULT_LEARNING_RATE;

        if (epochs == 0u || batch_size == 0u || learning_rate <= 0.0f)
        {
            fprintf(stderr, "Training arguments must be positive\n");
            return EXIT_FAILURE;
        }

        return run_training(dataset_path, epochs, batch_size, learning_rate);
    }

    if (strcmp(argv[1], "validate") == 0)
    {
        size_t batch_size;

        if (argc < 4 || argc > 5)
        {
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }

        batch_size = argc > 4 ? (size_t)strtoull(argv[4], NULL, 10) : DEFAULT_BATCH_SIZE;

        if (batch_size == 0u)
        {
            fprintf(stderr, "Batch size must be positive\n");
            return EXIT_FAILURE;
        }

        return run_validation(argv[2], argv[3], batch_size);
    }

    if (strcmp(argv[1], "submit") == 0)
    {
        size_t batch_size;

        if (argc < 5 || argc > 6)
        {
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }

        batch_size = argc > 5 ? (size_t)strtoull(argv[5], NULL, 10) : DEFAULT_BATCH_SIZE;

        if (batch_size == 0u)
        {
            fprintf(stderr, "Batch size must be positive\n");
            return EXIT_FAILURE;
        }

        return run_submission(argv[2], argv[3], argv[4], batch_size);
    }

    if (strcmp(argv[1], "predict") == 0)
    {
        size_t image_id;

        if (argc != 5)
        {
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }

        image_id = (size_t)strtoull(argv[4], NULL, 10);
        return run_prediction(argv[2], argv[3], image_id);
    }

    print_usage(argv[0]);
    return EXIT_FAILURE;
}
