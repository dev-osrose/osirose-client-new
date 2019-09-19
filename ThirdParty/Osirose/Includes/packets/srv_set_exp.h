#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetExp : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_EXP;
        SrvSetExp();
        SrvSetExp(CRoseReader reader);
        SrvSetExp(SrvSetExp&&) = default;
        SrvSetExp& operator=(SrvSetExp&&) = default;
        ~SrvSetExp() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetExp& set_exp(const int64_t);
        int64_t get_exp() const;
        SrvSetExp& set_stamina(const int16_t);
        int16_t get_stamina() const;
        SrvSetExp& set_source_id(const uint16_t);
        uint16_t get_source_id() const;
        
        
        static SrvSetExp create(const int64_t& exp, const int16_t& stamina);
        static SrvSetExp create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetExp> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int64_t exp;
        int16_t stamina;
        uint16_t source_id = 0;
};

}
}
