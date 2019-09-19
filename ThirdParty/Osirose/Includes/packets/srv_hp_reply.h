#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvHpReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_HP_REPLY;
        SrvHpReply();
        SrvHpReply(CRoseReader reader);
        SrvHpReply(SrvHpReply&&) = default;
        SrvHpReply& operator=(SrvHpReply&&) = default;
        ~SrvHpReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvHpReply& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvHpReply& set_hp(const int32_t);
        int32_t get_hp() const;
        
        
        static SrvHpReply create(const uint16_t& id, const int32_t& hp);
        static SrvHpReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvHpReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        int32_t hp;
};

}
}
