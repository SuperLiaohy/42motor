//
// Created by Administrator on 24-10-3.
//

#ifdef __cplusplus
extern "C" {
#endif
#include "FreeRTOS.h"
#include "cmsis_os.h"

#ifdef __cplusplus
}
#endif

#include "ThreadConfig.h"
#include "SuperCan.h"
#include "Motor/Motor.h"
extern float yaw;
float relative_position = 0;
float GM6020pos = 0;
float lkMotorSpeed = 0;
float dmMotorSpeed = 0;
float dmMotorPos = 0;
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
    UNUSED(RxFifo0ITs);
    if (hfdcan == canPlus1.hcan) {
        motor1.status = canPlus1.read()[1];
        canPlus1.receive();
    }
}
