#include "lec_11_09_11_func_cpp_header.h"

template <typename T> 
T compute_mult(T a, T b)
{
    return a * b;
}

template float  compute_mult<float> (float,  float);
template double compute_mult<double>(double, double);
