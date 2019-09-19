#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvClanChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CLAN_CHAT;
        SrvClanChat();
        SrvClanChat(CRoseReader reader);
        SrvClanChat(SrvClanChat&&) = default;
        SrvClanChat& operator=(SrvClanChat&&) = default;
        ~SrvClanChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvClanChat& set_sender(const std::string&);
        const std::string& get_sender() const;
        SrvClanChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvClanChat create(const std::string& sender, const std::string& message);
        static SrvClanChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvClanChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string sender;
        std::string message;
};

}
}
