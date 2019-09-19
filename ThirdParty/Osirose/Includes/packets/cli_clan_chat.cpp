#include "cli_clan_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliClanChat::CliClanChat() : CRosePacket(CliClanChat::PACKET_ID) {}

CliClanChat::CliClanChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(message)) {
        return;
    }
}

CliClanChat& CliClanChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliClanChat::get_message() const {
    return message;
}

CliClanChat CliClanChat::create(const std::string& message) {
    CliClanChat packet;
    packet.set_message(message);
    return packet;
}

CliClanChat CliClanChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliClanChat(reader);
}

std::unique_ptr<CliClanChat> CliClanChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliClanChat>(reader);
}

bool CliClanChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliClanChat::size() {
    size_t size = 0;
    return size;
}

