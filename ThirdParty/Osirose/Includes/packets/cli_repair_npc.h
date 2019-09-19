#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliRepairNpc : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_REPAIR_NPC;
        CliRepairNpc();
        CliRepairNpc(CRoseReader reader);
        CliRepairNpc(CliRepairNpc&&) = default;
        CliRepairNpc& operator=(CliRepairNpc&&) = default;
        ~CliRepairNpc() = default;
        
        static constexpr size_t size();
        
        
        
        CliRepairNpc& set_npc_id(const uint16_t);
        uint16_t get_npc_id() const;
        CliRepairNpc& set_target_index(const uint16_t);
        uint16_t get_target_index() const;
        
        
        static CliRepairNpc create(const uint16_t& npc_id, const uint16_t& target_index);
        static CliRepairNpc create(const uint8_t* buffer);
        static std::unique_ptr<CliRepairNpc> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t npc_id;
        uint16_t target_index;
};

}
}
