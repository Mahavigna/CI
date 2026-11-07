#define FN_LOSS_MSE 0u
#define FN_LOSS_HUBER 1u
#define FN_ACTIVATION_LINEAR 0u
#define FN_ACTIVATION_SIGMOID 1u
#define FN_ACTIVATION_TANH 2u
#define FN_ACTIVATION_RELU 3u
#define FN_SHAPE_RAMP 0u
#define FN_SHAPE_TRIANGLE 1u
#define FN_SHAPE_TRAPEZOID 2u
#define FN_SHAPE_SMF 3u
#define FN_SHAPE_ZMF 4u
#define FN_SHAPE_GAUSSIAN 5u
#define FN_SHAPE_BELL 6u
#define FN_SHAPE_SIGMOID 7u
#define FN_SHAPE_PIMF 8u
#define FN_SHAPE_DSIGMOID 9u
#define FN_SHAPE_PSIGMOID 10u
#define FN_SHAPE_GAUSSIAN2 11u
#define FN_EXPR_MEMBERSHIP 0u
#define FN_EXPR_NOT 1u
#define FN_EXPR_AND 2u
#define FN_EXPR_OR 3u
#define FN_LOGIC_STANDARD 0u
#define FN_LOGIC_ALGEBRAIC 1u
#define FN_LOGIC_BOUNDED 2u

typedef struct fn_premise
{
    uint input_index;
    uint shape;
    uint parameter_offset;
    uint parameter_count;
    uint trainable_mask;
    uint reserved0;
    float hedge;
    float domain_minimum;
    float domain_maximum;
    float epsilon;
}
fn_premise_t;

typedef struct fn_expression
{
    uint kind;
    uint left;
    uint right;
    uint value;
}
fn_expression_t;

inline float fn_activate(float value, uint kind)
{
    if (kind == FN_ACTIVATION_SIGMOID) return (1.0f / (1.0f + exp(-clamp(value, -80.0f, 80.0f))));
    if (kind == FN_ACTIVATION_TANH) return tanh(value);
    if (kind == FN_ACTIVATION_RELU) return fmax(value, 0.0f);
    return value;
}

inline float fn_derivative_from_output(float output, uint kind)
{
    if (kind == FN_ACTIVATION_SIGMOID) return output * (1.0f - output);
    if (kind == FN_ACTIVATION_TANH) return fma(-output, output, 1.0f);
    if (kind == FN_ACTIVATION_RELU) return output > 0.0f ? 1.0f : 0.0f;
    return 1.0f;
}

inline float fn_logic_and(float left, float right, uint method)
{
    if (method == FN_LOGIC_ALGEBRAIC) return left * right;
    if (method == FN_LOGIC_BOUNDED) return fmax(0.0f, left + right - 1.0f);
    return fmin(left, right);
}

inline float fn_logic_or(float left, float right, uint method)
{
    if (method == FN_LOGIC_ALGEBRAIC) return left + right - left * right;
    if (method == FN_LOGIC_BOUNDED) return fmin(1.0f, left + right);
    return fmax(left, right);
}

inline float fn_sigmoid(float slope, float center, float x)
{
    return (1.0f / (1.0f + exp(-clamp(slope * (x - center), -80.0f, 80.0f))));
}

inline float fn_parameter(__global const float *parameters, uint index, uint shifted_index, float shift)
{
    return parameters[index] + (index == shifted_index ? shift : 0.0f);
}

