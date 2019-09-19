#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliPartyReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_PARTY_REPLY;
        CliPartyReply();
        CliPartyReply(CRoseReader reader);
        CliPartyReply(CliPartyReply&&) = default;
        CliPartyReply& operator=(CliPartyReply&&) = default;
        ~CliPartyReply() = default;
        
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
        
        
        CliPartyReply& set_type(const PartyReplyType);
        PartyReplyType get_type() const;
        CliPartyReply& set_target(const uint16_t);
        uint16_t get_target() const;
        
        
        static CliPartyReply create(const PartyReplyType& type, const uint16_t& target);
        static CliPartyReply create(const uint8_t* buffer);
        static std::unique_ptr<CliPartyReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyReplyType type;
        uint16_t target;
};

}
}
