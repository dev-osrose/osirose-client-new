#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliChatroom : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CHATROOM;
        CliChatroom();
        CliChatroom(CRoseReader reader);
        CliChatroom(CliChatroom&&) = default;
        CliChatroom& operator=(CliChatroom&&) = default;
        ~CliChatroom() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliChatroom create();
        static CliChatroom create(const uint8_t* buffer);
        static std::unique_ptr<CliChatroom> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
