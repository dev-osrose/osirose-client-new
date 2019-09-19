#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvCreateCharReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CREATE_CHAR_REPLY;
        SrvCreateCharReply();
        SrvCreateCharReply(CRoseReader reader);
        SrvCreateCharReply(SrvCreateCharReply&&) = default;
        SrvCreateCharReply& operator=(SrvCreateCharReply&&) = default;
        ~SrvCreateCharReply() = default;
        
        static constexpr size_t size();
        
        
        enum Result : uint8_t {
            OK = 0,
            FAILED = 1,
            NAME_TAKEN = 2,
            INVALID_VALUE = 3,
            TOO_MANY_CHARS = 4,
            BLOCKED = 5,
        };
        
        
        SrvCreateCharReply& set_result(const Result);
        Result get_result() const;
        SrvCreateCharReply& set_platininum(const uint8_t);
        uint8_t get_platininum() const;
        
        
        static SrvCreateCharReply create(const Result& result);
        static SrvCreateCharReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvCreateCharReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        Result result;
        uint8_t platininum = 0;
};

}
}
