//
// Created by lhy on 2024/9/15.
//

#ifndef NEW_PRJ_ROUNDQUEUE_H
#define NEW_PRJ_ROUNDQUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

#ifdef __cplusplus
}
#endif

const static uint8_t max = 10;

class RoundQueue {
public:
    explicit RoundQueue(int8_t size) : head(0), tail(0), size(size) {}

    float pop();

    float push(float value);

    void clear() {
        head = 0;
        tail = 0;
    }

    int32_t len() const {
        return (head - tail + size) % size;
    }

private:
    float buffer[max]{};

    int8_t head;
    int8_t tail;
    int8_t size;

};


#endif //NEW_PRJ_ROUNDQUEUE_H
