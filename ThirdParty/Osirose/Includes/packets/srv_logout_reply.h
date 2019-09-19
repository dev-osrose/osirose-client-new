#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvLogoutReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_LOGOUT_REPLY;
        SrvLogoutReply();
        SrvLogoutReply(CRoseReader reader);
        SrvLogoutReply(SrvLogoutReply&&) = default;
        SrvLogoutReply& operator=(SrvLogoutReply&&) = default;
        ~SrvLogoutReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvLogoutReply& set_waitTime(const uint16_t);
        uint16_t get_waitTime() const;
        
        
        static SrvLogoutReply create(const uint16_t& waitTime);
        static SrvLogoutReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvLogoutReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t waitTime;
};

}
}
