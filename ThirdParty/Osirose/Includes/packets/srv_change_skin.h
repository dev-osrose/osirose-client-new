#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvChangeSkin : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CHANGE_SKIN;
        SrvChangeSkin();
        SrvChangeSkin(CRoseReader reader);
        SrvChangeSkin(SrvChangeSkin&&) = default;
        SrvChangeSkin& operator=(SrvChangeSkin&&) = default;
        ~SrvChangeSkin() = default;
        
        static constexpr size_t size();
        
        
        enum EquippedPositionRide : uint16_t {
            BODY = 0,
            ENGINE = 1,
            LEG = 2,
            ABILITY = 3,
            ARM = 4,
        };
        
        
        SrvChangeSkin& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvChangeSkin& set_slot(const EquippedPositionRide);
        EquippedPositionRide get_slot() const;
        SrvChangeSkin& set_item_id(const uint32_t);
        uint32_t get_item_id() const;
        
        
        static SrvChangeSkin create(const uint16_t& char_id, const EquippedPositionRide& slot, const uint32_t& item_id);
        static SrvChangeSkin create(const uint8_t* buffer);
        static std::unique_ptr<SrvChangeSkin> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        EquippedPositionRide slot;
        uint32_t item_id;
};

}
}
