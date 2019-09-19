#include "srv_skill_cast_target.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillCastTarget::SrvSkillCastTarget() : CRosePacket(SrvSkillCastTarget::PACKET_ID) {}

SrvSkillCastTarget::SrvSkillCastTarget(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(source)) {
        return;
    }
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_int8_t(id)) {
        return;
    }
    if (!reader.get_uint16_t(distance)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
    uint8_t animation_temp;
    if (!reader.get_uint8_t(animation_temp)) {
        return;
    }
    animation = static_cast<MobAnimation>(animation_temp);
    
}

SrvSkillCastTarget& SrvSkillCastTarget::set_source(const uint16_t source) {
    this->source = source;
    return *this;
}

uint16_t SrvSkillCastTarget::get_source() const {
    return source;
}

SrvSkillCastTarget& SrvSkillCastTarget::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillCastTarget::get_target() const {
    return target;
}

SrvSkillCastTarget& SrvSkillCastTarget::set_id(const int8_t id) {
    this->id = id;
    return *this;
}

int8_t SrvSkillCastTarget::get_id() const {
    return id;
}

SrvSkillCastTarget& SrvSkillCastTarget::set_distance(const uint16_t distance) {
    this->distance = distance;
    return *this;
}

uint16_t SrvSkillCastTarget::get_distance() const {
    return distance;
}

SrvSkillCastTarget& SrvSkillCastTarget::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvSkillCastTarget::get_x() const {
    return x;
}

SrvSkillCastTarget& SrvSkillCastTarget::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvSkillCastTarget::get_y() const {
    return y;
}

SrvSkillCastTarget& SrvSkillCastTarget::set_animation(const SrvSkillCastTarget::MobAnimation animation) {
    this->animation = animation;
    return *this;
}

SrvSkillCastTarget::MobAnimation SrvSkillCastTarget::get_animation() const {
    return animation;
}

SrvSkillCastTarget SrvSkillCastTarget::create(const uint16_t& source, const uint16_t& target, const int8_t& id, const uint16_t& distance, const float& x, const float& y) {
    SrvSkillCastTarget packet;
    packet.set_source(source);
    packet.set_target(target);
    packet.set_id(id);
    packet.set_distance(distance);
    packet.set_x(x);
    packet.set_y(y);
    return packet;
}

SrvSkillCastTarget SrvSkillCastTarget::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillCastTarget(reader);
}

std::unique_ptr<SrvSkillCastTarget> SrvSkillCastTarget::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillCastTarget>(reader);
}

bool SrvSkillCastTarget::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(source)) {
        return false;
    }
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_int8_t(id)) {
        return false;
    }
    if (!writer.set_uint16_t(distance)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    if (!writer.set_uint8_t(animation)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillCastTarget::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // source
    size += sizeof(uint16_t); // target
    size += sizeof(int8_t); // id
    size += sizeof(uint16_t); // distance
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(MobAnimation); // animation
    return size;
}

