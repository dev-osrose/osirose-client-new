#include "srv_appraisal_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvAppraisalReply::AppraisalReply& SrvAppraisalReply::AppraisalReply::set_index(const uint16_t index) {
    this->data.index = index;
    return *this;
}

uint16_t SrvAppraisalReply::AppraisalReply::get_index() const {
    return data.index;
}

SrvAppraisalReply::AppraisalReply& SrvAppraisalReply::AppraisalReply::set_result(const uint16_t result) {
    this->data.result = result;
    return *this;
}

uint16_t SrvAppraisalReply::AppraisalReply::get_result() const {
    return data.result;
}

SrvAppraisalReply::AppraisalReply& SrvAppraisalReply::AppraisalReply::set_data(const uint16_t data) {
    this->data.data = data;
    return *this;
}

uint16_t SrvAppraisalReply::AppraisalReply::get_data() const {
    return data.data;
}

bool SrvAppraisalReply::AppraisalReply::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvAppraisalReply::AppraisalReply::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAppraisalReply::AppraisalReply::size() {
    return sizeof(data);
}


SrvAppraisalReply::SrvAppraisalReply() : CRosePacket(SrvAppraisalReply::PACKET_ID) {}

SrvAppraisalReply::SrvAppraisalReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_iserialize(result)) {
        return;
    }
}

SrvAppraisalReply& SrvAppraisalReply::set_result(const SrvAppraisalReply::AppraisalReply result) {
    this->result = result;
    return *this;
}

SrvAppraisalReply::AppraisalReply SrvAppraisalReply::get_result() const {
    return result;
}

SrvAppraisalReply SrvAppraisalReply::create(const SrvAppraisalReply::AppraisalReply& result) {
    SrvAppraisalReply packet;
    packet.set_result(result);
    return packet;
}

SrvAppraisalReply SrvAppraisalReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvAppraisalReply(reader);
}

std::unique_ptr<SrvAppraisalReply> SrvAppraisalReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvAppraisalReply>(reader);
}

bool SrvAppraisalReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(result)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAppraisalReply::size() {
    size_t size = 0;
    size += AppraisalReply::size(); // result
    return size;
}

