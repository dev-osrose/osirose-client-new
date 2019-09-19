#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliTeleportReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_TELEPORT_REQ;
        CliTeleportReq();
        CliTeleportReq(CRoseReader reader);
        CliTeleportReq(CliTeleportReq&&) = default;
        CliTeleportReq& operator=(CliTeleportReq&&) = default;
        ~CliTeleportReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliTeleportReq& set_id(const int16_t);
        int16_t get_id() const;
        CliTeleportReq& set_x(const float);
        float get_x() const;
        CliTeleportReq& set_y(const float);
        float get_y() const;
        
        
        static CliTeleportReq create(const int16_t& id, const float& x, const float& y);
        static CliTeleportReq create(const uint8_t* buffer);
        static std::unique_ptr<CliTeleportReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int16_t id;
        float x;
        float y;
};

}
}
