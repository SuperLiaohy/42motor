//
// Created by liaohy on 9/5/24.
//

#include "pid.h"


float PID::update(float _target, float input) {
    if (this->target != _target) {
        this->target = _target;
//			item.i = 0;
    }

    item.p = target - input;
    item.i += item.p;
    if (item.i > Max.i) {
        item.i = Max.i;
    } else if (item.i < -Max.i) {
        item.i = -Max.i;
    }
    item.d = item.p - item.p_last;

    item.p_last = item.p;
    auto temp = number.p * item.p + number.i * item.i + number.d * item.d;
    if (temp > Max.output) {
        output = Max.output;
    } else if (temp < -Max.output) {
        output = -Max.output;
    } else {
        output = temp;
    }
    return output;
}


