#include "srv_trade.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvTrade::SrvTrade() : CRosePacket(SrvTrade::PACKET_ID) {}

SrvTrade::SrvTrade(CRoseReader reader) : CRosePacket(reader) {
    uint8_t state_temp;
    if (!reader.get_uint8_t(state_temp)) {
        return;
    }
    state = static_cast<TradeState>(state_temp);
    
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint8_t(index)) {
        return;
    }
}

SrvTrade& SrvTrade::set_state(const SrvTrade::TradeState state) {
    this->state = state;
    return *this;
}

SrvTrade::TradeState SrvTrade::get_state() const {
    return state;
}

SrvTrade& SrvTrade::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvTrade::get_target() const {
    return target;
}

SrvTrade& SrvTrade::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t SrvTrade::get_index() const {
    return index;
}

SrvTrade SrvTrade::create(const SrvTrade::TradeState& state, const uint16_t& target) {
    SrvTrade packet;
    packet.set_state(state);
    packet.set_target(target);
    return packet;
}

SrvTrade SrvTrade::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvTrade(reader);
}

std::unique_ptr<SrvTrade> SrvTrade::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvTrade>(reader);
}

bool SrvTrade::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(state)) {
        return false;
    }
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    return true;
}

constexpr size_t SrvTrade::size() {
    size_t size = 0;
    size += sizeof(TradeState); // state
    size += sizeof(uint16_t); // target
    size += sizeof(uint8_t); // index
    return size;
}

