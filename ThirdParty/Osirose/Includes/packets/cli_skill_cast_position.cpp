#include "cli_skill_cast_position.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSkillCastPosition::CliSkillCastPosition() : CRosePacket(CliSkillCastPosition::PACKET_ID) {}

CliSkillCastPosition::CliSkillCastPosition(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
}

CliSkillCastPosition& CliSkillCastPosition::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliSkillCastPosition::get_slot() const {
    return slot;
}

CliSkillCastPosition& CliSkillCastPosition::set_x(const float x) {
    this->x = x;
    return *this;
}

float CliSkillCastPosition::get_x() const {
    return x;
}

CliSkillCastPosition& CliSkillCastPosition::set_y(const float y) {
    this->y = y;
    return *this;
}

float CliSkillCastPosition::get_y() const {
    return y;
}

CliSkillCastPosition CliSkillCastPosition::create(const uint8_t& slot, const float& x, const float& y) {
    CliSkillCastPosition packet;
    packet.set_slot(slot);
    packet.set_x(x);
    packet.set_y(y);
    return packet;
}

CliSkillCastPosition CliSkillCastPosition::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSkillCastPosition(reader);
}

std::unique_ptr<CliSkillCastPosition> CliSkillCastPosition::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSkillCastPosition>(reader);
}

bool CliSkillCastPosition::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    return true;
}

constexpr size_t CliSkillCastPosition::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // slot
    size += sizeof(float); // x
    size += sizeof(float); // y
    return size;
}

