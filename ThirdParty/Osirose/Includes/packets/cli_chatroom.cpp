#include "cli_chatroom.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliChatroom::CliChatroom() : CRosePacket(CliChatroom::PACKET_ID) {}

CliChatroom::CliChatroom(CRoseReader reader) : CRosePacket(reader) {
}

CliChatroom CliChatroom::create() {
    CliChatroom packet;
    return packet;
}

CliChatroom CliChatroom::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliChatroom(reader);
}

std::unique_ptr<CliChatroom> CliChatroom::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliChatroom>(reader);
}

bool CliChatroom::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliChatroom::size() {
    size_t size = 0;
    return size;
}

