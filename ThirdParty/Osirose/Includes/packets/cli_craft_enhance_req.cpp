#include "cli_craft_enhance_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliCraftEnhanceReq::CliCraftEnhanceReq() : CRosePacket(CliCraftEnhanceReq::PACKET_ID) {}

CliCraftEnhanceReq::CliCraftEnhanceReq(CRoseReader reader) : CRosePacket(reader) {
}

CliCraftEnhanceReq CliCraftEnhanceReq::create() {
    CliCraftEnhanceReq packet;
    return packet;
}

CliCraftEnhanceReq CliCraftEnhanceReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliCraftEnhanceReq(reader);
}

std::unique_ptr<CliCraftEnhanceReq> CliCraftEnhanceReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliCraftEnhanceReq>(reader);
}

bool CliCraftEnhanceReq::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliCraftEnhanceReq::size() {
    size_t size = 0;
    return size;
}

