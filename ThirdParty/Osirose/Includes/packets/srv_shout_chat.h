#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvShoutChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SHOUT_CHAT;
        SrvShoutChat();
        SrvShoutChat(CRoseReader reader);
        SrvShoutChat(SrvShoutChat&&) = default;
        SrvShoutChat& operator=(SrvShoutChat&&) = default;
        ~SrvShoutChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvShoutChat& set_sender(const std::string&);
        const std::string& get_sender() const;
        SrvShoutChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvShoutChat create(const std::string& sender, const std::string& message);
        static SrvShoutChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvShoutChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string sender;
        std::string message;
};

}
}
