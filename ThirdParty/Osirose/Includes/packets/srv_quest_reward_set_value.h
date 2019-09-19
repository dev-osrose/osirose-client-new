#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvQuestRewardSetValue : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_QUEST_REWARD_SET_VALUE;
        SrvQuestRewardSetValue();
        SrvQuestRewardSetValue(CRoseReader reader);
        SrvQuestRewardSetValue(SrvQuestRewardSetValue&&) = default;
        SrvQuestRewardSetValue& operator=(SrvQuestRewardSetValue&&) = default;
        ~SrvQuestRewardSetValue() = default;
        
        static constexpr size_t size();
        
        
        enum QuestRewardValueType : uint16_t {
            SEX = 2,
            CLASS = 4,
            UNION = 5,
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
            LEVEL = 31,
            PK_FLAG = 33,
            TEAM = 34,
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
        
        
        SrvQuestRewardSetValue& set_type(const QuestRewardValueType);
        QuestRewardValueType get_type() const;
        SrvQuestRewardSetValue& set_value(const int32_t);
        int32_t get_value() const;
        
        
        static SrvQuestRewardSetValue create(const QuestRewardValueType& type, const int32_t& value);
        static SrvQuestRewardSetValue create(const uint8_t* buffer);
        static std::unique_ptr<SrvQuestRewardSetValue> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        QuestRewardValueType type;
        int32_t value;
};

}
}
