#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvEventStatus : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_EVENT_STATUS;
        SrvEventStatus();
        SrvEventStatus(CRoseReader reader);
        SrvEventStatus(SrvEventStatus&&) = default;
        SrvEventStatus& operator=(SrvEventStatus&&) = default;
        ~SrvEventStatus() = default;
        
        static constexpr size_t size();
        
        
        
        SrvEventStatus& set_object_id(const uint16_t);
        uint16_t get_object_id() const;
        SrvEventStatus& set_status(const int16_t);
        int16_t get_status() const;
        
        
        static SrvEventStatus create(const uint16_t& object_id, const int16_t& status);
        static SrvEventStatus create(const uint8_t* buffer);
        static std::unique_ptr<SrvEventStatus> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t object_id;
        int16_t status;
};

}
}
