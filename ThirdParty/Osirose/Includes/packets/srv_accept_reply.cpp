#include "srv_accept_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvAcceptReply::SrvAcceptReply() : CRosePacket(SrvAcceptReply::PACKET_ID) {}

SrvAcceptReply::SrvAcceptReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<Result>(result_temp);
    
    if (!reader.get_uint32_t(randValue)) {
        return;
    }
}

SrvAcceptReply& SrvAcceptReply::set_result(const SrvAcceptReply::Result result) {
    this->result = result;
    return *this;
}

SrvAcceptReply::Result SrvAcceptReply::get_result() const {
    return result;
}

SrvAcceptReply& SrvAcceptReply::set_randValue(const uint32_t randValue) {
    this->randValue = randValue;
    return *this;
}

uint32_t SrvAcceptReply::get_randValue() const {
    return randValue;
}

SrvAcceptReply SrvAcceptReply::create(const SrvAcceptReply::Result& result, const uint32_t& randValue) {
    SrvAcceptReply packet;
    packet.set_result(result);
    packet.set_randValue(randValue);
    return packet;
}

SrvAcceptReply SrvAcceptReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvAcceptReply(reader);
}

std::unique_ptr<SrvAcceptReply> SrvAcceptReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvAcceptReply>(reader);
}

bool SrvAcceptReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint32_t(randValue)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAcceptReply::size() {
    size_t size = 0;
    size += sizeof(Result); // result
    size += sizeof(uint32_t); // randValue
    return size;
}

