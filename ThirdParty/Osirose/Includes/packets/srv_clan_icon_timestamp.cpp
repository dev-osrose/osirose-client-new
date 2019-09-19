#include "srv_clan_icon_timestamp.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvClanIconTimestamp::SrvClanIconTimestamp() : CRosePacket(SrvClanIconTimestamp::PACKET_ID) {}

SrvClanIconTimestamp::SrvClanIconTimestamp(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(year)) {
        return;
    }
    if (!reader.get_uint8_t(month)) {
        return;
    }
    if (!reader.get_uint8_t(day)) {
        return;
    }
    if (!reader.get_uint8_t(hour)) {
        return;
    }
    if (!reader.get_uint8_t(min)) {
        return;
    }
    if (!reader.get_uint8_t(sec)) {
        return;
    }
}

SrvClanIconTimestamp& SrvClanIconTimestamp::set_year(const uint16_t year) {
    this->year = year;
    return *this;
}

uint16_t SrvClanIconTimestamp::get_year() const {
    return year;
}

SrvClanIconTimestamp& SrvClanIconTimestamp::set_month(const uint8_t month) {
    this->month = month;
    return *this;
}

uint8_t SrvClanIconTimestamp::get_month() const {
    return month;
}

SrvClanIconTimestamp& SrvClanIconTimestamp::set_day(const uint8_t day) {
    this->day = day;
    return *this;
}

uint8_t SrvClanIconTimestamp::get_day() const {
    return day;
}

SrvClanIconTimestamp& SrvClanIconTimestamp::set_hour(const uint8_t hour) {
    this->hour = hour;
    return *this;
}

uint8_t SrvClanIconTimestamp::get_hour() const {
    return hour;
}

SrvClanIconTimestamp& SrvClanIconTimestamp::set_min(const uint8_t min) {
    this->min = min;
    return *this;
}

uint8_t SrvClanIconTimestamp::get_min() const {
    return min;
}

SrvClanIconTimestamp& SrvClanIconTimestamp::set_sec(const uint8_t sec) {
    this->sec = sec;
    return *this;
}

uint8_t SrvClanIconTimestamp::get_sec() const {
    return sec;
}

SrvClanIconTimestamp SrvClanIconTimestamp::create(const uint16_t& year, const uint8_t& month, const uint8_t& day, const uint8_t& hour, const uint8_t& min, const uint8_t& sec) {
    SrvClanIconTimestamp packet;
    packet.set_year(year);
    packet.set_month(month);
    packet.set_day(day);
    packet.set_hour(hour);
    packet.set_min(min);
    packet.set_sec(sec);
    return packet;
}

SrvClanIconTimestamp SrvClanIconTimestamp::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvClanIconTimestamp(reader);
}

std::unique_ptr<SrvClanIconTimestamp> SrvClanIconTimestamp::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvClanIconTimestamp>(reader);
}

bool SrvClanIconTimestamp::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(year)) {
        return false;
    }
    if (!writer.set_uint8_t(month)) {
        return false;
    }
    if (!writer.set_uint8_t(day)) {
        return false;
    }
    if (!writer.set_uint8_t(hour)) {
        return false;
    }
    if (!writer.set_uint8_t(min)) {
        return false;
    }
    if (!writer.set_uint8_t(sec)) {
        return false;
    }
    return true;
}

constexpr size_t SrvClanIconTimestamp::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // year
    size += sizeof(uint8_t); // month
    size += sizeof(uint8_t); // day
    size += sizeof(uint8_t); // hour
    size += sizeof(uint8_t); // min
    size += sizeof(uint8_t); // sec
    return size;
}

