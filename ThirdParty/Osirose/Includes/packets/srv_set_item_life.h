#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetItemLife : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_ITEM_LIFE;
        SrvSetItemLife();
        SrvSetItemLife(CRoseReader reader);
        SrvSetItemLife(SrvSetItemLife&&) = default;
        SrvSetItemLife& operator=(SrvSetItemLife&&) = default;
        ~SrvSetItemLife() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetItemLife& set_index(const uint16_t);
        uint16_t get_index() const;
        SrvSetItemLife& set_life(const uint16_t);
        uint16_t get_life() const;
        
        
        static SrvSetItemLife create(const uint16_t& index, const uint16_t& life);
        static SrvSetItemLife create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetItemLife> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t index;
        uint16_t life;
};

}
}
