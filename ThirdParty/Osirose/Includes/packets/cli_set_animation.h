#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSetAnimation : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SET_ANIMATION;
        CliSetAnimation();
        CliSetAnimation(CRoseReader reader);
        CliSetAnimation(CliSetAnimation&&) = default;
        CliSetAnimation& operator=(CliSetAnimation&&) = default;
        ~CliSetAnimation() = default;
        
        static constexpr size_t size();
        
        
        
        CliSetAnimation& set_id(const uint16_t);
        uint16_t get_id() const;
        CliSetAnimation& set_value(const uint16_t);
        uint16_t get_value() const;
        
        
        static CliSetAnimation create(const uint16_t& id, const uint16_t& value);
        static CliSetAnimation create(const uint8_t* buffer);
        static std::unique_ptr<CliSetAnimation> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        uint16_t value;
};

}
}
