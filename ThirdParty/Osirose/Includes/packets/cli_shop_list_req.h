#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliShopListReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SHOP_LIST_REQ;
        CliShopListReq();
        CliShopListReq(CRoseReader reader);
        CliShopListReq(CliShopListReq&&) = default;
        CliShopListReq& operator=(CliShopListReq&&) = default;
        ~CliShopListReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliShopListReq& set_id(const uint16_t);
        uint16_t get_id() const;
        
        
        static CliShopListReq create(const uint16_t& id);
        static CliShopListReq create(const uint8_t* buffer);
        static std::unique_ptr<CliShopListReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
};

}
}
