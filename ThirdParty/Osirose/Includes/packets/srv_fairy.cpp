#include "srv_fairy.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvFairy::SrvFairy() : CRosePacket(SrvFairy::PACKET_ID) {}

SrvFairy::SrvFairy(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int8_t(enabled)) {
        return;
    }
    if (!reader.get_uint16_t(target)) {
        return;
    }
}

SrvFairy& SrvFairy::set_enabled(const int8_t enabled) {
    this->enabled = enabled;
    return *this;
}

int8_t SrvFairy::get_enabled() const {
    return enabled;
}

SrvFairy& SrvFairy::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvFairy::get_target() const {
    return target;
}

SrvFairy SrvFairy::create(const int8_t& enabled, const uint16_t& target) {
    SrvFairy packet;
    packet.set_enabled(enabled);
    packet.set_target(target);
    return packet;
}

SrvFairy SrvFairy::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvFairy(reader);
}

std::unique_ptr<SrvFairy> SrvFairy::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvFairy>(reader);
}

bool SrvFairy::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int8_t(enabled)) {
        return false;
    }
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    return true;
}

constexpr size_t SrvFairy::size() {
    size_t size = 0;
    size += sizeof(int8_t); // enabled
    size += sizeof(uint16_t); // target
    return size;
}

