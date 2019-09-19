#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvRideStateChange : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_RIDE_STATE_CHANGE;
        SrvRideStateChange();
        SrvRideStateChange(CRoseReader reader);
        SrvRideStateChange(SrvRideStateChange&&) = default;
        SrvRideStateChange& operator=(SrvRideStateChange&&) = default;
        ~SrvRideStateChange() = default;
        
        static constexpr size_t size();
        
        
        
        SrvRideStateChange& set_enabled(const int8_t);
        int8_t get_enabled() const;
        SrvRideStateChange& set_cooldown(const uint32_t);
        uint32_t get_cooldown() const;
        SrvRideStateChange& set_max_hp(const int16_t);
        int16_t get_max_hp() const;
        SrvRideStateChange& set_target(const uint16_t);
        uint16_t get_target() const;
        
        
        static SrvRideStateChange create(const int8_t& enabled, const uint32_t& cooldown, const int16_t& max_hp, const uint16_t& target);
        static SrvRideStateChange create(const uint8_t* buffer);
        static std::unique_ptr<SrvRideStateChange> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int8_t enabled;
        uint32_t cooldown;
        int16_t max_hp;
        uint16_t target;
};

}
}