inline float fn_shape_shift(uint shape, float x, __global const float *parameters, uint offset, uint count, float epsilon, uint shifted_index, float shift)
{
    if (shape == FN_SHAPE_RAMP && count == 3u)
    {
        float a=fn_parameter(parameters,offset,shifted_index,shift);
        float b=fn_parameter(parameters,offset+1u,shifted_index,shift);
        int rising=fn_parameter(parameters,offset+2u,shifted_index,shift)!=0.0f;
        if (!(b>a)) return 0.0f;
        if (x<=a) return rising?0.0f:1.0f;
        if (x>=b) return rising?1.0f:0.0f;
        return rising?(x-a)/(b-a):(b-x)/(b-a);
    }
    if (shape == FN_SHAPE_TRIANGLE && count == 3u)
    {
        float a=fn_parameter(parameters,offset,shifted_index,shift);
        float b=fn_parameter(parameters,offset+1u,shifted_index,shift);
        float c=fn_parameter(parameters,offset+2u,shifted_index,shift);
        if (!(a<b&&b<c)||x<=a||x>=c) return 0.0f;
        return x<=b?(x-a)/(b-a):(c-x)/(c-b);
    }
    if (shape == FN_SHAPE_TRAPEZOID && count == 4u)
    {
        float a=fn_parameter(parameters,offset,shifted_index,shift);
        float b=fn_parameter(parameters,offset+1u,shifted_index,shift);
        float c=fn_parameter(parameters,offset+2u,shifted_index,shift);
        float d=fn_parameter(parameters,offset+3u,shifted_index,shift);
        if (!(a<b&&b<=c&&c<d)||x<=a||x>=d) return 0.0f;
        if (x>=b&&x<=c) return 1.0f;
        return x<b?(x-a)/(b-a):(d-x)/(d-c);
    }
    if ((shape == FN_SHAPE_SMF || shape == FN_SHAPE_ZMF) && count == 2u)
    {
        float a=fn_parameter(parameters,offset,shifted_index,shift);
        float b=fn_parameter(parameters,offset+1u,shifted_index,shift);
        float result,t;
        if (!(b>a)) return 0.0f;
        if (x<=a) result=0.0f;
        else if (x>=b) result=1.0f;
        else if (x<=0.5f*(a+b))
        {
            t=(x-a)/(b-a);
            result=2.0f*t*t;
        }
        else
        {
            t=(b-x)/(b-a);
            result=1.0f-2.0f*t*t;
        }
        return shape==FN_SHAPE_ZMF?1.0f-result:result;
    }
    if (shape == FN_SHAPE_GAUSSIAN && count == 2u)
    {
        float mean=fn_parameter(parameters,offset,shifted_index,shift);
        float sigma=fabs(fn_parameter(parameters,offset+1u,shifted_index,shift));
        float d;
        if (sigma<=epsilon) return 0.0f;
        d=(x-mean)/sigma;
        return exp(-0.5f*d*d);
    }
    if (shape == FN_SHAPE_BELL && count == 3u)
    {
        float width=fn_parameter(parameters,offset,shifted_index,shift);
        float slope=fn_parameter(parameters,offset+1u,shifted_index,shift);
        float center=fn_parameter(parameters,offset+2u,shifted_index,shift);
        if (fabs(width)<=epsilon) return 0.0f;
        return (1.0f / (1.0f + pow(fabs((x - center) / (0.5f * width)), 2.0f * slope)));
    }
    if (shape == FN_SHAPE_SIGMOID && count == 2u) return fn_sigmoid(fn_parameter(parameters,offset,shifted_index,shift),fn_parameter(parameters,offset+1u,shifted_index,shift),x);
    if (shape == FN_SHAPE_PIMF && count == 4u)
    {
        float a=fn_parameter(parameters,offset,shifted_index,shift);
        float b=fn_parameter(parameters,offset+1u,shifted_index,shift);
        float c=fn_parameter(parameters,offset+2u,shifted_index,shift);
        float d=fn_parameter(parameters,offset+3u,shifted_index,shift);
        float left,right,t;
        if (!(a<b&&b<=c&&c<d)) return 0.0f;
        if (x<=a||x>=d) return 0.0f;
        if (x>=b&&x<=c) return 1.0f;
        if (x<b)
        {
            if (x<=0.5f*(a+b))
            {
                t=(x-a)/(b-a);
                left=2.0f*t*t;
            }
            else
            {
                t=(b-x)/(b-a);
                left=1.0f-2.0f*t*t;
            }
            return left;
        }
        if (x<=0.5f*(c+d))
        {
            t=(x-c)/(d-c);
            right=1.0f-2.0f*t*t;
        }
        else
        {
            t=(d-x)/(d-c);
            right=2.0f*t*t;
        }
        return right;
    }
    if ((shape == FN_SHAPE_DSIGMOID || shape == FN_SHAPE_PSIGMOID) && count == 4u)
    {
        float first=fn_sigmoid(fn_parameter(parameters,offset,shifted_index,shift),fn_parameter(parameters,offset+1u,shifted_index,shift),x);
        float second=fn_sigmoid(fn_parameter(parameters,offset+2u,shifted_index,shift),fn_parameter(parameters,offset+3u,shifted_index,shift),x);
        return shape==FN_SHAPE_DSIGMOID?clamp(first-second,0.0f,1.0f):first*second;
    }
    if (shape == FN_SHAPE_GAUSSIAN2 && count == 4u)
    {
        float m1=fn_parameter(parameters,offset,shifted_index,shift);
        float s1=fabs(fn_parameter(parameters,offset+1u,shifted_index,shift));
        float m2=fn_parameter(parameters,offset+2u,shifted_index,shift);
        float s2=fabs(fn_parameter(parameters,offset+3u,shifted_index,shift));
        float d;
        if (s1<=epsilon||s2<=epsilon||m1>m2) return 0.0f;
        if (x<m1)
        {
            d=(x-m1)/s1;
            return exp(-0.5f*d*d);
        }
        if (x<=m2) return 1.0f;
        d=(x-m2)/s2;
        return exp(-0.5f*d*d);
    }
    return 0.0f;
}

