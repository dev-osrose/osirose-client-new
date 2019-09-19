#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliRepairUseItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_REPAIR_USE_ITEM;
        CliRepairUseItem();
        CliRepairUseItem(CRoseReader reader);
        CliRepairUseItem(CliRepairUseItem&&) = default;
        CliRepairUseItem& operator=(CliRepairUseItem&&) = default;
        ~CliRepairUseItem() = default;
        
        static constexpr size_t size();
        
        
        
        CliRepairUseItem& set_index(const uint16_t);
        uint16_t get_index() const;
        CliRepairUseItem& set_target_index(const uint16_t);
        uint16_t get_target_index() const;
        
        
        static CliRepairUseItem create(const uint16_t& index, const uint16_t& target_index);
        static CliRepairUseItem create(const uint8_t* buffer);
        static std::unique_ptr<CliRepairUseItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t index;
        uint16_t target_index;
};

}
}
