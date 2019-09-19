#include "srv_chatroom.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvChatroom::SrvChatroom() : CRosePacket(SrvChatroom::PACKET_ID) {}

SrvChatroom::SrvChatroom(CRoseReader reader) : CRosePacket(reader) {
}

SrvChatroom SrvChatroom::create() {
    SrvChatroom packet;
    return packet;
}

SrvChatroom SrvChatroom::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvChatroom(reader);
}

std::unique_ptr<SrvChatroom> SrvChatroom::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvChatroom>(reader);
}

bool SrvChatroom::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t SrvChatroom::size() {
    size_t size = 0;
    return size;
}

