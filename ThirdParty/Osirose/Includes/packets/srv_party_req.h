#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvPartyReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_REQ;
        SrvPartyReq();
        SrvPartyReq(CRoseReader reader);
        SrvPartyReq(SrvPartyReq&&) = default;
        SrvPartyReq& operator=(SrvPartyReq&&) = default;
        ~SrvPartyReq() = default;
        
        static constexpr size_t size();
        
        
        enum PartyReqType : uint8_t {
            CREATE = 0,
            JOIN = 1,
            LEAVE = 2,
            CHANGE_OWNER = 3,
            BAN = 129,
        };
        
        
        SrvPartyReq& set_type(const PartyReqType);
        PartyReqType get_type() const;
        SrvPartyReq& set_source(const uint16_t);
        uint16_t get_source() const;
        
        
        static SrvPartyReq create(const PartyReqType& type, const uint16_t& source);
        static SrvPartyReq create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyReqType type;
        uint16_t source;
};

}
}
