//
// Created by lhy on 2024/9/20.
//

#include "CppTask.h"
#include "ThreadConfig.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#include "CAN/SuperCan.h"
#include "GPIO/SuperGPIO.h"



void CanTask() {
    canPlus1.filter_config(0);
    canPlus1.can_start();

    while (1) {


    }
}

