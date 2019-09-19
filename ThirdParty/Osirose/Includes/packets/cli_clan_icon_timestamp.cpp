#include "cli_clan_icon_timestamp.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliClanIconTimestamp::CliClanIconTimestamp() : CRosePacket(CliClanIconTimestamp::PACKET_ID) {}

CliClanIconTimestamp::CliClanIconTimestamp(CRoseReader reader) : CRosePacket(reader) {
}

CliClanIconTimestamp CliClanIconTimestamp::create() {
    CliClanIconTimestamp packet;
    return packet;
}

CliClanIconTimestamp CliClanIconTimestamp::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliClanIconTimestamp(reader);
}

std::unique_ptr<CliClanIconTimestamp> CliClanIconTimestamp::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliClanIconTimestamp>(reader);
}

bool CliClanIconTimestamp::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliClanIconTimestamp::size() {
    size_t size = 0;
    return size;
}

