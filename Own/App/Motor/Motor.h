//
// Created by Administrator on 24-10-26.
//

#ifndef CAN_42MOTOR_MOTOR_H
#define CAN_42MOTOR_MOTOR_H

#include "CAN/SuperCan.h"
#include "Crc/Crc.h"
#include "Detect/Detect.h"

class Motor {

public:
    Motor(SuperCan *_canPlus, uint8_t _addr, Detect_cfg detectCfg) : addr(_addr), canPlus(_canPlus), detect(detectCfg) {};
    void read_n_encoder();
    void read_total_encoder();
    void read_speed();
    void read_pluse();
    void read_pos_error();
    void read_enable_state();
    void read_back_zero_state();
    void read_cancel_block_state();
    void read_block_state();

    void cal();

    enum run_mode{
        CR_OPEN = 0x00,
        CR_CLOSE = 0x01,
        CR_vFOC = 0x02,
        SR_OPEN = 0x03,
        SR_CLOSE = 0x04,
        SR_vFOC = 0x05,
    };
    void set_mode(run_mode mode);
    void set_current(uint16_t value);
    void set_current_percent(uint8_t holdMa);
    void set_MStep(uint8_t micstep);
    enum en_active_pin_state{
        EN_ACTIVE_LOW = 0x00,
        EN_ACTIVE_HIGH = 0x01,
        EN_ACTIVE_HOLD = 0x02,
    };
    void set_En_active_pin_state(en_active_pin_state state);
    enum direction{
        DIR_POSITIVE = 0x00,
        DIR_NEGATIVE = 0x01,
    };
    void set_spin_dir(direction dir);

    enum ifEnable{
        ENABLE = 0x01,
        DISABLE = 0x00,
    };
    void set_autosdd(ifEnable if_enable);
    void set_block_protect(ifEnable if_enable);
    void enable_MPlyer(ifEnable if_enable);

    enum bitRate{
        CAN_125K = 0x00,
        CAN_250K = 0x01,
        CAN_500K = 0x02,
        CAN_1M = 0x03,
    };
    void set_Can_rate(bitRate rate);
    void set_address(uint16_t address);

    void enable_ack_and_auto_feedback(ifEnable ack_if_enable, ifEnable auto_feedback_if_enable);
    void set_key_lock(ifEnable if_enable);
    void set_address_group(uint16_t groupAdd);

    void set_limit_param();
    void set_limit_zero();
    void set_zero();

    void set_param();
    void set_limit_remap();

    void set_back_zero();

    void set_defult_param();
    void restart();

    void read_version();

    void raed_run_state();
    void enable_run_state(ifEnable if_enable);

    void set_stop();//不要在电机转速超过1000rpm时调用
    void dir_speed_acc_ctrl(direction dir, uint16_t speed, uint8_t acc);
    void acc_stop_ctrl(uint8_t acc);

    void save_param();
    void clear_param();
    void pos_pluse_relative_ctrl(direction dir, uint16_t speed, uint8_t acc, uint32_t pluse);
    void stop_pos_pluse_relative_ctrl(uint8_t acc);
    void pos_pluse_absolute_ctrl(uint16_t speed, uint8_t acc, uint32_t pluse);
    void stop_pos_pluse_absolute_ctrl(uint8_t acc);

    void set_pos_axis_relative(direction dir, uint16_t speed, uint8_t acc, int32_t axis);
    void stop_pos_axis_relative(uint8_t acc);
    void set_pos_axis_absolute(uint16_t speed, uint8_t acc, int32_t axis);
    void stop_pos_axis_absolute(uint8_t acc);

    struct _raw_data{
        struct _n_encoder{
            int32_t carry;
            int16_t value;
        } n_encoder;
        struct _total_encoder{
            int64_t value;
        } total_encoder;
        struct _speed{
            int16_t value;
        } speed;
    } raw_data;
    uint8_t status;
private:
    uint8_t addr;
    SuperCan *canPlus;
    Detect detect;
};

extern Motor motor1;
#endif //CAN_42MOTOR_MOTOR_H
