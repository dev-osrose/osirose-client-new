#include "srv_global_vars.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvGlobalVars::SrvGlobalVars() : CRosePacket(SrvGlobalVars::PACKET_ID) {}

SrvGlobalVars::SrvGlobalVars(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int16_t(world_product)) {
        return;
    }
    if (!reader.get_int32_t(update_time)) {
        return;
    }
    if (!reader.get_int16_t(world_rate)) {
        return;
    }
    if (!reader.get_uint8_t(town_rate)) {
        return;
    }
    for (size_t index = 0; index < MAX_SELL_TYPE; ++index) {
        if (!reader.get_uint8_t(item_rate[index])) {
            return;
        }
    }
    if (!reader.get_uint32_t(flags)) {
        return;
    }
}

SrvGlobalVars& SrvGlobalVars::set_world_product(const int16_t world_product) {
    this->world_product = world_product;
    return *this;
}

int16_t SrvGlobalVars::get_world_product() const {
    return world_product;
}

SrvGlobalVars& SrvGlobalVars::set_update_time(const int32_t update_time) {
    this->update_time = update_time;
    return *this;
}

int32_t SrvGlobalVars::get_update_time() const {
    return update_time;
}

SrvGlobalVars& SrvGlobalVars::set_world_rate(const int16_t world_rate) {
    this->world_rate = world_rate;
    return *this;
}

int16_t SrvGlobalVars::get_world_rate() const {
    return world_rate;
}

SrvGlobalVars& SrvGlobalVars::set_town_rate(const uint8_t town_rate) {
    this->town_rate = town_rate;
    return *this;
}

uint8_t SrvGlobalVars::get_town_rate() const {
    return town_rate;
}

SrvGlobalVars& SrvGlobalVars::set_item_rate(const std::array<uint8_t, MAX_SELL_TYPE>& item_rate) {
    this->item_rate = item_rate;
    return *this;
}

SrvGlobalVars& SrvGlobalVars::set_item_rate(const uint8_t& item_rate, size_t index) {
    this->item_rate[index] = item_rate;
    return *this;
}

const std::array<uint8_t, MAX_SELL_TYPE>& SrvGlobalVars::get_item_rate() const {
    return item_rate;
}

const uint8_t& SrvGlobalVars::get_item_rate(size_t index) const {
    return item_rate[index];
}

SrvGlobalVars& SrvGlobalVars::set_flags(const uint32_t flags) {
    this->flags = flags;
    return *this;
}

uint32_t SrvGlobalVars::get_flags() const {
    return flags;
}

SrvGlobalVars SrvGlobalVars::create() {
    SrvGlobalVars packet;
    return packet;
}

SrvGlobalVars SrvGlobalVars::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvGlobalVars(reader);
}

std::unique_ptr<SrvGlobalVars> SrvGlobalVars::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvGlobalVars>(reader);
}

bool SrvGlobalVars::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int16_t(world_product)) {
        return false;
    }
    if (!writer.set_int32_t(update_time)) {
        return false;
    }
    if (!writer.set_int16_t(world_rate)) {
        return false;
    }
    if (!writer.set_uint8_t(town_rate)) {
        return false;
    }
    for (const auto& elem : item_rate) {
        if (!writer.set_uint8_t(elem)) {
            return false;
        }
    }
    if (!writer.set_uint32_t(flags)) {
        return false;
    }
    return true;
}

constexpr size_t SrvGlobalVars::size() {
    size_t size = 0;
    size += sizeof(int16_t); // world_product
    size += sizeof(int32_t); // update_time
    size += sizeof(int16_t); // world_rate
    size += sizeof(uint8_t); // town_rate
    size += sizeof(uint8_t) * MAX_SELL_TYPE; // item_rate
    size += sizeof(uint32_t); // flags
    return size;
}

