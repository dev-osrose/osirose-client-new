#include "srv_global_flags.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvGlobalFlags::SrvGlobalFlags() : CRosePacket(SrvGlobalFlags::PACKET_ID) {}

SrvGlobalFlags::SrvGlobalFlags(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int32_t(flags)) {
        return;
    }
}

SrvGlobalFlags& SrvGlobalFlags::set_flags(const int32_t flags) {
    this->flags = flags;
    return *this;
}

int32_t SrvGlobalFlags::get_flags() const {
    return flags;
}

SrvGlobalFlags SrvGlobalFlags::create(const int32_t& flags) {
    SrvGlobalFlags packet;
    packet.set_flags(flags);
    return packet;
}

SrvGlobalFlags SrvGlobalFlags::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvGlobalFlags(reader);
}

std::unique_ptr<SrvGlobalFlags> SrvGlobalFlags::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvGlobalFlags>(reader);
}

bool SrvGlobalFlags::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int32_t(flags)) {
        return false;
    }
    return true;
}

constexpr size_t SrvGlobalFlags::size() {
    size_t size = 0;
    size += sizeof(int32_t); // flags
    return size;
}

