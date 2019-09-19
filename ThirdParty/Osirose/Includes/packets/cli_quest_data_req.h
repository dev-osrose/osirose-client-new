#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliQuestDataReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_QUEST_DATA_REQ;
        CliQuestDataReq();
        CliQuestDataReq(CRoseReader reader);
        CliQuestDataReq(CliQuestDataReq&&) = default;
        CliQuestDataReq& operator=(CliQuestDataReq&&) = default;
        ~CliQuestDataReq() = default;
        
        static constexpr size_t size();
        
        
        enum QuestDataRequestType : uint8_t {
            ADD = 0,
            REMOVE = 1,
            TRIGGER = 2,
        };
        
        
        CliQuestDataReq& set_type(const QuestDataRequestType);
        QuestDataRequestType get_type() const;
        CliQuestDataReq& set_slot(const uint8_t);
        uint8_t get_slot() const;
        CliQuestDataReq& set_id(const int32_t);
        int32_t get_id() const;
        
        
        static CliQuestDataReq create(const QuestDataRequestType& type, const uint8_t& slot, const int32_t& id);
        static CliQuestDataReq create(const uint8_t* buffer);
        static std::unique_ptr<CliQuestDataReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        QuestDataRequestType type;
        uint8_t slot;
        int32_t id;
};

}
}
