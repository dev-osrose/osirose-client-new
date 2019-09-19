#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliHpReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_HP_REQ;
        CliHpReq();
        CliHpReq(CRoseReader reader);
        CliHpReq(CliHpReq&&) = default;
        CliHpReq& operator=(CliHpReq&&) = default;
        ~CliHpReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliHpReq& set_targetId(const uint16_t);
        uint16_t get_targetId() const;
        
        
        static CliHpReq create(const uint16_t& targetId);
        static CliHpReq create(const uint8_t* buffer);
        static std::unique_ptr<CliHpReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t targetId;
};

}
}
