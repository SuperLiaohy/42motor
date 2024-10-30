//
// Created by Administrator on 24-10-26.
//

#include "Motor.h"
void append_crc8(uint8_t *data, uint8_t len) {
    uint32_t crc = 0;
    for (int i = 0; i < len - 1; i++) {
        crc += data[i];
    }
    data[len - 1] = crc & 0xff;
}

void Motor::read_n_encoder() {
    uint8_t data[9]={addr,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    data[1] = 0x30;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1], 2);
}

void Motor::read_total_encoder() {
    uint8_t data[9]={addr};
    data[1] = 0x31;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_speed() {
    uint8_t data[9]={addr};
    data[1] = 0x32;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_pluse() {
    uint8_t data[9]={addr};
    data[1] = 0x33;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_pos_error() {
    uint8_t data[9]={addr};
    data[1] = 0x39;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_enable_state() {
    uint8_t data[9]={addr};
    data[1] = 0x3A;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_back_zero_state() {
    uint8_t data[9]={addr};
    data[1] = 0x3B;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_cancel_block_state() {
    uint8_t data[9]={addr};
    data[1] = 0x3D;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::read_block_state() {
    uint8_t data[9]={addr};
    data[1] = 0x3E;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1]);
}

void Motor::cal() {
    uint8_t data[9]={addr};
    data[1] = 0x80;
    data[2] = 0x00;
    append_crc8(data, 4);
//    canPlus->write(&data[1]);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_mode(run_mode mode) {
    uint8_t data[9]={addr};
    data[1] = 0x82;
    data[2] = mode;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_current(uint16_t value) {
    uint8_t data[9]={addr};
    data[1] = 0x83;
    data[2] = value >> 8;
    data[3] = value;
    append_crc8(data, 5);
    canPlus->send(addr, &data[1],4);
}

void Motor::set_current_percent(uint8_t holdMa) {
    uint8_t data[9]={addr};
    data[1] = 0x9B;
    data[2] = holdMa;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_MStep(uint8_t micstep) {
    uint8_t data[9]={addr};
    data[1] = 0x84;
    data[2] = micstep;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_En_active_pin_state(Motor::en_active_pin_state state) {
    uint8_t data[9]={addr};
    data[1] = 0x85;
    data[2] = state;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_spin_dir(Motor::direction dir) {
    uint8_t data[9]={addr};
    data[1] = 0x86;
    data[2] = dir;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_autosdd(Motor::ifEnable if_enable) {
    uint8_t data[9]={addr};
    data[1] = 0x87;
    data[2] = if_enable;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);

}

void Motor::set_block_protect(Motor::ifEnable if_enable) {
    uint8_t data[9]={addr};
    data[1] = 0x88;
    data[2] = if_enable;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::enable_MPlyer(Motor::ifEnable if_enable) {
    uint8_t data[9]={addr};
    data[1] = 0x89;
    data[2] = if_enable;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_Can_rate(bitRate rate) {
    uint8_t data[9]={addr};
    data[1] = 0x8A;
    data[2] = rate;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_address(uint16_t address) {
    uint8_t data[9]={addr};
    data[1] = 0x8B;
    data[2] = address >> 8;
    data[3] = address;
    append_crc8(data, 5);
    canPlus->send(addr, &data[1],4);
}

void Motor::enable_ack_and_auto_feedback(Motor::ifEnable ack_if_enable, Motor::ifEnable auto_feedback_if_enable) {
    uint8_t data[9]={addr};
    data[1] = 0x8C;
    data[2] = ack_if_enable;
    data[3] = auto_feedback_if_enable;
    append_crc8(data, 6);
    canPlus->send(addr, &data[1],5);
}

void Motor::set_key_lock(Motor::ifEnable if_enable) {
    uint8_t data[9]={addr};
    data[1] = 0x8F;
    data[2] = if_enable;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_address_group(uint16_t groupAdd) {
    uint8_t data[9]={addr};
    data[1] = 0x9D;
    data[2] = groupAdd >> 8;
    data[3] = groupAdd;
    append_crc8(data, 5);
    canPlus->send(addr, &data[1],4);
}

void Motor::set_defult_param() {
    uint8_t data[9]={addr};
    data[1] = 0x3F;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1],2);
}

void Motor::restart() {
    uint8_t data[9]={addr};
    data[1] = 0x41;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1],2);
}

void Motor::read_version() {
    uint8_t data[9]={addr};
    data[1] = 0x40;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1],2);
}

void Motor::raed_run_state() {
    uint8_t data[9]={addr};
    data[1] = 0xF1;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1],2);
}

void Motor::enable_run_state(Motor::ifEnable if_enable) {
    uint8_t data[9]={addr};
    data[1] = 0xF3;
    data[2] = if_enable;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::set_stop() {
    uint8_t data[9]={addr};
    data[1] = 0xF7;
    append_crc8(data, 3);
    canPlus->send(addr, &data[1],2);
}

void Motor::dir_speed_acc_ctrl(Motor::direction dir, uint16_t speed, uint8_t acc) {
    uint8_t data[9]={addr};
    data[1] = 0xF6;
    data[2] = dir<<7;
    data[2] |= (speed >> 8);
    data[3] = speed & 0xff;
    data[4] = acc;
    append_crc8(data, 6);
    canPlus->send(addr, &data[1],5);
}

void Motor::acc_stop_ctrl(uint8_t acc) {
    uint8_t data[9]={addr};
    data[1] = 0xF6;
    data[4] = acc;
    append_crc8(data, 6);
    canPlus->send(addr, &data[1],5);
}

void Motor::save_param() {
    uint8_t data[9]={addr};
    data[1] = 0xFF;
    data[2] = 0xC8;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::clear_param() {
    uint8_t data[9]={addr};
    data[1] = 0xFF;
    data[2] = 0xCA;
    append_crc8(data, 4);
    canPlus->send(addr, &data[1],3);
}

void Motor::pos_pluse_relative_ctrl(Motor::direction dir, uint16_t speed, uint8_t acc, uint32_t pluse) {
    uint8_t data[9]={addr};
    data[1] = 0xFD;
    data[2] = dir<<7;
    data[2] |= (speed >> 8);
    data[3] = speed & 0xff;
    data[4] = acc;
    data[5] = pluse >> 16;
    data[6] = (pluse >> 8) & 0xff;
    data[7] = pluse & 0xff;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::stop_pos_pluse_relative_ctrl(uint8_t acc) {
    uint8_t data[9]={addr};
    data[1] = 0xFD;
    data[4] = acc;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::pos_pluse_absolute_ctrl(uint16_t speed, uint8_t acc, uint32_t pluse) {
    uint8_t data[9]={addr};
    data[1] = 0xFE;
    data[2] = speed >> 8;
    data[3] = speed & 0xff;
    data[4] = acc;
    data[5] = pluse >> 16;
    data[6] = (pluse >> 8) & 0xff;
    data[7] = pluse & 0xff;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::stop_pos_pluse_absolute_ctrl(uint8_t acc) {
    uint8_t data[9]={addr};
    data[1] = 0xFE;
    data[4] = acc;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::set_pos_axis_relative(Motor::direction dir, uint16_t speed, uint8_t acc, int32_t axis) {
    uint8_t data[9]={addr};
    data[1] = 0xF4;
    data[2] = dir<<7;
    data[2] = speed >> 8;
    data[3] = speed & 0xff;
    data[4] = acc;
    data[5] = (axis >> 16) & 0xff;
    data[6] = (axis >> 8) & 0xff;
    data[7] = axis & 0xff;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::stop_pos_axis_relative(uint8_t acc) {
    uint8_t data[9]={addr};
    data[1] = 0xF4;
    data[4] = acc;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::set_pos_axis_absolute(uint16_t speed, uint8_t acc, int32_t axis) {
    uint8_t data[9]={addr};
    data[1] = 0xF5;
    data[2] = speed >> 8;
    data[3] = speed & 0xff;
    data[4] = acc;
    data[5] = (axis >> 16) & 0xff;
    data[6] = (axis >> 8) & 0xff;
    data[7] = axis & 0xff;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

void Motor::stop_pos_axis_absolute(uint8_t acc) {
    uint8_t data[9]={addr};
    data[1] = 0xF5;
    data[4] = acc;
    append_crc8(data, 9);
    canPlus->send(addr, &data[1],8);
}

