#include "srv_revive_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvReviveReply::SrvReviveReply() : CRosePacket(SrvReviveReply::PACKET_ID) {}

SrvReviveReply::SrvReviveReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(map_id)) {
        return;
    }
}

SrvReviveReply& SrvReviveReply::set_map_id(const uint16_t map_id) {
    this->map_id = map_id;
    return *this;
}

uint16_t SrvReviveReply::get_map_id() const {
    return map_id;
}

SrvReviveReply SrvReviveReply::create() {
    SrvReviveReply packet;
    return packet;
}

SrvReviveReply SrvReviveReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvReviveReply(reader);
}

std::unique_ptr<SrvReviveReply> SrvReviveReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvReviveReply>(reader);
}

bool SrvReviveReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(map_id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvReviveReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // map_id
    return size;
}

