#include "srv_clan_command.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvClanCommand::SrvClanCommand() : CRosePacket(SrvClanCommand::PACKET_ID) {}

SrvClanCommand::SrvClanCommand(CRoseReader reader) : CRosePacket(reader) {
}

SrvClanCommand SrvClanCommand::create() {
    SrvClanCommand packet;
    return packet;
}

SrvClanCommand SrvClanCommand::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvClanCommand(reader);
}

std::unique_ptr<SrvClanCommand> SrvClanCommand::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvClanCommand>(reader);
}

bool SrvClanCommand::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t SrvClanCommand::size() {
    size_t size = 0;
    return size;
}

