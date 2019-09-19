#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliClanCommand : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CLAN_COMMAND;
        CliClanCommand();
        CliClanCommand(CRoseReader reader);
        CliClanCommand(CliClanCommand&&) = default;
        CliClanCommand& operator=(CliClanCommand&&) = default;
        ~CliClanCommand() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliClanCommand create();
        static CliClanCommand create(const uint8_t* buffer);
        static std::unique_ptr<CliClanCommand> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
