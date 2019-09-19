#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvClearStatus : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CLEAR_STATUS;
        SrvClearStatus();
        SrvClearStatus(CRoseReader reader);
        SrvClearStatus(SrvClearStatus&&) = default;
        SrvClearStatus& operator=(SrvClearStatus&&) = default;
        ~SrvClearStatus() = default;
        
        static constexpr size_t size();
        
        
        
        SrvClearStatus& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvClearStatus& set_status(const uint32_t);
        uint32_t get_status() const;
        SrvClearStatus& set_hp(const int16_t);
        int16_t get_hp() const;
        SrvClearStatus& set_mp(const int16_t);
        int16_t get_mp() const;
        
        
        static SrvClearStatus create(const uint16_t& target, const uint32_t& status, const int16_t& hp, const int16_t& mp);
        static SrvClearStatus create(const uint8_t* buffer);
        static std::unique_ptr<SrvClearStatus> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        uint32_t status;
        int16_t hp;
        int16_t mp;
};

}
}
