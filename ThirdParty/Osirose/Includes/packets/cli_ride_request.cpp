#include "cli_ride_request.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliRideRequest::CliRideRequest() : CRosePacket(CliRideRequest::PACKET_ID) {}

CliRideRequest::CliRideRequest(CRoseReader reader) : CRosePacket(reader) {
    uint8_t action_temp;
    if (!reader.get_uint8_t(action_temp)) {
        return;
    }
    action = static_cast<RideAction>(action_temp);
    
    if (!reader.get_uint16_t(owner)) {
        return;
    }
    if (!reader.get_uint32_t(guest)) {
        return;
    }
}

CliRideRequest& CliRideRequest::set_action(const CliRideRequest::RideAction action) {
    this->action = action;
    return *this;
}

CliRideRequest::RideAction CliRideRequest::get_action() const {
    return action;
}

CliRideRequest& CliRideRequest::set_owner(const uint16_t owner) {
    this->owner = owner;
    return *this;
}

uint16_t CliRideRequest::get_owner() const {
    return owner;
}

CliRideRequest& CliRideRequest::set_guest(const uint32_t guest) {
    this->guest = guest;
    return *this;
}

uint32_t CliRideRequest::get_guest() const {
    return guest;
}

CliRideRequest CliRideRequest::create(const CliRideRequest::RideAction& action, const uint16_t& owner, const uint32_t& guest) {
    CliRideRequest packet;
    packet.set_action(action);
    packet.set_owner(owner);
    packet.set_guest(guest);
    return packet;
}

CliRideRequest CliRideRequest::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliRideRequest(reader);
}

std::unique_ptr<CliRideRequest> CliRideRequest::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliRideRequest>(reader);
}

bool CliRideRequest::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(action)) {
        return false;
    }
    if (!writer.set_uint16_t(owner)) {
        return false;
    }
    if (!writer.set_uint32_t(guest)) {
        return false;
    }
    return true;
}

constexpr size_t CliRideRequest::size() {
    size_t size = 0;
    size += sizeof(RideAction); // action
    size += sizeof(uint16_t); // owner
    size += sizeof(uint32_t); // guest
    return size;
}

