#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvStoreTradeReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_STORE_TRADE_REPLY;
        SrvStoreTradeReply();
        SrvStoreTradeReply(CRoseReader reader);
        SrvStoreTradeReply(SrvStoreTradeReply&&) = default;
        SrvStoreTradeReply& operator=(SrvStoreTradeReply&&) = default;
        ~SrvStoreTradeReply() = default;
        
        static constexpr size_t size();
        
        
        enum StoreTradeResult : uint8_t {
            PRICE_DIFF = 1,
            INVALID_NPC = 2,
            TOO_FAR = 3,
            NO_MONEY = 4,
            INVALID_UNION = 5,
            NO_POINTS = 6,
        };
        
        
        SrvStoreTradeReply& set_result(const StoreTradeResult);
        StoreTradeResult get_result() const;
        
        
        static SrvStoreTradeReply create(const StoreTradeResult& result);
        static SrvStoreTradeReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvStoreTradeReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        StoreTradeResult result;
};

}
}
