#include "cli_toggle_move.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliToggleMove::CliToggleMove() : CRosePacket(CliToggleMove::PACKET_ID) {}

CliToggleMove::CliToggleMove(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<ToggleMove>(type_temp);
    
}

CliToggleMove& CliToggleMove::set_type(const CliToggleMove::ToggleMove type) {
    this->type = type;
    return *this;
}

CliToggleMove::ToggleMove CliToggleMove::get_type() const {
    return type;
}

CliToggleMove CliToggleMove::create(const CliToggleMove::ToggleMove& type) {
    CliToggleMove packet;
    packet.set_type(type);
    return packet;
}

CliToggleMove CliToggleMove::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliToggleMove(reader);
}

std::unique_ptr<CliToggleMove> CliToggleMove::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliToggleMove>(reader);
}

bool CliToggleMove::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    return true;
}

constexpr size_t CliToggleMove::size() {
    size_t size = 0;
    size += sizeof(ToggleMove); // type
    return size;
}

