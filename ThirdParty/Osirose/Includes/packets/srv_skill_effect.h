#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillEffect : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_EFFECT;
        SrvSkillEffect();
        SrvSkillEffect(CRoseReader reader);
        SrvSkillEffect(SrvSkillEffect&&) = default;
        SrvSkillEffect& operator=(SrvSkillEffect&&) = default;
        ~SrvSkillEffect() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSkillEffect& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSkillEffect& set_source(const uint16_t);
        uint16_t get_source() const;
        SrvSkillEffect& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvSkillEffect& set_amount(const float);
        float get_amount() const;
        SrvSkillEffect& set_state(const uint8_t);
        uint8_t get_state() const;
        
        
        static SrvSkillEffect create(const uint16_t& target, const uint16_t& source, const uint16_t& id, const float& amount, const uint8_t& state);
        static SrvSkillEffect create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillEffect> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        uint16_t source;
        uint16_t id;
        float amount;
        uint8_t state;
};

}
}
