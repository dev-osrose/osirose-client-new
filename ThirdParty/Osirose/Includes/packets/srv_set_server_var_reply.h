#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetServerVarReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_SERVER_VAR_REPLY;
        SrvSetServerVarReply();
        SrvSetServerVarReply(CRoseReader reader);
        SrvSetServerVarReply(SrvSetServerVarReply&&) = default;
        SrvSetServerVarReply& operator=(SrvSetServerVarReply&&) = default;
        ~SrvSetServerVarReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetServerVarReply& set_type(const uint8_t);
        uint8_t get_type() const;
        SrvSetServerVarReply& set_value(const uint32_t);
        uint32_t get_value() const;
        
        
        static SrvSetServerVarReply create();
        static SrvSetServerVarReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetServerVarReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t type = 0;
        uint32_t value = 0;
};

}
}
