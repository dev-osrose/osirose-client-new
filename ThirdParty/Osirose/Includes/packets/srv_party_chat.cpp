#include "srv_party_chat.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvPartyChat::SrvPartyChat() : CRosePacket(SrvPartyChat::PACKET_ID) {}

SrvPartyChat::SrvPartyChat(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvPartyChat& SrvPartyChat::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvPartyChat::get_char_id() const {
    return char_id;
}

SrvPartyChat& SrvPartyChat::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvPartyChat::get_message() const {
    return message;
}

SrvPartyChat SrvPartyChat::create(const uint16_t& char_id, const std::string& message) {
    SrvPartyChat packet;
    packet.set_char_id(char_id);
    packet.set_message(message);
    return packet;
}

SrvPartyChat SrvPartyChat::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyChat(reader);
}

std::unique_ptr<SrvPartyChat> SrvPartyChat::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyChat>(reader);
}

bool SrvPartyChat::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyChat::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    return size;
}

