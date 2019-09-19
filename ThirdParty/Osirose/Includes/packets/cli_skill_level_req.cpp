#include "cli_skill_level_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSkillLevelReq::CliSkillLevelReq() : CRosePacket(CliSkillLevelReq::PACKET_ID) {}

CliSkillLevelReq::CliSkillLevelReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_int16_t(next_index)) {
        return;
    }
}

CliSkillLevelReq& CliSkillLevelReq::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliSkillLevelReq::get_slot() const {
    return slot;
}

CliSkillLevelReq& CliSkillLevelReq::set_next_index(const int16_t next_index) {
    this->next_index = next_index;
    return *this;
}

int16_t CliSkillLevelReq::get_next_index() const {
    return next_index;
}

CliSkillLevelReq CliSkillLevelReq::create(const uint8_t& slot) {
    CliSkillLevelReq packet;
    packet.set_slot(slot);
    return packet;
}

CliSkillLevelReq CliSkillLevelReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSkillLevelReq(reader);
}

std::unique_ptr<CliSkillLevelReq> CliSkillLevelReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSkillLevelReq>(reader);
}

bool CliSkillLevelReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_int16_t(next_index)) {
        return false;
    }
    return true;
}

constexpr size_t CliSkillLevelReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // slot
    size += sizeof(int16_t); // next_index
    return size;
}

