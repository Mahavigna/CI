/* fuzzy_neuron_anfis_opencl_system.c
 * Maintainable fixed-premise ANFIS/fuzzy-neuron demo.
 *
 * The CPU graph is the semantic source of truth:
 *   fuzzy.h memberships -> RULE-backed rule evaluators -> normalized strengths
 *   -> trainable first-order Sugeno neurons -> weighted output.
 *
 * OpenCL receives flattened inputs, normalized rule strengths and parameters.
 * It never contains a second hard-coded copy of the fuzzy rules.
 */
#define CL_TARGET_OPENCL_VERSION 120
#define FUZZY_MAX_RULES 32u
#define FUZZY_MAX_VALUES 16u
#define FUZZY_IMPLEMENTATION
#include "fuzzy.h"
#include <CL/cl.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAW_INPUTS 3u
#define OUTPUTS 1u
#define CONSEQUENT_PARAMETERS (RAW_INPUTS + 1u)
#define BATCH_SIZE 4096u
#define EPOCHS 1000u
#define LEARNING_RATE 0.005f
#define TARGET_SCALE 255.0f
#define TEST_MODULO 5u

FUZZY_VAR(temperature_low, FUZZY_SHAPE_RAMP, 1.0f, 15.0f, 40.0f, false)
FUZZY_VAR(temperature_high, FUZZY_SHAPE_RAMP, 1.0f, 35.0f, 75.0f, true)
FUZZY_VAR(load_low, FUZZY_SHAPE_RAMP, 1.0f, 20.0f, 50.0f, false)
FUZZY_VAR(load_high, FUZZY_SHAPE_RAMP, 1.0f, 45.0f, 85.0f, true)
FUZZY_VAR(vibration_low, FUZZY_SHAPE_RAMP, 1.0f, 1.0f, 4.0f, false)
FUZZY_VAR(vibration_high, FUZZY_SHAPE_RAMP, 1.0f, 3.0f, 8.0f, true)

typedef float (*fuzzy_rule_evaluator_t)(const float inputs[]);

typedef struct sample
{
    float x[RAW_INPUTS];
    float target;
}
sample_t;

typedef struct fuzzy_neuron fuzzy_neuron_t;

typedef struct fuzzy_neuron_connection
{
    fuzzy_neuron_t *source;
    float weight;
    float gradient;
}
fuzzy_neuron_connection_t;

struct fuzzy_neuron
{
    const char *name;
    fuzzy_rule_evaluator_t rule;
    fuzzy_neuron_connection_t *connections;
    size_t connection_count;
    float *parameters;
    size_t parameter_count;
    float firing_strength;
    float normalized_strength;
    float weighted_sum;
    float output;
    float delta;
};

typedef enum fuzzy_neuron_layer_kind
{
    FUZZY_NEURON_LAYER_INPUT,
    FUZZY_NEURON_LAYER_RULE,
    FUZZY_NEURON_LAYER_OUTPUT
}
fuzzy_neuron_layer_kind_t;

typedef struct fuzzy_neuron_layer
{
    fuzzy_neuron_layer_kind_t kind;
    fuzzy_neuron_t *neurons;
    size_t count;
    struct fuzzy_neuron_layer *previous;
    struct fuzzy_neuron_layer *next;
}
fuzzy_neuron_layer_t;

typedef struct fuzzy_neuron_opencl
{
    cl_platform_id platform;
    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;
    cl_kernel forward_kernel;
    cl_kernel gradient_kernel;
    cl_kernel update_kernel;
    cl_mem inputs;
    cl_mem targets;
    cl_mem strengths;
    cl_mem parameters;
    cl_mem predictions;
    cl_mem gradients;
    size_t batch_capacity;
    bool ready;
}
fuzzy_neuron_opencl_t;

typedef struct fuzzy_neuron_network
{
    fuzzy_neuron_layer_t *first_layer;
    fuzzy_neuron_layer_t *last_layer;
    fuzzy_neuron_layer_t *input_layer;
    fuzzy_neuron_layer_t *rule_layer;
    fuzzy_neuron_layer_t *output_layer;
    fuzzy_rules_t rule_bank;
    size_t input_count;
    size_t output_count;
    size_t layer_count;
    size_t neuron_count;
    size_t connection_count;
    size_t parameter_count;
    float output;
    fuzzy_neuron_opencl_t opencl;
}
fuzzy_neuron_network_t;

static fuzzy_neuron_network_t *plot_network;

static float fuzzy_neuron_identity(float value)
{
    return value;
}

static float rule_idle(const float x[])
{
    return SAND(temperature_low(x[0]*100.0f),load_low(x[1]*100.0f),vibration_low(x[2]*10.0f));
}

static float rule_economy(const float x[])
{
    return SAND(1.0f-temperature_high(x[0]*100.0f),load_high(x[1]*100.0f));
}

static float rule_balanced(const float x[])
{
    return SOR(temperature_high(x[0]*100.0f),vibration_high(x[2]*10.0f));
}

