#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliCharListReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CHAR_LIST_REQ;
        CliCharListReq();
        CliCharListReq(CRoseReader reader);
        CliCharListReq(CliCharListReq&&) = default;
        CliCharListReq& operator=(CliCharListReq&&) = default;
        ~CliCharListReq() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliCharListReq create();
        static CliCharListReq create(const uint8_t* buffer);
        static std::unique_ptr<CliCharListReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
