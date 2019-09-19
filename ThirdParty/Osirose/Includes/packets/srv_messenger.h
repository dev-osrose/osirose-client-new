#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvMessenger : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_MESSENGER;
        SrvMessenger();
        SrvMessenger(CRoseReader reader);
        SrvMessenger(SrvMessenger&&) = default;
        SrvMessenger& operator=(SrvMessenger&&) = default;
        ~SrvMessenger() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static SrvMessenger create();
        static SrvMessenger create(const uint8_t* buffer);
        static std::unique_ptr<SrvMessenger> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
