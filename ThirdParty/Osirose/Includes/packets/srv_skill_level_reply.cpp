#include "srv_skill_level_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSkillLevelReply::SrvSkillLevelReply() : CRosePacket(SrvSkillLevelReply::PACKET_ID) {}

SrvSkillLevelReply::SrvSkillLevelReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<SkillLevelResult>(result_temp);
    
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

SrvSkillLevelReply& SrvSkillLevelReply::set_result(const SrvSkillLevelReply::SkillLevelResult result) {
    this->result = result;
    return *this;
}

SrvSkillLevelReply::SkillLevelResult SrvSkillLevelReply::get_result() const {
    return result;
}

SrvSkillLevelReply& SrvSkillLevelReply::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t SrvSkillLevelReply::get_slot() const {
    return slot;
}

SrvSkillLevelReply& SrvSkillLevelReply::set_id(const int16_t id) {
    this->id = id;
    return *this;
}

int16_t SrvSkillLevelReply::get_id() const {
    return id;
}

SrvSkillLevelReply& SrvSkillLevelReply::set_points(const int16_t points) {
    this->points = points;
    return *this;
}

int16_t SrvSkillLevelReply::get_points() const {
    return points;
}

SrvSkillLevelReply SrvSkillLevelReply::create(const SrvSkillLevelReply::SkillLevelResult& result, const uint8_t& slot, const int16_t& id, const int16_t& points) {
    SrvSkillLevelReply packet;
    packet.set_result(result);
    packet.set_slot(slot);
    packet.set_id(id);
    packet.set_points(points);
    return packet;
}

SrvSkillLevelReply SrvSkillLevelReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillLevelReply(reader);
}

std::unique_ptr<SrvSkillLevelReply> SrvSkillLevelReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillLevelReply>(reader);
}

bool SrvSkillLevelReply::pack(CRoseBasePolicy& writer) const {
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

constexpr size_t SrvSkillLevelReply::size() {
    size_t size = 0;
    size += sizeof(SkillLevelResult); // result
    size += sizeof(uint8_t); // slot
    size += sizeof(int16_t); // id
    size += sizeof(int16_t); // points
    return size;
}

