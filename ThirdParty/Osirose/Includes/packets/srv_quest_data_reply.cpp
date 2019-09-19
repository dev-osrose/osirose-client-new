#include "srv_quest_data_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvQuestDataReply::SrvQuestDataReply() : CRosePacket(SrvQuestDataReply::PACKET_ID) {}

SrvQuestDataReply::SrvQuestDataReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<QuestDataResult>(result_temp);
    
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_int32_t(id)) {
        return;
    }
}

SrvQuestDataReply& SrvQuestDataReply::set_result(const SrvQuestDataReply::QuestDataResult result) {
    this->result = result;
    return *this;
}

SrvQuestDataReply::QuestDataResult SrvQuestDataReply::get_result() const {
    return result;
}

SrvQuestDataReply& SrvQuestDataReply::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t SrvQuestDataReply::get_slot() const {
    return slot;
}

SrvQuestDataReply& SrvQuestDataReply::set_id(const int32_t id) {
    this->id = id;
    return *this;
}

int32_t SrvQuestDataReply::get_id() const {
    return id;
}

SrvQuestDataReply SrvQuestDataReply::create(const SrvQuestDataReply::QuestDataResult& result, const uint8_t& slot, const int32_t& id) {
    SrvQuestDataReply packet;
    packet.set_result(result);
    packet.set_slot(slot);
    packet.set_id(id);
    return packet;
}

SrvQuestDataReply SrvQuestDataReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvQuestDataReply(reader);
}

std::unique_ptr<SrvQuestDataReply> SrvQuestDataReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvQuestDataReply>(reader);
}

bool SrvQuestDataReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
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

constexpr size_t SrvQuestDataReply::size() {
    size_t size = 0;
    size += sizeof(QuestDataResult); // result
    size += sizeof(uint8_t); // slot
    size += sizeof(int32_t); // id
    return size;
}

