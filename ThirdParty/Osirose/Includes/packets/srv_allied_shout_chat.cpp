#include "srv_allied_shout_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvAlliedShoutChat::SrvAlliedShoutChat() : CRosePacket(SrvAlliedShoutChat::PACKET_ID) {}

SrvAlliedShoutChat::SrvAlliedShoutChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint32_t(team)) {
        return;
    }
    if (!reader.get_string(sender)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvAlliedShoutChat& SrvAlliedShoutChat::set_team(const uint32_t team) {
    this->team = team;
    return *this;
}

uint32_t SrvAlliedShoutChat::get_team() const {
    return team;
}

SrvAlliedShoutChat& SrvAlliedShoutChat::set_sender(const std::string& sender) {
    this->sender = sender;
    return *this;
}

const std::string& SrvAlliedShoutChat::get_sender() const {
    return sender;
}

SrvAlliedShoutChat& SrvAlliedShoutChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvAlliedShoutChat::get_message() const {
    return message;
}

SrvAlliedShoutChat SrvAlliedShoutChat::create(const uint32_t& team, const std::string& sender, const std::string& message) {
    SrvAlliedShoutChat packet;
    packet.set_team(team);
    packet.set_sender(sender);
    packet.set_message(message);
    return packet;
}

SrvAlliedShoutChat SrvAlliedShoutChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvAlliedShoutChat(reader);
}

std::unique_ptr<SrvAlliedShoutChat> SrvAlliedShoutChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvAlliedShoutChat>(reader);
}

bool SrvAlliedShoutChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(team)) {
        return false;
    }
    if (!writer.set_string(sender)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvAlliedShoutChat::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // team
    return size;
}

