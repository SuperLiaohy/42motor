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
#include "Motor/lkMotor.h"
#include "Motor/dmMotor.h"
#include "Motor/GM6020.h"
#include "CAN/SuperCan.h"
#include "GPIO/SuperGPIO.h"
#include "RGBLED/RGBLED.h"
#include "RemoteControl/RemoteControl.h"
#include "Chassis/Chassis.h"
uint8_t count = 0;
volatile float can_target = 0;
void LedTask() {
    while (1) {
//        if (count++ % 2) {
//            Led.SetColor(255, 0, 0);
//            osDelay(1000);
//            Led.SetColor(0, 255, 0);
//            osDelay(1000);
//            Led.SetColor(0, 0, 255);
//            osDelay(1000);
//        }
        if (remote_control.rcInfo.right == 3){
            Led.SetColor(0, 0, 0);
        } else  {
            Led.update();
        }
//        osDelay(3000);
//        if (can_target<200)
//            can_target = 300;
//        else
//            can_target = 100;
    }
}
uint8_t data[2] = {0};
float target_dm_pos = 0;
void CanTask() {
    canPlus1.filter_config(0);
    canPlus1.can_start();
    lkMotor1.open();
//    osDelay(1000);
//    dmMotor1.enable();
    while (1) {
//        canPlus1.write(static_cast<int16_t>(gm6020.doublePid.output),0,0,0);
//        canPlus1.write(static_cast<int16_t>(gm6020.pid.output),0,0,0);
//        canPlus1.send(GM6020::GM6020_FOC.TX_LOW_ID);

        lkMotor1.totalposition1Control(36000);
//        lkMotor1.speedControl(36000*5*7);
//        dmMotor1.mit_ctrl(target_dm_pos,0,0,9,3);
//        chassis.UpdateState();

        data[0] = (uint8_t)(gm6020.RawData.position >> 8);
        data[1] = (uint8_t)(gm6020.RawData.position & 0xff);
        uartPlus10.write(data, 2);
        osDelay(1);

    }
}

void UserPidTask(){
    osDelay(1000);
//    remote_control.start();
    while(1){

//        gm6020.doublePid.update(gm6020.totalPosition, can_target, gm6020.Data.speed);
//        gm6020.pid.update(60, gm6020.Data.speed);

        osDelay(1);

    }
}