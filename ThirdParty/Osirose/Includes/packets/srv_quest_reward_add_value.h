#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvQuestRewardAddValue : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_QUEST_REWARD_ADD_VALUE;
        SrvQuestRewardAddValue();
        SrvQuestRewardAddValue(CRoseReader reader);
        SrvQuestRewardAddValue(SrvQuestRewardAddValue&&) = default;
        SrvQuestRewardAddValue& operator=(SrvQuestRewardAddValue&&) = default;
        ~SrvQuestRewardAddValue() = default;
        
        static constexpr size_t size();
        
        
        enum QuestRewardValueType : uint16_t {
            SEX = 2,
            FACE = 8,
            HAIR = 9,
            STR = 10,
            DEX = 11,
            INT = 12,
            CON = 13,
            CHA = 14,
            SEN = 15,
            HP = 16,
            MP = 17,
            EXP = 30,
            STATPOINT = 32,
            SKILLPOINT = 37,
            MONEY = 40,
            STAMINA = 76,
            UNIONPOINT1 = 81,
            UNIONPOINT2 = 82,
            UNIONPOINT3 = 83,
            UNIONPOINT4 = 84,
            UNIONPOINT5 = 85,
            UNIONPOINT6 = 86,
            UNIONPOINT7 = 87,
            UNIONPOINT8 = 88,
            UNIONPOINT9 = 89,
            UNIONPOINT10 = 90,
        };
        
        
        SrvQuestRewardAddValue& set_type(const QuestRewardValueType);
        QuestRewardValueType get_type() const;
        SrvQuestRewardAddValue& set_value(const int32_t);
        int32_t get_value() const;
        
        
        static SrvQuestRewardAddValue create(const QuestRewardValueType& type, const int32_t& value);
        static SrvQuestRewardAddValue create(const uint8_t* buffer);
        static std::unique_ptr<SrvQuestRewardAddValue> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        QuestRewardValueType type;
        int32_t value;
};

}
}
