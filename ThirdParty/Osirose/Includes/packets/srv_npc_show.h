#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvNpcShow : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_NPC_SHOW;
        SrvNpcShow();
        SrvNpcShow(CRoseReader reader);
        SrvNpcShow(SrvNpcShow&&) = default;
        SrvNpcShow& operator=(SrvNpcShow&&) = default;
        ~SrvNpcShow() = default;
        
        static constexpr size_t size();
        
        
        
        SrvNpcShow& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvNpcShow& set_show(const uint8_t);
        uint8_t get_show() const;
        
        
        static SrvNpcShow create(const uint16_t& id, const uint8_t& show);
        static SrvNpcShow create(const uint8_t* buffer);
        static std::unique_ptr<SrvNpcShow> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        uint8_t show;
};

}
}
