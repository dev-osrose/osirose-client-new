#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliClanIconReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CLAN_ICON_REQ;
        CliClanIconReq();
        CliClanIconReq(CRoseReader reader);
        CliClanIconReq(CliClanIconReq&&) = default;
        CliClanIconReq& operator=(CliClanIconReq&&) = default;
        ~CliClanIconReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliClanIconReq& set_id(const uint32_t);
        uint32_t get_id() const;
        
        
        static CliClanIconReq create(const uint32_t& id);
        static CliClanIconReq create(const uint8_t* buffer);
        static std::unique_ptr<CliClanIconReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint32_t id;
};

}
}
