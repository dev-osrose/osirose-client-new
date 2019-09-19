#include "cli_equip_projectile.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


CliEquipProjectile::ProjectileTypeAndIndex& CliEquipProjectile::ProjectileTypeAndIndex::set_type(const uint16_t type) {
    this->data.type = type;
    return *this;
}

uint16_t CliEquipProjectile::ProjectileTypeAndIndex::get_type() const {
    return data.type;
}

CliEquipProjectile::ProjectileTypeAndIndex& CliEquipProjectile::ProjectileTypeAndIndex::set_index(const uint16_t index) {
    this->data.index = index;
    return *this;
}

uint16_t CliEquipProjectile::ProjectileTypeAndIndex::get_index() const {
    return data.index;
}

CliEquipProjectile::ProjectileTypeAndIndex& CliEquipProjectile::ProjectileTypeAndIndex::set_data(const uint16_t data) {
    this->data.data = data;
    return *this;
}

uint16_t CliEquipProjectile::ProjectileTypeAndIndex::get_data() const {
    return data.data;
}

bool CliEquipProjectile::ProjectileTypeAndIndex::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.data)) {
        return false;
    }
    return true;
}

bool CliEquipProjectile::ProjectileTypeAndIndex::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t CliEquipProjectile::ProjectileTypeAndIndex::size() {
    return sizeof(data);
}


CliEquipProjectile::CliEquipProjectile() : CRosePacket(CliEquipProjectile::PACKET_ID) {}

CliEquipProjectile::CliEquipProjectile(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_iserialize(projectile)) {
        return;
    }
}

CliEquipProjectile& CliEquipProjectile::set_projectile(const CliEquipProjectile::ProjectileTypeAndIndex projectile) {
    this->projectile = projectile;
    return *this;
}

CliEquipProjectile::ProjectileTypeAndIndex CliEquipProjectile::get_projectile() const {
    return projectile;
}

CliEquipProjectile CliEquipProjectile::create(const CliEquipProjectile::ProjectileTypeAndIndex& projectile) {
    CliEquipProjectile packet;
    packet.set_projectile(projectile);
    return packet;
}

CliEquipProjectile CliEquipProjectile::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliEquipProjectile(reader);
}

std::unique_ptr<CliEquipProjectile> CliEquipProjectile::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliEquipProjectile>(reader);
}

bool CliEquipProjectile::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(projectile)) {
        return false;
    }
    return true;
}

constexpr size_t CliEquipProjectile::size() {
    size_t size = 0;
    size += ProjectileTypeAndIndex::size(); // projectile
    return size;
}

