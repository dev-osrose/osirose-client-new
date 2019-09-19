#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSetServerVarReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SET_SERVER_VAR_REQ;
        CliSetServerVarReq();
        CliSetServerVarReq(CRoseReader reader);
        CliSetServerVarReq(CliSetServerVarReq&&) = default;
        CliSetServerVarReq& operator=(CliSetServerVarReq&&) = default;
        ~CliSetServerVarReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliSetServerVarReq& set_type(const uint8_t);
        uint8_t get_type() const;
        CliSetServerVarReq& set_value(const uint32_t);
        uint32_t get_value() const;
        
        
        static CliSetServerVarReq create(const uint8_t& type, const uint32_t& value);
        static CliSetServerVarReq create(const uint8_t* buffer);
        static std::unique_ptr<CliSetServerVarReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t type;
        uint32_t value;
};

}
}
