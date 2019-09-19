#include "cli_use_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliUseItem::CliUseItem() : CRosePacket(CliUseItem::PACKET_ID) {}

CliUseItem::CliUseItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(index)) {
        return;
    }
    if (!reader.get_uint16_t(item_id)) {
        return;
    }
}

CliUseItem& CliUseItem::set_index(const uint16_t index) {
    this->index = index;
    return *this;
}

uint16_t CliUseItem::get_index() const {
    return index;
}

CliUseItem& CliUseItem::set_item_id(const uint16_t item_id) {
    this->item_id = item_id;
    return *this;
}

uint16_t CliUseItem::get_item_id() const {
    return item_id;
}

CliUseItem CliUseItem::create(const uint16_t& index, const uint16_t& item_id) {
    CliUseItem packet;
    packet.set_index(index);
    packet.set_item_id(item_id);
    return packet;
}

CliUseItem CliUseItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliUseItem(reader);
}

std::unique_ptr<CliUseItem> CliUseItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliUseItem>(reader);
}

bool CliUseItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(index)) {
        return false;
    }
    if (!writer.set_uint16_t(item_id)) {
        return false;
    }
    return true;
}

constexpr size_t CliUseItem::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // index
    size += sizeof(uint16_t); // item_id
    return size;
}

