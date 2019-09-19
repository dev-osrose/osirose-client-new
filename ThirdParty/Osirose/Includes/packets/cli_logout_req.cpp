#include "cli_logout_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliLogoutReq::CliLogoutReq() : CRosePacket(CliLogoutReq::PACKET_ID) {}

CliLogoutReq::CliLogoutReq(CRoseReader reader) : CRosePacket(reader) {
}

CliLogoutReq CliLogoutReq::create() {
    CliLogoutReq packet;
    return packet;
}

CliLogoutReq CliLogoutReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliLogoutReq(reader);
}

std::unique_ptr<CliLogoutReq> CliLogoutReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliLogoutReq>(reader);
}

bool CliLogoutReq::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliLogoutReq::size() {
    size_t size = 0;
    return size;
}

