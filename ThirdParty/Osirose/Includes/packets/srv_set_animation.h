#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetAnimation : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PACWC_SET_ANIMATION;
        SrvSetAnimation();
        SrvSetAnimation(CRoseReader reader);
        SrvSetAnimation(SrvSetAnimation&&) = default;
        SrvSetAnimation& operator=(SrvSetAnimation&&) = default;
        ~SrvSetAnimation() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetAnimation& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvSetAnimation& set_value(const uint16_t);
        uint16_t get_value() const;
        SrvSetAnimation& set_object_id(const uint16_t);
        uint16_t get_object_id() const;
        
        
        static SrvSetAnimation create();
        static SrvSetAnimation create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetAnimation> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id = 0;
        uint16_t value = 0;
        uint16_t object_id = 0;
};

}
}
