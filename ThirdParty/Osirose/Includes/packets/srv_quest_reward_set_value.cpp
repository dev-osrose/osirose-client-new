#include "srv_quest_reward_set_value.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvQuestRewardSetValue::SrvQuestRewardSetValue() : CRosePacket(SrvQuestRewardSetValue::PACKET_ID) {}

SrvQuestRewardSetValue::SrvQuestRewardSetValue(CRoseReader reader) : CRosePacket(reader) {
    uint16_t type_temp;
    if (!reader.get_uint16_t(type_temp)) {
        return;
    }
    type = static_cast<QuestRewardValueType>(type_temp);
    
    if (!reader.get_int32_t(value)) {
        return;
    }
}

SrvQuestRewardSetValue& SrvQuestRewardSetValue::set_type(const SrvQuestRewardSetValue::QuestRewardValueType type) {
    this->type = type;
    return *this;
}

SrvQuestRewardSetValue::QuestRewardValueType SrvQuestRewardSetValue::get_type() const {
    return type;
}

SrvQuestRewardSetValue& SrvQuestRewardSetValue::set_value(const int32_t value) {
    this->value = value;
    return *this;
}

int32_t SrvQuestRewardSetValue::get_value() const {
    return value;
}

SrvQuestRewardSetValue SrvQuestRewardSetValue::create(const SrvQuestRewardSetValue::QuestRewardValueType& type, const int32_t& value) {
    SrvQuestRewardSetValue packet;
    packet.set_type(type);
    packet.set_value(value);
    return packet;
}

SrvQuestRewardSetValue SrvQuestRewardSetValue::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvQuestRewardSetValue(reader);
}

std::unique_ptr<SrvQuestRewardSetValue> SrvQuestRewardSetValue::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvQuestRewardSetValue>(reader);
}

bool SrvQuestRewardSetValue::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(type)) {
        return false;
    }
    if (!writer.set_int32_t(value)) {
        return false;
    }
    return true;
}

constexpr size_t SrvQuestRewardSetValue::size() {
    size_t size = 0;
    size += sizeof(QuestRewardValueType); // type
    size += sizeof(int32_t); // value
    return size;
}

