#include "cli_attack.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliAttack::CliAttack() : CRosePacket(CliAttack::PACKET_ID) {}

CliAttack::CliAttack(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(targetId)) {
        return;
    }
}

CliAttack& CliAttack::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t CliAttack::get_targetId() const {
    return targetId;
}

CliAttack CliAttack::create(const uint16_t& targetId) {
    CliAttack packet;
    packet.set_targetId(targetId);
    return packet;
}

CliAttack CliAttack::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliAttack(reader);
}

std::unique_ptr<CliAttack> CliAttack::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliAttack>(reader);
}

bool CliAttack::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(targetId)) {
        return false;
    }
    return true;
}

constexpr size_t CliAttack::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // targetId
    return size;
}

