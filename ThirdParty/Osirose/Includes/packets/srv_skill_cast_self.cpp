#include "srv_skill_cast_self.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillCastSelf::SrvSkillCastSelf() : CRosePacket(SrvSkillCastSelf::PACKET_ID) {}

SrvSkillCastSelf::SrvSkillCastSelf(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_int8_t(id)) {
        return;
    }
    uint8_t animation_temp;
    if (!reader.get_uint8_t(animation_temp)) {
        return;
    }
    animation = static_cast<MobAnimation>(animation_temp);
    
}

SrvSkillCastSelf& SrvSkillCastSelf::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillCastSelf::get_target() const {
    return target;
}

SrvSkillCastSelf& SrvSkillCastSelf::set_id(const int8_t id) {
    this->id = id;
    return *this;
}

int8_t SrvSkillCastSelf::get_id() const {
    return id;
}

SrvSkillCastSelf& SrvSkillCastSelf::set_animation(const SrvSkillCastSelf::MobAnimation animation) {
    this->animation = animation;
    return *this;
}

SrvSkillCastSelf::MobAnimation SrvSkillCastSelf::get_animation() const {
    return animation;
}

SrvSkillCastSelf SrvSkillCastSelf::create(const uint16_t& target, const int8_t& id) {
    SrvSkillCastSelf packet;
    packet.set_target(target);
    packet.set_id(id);
    return packet;
}

SrvSkillCastSelf SrvSkillCastSelf::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillCastSelf(reader);
}

std::unique_ptr<SrvSkillCastSelf> SrvSkillCastSelf::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillCastSelf>(reader);
}

bool SrvSkillCastSelf::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_int8_t(id)) {
        return false;
    }
    if (!writer.set_uint8_t(animation)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillCastSelf::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(int8_t); // id
    size += sizeof(MobAnimation); // animation
    return size;
}

