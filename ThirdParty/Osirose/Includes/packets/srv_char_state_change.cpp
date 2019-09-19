#include "srv_char_state_change.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvCharStateChange::SrvCharStateChange() : CRosePacket(SrvCharStateChange::PACKET_ID) {}

SrvCharStateChange::SrvCharStateChange(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint32_t(flag)) {
        return;
    }
}

SrvCharStateChange& SrvCharStateChange::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvCharStateChange::get_target() const {
    return target;
}

SrvCharStateChange& SrvCharStateChange::set_flag(const uint32_t flag) {
    this->flag = flag;
    return *this;
}

uint32_t SrvCharStateChange::get_flag() const {
    return flag;
}

SrvCharStateChange SrvCharStateChange::create(const uint16_t& target, const uint32_t& flag) {
    SrvCharStateChange packet;
    packet.set_target(target);
    packet.set_flag(flag);
    return packet;
}

SrvCharStateChange SrvCharStateChange::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvCharStateChange(reader);
}

std::unique_ptr<SrvCharStateChange> SrvCharStateChange::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvCharStateChange>(reader);
}

bool SrvCharStateChange::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint32_t(flag)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCharStateChange::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(uint32_t); // flag
    return size;
}

