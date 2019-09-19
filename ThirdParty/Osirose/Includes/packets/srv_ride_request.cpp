#include "srv_ride_request.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvRideRequest::SrvRideRequest() : CRosePacket(SrvRideRequest::PACKET_ID) {}

SrvRideRequest::SrvRideRequest(CRoseReader reader) : CRosePacket(reader) {
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

SrvRideRequest& SrvRideRequest::set_action(const SrvRideRequest::RideAction action) {
    this->action = action;
    return *this;
}

SrvRideRequest::RideAction SrvRideRequest::get_action() const {
    return action;
}

SrvRideRequest& SrvRideRequest::set_owner(const uint16_t owner) {
    this->owner = owner;
    return *this;
}

uint16_t SrvRideRequest::get_owner() const {
    return owner;
}

SrvRideRequest& SrvRideRequest::set_guest(const uint32_t guest) {
    this->guest = guest;
    return *this;
}

uint32_t SrvRideRequest::get_guest() const {
    return guest;
}

SrvRideRequest SrvRideRequest::create(const SrvRideRequest::RideAction& action, const uint16_t& owner, const uint32_t& guest) {
    SrvRideRequest packet;
    packet.set_action(action);
    packet.set_owner(owner);
    packet.set_guest(guest);
    return packet;
}

SrvRideRequest SrvRideRequest::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvRideRequest(reader);
}

std::unique_ptr<SrvRideRequest> SrvRideRequest::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvRideRequest>(reader);
}

bool SrvRideRequest::pack(CRoseBasePolicy& writer) const {
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

constexpr size_t SrvRideRequest::size() {
    size_t size = 0;
    size += sizeof(RideAction); // action
    size += sizeof(uint16_t); // owner
    size += sizeof(uint32_t); // guest
    return size;
}

