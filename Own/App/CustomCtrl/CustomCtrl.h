//
// Created by Administrator on 24-10-29.
//

#ifndef CAN_42MOTOR_CUSTOMCTRL_H
#define CAN_42MOTOR_CUSTOMCTRL_H

#include "Motor/Motor.h"
#include "Uart/SuperUart.h"
#include "Detect/Detect.h"
class CustomCtrl {
public:
    CustomCtrl(UART_HandleTypeDef *huart, Detect_cfg detectCfg) : uart1(huart, 60, 60), detect(detectCfg) {};

    void run() {
//        motor1.set_pos_axis_absolute();
    }
private:
    struct ReceiveData {

        float motor1_pos;
        float motor2_pos;
        float motor3_pos;
        float motor4_pos;
        float motor5_pos;
        float motor6_pos;
        float motor7_pos;
    } receive_target;
    struct TransmitData {
        float motor1_pos;
        float motor2_pos;
        float motor3_pos;
        float motor4_pos;
        float motor5_pos;
        float motor6_pos;
        float motor7_pos;
    } transmit_target;
    SuperUart uart1;
//    Motor motor1;
    Detect detect;
};


#endif //CAN_42MOTOR_CUSTOMCTRL_H
