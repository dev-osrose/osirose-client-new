#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvShopClose : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SHOP_CLOSE;
        SrvShopClose();
        SrvShopClose(CRoseReader reader);
        SrvShopClose(SrvShopClose&&) = default;
        SrvShopClose& operator=(SrvShopClose&&) = default;
        ~SrvShopClose() = default;
        
        static constexpr size_t size();
        
        
        
        SrvShopClose& set_id(const uint16_t);
        uint16_t get_id() const;
        
        
        static SrvShopClose create(const uint16_t& id);
        static SrvShopClose create(const uint8_t* buffer);
        static std::unique_ptr<SrvShopClose> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
};

}
}
