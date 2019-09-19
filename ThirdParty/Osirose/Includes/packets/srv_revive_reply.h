#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvReviveReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_REVIVE_REPLY;
        SrvReviveReply();
        SrvReviveReply(CRoseReader reader);
        SrvReviveReply(SrvReviveReply&&) = default;
        SrvReviveReply& operator=(SrvReviveReply&&) = default;
        ~SrvReviveReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvReviveReply& set_map_id(const uint16_t);
        uint16_t get_map_id() const;
        
        
        static SrvReviveReply create();
        static SrvReviveReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvReviveReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t map_id = 0;
};

}
}
