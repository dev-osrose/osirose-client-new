#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliCraftEnhanceReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CRAFT_ENHANCE_REQ;
        CliCraftEnhanceReq();
        CliCraftEnhanceReq(CRoseReader reader);
        CliCraftEnhanceReq(CliCraftEnhanceReq&&) = default;
        CliCraftEnhanceReq& operator=(CliCraftEnhanceReq&&) = default;
        ~CliCraftEnhanceReq() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliCraftEnhanceReq create();
        static CliCraftEnhanceReq create(const uint8_t* buffer);
        static std::unique_ptr<CliCraftEnhanceReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
