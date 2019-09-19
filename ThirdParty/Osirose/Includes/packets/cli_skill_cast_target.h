#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSkillCastTarget : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SKILL_CAST_TARGET;
        CliSkillCastTarget();
        CliSkillCastTarget(CRoseReader reader);
        CliSkillCastTarget(CliSkillCastTarget&&) = default;
        CliSkillCastTarget& operator=(CliSkillCastTarget&&) = default;
        ~CliSkillCastTarget() = default;
        
        static constexpr size_t size();
        
        
        
        CliSkillCastTarget& set_target(const uint16_t);
        uint16_t get_target() const;
        CliSkillCastTarget& set_slot(const uint8_t);
        uint8_t get_slot() const;
        
        
        static CliSkillCastTarget create(const uint16_t& target, const uint8_t& slot);
        static CliSkillCastTarget create(const uint8_t* buffer);
        static std::unique_ptr<CliSkillCastTarget> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        uint8_t slot;
};

}
}
