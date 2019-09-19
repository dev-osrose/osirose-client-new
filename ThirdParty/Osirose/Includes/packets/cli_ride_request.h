#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliRideRequest : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_RIDE_REQUEST;
        CliRideRequest();
        CliRideRequest(CRoseReader reader);
        CliRideRequest(CliRideRequest&&) = default;
        CliRideRequest& operator=(CliRideRequest&&) = default;
        ~CliRideRequest() = default;
        
        static constexpr size_t size();
        
        
        enum RideAction : uint8_t {
            REQUEST = 0,
            ACCEPT = 1,
            REFUSE = 2,
            OWNER_NOT_FOUND = 3,
            GUEST_NOT_FOUND = 4,
        };
        
        
        CliRideRequest& set_action(const RideAction);
        RideAction get_action() const;
        CliRideRequest& set_owner(const uint16_t);
        uint16_t get_owner() const;
        CliRideRequest& set_guest(const uint32_t);
        uint32_t get_guest() const;
        
        
        static CliRideRequest create(const RideAction& action, const uint16_t& owner, const uint32_t& guest);
        static CliRideRequest create(const uint8_t* buffer);
        static std::unique_ptr<CliRideRequest> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        RideAction action;
        uint16_t owner;
        uint32_t guest;
};

}
}
