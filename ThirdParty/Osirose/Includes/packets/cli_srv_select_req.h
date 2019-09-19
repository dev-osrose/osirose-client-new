#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSrvSelectReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SRV_SELECT_REQ;
        CliSrvSelectReq();
        CliSrvSelectReq(CRoseReader reader);
        CliSrvSelectReq(CliSrvSelectReq&&) = default;
        CliSrvSelectReq& operator=(CliSrvSelectReq&&) = default;
        ~CliSrvSelectReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliSrvSelectReq& set_serverId(const uint32_t);
        uint32_t get_serverId() const;
        CliSrvSelectReq& set_channelId(const uint8_t);
        uint8_t get_channelId() const;
        
        
        static CliSrvSelectReq create(const uint32_t& serverId, const uint8_t& channelId);
        static CliSrvSelectReq create(const uint8_t* buffer);
        static std::unique_ptr<CliSrvSelectReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint32_t serverId;
        uint8_t channelId;
};

}
}
