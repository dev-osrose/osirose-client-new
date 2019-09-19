#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliChatroomMessage : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CHATROOM_MESSAGE;
        CliChatroomMessage();
        CliChatroomMessage(CRoseReader reader);
        CliChatroomMessage(CliChatroomMessage&&) = default;
        CliChatroomMessage& operator=(CliChatroomMessage&&) = default;
        ~CliChatroomMessage() = default;
        
        static constexpr size_t size();
        
        
        
        CliChatroomMessage& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliChatroomMessage create(const std::string& message);
        static CliChatroomMessage create(const uint8_t* buffer);
        static std::unique_ptr<CliChatroomMessage> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
