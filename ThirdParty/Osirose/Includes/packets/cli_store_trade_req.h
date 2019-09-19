#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliStoreTradeReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_STORE_TRADE_REQ;
        CliStoreTradeReq();
        CliStoreTradeReq(CRoseReader reader);
        CliStoreTradeReq(CliStoreTradeReq&&) = default;
        CliStoreTradeReq& operator=(CliStoreTradeReq&&) = default;
        ~CliStoreTradeReq() = default;
        
        static constexpr size_t size();
        
        
        struct BuySellItem : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            BuySellItem& set_buy_tab_id(const uint8_t);
            uint8_t get_buy_tab_id() const;
            BuySellItem& set_buy_col_id(const uint8_t);
            uint8_t get_buy_col_id() const;
            BuySellItem& set_buy_amount(const uint16_t);
            uint16_t get_buy_amount() const;
            BuySellItem& set_sell_inventory_idx(const uint8_t);
            uint8_t get_sell_inventory_idx() const;
            BuySellItem& set_sell_amount(const uint16_t);
            uint16_t get_sell_amount() const;
            BuySellItem& set_data(const uint32_t);
            uint32_t get_data() const;
            
            private:
                union {
                    PACK(struct {
                        uint8_t buy_tab_id;
                        uint8_t buy_col_id;
                        uint16_t buy_amount;
                    });
                    PACK(struct {
                        uint8_t sell_inventory_idx;
                        uint16_t sell_amount;
                    });
                    uint32_t data;
                } data;
        };
        
        
        CliStoreTradeReq& set_npc_id(const uint16_t);
        uint16_t get_npc_id() const;
        CliStoreTradeReq& set_is_buy(const uint8_t);
        uint8_t get_is_buy() const;
        CliStoreTradeReq& set_is_sell(const uint8_t);
        uint8_t get_is_sell() const;
        CliStoreTradeReq& set_time(const uint32_t);
        uint32_t get_time() const;
        CliStoreTradeReq& set_item(const BuySellItem);
        BuySellItem get_item() const;
        
        
        static CliStoreTradeReq create(const uint16_t& npc_id, const uint8_t& is_buy, const uint8_t& is_sell, const uint32_t& time, const BuySellItem& item);
        static CliStoreTradeReq create(const uint8_t* buffer);
        static std::unique_ptr<CliStoreTradeReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t npc_id;
        uint8_t is_buy;
        uint8_t is_sell;
        uint32_t time;
        BuySellItem item;
};

}
}
