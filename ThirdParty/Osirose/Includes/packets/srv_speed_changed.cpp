#include "srv_speed_changed.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSpeedChanged::SrvSpeedChanged() : CRosePacket(SrvSpeedChanged::PACKET_ID) {}

SrvSpeedChanged::SrvSpeedChanged(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_int16_t(move_speed)) {
        return;
    }
    if (!reader.get_int16_t(attack_speed)) {
        return;
    }
    if (!reader.get_uint8_t(weight)) {
        return;
    }
}

SrvSpeedChanged& SrvSpeedChanged::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSpeedChanged::get_target() const {
    return target;
}

SrvSpeedChanged& SrvSpeedChanged::set_move_speed(const int16_t move_speed) {
    this->move_speed = move_speed;
    return *this;
}

int16_t SrvSpeedChanged::get_move_speed() const {
    return move_speed;
}

SrvSpeedChanged& SrvSpeedChanged::set_attack_speed(const int16_t attack_speed) {
    this->attack_speed = attack_speed;
    return *this;
}

int16_t SrvSpeedChanged::get_attack_speed() const {
    return attack_speed;
}

SrvSpeedChanged& SrvSpeedChanged::set_weight(const uint8_t weight) {
    this->weight = weight;
    return *this;
}

uint8_t SrvSpeedChanged::get_weight() const {
    return weight;
}

SrvSpeedChanged SrvSpeedChanged::create(const uint16_t& target, const int16_t& move_speed, const int16_t& attack_speed, const uint8_t& weight) {
    SrvSpeedChanged packet;
    packet.set_target(target);
    packet.set_move_speed(move_speed);
    packet.set_attack_speed(attack_speed);
    packet.set_weight(weight);
    return packet;
}

SrvSpeedChanged SrvSpeedChanged::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSpeedChanged(reader);
}

std::unique_ptr<SrvSpeedChanged> SrvSpeedChanged::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSpeedChanged>(reader);
}

bool SrvSpeedChanged::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_int16_t(move_speed)) {
        return false;
    }
    if (!writer.set_int16_t(attack_speed)) {
        return false;
    }
    if (!writer.set_uint8_t(weight)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSpeedChanged::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(int16_t); // move_speed
    size += sizeof(int16_t); // attack_speed
    size += sizeof(uint8_t); // weight
    return size;
}

