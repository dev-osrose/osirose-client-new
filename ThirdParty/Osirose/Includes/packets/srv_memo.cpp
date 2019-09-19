#include "srv_memo.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvMemo::SrvMemo() : CRosePacket(SrvMemo::PACKET_ID) {}

SrvMemo::SrvMemo(CRoseReader reader) : CRosePacket(reader) {
}

SrvMemo SrvMemo::create() {
    SrvMemo packet;
    return packet;
}

SrvMemo SrvMemo::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvMemo(reader);
}

std::unique_ptr<SrvMemo> SrvMemo::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvMemo>(reader);
}

bool SrvMemo::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t SrvMemo::size() {
    size_t size = 0;
    return size;
}

