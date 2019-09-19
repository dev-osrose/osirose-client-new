#include "srv_quest_reward_add_value.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvQuestRewardAddValue::SrvQuestRewardAddValue() : CRosePacket(SrvQuestRewardAddValue::PACKET_ID) {}

SrvQuestRewardAddValue::SrvQuestRewardAddValue(CRoseReader reader) : CRosePacket(reader) {
    uint16_t type_temp;
    if (!reader.get_uint16_t(type_temp)) {
        return;
    }
    type = static_cast<QuestRewardValueType>(type_temp);
    
    if (!reader.get_int32_t(value)) {
        return;
    }
}

SrvQuestRewardAddValue& SrvQuestRewardAddValue::set_type(const SrvQuestRewardAddValue::QuestRewardValueType type) {
    this->type = type;
    return *this;
}

SrvQuestRewardAddValue::QuestRewardValueType SrvQuestRewardAddValue::get_type() const {
    return type;
}

SrvQuestRewardAddValue& SrvQuestRewardAddValue::set_value(const int32_t value) {
    this->value = value;
    return *this;
}

int32_t SrvQuestRewardAddValue::get_value() const {
    return value;
}

SrvQuestRewardAddValue SrvQuestRewardAddValue::create(const SrvQuestRewardAddValue::QuestRewardValueType& type, const int32_t& value) {
    SrvQuestRewardAddValue packet;
    packet.set_type(type);
    packet.set_value(value);
    return packet;
}

SrvQuestRewardAddValue SrvQuestRewardAddValue::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvQuestRewardAddValue(reader);
}

std::unique_ptr<SrvQuestRewardAddValue> SrvQuestRewardAddValue::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvQuestRewardAddValue>(reader);
}

bool SrvQuestRewardAddValue::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(type)) {
        return false;
    }
    if (!writer.set_int32_t(value)) {
        return false;
    }
    return true;
}

constexpr size_t SrvQuestRewardAddValue::size() {
    size_t size = 0;
    size += sizeof(QuestRewardValueType); // type
    size += sizeof(int32_t); // value
    return size;
}

