#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliAlliedChat : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_ALLIED_CHAT;
        CliAlliedChat();
        CliAlliedChat(CRoseReader reader);
        CliAlliedChat(CliAlliedChat&&) = default;
        CliAlliedChat& operator=(CliAlliedChat&&) = default;
        ~CliAlliedChat() = default;
        
        static constexpr size_t size();
        
        
        
        CliAlliedChat& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliAlliedChat create(const std::string& message);
        static CliAlliedChat create(const uint8_t* buffer);
        static std::unique_ptr<CliAlliedChat> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::string message;
};

}
}
