#include "srv_party_levelexp.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvPartyLevelexp::PartyExpData& SrvPartyLevelexp::PartyExpData::set_exp(const uint32_t exp) {
    this->data.exp = exp;
    return *this;
}

uint32_t SrvPartyLevelexp::PartyExpData::get_exp() const {
    return data.exp;
}

SrvPartyLevelexp::PartyExpData& SrvPartyLevelexp::PartyExpData::set_level_up(const uint32_t level_up) {
    this->data.level_up = level_up;
    return *this;
}

uint32_t SrvPartyLevelexp::PartyExpData::get_level_up() const {
    return data.level_up;
}

SrvPartyLevelexp::PartyExpData& SrvPartyLevelexp::PartyExpData::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t SrvPartyLevelexp::PartyExpData::get_data() const {
    return data.data;
}

bool SrvPartyLevelexp::PartyExpData::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvPartyLevelexp::PartyExpData::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyLevelexp::PartyExpData::size() {
    return sizeof(data);
}


SrvPartyLevelexp::SrvPartyLevelexp() : CRosePacket(SrvPartyLevelexp::PACKET_ID) {}

SrvPartyLevelexp::SrvPartyLevelexp(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(level)) {
        return;
    }
    if (!reader.get_iserialize(exp_data)) {
        return;
    }
}

SrvPartyLevelexp& SrvPartyLevelexp::set_level(const uint8_t level) {
    this->level = level;
    return *this;
}

uint8_t SrvPartyLevelexp::get_level() const {
    return level;
}

SrvPartyLevelexp& SrvPartyLevelexp::set_exp_data(const SrvPartyLevelexp::PartyExpData exp_data) {
    this->exp_data = exp_data;
    return *this;
}

SrvPartyLevelexp::PartyExpData SrvPartyLevelexp::get_exp_data() const {
    return exp_data;
}

SrvPartyLevelexp SrvPartyLevelexp::create(const uint8_t& level, const SrvPartyLevelexp::PartyExpData& exp_data) {
    SrvPartyLevelexp packet;
    packet.set_level(level);
    packet.set_exp_data(exp_data);
    return packet;
}

SrvPartyLevelexp SrvPartyLevelexp::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyLevelexp(reader);
}

std::unique_ptr<SrvPartyLevelexp> SrvPartyLevelexp::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyLevelexp>(reader);
}

bool SrvPartyLevelexp::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(level)) {
        return false;
    }
    if (!writer.set_iserialize(exp_data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyLevelexp::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // level
    size += PartyExpData::size(); // exp_data
    return size;
}