inline float fn_shape(uint shape,float x,__global const float *parameters,uint offset,uint count,float epsilon)
{
    return fn_shape_shift(shape,x,parameters,offset,count,epsilon,0xffffffffu,0.0f);
}

__kernel void fn_premise_forward(__global const float *restrict raw_inputs,__global const fn_premise_t *restrict premises,__global const float *restrict parameters,__global float *restrict memberships,uint sample_count,uint input_count,uint premise_count)
{
    uint sample=get_global_id(0), premise_index=get_global_id(1);
    if(sample>=sample_count||premise_index>=premise_count)return;
    fn_premise_t p=premises[premise_index];
    float base=fn_shape(p.shape,raw_inputs[(size_t)sample*input_count+p.input_index],parameters,p.parameter_offset,p.parameter_count,p.epsilon);
    memberships[(size_t)sample*premise_count+premise_index]=pow(clamp(base,0.0f,1.0f),fmax(p.hedge,p.epsilon));
}

__kernel void fn_expression_forward(__global const fn_expression_t *restrict expressions,__global const uint *restrict rule_roots,__global const float *restrict memberships,__global float *restrict expression_values,__global float *restrict raw_rules,uint sample_count,uint premise_count,uint expression_count,uint rule_count,uint logic_method)
{
    uint sample=get_global_id(0);
    if(sample>=sample_count)return;
    size_t eb=(size_t)sample*expression_count, mb=(size_t)sample*premise_count;
    for(uint n=0;n<expression_count;n++)
    {
        fn_expression_t e=expressions[n];
        float v;
        if(e.kind==FN_EXPR_MEMBERSHIP)v=memberships[mb+e.value];
        else if(e.kind==FN_EXPR_NOT)v=1.0f-expression_values[eb+e.left];
        else if(e.kind==FN_EXPR_AND)v=fn_logic_and(expression_values[eb+e.left],expression_values[eb+e.right],logic_method);
        else v=fn_logic_or(expression_values[eb+e.left],expression_values[eb+e.right],logic_method);
        expression_values[eb+n]=v;
    }
    for(uint r=0;r<rule_count;r++)raw_rules[(size_t)sample*rule_count+r]=expression_values[eb+rule_roots[r]];
}

__kernel void fn_normalize_rules(__global const float *restrict raw_rules,__global float *restrict activations,uint sample_count,uint rule_count,uint neuron_count)
{
    uint s=get_global_id(0);
    if(s>=sample_count)return;
    size_t rb=(size_t)s*rule_count,ab=(size_t)s*neuron_count;
    float total=0.0f;
    for(uint r=0;r<rule_count;r++)total+=raw_rules[rb+r];
    for(uint r=0;r<rule_count;r++)activations[ab+r]=total>1.0e-12f?raw_rules[rb+r]/total:0.0f;
}

__kernel void fn_forward_gemm(__global const float *restrict weights,__global const float *restrict biases,__global float *restrict activations,uint sample_count,uint neuron_count,uint source_offset,uint source_count,uint destination_offset,uint destination_count,uint weight_offset,uint bias_offset,uint activation_kind)
{
    uint s=get_global_id(0),d=get_global_id(1);
    if(s>=sample_count||d>=destination_count)return;
    size_t ab=(size_t)s*neuron_count,wb=(size_t)weight_offset+(size_t)d*source_count;
    float sum=biases[bias_offset+d];
    for(uint i=0;i<source_count;i++)sum=fma(activations[ab+source_offset+i],weights[wb+i],sum);
    activations[ab+destination_offset+d]=fn_activate(sum,activation_kind);
}

