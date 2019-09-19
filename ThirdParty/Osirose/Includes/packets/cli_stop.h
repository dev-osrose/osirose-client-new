#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliStop : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_STOP;
        CliStop();
        CliStop(CRoseReader reader);
        CliStop(CliStop&&) = default;
        CliStop& operator=(CliStop&&) = default;
        ~CliStop() = default;
        
        static constexpr size_t size();
        
        
        
        CliStop& set_x(const float);
        float get_x() const;
        CliStop& set_y(const float);
        float get_y() const;
        
        
        static CliStop create(const float& x, const float& y);
        static CliStop create(const uint8_t* buffer);
        static std::unique_ptr<CliStop> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        float x;
        float y;
};

}
}
