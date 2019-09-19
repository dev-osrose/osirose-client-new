#include "srv_use_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvUseItem::SrvUseItem() : CRosePacket(SrvUseItem::PACKET_ID) {}

SrvUseItem::SrvUseItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
        return;
    }
    if (!reader.get_uint16_t(item_id)) {
        return;
    }
    if (!reader.get_uint8_t(index)) {
        return;
    }
}

SrvUseItem& SrvUseItem::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvUseItem::get_char_id() const {
    return char_id;
}

SrvUseItem& SrvUseItem::set_item_id(const uint16_t item_id) {
    this->item_id = item_id;
    return *this;
}

uint16_t SrvUseItem::get_item_id() const {
    return item_id;
}

SrvUseItem& SrvUseItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t SrvUseItem::get_index() const {
    return index;
}

SrvUseItem SrvUseItem::create(const uint16_t& char_id, const uint16_t& item_id, const uint8_t& index) {
    SrvUseItem packet;
    packet.set_char_id(char_id);
    packet.set_item_id(item_id);
    packet.set_index(index);
    return packet;
}

SrvUseItem SrvUseItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvUseItem(reader);
}

std::unique_ptr<SrvUseItem> SrvUseItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvUseItem>(reader);
}

bool SrvUseItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
        return false;
    }
    if (!writer.set_uint16_t(item_id)) {
        return false;
    }
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    return true;
}

constexpr size_t SrvUseItem::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    size += sizeof(uint16_t); // item_id
    size += sizeof(uint8_t); // index
    return size;
}

