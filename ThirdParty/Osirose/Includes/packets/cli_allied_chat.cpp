#include "cli_allied_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliAlliedChat::CliAlliedChat() : CRosePacket(CliAlliedChat::PACKET_ID) {}

CliAlliedChat::CliAlliedChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(message)) {
        return;
    }
}

CliAlliedChat& CliAlliedChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliAlliedChat::get_message() const {
    return message;
}

CliAlliedChat CliAlliedChat::create(const std::string& message) {
    CliAlliedChat packet;
    packet.set_message(message);
    return packet;
}

CliAlliedChat CliAlliedChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliAlliedChat(reader);
}

std::unique_ptr<CliAlliedChat> CliAlliedChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliAlliedChat>(reader);
}

bool CliAlliedChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliAlliedChat::size() {
    size_t size = 0;
    return size;
}

