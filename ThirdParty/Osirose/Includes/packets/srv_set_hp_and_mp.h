#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetHpAndMp : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_HP_AND_MP;
        SrvSetHpAndMp();
        SrvSetHpAndMp(CRoseReader reader);
        SrvSetHpAndMp(SrvSetHpAndMp&&) = default;
        SrvSetHpAndMp& operator=(SrvSetHpAndMp&&) = default;
        ~SrvSetHpAndMp() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetHpAndMp& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvSetHpAndMp& set_hp(const int32_t);
        int32_t get_hp() const;
        SrvSetHpAndMp& set_mp(const int32_t);
        int32_t get_mp() const;
        
        
        static SrvSetHpAndMp create(const uint16_t& id, const int32_t& hp, const int32_t& mp);
        static SrvSetHpAndMp create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetHpAndMp> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        int32_t hp;
        int32_t mp;
};

}
}
