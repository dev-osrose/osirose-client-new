#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillLearn : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_LEARN;
        SrvSkillLearn();
        SrvSkillLearn(CRoseReader reader);
        SrvSkillLearn(SrvSkillLearn&&) = default;
        SrvSkillLearn& operator=(SrvSkillLearn&&) = default;
        ~SrvSkillLearn() = default;
        
        static constexpr size_t size();
        
        
        enum SkillLearnResult : uint8_t {
            FAILED = 0,
            SUCCEEDED = 1,
            NEED_JOB = 2,
            NEED_SKILL = 3,
            NEED_STAT = 4,
            NO_SLOTS = 5,
            INVALID_SKILL = 6,
            NO_POINTS = 7,
            DELETE = 8,
        };
        
        
        SrvSkillLearn& set_result(const SkillLearnResult);
        SkillLearnResult get_result() const;
        SrvSkillLearn& set_slot(const uint8_t);
        uint8_t get_slot() const;
        SrvSkillLearn& set_id(const int16_t);
        int16_t get_id() const;
        SrvSkillLearn& set_points(const int16_t);
        int16_t get_points() const;
        
        
        static SrvSkillLearn create(const SkillLearnResult& result, const uint8_t& slot, const int16_t& id, const int16_t& points);
        static SrvSkillLearn create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillLearn> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        SkillLearnResult result;
        uint8_t slot;
        int16_t id;
        int16_t points;
};

}
}
