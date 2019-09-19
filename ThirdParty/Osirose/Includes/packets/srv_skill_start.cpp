#include "srv_skill_start.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillStart::SrvSkillStart() : CRosePacket(SrvSkillStart::PACKET_ID) {}

SrvSkillStart::SrvSkillStart(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
}

SrvSkillStart& SrvSkillStart::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillStart::get_target() const {
    return target;
}

SrvSkillStart SrvSkillStart::create(const uint16_t& target) {
    SrvSkillStart packet;
    packet.set_target(target);
    return packet;
}

SrvSkillStart SrvSkillStart::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillStart(reader);
}

std::unique_ptr<SrvSkillStart> SrvSkillStart::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillStart>(reader);
}

bool SrvSkillStart::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillStart::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    return size;
}

