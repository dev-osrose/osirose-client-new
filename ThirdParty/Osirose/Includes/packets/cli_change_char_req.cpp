#include "cli_change_char_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliChangeCharReq::CliChangeCharReq() : CRosePacket(CliChangeCharReq::PACKET_ID) {}

CliChangeCharReq::CliChangeCharReq(CRoseReader reader) : CRosePacket(reader) {
}

CliChangeCharReq CliChangeCharReq::create() {
    CliChangeCharReq packet;
    return packet;
}

CliChangeCharReq CliChangeCharReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliChangeCharReq(reader);
}

std::unique_ptr<CliChangeCharReq> CliChangeCharReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliChangeCharReq>(reader);
}

bool CliChangeCharReq::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliChangeCharReq::size() {
    size_t size = 0;
    return size;
}

