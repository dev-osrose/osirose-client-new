#include "srv_allied_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvAlliedChat::SrvAlliedChat() : CRosePacket(SrvAlliedChat::PACKET_ID) {}

SrvAlliedChat::SrvAlliedChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint32_t(team)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvAlliedChat& SrvAlliedChat::set_team(const uint32_t team) {
    this->team = team;
    return *this;
}

uint32_t SrvAlliedChat::get_team() const {
    return team;
}

SrvAlliedChat& SrvAlliedChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvAlliedChat::get_message() const {
    return message;
}

SrvAlliedChat SrvAlliedChat::create(const std::string& message) {
    SrvAlliedChat packet;
    packet.set_message(message);
    return packet;
}

SrvAlliedChat SrvAlliedChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvAlliedChat(reader);
}

std::unique_ptr<SrvAlliedChat> SrvAlliedChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvAlliedChat>(reader);
}

bool SrvAlliedChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(team)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAlliedChat::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // team
    return size;
}

