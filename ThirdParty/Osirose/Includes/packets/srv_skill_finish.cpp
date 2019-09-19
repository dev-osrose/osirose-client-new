#include "srv_skill_finish.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillFinish::SrvSkillFinish() : CRosePacket(SrvSkillFinish::PACKET_ID) {}

SrvSkillFinish::SrvSkillFinish(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint16_t(id)) {
        return;
    }
}

SrvSkillFinish& SrvSkillFinish::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillFinish::get_target() const {
    return target;
}

SrvSkillFinish& SrvSkillFinish::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvSkillFinish::get_id() const {
    return id;
}

SrvSkillFinish SrvSkillFinish::create(const uint16_t& target, const uint16_t& id) {
    SrvSkillFinish packet;
    packet.set_target(target);
    packet.set_id(id);
    return packet;
}

SrvSkillFinish SrvSkillFinish::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillFinish(reader);
}

std::unique_ptr<SrvSkillFinish> SrvSkillFinish::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillFinish>(reader);
}

bool SrvSkillFinish::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillFinish::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(uint16_t); // id
    return size;
}

