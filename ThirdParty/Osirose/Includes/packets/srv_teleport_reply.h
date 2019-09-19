#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvTeleportReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_TELEPORT_REPLY;
        SrvTeleportReply();
        SrvTeleportReply(CRoseReader reader);
        SrvTeleportReply(SrvTeleportReply&&) = default;
        SrvTeleportReply& operator=(SrvTeleportReply&&) = default;
        ~SrvTeleportReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvTeleportReply& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvTeleportReply& set_map(const uint16_t);
        uint16_t get_map() const;
        SrvTeleportReply& set_x(const float);
        float get_x() const;
        SrvTeleportReply& set_y(const float);
        float get_y() const;
        SrvTeleportReply& set_moveMode(const uint8_t);
        uint8_t get_moveMode() const;
        SrvTeleportReply& set_rideMode(const uint8_t);
        uint8_t get_rideMode() const;
        
        
        static SrvTeleportReply create(const uint16_t& id, const uint16_t& map, const float& x, const float& y, const uint8_t& moveMode, const uint8_t& rideMode);
        static SrvTeleportReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvTeleportReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        uint16_t map;
        float x;
        float y;
        uint8_t moveMode;
        uint8_t rideMode;
};

}
}
