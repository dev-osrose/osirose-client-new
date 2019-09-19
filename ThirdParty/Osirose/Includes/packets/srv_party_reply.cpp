#include "srv_party_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvPartyReply::SrvPartyReply() : CRosePacket(SrvPartyReply::PACKET_ID) {}

SrvPartyReply::SrvPartyReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<PartyReplyType>(type_temp);
    
    if (!reader.get_uint16_t(source)) {
        return;
    }
}

SrvPartyReply& SrvPartyReply::set_type(const SrvPartyReply::PartyReplyType type) {
    this->type = type;
    return *this;
}

SrvPartyReply::PartyReplyType SrvPartyReply::get_type() const {
    return type;
}

SrvPartyReply& SrvPartyReply::set_source(const uint16_t source) {
    this->source = source;
    return *this;
}

uint16_t SrvPartyReply::get_source() const {
    return source;
}

SrvPartyReply SrvPartyReply::create(const SrvPartyReply::PartyReplyType& type, const uint16_t& source) {
    SrvPartyReply packet;
    packet.set_type(type);
    packet.set_source(source);
    return packet;
}

SrvPartyReply SrvPartyReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyReply(reader);
}

std::unique_ptr<SrvPartyReply> SrvPartyReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyReply>(reader);
}

bool SrvPartyReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint16_t(source)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyReply::size() {
    size_t size = 0;
    size += sizeof(PartyReplyType); // type
    size += sizeof(uint16_t); // source
    return size;
}

