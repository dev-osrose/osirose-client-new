#include "srv_set_item_life.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetItemLife::SrvSetItemLife() : CRosePacket(SrvSetItemLife::PACKET_ID) {}

SrvSetItemLife::SrvSetItemLife(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(index)) {
        return;
    }
    if (!reader.get_uint16_t(life)) {
        return;
    }
}

SrvSetItemLife& SrvSetItemLife::set_index(const uint16_t index) {
    this->index = index;
    return *this;
}

uint16_t SrvSetItemLife::get_index() const {
    return index;
}

SrvSetItemLife& SrvSetItemLife::set_life(const uint16_t life) {
    this->life = life;
    return *this;
}

uint16_t SrvSetItemLife::get_life() const {
    return life;
}

SrvSetItemLife SrvSetItemLife::create(const uint16_t& index, const uint16_t& life) {
    SrvSetItemLife packet;
    packet.set_index(index);
    packet.set_life(life);
    return packet;
}

SrvSetItemLife SrvSetItemLife::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetItemLife(reader);
}

std::unique_ptr<SrvSetItemLife> SrvSetItemLife::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetItemLife>(reader);
}

bool SrvSetItemLife::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(index)) {
        return false;
    }
    if (!writer.set_uint16_t(life)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetItemLife::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // index
    size += sizeof(uint16_t); // life
    return size;
}

