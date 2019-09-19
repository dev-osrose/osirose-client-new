#include "srv_move.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvMove::SrvMove() : CRosePacket(SrvMove::PACKET_ID) {}

SrvMove::SrvMove(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_uint16_t(target_id)) {
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
    uint8_t move_mode_temp;
    if (!reader.get_uint8_t(move_mode_temp)) {
        return;
    }
    move_mode = static_cast<MoveMode>(move_mode_temp);
    
}

SrvMove& SrvMove::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvMove::get_id() const {
    return id;
}

SrvMove& SrvMove::set_target_id(const uint16_t target_id) {
    this->target_id = target_id;
    return *this;
}

uint16_t SrvMove::get_target_id() const {
    return target_id;
}

SrvMove& SrvMove::set_distance(const uint16_t distance) {
    this->distance = distance;
    return *this;
}

uint16_t SrvMove::get_distance() const {
    return distance;
}

SrvMove& SrvMove::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvMove::get_x() const {
    return x;
}

SrvMove& SrvMove::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvMove::get_y() const {
    return y;
}

SrvMove& SrvMove::set_z(const uint16_t z) {
    this->z = z;
    return *this;
}

uint16_t SrvMove::get_z() const {
    return z;
}

SrvMove& SrvMove::set_move_mode(const SrvMove::MoveMode move_mode) {
    this->move_mode = move_mode;
    return *this;
}

SrvMove::MoveMode SrvMove::get_move_mode() const {
    return move_mode;
}

SrvMove SrvMove::create(const uint16_t& id) {
    SrvMove packet;
    packet.set_id(id);
    return packet;
}

SrvMove SrvMove::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvMove(reader);
}

std::unique_ptr<SrvMove> SrvMove::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvMove>(reader);
}

bool SrvMove::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint16_t(target_id)) {
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
    if (!writer.set_uint8_t(move_mode)) {
        return false;
    }
    return true;
}

constexpr size_t SrvMove::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint16_t); // target_id
    size += sizeof(uint16_t); // distance
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(uint16_t); // z
    size += sizeof(MoveMode); // move_mode
    return size;
}

