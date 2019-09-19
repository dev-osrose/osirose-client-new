#include "srv_stop.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvStop::SrvStop() : CRosePacket(SrvStop::PACKET_ID) {}

SrvStop::SrvStop(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
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

SrvStop& SrvStop::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvStop::get_char_id() const {
    return char_id;
}

SrvStop& SrvStop::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvStop::get_x() const {
    return x;
}

SrvStop& SrvStop::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvStop::get_y() const {
    return y;
}

SrvStop& SrvStop::set_z(const int16_t z) {
    this->z = z;
    return *this;
}

int16_t SrvStop::get_z() const {
    return z;
}

SrvStop SrvStop::create(const uint16_t& char_id, const float& x, const float& y, const int16_t& z) {
    SrvStop packet;
    packet.set_char_id(char_id);
    packet.set_x(x);
    packet.set_y(y);
    packet.set_z(z);
    return packet;
}

SrvStop SrvStop::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvStop(reader);
}

std::unique_ptr<SrvStop> SrvStop::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvStop>(reader);
}

bool SrvStop::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
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

constexpr size_t SrvStop::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(int16_t); // z
    return size;
}

