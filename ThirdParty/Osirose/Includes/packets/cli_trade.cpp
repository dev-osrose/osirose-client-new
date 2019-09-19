#include "cli_trade.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliTrade::CliTrade() : CRosePacket(CliTrade::PACKET_ID) {}

CliTrade::CliTrade(CRoseReader reader) : CRosePacket(reader) {
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

CliTrade& CliTrade::set_state(const CliTrade::TradeState state) {
    this->state = state;
    return *this;
}

CliTrade::TradeState CliTrade::get_state() const {
    return state;
}

CliTrade& CliTrade::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t CliTrade::get_target() const {
    return target;
}

CliTrade& CliTrade::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t CliTrade::get_index() const {
    return index;
}

CliTrade CliTrade::create(const CliTrade::TradeState& state, const uint16_t& target) {
    CliTrade packet;
    packet.set_state(state);
    packet.set_target(target);
    return packet;
}

CliTrade CliTrade::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliTrade(reader);
}

std::unique_ptr<CliTrade> CliTrade::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliTrade>(reader);
}

bool CliTrade::pack(CRoseBasePolicy& writer) const {
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

constexpr size_t CliTrade::size() {
    size_t size = 0;
    size += sizeof(TradeState); // state
    size += sizeof(uint16_t); // target
    size += sizeof(uint8_t); // index
    return size;
}

