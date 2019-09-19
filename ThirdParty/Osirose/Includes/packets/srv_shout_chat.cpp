#include "srv_shout_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvShoutChat::SrvShoutChat() : CRosePacket(SrvShoutChat::PACKET_ID) {}

SrvShoutChat::SrvShoutChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(sender)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvShoutChat& SrvShoutChat::set_sender(const std::string& sender) {
    this->sender = sender;
    return *this;
}

const std::string& SrvShoutChat::get_sender() const {
    return sender;
}

SrvShoutChat& SrvShoutChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvShoutChat::get_message() const {
    return message;
}

SrvShoutChat SrvShoutChat::create(const std::string& sender, const std::string& message) {
    SrvShoutChat packet;
    packet.set_sender(sender);
    packet.set_message(message);
    return packet;
}

SrvShoutChat SrvShoutChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvShoutChat(reader);
}

std::unique_ptr<SrvShoutChat> SrvShoutChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvShoutChat>(reader);
}

bool SrvShoutChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(sender)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShoutChat::size() {
    size_t size = 0;
    return size;
}

