#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliUseItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_USE_ITEM;
        CliUseItem();
        CliUseItem(CRoseReader reader);
        CliUseItem(CliUseItem&&) = default;
        CliUseItem& operator=(CliUseItem&&) = default;
        ~CliUseItem() = default;
        
        static constexpr size_t size();
        
        
        
        CliUseItem& set_index(const uint16_t);
        uint16_t get_index() const;
        CliUseItem& set_item_id(const uint16_t);
        uint16_t get_item_id() const;
        
        
        static CliUseItem create(const uint16_t& index, const uint16_t& item_id);
        static CliUseItem create(const uint8_t* buffer);
        static std::unique_ptr<CliUseItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t index;
        uint16_t item_id;
};

}
}
