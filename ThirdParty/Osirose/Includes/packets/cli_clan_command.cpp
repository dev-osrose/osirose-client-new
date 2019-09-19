#include "cli_clan_command.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliClanCommand::CliClanCommand() : CRosePacket(CliClanCommand::PACKET_ID) {}

CliClanCommand::CliClanCommand(CRoseReader reader) : CRosePacket(reader) {
}

CliClanCommand CliClanCommand::create() {
    CliClanCommand packet;
    return packet;
}

CliClanCommand CliClanCommand::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliClanCommand(reader);
}

std::unique_ptr<CliClanCommand> CliClanCommand::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliClanCommand>(reader);
}

bool CliClanCommand::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliClanCommand::size() {
    size_t size = 0;
    return size;
}

