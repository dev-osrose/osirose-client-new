#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvCharStateChange : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAWKC_CHAR_STATE_CHANGE;
        SrvCharStateChange();
        SrvCharStateChange(CRoseReader reader);
        SrvCharStateChange(SrvCharStateChange&&) = default;
        SrvCharStateChange& operator=(SrvCharStateChange&&) = default;
        ~SrvCharStateChange() = default;
        
        static constexpr size_t size();
        
        
        
        SrvCharStateChange& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvCharStateChange& set_flag(const uint32_t);
        uint32_t get_flag() const;
        
        
        static SrvCharStateChange create(const uint16_t& target, const uint32_t& flag);
        static SrvCharStateChange create(const uint8_t* buffer);
        static std::unique_ptr<SrvCharStateChange> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        uint32_t flag;
};

}
}
