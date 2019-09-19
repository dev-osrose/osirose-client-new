#include "cli_hotbar_set_icon_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliHotbarSetIconReq::CliHotbarSetIconReq() : CRosePacket(CliHotbarSetIconReq::PACKET_ID) {}

CliHotbarSetIconReq::CliHotbarSetIconReq(CRoseReader reader) : CRosePacket(reader) {
}

CliHotbarSetIconReq CliHotbarSetIconReq::create() {
    CliHotbarSetIconReq packet;
    return packet;
}

CliHotbarSetIconReq CliHotbarSetIconReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliHotbarSetIconReq(reader);
}

std::unique_ptr<CliHotbarSetIconReq> CliHotbarSetIconReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliHotbarSetIconReq>(reader);
}

bool CliHotbarSetIconReq::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliHotbarSetIconReq::size() {
    size_t size = 0;
    return size;
}

