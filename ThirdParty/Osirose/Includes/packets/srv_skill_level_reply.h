#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillLevelReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_LEVEL_REPLY;
        SrvSkillLevelReply();
        SrvSkillLevelReply(CRoseReader reader);
        SrvSkillLevelReply(SrvSkillLevelReply&&) = default;
        SrvSkillLevelReply& operator=(SrvSkillLevelReply&&) = default;
        ~SrvSkillLevelReply() = default;
        
        static constexpr size_t size();
        
        
        enum SkillLevelResult : uint8_t {
            SUCCEEDED = 0,
            FAILED = 1,
            NO_POINTS = 2,
            NEED_STAT = 3,
            NEED_JOB = 4,
            NEED_SKILL = 5,
            NO_MONEY = 6,
        };
        
        
        SrvSkillLevelReply& set_result(const SkillLevelResult);
        SkillLevelResult get_result() const;
        SrvSkillLevelReply& set_slot(const uint8_t);
        uint8_t get_slot() const;
        SrvSkillLevelReply& set_id(const int16_t);
        int16_t get_id() const;
        SrvSkillLevelReply& set_points(const int16_t);
        int16_t get_points() const;
        
        
        static SrvSkillLevelReply create(const SkillLevelResult& result, const uint8_t& slot, const int16_t& id, const int16_t& points);
        static SrvSkillLevelReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillLevelReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        SkillLevelResult result;
        uint8_t slot;
        int16_t id;
        int16_t points;
};

}
}
