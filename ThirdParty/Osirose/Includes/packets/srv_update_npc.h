#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvUpdateNpc : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_UPDATE_NPC;
        SrvUpdateNpc();
        SrvUpdateNpc(CRoseReader reader);
        SrvUpdateNpc(SrvUpdateNpc&&) = default;
        SrvUpdateNpc& operator=(SrvUpdateNpc&&) = default;
        ~SrvUpdateNpc() = default;
        
        static constexpr size_t size();
        
        
        
        SrvUpdateNpc& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvUpdateNpc& set_npc_id(const int16_t);
        int16_t get_npc_id() const;
        
        
        static SrvUpdateNpc create(const uint16_t& id);
        static SrvUpdateNpc create(const uint8_t* buffer);
        static std::unique_ptr<SrvUpdateNpc> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        int16_t npc_id = 0;
};

}
}
