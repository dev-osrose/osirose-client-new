#include "srv_equip_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvEquipItem::EquippedItem& SrvEquipItem::EquippedItem::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvEquipItem::EquippedItem::get_id() const {
    return data.id;
}

SrvEquipItem::EquippedItem& SrvEquipItem::EquippedItem::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvEquipItem::EquippedItem::get_gem_opt() const {
    return data.gem_opt;
}

SrvEquipItem::EquippedItem& SrvEquipItem::EquippedItem::set_socket(const unsigned int socket) {
    this->data.socket = socket;
    return *this;
}

unsigned int SrvEquipItem::EquippedItem::get_socket() const {
    return data.socket;
}

SrvEquipItem::EquippedItem& SrvEquipItem::EquippedItem::set_grade(const unsigned int grade) {
    this->data.grade = grade;
    return *this;
}

unsigned int SrvEquipItem::EquippedItem::get_grade() const {
    return data.grade;
}

SrvEquipItem::EquippedItem& SrvEquipItem::EquippedItem::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t SrvEquipItem::EquippedItem::get_data() const {
    return data.data;
}

bool SrvEquipItem::EquippedItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvEquipItem::EquippedItem::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEquipItem::EquippedItem::size() {
    return sizeof(data);
}


SrvEquipItem::SrvEquipItem() : CRosePacket(SrvEquipItem::PACKET_ID) {}

SrvEquipItem::SrvEquipItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_int16_t(slot)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

SrvEquipItem& SrvEquipItem::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvEquipItem::get_id() const {
    return id;
}

SrvEquipItem& SrvEquipItem::set_slot(const int16_t slot) {
    this->slot = slot;
    return *this;
}

int16_t SrvEquipItem::get_slot() const {
    return slot;
}

SrvEquipItem& SrvEquipItem::set_item(const SrvEquipItem::EquippedItem item) {
    this->item = item;
    return *this;
}

SrvEquipItem::EquippedItem SrvEquipItem::get_item() const {
    return item;
}

SrvEquipItem SrvEquipItem::create(const uint16_t& id, const int16_t& slot, const SrvEquipItem::EquippedItem& item) {
    SrvEquipItem packet;
    packet.set_id(id);
    packet.set_slot(slot);
    packet.set_item(item);
    return packet;
}

SrvEquipItem SrvEquipItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvEquipItem(reader);
}

std::unique_ptr<SrvEquipItem> SrvEquipItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvEquipItem>(reader);
}

bool SrvEquipItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_int16_t(slot)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEquipItem::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(int16_t); // slot
    size += EquippedItem::size(); // item
    return size;
}

