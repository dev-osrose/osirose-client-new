#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvChanCharReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CHAN_CHAR_REPLY;
        SrvChanCharReply();
        SrvChanCharReply(CRoseReader reader);
        SrvChanCharReply(SrvChanCharReply&&) = default;
        SrvChanCharReply& operator=(SrvChanCharReply&&) = default;
        ~SrvChanCharReply() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static SrvChanCharReply create();
        static SrvChanCharReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvChanCharReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
