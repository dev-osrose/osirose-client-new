#include "cli_repair_npc.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliRepairNpc::CliRepairNpc() : CRosePacket(CliRepairNpc::PACKET_ID) {}

CliRepairNpc::CliRepairNpc(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(npc_id)) {
        return;
    }
    if (!reader.get_uint16_t(target_index)) {
        return;
    }
}

CliRepairNpc& CliRepairNpc::set_npc_id(const uint16_t npc_id) {
    this->npc_id = npc_id;
    return *this;
}

uint16_t CliRepairNpc::get_npc_id() const {
    return npc_id;
}

CliRepairNpc& CliRepairNpc::set_target_index(const uint16_t target_index) {
    this->target_index = target_index;
    return *this;
}

uint16_t CliRepairNpc::get_target_index() const {
    return target_index;
}

CliRepairNpc CliRepairNpc::create(const uint16_t& npc_id, const uint16_t& target_index) {
    CliRepairNpc packet;
    packet.set_npc_id(npc_id);
    packet.set_target_index(target_index);
    return packet;
}

CliRepairNpc CliRepairNpc::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliRepairNpc(reader);
}

std::unique_ptr<CliRepairNpc> CliRepairNpc::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliRepairNpc>(reader);
}

bool CliRepairNpc::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(npc_id)) {
        return false;
    }
    if (!writer.set_uint16_t(target_index)) {
        return false;
    }
    return true;
}

constexpr size_t CliRepairNpc::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // npc_id
    size += sizeof(uint16_t); // target_index
    return size;
}

