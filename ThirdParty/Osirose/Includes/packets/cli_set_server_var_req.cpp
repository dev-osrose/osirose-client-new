#include "cli_set_server_var_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSetServerVarReq::CliSetServerVarReq() : CRosePacket(CliSetServerVarReq::PACKET_ID) {}

CliSetServerVarReq::CliSetServerVarReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(type)) {
        return;
    }
    if (!reader.get_uint32_t(value)) {
        return;
    }
}

CliSetServerVarReq& CliSetServerVarReq::set_type(const uint8_t type) {
    this->type = type;
    return *this;
}

uint8_t CliSetServerVarReq::get_type() const {
    return type;
}

CliSetServerVarReq& CliSetServerVarReq::set_value(const uint32_t value) {
    this->value = value;
    return *this;
}

uint32_t CliSetServerVarReq::get_value() const {
    return value;
}

CliSetServerVarReq CliSetServerVarReq::create(const uint8_t& type, const uint32_t& value) {
    CliSetServerVarReq packet;
    packet.set_type(type);
    packet.set_value(value);
    return packet;
}

CliSetServerVarReq CliSetServerVarReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSetServerVarReq(reader);
}

std::unique_ptr<CliSetServerVarReq> CliSetServerVarReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSetServerVarReq>(reader);
}

bool CliSetServerVarReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint32_t(value)) {
        return false;
    }
    return true;
}

constexpr size_t CliSetServerVarReq::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // type
    size += sizeof(uint32_t); // value
    return size;
}

