#include "cli_craft_status.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliCraftStatus::CliCraftStatus() : CRosePacket(CliCraftStatus::PACKET_ID) {}

CliCraftStatus::CliCraftStatus(CRoseReader reader) : CRosePacket(reader) {
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

CliCraftStatus& CliCraftStatus::set_stats(const CliCraftStatus::CraftStatus stats) {
    this->stats = stats;
    return *this;
}

CliCraftStatus::CraftStatus CliCraftStatus::get_stats() const {
    return stats;
}

CliCraftStatus& CliCraftStatus::set_type(const int8_t type) {
    this->type = type;
    return *this;
}

int8_t CliCraftStatus::get_type() const {
    return type;
}

CliCraftStatus& CliCraftStatus::set_id(const int16_t id) {
    this->id = id;
    return *this;
}

int16_t CliCraftStatus::get_id() const {
    return id;
}

CliCraftStatus CliCraftStatus::create(const CliCraftStatus::CraftStatus& stats, const int8_t& type, const int16_t& id) {
    CliCraftStatus packet;
    packet.set_stats(stats);
    packet.set_type(type);
    packet.set_id(id);
    return packet;
}

CliCraftStatus CliCraftStatus::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliCraftStatus(reader);
}

std::unique_ptr<CliCraftStatus> CliCraftStatus::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliCraftStatus>(reader);
}

bool CliCraftStatus::pack(CRoseBasePolicy& writer) const {
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

constexpr size_t CliCraftStatus::size() {
    size_t size = 0;
    size += sizeof(CraftStatus); // stats
    size += sizeof(int8_t); // type
    size += sizeof(int16_t); // id
    return size;
}

