#include "cli_repair_use_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliRepairUseItem::CliRepairUseItem() : CRosePacket(CliRepairUseItem::PACKET_ID) {}

CliRepairUseItem::CliRepairUseItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(index)) {
        return;
    }
    if (!reader.get_uint16_t(target_index)) {
        return;
    }
}

CliRepairUseItem& CliRepairUseItem::set_index(const uint16_t index) {
    this->index = index;
    return *this;
}

uint16_t CliRepairUseItem::get_index() const {
    return index;
}

CliRepairUseItem& CliRepairUseItem::set_target_index(const uint16_t target_index) {
    this->target_index = target_index;
    return *this;
}

uint16_t CliRepairUseItem::get_target_index() const {
    return target_index;
}

CliRepairUseItem CliRepairUseItem::create(const uint16_t& index, const uint16_t& target_index) {
    CliRepairUseItem packet;
    packet.set_index(index);
    packet.set_target_index(target_index);
    return packet;
}

CliRepairUseItem CliRepairUseItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliRepairUseItem(reader);
}

std::unique_ptr<CliRepairUseItem> CliRepairUseItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliRepairUseItem>(reader);
}

bool CliRepairUseItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(index)) {
        return false;
    }
    if (!writer.set_uint16_t(target_index)) {
        return false;
    }
    return true;
}

constexpr size_t CliRepairUseItem::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // index
    size += sizeof(uint16_t); // target_index
    return size;
}

