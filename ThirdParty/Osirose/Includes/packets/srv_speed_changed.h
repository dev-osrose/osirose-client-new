#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSpeedChanged : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SPEED_CHANGED;
        SrvSpeedChanged();
        SrvSpeedChanged(CRoseReader reader);
        SrvSpeedChanged(SrvSpeedChanged&&) = default;
        SrvSpeedChanged& operator=(SrvSpeedChanged&&) = default;
        ~SrvSpeedChanged() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSpeedChanged& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSpeedChanged& set_move_speed(const int16_t);
        int16_t get_move_speed() const;
        SrvSpeedChanged& set_attack_speed(const int16_t);
        int16_t get_attack_speed() const;
        SrvSpeedChanged& set_weight(const uint8_t);
        uint8_t get_weight() const;
        
        
        static SrvSpeedChanged create(const uint16_t& target, const int16_t& move_speed, const int16_t& attack_speed, const uint8_t& weight);
        static SrvSpeedChanged create(const uint8_t* buffer);
        static std::unique_ptr<SrvSpeedChanged> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        int16_t move_speed;
        int16_t attack_speed;
        uint8_t weight;
};

}
}
