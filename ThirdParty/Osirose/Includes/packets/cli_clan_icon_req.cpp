#include "cli_clan_icon_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliClanIconReq::CliClanIconReq() : CRosePacket(CliClanIconReq::PACKET_ID) {}

CliClanIconReq::CliClanIconReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint32_t(id)) {
        return;
    }
}

CliClanIconReq& CliClanIconReq::set_id(const uint32_t id) {
    this->id = id;
    return *this;
}

uint32_t CliClanIconReq::get_id() const {
    return id;
}

CliClanIconReq CliClanIconReq::create(const uint32_t& id) {
    CliClanIconReq packet;
    packet.set_id(id);
    return packet;
}

CliClanIconReq CliClanIconReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliClanIconReq(reader);
}

std::unique_ptr<CliClanIconReq> CliClanIconReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliClanIconReq>(reader);
}

bool CliClanIconReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t CliClanIconReq::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // id
    return size;
}

