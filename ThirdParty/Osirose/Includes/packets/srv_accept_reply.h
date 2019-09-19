#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvAcceptReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKSS_ACCEPT_REPLY;
        SrvAcceptReply();
        SrvAcceptReply(CRoseReader reader);
        SrvAcceptReply(SrvAcceptReply&&) = default;
        SrvAcceptReply& operator=(SrvAcceptReply&&) = default;
        ~SrvAcceptReply() = default;
        
        static constexpr size_t size();
        
        
        enum Result : uint8_t {
            CONNECT = 1,
            ACCEPTED = 2,
            DISCONNECT = 3,
            DERVERDEAD = 4,
        };
        
        
        SrvAcceptReply& set_result(const Result);
        Result get_result() const;
        SrvAcceptReply& set_randValue(const uint32_t);
        uint32_t get_randValue() const;
        
        
        static SrvAcceptReply create(const Result& result, const uint32_t& randValue);
        static SrvAcceptReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvAcceptReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        Result result;
        uint32_t randValue;
};

}
}
