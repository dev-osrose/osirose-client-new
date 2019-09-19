#include "cli_shop_list_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliShopListReq::CliShopListReq() : CRosePacket(CliShopListReq::PACKET_ID) {}

CliShopListReq::CliShopListReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
}

CliShopListReq& CliShopListReq::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t CliShopListReq::get_id() const {
    return id;
}

CliShopListReq CliShopListReq::create(const uint16_t& id) {
    CliShopListReq packet;
    packet.set_id(id);
    return packet;
}

CliShopListReq CliShopListReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliShopListReq(reader);
}

std::unique_ptr<CliShopListReq> CliShopListReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliShopListReq>(reader);
}

bool CliShopListReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t CliShopListReq::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    return size;
}

