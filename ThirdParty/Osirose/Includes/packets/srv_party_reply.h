#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvPartyReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_REPLY;
        SrvPartyReply();
        SrvPartyReply(CRoseReader reader);
        SrvPartyReply(SrvPartyReply&&) = default;
        SrvPartyReply& operator=(SrvPartyReply&&) = default;
        ~SrvPartyReply() = default;
        
        static constexpr size_t size();
        
        
        enum PartyReplyType : uint8_t {
            NOT_FOUND = 0,
            BUSY = 1,
            ACCEPT_CREATE = 2,
            ACCEPT_JOIN = 3,
            REJECT_JOIN = 4,
            DESTROY = 5,
            FULL = 6,
            INVALID_LEVEL = 7,
            CHANGE_OWNER = 8,
            CHANGE_OWNER_AND_LEAVE = 9,
            NO_PREMIUM = 10,
            BAD = 128,
            LEAVE = 129,
            REJOIN = 130,
        };
        
        
        SrvPartyReply& set_type(const PartyReplyType);
        PartyReplyType get_type() const;
        SrvPartyReply& set_source(const uint16_t);
        uint16_t get_source() const;
        
        
        static SrvPartyReply create(const PartyReplyType& type, const uint16_t& source);
        static SrvPartyReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyReplyType type;
        uint16_t source;
};

}
}
