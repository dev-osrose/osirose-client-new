#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvClanIconTimestamp : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CLAN_ICON_TIMESTAMP;
        SrvClanIconTimestamp();
        SrvClanIconTimestamp(CRoseReader reader);
        SrvClanIconTimestamp(SrvClanIconTimestamp&&) = default;
        SrvClanIconTimestamp& operator=(SrvClanIconTimestamp&&) = default;
        ~SrvClanIconTimestamp() = default;
        
        static constexpr size_t size();
        
        
        
        SrvClanIconTimestamp& set_year(const uint16_t);
        uint16_t get_year() const;
        SrvClanIconTimestamp& set_month(const uint8_t);
        uint8_t get_month() const;
        SrvClanIconTimestamp& set_day(const uint8_t);
        uint8_t get_day() const;
        SrvClanIconTimestamp& set_hour(const uint8_t);
        uint8_t get_hour() const;
        SrvClanIconTimestamp& set_min(const uint8_t);
        uint8_t get_min() const;
        SrvClanIconTimestamp& set_sec(const uint8_t);
        uint8_t get_sec() const;
        
        
        static SrvClanIconTimestamp create(const uint16_t& year, const uint8_t& month, const uint8_t& day, const uint8_t& hour, const uint8_t& min, const uint8_t& sec);
        static SrvClanIconTimestamp create(const uint8_t* buffer);
        static std::unique_ptr<SrvClanIconTimestamp> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t year;
        uint8_t month;
        uint8_t day;
        uint8_t hour;
        uint8_t min;
        uint8_t sec;
};

}
}
