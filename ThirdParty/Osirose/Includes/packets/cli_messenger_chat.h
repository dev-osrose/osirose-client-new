#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliMessengerChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_MESSENGER_CHAT;
        CliMessengerChat();
        CliMessengerChat(CRoseReader reader);
        CliMessengerChat(CliMessengerChat&&) = default;
        CliMessengerChat& operator=(CliMessengerChat&&) = default;
        ~CliMessengerChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliMessengerChat& set_tag(const uint16_t);
        uint16_t get_tag() const;
        CliMessengerChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliMessengerChat create(const uint16_t& tag, const std::string& message);
        static CliMessengerChat create(const uint8_t* buffer);
        static std::unique_ptr<CliMessengerChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t tag;
        std::string message;
};

}
}
