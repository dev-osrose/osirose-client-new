#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvFairy : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_FAIRY;
        SrvFairy();
        SrvFairy(CRoseReader reader);
        SrvFairy(SrvFairy&&) = default;
        SrvFairy& operator=(SrvFairy&&) = default;
        ~SrvFairy() = default;
        
        static constexpr size_t size();
        
        
        
        SrvFairy& set_enabled(const int8_t);
        int8_t get_enabled() const;
        SrvFairy& set_target(const uint16_t);
        uint16_t get_target() const;
        
        
        static SrvFairy create(const int8_t& enabled, const uint16_t& target);
        static SrvFairy create(const uint8_t* buffer);
        static std::unique_ptr<SrvFairy> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int8_t enabled;
        uint16_t target;
};

}
}
