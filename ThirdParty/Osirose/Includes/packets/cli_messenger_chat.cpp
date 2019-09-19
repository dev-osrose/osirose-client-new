#include "cli_messenger_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliMessengerChat::CliMessengerChat() : CRosePacket(CliMessengerChat::PACKET_ID) {}

CliMessengerChat::CliMessengerChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(tag)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

CliMessengerChat& CliMessengerChat::set_tag(const uint16_t tag) {
    this->tag = tag;
    return *this;
}

uint16_t CliMessengerChat::get_tag() const {
    return tag;
}

CliMessengerChat& CliMessengerChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliMessengerChat::get_message() const {
    return message;
}

CliMessengerChat CliMessengerChat::create(const uint16_t& tag, const std::string& message) {
    CliMessengerChat packet;
    packet.set_tag(tag);
    packet.set_message(message);
    return packet;
}

CliMessengerChat CliMessengerChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliMessengerChat(reader);
}

std::unique_ptr<CliMessengerChat> CliMessengerChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliMessengerChat>(reader);
}

bool CliMessengerChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(tag)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliMessengerChat::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // tag
    return size;
}

