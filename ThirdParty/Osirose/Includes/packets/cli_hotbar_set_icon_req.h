#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliHotbarSetIconReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_HOTBAR_SET_ICON_REQ;
        CliHotbarSetIconReq();
        CliHotbarSetIconReq(CRoseReader reader);
        CliHotbarSetIconReq(CliHotbarSetIconReq&&) = default;
        CliHotbarSetIconReq& operator=(CliHotbarSetIconReq&&) = default;
        ~CliHotbarSetIconReq() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliHotbarSetIconReq create();
        static CliHotbarSetIconReq create(const uint8_t* buffer);
        static std::unique_ptr<CliHotbarSetIconReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
