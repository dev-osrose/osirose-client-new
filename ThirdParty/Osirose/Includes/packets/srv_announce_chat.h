#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvAnnounceChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKSW_ANNOUNCE_CHAT;
        SrvAnnounceChat();
        SrvAnnounceChat(CRoseReader reader);
        SrvAnnounceChat(SrvAnnounceChat&&) = default;
        SrvAnnounceChat& operator=(SrvAnnounceChat&&) = default;
        ~SrvAnnounceChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvAnnounceChat& set_message(const std::string&);
        const std::string& get_message() const;
        SrvAnnounceChat& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static SrvAnnounceChat create(const std::string& message, const std::string& name);
        static SrvAnnounceChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvAnnounceChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
        std::string name;
};

}
}
