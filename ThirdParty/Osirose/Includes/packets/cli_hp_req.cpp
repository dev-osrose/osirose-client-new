#include "cli_hp_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliHpReq::CliHpReq() : CRosePacket(CliHpReq::PACKET_ID) {}

CliHpReq::CliHpReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(targetId)) {
        return;
    }
}

CliHpReq& CliHpReq::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t CliHpReq::get_targetId() const {
    return targetId;
}

CliHpReq CliHpReq::create(const uint16_t& targetId) {
    CliHpReq packet;
    packet.set_targetId(targetId);
    return packet;
}

CliHpReq CliHpReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliHpReq(reader);
}

std::unique_ptr<CliHpReq> CliHpReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliHpReq>(reader);
}

bool CliHpReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(targetId)) {
        return false;
    }
    return true;
}

constexpr size_t CliHpReq::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // targetId
    return size;
}

