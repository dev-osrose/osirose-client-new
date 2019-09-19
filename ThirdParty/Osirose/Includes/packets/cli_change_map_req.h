#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliChangeMapReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CHANGE_MAP_REQ;
        CliChangeMapReq();
        CliChangeMapReq(CRoseReader reader);
        CliChangeMapReq(CliChangeMapReq&&) = default;
        CliChangeMapReq& operator=(CliChangeMapReq&&) = default;
        ~CliChangeMapReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliChangeMapReq& set_weightRate(const uint8_t);
        uint8_t get_weightRate() const;
        CliChangeMapReq& set_z(const uint16_t);
        uint16_t get_z() const;
        
        
        static CliChangeMapReq create(const uint8_t& weightRate, const uint16_t& z);
        static CliChangeMapReq create(const uint8_t* buffer);
        static std::unique_ptr<CliChangeMapReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t weightRate;
        uint16_t z;
};

}
}
