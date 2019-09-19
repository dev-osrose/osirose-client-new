#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvChatroomMessage : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CHATROOM_MESSAGE;
        SrvChatroomMessage();
        SrvChatroomMessage(CRoseReader reader);
        SrvChatroomMessage(SrvChatroomMessage&&) = default;
        SrvChatroomMessage& operator=(SrvChatroomMessage&&) = default;
        ~SrvChatroomMessage() = default;
        
        static constexpr size_t size();
        
        
        
        SrvChatroomMessage& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvChatroomMessage& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvChatroomMessage create(const uint16_t& target, const std::string& message);
        static SrvChatroomMessage create(const uint8_t* buffer);
        static std::unique_ptr<SrvChatroomMessage> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        std::string message;
};

}
}
