#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSkillCastPosition : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SKILL_CAST_POSITION;
        CliSkillCastPosition();
        CliSkillCastPosition(CRoseReader reader);
        CliSkillCastPosition(CliSkillCastPosition&&) = default;
        CliSkillCastPosition& operator=(CliSkillCastPosition&&) = default;
        ~CliSkillCastPosition() = default;
        
        static constexpr size_t size();
        
        
        
        CliSkillCastPosition& set_slot(const uint8_t);
        uint8_t get_slot() const;
        CliSkillCastPosition& set_x(const float);
        float get_x() const;
        CliSkillCastPosition& set_y(const float);
        float get_y() const;
        
        
        static CliSkillCastPosition create(const uint8_t& slot, const float& x, const float& y);
        static CliSkillCastPosition create(const uint8_t* buffer);
        static std::unique_ptr<CliSkillCastPosition> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t slot;
        float x;
        float y;
};

}
}
