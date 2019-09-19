#include "srv_gm_command_code.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvGmCommandCode::SrvGmCommandCode() : CRosePacket(SrvGmCommandCode::PACKET_ID) {}

SrvGmCommandCode::SrvGmCommandCode(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_string(command)) {
        return;
    }
}

SrvGmCommandCode& SrvGmCommandCode::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvGmCommandCode::get_target() const {
    return target;
}

SrvGmCommandCode& SrvGmCommandCode::set_command(const std::string& command) {
    this->command = command;
    return *this;
}

const std::string& SrvGmCommandCode::get_command() const {
    return command;
}

SrvGmCommandCode SrvGmCommandCode::create(const uint16_t& target, const std::string& command) {
    SrvGmCommandCode packet;
    packet.set_target(target);
    packet.set_command(command);
    return packet;
}

SrvGmCommandCode SrvGmCommandCode::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvGmCommandCode(reader);
}

std::unique_ptr<SrvGmCommandCode> SrvGmCommandCode::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvGmCommandCode>(reader);
}

bool SrvGmCommandCode::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_string(command)) {
        return false;
    }
    return true;
}

constexpr size_t SrvGmCommandCode::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    return size;
}

