#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvAlliedChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_ALLIED_CHAT;
        SrvAlliedChat();
        SrvAlliedChat(CRoseReader reader);
        SrvAlliedChat(SrvAlliedChat&&) = default;
        SrvAlliedChat& operator=(SrvAlliedChat&&) = default;
        ~SrvAlliedChat() = default;
        
        static constexpr size_t size();
        
        
        
        SrvAlliedChat& set_team(const uint32_t);
        uint32_t get_team() const;
        SrvAlliedChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static SrvAlliedChat create(const std::string& message);
        static SrvAlliedChat create(const uint8_t* buffer);
        static std::unique_ptr<SrvAlliedChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint32_t team = 0;
        std::string message;
};

}
}
