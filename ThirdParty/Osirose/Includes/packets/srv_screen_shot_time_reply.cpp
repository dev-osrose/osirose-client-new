#include "srv_screen_shot_time_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvScreenShotTimeReply::SrvScreenShotTimeReply() : CRosePacket(SrvScreenShotTimeReply::PACKET_ID) {}

SrvScreenShotTimeReply::SrvScreenShotTimeReply(CRoseReader reader) : CRosePacket(reader) {
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
}

SrvScreenShotTimeReply& SrvScreenShotTimeReply::set_year(const uint16_t year) {
    this->year = year;
    return *this;
}

uint16_t SrvScreenShotTimeReply::get_year() const {
    return year;
}

SrvScreenShotTimeReply& SrvScreenShotTimeReply::set_month(const uint8_t month) {
    this->month = month;
    return *this;
}

uint8_t SrvScreenShotTimeReply::get_month() const {
    return month;
}

SrvScreenShotTimeReply& SrvScreenShotTimeReply::set_day(const uint8_t day) {
    this->day = day;
    return *this;
}

uint8_t SrvScreenShotTimeReply::get_day() const {
    return day;
}

SrvScreenShotTimeReply& SrvScreenShotTimeReply::set_hour(const uint8_t hour) {
    this->hour = hour;
    return *this;
}

uint8_t SrvScreenShotTimeReply::get_hour() const {
    return hour;
}

SrvScreenShotTimeReply& SrvScreenShotTimeReply::set_min(const uint8_t min) {
    this->min = min;
    return *this;
}

uint8_t SrvScreenShotTimeReply::get_min() const {
    return min;
}

SrvScreenShotTimeReply SrvScreenShotTimeReply::create(const uint16_t& year, const uint8_t& month, const uint8_t& day, const uint8_t& hour, const uint8_t& min) {
    SrvScreenShotTimeReply packet;
    packet.set_year(year);
    packet.set_month(month);
    packet.set_day(day);
    packet.set_hour(hour);
    packet.set_min(min);
    return packet;
}

SrvScreenShotTimeReply SrvScreenShotTimeReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvScreenShotTimeReply(reader);
}

std::unique_ptr<SrvScreenShotTimeReply> SrvScreenShotTimeReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvScreenShotTimeReply>(reader);
}

bool SrvScreenShotTimeReply::pack(CRoseBasePolicy& writer) const {
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
    return true;
}

constexpr size_t SrvScreenShotTimeReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // year
    size += sizeof(uint8_t); // month
    size += sizeof(uint8_t); // day
    size += sizeof(uint8_t); // hour
    size += sizeof(uint8_t); // min
    return size;
}

