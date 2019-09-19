#include "cli_stat_add_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliStatAddReq::CliStatAddReq() : CRosePacket(CliStatAddReq::PACKET_ID) {}

CliStatAddReq::CliStatAddReq(CRoseReader reader) : CRosePacket(reader) {
    uint8_t stat_temp;
    if (!reader.get_uint8_t(stat_temp)) {
        return;
    }
    stat = static_cast<Stat>(stat_temp);
    
}

CliStatAddReq& CliStatAddReq::set_stat(const CliStatAddReq::Stat stat) {
    this->stat = stat;
    return *this;
}

CliStatAddReq::Stat CliStatAddReq::get_stat() const {
    return stat;
}

CliStatAddReq CliStatAddReq::create(const CliStatAddReq::Stat& stat) {
    CliStatAddReq packet;
    packet.set_stat(stat);
    return packet;
}

CliStatAddReq CliStatAddReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliStatAddReq(reader);
}

std::unique_ptr<CliStatAddReq> CliStatAddReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliStatAddReq>(reader);
}

bool CliStatAddReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(stat)) {
        return false;
    }
    return true;
}

constexpr size_t CliStatAddReq::size() {
    size_t size = 0;
    size += sizeof(Stat); // stat
    return size;
}

