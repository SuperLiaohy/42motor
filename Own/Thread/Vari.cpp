//
// Created by Administrator on 24-10-3.
//
#include "CustomHeap.h"
#include "CAN/SuperCan.h"
#include "CustomHeap.h"
#include "GPIO/SuperGPIO.h"
#include "Motor/Motor.h"

//uint64_t DTCMUsed[16*1024/8];
__attribute__((section("._D1_Area"))) uint64_t D1Used[64 * 1024 / 8];
__attribute__((section("._D2_Area"))) uint64_t D2Used[8 * 1024 / 8];
__attribute__((section("._D3_Area"))) uint64_t D3Used[8 * 1024 / 8];


//CustomHeap DTCMHeap(DTCMUsed, sizeof(DTCMUsed));
__attribute__((section("._D1_Area"))) CustomHeap D1Heap(D1Used, sizeof(D1Used));
__attribute__((section("._D2_Area"))) CustomHeap D2Heap(D2Used, sizeof(D2Used));
__attribute__((section("._D3_Area"))) CustomHeap D3Heap(D3Used, sizeof(D3Used));

DetectManager Detect::detectManager;

SuperCan canPlus1(&hfdcan1, FDCAN_RX_FIFO0, FDCAN_IT_RX_FIFO0_NEW_MESSAGE);
Motor motor1(&canPlus1, 0x01, Detect_cfg());

