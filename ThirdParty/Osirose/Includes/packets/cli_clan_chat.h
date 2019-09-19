#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliClanChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CLAN_CHAT;
        CliClanChat();
        CliClanChat(CRoseReader reader);
        CliClanChat(CliClanChat&&) = default;
        CliClanChat& operator=(CliClanChat&&) = default;
        ~CliClanChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliClanChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliClanChat create(const std::string& message);
        static CliClanChat create(const uint8_t* buffer);
        static std::unique_ptr<CliClanChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
