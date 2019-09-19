#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvTrade : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_TRADE;
        SrvTrade();
        SrvTrade(CRoseReader reader);
        SrvTrade(SrvTrade&&) = default;
        SrvTrade& operator=(SrvTrade&&) = default;
        ~SrvTrade() = default;
        
        static constexpr size_t size();
        
        
        enum TradeState : uint8_t {
            REQUEST = 0,
            ACCEPT = 1,
            REJECT = 2,
            CANCEL = 3,
            READY = 4,
            NOTREADY = 5,
            DONE = 6,
            BUSY = 7,
            TOO_FAR = 8,
            INVALID_TARGET = 9,
            NO_SPACE = 10,
            TRADE_DISABLED = 11,
        };
        
        
        SrvTrade& set_state(const TradeState);
        TradeState get_state() const;
        SrvTrade& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvTrade& set_index(const uint8_t);
        uint8_t get_index() const;
        
        
        static SrvTrade create(const TradeState& state, const uint16_t& target);
        static SrvTrade create(const uint8_t* buffer);
        static std::unique_ptr<SrvTrade> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        TradeState state;
        uint16_t target;
        uint8_t index = 0;
};

}
}
