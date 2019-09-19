#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetPosition : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_POSITION;
        SrvSetPosition();
        SrvSetPosition(CRoseReader reader);
        SrvSetPosition(SrvSetPosition&&) = default;
        SrvSetPosition& operator=(SrvSetPosition&&) = default;
        ~SrvSetPosition() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetPosition& set_charId(const uint16_t);
        uint16_t get_charId() const;
        SrvSetPosition& set_x(const float);
        float get_x() const;
        SrvSetPosition& set_y(const float);
        float get_y() const;
        SrvSetPosition& set_z(const int16_t);
        int16_t get_z() const;
        
        
        static SrvSetPosition create(const uint16_t& charId, const float& x, const float& y, const int16_t& z);
        static SrvSetPosition create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetPosition> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t charId;
        float x;
        float y;
        int16_t z;
};

}
}
