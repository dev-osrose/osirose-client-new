#include "srv_clear_status.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvClearStatus::SrvClearStatus() : CRosePacket(SrvClearStatus::PACKET_ID) {}

SrvClearStatus::SrvClearStatus(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint32_t(status)) {
        return;
    }
    if (!reader.get_int16_t(hp)) {
        return;
    }
    if (!reader.get_int16_t(mp)) {
        return;
    }
}

SrvClearStatus& SrvClearStatus::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvClearStatus::get_target() const {
    return target;
}

SrvClearStatus& SrvClearStatus::set_status(const uint32_t status) {
    this->status = status;
    return *this;
}

uint32_t SrvClearStatus::get_status() const {
    return status;
}

SrvClearStatus& SrvClearStatus::set_hp(const int16_t hp) {
    this->hp = hp;
    return *this;
}

int16_t SrvClearStatus::get_hp() const {
    return hp;
}

SrvClearStatus& SrvClearStatus::set_mp(const int16_t mp) {
    this->mp = mp;
    return *this;
}

int16_t SrvClearStatus::get_mp() const {
    return mp;
}

SrvClearStatus SrvClearStatus::create(const uint16_t& target, const uint32_t& status, const int16_t& hp, const int16_t& mp) {
    SrvClearStatus packet;
    packet.set_target(target);
    packet.set_status(status);
    packet.set_hp(hp);
    packet.set_mp(mp);
    return packet;
}

SrvClearStatus SrvClearStatus::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvClearStatus(reader);
}

std::unique_ptr<SrvClearStatus> SrvClearStatus::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvClearStatus>(reader);
}

bool SrvClearStatus::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint32_t(status)) {
        return false;
    }
    if (!writer.set_int16_t(hp)) {
        return false;
    }
    if (!writer.set_int16_t(mp)) {
        return false;
    }
    return true;
}

constexpr size_t SrvClearStatus::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(uint32_t); // status
    size += sizeof(int16_t); // hp
    size += sizeof(int16_t); // mp
    return size;
}

