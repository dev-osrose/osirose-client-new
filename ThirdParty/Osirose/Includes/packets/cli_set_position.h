#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSetPosition : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SET_POSITION;
        CliSetPosition();
        CliSetPosition(CRoseReader reader);
        CliSetPosition(CliSetPosition&&) = default;
        CliSetPosition& operator=(CliSetPosition&&) = default;
        ~CliSetPosition() = default;
        
        static constexpr size_t size();
        
        
        
        CliSetPosition& set_x(const float);
        float get_x() const;
        CliSetPosition& set_y(const float);
        float get_y() const;
        
        
        static CliSetPosition create(const float& x, const float& y);
        static CliSetPosition create(const uint8_t* buffer);
        static std::unique_ptr<CliSetPosition> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        float x;
        float y;
};

}
}
