#include "cli_set_animation.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSetAnimation::CliSetAnimation() : CRosePacket(CliSetAnimation::PACKET_ID) {}

CliSetAnimation::CliSetAnimation(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_uint16_t(value)) {
        return;
    }
}

CliSetAnimation& CliSetAnimation::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t CliSetAnimation::get_id() const {
    return id;
}

CliSetAnimation& CliSetAnimation::set_value(const uint16_t value) {
    this->value = value;
    return *this;
}

uint16_t CliSetAnimation::get_value() const {
    return value;
}

CliSetAnimation CliSetAnimation::create(const uint16_t& id, const uint16_t& value) {
    CliSetAnimation packet;
    packet.set_id(id);
    packet.set_value(value);
    return packet;
}

CliSetAnimation CliSetAnimation::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSetAnimation(reader);
}

std::unique_ptr<CliSetAnimation> CliSetAnimation::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSetAnimation>(reader);
}

bool CliSetAnimation::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint16_t(value)) {
        return false;
    }
    return true;
}

constexpr size_t CliSetAnimation::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint16_t); // value
    return size;
}