__kernel void fn_output_delta(__global const float *restrict targets,__global const float *restrict activations,__global float *restrict deltas,__global float *restrict losses,uint sample_count,uint output_count,uint neuron_count,uint output_offset,uint activation_kind,uint loss_method,float huber_delta)
{
    size_t i=get_global_id(0),total=(size_t)sample_count*output_count;
    if(i>=total)return;
    size_t s=i/output_count,o=i-s*output_count,a=s*neuron_count+output_offset+o;
    float prediction=activations[a],error=prediction-targets[i],gradient=error,loss=error*error;
    if(loss_method==FN_LOSS_HUBER)
    {
        float m=fabs(error);
        int q=m<=huber_delta;
        gradient=q?error/huber_delta:copysign(1.0f,error);
        loss=q?0.5f*error*error/huber_delta:m-0.5f*huber_delta;
    }
    deltas[a]=gradient*fn_derivative_from_output(prediction,activation_kind);
    losses[i]=loss;
}

__kernel void fn_hidden_delta_gemm(__global const float *restrict weights,__global const float *restrict activations,__global float *restrict deltas,uint sample_count,uint neuron_count,uint current_offset,uint current_count,uint next_offset,uint next_count,uint next_weight_offset,uint activation_kind)
{
    uint s=get_global_id(0),c=get_global_id(1);
    if(s>=sample_count||c>=current_count)return;
    size_t b=(size_t)s*neuron_count;
    float sum=0.0f;
    for(uint n=0;n<next_count;n++)sum=fma(weights[(size_t)next_weight_offset+(size_t)n*current_count+c],deltas[b+next_offset+n],sum);
    size_t i=b+current_offset+c;
    deltas[i]=sum*fn_derivative_from_output(activations[i],activation_kind);
}

__kernel void fn_input_delta(__global const float *restrict weights,__global const float *restrict deltas,__global float *restrict normalized_rule_gradients,uint sample_count,uint neuron_count,uint rule_count,uint first_destination_offset,uint first_destination_count,uint first_weight_offset)
{
    uint s=get_global_id(0),r=get_global_id(1);
    if(s>=sample_count||r>=rule_count)return;
    size_t b=(size_t)s*neuron_count;
    float g=0.0f;
    for(uint d=0;d<first_destination_count;d++)g=fma(weights[(size_t)first_weight_offset+(size_t)d*rule_count+r],deltas[b+first_destination_offset+d],g);
    normalized_rule_gradients[(size_t)s*rule_count+r]=g;
}

__kernel void fn_normalize_backward(__global const float *restrict raw_rules,__global const float *restrict normalized_gradients,__global float *restrict raw_rule_gradients,uint sample_count,uint rule_count)
{
    uint s=get_global_id(0);
    if(s>=sample_count)return;
    size_t b=(size_t)s*rule_count;
    float total=0.0f,weighted=0.0f;
    for(uint r=0;r<rule_count;r++)
    {
        total+=raw_rules[b+r];
        weighted+=normalized_gradients[b+r]*raw_rules[b+r];
    }
    for(uint r=0;r<rule_count;r++)raw_rule_gradients[b+r]=total>1.0e-12f?(normalized_gradients[b+r]*total-weighted)/(total*total):0.0f;
}

