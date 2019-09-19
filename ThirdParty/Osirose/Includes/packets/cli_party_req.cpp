#include "cli_party_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliPartyReq::CliPartyReq() : CRosePacket(CliPartyReq::PACKET_ID) {}

CliPartyReq::CliPartyReq(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<PartyReqType>(type_temp);
    
    if (!reader.get_uint16_t(target)) {
        return;
    }
}

CliPartyReq& CliPartyReq::set_type(const CliPartyReq::PartyReqType type) {
    this->type = type;
    return *this;
}

CliPartyReq::PartyReqType CliPartyReq::get_type() const {
    return type;
}

CliPartyReq& CliPartyReq::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t CliPartyReq::get_target() const {
    return target;
}

CliPartyReq CliPartyReq::create(const CliPartyReq::PartyReqType& type, const uint16_t& target) {
    CliPartyReq packet;
    packet.set_type(type);
    packet.set_target(target);
    return packet;
}

CliPartyReq CliPartyReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliPartyReq(reader);
}

std::unique_ptr<CliPartyReq> CliPartyReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliPartyReq>(reader);
}

bool CliPartyReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    return true;
}

constexpr size_t CliPartyReq::size() {
    size_t size = 0;
    size += sizeof(PartyReqType); // type
    size += sizeof(uint16_t); // target
    return size;
}

