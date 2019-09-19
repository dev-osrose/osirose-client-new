#include "srv_party_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvPartyReq::SrvPartyReq() : CRosePacket(SrvPartyReq::PACKET_ID) {}

SrvPartyReq::SrvPartyReq(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<PartyReqType>(type_temp);
    
    if (!reader.get_uint16_t(source)) {
        return;
    }
}

SrvPartyReq& SrvPartyReq::set_type(const SrvPartyReq::PartyReqType type) {
    this->type = type;
    return *this;
}

SrvPartyReq::PartyReqType SrvPartyReq::get_type() const {
    return type;
}

SrvPartyReq& SrvPartyReq::set_source(const uint16_t source) {
    this->source = source;
    return *this;
}

uint16_t SrvPartyReq::get_source() const {
    return source;
}

SrvPartyReq SrvPartyReq::create(const SrvPartyReq::PartyReqType& type, const uint16_t& source) {
    SrvPartyReq packet;
    packet.set_type(type);
    packet.set_source(source);
    return packet;
}

SrvPartyReq SrvPartyReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyReq(reader);
}

std::unique_ptr<SrvPartyReq> SrvPartyReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyReq>(reader);
}

bool SrvPartyReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint16_t(source)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyReq::size() {
    size_t size = 0;
    size += sizeof(PartyReqType); // type
    size += sizeof(uint16_t); // source
    return size;
}

