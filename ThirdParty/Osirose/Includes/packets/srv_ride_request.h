#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvRideRequest : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_RIDE_REQUEST;
        SrvRideRequest();
        SrvRideRequest(CRoseReader reader);
        SrvRideRequest(SrvRideRequest&&) = default;
        SrvRideRequest& operator=(SrvRideRequest&&) = default;
        ~SrvRideRequest() = default;
        
        static constexpr size_t size();
        
        
        enum RideAction : uint8_t {
            REQUEST = 0,
            ACCEPT = 1,
            REFUSE = 2,
            OWNER_NOT_FOUND = 3,
            GUEST_NOT_FOUND = 4,
        };
        
        
        SrvRideRequest& set_action(const RideAction);
        RideAction get_action() const;
        SrvRideRequest& set_owner(const uint16_t);
        uint16_t get_owner() const;
        SrvRideRequest& set_guest(const uint32_t);
        uint32_t get_guest() const;
        
        
        static SrvRideRequest create(const RideAction& action, const uint16_t& owner, const uint32_t& guest);
        static SrvRideRequest create(const uint8_t* buffer);
        static std::unique_ptr<SrvRideRequest> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        RideAction action;
        uint16_t owner;
        uint32_t guest;
};

}
}
