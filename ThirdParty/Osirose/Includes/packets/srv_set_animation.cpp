#include "srv_set_animation.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetAnimation::SrvSetAnimation() : CRosePacket(SrvSetAnimation::PACKET_ID) {}

SrvSetAnimation::SrvSetAnimation(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_uint16_t(value)) {
        return;
    }
    if (!reader.get_uint16_t(object_id)) {
        return;
    }
}

SrvSetAnimation& SrvSetAnimation::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvSetAnimation::get_id() const {
    return id;
}

SrvSetAnimation& SrvSetAnimation::set_value(const uint16_t value) {
    this->value = value;
    return *this;
}

uint16_t SrvSetAnimation::get_value() const {
    return value;
}

SrvSetAnimation& SrvSetAnimation::set_object_id(const uint16_t object_id) {
    this->object_id = object_id;
    return *this;
}

uint16_t SrvSetAnimation::get_object_id() const {
    return object_id;
}

SrvSetAnimation SrvSetAnimation::create() {
    SrvSetAnimation packet;
    return packet;
}

SrvSetAnimation SrvSetAnimation::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetAnimation(reader);
}

std::unique_ptr<SrvSetAnimation> SrvSetAnimation::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetAnimation>(reader);
}

bool SrvSetAnimation::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint16_t(value)) {
        return false;
    }
    if (!writer.set_uint16_t(object_id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetAnimation::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint16_t); // value
    size += sizeof(uint16_t); // object_id
    return size;
}

