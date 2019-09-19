#include "cli_equip_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliEquipItem::CliEquipItem() : CRosePacket(CliEquipItem::PACKET_ID) {}

CliEquipItem::CliEquipItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int16_t(slotTo)) {
        return;
    }
    if (!reader.get_int16_t(slotFrom)) {
        return;
    }
}

CliEquipItem& CliEquipItem::set_slotTo(const int16_t slotTo) {
    this->slotTo = slotTo;
    return *this;
}

int16_t CliEquipItem::get_slotTo() const {
    return slotTo;
}

CliEquipItem& CliEquipItem::set_slotFrom(const int16_t slotFrom) {
    this->slotFrom = slotFrom;
    return *this;
}

int16_t CliEquipItem::get_slotFrom() const {
    return slotFrom;
}

CliEquipItem CliEquipItem::create(const int16_t& slotTo, const int16_t& slotFrom) {
    CliEquipItem packet;
    packet.set_slotTo(slotTo);
    packet.set_slotFrom(slotFrom);
    return packet;
}

CliEquipItem CliEquipItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliEquipItem(reader);
}

std::unique_ptr<CliEquipItem> CliEquipItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliEquipItem>(reader);
}

bool CliEquipItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int16_t(slotTo)) {
        return false;
    }
    if (!writer.set_int16_t(slotFrom)) {
        return false;
    }
    return true;
}

constexpr size_t CliEquipItem::size() {
    size_t size = 0;
    size += sizeof(int16_t); // slotTo
    size += sizeof(int16_t); // slotFrom
    return size;
}

