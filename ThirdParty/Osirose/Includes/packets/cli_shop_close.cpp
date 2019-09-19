#include "cli_shop_close.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliShopClose::CliShopClose() : CRosePacket(CliShopClose::PACKET_ID) {}

CliShopClose::CliShopClose(CRoseReader reader) : CRosePacket(reader) {
}

CliShopClose CliShopClose::create() {
    CliShopClose packet;
    return packet;
}

CliShopClose CliShopClose::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliShopClose(reader);
}

std::unique_ptr<CliShopClose> CliShopClose::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliShopClose>(reader);
}

bool CliShopClose::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliShopClose::size() {
    size_t size = 0;
    return size;
}

