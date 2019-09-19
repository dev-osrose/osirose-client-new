#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillCastTarget : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_CAST_TARGET;
        SrvSkillCastTarget();
        SrvSkillCastTarget(CRoseReader reader);
        SrvSkillCastTarget(SrvSkillCastTarget&&) = default;
        SrvSkillCastTarget& operator=(SrvSkillCastTarget&&) = default;
        ~SrvSkillCastTarget() = default;
        
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
        
        
        SrvSkillCastTarget& set_source(const uint16_t);
        uint16_t get_source() const;
        SrvSkillCastTarget& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSkillCastTarget& set_id(const int8_t);
        int8_t get_id() const;
        SrvSkillCastTarget& set_distance(const uint16_t);
        uint16_t get_distance() const;
        SrvSkillCastTarget& set_x(const float);
        float get_x() const;
        SrvSkillCastTarget& set_y(const float);
        float get_y() const;
        SrvSkillCastTarget& set_animation(const MobAnimation);
        MobAnimation get_animation() const;
        
        
        static SrvSkillCastTarget create(const uint16_t& source, const uint16_t& target, const int8_t& id, const uint16_t& distance, const float& x, const float& y);
        static SrvSkillCastTarget create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillCastTarget> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t source;
        uint16_t target;
        int8_t id;
        uint16_t distance;
        float x;
        float y;
        MobAnimation animation = MobAnimation::STOP;
};

}
}
