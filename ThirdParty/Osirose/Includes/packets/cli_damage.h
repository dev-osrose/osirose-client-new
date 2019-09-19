#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliDamage : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_DAMAGE;
        CliDamage();
        CliDamage(CRoseReader reader);
        CliDamage(CliDamage&&) = default;
        CliDamage& operator=(CliDamage&&) = default;
        ~CliDamage() = default;
        
        static constexpr size_t size();
        
        
        
        CliDamage& set_targetId(const uint16_t);
        uint16_t get_targetId() const;
        CliDamage& set__randomId(const uint16_t);
        uint16_t get__randomId() const;
        
        
        static CliDamage create();
        static CliDamage create(const uint8_t* buffer);
        static std::unique_ptr<CliDamage> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t targetId = 0;
        uint16_t _randomId = 0;
};

}
}
