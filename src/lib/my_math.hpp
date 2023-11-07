#ifndef MY_MATH_HPP_INCLUDED
#define MY_MATH_HPP_INCLUDED

//--------------------------------------------------


#include <math.h>
#include <stdio.h>


//--------------------------------------------------


#define EPSILON 0.001


//--------------------------------------------------


bool double_equal (double first, double second);
size_t my_max (size_t value1, size_t value2);
double my_min (double value1, double value2);

void ensure_is_not_less_than (int& value, int goal);

//--------------------------------------------------


#endif