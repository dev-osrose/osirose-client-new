#include "srv_toggle_move.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvToggleMove::SrvToggleMove() : CRosePacket(SrvToggleMove::PACKET_ID) {}

SrvToggleMove::SrvToggleMove(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(object_id)) {
        return;
    }
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<ToggleMove>(type_temp);
    
    if (!reader.get_uint16_t(run_speed)) {
        return;
    }
}

SrvToggleMove& SrvToggleMove::set_object_id(const uint16_t object_id) {
    this->object_id = object_id;
    return *this;
}

uint16_t SrvToggleMove::get_object_id() const {
    return object_id;
}

SrvToggleMove& SrvToggleMove::set_type(const SrvToggleMove::ToggleMove type) {
    this->type = type;
    return *this;
}

SrvToggleMove::ToggleMove SrvToggleMove::get_type() const {
    return type;
}

SrvToggleMove& SrvToggleMove::set_run_speed(const uint16_t run_speed) {
    this->run_speed = run_speed;
    return *this;
}

uint16_t SrvToggleMove::get_run_speed() const {
    return run_speed;
}

SrvToggleMove SrvToggleMove::create(const SrvToggleMove::ToggleMove& type) {
    SrvToggleMove packet;
    packet.set_type(type);
    return packet;
}

SrvToggleMove SrvToggleMove::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvToggleMove(reader);
}

std::unique_ptr<SrvToggleMove> SrvToggleMove::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvToggleMove>(reader);
}

bool SrvToggleMove::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(object_id)) {
        return false;
    }
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint16_t(run_speed)) {
        return false;
    }
    return true;
}

constexpr size_t SrvToggleMove::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // object_id
    size += sizeof(ToggleMove); // type
    size += sizeof(uint16_t); // run_speed
    return size;
}

