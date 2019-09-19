#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliPartyChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_PARTY_CHAT;
        CliPartyChat();
        CliPartyChat(CRoseReader reader);
        CliPartyChat(CliPartyChat&&) = default;
        CliPartyChat& operator=(CliPartyChat&&) = default;
        ~CliPartyChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliPartyChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliPartyChat create(const std::string& message);
        static CliPartyChat create(const uint8_t* buffer);
        static std::unique_ptr<CliPartyChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
