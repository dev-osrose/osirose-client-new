#include "cli_trade_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliTradeItem::CliTradeItem() : CRosePacket(CliTradeItem::PACKET_ID) {}

CliTradeItem::CliTradeItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_uint16_t(index)) {
        return;
    }
    if (!reader.get_uint32_t(amount)) {
        return;
    }
}

CliTradeItem& CliTradeItem::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliTradeItem::get_slot() const {
    return slot;
}

CliTradeItem& CliTradeItem::set_index(const uint16_t index) {
    this->index = index;
    return *this;
}

uint16_t CliTradeItem::get_index() const {
    return index;
}

CliTradeItem& CliTradeItem::set_amount(const uint32_t amount) {
    this->amount = amount;
    return *this;
}

uint32_t CliTradeItem::get_amount() const {
    return amount;
}

CliTradeItem CliTradeItem::create(const uint8_t& slot, const uint16_t& index, const uint32_t& amount) {
    CliTradeItem packet;
    packet.set_slot(slot);
    packet.set_index(index);
    packet.set_amount(amount);
    return packet;
}

CliTradeItem CliTradeItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliTradeItem(reader);
}

std::unique_ptr<CliTradeItem> CliTradeItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliTradeItem>(reader);
}

bool CliTradeItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_uint16_t(index)) {
        return false;
    }
    if (!writer.set_uint32_t(amount)) {
        return false;
    }
    return true;
}

constexpr size_t CliTradeItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // slot
    size += sizeof(uint16_t); // index
    size += sizeof(uint32_t); // amount
    return size;
}

