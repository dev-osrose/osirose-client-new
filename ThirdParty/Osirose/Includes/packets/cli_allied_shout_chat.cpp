#include "cli_allied_shout_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliAlliedShoutChat::CliAlliedShoutChat() : CRosePacket(CliAlliedShoutChat::PACKET_ID) {}

CliAlliedShoutChat::CliAlliedShoutChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(message)) {
        return;
    }
}

CliAlliedShoutChat& CliAlliedShoutChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliAlliedShoutChat::get_message() const {
    return message;
}

CliAlliedShoutChat CliAlliedShoutChat::create(const std::string& message) {
    CliAlliedShoutChat packet;
    packet.set_message(message);
    return packet;
}

CliAlliedShoutChat CliAlliedShoutChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliAlliedShoutChat(reader);
}

std::unique_ptr<CliAlliedShoutChat> CliAlliedShoutChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliAlliedShoutChat>(reader);
}

bool CliAlliedShoutChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliAlliedShoutChat::size() {
    size_t size = 0;
    return size;
}

