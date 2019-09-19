#include "srv_event_add.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvEventAdd::SrvEventAdd() : CRosePacket(SrvEventAdd::PACKET_ID) {}

SrvEventAdd::SrvEventAdd(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_int8_t(x)) {
        return;
    }
    if (!reader.get_int8_t(y)) {
        return;
    }
    if (!reader.get_uint16_t(event_id)) {
        return;
    }
    if (!reader.get_int16_t(status)) {
        return;
    }
}

SrvEventAdd& SrvEventAdd::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvEventAdd::get_id() const {
    return id;
}

SrvEventAdd& SrvEventAdd::set_x(const int8_t x) {
    this->x = x;
    return *this;
}

int8_t SrvEventAdd::get_x() const {
    return x;
}

SrvEventAdd& SrvEventAdd::set_y(const int8_t y) {
    this->y = y;
    return *this;
}

int8_t SrvEventAdd::get_y() const {
    return y;
}

SrvEventAdd& SrvEventAdd::set_event_id(const uint16_t event_id) {
    this->event_id = event_id;
    return *this;
}

uint16_t SrvEventAdd::get_event_id() const {
    return event_id;
}

SrvEventAdd& SrvEventAdd::set_status(const int16_t status) {
    this->status = status;
    return *this;
}

int16_t SrvEventAdd::get_status() const {
    return status;
}

SrvEventAdd SrvEventAdd::create(const uint16_t& id, const int8_t& x, const int8_t& y, const uint16_t& event_id, const int16_t& status) {
    SrvEventAdd packet;
    packet.set_id(id);
    packet.set_x(x);
    packet.set_y(y);
    packet.set_event_id(event_id);
    packet.set_status(status);
    return packet;
}

SrvEventAdd SrvEventAdd::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvEventAdd(reader);
}

std::unique_ptr<SrvEventAdd> SrvEventAdd::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvEventAdd>(reader);
}

bool SrvEventAdd::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_int8_t(x)) {
        return false;
    }
    if (!writer.set_int8_t(y)) {
        return false;
    }
    if (!writer.set_uint16_t(event_id)) {
        return false;
    }
    if (!writer.set_int16_t(status)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEventAdd::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(int8_t); // x
    size += sizeof(int8_t); // y
    size += sizeof(uint16_t); // event_id
    size += sizeof(int16_t); // status
    return size;
}

