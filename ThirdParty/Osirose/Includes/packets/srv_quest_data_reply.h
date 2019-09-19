#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvQuestDataReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_QUEST_DATA_REPLY;
        SrvQuestDataReply();
        SrvQuestDataReply(CRoseReader reader);
        SrvQuestDataReply(SrvQuestDataReply&&) = default;
        SrvQuestDataReply& operator=(SrvQuestDataReply&&) = default;
        ~SrvQuestDataReply() = default;
        
        static constexpr size_t size();
        
        
        enum QuestDataResult : uint8_t {
            ADD_SUCCESS = 0,
            ADD_FAIL = 1,
            REMOVE_SUCCESS = 2,
            REMOVE_FAIL = 3,
            TRIGGER_SUCCESS = 4,
            TRIGGER_FAIL = 5,
        };
        
        
        SrvQuestDataReply& set_result(const QuestDataResult);
        QuestDataResult get_result() const;
        SrvQuestDataReply& set_slot(const uint8_t);
        uint8_t get_slot() const;
        SrvQuestDataReply& set_id(const int32_t);
        int32_t get_id() const;
        
        
        static SrvQuestDataReply create(const QuestDataResult& result, const uint8_t& slot, const int32_t& id);
        static SrvQuestDataReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvQuestDataReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        QuestDataResult result;
        uint8_t slot;
        int32_t id;
};

}
}
