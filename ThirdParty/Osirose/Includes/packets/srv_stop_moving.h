#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvStopMoving : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_STOP_MOVING;
        SrvStopMoving();
        SrvStopMoving(CRoseReader reader);
        SrvStopMoving(SrvStopMoving&&) = default;
        SrvStopMoving& operator=(SrvStopMoving&&) = default;
        ~SrvStopMoving() = default;
        
        static constexpr size_t size();
        
        
        
        SrvStopMoving& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvStopMoving& set_x(const float);
        float get_x() const;
        SrvStopMoving& set_y(const float);
        float get_y() const;
        SrvStopMoving& set_z(const int16_t);
        int16_t get_z() const;
        
        
        static SrvStopMoving create(const uint16_t& char_id, const float& x, const float& y, const int16_t& z);
        static SrvStopMoving create(const uint8_t* buffer);
        static std::unique_ptr<SrvStopMoving> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        float x;
        float y;
        int16_t z;
};

}
}
