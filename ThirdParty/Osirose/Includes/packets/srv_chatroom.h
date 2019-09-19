#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvChatroom : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CHATROOM;
        SrvChatroom();
        SrvChatroom(CRoseReader reader);
        SrvChatroom(SrvChatroom&&) = default;
        SrvChatroom& operator=(SrvChatroom&&) = default;
        ~SrvChatroom() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static SrvChatroom create();
        static SrvChatroom create(const uint8_t* buffer);
        static std::unique_ptr<SrvChatroom> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
