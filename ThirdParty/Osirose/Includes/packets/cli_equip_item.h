#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliEquipItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_EQUIP_ITEM;
        CliEquipItem();
        CliEquipItem(CRoseReader reader);
        CliEquipItem(CliEquipItem&&) = default;
        CliEquipItem& operator=(CliEquipItem&&) = default;
        ~CliEquipItem() = default;
        
        static constexpr size_t size();
        
        
        
        CliEquipItem& set_slotTo(const int16_t);
        int16_t get_slotTo() const;
        CliEquipItem& set_slotFrom(const int16_t);
        int16_t get_slotFrom() const;
        
        
        static CliEquipItem create(const int16_t& slotTo, const int16_t& slotFrom);
        static CliEquipItem create(const uint8_t* buffer);
        static std::unique_ptr<CliEquipItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int16_t slotTo;
        int16_t slotFrom;
};

}
}
