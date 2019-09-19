#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliScreenShotTimeReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SCREEN_SHOT_TIME_REQ;
        CliScreenShotTimeReq();
        CliScreenShotTimeReq(CRoseReader reader);
        CliScreenShotTimeReq(CliScreenShotTimeReq&&) = default;
        CliScreenShotTimeReq& operator=(CliScreenShotTimeReq&&) = default;
        ~CliScreenShotTimeReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliScreenShotTimeReq& set_count(const uint16_t);
        uint16_t get_count() const;
        
        
        static CliScreenShotTimeReq create();
        static CliScreenShotTimeReq create(const uint8_t* buffer);
        static std::unique_ptr<CliScreenShotTimeReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t count = 1;
};

}
}
