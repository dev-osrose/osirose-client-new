#include "cli_teleport_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliTeleportReq::CliTeleportReq() : CRosePacket(CliTeleportReq::PACKET_ID) {}

CliTeleportReq::CliTeleportReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int16_t(id)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
}

CliTeleportReq& CliTeleportReq::set_id(const int16_t id) {
    this->id = id;
    return *this;
}

int16_t CliTeleportReq::get_id() const {
    return id;
}

CliTeleportReq& CliTeleportReq::set_x(const float x) {
    this->x = x;
    return *this;
}

float CliTeleportReq::get_x() const {
    return x;
}

CliTeleportReq& CliTeleportReq::set_y(const float y) {
    this->y = y;
    return *this;
}

float CliTeleportReq::get_y() const {
    return y;
}

CliTeleportReq CliTeleportReq::create(const int16_t& id, const float& x, const float& y) {
    CliTeleportReq packet;
    packet.set_id(id);
    packet.set_x(x);
    packet.set_y(y);
    return packet;
}

CliTeleportReq CliTeleportReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliTeleportReq(reader);
}

std::unique_ptr<CliTeleportReq> CliTeleportReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliTeleportReq>(reader);
}

bool CliTeleportReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int16_t(id)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    return true;
}

constexpr size_t CliTeleportReq::size() {
    size_t size = 0;
    size += sizeof(int16_t); // id
    size += sizeof(float); // x
    size += sizeof(float); // y
    return size;
}

