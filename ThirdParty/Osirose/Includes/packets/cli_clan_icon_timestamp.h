#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliClanIconTimestamp : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CLAN_ICON_TIMESTAMP;
        CliClanIconTimestamp();
        CliClanIconTimestamp(CRoseReader reader);
        CliClanIconTimestamp(CliClanIconTimestamp&&) = default;
        CliClanIconTimestamp& operator=(CliClanIconTimestamp&&) = default;
        ~CliClanIconTimestamp() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliClanIconTimestamp create();
        static CliClanIconTimestamp create(const uint8_t* buffer);
        static std::unique_ptr<CliClanIconTimestamp> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
