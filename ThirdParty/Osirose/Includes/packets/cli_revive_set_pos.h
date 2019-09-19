#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliReviveSetPos : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_REVIVE_SET_POS;
        CliReviveSetPos();
        CliReviveSetPos(CRoseReader reader);
        CliReviveSetPos(CliReviveSetPos&&) = default;
        CliReviveSetPos& operator=(CliReviveSetPos&&) = default;
        ~CliReviveSetPos() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static CliReviveSetPos create();
        static CliReviveSetPos create(const uint8_t* buffer);
        static std::unique_ptr<CliReviveSetPos> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
