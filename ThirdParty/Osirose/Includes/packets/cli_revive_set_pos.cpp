#include "cli_revive_set_pos.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliReviveSetPos::CliReviveSetPos() : CRosePacket(CliReviveSetPos::PACKET_ID) {}

CliReviveSetPos::CliReviveSetPos(CRoseReader reader) : CRosePacket(reader) {
}

CliReviveSetPos CliReviveSetPos::create() {
    CliReviveSetPos packet;
    return packet;
}

CliReviveSetPos CliReviveSetPos::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliReviveSetPos(reader);
}

std::unique_ptr<CliReviveSetPos> CliReviveSetPos::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliReviveSetPos>(reader);
}

bool CliReviveSetPos::pack(CRoseBasePolicy&) const {
    return true;
}

constexpr size_t CliReviveSetPos::size() {
    size_t size = 0;
    return size;
}

