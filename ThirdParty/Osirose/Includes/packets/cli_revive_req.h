#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliReviveReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_REVIVE_REQ;
        CliReviveReq();
        CliReviveReq(CRoseReader reader);
        CliReviveReq(CliReviveReq&&) = default;
        CliReviveReq& operator=(CliReviveReq&&) = default;
        ~CliReviveReq() = default;
        
        static constexpr size_t size();
        
        
        enum ReviveRequest : uint8_t {
            REVIVE_POSITION = 1,
            SAVE_POSITION = 2,
            START_POSITION = 3,
            CURRENT_POSITION = 4,
        };
        
        
        CliReviveReq& set_reviveType(const ReviveRequest);
        ReviveRequest get_reviveType() const;
        
        
        static CliReviveReq create(const ReviveRequest& reviveType);
        static CliReviveReq create(const uint8_t* buffer);
        static std::unique_ptr<CliReviveReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        ReviveRequest reviveType;
};

}
}
