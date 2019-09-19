#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvShopOpen : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SHOP_OPEN;
        SrvShopOpen();
        SrvShopOpen(CRoseReader reader);
        SrvShopOpen(SrvShopOpen&&) = default;
        SrvShopOpen& operator=(SrvShopOpen&&) = default;
        ~SrvShopOpen() = default;
        
        static constexpr size_t size();
        
        
        
        SrvShopOpen& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvShopOpen& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static SrvShopOpen create(const uint16_t& id, const std::string& name);
        static SrvShopOpen create(const uint8_t* buffer);
        static std::unique_ptr<SrvShopOpen> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        std::string name;
};

}
}
