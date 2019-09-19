#include "srv_hp_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvHpReply::SrvHpReply() : CRosePacket(SrvHpReply::PACKET_ID) {}

SrvHpReply::SrvHpReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_int32_t(hp)) {
        return;
    }
}

SrvHpReply& SrvHpReply::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvHpReply::get_id() const {
    return id;
}

SrvHpReply& SrvHpReply::set_hp(const int32_t hp) {
    this->hp = hp;
    return *this;
}

int32_t SrvHpReply::get_hp() const {
    return hp;
}

SrvHpReply SrvHpReply::create(const uint16_t& id, const int32_t& hp) {
    SrvHpReply packet;
    packet.set_id(id);
    packet.set_hp(hp);
    return packet;
}

SrvHpReply SrvHpReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvHpReply(reader);
}

std::unique_ptr<SrvHpReply> SrvHpReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvHpReply>(reader);
}

bool SrvHpReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_int32_t(hp)) {
        return false;
    }
    return true;
}

constexpr size_t SrvHpReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(int32_t); // hp
    return size;
}

