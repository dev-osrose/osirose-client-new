#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliLogoutReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_LOGOUT_REQ;
        CliLogoutReq();
        CliLogoutReq(CRoseReader reader);
        CliLogoutReq(CliLogoutReq&&) = default;
        CliLogoutReq& operator=(CliLogoutReq&&) = default;
        ~CliLogoutReq() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliLogoutReq create();
        static CliLogoutReq create(const uint8_t* buffer);
        static std::unique_ptr<CliLogoutReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
