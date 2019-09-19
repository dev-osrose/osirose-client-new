#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliAlliedShoutChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_ALLIED_SHOUT_CHAT;
        CliAlliedShoutChat();
        CliAlliedShoutChat(CRoseReader reader);
        CliAlliedShoutChat(CliAlliedShoutChat&&) = default;
        CliAlliedShoutChat& operator=(CliAlliedShoutChat&&) = default;
        ~CliAlliedShoutChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliAlliedShoutChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliAlliedShoutChat create(const std::string& message);
        static CliAlliedShoutChat create(const uint8_t* buffer);
        static std::unique_ptr<CliAlliedShoutChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
