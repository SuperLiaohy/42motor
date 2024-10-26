//
// Created by lhy on 2024/9/17.
//

#include "Detect.h"



Detect::~Detect() {
    detectManager.Unregister(this);
}

Detect::Detect(uint32_t maxInterval, uint32_t lastReceiveTime, uint8_t isLost)
        : maxInterval(maxInterval),
          lastReceiveTime(lastReceiveTime),
          isLost(isLost) {
    detectManager.Register(this);
}

Detect::Detect(Detect_cfg cfg)
        : maxInterval(cfg.maxInterval),
          lastReceiveTime(cfg.lastReceiveTime),
          isLost(cfg.isLost) {
    detectManager.Register(this);
}

void Detect::update() {
    lastReceiveTime = getSysTime();
}

void Detect::JudgeLost() {
    uint32_t presentTime = getSysTime();
    if (presentTime - lastReceiveTime > maxInterval) {
        if (!isLost) {
            lostFunc();
            isLost = 1;
        }
    } else {
        if (isLost) {
            recoverFunc();
            isLost = 0;
        }
    }
}


void Detect::lostFunc() { }

void Detect::recoverFunc() { }