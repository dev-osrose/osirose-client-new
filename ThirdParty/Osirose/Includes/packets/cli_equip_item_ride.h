#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliEquipItemRide : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_EQUIP_ITEM_RIDE;
        CliEquipItemRide();
        CliEquipItemRide(CRoseReader reader);
        CliEquipItemRide(CliEquipItemRide&&) = default;
        CliEquipItemRide& operator=(CliEquipItemRide&&) = default;
        ~CliEquipItemRide() = default;
        
        static constexpr size_t size();
        
        
        enum EquippedPositionRide : uint16_t {
            BODY = 0,
            ENGINE = 1,
            LEG = 2,
            ABILITY = 3,
            ARM = 4,
        };
        
        
        CliEquipItemRide& set_slot(const EquippedPositionRide);
        EquippedPositionRide get_slot() const;
        CliEquipItemRide& set_index(const uint16_t);
        uint16_t get_index() const;
        
        
        static CliEquipItemRide create(const EquippedPositionRide& slot, const uint16_t& index);
        static CliEquipItemRide create(const uint8_t* buffer);
        static std::unique_ptr<CliEquipItemRide> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        EquippedPositionRide slot;
        uint16_t index;
};

}
}
