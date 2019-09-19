#include "srv_update_name.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvUpdateName::SrvUpdateName() : CRosePacket(SrvUpdateName::PACKET_ID) {}

SrvUpdateName::SrvUpdateName(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

SrvUpdateName& SrvUpdateName::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvUpdateName::get_target() const {
    return target;
}

SrvUpdateName& SrvUpdateName::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvUpdateName::get_name() const {
    return name;
}

SrvUpdateName SrvUpdateName::create(const uint16_t& target, const std::string& name) {
    SrvUpdateName packet;
    packet.set_target(target);
    packet.set_name(name);
    return packet;
}

SrvUpdateName SrvUpdateName::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvUpdateName(reader);
}

std::unique_ptr<SrvUpdateName> SrvUpdateName::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvUpdateName>(reader);
}

bool SrvUpdateName::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t SrvUpdateName::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    return size;
}

