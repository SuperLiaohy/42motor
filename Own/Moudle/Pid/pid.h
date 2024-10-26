//
// Created by liaohy on 9/5/24.
//

#ifndef NONE_PRJ_PID_H
#define NONE_PRJ_PID_H


class PID {
public:
    PID() = default;

    PID(float p, float i, float d, float maxI, float maxOut, float dead_zone = 0)
            : number{p, i, d},
              item{0, 0, 0, 0},
              Max{maxI, maxOut},
              output(0),
              dead_zone(dead_zone),
              target(0) {}

    struct {
        float p;
        float i;
        float d;
    } number{};

    struct {
        float p;
        float p_last;
        float i;
        float d;
    } item{};

    struct {
        float i;
        float output;
    } Max;

    float output;
    float dead_zone;
    float target;

    virtual float update(float _target, float input);

    float update(float input) {
        return update(target, input);
    }

    void clear() {
        item.p = 0;
        item.p_last = 0;
        item.i = 0;
        output = 0;
    }

};


#endif //NONE_PRJ_PID_H
