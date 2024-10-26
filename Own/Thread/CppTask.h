//
// Created by lhy on 2024/9/20.
//

#ifndef OWN_CPPTASK_H
#define OWN_CPPTASK_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"


#ifdef __cplusplus
}
#endif
void UserPidTask();
void CanTask();
void LedTask();
void ErrorTask();
void DetectTask();
void ChassisTask();
void MotorTask();
void RcTask();
void IMUTask();
#endif //OWN_CPPTASK_H
