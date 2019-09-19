#include "cli_skill_cast_target.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSkillCastTarget::CliSkillCastTarget() : CRosePacket(CliSkillCastTarget::PACKET_ID) {}

CliSkillCastTarget::CliSkillCastTarget(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint8_t(slot)) {
        return;
    }
}

CliSkillCastTarget& CliSkillCastTarget::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t CliSkillCastTarget::get_target() const {
    return target;
}

CliSkillCastTarget& CliSkillCastTarget::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliSkillCastTarget::get_slot() const {
    return slot;
}

CliSkillCastTarget CliSkillCastTarget::create(const uint16_t& target, const uint8_t& slot) {
    CliSkillCastTarget packet;
    packet.set_target(target);
    packet.set_slot(slot);
    return packet;
}

CliSkillCastTarget CliSkillCastTarget::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSkillCastTarget(reader);
}

std::unique_ptr<CliSkillCastTarget> CliSkillCastTarget::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSkillCastTarget>(reader);
}

bool CliSkillCastTarget::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    return true;
}

constexpr size_t CliSkillCastTarget::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(uint8_t); // slot
    return size;
}

