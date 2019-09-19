#include "srv_join_server_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvJoinServerReply::SrvJoinServerReply() : CRosePacket(SrvJoinServerReply::PACKET_ID) {}

SrvJoinServerReply::SrvJoinServerReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<Result>(result_temp);
    
    if (!reader.get_uint32_t(id)) {
        return;
    }
    if (!reader.get_uint32_t(payFlag)) {
        return;
    }
}

SrvJoinServerReply& SrvJoinServerReply::set_result(const SrvJoinServerReply::Result result) {
    this->result = result;
    return *this;
}

SrvJoinServerReply::Result SrvJoinServerReply::get_result() const {
    return result;
}

SrvJoinServerReply& SrvJoinServerReply::set_id(const uint32_t id) {
    this->id = id;
    return *this;
}

uint32_t SrvJoinServerReply::get_id() const {
    return id;
}

SrvJoinServerReply& SrvJoinServerReply::set_payFlag(const uint32_t payFlag) {
    this->payFlag = payFlag;
    return *this;
}

uint32_t SrvJoinServerReply::get_payFlag() const {
    return payFlag;
}

SrvJoinServerReply SrvJoinServerReply::create(const SrvJoinServerReply::Result& result, const uint32_t& id) {
    SrvJoinServerReply packet;
    packet.set_result(result);
    packet.set_id(id);
    return packet;
}

SrvJoinServerReply SrvJoinServerReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvJoinServerReply(reader);
}

std::unique_ptr<SrvJoinServerReply> SrvJoinServerReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvJoinServerReply>(reader);
}

bool SrvJoinServerReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint32_t(id)) {
        return false;
    }
    if (!writer.set_uint32_t(payFlag)) {
        return false;
    }
    return true;
}

constexpr size_t SrvJoinServerReply::size() {
    size_t size = 0;
    size += sizeof(Result); // result
    size += sizeof(uint32_t); // id
    size += sizeof(uint32_t); // payFlag
    return size;
}

