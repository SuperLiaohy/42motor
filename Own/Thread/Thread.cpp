//
// Created by lhy on 2024/9/17.
//

#include "Thread.h"

#include "CppTask.h"

#include "ThreadConfig.h"


void StartDefaultTask(void const *argument) {
    UNUSED(argument);

    LedTask();

}

void OS_LedCallback(void const *argument) {
    UNUSED(argument);
    LedTask();
}

void UserCANTask(void const *argument) {
    UNUSED(argument);
    CanTask();
}

void PidTask(void const * argument){
    UNUSED(argument);
    UserPidTask();
}