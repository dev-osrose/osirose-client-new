#include "srv_party_rule.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvPartyRule::SrvPartyRule() : CRosePacket(SrvPartyRule::PACKET_ID) {}

SrvPartyRule::SrvPartyRule(CRoseReader reader) : CRosePacket(reader) {
    uint8_t rule_temp;
    if (!reader.get_uint8_t(rule_temp)) {
        return;
    }
    rule = static_cast<PartyRule>(rule_temp);
    
}

SrvPartyRule& SrvPartyRule::set_rule(const SrvPartyRule::PartyRule rule) {
    this->rule = rule;
    return *this;
}

SrvPartyRule::PartyRule SrvPartyRule::get_rule() const {
    return rule;
}

SrvPartyRule SrvPartyRule::create(const SrvPartyRule::PartyRule& rule) {
    SrvPartyRule packet;
    packet.set_rule(rule);
    return packet;
}

SrvPartyRule SrvPartyRule::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyRule(reader);
}

std::unique_ptr<SrvPartyRule> SrvPartyRule::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyRule>(reader);
}

bool SrvPartyRule::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(rule)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyRule::size() {
    size_t size = 0;
    size += sizeof(PartyRule); // rule
    return size;
}

