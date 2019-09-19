#include "srv_equip_item_ride.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvEquipItemRide::EquippedItem& SrvEquipItemRide::EquippedItem::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvEquipItemRide::EquippedItem::get_id() const {
    return data.id;
}

SrvEquipItemRide::EquippedItem& SrvEquipItemRide::EquippedItem::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvEquipItemRide::EquippedItem::get_gem_opt() const {
    return data.gem_opt;
}

SrvEquipItemRide::EquippedItem& SrvEquipItemRide::EquippedItem::set_socket(const unsigned int socket) {
    this->data.socket = socket;
    return *this;
}

unsigned int SrvEquipItemRide::EquippedItem::get_socket() const {
    return data.socket;
}

SrvEquipItemRide::EquippedItem& SrvEquipItemRide::EquippedItem::set_grade(const unsigned int grade) {
    this->data.grade = grade;
    return *this;
}

unsigned int SrvEquipItemRide::EquippedItem::get_grade() const {
    return data.grade;
}

SrvEquipItemRide::EquippedItem& SrvEquipItemRide::EquippedItem::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t SrvEquipItemRide::EquippedItem::get_data() const {
    return data.data;
}

bool SrvEquipItemRide::EquippedItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvEquipItemRide::EquippedItem::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEquipItemRide::EquippedItem::size() {
    return sizeof(data);
}


SrvEquipItemRide::SrvEquipItemRide() : CRosePacket(SrvEquipItemRide::PACKET_ID) {}

SrvEquipItemRide::SrvEquipItemRide(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
        return;
    }
    uint16_t slot_temp;
    if (!reader.get_uint16_t(slot_temp)) {
        return;
    }
    slot = static_cast<EquippedPositionRide>(slot_temp);
    
    if (!reader.get_iserialize(item)) {
        return;
    }
    if (!reader.get_uint16_t(move_speed)) {
        return;
    }
}

SrvEquipItemRide& SrvEquipItemRide::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvEquipItemRide::get_char_id() const {
    return char_id;
}

SrvEquipItemRide& SrvEquipItemRide::set_slot(const SrvEquipItemRide::EquippedPositionRide slot) {
    this->slot = slot;
    return *this;
}

SrvEquipItemRide::EquippedPositionRide SrvEquipItemRide::get_slot() const {
    return slot;
}

SrvEquipItemRide& SrvEquipItemRide::set_item(const SrvEquipItemRide::EquippedItem item) {
    this->item = item;
    return *this;
}

SrvEquipItemRide::EquippedItem SrvEquipItemRide::get_item() const {
    return item;
}

SrvEquipItemRide& SrvEquipItemRide::set_move_speed(const uint16_t move_speed) {
    this->move_speed = move_speed;
    return *this;
}

uint16_t SrvEquipItemRide::get_move_speed() const {
    return move_speed;
}

SrvEquipItemRide SrvEquipItemRide::create(const uint16_t& char_id, const SrvEquipItemRide::EquippedPositionRide& slot, const SrvEquipItemRide::EquippedItem& item, const uint16_t& move_speed) {
    SrvEquipItemRide packet;
    packet.set_char_id(char_id);
    packet.set_slot(slot);
    packet.set_item(item);
    packet.set_move_speed(move_speed);
    return packet;
}

SrvEquipItemRide SrvEquipItemRide::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvEquipItemRide(reader);
}

std::unique_ptr<SrvEquipItemRide> SrvEquipItemRide::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvEquipItemRide>(reader);
}

bool SrvEquipItemRide::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
        return false;
    }
    if (!writer.set_uint16_t(slot)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    if (!writer.set_uint16_t(move_speed)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEquipItemRide::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    size += sizeof(EquippedPositionRide); // slot
    size += EquippedItem::size(); // item
    size += sizeof(uint16_t); // move_speed
    return size;
}

