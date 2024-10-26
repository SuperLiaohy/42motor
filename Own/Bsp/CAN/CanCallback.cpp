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
#include "Motor/GM6020.h"
#include "Motor/lkMotor.h"
#include "Motor/dmMotor.h"
extern float yaw;
float relative_position = 0;
float GM6020pos = 0;
float lkMotorSpeed = 0;
float dmMotorSpeed = 0;
float dmMotorPos = 0;
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
    UNUSED(RxFifo0ITs);
    if (hfdcan == canPlus1.hcan) {
        if (canPlus1.rx_header.Identifier == GM6020::GM6020_FOC.RX_ID + gm6020.id) {
            gm6020.readData(canPlus1.rx_data);
            GM6020pos = gm6020.Data.position;
            relative_position = GM6020pos - yaw;
        }
        if (canPlus1.rx_header.Identifier == lkMotor::lkMotor_FOC.RX_ID + lkMotor1.id){
            lkMotor1.feedback(canPlus1.rx_data);
            lkMotorSpeed = lkMotor1.Data.speed;
        }
        if (canPlus1.rx_header.Identifier == dmMotor::dmMotor_FOC.RX_ID + dmMotor1.masterId){
            dmMotor1.readData(canPlus1.rx_data);
            dmMotorSpeed = dmMotor1.Data.speed;
            dmMotorPos = dmMotor1.Data.position;
        }
        canPlus1.receive();
    }
}
