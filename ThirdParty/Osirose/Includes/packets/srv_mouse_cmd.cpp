#include "srv_mouse_cmd.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvMouseCmd::SrvMouseCmd() : CRosePacket(SrvMouseCmd::PACKET_ID) {}

SrvMouseCmd::SrvMouseCmd(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_uint16_t(targetId)) {
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

SrvMouseCmd& SrvMouseCmd::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvMouseCmd::get_id() const {
    return id;
}

SrvMouseCmd& SrvMouseCmd::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t SrvMouseCmd::get_targetId() const {
    return targetId;
}

SrvMouseCmd& SrvMouseCmd::set_distance(const uint16_t distance) {
    this->distance = distance;
    return *this;
}

uint16_t SrvMouseCmd::get_distance() const {
    return distance;
}

SrvMouseCmd& SrvMouseCmd::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvMouseCmd::get_x() const {
    return x;
}

SrvMouseCmd& SrvMouseCmd::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvMouseCmd::get_y() const {
    return y;
}

SrvMouseCmd& SrvMouseCmd::set_z(const uint16_t z) {
    this->z = z;
    return *this;
}

uint16_t SrvMouseCmd::get_z() const {
    return z;
}

SrvMouseCmd SrvMouseCmd::create(const uint16_t& id) {
    SrvMouseCmd packet;
    packet.set_id(id);
    return packet;
}

SrvMouseCmd SrvMouseCmd::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvMouseCmd(reader);
}

std::unique_ptr<SrvMouseCmd> SrvMouseCmd::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvMouseCmd>(reader);
}

bool SrvMouseCmd::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint16_t(targetId)) {
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

constexpr size_t SrvMouseCmd::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint16_t); // targetId
    size += sizeof(uint16_t); // distance
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(uint16_t); // z
    return size;
}

