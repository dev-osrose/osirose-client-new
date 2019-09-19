#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillFinish : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_FINISH;
        SrvSkillFinish();
        SrvSkillFinish(CRoseReader reader);
        SrvSkillFinish(SrvSkillFinish&&) = default;
        SrvSkillFinish& operator=(SrvSkillFinish&&) = default;
        ~SrvSkillFinish() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSkillFinish& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSkillFinish& set_id(const uint16_t);
        uint16_t get_id() const;
        
        
        static SrvSkillFinish create(const uint16_t& target, const uint16_t& id);
        static SrvSkillFinish create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillFinish> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        uint16_t id;
};

}
}
