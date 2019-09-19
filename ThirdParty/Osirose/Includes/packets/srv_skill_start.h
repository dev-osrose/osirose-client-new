#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillStart : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_START;
        SrvSkillStart();
        SrvSkillStart(CRoseReader reader);
        SrvSkillStart(SrvSkillStart&&) = default;
        SrvSkillStart& operator=(SrvSkillStart&&) = default;
        ~SrvSkillStart() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSkillStart& set_target(const uint16_t);
        uint16_t get_target() const;
        
        
        static SrvSkillStart create(const uint16_t& target);
        static SrvSkillStart create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillStart> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
};

}
}
