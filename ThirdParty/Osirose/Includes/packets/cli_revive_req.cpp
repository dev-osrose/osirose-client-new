#include "cli_revive_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliReviveReq::CliReviveReq() : CRosePacket(CliReviveReq::PACKET_ID) {}

CliReviveReq::CliReviveReq(CRoseReader reader) : CRosePacket(reader) {
    uint8_t reviveType_temp;
    if (!reader.get_uint8_t(reviveType_temp)) {
        return;
    }
    reviveType = static_cast<ReviveRequest>(reviveType_temp);
    
}

CliReviveReq& CliReviveReq::set_reviveType(const CliReviveReq::ReviveRequest reviveType) {
    this->reviveType = reviveType;
    return *this;
}

CliReviveReq::ReviveRequest CliReviveReq::get_reviveType() const {
    return reviveType;
}

CliReviveReq CliReviveReq::create(const CliReviveReq::ReviveRequest& reviveType) {
    CliReviveReq packet;
    packet.set_reviveType(reviveType);
    return packet;
}

CliReviveReq CliReviveReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliReviveReq(reader);
}

std::unique_ptr<CliReviveReq> CliReviveReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliReviveReq>(reader);
}

bool CliReviveReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(reviveType)) {
        return false;
    }
    return true;
}

constexpr size_t CliReviveReq::size() {
    size_t size = 0;
    size += sizeof(ReviveRequest); // reviveType
    return size;
}

