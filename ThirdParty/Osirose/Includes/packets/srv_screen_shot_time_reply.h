#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvScreenShotTimeReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKSC_SCREEN_SHOT_TIME_REPLY;
        SrvScreenShotTimeReply();
        SrvScreenShotTimeReply(CRoseReader reader);
        SrvScreenShotTimeReply(SrvScreenShotTimeReply&&) = default;
        SrvScreenShotTimeReply& operator=(SrvScreenShotTimeReply&&) = default;
        ~SrvScreenShotTimeReply() = default;
        
        static constexpr size_t size();
        
        
        
        SrvScreenShotTimeReply& set_year(const uint16_t);
        uint16_t get_year() const;
        SrvScreenShotTimeReply& set_month(const uint8_t);
        uint8_t get_month() const;
        SrvScreenShotTimeReply& set_day(const uint8_t);
        uint8_t get_day() const;
        SrvScreenShotTimeReply& set_hour(const uint8_t);
        uint8_t get_hour() const;
        SrvScreenShotTimeReply& set_min(const uint8_t);
        uint8_t get_min() const;
        
        
        static SrvScreenShotTimeReply create(const uint16_t& year, const uint8_t& month, const uint8_t& day, const uint8_t& hour, const uint8_t& min);
        static SrvScreenShotTimeReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvScreenShotTimeReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t year;
        uint8_t month;
        uint8_t day;
        uint8_t hour;
        uint8_t min;
};

}
}
