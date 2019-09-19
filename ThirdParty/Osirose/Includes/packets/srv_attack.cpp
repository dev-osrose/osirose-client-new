#include "srv_attack.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvAttack::SrvAttack() : CRosePacket(SrvAttack::PACKET_ID) {}

SrvAttack::SrvAttack(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(attackerId)) {
        return;
    }
    if (!reader.get_uint16_t(defenderId)) {
        return;
    }
    if (!reader.get_uint16_t(distance)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
    if (!reader.get_uint16_t(z)) {
        return;
    }
}

SrvAttack& SrvAttack::set_attackerId(const uint16_t attackerId) {
    this->attackerId = attackerId;
    return *this;
}

uint16_t SrvAttack::get_attackerId() const {
    return attackerId;
}

SrvAttack& SrvAttack::set_defenderId(const uint16_t defenderId) {
    this->defenderId = defenderId;
    return *this;
}

uint16_t SrvAttack::get_defenderId() const {
    return defenderId;
}

SrvAttack& SrvAttack::set_distance(const uint16_t distance) {
    this->distance = distance;
    return *this;
}

uint16_t SrvAttack::get_distance() const {
    return distance;
}

SrvAttack& SrvAttack::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvAttack::get_x() const {
    return x;
}

SrvAttack& SrvAttack::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvAttack::get_y() const {
    return y;
}

SrvAttack& SrvAttack::set_z(const uint16_t z) {
    this->z = z;
    return *this;
}

uint16_t SrvAttack::get_z() const {
    return z;
}

SrvAttack SrvAttack::create(const uint16_t& attackerId, const uint16_t& defenderId) {
    SrvAttack packet;
    packet.set_attackerId(attackerId);
    packet.set_defenderId(defenderId);
    return packet;
}

SrvAttack SrvAttack::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvAttack(reader);
}

std::unique_ptr<SrvAttack> SrvAttack::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvAttack>(reader);
}

bool SrvAttack::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(attackerId)) {
        return false;
    }
    if (!writer.set_uint16_t(defenderId)) {
        return false;
    }
    if (!writer.set_uint16_t(distance)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    if (!writer.set_uint16_t(z)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAttack::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // attackerId
    size += sizeof(uint16_t); // defenderId
    size += sizeof(uint16_t); // distance
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(uint16_t); // z
    return size;
}

