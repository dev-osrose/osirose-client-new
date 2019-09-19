#include "srv_party_member.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_tag(const uint32_t tag) {
    this->tag = tag;
    return *this;
}

uint32_t SrvPartyMember::PartyMember::get_tag() const {
    return tag;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvPartyMember::PartyMember::get_id() const {
    return id;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_max_hp(const uint32_t max_hp) {
    this->max_hp = max_hp;
    return *this;
}

uint32_t SrvPartyMember::PartyMember::get_max_hp() const {
    return max_hp;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_hp(const uint32_t hp) {
    this->hp = hp;
    return *this;
}

uint32_t SrvPartyMember::PartyMember::get_hp() const {
    return hp;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_status(const uint32_t status) {
    this->status = status;
    return *this;
}

uint32_t SrvPartyMember::PartyMember::get_status() const {
    return status;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_con(const uint16_t con) {
    this->con = con;
    return *this;
}

uint16_t SrvPartyMember::PartyMember::get_con() const {
    return con;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_hp_recovery(const uint16_t hp_recovery) {
    this->hp_recovery = hp_recovery;
    return *this;
}

uint16_t SrvPartyMember::PartyMember::get_hp_recovery() const {
    return hp_recovery;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_mp_recovery(const uint16_t mp_recovery) {
    this->mp_recovery = mp_recovery;
    return *this;
}

uint16_t SrvPartyMember::PartyMember::get_mp_recovery() const {
    return mp_recovery;
}

SrvPartyMember::PartyMember& SrvPartyMember::PartyMember::set_stamina(const int16_t stamina) {
    this->stamina = stamina;
    return *this;
}

int16_t SrvPartyMember::PartyMember::get_stamina() const {
    return stamina;
}

bool SrvPartyMember::PartyMember::write(CRoseBasePolicy& writer) const {
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

bool SrvPartyMember::PartyMember::read(CRoseReader& reader) {
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

constexpr size_t SrvPartyMember::PartyMember::size() {
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


SrvPartyMember::SrvPartyMember() : CRosePacket(SrvPartyMember::PACKET_ID) {}

SrvPartyMember::SrvPartyMember(CRoseReader reader) : CRosePacket(reader) {
    uint8_t rule_temp;
    if (!reader.get_uint8_t(rule_temp)) {
        return;
    }
    rule = static_cast<PartyRule>(rule_temp);
    
    int8_t action_temp;
    if (!reader.get_int8_t(action_temp)) {
        return;
    }
    action = static_cast<PartyMemberAction>(action_temp);
    
    if (!reader.get_iserialize(member)) {
        return;
    }
}

SrvPartyMember& SrvPartyMember::set_rule(const SrvPartyMember::PartyRule rule) {
    this->rule = rule;
    return *this;
}

SrvPartyMember::PartyRule SrvPartyMember::get_rule() const {
    return rule;
}

SrvPartyMember& SrvPartyMember::set_action(const SrvPartyMember::PartyMemberAction action) {
    this->action = action;
    return *this;
}

SrvPartyMember::PartyMemberAction SrvPartyMember::get_action() const {
    return action;
}

SrvPartyMember& SrvPartyMember::set_member(const SrvPartyMember::PartyMember member) {
    this->member = member;
    return *this;
}

SrvPartyMember::PartyMember SrvPartyMember::get_member() const {
    return member;
}

SrvPartyMember SrvPartyMember::create(const SrvPartyMember::PartyRule& rule, const SrvPartyMember::PartyMemberAction& action, const SrvPartyMember::PartyMember& member) {
    SrvPartyMember packet;
    packet.set_rule(rule);
    packet.set_action(action);
    packet.set_member(member);
    return packet;
}

SrvPartyMember SrvPartyMember::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyMember(reader);
}

std::unique_ptr<SrvPartyMember> SrvPartyMember::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyMember>(reader);
}

bool SrvPartyMember::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(rule)) {
        return false;
    }
    if (!writer.set_int8_t(action)) {
        return false;
    }
    if (!writer.set_iserialize(member)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyMember::size() {
    size_t size = 0;
    size += sizeof(PartyRule); // rule
    size += sizeof(PartyMemberAction); // action
    size += PartyMember::size(); // member
    return size;
}

