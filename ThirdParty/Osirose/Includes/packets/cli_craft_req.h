#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <array>

namespace RoseCommon {
namespace Packet {

class CliCraftReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CRAFT_REQ;
        CliCraftReq();
        CliCraftReq(CRoseReader reader);
        CliCraftReq(CliCraftReq&&) = default;
        CliCraftReq& operator=(CliCraftReq&&) = default;
        ~CliCraftReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliCraftReq& set_slot(const uint8_t);
        uint8_t get_slot() const;
        CliCraftReq& set_type(const int8_t);
        int8_t get_type() const;
        CliCraftReq& set_id(const int8_t);
        int8_t get_id() const;
        CliCraftReq& set_material_slots(const std::array<int16_t, 4>&);
        CliCraftReq& set_material_slots(const int16_t&, size_t index);
        const std::array<int16_t, 4>& get_material_slots() const;
        const int16_t& get_material_slots(size_t index) const;
        
        
        static CliCraftReq create(const uint8_t& slot, const int8_t& type, const int8_t& id, const std::array<int16_t, 4>& material_slots);
        static CliCraftReq create(const uint8_t* buffer);
        static std::unique_ptr<CliCraftReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t slot;
        int8_t type;
        int8_t id;
        std::array<int16_t, 4> material_slots;
};

}
}
