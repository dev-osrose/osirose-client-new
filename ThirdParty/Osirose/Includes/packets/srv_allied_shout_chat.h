#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvAlliedShoutChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_ALLIED_SHOUT_CHAT;
        SrvAlliedShoutChat();
        SrvAlliedShoutChat(CRoseReader reader);
        SrvAlliedShoutChat(SrvAlliedShoutChat&&) = default;
        SrvAlliedShoutChat& operator=(SrvAlliedShoutChat&&) = default;
        ~SrvAlliedShoutChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvAlliedShoutChat& set_team(const uint32_t);
        uint32_t get_team() const;
        SrvAlliedShoutChat& set_sender(const std::string&);
        const std::string& get_sender() const;
        SrvAlliedShoutChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvAlliedShoutChat create(const uint32_t& team, const std::string& sender, const std::string& message);
        static SrvAlliedShoutChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvAlliedShoutChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint32_t team;
        std::string sender;
        std::string message;
};

}
}
