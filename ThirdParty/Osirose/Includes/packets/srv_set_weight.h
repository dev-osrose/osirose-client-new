#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetWeight : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_WEIGHT;
        SrvSetWeight();
        SrvSetWeight(CRoseReader reader);
        SrvSetWeight(SrvSetWeight&&) = default;
        SrvSetWeight& operator=(SrvSetWeight&&) = default;
        ~SrvSetWeight() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetWeight& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvSetWeight& set_weight(const uint8_t);
        uint8_t get_weight() const;
        
        
        static SrvSetWeight create(const uint16_t& char_id, const uint8_t& weight);
        static SrvSetWeight create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetWeight> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        uint8_t weight;
};

}
}
