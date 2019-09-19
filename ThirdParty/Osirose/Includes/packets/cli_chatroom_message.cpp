#include "cli_chatroom_message.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliChatroomMessage::CliChatroomMessage() : CRosePacket(CliChatroomMessage::PACKET_ID) {}

CliChatroomMessage::CliChatroomMessage(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(message)) {
        return;
    }
}

CliChatroomMessage& CliChatroomMessage::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliChatroomMessage::get_message() const {
    return message;
}

CliChatroomMessage CliChatroomMessage::create(const std::string& message) {
    CliChatroomMessage packet;
    packet.set_message(message);
    return packet;
}

CliChatroomMessage CliChatroomMessage::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliChatroomMessage(reader);
}

std::unique_ptr<CliChatroomMessage> CliChatroomMessage::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliChatroomMessage>(reader);
}

bool CliChatroomMessage::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliChatroomMessage::size() {
    size_t size = 0;
    return size;
}

