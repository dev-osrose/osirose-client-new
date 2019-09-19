#include "srv_set_money.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetMoney::SrvSetMoney() : CRosePacket(SrvSetMoney::PACKET_ID) {}

SrvSetMoney::SrvSetMoney(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int64_t(zuly)) {
        return;
    }
}

SrvSetMoney& SrvSetMoney::set_zuly(const int64_t zuly) {
    this->zuly = zuly;
    return *this;
}

int64_t SrvSetMoney::get_zuly() const {
    return zuly;
}

SrvSetMoney SrvSetMoney::create(const int64_t& zuly) {
    SrvSetMoney packet;
    packet.set_zuly(zuly);
    return packet;
}

SrvSetMoney SrvSetMoney::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetMoney(reader);
}

std::unique_ptr<SrvSetMoney> SrvSetMoney::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetMoney>(reader);
}

bool SrvSetMoney::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int64_t(zuly)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetMoney::size() {
    size_t size = 0;
    size += sizeof(int64_t); // zuly
    return size;
}

