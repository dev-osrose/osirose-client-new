#include "srv_update_npc.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvUpdateNpc::SrvUpdateNpc() : CRosePacket(SrvUpdateNpc::PACKET_ID) {}

SrvUpdateNpc::SrvUpdateNpc(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_int16_t(npc_id)) {
        return;
    }
}

SrvUpdateNpc& SrvUpdateNpc::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvUpdateNpc::get_id() const {
    return id;
}

SrvUpdateNpc& SrvUpdateNpc::set_npc_id(const int16_t npc_id) {
    this->npc_id = npc_id;
    return *this;
}

int16_t SrvUpdateNpc::get_npc_id() const {
    return npc_id;
}

SrvUpdateNpc SrvUpdateNpc::create(const uint16_t& id) {
    SrvUpdateNpc packet;
    packet.set_id(id);
    return packet;
}

SrvUpdateNpc SrvUpdateNpc::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvUpdateNpc(reader);
}

std::unique_ptr<SrvUpdateNpc> SrvUpdateNpc::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvUpdateNpc>(reader);
}

bool SrvUpdateNpc::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_int16_t(npc_id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvUpdateNpc::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(int16_t); // npc_id
    return size;
}

