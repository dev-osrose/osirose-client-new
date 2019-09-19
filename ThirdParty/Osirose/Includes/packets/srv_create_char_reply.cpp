#include "srv_create_char_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvCreateCharReply::SrvCreateCharReply() : CRosePacket(SrvCreateCharReply::PACKET_ID) {}

SrvCreateCharReply::SrvCreateCharReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<Result>(result_temp);
    
    if (!reader.get_uint8_t(platininum)) {
        return;
    }
}

SrvCreateCharReply& SrvCreateCharReply::set_result(const SrvCreateCharReply::Result result) {
    this->result = result;
    return *this;
}

SrvCreateCharReply::Result SrvCreateCharReply::get_result() const {
    return result;
}

SrvCreateCharReply& SrvCreateCharReply::set_platininum(const uint8_t platininum) {
    this->platininum = platininum;
    return *this;
}

uint8_t SrvCreateCharReply::get_platininum() const {
    return platininum;
}

SrvCreateCharReply SrvCreateCharReply::create(const SrvCreateCharReply::Result& result) {
    SrvCreateCharReply packet;
    packet.set_result(result);
    return packet;
}

SrvCreateCharReply SrvCreateCharReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvCreateCharReply(reader);
}

std::unique_ptr<SrvCreateCharReply> SrvCreateCharReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvCreateCharReply>(reader);
}

bool SrvCreateCharReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint8_t(platininum)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCreateCharReply::size() {
    size_t size = 0;
    size += sizeof(Result); // result
    size += sizeof(uint8_t); // platininum
    return size;
}

