#include "srv_shop_open.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvShopOpen::SrvShopOpen() : CRosePacket(SrvShopOpen::PACKET_ID) {}

SrvShopOpen::SrvShopOpen(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

SrvShopOpen& SrvShopOpen::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvShopOpen::get_id() const {
    return id;
}

SrvShopOpen& SrvShopOpen::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvShopOpen::get_name() const {
    return name;
}

SrvShopOpen SrvShopOpen::create(const uint16_t& id, const std::string& name) {
    SrvShopOpen packet;
    packet.set_id(id);
    packet.set_name(name);
    return packet;
}

SrvShopOpen SrvShopOpen::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvShopOpen(reader);
}

std::unique_ptr<SrvShopOpen> SrvShopOpen::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvShopOpen>(reader);
}

bool SrvShopOpen::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShopOpen::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    return size;
}

