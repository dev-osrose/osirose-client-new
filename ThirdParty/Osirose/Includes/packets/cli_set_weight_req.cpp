#include "cli_set_weight_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSetWeightReq::CliSetWeightReq() : CRosePacket(CliSetWeightReq::PACKET_ID) {}

CliSetWeightReq::CliSetWeightReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(weight)) {
        return;
    }
}

CliSetWeightReq& CliSetWeightReq::set_weight(const uint8_t weight) {
    this->weight = weight;
    return *this;
}

uint8_t CliSetWeightReq::get_weight() const {
    return weight;
}

CliSetWeightReq CliSetWeightReq::create(const uint8_t& weight) {
    CliSetWeightReq packet;
    packet.set_weight(weight);
    return packet;
}

CliSetWeightReq CliSetWeightReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSetWeightReq(reader);
}

std::unique_ptr<CliSetWeightReq> CliSetWeightReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSetWeightReq>(reader);
}

bool CliSetWeightReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(weight)) {
        return false;
    }
    return true;
}

constexpr size_t CliSetWeightReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // weight
    return size;
}

