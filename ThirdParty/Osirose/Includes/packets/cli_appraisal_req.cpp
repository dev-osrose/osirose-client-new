#include "cli_appraisal_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliAppraisalReq::CliAppraisalReq() : CRosePacket(CliAppraisalReq::PACKET_ID) {}

CliAppraisalReq::CliAppraisalReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(index)) {
        return;
    }
}

CliAppraisalReq& CliAppraisalReq::set_index(const uint16_t index) {
    this->index = index;
    return *this;
}

uint16_t CliAppraisalReq::get_index() const {
    return index;
}

CliAppraisalReq CliAppraisalReq::create(const uint16_t& index) {
    CliAppraisalReq packet;
    packet.set_index(index);
    return packet;
}

CliAppraisalReq CliAppraisalReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliAppraisalReq(reader);
}

std::unique_ptr<CliAppraisalReq> CliAppraisalReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliAppraisalReq>(reader);
}

bool CliAppraisalReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(index)) {
        return false;
    }
    return true;
}

constexpr size_t CliAppraisalReq::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // index
    return size;
}

