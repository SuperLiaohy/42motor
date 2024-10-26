//
// Created by lhy on 2024/9/15.
//

#ifndef NEW_PRJ_SLOPE_H
#define NEW_PRJ_SLOPE_H


struct Slope_cfg {
    float step;
    float dead_zone;

    Slope_cfg(float step, float dead_zone) : step(step), dead_zone(dead_zone) {}
};

class Slope {
public:
    Slope(float target, float step, float dead_zone) : target(target), step(step), value(0), dead_zone(dead_zone) {}

    explicit Slope(Slope_cfg cfg) : target(0), step(cfg.step), value(0), dead_zone(cfg.dead_zone) {}

    void target_set(float input) {
        target = input;
    }

    void step_set(float input) {
        step = input;
    }

    float value_get() const {
        return value;
    }

    float update();

private:
    float target;
    float step;
    float value;
    float dead_zone;

};


#endif //NEW_PRJ_SLOPE_H
