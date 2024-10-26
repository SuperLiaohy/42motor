//
// Created by Administrator on 24-10-3.
//

#include "RemoteControl/RemoteControl.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "cmsis_os.h"

#ifdef __cplusplus
}
#endif

#include "ThreadConfig.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    UNUSED(huart);
#if USING_UART_IT

    auto &serial = liaohy::serial;

    if (huart == serial.uart) {

//    liaohy::serial.println("Hello, World!");
        serial.tx_buffer = serial.rx_buffer->read(reinterpret_cast<uint16_t &>(serial.len));
        serial.print();
//    uint8_t ch[15] = {0};
//    HAL_UART_Receive_IT(&huart1, (uint8_t *) ch, 15);

        serial.read_it(15);
//        HAL_UART_Receive_IT(serial.uart, serial.rx_buffer->next(15)->data, 15);

    }

#endif
}

int16_t x,y;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
    UNUSED(Size);
#if USING_UART_IDLE

    if (huart == remote_control.uartPlus.uart) {
        remote_control.update();
    }
    if (huart == uartPlus10.uart){

    }

#endif
}