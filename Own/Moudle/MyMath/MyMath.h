//
// Created by lhy on 2024/9/9.
//

#ifndef NONE_PRJ_MYMATH_H
#define NONE_PRJ_MYMATH_H


float limit(float *value, float min, float max);

float whileLimit(float *value, float min, float max);

float SmoothLimit(float *value, float target, float smooth);

float my_abs(float value);

int float_to_uint(float x_float, float x_min, float x_max, int bits);

float uint_to_float(int x_int, float x_min, float x_max, int bits);
#endif //NONE_PRJ_MYMATH_H
