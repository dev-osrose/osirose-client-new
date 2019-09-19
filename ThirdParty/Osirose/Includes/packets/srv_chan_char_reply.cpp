#include "srv_chan_char_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvChanCharReply::SrvChanCharReply() : CRosePacket(SrvChanCharReply::PACKET_ID) {}

SrvChanCharReply::SrvChanCharReply(CRoseReader reader) : CRosePacket(reader) {
}

SrvChanCharReply SrvChanCharReply::create() {
    SrvChanCharReply packet;
    return packet;
}

SrvChanCharReply SrvChanCharReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvChanCharReply(reader);
}

std::unique_ptr<SrvChanCharReply> SrvChanCharReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvChanCharReply>(reader);
}

bool SrvChanCharReply::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t SrvChanCharReply::size() {
    size_t size = 0;
    return size;
}

