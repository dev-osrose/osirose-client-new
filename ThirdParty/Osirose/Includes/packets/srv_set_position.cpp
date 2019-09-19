#include "srv_set_position.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetPosition::SrvSetPosition() : CRosePacket(SrvSetPosition::PACKET_ID) {}

SrvSetPosition::SrvSetPosition(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(charId)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
    if (!reader.get_int16_t(z)) {
        return;
    }
}

SrvSetPosition& SrvSetPosition::set_charId(const uint16_t charId) {
    this->charId = charId;
    return *this;
}

uint16_t SrvSetPosition::get_charId() const {
    return charId;
}

SrvSetPosition& SrvSetPosition::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvSetPosition::get_x() const {
    return x;
}

SrvSetPosition& SrvSetPosition::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvSetPosition::get_y() const {
    return y;
}

SrvSetPosition& SrvSetPosition::set_z(const int16_t z) {
    this->z = z;
    return *this;
}

int16_t SrvSetPosition::get_z() const {
    return z;
}

SrvSetPosition SrvSetPosition::create(const uint16_t& charId, const float& x, const float& y, const int16_t& z) {
    SrvSetPosition packet;
    packet.set_charId(charId);
    packet.set_x(x);
    packet.set_y(y);
    packet.set_z(z);
    return packet;
}

SrvSetPosition SrvSetPosition::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetPosition(reader);
}

std::unique_ptr<SrvSetPosition> SrvSetPosition::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetPosition>(reader);
}

bool SrvSetPosition::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(charId)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    if (!writer.set_int16_t(z)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetPosition::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // charId
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(int16_t); // z
    return size;
}

