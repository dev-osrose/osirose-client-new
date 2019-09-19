#include "srv_skill_cancel.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillCancel::SrvSkillCancel() : CRosePacket(SrvSkillCancel::PACKET_ID) {}

SrvSkillCancel::SrvSkillCancel(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<SkillCancelResult>(result_temp);
    
}

SrvSkillCancel& SrvSkillCancel::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillCancel::get_target() const {
    return target;
}

SrvSkillCancel& SrvSkillCancel::set_result(const SrvSkillCancel::SkillCancelResult result) {
    this->result = result;
    return *this;
}

SrvSkillCancel::SkillCancelResult SrvSkillCancel::get_result() const {
    return result;
}

SrvSkillCancel SrvSkillCancel::create(const uint16_t& target, const SrvSkillCancel::SkillCancelResult& result) {
    SrvSkillCancel packet;
    packet.set_target(target);
    packet.set_result(result);
    return packet;
}

SrvSkillCancel SrvSkillCancel::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillCancel(reader);
}

std::unique_ptr<SrvSkillCancel> SrvSkillCancel::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillCancel>(reader);
}

bool SrvSkillCancel::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillCancel::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(SkillCancelResult); // result
    return size;
}

