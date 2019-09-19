#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliDropItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_DROP_ITEM;
        CliDropItem();
        CliDropItem(CRoseReader reader);
        CliDropItem(CliDropItem&&) = default;
        CliDropItem& operator=(CliDropItem&&) = default;
        ~CliDropItem() = default;
        
        static constexpr size_t size();
        
        
        
        CliDropItem& set_index(const uint8_t);
        uint8_t get_index() const;
        CliDropItem& set_quantity(const uint32_t);
        uint32_t get_quantity() const;
        
        
        static CliDropItem create(const uint8_t& index, const uint32_t& quantity);
        static CliDropItem create(const uint8_t* buffer);
        static std::unique_ptr<CliDropItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t index;
        uint32_t quantity;
};

}
}
