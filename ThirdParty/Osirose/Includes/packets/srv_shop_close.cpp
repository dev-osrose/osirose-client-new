#include "srv_shop_close.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvShopClose::SrvShopClose() : CRosePacket(SrvShopClose::PACKET_ID) {}

SrvShopClose::SrvShopClose(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
}

SrvShopClose& SrvShopClose::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvShopClose::get_id() const {
    return id;
}

SrvShopClose SrvShopClose::create(const uint16_t& id) {
    SrvShopClose packet;
    packet.set_id(id);
    return packet;
}

SrvShopClose SrvShopClose::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvShopClose(reader);
}

std::unique_ptr<SrvShopClose> SrvShopClose::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvShopClose>(reader);
}

bool SrvShopClose::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShopClose::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    return size;
}

