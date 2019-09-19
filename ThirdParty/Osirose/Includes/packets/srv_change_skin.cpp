#include "srv_change_skin.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvChangeSkin::SrvChangeSkin() : CRosePacket(SrvChangeSkin::PACKET_ID) {}

SrvChangeSkin::SrvChangeSkin(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
        return;
    }
    uint16_t slot_temp;
    if (!reader.get_uint16_t(slot_temp)) {
        return;
    }
    slot = static_cast<EquippedPositionRide>(slot_temp);
    
    if (!reader.get_uint32_t(item_id)) {
        return;
    }
}

SrvChangeSkin& SrvChangeSkin::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvChangeSkin::get_char_id() const {
    return char_id;
}

SrvChangeSkin& SrvChangeSkin::set_slot(const SrvChangeSkin::EquippedPositionRide slot) {
    this->slot = slot;
    return *this;
}

SrvChangeSkin::EquippedPositionRide SrvChangeSkin::get_slot() const {
    return slot;
}

SrvChangeSkin& SrvChangeSkin::set_item_id(const uint32_t item_id) {
    this->item_id = item_id;
    return *this;
}

uint32_t SrvChangeSkin::get_item_id() const {
    return item_id;
}

SrvChangeSkin SrvChangeSkin::create(const uint16_t& char_id, const SrvChangeSkin::EquippedPositionRide& slot, const uint32_t& item_id) {
    SrvChangeSkin packet;
    packet.set_char_id(char_id);
    packet.set_slot(slot);
    packet.set_item_id(item_id);
    return packet;
}

SrvChangeSkin SrvChangeSkin::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvChangeSkin(reader);
}

std::unique_ptr<SrvChangeSkin> SrvChangeSkin::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvChangeSkin>(reader);
}

bool SrvChangeSkin::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
        return false;
    }
    if (!writer.set_uint16_t(slot)) {
        return false;
    }
    if (!writer.set_uint32_t(item_id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvChangeSkin::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    size += sizeof(EquippedPositionRide); // slot
    size += sizeof(uint32_t); // item_id
    return size;
}

