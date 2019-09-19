#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvPartyChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_CHAT;
        SrvPartyChat();
        SrvPartyChat(CRoseReader reader);
        SrvPartyChat(SrvPartyChat&&) = default;
        SrvPartyChat& operator=(SrvPartyChat&&) = default;
        ~SrvPartyChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvPartyChat& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvPartyChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvPartyChat create(const uint16_t& char_id, const std::string& message);
        static SrvPartyChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        std::string message;
};

}
}
