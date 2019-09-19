#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliNormalChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_NORMAL_CHAT;
        CliNormalChat();
        CliNormalChat(CRoseReader reader);
        CliNormalChat(CliNormalChat&&) = default;
        CliNormalChat& operator=(CliNormalChat&&) = default;
        ~CliNormalChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliNormalChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliNormalChat create(const std::string& message);
        static CliNormalChat create(const uint8_t* buffer);
        static std::unique_ptr<CliNormalChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
