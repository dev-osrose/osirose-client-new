#include "cli_drop_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliDropItem::CliDropItem() : CRosePacket(CliDropItem::PACKET_ID) {}

CliDropItem::CliDropItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(index)) {
        return;
    }
    if (!reader.get_uint32_t(quantity)) {
        return;
    }
}

CliDropItem& CliDropItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t CliDropItem::get_index() const {
    return index;
}

CliDropItem& CliDropItem::set_quantity(const uint32_t quantity) {
    this->quantity = quantity;
    return *this;
}

uint32_t CliDropItem::get_quantity() const {
    return quantity;
}

CliDropItem CliDropItem::create(const uint8_t& index, const uint32_t& quantity) {
    CliDropItem packet;
    packet.set_index(index);
    packet.set_quantity(quantity);
    return packet;
}

CliDropItem CliDropItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliDropItem(reader);
}

std::unique_ptr<CliDropItem> CliDropItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliDropItem>(reader);
}

bool CliDropItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    if (!writer.set_uint32_t(quantity)) {
        return false;
    }
    return true;
}

constexpr size_t CliDropItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // index
    size += sizeof(uint32_t); // quantity
    return size;
}

