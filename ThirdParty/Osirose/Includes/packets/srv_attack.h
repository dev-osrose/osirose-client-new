#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvAttack : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_ATTACK;
        SrvAttack();
        SrvAttack(CRoseReader reader);
        SrvAttack(SrvAttack&&) = default;
        SrvAttack& operator=(SrvAttack&&) = default;
        ~SrvAttack() = default;
        
        static constexpr size_t size();
        
        
        
        SrvAttack& set_attackerId(const uint16_t);
        uint16_t get_attackerId() const;
        SrvAttack& set_defenderId(const uint16_t);
        uint16_t get_defenderId() const;
        SrvAttack& set_distance(const uint16_t);
        uint16_t get_distance() const;
        SrvAttack& set_x(const float);
        float get_x() const;
        SrvAttack& set_y(const float);
        float get_y() const;
        SrvAttack& set_z(const uint16_t);
        uint16_t get_z() const;
        
        
        static SrvAttack create(const uint16_t& attackerId, const uint16_t& defenderId);
        static SrvAttack create(const uint8_t* buffer);
        static std::unique_ptr<SrvAttack> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t attackerId;
        uint16_t defenderId;
        uint16_t distance = 0;
        float x = 0;
        float y = 0;
        uint16_t z = 0;
};

}
}
