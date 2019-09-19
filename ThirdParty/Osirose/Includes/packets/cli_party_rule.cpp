#include "cli_party_rule.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliPartyRule::CliPartyRule() : CRosePacket(CliPartyRule::PACKET_ID) {}

CliPartyRule::CliPartyRule(CRoseReader reader) : CRosePacket(reader) {
    uint8_t rule_temp;
    if (!reader.get_uint8_t(rule_temp)) {
        return;
    }
    rule = static_cast<PartyRule>(rule_temp);
    
}

CliPartyRule& CliPartyRule::set_rule(const CliPartyRule::PartyRule rule) {
    this->rule = rule;
    return *this;
}

CliPartyRule::PartyRule CliPartyRule::get_rule() const {
    return rule;
}

CliPartyRule CliPartyRule::create(const CliPartyRule::PartyRule& rule) {
    CliPartyRule packet;
    packet.set_rule(rule);
    return packet;
}

CliPartyRule CliPartyRule::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliPartyRule(reader);
}

std::unique_ptr<CliPartyRule> CliPartyRule::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliPartyRule>(reader);
}

bool CliPartyRule::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(rule)) {
        return false;
    }
    return true;
}

constexpr size_t CliPartyRule::size() {
    size_t size = 0;
    size += sizeof(PartyRule); // rule
    return size;
}

