#include "cli_party_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliPartyReply::CliPartyReply() : CRosePacket(CliPartyReply::PACKET_ID) {}

CliPartyReply::CliPartyReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<PartyReplyType>(type_temp);
    
    if (!reader.get_uint16_t(target)) {
        return;
    }
}

CliPartyReply& CliPartyReply::set_type(const CliPartyReply::PartyReplyType type) {
    this->type = type;
    return *this;
}

CliPartyReply::PartyReplyType CliPartyReply::get_type() const {
    return type;
}

CliPartyReply& CliPartyReply::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t CliPartyReply::get_target() const {
    return target;
}

CliPartyReply CliPartyReply::create(const CliPartyReply::PartyReplyType& type, const uint16_t& target) {
    CliPartyReply packet;
    packet.set_type(type);
    packet.set_target(target);
    return packet;
}

CliPartyReply CliPartyReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliPartyReply(reader);
}

std::unique_ptr<CliPartyReply> CliPartyReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliPartyReply>(reader);
}

bool CliPartyReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    return true;
}

constexpr size_t CliPartyReply::size() {
    size_t size = 0;
    size += sizeof(PartyReplyType); // type
    size += sizeof(uint16_t); // target
    return size;
}

