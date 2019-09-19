#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliChangeCharReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CHANGE_CHAR_REQ;
        CliChangeCharReq();
        CliChangeCharReq(CRoseReader reader);
        CliChangeCharReq(CliChangeCharReq&&) = default;
        CliChangeCharReq& operator=(CliChangeCharReq&&) = default;
        ~CliChangeCharReq() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliChangeCharReq create();
        static CliChangeCharReq create(const uint8_t* buffer);
        static std::unique_ptr<CliChangeCharReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
