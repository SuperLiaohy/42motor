//
// Created by lhy on 2024/9/9.
//

#ifndef NONE_PRJ_MYMATH_H
#define NONE_PRJ_MYMATH_H

#include "cstdint"

//class int48_t {
//public:
//    int48_t(int64_t _value){
//        if (_value > 0) {
//            value[0] = _value & 0xff;
//            value[1] = (_value >> 8) & 0xff;
//            value[2] = (_value >> 16) & 0xff;
//        } else {
//            value[0] = (~_value) & 0xff;
//            value[1] = ((~_value) >> 8) & 0xff;
//            value[2] = ((~_value) >> 16) & 0xff;
//        }
//    };
//    uint8_t value[6];
//};
//
//class int24_t {
//public:
//    explicit int24_t(int32_t _value) {
//        if (_value < 0) {
//            value = _value + 0x1000000;
//        } else {
//            value = _value;
//        }
//    };
//    int32_t value;
//};

float limit(float *value, float min, float max);

float whileLimit(float *value, float min, float max);

float SmoothLimit(float *value, float target, float smooth);

float my_abs(float value);

int float_to_uint(float x_float, float x_min, float x_max, int bits);

float uint_to_float(int x_int, float x_min, float x_max, int bits);
#endif //NONE_PRJ_MYMATH_H
