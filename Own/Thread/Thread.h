//
// Created by lhy on 2024/9/17.
//

#ifndef NEW_PRJ_THREAD_H
#define NEW_PRJ_THREAD_H

#ifdef __cplusplus
extern "C" {
#endif
void UserCANTask(void const *argument);
void PidTask(void const * argument);
void StartDefaultTask(void const *argument);
void OS_LedCallback(void const *argument);
void OS_ErrorCallback(void const *argument);
void OS_DetectCallback(void const *argument);
void OS_ChassisCallback(void const *argument);
void OS_MotorCallback(void const *argument);
void OS_RcCallback(void const *argument);
void OS_IMUCallback(void const *argument);

#ifdef __cplusplus
}
#endif


#endif //NEW_PRJ_THREAD_H
