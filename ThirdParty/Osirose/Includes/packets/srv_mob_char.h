#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvMobChar : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_MOB_CHAR;
        SrvMobChar();
        SrvMobChar(CRoseReader reader);
        SrvMobChar(SrvMobChar&&) = default;
        SrvMobChar& operator=(SrvMobChar&&) = default;
        ~SrvMobChar() = default;
        
        static constexpr size_t size();
        
        
        
        SrvMobChar& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvMobChar& set_x(const float);
        float get_x() const;
        SrvMobChar& set_y(const float);
        float get_y() const;
        SrvMobChar& set_destX(const float);
        float get_destX() const;
        SrvMobChar& set_destY(const float);
        float get_destY() const;
        SrvMobChar& set_command(const uint16_t);
        uint16_t get_command() const;
        SrvMobChar& set_targetId(const uint16_t);
        uint16_t get_targetId() const;
        SrvMobChar& set_moveMode(const uint8_t);
        uint8_t get_moveMode() const;
        SrvMobChar& set_hp(const int32_t);
        int32_t get_hp() const;
        SrvMobChar& set_teamId(const int32_t);
        int32_t get_teamId() const;
        SrvMobChar& set_statusFlag(const uint32_t);
        uint32_t get_statusFlag() const;
        SrvMobChar& set_npcId(const uint16_t);
        uint16_t get_npcId() const;
        SrvMobChar& set_questId(const uint16_t);
        uint16_t get_questId() const;
        
        
        static SrvMobChar create(const uint16_t& id);
        static SrvMobChar create(const uint8_t* buffer);
        static std::unique_ptr<SrvMobChar> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        float x = 0;
        float y = 0;
        float destX = 0;
        float destY = 0;
        uint16_t command = 0;
        uint16_t targetId = 0;
        uint8_t moveMode = 0;
        int32_t hp = 0;
        int32_t teamId = 0;
        uint32_t statusFlag = 0;
        uint16_t npcId = 0;
        uint16_t questId = 0;
};

}
}
