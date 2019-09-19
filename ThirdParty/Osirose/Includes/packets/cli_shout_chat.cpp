#include "cli_shout_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliShoutChat::CliShoutChat() : CRosePacket(CliShoutChat::PACKET_ID) {}

CliShoutChat::CliShoutChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(message)) {
        return;
    }
}

CliShoutChat& CliShoutChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliShoutChat::get_message() const {
    return message;
}

CliShoutChat CliShoutChat::create(const std::string& message) {
    CliShoutChat packet;
    packet.set_message(message);
    return packet;
}

CliShoutChat CliShoutChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliShoutChat(reader);
}

std::unique_ptr<CliShoutChat> CliShoutChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliShoutChat>(reader);
}

bool CliShoutChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliShoutChat::size() {
    size_t size = 0;
    return size;
}