__kernel void fn_expression_backward(__global const fn_expression_t *restrict expressions,__global const uint *restrict rule_roots,__global const float *restrict expression_values,__global const float *restrict raw_rule_gradients,__global float *restrict expression_gradients,__global float *restrict membership_gradients,uint sample_count,uint premise_count,uint expression_count,uint rule_count,uint logic_method)
{
    uint s=get_global_id(0);
    if(s>=sample_count)return;
    size_t eb=(size_t)s*expression_count,mb=(size_t)s*premise_count;
    for(uint n=0;n<expression_count;n++)expression_gradients[eb+n]=0.0f;
    for(uint p=0;p<premise_count;p++)membership_gradients[mb+p]=0.0f;
    for(uint r=0;r<rule_count;r++)expression_gradients[eb+rule_roots[r]]+=raw_rule_gradients[(size_t)s*rule_count+r];
    for(uint rev=expression_count;rev-->0u;)
    {
        fn_expression_t e=expressions[rev];
        float in=expression_gradients[eb+rev];
        if(e.kind==FN_EXPR_MEMBERSHIP)membership_gradients[mb+e.value]+=in;
        else if(e.kind==FN_EXPR_NOT)expression_gradients[eb+e.left]-=in;
        else
        {
            float l=expression_values[eb+e.left],r=expression_values[eb+e.right];
            if(logic_method==FN_LOGIC_ALGEBRAIC)
            {
                if(e.kind==FN_EXPR_AND)
                {
                    expression_gradients[eb+e.left]+=in*r;
                    expression_gradients[eb+e.right]+=in*l;
                }
                else
                {
                    expression_gradients[eb+e.left]+=in*(1.0f-r);
                    expression_gradients[eb+e.right]+=in*(1.0f-l);
                }
            }
            else if(logic_method==FN_LOGIC_BOUNDED)
            {
                float active=e.kind==FN_EXPR_AND?(l+r>1.0f):(l+r<1.0f);
                if(active)
                {
                    expression_gradients[eb+e.left]+=in;
                    expression_gradients[eb+e.right]+=in;
                }
            }
            else
            {
                int lw=e.kind==FN_EXPR_AND?l<r:l>r;
                int rw=e.kind==FN_EXPR_AND?r<l:r>l;
                if(!lw&&!rw)
                {
                    expression_gradients[eb+e.left]+=0.5f*in;
                    expression_gradients[eb+e.right]+=0.5f*in;
                }
                else if(lw)expression_gradients[eb+e.left]+=in;
                else expression_gradients[eb+e.right]+=in;
            }
        }
    }
}

__kernel void fn_premise_gradient(__global const float *restrict raw_inputs,__global const fn_premise_t *restrict premises,__global const float *restrict parameters,__global const float *restrict memberships,__global const float *restrict membership_gradients,__global float *restrict parameter_gradients,uint sample_count,uint input_count,uint premise_count,uint parameter_count)
{
    uint parameter=get_global_id(0);
    if(parameter>=parameter_count)return;
    float gradient=0.0f;
    for(uint pi=0;pi<premise_count;pi++)
    {
        fn_premise_t p=premises[pi];
        if(parameter<p.parameter_offset||parameter>=p.parameter_offset+p.parameter_count)continue;
        uint local_param=parameter-p.parameter_offset;
        if(local_param>=32u||(p.trainable_mask&(1u<<local_param))==0u)continue;
        float original=parameters[parameter],h=fmax(p.epsilon,fabs(original)*1.0e-4f);
        for(uint s=0;s<sample_count;s++)
        {
            float x=raw_inputs[(size_t)s*input_count+p.input_index];
            float plus=fn_shape_shift(p.shape,x,parameters,p.parameter_offset,p.parameter_count,p.epsilon,parameter,h);
            float minus=fn_shape_shift(p.shape,x,parameters,p.parameter_offset,p.parameter_count,p.epsilon,parameter,-h);
            float d=(plus-minus)/(2.0f*h);
            float base=fn_shape(p.shape,x,parameters,p.parameter_offset,p.parameter_count,p.epsilon);
            d*=p.hedge*pow(fmax(base,p.epsilon),p.hedge-1.0f);
            gradient+=membership_gradients[(size_t)s*premise_count+pi]*d;
        }
    }
    parameter_gradients[parameter]=gradient;
}

__kernel void fn_weight_gradient_gemm(__global const float *restrict activations,__global const float *restrict deltas,__global float *restrict gradients,uint sample_count,uint neuron_count,uint source_offset,uint source_count,uint destination_offset,uint destination_count,uint weight_offset)
{
    uint src=get_global_id(0),dst=get_global_id(1);
    if(src>=source_count||dst>=destination_count)return;
    float g=0.0f;
    for(uint s=0;s<sample_count;s++)
    {
        size_t b=(size_t)s*neuron_count;
        g=fma(deltas[b+destination_offset+dst],activations[b+source_offset+src],g);
    }
    gradients[(size_t)weight_offset+(size_t)dst*source_count+src]=g;
}

