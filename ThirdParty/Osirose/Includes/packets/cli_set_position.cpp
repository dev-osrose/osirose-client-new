#include "cli_set_position.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliSetPosition::CliSetPosition() : CRosePacket(CliSetPosition::PACKET_ID) {}

CliSetPosition::CliSetPosition(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
}

CliSetPosition& CliSetPosition::set_x(const float x) {
    this->x = x;
    return *this;
}

float CliSetPosition::get_x() const {
    return x;
}

CliSetPosition& CliSetPosition::set_y(const float y) {
    this->y = y;
    return *this;
}

float CliSetPosition::get_y() const {
    return y;
}

CliSetPosition CliSetPosition::create(const float& x, const float& y) {
    CliSetPosition packet;
    packet.set_x(x);
    packet.set_y(y);
    return packet;
}

CliSetPosition CliSetPosition::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliSetPosition(reader);
}

std::unique_ptr<CliSetPosition> CliSetPosition::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliSetPosition>(reader);
}

bool CliSetPosition::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    return true;
}

constexpr size_t CliSetPosition::size() {
    size_t size = 0;
    size += sizeof(float); // x
    size += sizeof(float); // y
    return size;
}

