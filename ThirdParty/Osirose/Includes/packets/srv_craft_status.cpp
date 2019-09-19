#include "srv_craft_status.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvCraftStatus::SrvCraftStatus() : CRosePacket(SrvCraftStatus::PACKET_ID) {}

SrvCraftStatus::SrvCraftStatus(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    uint8_t stats_temp;
    if (!reader.get_uint8_t(stats_temp)) {
        return;
    }
    stats = static_cast<CraftStatus>(stats_temp);
    
    if (!reader.get_int8_t(type)) {
        return;
    }
    if (!reader.get_int16_t(id)) {
        return;
    }
}

SrvCraftStatus& SrvCraftStatus::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvCraftStatus::get_target() const {
    return target;
}

SrvCraftStatus& SrvCraftStatus::set_stats(const SrvCraftStatus::CraftStatus stats) {
    this->stats = stats;
    return *this;
}

SrvCraftStatus::CraftStatus SrvCraftStatus::get_stats() const {
    return stats;
}

SrvCraftStatus& SrvCraftStatus::set_type(const int8_t type) {
    this->type = type;
    return *this;
}

int8_t SrvCraftStatus::get_type() const {
    return type;
}

SrvCraftStatus& SrvCraftStatus::set_id(const int16_t id) {
    this->id = id;
    return *this;
}

int16_t SrvCraftStatus::get_id() const {
    return id;
}

SrvCraftStatus SrvCraftStatus::create(const uint16_t& target, const SrvCraftStatus::CraftStatus& stats, const int8_t& type, const int16_t& id) {
    SrvCraftStatus packet;
    packet.set_target(target);
    packet.set_stats(stats);
    packet.set_type(type);
    packet.set_id(id);
    return packet;
}

SrvCraftStatus SrvCraftStatus::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvCraftStatus(reader);
}

std::unique_ptr<SrvCraftStatus> SrvCraftStatus::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvCraftStatus>(reader);
}

bool SrvCraftStatus::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint8_t(stats)) {
        return false;
    }
    if (!writer.set_int8_t(type)) {
        return false;
    }
    if (!writer.set_int16_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftStatus::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(CraftStatus); // stats
    size += sizeof(int8_t); // type
    size += sizeof(int16_t); // id
    return size;
}

