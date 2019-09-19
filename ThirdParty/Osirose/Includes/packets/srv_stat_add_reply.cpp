#include "srv_stat_add_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvStatAddReply::SrvStatAddReply() : CRosePacket(SrvStatAddReply::PACKET_ID) {}

SrvStatAddReply::SrvStatAddReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t stat_temp;
    if (!reader.get_uint8_t(stat_temp)) {
        return;
    }
    stat = static_cast<Stat>(stat_temp);
    
    if (!reader.get_int16_t(value)) {
        return;
    }
}

SrvStatAddReply& SrvStatAddReply::set_stat(const SrvStatAddReply::Stat stat) {
    this->stat = stat;
    return *this;
}

SrvStatAddReply::Stat SrvStatAddReply::get_stat() const {
    return stat;
}

SrvStatAddReply& SrvStatAddReply::set_value(const int16_t value) {
    this->value = value;
    return *this;
}

int16_t SrvStatAddReply::get_value() const {
    return value;
}

SrvStatAddReply SrvStatAddReply::create(const SrvStatAddReply::Stat& stat, const int16_t& value) {
    SrvStatAddReply packet;
    packet.set_stat(stat);
    packet.set_value(value);
    return packet;
}

SrvStatAddReply SrvStatAddReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvStatAddReply(reader);
}

std::unique_ptr<SrvStatAddReply> SrvStatAddReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvStatAddReply>(reader);
}

bool SrvStatAddReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(stat)) {
        return false;
    }
    if (!writer.set_int16_t(value)) {
        return false;
    }
    return true;
}

constexpr size_t SrvStatAddReply::size() {
    size_t size = 0;
    size += sizeof(Stat); // stat
    size += sizeof(int16_t); // value
    return size;
}

