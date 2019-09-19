#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliAttack : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_ATTACK;
        CliAttack();
        CliAttack(CRoseReader reader);
        CliAttack(CliAttack&&) = default;
        CliAttack& operator=(CliAttack&&) = default;
        ~CliAttack() = default;
        
        static constexpr size_t size();
        
        
        
        CliAttack& set_targetId(const uint16_t);
        uint16_t get_targetId() const;
        
        
        static CliAttack create(const uint16_t& targetId);
        static CliAttack create(const uint8_t* buffer);
        static std::unique_ptr<CliAttack> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t targetId;
};

}
}
