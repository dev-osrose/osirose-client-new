#include "srv_set_server_var_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetServerVarReply::SrvSetServerVarReply() : CRosePacket(SrvSetServerVarReply::PACKET_ID) {}

SrvSetServerVarReply::SrvSetServerVarReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(type)) {
        return;
    }
    if (!reader.get_uint32_t(value)) {
        return;
    }
}

SrvSetServerVarReply& SrvSetServerVarReply::set_type(const uint8_t type) {
    this->type = type;
    return *this;
}

uint8_t SrvSetServerVarReply::get_type() const {
    return type;
}

SrvSetServerVarReply& SrvSetServerVarReply::set_value(const uint32_t value) {
    this->value = value;
    return *this;
}

uint32_t SrvSetServerVarReply::get_value() const {
    return value;
}

SrvSetServerVarReply SrvSetServerVarReply::create() {
    SrvSetServerVarReply packet;
    return packet;
}

SrvSetServerVarReply SrvSetServerVarReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetServerVarReply(reader);
}

std::unique_ptr<SrvSetServerVarReply> SrvSetServerVarReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetServerVarReply>(reader);
}

bool SrvSetServerVarReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint32_t(value)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetServerVarReply::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // type
    size += sizeof(uint32_t); // value
    return size;
}

