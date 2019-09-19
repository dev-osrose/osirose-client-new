#include "srv_ride_state_change.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvRideStateChange::SrvRideStateChange() : CRosePacket(SrvRideStateChange::PACKET_ID) {}

SrvRideStateChange::SrvRideStateChange(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int8_t(enabled)) {
        return;
    }
    if (!reader.get_uint32_t(cooldown)) {
        return;
    }
    if (!reader.get_int16_t(max_hp)) {
        return;
    }
    if (!reader.get_uint16_t(target)) {
        return;
    }
}

SrvRideStateChange& SrvRideStateChange::set_enabled(const int8_t enabled) {
    this->enabled = enabled;
    return *this;
}

int8_t SrvRideStateChange::get_enabled() const {
    return enabled;
}

SrvRideStateChange& SrvRideStateChange::set_cooldown(const uint32_t cooldown) {
    this->cooldown = cooldown;
    return *this;
}

uint32_t SrvRideStateChange::get_cooldown() const {
    return cooldown;
}

SrvRideStateChange& SrvRideStateChange::set_max_hp(const int16_t max_hp) {
    this->max_hp = max_hp;
    return *this;
}

int16_t SrvRideStateChange::get_max_hp() const {
    return max_hp;
}

SrvRideStateChange& SrvRideStateChange::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvRideStateChange::get_target() const {
    return target;
}

SrvRideStateChange SrvRideStateChange::create(const int8_t& enabled, const uint32_t& cooldown, const int16_t& max_hp, const uint16_t& target) {
    SrvRideStateChange packet;
    packet.set_enabled(enabled);
    packet.set_cooldown(cooldown);
    packet.set_max_hp(max_hp);
    packet.set_target(target);
    return packet;
}

SrvRideStateChange SrvRideStateChange::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvRideStateChange(reader);
}

std::unique_ptr<SrvRideStateChange> SrvRideStateChange::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvRideStateChange>(reader);
}

bool SrvRideStateChange::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int8_t(enabled)) {
        return false;
    }
    if (!writer.set_uint32_t(cooldown)) {
        return false;
    }
    if (!writer.set_int16_t(max_hp)) {
        return false;
    }
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    return true;
}

constexpr size_t SrvRideStateChange::size() {
    size_t size = 0;
    size += sizeof(int8_t); // enabled
    size += sizeof(uint32_t); // cooldown
    size += sizeof(int16_t); // max_hp
    size += sizeof(uint16_t); // target
    return size;
}

