#include "srv_levelup.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvLevelup::SrvLevelup() : CRosePacket(SrvLevelup::PACKET_ID) {}

SrvLevelup::SrvLevelup(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_int16_t(level)) {
        return;
    }
    if (!reader.get_int64_t(exp)) {
        return;
    }
    if (!reader.get_int16_t(stat_points)) {
        return;
    }
    if (!reader.get_int16_t(skill_points)) {
        return;
    }
}

SrvLevelup& SrvLevelup::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvLevelup::get_id() const {
    return id;
}

SrvLevelup& SrvLevelup::set_level(const int16_t level) {
    this->level = level;
    return *this;
}

int16_t SrvLevelup::get_level() const {
    return level;
}

SrvLevelup& SrvLevelup::set_exp(const int64_t exp) {
    this->exp = exp;
    return *this;
}

int64_t SrvLevelup::get_exp() const {
    return exp;
}

SrvLevelup& SrvLevelup::set_stat_points(const int16_t stat_points) {
    this->stat_points = stat_points;
    return *this;
}

int16_t SrvLevelup::get_stat_points() const {
    return stat_points;
}

SrvLevelup& SrvLevelup::set_skill_points(const int16_t skill_points) {
    this->skill_points = skill_points;
    return *this;
}

int16_t SrvLevelup::get_skill_points() const {
    return skill_points;
}

SrvLevelup SrvLevelup::create(const uint16_t& id, const int16_t& level, const int64_t& exp, const int16_t& stat_points, const int16_t& skill_points) {
    SrvLevelup packet;
    packet.set_id(id);
    packet.set_level(level);
    packet.set_exp(exp);
    packet.set_stat_points(stat_points);
    packet.set_skill_points(skill_points);
    return packet;
}

SrvLevelup SrvLevelup::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvLevelup(reader);
}

std::unique_ptr<SrvLevelup> SrvLevelup::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvLevelup>(reader);
}

bool SrvLevelup::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_int16_t(level)) {
        return false;
    }
    if (!writer.set_int64_t(exp)) {
        return false;
    }
    if (!writer.set_int16_t(stat_points)) {
        return false;
    }
    if (!writer.set_int16_t(skill_points)) {
        return false;
    }
    return true;
}

constexpr size_t SrvLevelup::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(int16_t); // level
    size += sizeof(int64_t); // exp
    size += sizeof(int16_t); // stat_points
    size += sizeof(int16_t); // skill_points
    return size;
}

