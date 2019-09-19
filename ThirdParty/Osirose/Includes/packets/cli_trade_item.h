#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliTradeItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_TRADE_ITEM;
        CliTradeItem();
        CliTradeItem(CRoseReader reader);
        CliTradeItem(CliTradeItem&&) = default;
        CliTradeItem& operator=(CliTradeItem&&) = default;
        ~CliTradeItem() = default;
        
        static constexpr size_t size();
        
        
        
        CliTradeItem& set_slot(const uint8_t);
        uint8_t get_slot() const;
        CliTradeItem& set_index(const uint16_t);
        uint16_t get_index() const;
        CliTradeItem& set_amount(const uint32_t);
        uint32_t get_amount() const;
        
        
        static CliTradeItem create(const uint8_t& slot, const uint16_t& index, const uint32_t& amount);
        static CliTradeItem create(const uint8_t* buffer);
        static std::unique_ptr<CliTradeItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t slot;
        uint16_t index;
        uint32_t amount;
};

}
}
