#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliPartyRule : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_PARTY_RULE;
        CliPartyRule();
        CliPartyRule(CRoseReader reader);
        CliPartyRule(CliPartyRule&&) = default;
        CliPartyRule& operator=(CliPartyRule&&) = default;
        ~CliPartyRule() = default;
        
        static constexpr size_t size();
        
        
        enum PartyRule : uint8_t {
            EXP_PER_PLAYER = 0,
            ITEM_IN_ORDER = 1,
        };
        
        
        CliPartyRule& set_rule(const PartyRule);
        PartyRule get_rule() const;
        
        
        static CliPartyRule create(const PartyRule& rule);
        static CliPartyRule create(const uint8_t* buffer);
        static std::unique_ptr<CliPartyRule> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyRule rule;
};

}
}
