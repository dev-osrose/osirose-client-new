#include "srv_announce_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvAnnounceChat::SrvAnnounceChat() : CRosePacket(SrvAnnounceChat::PACKET_ID) {}

SrvAnnounceChat::SrvAnnounceChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_string(message)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

SrvAnnounceChat& SrvAnnounceChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvAnnounceChat::get_message() const {
    return message;
}

SrvAnnounceChat& SrvAnnounceChat::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvAnnounceChat::get_name() const {
    return name;
}

SrvAnnounceChat SrvAnnounceChat::create(const std::string& message, const std::string& name) {
    SrvAnnounceChat packet;
    packet.set_message(message);
    packet.set_name(name);
    return packet;
}

SrvAnnounceChat SrvAnnounceChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvAnnounceChat(reader);
}

std::unique_ptr<SrvAnnounceChat> SrvAnnounceChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvAnnounceChat>(reader);
}

bool SrvAnnounceChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_string(message)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAnnounceChat::size() {
    size_t size = 0;
    return size;
}

