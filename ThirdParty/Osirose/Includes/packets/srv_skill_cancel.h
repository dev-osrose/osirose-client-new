#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillCancel : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_CANCEL;
        SrvSkillCancel();
        SrvSkillCancel(CRoseReader reader);
        SrvSkillCancel(SrvSkillCancel&&) = default;
        SrvSkillCancel& operator=(SrvSkillCancel&&) = default;
        ~SrvSkillCancel() = default;
        
        static constexpr size_t size();
        
        
        enum SkillCancelResult : uint8_t {
            INVALID_SKILL = 0,
            INVALID_TARGET = 1,
            TARGET_NOT_FOUND = 2,
        };
        
        
        SrvSkillCancel& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSkillCancel& set_result(const SkillCancelResult);
        SkillCancelResult get_result() const;
        
        
        static SrvSkillCancel create(const uint16_t& target, const SkillCancelResult& result);
        static SrvSkillCancel create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillCancel> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        SkillCancelResult result;
};

}
}
