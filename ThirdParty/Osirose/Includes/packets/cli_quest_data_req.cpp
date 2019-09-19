#include "cli_quest_data_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliQuestDataReq::CliQuestDataReq() : CRosePacket(CliQuestDataReq::PACKET_ID) {}

CliQuestDataReq::CliQuestDataReq(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<QuestDataRequestType>(type_temp);
    
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_int32_t(id)) {
        return;
    }
}

CliQuestDataReq& CliQuestDataReq::set_type(const CliQuestDataReq::QuestDataRequestType type) {
    this->type = type;
    return *this;
}

CliQuestDataReq::QuestDataRequestType CliQuestDataReq::get_type() const {
    return type;
}

CliQuestDataReq& CliQuestDataReq::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t CliQuestDataReq::get_slot() const {
    return slot;
}

CliQuestDataReq& CliQuestDataReq::set_id(const int32_t id) {
    this->id = id;
    return *this;
}

int32_t CliQuestDataReq::get_id() const {
    return id;
}

CliQuestDataReq CliQuestDataReq::create(const CliQuestDataReq::QuestDataRequestType& type, const uint8_t& slot, const int32_t& id) {
    CliQuestDataReq packet;
    packet.set_type(type);
    packet.set_slot(slot);
    packet.set_id(id);
    return packet;
}

CliQuestDataReq CliQuestDataReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliQuestDataReq(reader);
}

std::unique_ptr<CliQuestDataReq> CliQuestDataReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliQuestDataReq>(reader);
}

bool CliQuestDataReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_int32_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t CliQuestDataReq::size() {
    size_t size = 0;
    size += sizeof(QuestDataRequestType); // type
    size += sizeof(uint8_t); // slot
    size += sizeof(int32_t); // id
    return size;
}

