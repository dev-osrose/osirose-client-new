#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillCastSelf : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_CAST_SELF;
        SrvSkillCastSelf();
        SrvSkillCastSelf(CRoseReader reader);
        SrvSkillCastSelf(SrvSkillCastSelf&&) = default;
        SrvSkillCastSelf& operator=(SrvSkillCastSelf&&) = default;
        ~SrvSkillCastSelf() = default;
        
        static constexpr size_t size();
        
        
        enum MobAnimation : uint8_t {
            STOP = 0,
            ATTACK = 1,
            HIT = 2,
            DIE = 3,
            RUN = 4,
            ACTION1 = 5,
            SKILL1 = 6,
            ACTION2 = 7,
            SKILL2 = 8,
            ETC = 9,
        };
        
        
        SrvSkillCastSelf& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSkillCastSelf& set_id(const int8_t);
        int8_t get_id() const;
        SrvSkillCastSelf& set_animation(const MobAnimation);
        MobAnimation get_animation() const;
        
        
        static SrvSkillCastSelf create(const uint16_t& target, const int8_t& id);
        static SrvSkillCastSelf create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillCastSelf> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        int8_t id;
        MobAnimation animation = MobAnimation::STOP;
};

}
}
