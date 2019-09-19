#include "cli_skill_cast_self.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSkillCastSelf::CliSkillCastSelf() : CRosePacket(CliSkillCastSelf::PACKET_ID) {}

CliSkillCastSelf::CliSkillCastSelf(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(slot)) {
        return;
    }
}

CliSkillCastSelf& CliSkillCastSelf::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliSkillCastSelf::get_slot() const {
    return slot;
}

CliSkillCastSelf CliSkillCastSelf::create(const uint8_t& slot) {
    CliSkillCastSelf packet;
    packet.set_slot(slot);
    return packet;
}

CliSkillCastSelf CliSkillCastSelf::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSkillCastSelf(reader);
}

std::unique_ptr<CliSkillCastSelf> CliSkillCastSelf::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSkillCastSelf>(reader);
}

bool CliSkillCastSelf::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    return true;
}

constexpr size_t CliSkillCastSelf::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // slot
    return size;
}

