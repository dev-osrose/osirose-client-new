#include "srv_skill_learn.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillLearn::SrvSkillLearn() : CRosePacket(SrvSkillLearn::PACKET_ID) {}

SrvSkillLearn::SrvSkillLearn(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<SkillLearnResult>(result_temp);
    
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_int16_t(id)) {
        return;
    }
    if (!reader.get_int16_t(points)) {
        return;
    }
}

SrvSkillLearn& SrvSkillLearn::set_result(const SrvSkillLearn::SkillLearnResult result) {
    this->result = result;
    return *this;
}

SrvSkillLearn::SkillLearnResult SrvSkillLearn::get_result() const {
    return result;
}

SrvSkillLearn& SrvSkillLearn::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t SrvSkillLearn::get_slot() const {
    return slot;
}

SrvSkillLearn& SrvSkillLearn::set_id(const int16_t id) {
    this->id = id;
    return *this;
}

int16_t SrvSkillLearn::get_id() const {
    return id;
}

SrvSkillLearn& SrvSkillLearn::set_points(const int16_t points) {
    this->points = points;
    return *this;
}

int16_t SrvSkillLearn::get_points() const {
    return points;
}

SrvSkillLearn SrvSkillLearn::create(const SrvSkillLearn::SkillLearnResult& result, const uint8_t& slot, const int16_t& id, const int16_t& points) {
    SrvSkillLearn packet;
    packet.set_result(result);
    packet.set_slot(slot);
    packet.set_id(id);
    packet.set_points(points);
    return packet;
}

SrvSkillLearn SrvSkillLearn::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillLearn(reader);
}

std::unique_ptr<SrvSkillLearn> SrvSkillLearn::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillLearn>(reader);
}

bool SrvSkillLearn::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_int16_t(id)) {
        return false;
    }
    if (!writer.set_int16_t(points)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillLearn::size() {
    size_t size = 0;
    size += sizeof(SkillLearnResult); // result
    size += sizeof(uint8_t); // slot
    size += sizeof(int16_t); // id
    size += sizeof(int16_t); // points
    return size;
}

