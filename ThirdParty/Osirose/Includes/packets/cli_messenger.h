#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliMessenger : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_MESSENGER;
        CliMessenger();
        CliMessenger(CRoseReader reader);
        CliMessenger(CliMessenger&&) = default;
        CliMessenger& operator=(CliMessenger&&) = default;
        ~CliMessenger() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliMessenger create();
        static CliMessenger create(const uint8_t* buffer);
        static std::unique_ptr<CliMessenger> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
