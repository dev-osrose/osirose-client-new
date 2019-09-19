#include "srv_logout_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvLogoutReply::SrvLogoutReply() : CRosePacket(SrvLogoutReply::PACKET_ID) {}

SrvLogoutReply::SrvLogoutReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(waitTime)) {
        return;
    }
}

SrvLogoutReply& SrvLogoutReply::set_waitTime(const uint16_t waitTime) {
    this->waitTime = waitTime;
    return *this;
}

uint16_t SrvLogoutReply::get_waitTime() const {
    return waitTime;
}

SrvLogoutReply SrvLogoutReply::create(const uint16_t& waitTime) {
    SrvLogoutReply packet;
    packet.set_waitTime(waitTime);
    return packet;
}

SrvLogoutReply SrvLogoutReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvLogoutReply(reader);
}

std::unique_ptr<SrvLogoutReply> SrvLogoutReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvLogoutReply>(reader);
}

bool SrvLogoutReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(waitTime)) {
        return false;
    }
    return true;
}

constexpr size_t SrvLogoutReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // waitTime
    return size;
}

