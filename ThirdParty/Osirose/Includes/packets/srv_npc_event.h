#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvNpcEvent : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_NPC_EVENT;
        SrvNpcEvent();
        SrvNpcEvent(CRoseReader reader);
        SrvNpcEvent(SrvNpcEvent&&) = default;
        SrvNpcEvent& operator=(SrvNpcEvent&&) = default;
        ~SrvNpcEvent() = default;
        
        static constexpr size_t size();
        
        
        
        SrvNpcEvent& set_id(const int16_t);
        int16_t get_id() const;
        
        
        static SrvNpcEvent create(const int16_t& id);
        static SrvNpcEvent create(const uint8_t* buffer);
        static std::unique_ptr<SrvNpcEvent> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int16_t id;
};

}
}
