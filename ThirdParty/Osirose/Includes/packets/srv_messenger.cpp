#include "srv_messenger.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvMessenger::SrvMessenger() : CRosePacket(SrvMessenger::PACKET_ID) {}

SrvMessenger::SrvMessenger(CRoseReader reader) : CRosePacket(reader) {
}

SrvMessenger SrvMessenger::create() {
    SrvMessenger packet;
    return packet;
}

SrvMessenger SrvMessenger::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvMessenger(reader);
}

std::unique_ptr<SrvMessenger> SrvMessenger::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvMessenger>(reader);
}

bool SrvMessenger::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t SrvMessenger::size() {
    size_t size = 0;
    return size;
}

