#include "cli_craft_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliCraftReq::CliCraftReq() : CRosePacket(CliCraftReq::PACKET_ID) {}

CliCraftReq::CliCraftReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_int8_t(type)) {
        return;
    }
    if (!reader.get_int8_t(id)) {
        return;
    }
    for (size_t index = 0; index < 4; ++index) {
        if (!reader.get_int16_t(material_slots[index])) {
            return;
        }
    }
}

CliCraftReq& CliCraftReq::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliCraftReq::get_slot() const {
    return slot;
}

CliCraftReq& CliCraftReq::set_type(const int8_t type) {
    this->type = type;
    return *this;
}

int8_t CliCraftReq::get_type() const {
    return type;
}

CliCraftReq& CliCraftReq::set_id(const int8_t id) {
    this->id = id;
    return *this;
}

int8_t CliCraftReq::get_id() const {
    return id;
}

CliCraftReq& CliCraftReq::set_material_slots(const std::array<int16_t, 4>& material_slots) {
    this->material_slots = material_slots;
    return *this;
}

CliCraftReq& CliCraftReq::set_material_slots(const int16_t& material_slots, size_t index) {
    this->material_slots[index] = material_slots;
    return *this;
}

const std::array<int16_t, 4>& CliCraftReq::get_material_slots() const {
    return material_slots;
}

const int16_t& CliCraftReq::get_material_slots(size_t index) const {
    return material_slots[index];
}

CliCraftReq CliCraftReq::create(const uint8_t& slot, const int8_t& type, const int8_t& id, const std::array<int16_t, 4>& material_slots) {
    CliCraftReq packet;
    packet.set_slot(slot);
    packet.set_type(type);
    packet.set_id(id);
    packet.set_material_slots(material_slots);
    return packet;
}

CliCraftReq CliCraftReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliCraftReq(reader);
}

std::unique_ptr<CliCraftReq> CliCraftReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliCraftReq>(reader);
}

bool CliCraftReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_int8_t(type)) {
        return false;
    }
    if (!writer.set_int8_t(id)) {
        return false;
    }
    for (const auto& elem : material_slots) {
        if (!writer.set_int16_t(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t CliCraftReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // slot
    size += sizeof(int8_t); // type
    size += sizeof(int8_t); // id
    size += sizeof(int16_t) * 4; // material_slots
    return size;
}

