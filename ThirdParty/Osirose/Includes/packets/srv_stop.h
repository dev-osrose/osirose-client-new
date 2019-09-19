#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvStop : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_STOP;
        SrvStop();
        SrvStop(CRoseReader reader);
        SrvStop(SrvStop&&) = default;
        SrvStop& operator=(SrvStop&&) = default;
        ~SrvStop() = default;
        
        static constexpr size_t size();
        
        
        
        SrvStop& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvStop& set_x(const float);
        float get_x() const;
        SrvStop& set_y(const float);
        float get_y() const;
        SrvStop& set_z(const int16_t);
        int16_t get_z() const;
        
        
        static SrvStop create(const uint16_t& char_id, const float& x, const float& y, const int16_t& z);
        static SrvStop create(const uint8_t* buffer);
        static std::unique_ptr<SrvStop> allocate(const uint8_t* buffer);
    
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