__kernel void fn_bias_gradient(__global const float *restrict deltas,__global float *restrict gradients,uint sample_count,uint neuron_count,uint destination_offset,uint destination_count,uint bias_offset)
{
    uint d=get_global_id(0);
    if(d>=destination_count)return;
    float g=0.0f;
    for(uint s=0;s<sample_count;s++)g+=deltas[(size_t)s*neuron_count+destination_offset+d];
    gradients[bias_offset+d]=g;
}

__kernel void fn_apply_parameters(__global float *parameters,__global const float *gradients,uint parameter_count,uint parameter_offset,uint sample_count,float learning_rate)
{
    uint p=get_global_id(0);
    if(p>=parameter_count)return;
    size_t i=(size_t)parameter_offset+p;
    parameters[i]=fma(-learning_rate/(float)sample_count,gradients[i],parameters[i]);
}

__kernel void fn_adam_apply(__global float *parameters,__global const float *gradients,__global float *first_moment,__global float *second_moment,uint parameter_count,uint parameter_offset,uint sample_count,float alpha,float beta1,float beta2,float epsilon)
{
    uint p=get_global_id(0);
    if(p>=parameter_count)return;
    size_t i=(size_t)parameter_offset+p;
    float g=gradients[i]/(float)sample_count,m1=fma(1.0f-beta1,g,beta1*first_moment[i]),m2=fma(1.0f-beta2,g*g,beta2*second_moment[i]);
    first_moment[i]=m1;
    second_moment[i]=m2;
    parameters[i]-=alpha*m1/(sqrt(m2)+epsilon);
}

inline void fn_order2(__global float *p,uint a,uint b,float epsilon)
{
    float x=p[a],y=p[b];
    if(!isfinite(x))x=0.0f;
    if(!isfinite(y))y=x+epsilon;
    if(y<x+epsilon)y=x+epsilon;
    p[a]=x;
    p[b]=y;
}

__kernel void fn_project_premises(__global const fn_premise_t *restrict premises,__global float *parameters,uint premise_count)
{
    uint i=get_global_id(0);
    if(i>=premise_count)return;
    fn_premise_t p=premises[i];
    uint o=p.parameter_offset,c=p.parameter_count;
    for(uint j=0;j<c;j++)
    {
        float v=parameters[o+j];
        if(!isfinite(v))parameters[o+j]=0.0f;
    }
    if(p.shape==FN_SHAPE_RAMP&&c==3u)
    {
        fn_order2(parameters,o,o+1u,p.epsilon);
        parameters[o+2u]=parameters[o+2u]!=0.0f?1.0f:0.0f;
    }
    else if(p.shape==FN_SHAPE_TRIANGLE&&c==3u)
    {
        fn_order2(parameters,o,o+1u,p.epsilon);
        fn_order2(parameters,o+1u,o+2u,p.epsilon);
    }
    else if((p.shape==FN_SHAPE_TRAPEZOID||p.shape==FN_SHAPE_PIMF)&&c==4u)
    {
        fn_order2(parameters,o,o+1u,p.epsilon);
        if(parameters[o+2u]<parameters[o+1u])parameters[o+2u]=parameters[o+1u];
        fn_order2(parameters,o+2u,o+3u,p.epsilon);
    }
    else if((p.shape==FN_SHAPE_SMF||p.shape==FN_SHAPE_ZMF)&&c==2u)fn_order2(parameters,o,o+1u,p.epsilon);
    else if(p.shape==FN_SHAPE_GAUSSIAN&&c==2u)
    {
        parameters[o+1u]=fmax(fabs(parameters[o+1u]),p.epsilon);
    }
    else if(p.shape==FN_SHAPE_BELL&&c==3u)
    {
        float sign=parameters[o]<0.0f?-1.0f:1.0f;
        parameters[o]=sign*fmax(fabs(parameters[o]),p.epsilon);
    }
    else if(p.shape==FN_SHAPE_GAUSSIAN2&&c==4u)
    {
        parameters[o+1u]=fmax(fabs(parameters[o+1u]),p.epsilon);
        parameters[o+3u]=fmax(fabs(parameters[o+3u]),p.epsilon);
        if(parameters[o+2u]<parameters[o])parameters[o+2u]=parameters[o];
    }
    for(uint j=0;j<c;j++)
    {
        uint bit=j<32u?(1u<<j):0u;
        if((p.trainable_mask&bit)!=0u)parameters[o+j]=clamp(parameters[o+j],p.domain_minimum,p.domain_maximum);
    }
}
