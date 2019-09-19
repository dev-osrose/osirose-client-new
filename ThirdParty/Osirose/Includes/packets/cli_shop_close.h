#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliShopClose : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SHOP_CLOSE;
        CliShopClose();
        CliShopClose(CRoseReader reader);
        CliShopClose(CliShopClose&&) = default;
        CliShopClose& operator=(CliShopClose&&) = default;
        ~CliShopClose() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliShopClose create();
        static CliShopClose create(const uint8_t* buffer);
        static std::unique_ptr<CliShopClose> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
