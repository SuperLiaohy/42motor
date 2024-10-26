//
// Created by Administrator on 24-10-3.
//
#include "CustomHeap.h"
#include "CAN/SuperCan.h"
#include "Motor/GM6020.h"
#include "Motor/M3508.h"
#include "Motor/Motor.h"
#include "Motor/dmMotor.h"
#include "Motor/lkMotor.h"
#include "RGBLED/RGBLED.h"
#include "GPIO/SuperGPIO.h"
#include "RemoteControl/RemoteControl.h"
#include "Chassis/Chassis.h"
#include "W25Q64/W25Q64.h"

//uint64_t DTCMUsed[16*1024/8];
__attribute__((section("._D1_Area"))) uint64_t D1Used[64 * 1024 / 8];
__attribute__((section("._D2_Area"))) uint64_t D2Used[8 * 1024 / 8];
__attribute__((section("._D3_Area"))) uint64_t D3Used[8 * 1024 / 8];


//CustomHeap DTCMHeap(DTCMUsed, sizeof(DTCMUsed));
__attribute__((section("._D1_Area"))) CustomHeap D1Heap(D1Used, sizeof(D1Used));
__attribute__((section("._D2_Area"))) CustomHeap D2Heap(D2Used, sizeof(D2Used));
__attribute__((section("._D3_Area"))) CustomHeap D3Heap(D3Used, sizeof(D3Used));

const FOC lkMotor::lkMotor_FOC = {0x140, 0x140, 0x140};
const FOC dmMotor::dmMotor_FOC = {0, 0x140, 0x140};

DetectManager Detect::detectManager;

W25Q64 w25q64(&hospi2);

SuperUart uartPlus10(&huart10, 10);

__weak SuperCan canPlus1(&hfdcan1, FDCAN_RX_FIFO0, FDCAN_IT_RX_FIFO0_NEW_MESSAGE);

__attribute__((section("._D1_Area"))) RemoteControl remote_control(&huart5, 60, Detect_cfg(1000));

lkMotor lkMotor1(PID(0.1, 0, 0.1, 0, 0),
                 PID(0.1, 0, 0.1, 0, 0),
                 1, Detect_cfg(1000), &canPlus1);

dmMotor dmMotor1(1, Detect_cfg(1000), &canPlus1, 0, 12.5, 45, 54);

Chassis chassis(&canPlus1,
                chassis_move_cfg{
                        Slope_cfg(75, 5),
                        Slope_cfg(75, 5),
                        Slope_cfg(0.04, 0)},
                {.vx = 2090, .vy = 2090, .w = 5},
                {.key_w = 0, .key_a = 0, .key_s = 0, .key_d = 0},
                {.pid = PID(0.15, 0, 0.1, 2, 4), .init_angle = 0, .angel = &gimbal_share_chassis},
                chassis_motor_cfg{
                        .LeftFront = M3508Config(1, 25, 0, 6, 7000, 16000, Detect_cfg()),
                        .RightFront = M3508Config(2, 25, 0, 6, 7000, 16000, Detect_cfg()),
                        .LeftRear = M3508Config(3, 25, 0, 6, 7000, 16000, Detect_cfg()),
                        .RightRear = M3508Config(4, 25, 0, 6, 7000, 16000, Detect_cfg())},
                chassis_info_cfg{
                        .wheel_base=364,
                        .wheel_track=455,
                        .wheel_radius=80,
                        .offset_x=0.,
                        .offset_y=0.},
                &remote_control);


GM6020 gm6020(PID(35.f, 0.08f, 2.f, 20000.f, 25000.0f),
              PID(2, 0, 0.1, 400, 320),
              1, Detect_cfg());

__attribute__((section("._D3_Area"))) RGBLED Led(&hspi6);
