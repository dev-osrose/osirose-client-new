#include "cli_equip_item_ride.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliEquipItemRide::CliEquipItemRide() : CRosePacket(CliEquipItemRide::PACKET_ID) {}

CliEquipItemRide::CliEquipItemRide(CRoseReader reader) : CRosePacket(reader) {
    uint16_t slot_temp;
    if (!reader.get_uint16_t(slot_temp)) {
        return;
    }
    slot = static_cast<EquippedPositionRide>(slot_temp);
    
    if (!reader.get_uint16_t(index)) {
        return;
    }
}

CliEquipItemRide& CliEquipItemRide::set_slot(const CliEquipItemRide::EquippedPositionRide slot) {
    this->slot = slot;
    return *this;
}

CliEquipItemRide::EquippedPositionRide CliEquipItemRide::get_slot() const {
    return slot;
}

CliEquipItemRide& CliEquipItemRide::set_index(const uint16_t index) {
    this->index = index;
    return *this;
}

uint16_t CliEquipItemRide::get_index() const {
    return index;
}

CliEquipItemRide CliEquipItemRide::create(const CliEquipItemRide::EquippedPositionRide& slot, const uint16_t& index) {
    CliEquipItemRide packet;
    packet.set_slot(slot);
    packet.set_index(index);
    return packet;
}

CliEquipItemRide CliEquipItemRide::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliEquipItemRide(reader);
}

std::unique_ptr<CliEquipItemRide> CliEquipItemRide::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliEquipItemRide>(reader);
}

bool CliEquipItemRide::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(slot)) {
        return false;
    }
    if (!writer.set_uint16_t(index)) {
        return false;
    }
    return true;
}

constexpr size_t CliEquipItemRide::size() {
    size_t size = 0;
    size += sizeof(EquippedPositionRide); // slot
    size += sizeof(uint16_t); // index
    return size;
}

