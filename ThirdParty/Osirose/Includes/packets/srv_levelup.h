#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvLevelup : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_LEVELUP;
        SrvLevelup();
        SrvLevelup(CRoseReader reader);
        SrvLevelup(SrvLevelup&&) = default;
        SrvLevelup& operator=(SrvLevelup&&) = default;
        ~SrvLevelup() = default;
        
        static constexpr size_t size();
        
        
        
        SrvLevelup& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvLevelup& set_level(const int16_t);
        int16_t get_level() const;
        SrvLevelup& set_exp(const int64_t);
        int64_t get_exp() const;
        SrvLevelup& set_stat_points(const int16_t);
        int16_t get_stat_points() const;
        SrvLevelup& set_skill_points(const int16_t);
        int16_t get_skill_points() const;
        
        
        static SrvLevelup create(const uint16_t& id, const int16_t& level, const int64_t& exp, const int16_t& stat_points, const int16_t& skill_points);
        static SrvLevelup create(const uint8_t* buffer);
        static std::unique_ptr<SrvLevelup> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        int16_t level;
        int64_t exp;
        int16_t stat_points;
        int16_t skill_points;
};

}
}
