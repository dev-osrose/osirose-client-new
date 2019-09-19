#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvEventAdd : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_EVENT_ADD;
        SrvEventAdd();
        SrvEventAdd(CRoseReader reader);
        SrvEventAdd(SrvEventAdd&&) = default;
        SrvEventAdd& operator=(SrvEventAdd&&) = default;
        ~SrvEventAdd() = default;
        
        static constexpr size_t size();
        
        
        
        SrvEventAdd& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvEventAdd& set_x(const int8_t);
        int8_t get_x() const;
        SrvEventAdd& set_y(const int8_t);
        int8_t get_y() const;
        SrvEventAdd& set_event_id(const uint16_t);
        uint16_t get_event_id() const;
        SrvEventAdd& set_status(const int16_t);
        int16_t get_status() const;
        
        
        static SrvEventAdd create(const uint16_t& id, const int8_t& x, const int8_t& y, const uint16_t& event_id, const int16_t& status);
        static SrvEventAdd create(const uint8_t* buffer);
        static std::unique_ptr<SrvEventAdd> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        int8_t x;
        int8_t y;
        uint16_t event_id;
        int16_t status;
};

}
}
