#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvClanCommand : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CLAN_COMMAND;
        SrvClanCommand();
        SrvClanCommand(CRoseReader reader);
        SrvClanCommand(SrvClanCommand&&) = default;
        SrvClanCommand& operator=(SrvClanCommand&&) = default;
        ~SrvClanCommand() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static SrvClanCommand create();
        static SrvClanCommand create(const uint8_t* buffer);
        static std::unique_ptr<SrvClanCommand> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
