#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliPickupItemReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_PICKUP_ITEM_REQ;
        CliPickupItemReq();
        CliPickupItemReq(CRoseReader reader);
        CliPickupItemReq(CliPickupItemReq&&) = default;
        CliPickupItemReq& operator=(CliPickupItemReq&&) = default;
        ~CliPickupItemReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliPickupItemReq& set_item_id(const uint16_t);
        uint16_t get_item_id() const;
        
        
        static CliPickupItemReq create(const uint16_t& item_id);
        static CliPickupItemReq create(const uint8_t* buffer);
        static std::unique_ptr<CliPickupItemReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t item_id;
};

}
}
