#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliPartyReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_PARTY_REQ;
        CliPartyReq();
        CliPartyReq(CRoseReader reader);
        CliPartyReq(CliPartyReq&&) = default;
        CliPartyReq& operator=(CliPartyReq&&) = default;
        ~CliPartyReq() = default;
        
        static constexpr size_t size();
        
        
        enum PartyReqType : uint8_t {
            CREATE = 0,
            JOIN = 1,
            LEAVE = 2,
            CHANGE_OWNER = 3,
            BAN = 129,
        };
        
        
        CliPartyReq& set_type(const PartyReqType);
        PartyReqType get_type() const;
        CliPartyReq& set_target(const uint16_t);
        uint16_t get_target() const;
        
        
        static CliPartyReq create(const PartyReqType& type, const uint16_t& target);
        static CliPartyReq create(const uint8_t* buffer);
        static std::unique_ptr<CliPartyReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyReqType type;
        uint16_t target;
};

}
}
