#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvUseItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_USE_ITEM;
        SrvUseItem();
        SrvUseItem(CRoseReader reader);
        SrvUseItem(SrvUseItem&&) = default;
        SrvUseItem& operator=(SrvUseItem&&) = default;
        ~SrvUseItem() = default;
        
        static constexpr size_t size();
        
        
        
        SrvUseItem& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvUseItem& set_item_id(const uint16_t);
        uint16_t get_item_id() const;
        SrvUseItem& set_index(const uint8_t);
        uint8_t get_index() const;
        
        
        static SrvUseItem create(const uint16_t& char_id, const uint16_t& item_id, const uint8_t& index);
        static SrvUseItem create(const uint8_t* buffer);
        static std::unique_ptr<SrvUseItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        uint16_t item_id;
        uint8_t index;
};

}
}
