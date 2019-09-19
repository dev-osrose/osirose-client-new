#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSkillCastSelf : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SKILL_CAST_SELF;
        CliSkillCastSelf();
        CliSkillCastSelf(CRoseReader reader);
        CliSkillCastSelf(CliSkillCastSelf&&) = default;
        CliSkillCastSelf& operator=(CliSkillCastSelf&&) = default;
        ~CliSkillCastSelf() = default;
        
        static constexpr size_t size();
        
        
        
        CliSkillCastSelf& set_slot(const uint8_t);
        uint8_t get_slot() const;
        
        
        static CliSkillCastSelf create(const uint8_t& slot);
        static CliSkillCastSelf create(const uint8_t* buffer);
        static std::unique_ptr<CliSkillCastSelf> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t slot;
};

}
}
