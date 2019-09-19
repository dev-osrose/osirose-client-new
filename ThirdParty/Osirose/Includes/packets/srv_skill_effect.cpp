#include "srv_skill_effect.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillEffect::SrvSkillEffect() : CRosePacket(SrvSkillEffect::PACKET_ID) {}

SrvSkillEffect::SrvSkillEffect(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint16_t(source)) {
        return;
    }
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_float(amount)) {
        return;
    }
    if (!reader.get_uint8_t(state)) {
        return;
    }
}

SrvSkillEffect& SrvSkillEffect::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillEffect::get_target() const {
    return target;
}

SrvSkillEffect& SrvSkillEffect::set_source(const uint16_t source) {
    this->source = source;
    return *this;
}

uint16_t SrvSkillEffect::get_source() const {
    return source;
}

SrvSkillEffect& SrvSkillEffect::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvSkillEffect::get_id() const {
    return id;
}

SrvSkillEffect& SrvSkillEffect::set_amount(const float amount) {
    this->amount = amount;
    return *this;
}

float SrvSkillEffect::get_amount() const {
    return amount;
}

SrvSkillEffect& SrvSkillEffect::set_state(const uint8_t state) {
    this->state = state;
    return *this;
}

uint8_t SrvSkillEffect::get_state() const {
    return state;
}

SrvSkillEffect SrvSkillEffect::create(const uint16_t& target, const uint16_t& source, const uint16_t& id, const float& amount, const uint8_t& state) {
    SrvSkillEffect packet;
    packet.set_target(target);
    packet.set_source(source);
    packet.set_id(id);
    packet.set_amount(amount);
    packet.set_state(state);
    return packet;
}

SrvSkillEffect SrvSkillEffect::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillEffect(reader);
}

std::unique_ptr<SrvSkillEffect> SrvSkillEffect::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillEffect>(reader);
}

bool SrvSkillEffect::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint16_t(source)) {
        return false;
    }
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_float(amount)) {
        return false;
    }
    if (!writer.set_uint8_t(state)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillEffect::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(uint16_t); // source
    size += sizeof(uint16_t); // id
    size += sizeof(float); // amount
    size += sizeof(uint8_t); // state
    return size;
}

