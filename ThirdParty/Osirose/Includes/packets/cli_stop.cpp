#include "cli_stop.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliStop::CliStop() : CRosePacket(CliStop::PACKET_ID) {}

CliStop::CliStop(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
}

CliStop& CliStop::set_x(const float x) {
    this->x = x;
    return *this;
}

float CliStop::get_x() const {
    return x;
}

CliStop& CliStop::set_y(const float y) {
    this->y = y;
    return *this;
}

float CliStop::get_y() const {
    return y;
}

CliStop CliStop::create(const float& x, const float& y) {
    CliStop packet;
    packet.set_x(x);
    packet.set_y(y);
    return packet;
}

CliStop CliStop::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliStop(reader);
}

std::unique_ptr<CliStop> CliStop::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliStop>(reader);
}

bool CliStop::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    return true;
}

constexpr size_t CliStop::size() {
    size_t size = 0;
    size += sizeof(float); // x
    size += sizeof(float); // y
    return size;
}

