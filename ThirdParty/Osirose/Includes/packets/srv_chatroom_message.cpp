#include "srv_chatroom_message.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvChatroomMessage::SrvChatroomMessage() : CRosePacket(SrvChatroomMessage::PACKET_ID) {}

SrvChatroomMessage::SrvChatroomMessage(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

SrvChatroomMessage& SrvChatroomMessage::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvChatroomMessage::get_target() const {
    return target;
}

SrvChatroomMessage& SrvChatroomMessage::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& SrvChatroomMessage::get_message() const {
    return message;
}

SrvChatroomMessage SrvChatroomMessage::create(const uint16_t& target, const std::string& message) {
    SrvChatroomMessage packet;
    packet.set_target(target);
    packet.set_message(message);
    return packet;
}

SrvChatroomMessage SrvChatroomMessage::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvChatroomMessage(reader);
}

std::unique_ptr<SrvChatroomMessage> SrvChatroomMessage::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvChatroomMessage>(reader);
}

bool SrvChatroomMessage::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t SrvChatroomMessage::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    return size;
}

