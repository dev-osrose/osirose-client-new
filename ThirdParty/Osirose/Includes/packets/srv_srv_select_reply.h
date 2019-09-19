#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvSrvSelectReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKLC_SRV_SELECT_REPLY;
        SrvSrvSelectReply();
        SrvSrvSelectReply(CRoseReader reader);
        SrvSrvSelectReply(SrvSrvSelectReply&&) = default;
        SrvSrvSelectReply& operator=(SrvSrvSelectReply&&) = default;
        ~SrvSrvSelectReply() = default;
        
        static constexpr size_t size();
        
        
        enum Result : uint8_t {
            OK = 0,
            FAILED = 1,
            FULL = 2,
            INVALID_CHANNEL = 3,
            CHANNEL_NOT_ACTIVE = 4,
            INVALID_AGE = 5,
        };
        
        
        SrvSrvSelectReply& set_result(const Result);
        Result get_result() const;
        SrvSrvSelectReply& set_sessionId(const uint32_t);
        uint32_t get_sessionId() const;
        SrvSrvSelectReply& set_cryptVal(const uint32_t);
        uint32_t get_cryptVal() const;
        SrvSrvSelectReply& set_ip(const std::string&);
        const std::string& get_ip() const;
        SrvSrvSelectReply& set_port(const uint16_t);
        uint16_t get_port() const;
        
        
        static SrvSrvSelectReply create(const Result& result, const uint32_t& sessionId, const uint32_t& cryptVal, const std::string& ip, const uint16_t& port);
        static SrvSrvSelectReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvSrvSelectReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        Result result;
        uint32_t sessionId;
        uint32_t cryptVal;
        std::string ip;
        uint16_t port;
};

}
}
