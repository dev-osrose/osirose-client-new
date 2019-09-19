#include "srv_equip_projectile.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvEquipProjectile::ProjectileData& SrvEquipProjectile::ProjectileData::set_type(const uint16_t type) {
    this->data.type = type;
    return *this;
}

uint16_t SrvEquipProjectile::ProjectileData::get_type() const {
    return data.type;
}

SrvEquipProjectile::ProjectileData& SrvEquipProjectile::ProjectileData::set_id(const uint16_t id) {
    this->data.id = id;
    return *this;
}

uint16_t SrvEquipProjectile::ProjectileData::get_id() const {
    return data.id;
}

SrvEquipProjectile::ProjectileData& SrvEquipProjectile::ProjectileData::set_data(const uint16_t data) {
    this->data.data = data;
    return *this;
}

uint16_t SrvEquipProjectile::ProjectileData::get_data() const {
    return data.data;
}

bool SrvEquipProjectile::ProjectileData::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvEquipProjectile::ProjectileData::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEquipProjectile::ProjectileData::size() {
    return sizeof(data);
}


SrvEquipProjectile::SrvEquipProjectile() : CRosePacket(SrvEquipProjectile::PACKET_ID) {}

SrvEquipProjectile::SrvEquipProjectile(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
        return;
    }
    if (!reader.get_iserialize(projectile)) {
        return;
    }
}

SrvEquipProjectile& SrvEquipProjectile::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvEquipProjectile::get_char_id() const {
    return char_id;
}

SrvEquipProjectile& SrvEquipProjectile::set_projectile(const SrvEquipProjectile::ProjectileData projectile) {
    this->projectile = projectile;
    return *this;
}

SrvEquipProjectile::ProjectileData SrvEquipProjectile::get_projectile() const {
    return projectile;
}

SrvEquipProjectile SrvEquipProjectile::create(const uint16_t& char_id, const SrvEquipProjectile::ProjectileData& projectile) {
    SrvEquipProjectile packet;
    packet.set_char_id(char_id);
    packet.set_projectile(projectile);
    return packet;
}

SrvEquipProjectile SrvEquipProjectile::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvEquipProjectile(reader);
}

std::unique_ptr<SrvEquipProjectile> SrvEquipProjectile::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvEquipProjectile>(reader);
}

bool SrvEquipProjectile::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
        return false;
    }
    if (!writer.set_iserialize(projectile)) {
        return false;
    }
    return true;
}

constexpr size_t SrvEquipProjectile::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    size += ProjectileData::size(); // projectile
    return size;
}

