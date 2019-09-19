#include "srv_event_status.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvEventStatus::SrvEventStatus() : CRosePacket(SrvEventStatus::PACKET_ID) {}

SrvEventStatus::SrvEventStatus(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(object_id)) {
        return;
    }
    if (!reader.get_int16_t(status)) {
        return;
    }
}

SrvEventStatus& SrvEventStatus::set_object_id(const uint16_t object_id) {
    this->object_id = object_id;
    return *this;
}

uint16_t SrvEventStatus::get_object_id() const {
    return object_id;
}

SrvEventStatus& SrvEventStatus::set_status(const int16_t status) {
    this->status = status;
    return *this;
}

int16_t SrvEventStatus::get_status() const {
    return status;
}

SrvEventStatus SrvEventStatus::create(const uint16_t& object_id, const int16_t& status) {
    SrvEventStatus packet;
    packet.set_object_id(object_id);
    packet.set_status(status);
    return packet;
}

SrvEventStatus SrvEventStatus::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvEventStatus(reader);
}

std::unique_ptr<SrvEventStatus> SrvEventStatus::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvEventStatus>(reader);
}

bool SrvEventStatus::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(object_id)) {
        return false;
    }
    if (!writer.set_int16_t(status)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEventStatus::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // object_id
    size += sizeof(int16_t); // status
    return size;
}

