#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliShoutChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SHOUT_CHAT;
        CliShoutChat();
        CliShoutChat(CRoseReader reader);
        CliShoutChat(CliShoutChat&&) = default;
        CliShoutChat& operator=(CliShoutChat&&) = default;
        ~CliShoutChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliShoutChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliShoutChat create(const std::string& message);
        static CliShoutChat create(const uint8_t* buffer);
        static std::unique_ptr<CliShoutChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
