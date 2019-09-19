#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include "dataconsts.h"
#include <array>

namespace RoseCommon {
namespace Packet {

class SrvChangeMapReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CHANGE_MAP_REPLY;
        SrvChangeMapReply();
        SrvChangeMapReply(CRoseReader reader);
        SrvChangeMapReply(SrvChangeMapReply&&) = default;
        SrvChangeMapReply& operator=(SrvChangeMapReply&&) = default;
        ~SrvChangeMapReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvChangeMapReply& set_objectIndex(const uint16_t);
        uint16_t get_objectIndex() const;
        SrvChangeMapReply& set_hp(const uint16_t);
        uint16_t get_hp() const;
        SrvChangeMapReply& set_mp(const uint16_t);
        uint16_t get_mp() const;
        SrvChangeMapReply& set_xp(const uint16_t);
        uint16_t get_xp() const;
        SrvChangeMapReply& set_penalizeXp(const uint16_t);
        uint16_t get_penalizeXp() const;
        SrvChangeMapReply& set_craftRate(const uint16_t);
        uint16_t get_craftRate() const;
        SrvChangeMapReply& set_updateTime(const uint16_t);
        uint16_t get_updateTime() const;
        SrvChangeMapReply& set_worldRate(const uint16_t);
        uint16_t get_worldRate() const;
        SrvChangeMapReply& set_townRate(const uint8_t);
        uint8_t get_townRate() const;
        SrvChangeMapReply& set_itemRate(const std::array<uint8_t, MAX_SELL_TYPE>);
        SrvChangeMapReply& set_itemRate(const uint8_t, size_t index);
        std::array<uint8_t, MAX_SELL_TYPE> get_itemRate() const;
        uint8_t get_itemRate(size_t index) const;
        SrvChangeMapReply& set_flags(const uint32_t);
        uint32_t get_flags() const;
        SrvChangeMapReply& set_worldTime(const uint16_t);
        uint16_t get_worldTime() const;
        SrvChangeMapReply& set_teamNumber(const uint16_t);
        uint16_t get_teamNumber() const;
        
        
        static SrvChangeMapReply create(const uint16_t& objectIndex, const uint16_t& hp, const uint16_t& mp, const uint16_t& xp, const uint16_t& penalizeXp, const uint16_t& worldTime, const uint16_t& teamNumber);
        static SrvChangeMapReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvChangeMapReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t objectIndex;
        uint16_t hp;
        uint16_t mp;
        uint16_t xp;
        uint16_t penalizeXp;
        uint16_t craftRate = 0;
        uint16_t updateTime = 0;
        uint16_t worldRate = 0;
        uint8_t townRate = 0;
        std::array<uint8_t, MAX_SELL_TYPE> itemRate = {0};
        uint32_t flags = 0;
        uint16_t worldTime;
        uint16_t teamNumber;
};

}
}
