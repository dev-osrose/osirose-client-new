#include "srv_clan_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvClanChat::SrvClanChat() : CRosePacket(SrvClanChat::PACKET_ID) {}

SrvClanChat::SrvClanChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(sender)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvClanChat& SrvClanChat::set_sender(const std::string& sender) {
    this->sender = sender;
    return *this;
}

const std::string& SrvClanChat::get_sender() const {
    return sender;
}

SrvClanChat& SrvClanChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvClanChat::get_message() const {
    return message;
}

SrvClanChat SrvClanChat::create(const std::string& sender, const std::string& message) {
    SrvClanChat packet;
    packet.set_sender(sender);
    packet.set_message(message);
    return packet;
}

SrvClanChat SrvClanChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvClanChat(reader);
}

std::unique_ptr<SrvClanChat> SrvClanChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvClanChat>(reader);
}

bool SrvClanChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(sender)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvClanChat::size() {
    size_t size = 0;
    return size;
}

