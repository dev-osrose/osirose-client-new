#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliStopMoving : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_STOP_MOVING;
        CliStopMoving();
        CliStopMoving(CRoseReader reader);
        CliStopMoving(CliStopMoving&&) = default;
        CliStopMoving& operator=(CliStopMoving&&) = default;
        ~CliStopMoving() = default;
        
        static constexpr size_t size();
        
        
        
        CliStopMoving& set_x(const float);
        float get_x() const;
        CliStopMoving& set_y(const float);
        float get_y() const;
        CliStopMoving& set_z(const uint16_t);
        uint16_t get_z() const;
        
        
        static CliStopMoving create(const float& x, const float& y, const uint16_t& z);
        static CliStopMoving create(const uint8_t* buffer);
        static std::unique_ptr<CliStopMoving> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        float x;
        float y;
        uint16_t z;
};

}
}
