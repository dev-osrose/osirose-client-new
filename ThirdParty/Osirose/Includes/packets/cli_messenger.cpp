#include "cli_messenger.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliMessenger::CliMessenger() : CRosePacket(CliMessenger::PACKET_ID) {}

CliMessenger::CliMessenger(CRoseReader reader) : CRosePacket(reader) {
}

CliMessenger CliMessenger::create() {
    CliMessenger packet;
    return packet;
}

CliMessenger CliMessenger::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliMessenger(reader);
}

std::unique_ptr<CliMessenger> CliMessenger::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliMessenger>(reader);
}

bool CliMessenger::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliMessenger::size() {
    size_t size = 0;
    return size;
}

