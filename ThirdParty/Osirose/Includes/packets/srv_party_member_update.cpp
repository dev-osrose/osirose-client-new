#include "srv_party_member_update.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_tag(const uint32_t tag) {
    this->tag = tag;
    return *this;
}

uint32_t SrvPartyMemberUpdate::PartyMember::get_tag() const {
    return tag;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvPartyMemberUpdate::PartyMember::get_id() const {
    return id;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_max_hp(const uint32_t max_hp) {
    this->max_hp = max_hp;
    return *this;
}

uint32_t SrvPartyMemberUpdate::PartyMember::get_max_hp() const {
    return max_hp;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_hp(const uint32_t hp) {
    this->hp = hp;
    return *this;
}

uint32_t SrvPartyMemberUpdate::PartyMember::get_hp() const {
    return hp;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_status(const uint32_t status) {
    this->status = status;
    return *this;
}

uint32_t SrvPartyMemberUpdate::PartyMember::get_status() const {
    return status;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_con(const uint16_t con) {
    this->con = con;
    return *this;
}

uint16_t SrvPartyMemberUpdate::PartyMember::get_con() const {
    return con;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_hp_recovery(const uint16_t hp_recovery) {
    this->hp_recovery = hp_recovery;
    return *this;
}

uint16_t SrvPartyMemberUpdate::PartyMember::get_hp_recovery() const {
    return hp_recovery;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_mp_recovery(const uint16_t mp_recovery) {
    this->mp_recovery = mp_recovery;
    return *this;
}

uint16_t SrvPartyMemberUpdate::PartyMember::get_mp_recovery() const {
    return mp_recovery;
}

SrvPartyMemberUpdate::PartyMember& SrvPartyMemberUpdate::PartyMember::set_stamina(const int16_t stamina) {
    this->stamina = stamina;
    return *this;
}

int16_t SrvPartyMemberUpdate::PartyMember::get_stamina() const {
    return stamina;
}

bool SrvPartyMemberUpdate::PartyMember::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(tag)) {
        return false;
    }
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint32_t(max_hp)) {
        return false;
    }
    if (!writer.set_uint32_t(hp)) {
        return false;
    }
    if (!writer.set_uint32_t(status)) {
        return false;
    }
    if (!writer.set_uint16_t(con)) {
        return false;
    }
    if (!writer.set_uint16_t(hp_recovery)) {
        return false;
    }
    if (!writer.set_uint16_t(mp_recovery)) {
        return false;
    }
    if (!writer.set_int16_t(stamina)) {
        return false;
    }
    return true;
}

bool SrvPartyMemberUpdate::PartyMember::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(tag)) {
        return false;
    }
    if (!reader.get_uint16_t(id)) {
        return false;
    }
    if (!reader.get_uint32_t(max_hp)) {
        return false;
    }
    if (!reader.get_uint32_t(hp)) {
        return false;
    }
    if (!reader.get_uint32_t(status)) {
        return false;
    }
    if (!reader.get_uint16_t(con)) {
        return false;
    }
    if (!reader.get_uint16_t(hp_recovery)) {
        return false;
    }
    if (!reader.get_uint16_t(mp_recovery)) {
        return false;
    }
    if (!reader.get_int16_t(stamina)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyMemberUpdate::PartyMember::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // tag
    size += sizeof(uint16_t); // id
    size += sizeof(uint32_t); // max_hp
    size += sizeof(uint32_t); // hp
    size += sizeof(uint32_t); // status
    size += sizeof(uint16_t); // con
    size += sizeof(uint16_t); // hp_recovery
    size += sizeof(uint16_t); // mp_recovery
    size += sizeof(int16_t); // stamina
    return size;
}


SrvPartyMemberUpdate::SrvPartyMemberUpdate() : CRosePacket(SrvPartyMemberUpdate::PACKET_ID) {}

SrvPartyMemberUpdate::SrvPartyMemberUpdate(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_iserialize(member)) {
        return;
    }
}

SrvPartyMemberUpdate& SrvPartyMemberUpdate::set_member(const SrvPartyMemberUpdate::PartyMember member) {
    this->member = member;
    return *this;
}

SrvPartyMemberUpdate::PartyMember SrvPartyMemberUpdate::get_member() const {
    return member;
}

SrvPartyMemberUpdate SrvPartyMemberUpdate::create(const SrvPartyMemberUpdate::PartyMember& member) {
    SrvPartyMemberUpdate packet;
    packet.set_member(member);
    return packet;
}

SrvPartyMemberUpdate SrvPartyMemberUpdate::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyMemberUpdate(reader);
}

std::unique_ptr<SrvPartyMemberUpdate> SrvPartyMemberUpdate::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyMemberUpdate>(reader);
}

bool SrvPartyMemberUpdate::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(member)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyMemberUpdate::size() {
    size_t size = 0;
    size += PartyMember::size(); // member
    return size;
}

