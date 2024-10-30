//
// Created by lhy on 2024/9/17.
//

#include "Thread.h"

#include "CppTask.h"
#include "CAN/SuperCan.h"
#include "ThreadConfig.h"
#include "Motor/Motor.h"
extern uint32_t target;
void StartDefaultTask(void const *argument) {
    UNUSED(argument);
    canPlus1.filter_config(0);
    canPlus1.can_start();
    motor1.set_mode(Motor::SR_vFOC);
//    osDelay(1);
    motor1.enable_run_state(Motor::ENABLE);
    while (true){
//        motor1.cal();
        osDelay(1);
//        motor1.dir_speed_acc_ctrl(Motor::DIR_POSITIVE, 320, 2);
        motor1.set_pos_axis_absolute(320, 2, target / 360.f * 0x4000 );
    }
}

void OS_LedCallback(void const *argument) {
    UNUSED(argument);
    while (true){ osDelay(1);}
}

void UserCANTask(void const *argument) {
    UNUSED(argument);
    osDelay(10000);
    while (true){
//        motor1.read_n_encoder();


        osDelay(1);
    }
}

void PidTask(void const * argument){
    UNUSED(argument);
    while (true){ osDelay(1);}
}