static float rule_cooling(const float x[])
{
    return SAND(temperature_high(x[0]*100.0f),load_high(x[1]*100.0f));
}

static float rule_heavy_load(const float x[])
{
    return SAND(load_high(x[1]*100.0f),1.0f-vibration_high(x[2]*10.0f));
}

static float rule_protection(const float x[])
{
    return SOR(
        SAND(temperature_high(x[0]*100.0f),vibration_high(x[2]*10.0f)),
        SAND(load_high(x[1]*100.0f),vibration_high(x[2]*10.0f))
    );
}

#define FUZZY_NEURON_RULE(network,symbol,evaluator) \
    do \
    { \
        fuzzy_neuron_network_add_rule(&(network),#symbol,(evaluator)); \
        RULE((network).rule_bank,#symbol,0.0f,fuzzy_neuron_identity); \
    } \
    while(0)

static void fail_opencl(cl_int error,const char *operation)
{
    if(error!=CL_SUCCESS)
    {
        fprintf(stderr,"OpenCL error %d at %s\n",error,operation);
        exit(1);
    }
}

static double elapsed_seconds(struct timespec start,struct timespec end)
{
    return (double)(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000.0;
}

static fuzzy_neuron_layer_t *fuzzy_neuron_network_add_layer(
    fuzzy_neuron_network_t *network,
    fuzzy_neuron_layer_kind_t kind,
    size_t count
)
{
    fuzzy_neuron_layer_t *layer=calloc(1u,sizeof(*layer));

    if(layer==NULL)exit(1);
    layer->kind=kind;
    layer->count=count;
    layer->neurons=count>0u?calloc(count,sizeof(*layer->neurons)):NULL;
    if(count>0u&&layer->neurons==NULL)exit(1);

    layer->previous=network->last_layer;
    if(network->last_layer!=NULL)network->last_layer->next=layer;
    else network->first_layer=layer;
    network->last_layer=layer;
    network->layer_count++;
    network->neuron_count+=count;

    if(kind==FUZZY_NEURON_LAYER_INPUT)network->input_layer=layer;
    if(kind==FUZZY_NEURON_LAYER_RULE)network->rule_layer=layer;
    if(kind==FUZZY_NEURON_LAYER_OUTPUT)network->output_layer=layer;

    return layer;
}

static void fuzzy_neuron_network_init(
    fuzzy_neuron_network_t *network,
    size_t input_count,
    size_t output_count
)
{
    size_t index;

    memset(network,0,sizeof(*network));
    network->input_count=input_count;
    network->output_count=output_count;
    network->rule_bank.count=0u;
    fuzzy_neuron_network_add_layer(network,FUZZY_NEURON_LAYER_INPUT,input_count);

    for(index=0u;index<input_count;index++)
    {
        network->input_layer->neurons[index].parameter_count=0u;
    }
}

static void fuzzy_neuron_network_add_rule(
    fuzzy_neuron_network_t *network,
    const char *name,
    fuzzy_rule_evaluator_t evaluator
)
{
    fuzzy_neuron_layer_t *layer=network->rule_layer;
    fuzzy_neuron_t *expanded;
    fuzzy_neuron_t *neuron;
    size_t count;

    if(layer==NULL)
    {
        layer=fuzzy_neuron_network_add_layer(network,FUZZY_NEURON_LAYER_RULE,0u);
        free(layer->neurons);
        layer->neurons=NULL;
    }

    count=layer->count+1u;
    expanded=realloc(layer->neurons,count*sizeof(*expanded));
    if(expanded==NULL)exit(1);
    layer->neurons=expanded;
    neuron=&layer->neurons[layer->count];
    memset(neuron,0,sizeof(*neuron));
    neuron->name=name;
    neuron->rule=evaluator;
    neuron->parameter_count=CONSEQUENT_PARAMETERS;
    neuron->parameters=calloc(CONSEQUENT_PARAMETERS,sizeof(*neuron->parameters));
    if(neuron->parameters==NULL)exit(1);
    layer->count=count;
    network->neuron_count++;
    network->parameter_count+=CONSEQUENT_PARAMETERS;
}

static void fuzzy_neuron_layer_connect_all(
    fuzzy_neuron_network_t *network,
    fuzzy_neuron_layer_t *source,
    fuzzy_neuron_layer_t *destination
)
{
    size_t destination_index;
    size_t source_index;

    for(destination_index=0u;destination_index<destination->count;destination_index++)
    {
        fuzzy_neuron_t *neuron=&destination->neurons[destination_index];
        neuron->connection_count=source->count;
        neuron->connections=calloc(source->count,sizeof(*neuron->connections));
        if(neuron->connections==NULL)exit(1);

        for(source_index=0u;source_index<source->count;source_index++)
        {
            neuron->connections[source_index].source=&source->neurons[source_index];
            neuron->connections[source_index].weight=1.0f;
            network->connection_count++;
        }
    }
}

static void fuzzy_neuron_network_connect_all(fuzzy_neuron_network_t *network)
{
    fuzzy_neuron_layer_t *layer;

    if(network->output_layer==NULL)
    {
        fuzzy_neuron_network_add_layer(network,FUZZY_NEURON_LAYER_OUTPUT,network->output_count);
    }

    for(layer=network->first_layer;layer!=NULL&&layer->next!=NULL;layer=layer->next)
    {
        fuzzy_neuron_layer_connect_all(network,layer,layer->next);
    }
}

static float fuzzy_neuron_consequent_feature(size_t parameter,const float inputs[])
{
    if(parameter==0u)return 1.0f;
    return inputs[parameter-1u];
}

static void fuzzy_neuron_set_inputs(
    fuzzy_neuron_layer_t *input_layer,
    const float inputs[],
    size_t input_count
)
{
    size_t index;

    for(index=0u;index<input_count;index++)
    {
        input_layer->neurons[index].output=inputs[index];
    }
}

static void fuzzy_neuron_evaluate_rule_layer(
    fuzzy_neuron_network_t *network,
    const float inputs[]
)
{
    size_t index;

    for(index=0u;index<network->rule_layer->count;index++)
    {
        fuzzy_neuron_t *neuron=&network->rule_layer->neurons[index];
        neuron->firing_strength=neuron->rule(inputs);
        network->rule_bank.rules[index].value=neuron->firing_strength;
    }
}

static void fuzzy_neuron_normalize_rule_layer(fuzzy_neuron_network_t *network)
{
    size_t index;
    float total=0.0f;

    for(index=0u;index<network->rule_layer->count;index++)
    {
        total+=network->rule_layer->neurons[index].firing_strength;
    }

    for(index=0u;index<network->rule_layer->count;index++)
    {
        fuzzy_neuron_t *neuron=&network->rule_layer->neurons[index];
        neuron->normalized_strength=total>1.0e-12f?neuron->firing_strength/total:0.0f;
    }
}

static void fuzzy_neuron_evaluate_rule_consequents(
    fuzzy_neuron_network_t *network,
    const float inputs[]
)
{
    size_t rule;
    size_t parameter;

    for(rule=0u;rule<network->rule_layer->count;rule++)
    {
        fuzzy_neuron_t *neuron=&network->rule_layer->neurons[rule];
        float consequent=0.0f;

        for(parameter=0u;parameter<neuron->parameter_count;parameter++)
        {
            consequent+=neuron->parameters[parameter]*fuzzy_neuron_consequent_feature(parameter,inputs);
        }

        neuron->weighted_sum=consequent;
        neuron->output=neuron->normalized_strength*consequent;
    }
}

static float fuzzy_neuron_collect_output(fuzzy_neuron_network_t *network)
{
    size_t rule;
    float output=0.0f;

    for(rule=0u;rule<network->rule_layer->count;rule++)
    {
        output+=network->rule_layer->neurons[rule].output;
    }

    network->output=output;
    network->output_layer->neurons[0].output=output;
    return output;
}

static float fuzzy_neuron_network_forward(
    fuzzy_neuron_network_t *network,
    const float inputs[]
)
{
    fuzzy_neuron_set_inputs(network->input_layer,inputs,network->input_count);
    fuzzy_neuron_evaluate_rule_layer(network,inputs);
    fuzzy_neuron_normalize_rule_layer(network);
    fuzzy_neuron_evaluate_rule_consequents(network,inputs);
    return fuzzy_neuron_collect_output(network);
}

static void fuzzy_neuron_network_backward(
    fuzzy_neuron_network_t *network,
    const float inputs[],
    float target,
    float learning_rate
)
{
    size_t rule;
    size_t parameter;
    float error=network->output-target;

    network->output_layer->neurons[0].delta=error;

    for(rule=0u;rule<network->rule_layer->count;rule++)
    {
        fuzzy_neuron_t *neuron=&network->rule_layer->neurons[rule];
        neuron->delta=error*neuron->normalized_strength;

        for(parameter=0u;parameter<neuron->parameter_count;parameter++)
        {
            float feature=fuzzy_neuron_consequent_feature(parameter,inputs);
            neuron->parameters[parameter]-=learning_rate*neuron->delta*feature;
        }
    }
}

static void fuzzy_neuron_flatten_parameters(
    const fuzzy_neuron_network_t *network,
    float parameters[]
)
{
    size_t rule;
    size_t parameter;
    size_t offset=0u;

    for(rule=0u;rule<network->rule_layer->count;rule++)
    {
        const fuzzy_neuron_t *neuron=&network->rule_layer->neurons[rule];

        for(parameter=0u;parameter<neuron->parameter_count;parameter++)
        {
            parameters[offset++]=neuron->parameters[parameter];
        }
    }
}

static void fuzzy_neuron_expand_parameters(
    fuzzy_neuron_network_t *network,
    const float parameters[]
)
{
    size_t rule;
    size_t parameter;
    size_t offset=0u;

    for(rule=0u;rule<network->rule_layer->count;rule++)
    {
        fuzzy_neuron_t *neuron=&network->rule_layer->neurons[rule];

        for(parameter=0u;parameter<neuron->parameter_count;parameter++)
        {
            neuron->parameters[parameter]=parameters[offset++];
        }
    }
}

static void fuzzy_neuron_prepare_strengths(
    fuzzy_neuron_network_t *network,
    const float inputs[],
    float strengths[],
    size_t sample_count
)
{
    size_t sample;
    size_t rule;

    for(sample=0u;sample<sample_count;sample++)
    {
        const float *sample_inputs=inputs+sample*network->input_count;
        fuzzy_neuron_evaluate_rule_layer(network,sample_inputs);
        fuzzy_neuron_normalize_rule_layer(network);

        for(rule=0u;rule<network->rule_layer->count;rule++)
        {
            strengths[sample*network->rule_layer->count+rule]=
                network->rule_layer->neurons[rule].normalized_strength;
        }
    }
}

static const char *fuzzy_neuron_opencl_source=
"__kernel void anfis_forward(__global const float*inputs,__global const float*strengths,__global const float*parameters,__global float*predictions,uint sample_count,uint input_count,uint rule_count,uint parameter_count){uint sample=get_global_id(0);if(sample>=sample_count)return;float output=0.0f;for(uint rule=0;rule<rule_count;rule++){uint base=rule*parameter_count;float consequent=parameters[base];for(uint input=0;input<input_count;input++)consequent+=parameters[base+input+1]*inputs[sample*input_count+input];output+=strengths[sample*rule_count+rule]*consequent;}predictions[sample]=output;}\n"
"__kernel void anfis_gradient(__global const float*inputs,__global const float*targets,__global const float*predictions,__global const float*strengths,__global float*gradients,uint sample_count,uint input_count,uint rule_count,uint parameter_count){uint sample=get_global_id(0);uint parameter=get_global_id(1);uint total=rule_count*parameter_count;if(sample>=sample_count||parameter>=total)return;uint rule=parameter/parameter_count;uint term=parameter%parameter_count;float feature=term==0?1.0f:inputs[sample*input_count+term-1];gradients[sample*total+parameter]=(predictions[sample]-targets[sample])*strengths[sample*rule_count+rule]*feature;}\n"
"__kernel void anfis_update(__global float*parameters,__global const float*gradients,uint sample_count,uint total_parameters,float learning_rate){uint parameter=get_global_id(0);if(parameter>=total_parameters)return;float sum=0.0f;for(uint sample=0;sample<sample_count;sample++)sum+=gradients[sample*total_parameters+parameter];parameters[parameter]-=learning_rate*sum/(float)sample_count;}\n";

static cl_kernel fuzzy_neuron_opencl_create_kernel(
    fuzzy_neuron_opencl_t *backend,
    const char *name
)
{
    cl_int error;
    cl_kernel kernel=clCreateKernel(backend->program,name,&error);
    fail_opencl(error,name);
    return kernel;
}

static cl_mem fuzzy_neuron_opencl_create_buffer(
    fuzzy_neuron_opencl_t *backend,
    size_t bytes,
    const char *name
)
{
    cl_int error;
    cl_mem buffer=clCreateBuffer(backend->context,CL_MEM_READ_WRITE,bytes,NULL,&error);
    fail_opencl(error,name);
    return buffer;
}

static void fuzzy_neuron_opencl_init(
    fuzzy_neuron_opencl_t *backend,
    fuzzy_neuron_network_t *network,
    size_t batch_capacity
)
{
    cl_int error;
    size_t log_size;
    char *log;
    float *parameters=malloc(network->parameter_count*sizeof(*parameters));

    memset(backend,0,sizeof(*backend));
    backend->batch_capacity=batch_capacity;
    fail_opencl(clGetPlatformIDs(1,&backend->platform,NULL),"clGetPlatformIDs");
    fail_opencl(clGetDeviceIDs(backend->platform,CL_DEVICE_TYPE_GPU,1,&backend->device,NULL),"clGetDeviceIDs");
    backend->context=clCreateContext(NULL,1,&backend->device,NULL,NULL,&error);
    fail_opencl(error,"clCreateContext");
    backend->queue=clCreateCommandQueue(backend->context,backend->device,0,&error);
    fail_opencl(error,"clCreateCommandQueue");
    backend->program=clCreateProgramWithSource(backend->context,1,&fuzzy_neuron_opencl_source,NULL,&error);
    fail_opencl(error,"clCreateProgramWithSource");

    error=clBuildProgram(backend->program,1,&backend->device,"-cl-fast-relaxed-math",NULL,NULL);
    if(error!=CL_SUCCESS)
    {
        clGetProgramBuildInfo(backend->program,backend->device,CL_PROGRAM_BUILD_LOG,0,NULL,&log_size);
        log=malloc(log_size+1u);
        clGetProgramBuildInfo(backend->program,backend->device,CL_PROGRAM_BUILD_LOG,log_size,log,NULL);
        log[log_size]='\0';
        fprintf(stderr,"%s\n",log);
        free(log);
        exit(1);
    }

    backend->forward_kernel=fuzzy_neuron_opencl_create_kernel(backend,"anfis_forward");
    backend->gradient_kernel=fuzzy_neuron_opencl_create_kernel(backend,"anfis_gradient");
    backend->update_kernel=fuzzy_neuron_opencl_create_kernel(backend,"anfis_update");
    backend->inputs=fuzzy_neuron_opencl_create_buffer(backend,batch_capacity*network->input_count*sizeof(float),"inputs");
    backend->targets=fuzzy_neuron_opencl_create_buffer(backend,batch_capacity*sizeof(float),"targets");
    backend->strengths=fuzzy_neuron_opencl_create_buffer(backend,batch_capacity*network->rule_layer->count*sizeof(float),"strengths");
    backend->parameters=fuzzy_neuron_opencl_create_buffer(backend,network->parameter_count*sizeof(float),"parameters");
    backend->predictions=fuzzy_neuron_opencl_create_buffer(backend,batch_capacity*sizeof(float),"predictions");
    backend->gradients=fuzzy_neuron_opencl_create_buffer(backend,batch_capacity*network->parameter_count*sizeof(float),"gradients");

    fuzzy_neuron_flatten_parameters(network,parameters);
    fail_opencl(clEnqueueWriteBuffer(backend->queue,backend->parameters,CL_TRUE,0,network->parameter_count*sizeof(float),parameters,0,NULL,NULL),"write parameters");
    free(parameters);
    backend->ready=true;
}

static void fuzzy_neuron_opencl_forward(
    fuzzy_neuron_opencl_t *backend,
    const fuzzy_neuron_network_t *network,
    cl_uint sample_count
)
{
    size_t global=sample_count;
    cl_uint input_count=(cl_uint)network->input_count;
    cl_uint rule_count=(cl_uint)network->rule_layer->count;
    cl_uint parameter_count=(cl_uint)CONSEQUENT_PARAMETERS;

    clSetKernelArg(backend->forward_kernel,0,sizeof(backend->inputs),&backend->inputs);
    clSetKernelArg(backend->forward_kernel,1,sizeof(backend->strengths),&backend->strengths);
    clSetKernelArg(backend->forward_kernel,2,sizeof(backend->parameters),&backend->parameters);
    clSetKernelArg(backend->forward_kernel,3,sizeof(backend->predictions),&backend->predictions);
    clSetKernelArg(backend->forward_kernel,4,sizeof(sample_count),&sample_count);
    clSetKernelArg(backend->forward_kernel,5,sizeof(input_count),&input_count);
    clSetKernelArg(backend->forward_kernel,6,sizeof(rule_count),&rule_count);
    clSetKernelArg(backend->forward_kernel,7,sizeof(parameter_count),&parameter_count);
    fail_opencl(clEnqueueNDRangeKernel(backend->queue,backend->forward_kernel,1,NULL,&global,NULL,0,NULL,NULL),"anfis_forward");
}

static void fuzzy_neuron_opencl_backward(
    fuzzy_neuron_opencl_t *backend,
    const fuzzy_neuron_network_t *network,
    cl_uint sample_count,
    float learning_rate
)
{
    cl_uint input_count=(cl_uint)network->input_count;
    cl_uint rule_count=(cl_uint)network->rule_layer->count;
    cl_uint parameter_count=(cl_uint)CONSEQUENT_PARAMETERS;
    cl_uint total_parameters=(cl_uint)network->parameter_count;
    size_t gradient_global[2]={sample_count,total_parameters};
    size_t update_global=total_parameters;

    clSetKernelArg(backend->gradient_kernel,0,sizeof(backend->inputs),&backend->inputs);
    clSetKernelArg(backend->gradient_kernel,1,sizeof(backend->targets),&backend->targets);
    clSetKernelArg(backend->gradient_kernel,2,sizeof(backend->predictions),&backend->predictions);
    clSetKernelArg(backend->gradient_kernel,3,sizeof(backend->strengths),&backend->strengths);
    clSetKernelArg(backend->gradient_kernel,4,sizeof(backend->gradients),&backend->gradients);
    clSetKernelArg(backend->gradient_kernel,5,sizeof(sample_count),&sample_count);
    clSetKernelArg(backend->gradient_kernel,6,sizeof(input_count),&input_count);
    clSetKernelArg(backend->gradient_kernel,7,sizeof(rule_count),&rule_count);
    clSetKernelArg(backend->gradient_kernel,8,sizeof(parameter_count),&parameter_count);
    fail_opencl(clEnqueueNDRangeKernel(backend->queue,backend->gradient_kernel,2,NULL,gradient_global,NULL,0,NULL,NULL),"anfis_gradient");

    clSetKernelArg(backend->update_kernel,0,sizeof(backend->parameters),&backend->parameters);
    clSetKernelArg(backend->update_kernel,1,sizeof(backend->gradients),&backend->gradients);
    clSetKernelArg(backend->update_kernel,2,sizeof(sample_count),&sample_count);
    clSetKernelArg(backend->update_kernel,3,sizeof(total_parameters),&total_parameters);
    clSetKernelArg(backend->update_kernel,4,sizeof(learning_rate),&learning_rate);
    fail_opencl(clEnqueueNDRangeKernel(backend->queue,backend->update_kernel,1,NULL,&update_global,NULL,0,NULL,NULL),"anfis_update");
}

static void fuzzy_neuron_opencl_sync_to_network(
    fuzzy_neuron_opencl_t *backend,
    fuzzy_neuron_network_t *network
)
{
    float *parameters=malloc(network->parameter_count*sizeof(*parameters));

    if(parameters==NULL)exit(1);
    fail_opencl(clEnqueueReadBuffer(backend->queue,backend->parameters,CL_TRUE,0,network->parameter_count*sizeof(float),parameters,0,NULL,NULL),"read parameters");
    fuzzy_neuron_expand_parameters(network,parameters);
    free(parameters);
}

static void fuzzy_neuron_opencl_train(
    fuzzy_neuron_opencl_t *backend,
    fuzzy_neuron_network_t *network,
    sample_t *samples,
    size_t count,
    size_t epochs,
    float learning_rate
)
{
    float *batch_inputs=malloc(backend->batch_capacity*network->input_count*sizeof(float));
    float *batch_targets=malloc(backend->batch_capacity*sizeof(float));
    float *batch_strengths=malloc(backend->batch_capacity*network->rule_layer->count*sizeof(float));
    float *batch_predictions=malloc(backend->batch_capacity*sizeof(float));
    size_t epoch;
    size_t position;
    size_t sample;
    size_t batch_count;

    if(batch_inputs==NULL||batch_targets==NULL||batch_strengths==NULL||batch_predictions==NULL)exit(1);

    for(epoch=0u;epoch<epochs;epoch++)
    {
        double loss=0.0;
        size_t seen=0u;

        for(position=0u;position<count;)
        {
            batch_count=0u;

            while(position<count&&batch_count<backend->batch_capacity)
            {
                if(position%TEST_MODULO!=0u)
                {
                    memcpy(batch_inputs+batch_count*network->input_count,samples[position].x,network->input_count*sizeof(float));
                    batch_targets[batch_count]=samples[position].target;
                    batch_count++;
                }
                position++;
            }

            if(batch_count==0u)continue;
            fuzzy_neuron_prepare_strengths(network,batch_inputs,batch_strengths,batch_count);
            fail_opencl(clEnqueueWriteBuffer(backend->queue,backend->inputs,CL_FALSE,0,batch_count*network->input_count*sizeof(float),batch_inputs,0,NULL,NULL),"train inputs");
            fail_opencl(clEnqueueWriteBuffer(backend->queue,backend->targets,CL_FALSE,0,batch_count*sizeof(float),batch_targets,0,NULL,NULL),"train targets");
            fail_opencl(clEnqueueWriteBuffer(backend->queue,backend->strengths,CL_FALSE,0,batch_count*network->rule_layer->count*sizeof(float),batch_strengths,0,NULL,NULL),"train strengths");
            fuzzy_neuron_opencl_forward(backend,network,(cl_uint)batch_count);
            fail_opencl(clEnqueueReadBuffer(backend->queue,backend->predictions,CL_TRUE,0,batch_count*sizeof(float),batch_predictions,0,NULL,NULL),"train predictions");

            for(sample=0u;sample<batch_count;sample++)
            {
                float error=batch_predictions[sample]-batch_targets[sample];
                loss+=(double)error*error;
            }

            fuzzy_neuron_opencl_backward(backend,network,(cl_uint)batch_count,learning_rate);
            seen+=batch_count;
        }

        if(epoch%25u==0u||epoch+1u==epochs)
        {
            printf("Epoch %4u MSE %.10f\n",(unsigned int)(epoch+1u),loss/(double)seen);
        }
    }

    fuzzy_neuron_opencl_sync_to_network(backend,network);
    free(batch_inputs);
    free(batch_targets);
    free(batch_strengths);
    free(batch_predictions);
}

static void fuzzy_neuron_opencl_predict(
    fuzzy_neuron_opencl_t *backend,
    fuzzy_neuron_network_t *network,
    const float inputs[],
    float predictions[],
    size_t count
)
{
    float *strengths=malloc(backend->batch_capacity*network->rule_layer->count*sizeof(float));
    size_t offset=0u;

    if(strengths==NULL)exit(1);

    while(offset<count)
    {
        size_t remaining=count-offset;
        size_t batch_count=remaining<backend->batch_capacity?remaining:backend->batch_capacity;
        const float *batch_inputs=inputs+offset*network->input_count;

        fuzzy_neuron_prepare_strengths(network,batch_inputs,strengths,batch_count);
        fail_opencl(clEnqueueWriteBuffer(backend->queue,backend->inputs,CL_FALSE,0,batch_count*network->input_count*sizeof(float),batch_inputs,0,NULL,NULL),"predict inputs");
        fail_opencl(clEnqueueWriteBuffer(backend->queue,backend->strengths,CL_FALSE,0,batch_count*network->rule_layer->count*sizeof(float),strengths,0,NULL,NULL),"predict strengths");
        fuzzy_neuron_opencl_forward(backend,network,(cl_uint)batch_count);
        fail_opencl(clEnqueueReadBuffer(backend->queue,backend->predictions,CL_TRUE,0,batch_count*sizeof(float),predictions+offset,0,NULL,NULL),"predict outputs");
        offset+=batch_count;
    }

    free(strengths);
}

static void fuzzy_neuron_opencl_free(fuzzy_neuron_opencl_t *backend)
{
    if(!backend->ready)return;
    clReleaseMemObject(backend->gradients);
    clReleaseMemObject(backend->predictions);
    clReleaseMemObject(backend->parameters);
    clReleaseMemObject(backend->strengths);
    clReleaseMemObject(backend->targets);
    clReleaseMemObject(backend->inputs);
    clReleaseKernel(backend->update_kernel);
    clReleaseKernel(backend->gradient_kernel);
    clReleaseKernel(backend->forward_kernel);
    clReleaseProgram(backend->program);
    clReleaseCommandQueue(backend->queue);
    clReleaseContext(backend->context);
    memset(backend,0,sizeof(*backend));
}

static sample_t *load_csv(const char *path,size_t *count)
{
    FILE *file=fopen(path,"r");
    sample_t *samples;
    char line[256];
    size_t capacity=65536u;

    if(file==NULL)return NULL;
    samples=malloc(capacity*sizeof(*samples));
    if(samples==NULL){fclose(file);return NULL;}
    *count=0u;

    if(fgets(line,sizeof(line),file)==NULL)
    {
        fclose(file);
        free(samples);
        return NULL;
    }

    while(fgets(line,sizeof(line),file)!=NULL)
    {
        float temperature;
        float load;
        float vibration;
        float target;

        if(sscanf(line,"%f,%f,%f,%f",&temperature,&load,&vibration,&target)!=4)continue;
        samples[*count].x[0]=temperature/100.0f;
        samples[*count].x[1]=load/100.0f;
        samples[*count].x[2]=vibration/10.0f;
        samples[*count].target=target/TARGET_SCALE;
        (*count)++;
    }

    fclose(file);
    return samples;
}

static void evaluate(
    fuzzy_neuron_network_t *network,
    sample_t *samples,
    size_t count,
    const char *path
)
{
    FILE *file;
    float *inputs;
    float *predictions;
    size_t index;
    size_t test_count=0u;
    double squared_error=0.0;
    double absolute_error=0.0;
    double maximum_error=0.0;

    for(index=0u;index<count;index+=TEST_MODULO)test_count++;
    inputs=malloc(test_count*network->input_count*sizeof(float));
    predictions=malloc(test_count*sizeof(float));
    file=fopen(path,"w");
    if(inputs==NULL||predictions==NULL||file==NULL)exit(1);

    test_count=0u;
    for(index=0u;index<count;index+=TEST_MODULO)
    {
        memcpy(inputs+test_count*network->input_count,samples[index].x,network->input_count*sizeof(float));
        test_count++;
    }

    fuzzy_neuron_opencl_predict(&network->opencl,network,inputs,predictions,test_count);
    fprintf(file,"Temperature,Load,Vibration,Expected,Predicted,Error\n");

    test_count=0u;
    for(index=0u;index<count;index+=TEST_MODULO)
    {
        float expected=samples[index].target*TARGET_SCALE;
        float predicted=predictions[test_count]*TARGET_SCALE;
        float error=predicted-expected;
        double magnitude=fabs((double)error);

        squared_error+=(double)error*error;
        absolute_error+=magnitude;
        if(magnitude>maximum_error)maximum_error=magnitude;
        fprintf(file,"%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n",samples[index].x[0]*100.0f,samples[index].x[1]*100.0f,samples[index].x[2]*10.0f,expected,predicted,error);
        test_count++;
    }

    fclose(file);
    printf("Test samples %u MSE %.8f RMSE %.8f MAE %.8f Max %.8f\n",(unsigned int)test_count,squared_error/test_count,sqrt(squared_error/test_count),absolute_error/test_count,maximum_error);
    free(inputs);
    free(predictions);
}

static float evaluate_learned_surface(
    const float inputs[],
    size_t input_count,
    float unused_step
)
{
    float normalized[RAW_INPUTS];

    (void)unused_step;
    if(plot_network==NULL||inputs==NULL||input_count!=RAW_INPUTS)return 0.0f;
    normalized[0]=inputs[0]/100.0f;
    normalized[1]=inputs[1]/100.0f;
    normalized[2]=inputs[2]/10.0f;
    return fuzzy_neuron_network_forward(plot_network,normalized)*TARGET_SCALE;
}

static void generate_plots(fuzzy_neuron_network_t *network)
{
    plot_network=network;

    PLOT("anfis_temperature_memberships","ANFIS Temperature Membership Functions",100.0f,1.0f,SERIES(temperature_low,"#3b82f6"),SERIES(temperature_high,"#ef4444"));
    PLOT("anfis_load_memberships","ANFIS Load Membership Functions",100.0f,1.0f,SERIES(load_low,"#22c55e"),SERIES(load_high,"#f97316"));
    PLOT("anfis_vibration_memberships","ANFIS Vibration Membership Functions",10.0f,0.1f,SERIES(vibration_low,"#06b6d4"),SERIES(vibration_high,"#a855f7"));

    FUZZY_COG_SWEEP(
        "anfis_learned_surface",
        "ANFIS Learned Fuzzy-Neuron Surface",
        evaluate_learned_surface,
        1.0f,
        FUZZY_SWEEP_DIMENSION("Temperature",0.0f,100.0f,2.0f),
        FUZZY_SWEEP_DIMENSION("Load",0.0f,100.0f,2.0f),
        FUZZY_SWEEP_DIMENSION("Vibration",0.0f,10.0f,0.5f)
    );
}

static void print_network(const fuzzy_neuron_network_t *network)
{
    size_t rule;
    size_t parameter;

    printf("\nNetwork: %u layers, %u neurons, %u connections, %u parameters\n",(unsigned int)network->layer_count,(unsigned int)network->neuron_count,(unsigned int)network->connection_count,(unsigned int)network->parameter_count);
    printf("Learned fuzzy neurons\n=====================\n");

    for(rule=0u;rule<network->rule_layer->count;rule++)
    {
        const fuzzy_neuron_t *neuron=&network->rule_layer->neurons[rule];
        printf("%-12s",neuron->name);

        for(parameter=0u;parameter<neuron->parameter_count;parameter++)
        {
            printf(" %+.7f",neuron->parameters[parameter]);
        }

        printf("\n");
    }
}

static void fuzzy_neuron_network_free(fuzzy_neuron_network_t *network)
{
    fuzzy_neuron_layer_t *layer=network->first_layer;

    fuzzy_neuron_opencl_free(&network->opencl);

    while(layer!=NULL)
    {
        fuzzy_neuron_layer_t *next=layer->next;
        size_t neuron;

        for(neuron=0u;neuron<layer->count;neuron++)
        {
            free(layer->neurons[neuron].connections);
            free(layer->neurons[neuron].parameters);
        }

        free(layer->neurons);
        free(layer);
        layer=next;
    }

    memset(network,0,sizeof(*network));
}

int main(int argc,char **argv)
{
    const char *input_path=argc>1?argv[1]:"sugeno_complex_sweep.csv";
    const char *output_path=argc>2?argv[2]:"fuzzy_neuron_gpu_predictions.csv";
    fuzzy_neuron_network_t network;
    sample_t *samples;
    size_t sample_count;
    struct timespec start;
    struct timespec end;
    double initialization_time;
    double training_time;
    double evaluation_time;
    double plotting_time;

    fuzzy_neuron_network_init(&network,RAW_INPUTS,OUTPUTS);
    FUZZY_NEURON_RULE(network,idle,rule_idle);
    FUZZY_NEURON_RULE(network,economy,rule_economy);
    FUZZY_NEURON_RULE(network,balanced,rule_balanced);
    FUZZY_NEURON_RULE(network,cooling,rule_cooling);
    FUZZY_NEURON_RULE(network,heavy_load,rule_heavy_load);
    FUZZY_NEURON_RULE(network,protection,rule_protection);
    fuzzy_neuron_network_connect_all(&network);

    samples=load_csv(input_path,&sample_count);
    if(samples==NULL){fprintf(stderr,"Cannot load %s\n",input_path);return 1;}

    timespec_get(&start,TIME_UTC);
    fuzzy_neuron_opencl_init(&network.opencl,&network,BATCH_SIZE);
    timespec_get(&end,TIME_UTC);
    initialization_time=elapsed_seconds(start,end);

    timespec_get(&start,TIME_UTC);
    fuzzy_neuron_opencl_train(&network.opencl,&network,samples,sample_count,EPOCHS,LEARNING_RATE);
    clFinish(network.opencl.queue);
    timespec_get(&end,TIME_UTC);
    training_time=elapsed_seconds(start,end);

    print_network(&network);

    timespec_get(&start,TIME_UTC);
    evaluate(&network,samples,sample_count,output_path);
    clFinish(network.opencl.queue);
    timespec_get(&end,TIME_UTC);
    evaluation_time=elapsed_seconds(start,end);

    timespec_get(&start,TIME_UTC);
    generate_plots(&network);
    timespec_get(&end,TIME_UTC);
    plotting_time=elapsed_seconds(start,end);

    printf("\nTiming\n======\nOpenCL initialization: %.3f s\nTraining:              %.3f s\nBatched test:          %.3f s\nCPU semantic plot:     %.3f s\nTotal measured:        %.3f s\n",initialization_time,training_time,evaluation_time,plotting_time,initialization_time+training_time+evaluation_time+plotting_time);
    printf("\nGenerated:\n  %s\n  anfis_temperature_memberships.svg\n  anfis_load_memberships.svg\n  anfis_vibration_memberships.svg\n  anfis_learned_surface.csv\n  anfis_learned_surface.svg\n",output_path);

    free(samples);
    fuzzy_neuron_network_free(&network);
    return 0;
}
