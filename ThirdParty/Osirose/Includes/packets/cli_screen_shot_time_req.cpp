#include "cli_screen_shot_time_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliScreenShotTimeReq::CliScreenShotTimeReq() : CRosePacket(CliScreenShotTimeReq::PACKET_ID) {}

CliScreenShotTimeReq::CliScreenShotTimeReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(count)) {
        return;
    }
}

CliScreenShotTimeReq& CliScreenShotTimeReq::set_count(const uint16_t count) {
    this->count = count;
    return *this;
}

uint16_t CliScreenShotTimeReq::get_count() const {
    return count;
}

CliScreenShotTimeReq CliScreenShotTimeReq::create() {
    CliScreenShotTimeReq packet;
    return packet;
}

CliScreenShotTimeReq CliScreenShotTimeReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliScreenShotTimeReq(reader);
}

std::unique_ptr<CliScreenShotTimeReq> CliScreenShotTimeReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliScreenShotTimeReq>(reader);
}

bool CliScreenShotTimeReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(count)) {
        return false;
    }
    return true;
}

constexpr size_t CliScreenShotTimeReq::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // count
    return size;
}

