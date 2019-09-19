#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvPartyRule : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_RULE;
        SrvPartyRule();
        SrvPartyRule(CRoseReader reader);
        SrvPartyRule(SrvPartyRule&&) = default;
        SrvPartyRule& operator=(SrvPartyRule&&) = default;
        ~SrvPartyRule() = default;
        
        static constexpr size_t size();
        
        
        enum PartyRule : uint8_t {
            EXP_PER_PLAYER = 0,
            ITEM_IN_ORDER = 1,
        };
        
        
        SrvPartyRule& set_rule(const PartyRule);
        PartyRule get_rule() const;
        
        
        static SrvPartyRule create(const PartyRule& rule);
        static SrvPartyRule create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyRule> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyRule rule;
};

}
}
