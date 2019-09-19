#include "srv_server_data.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvServerData::SrvServerData() : CRosePacket(SrvServerData::PACKET_ID) {}

SrvServerData::SrvServerData(CRoseReader reader) : CRosePacket(reader) {
}

SrvServerData SrvServerData::create() {
    SrvServerData packet;
    return packet;
}

SrvServerData SrvServerData::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvServerData(reader);
}

std::unique_ptr<SrvServerData> SrvServerData::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvServerData>(reader);
}

bool SrvServerData::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t SrvServerData::size() {
    size_t size = 0;
    return size;
}

