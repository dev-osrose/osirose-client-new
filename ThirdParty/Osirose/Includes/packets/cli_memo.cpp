#include "cli_memo.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliMemo::CliMemo() : CRosePacket(CliMemo::PACKET_ID) {}

CliMemo::CliMemo(CRoseReader reader) : CRosePacket(reader) {
    uint8_t type_temp;
    if (!reader.get_uint8_t(type_temp)) {
        return;
    }
    type = static_cast<MemoType>(type_temp);
    
    if (!reader.get_string(target)) {
        return;
    }
    if (!reader.get_string(message)) {
        return;
    }
}

CliMemo& CliMemo::set_type(const CliMemo::MemoType type) {
    this->type = type;
    return *this;
}

CliMemo::MemoType CliMemo::get_type() const {
    return type;
}

CliMemo& CliMemo::set_target(const std::string& target) {
    this->target = target;
    return *this;
}

const std::string& CliMemo::get_target() const {
    return target;
}

CliMemo& CliMemo::set_message(const std::string& message) {
    this->message = message;
    return *this;
}

const std::string& CliMemo::get_message() const {
    return message;
}

CliMemo CliMemo::create(const CliMemo::MemoType& type, const std::string& target, const std::string& message) {
    CliMemo packet;
    packet.set_type(type);
    packet.set_target(target);
    packet.set_message(message);
    return packet;
}

CliMemo CliMemo::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliMemo(reader);
}

std::unique_ptr<CliMemo> CliMemo::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliMemo>(reader);
}

bool CliMemo::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(type)) {
        return false;
    }
    if (!writer.set_string(target)) {
        return false;
    }
    if (!writer.set_string(message)) {
        return false;
    }
    return true;
}

constexpr size_t CliMemo::size() {
    size_t size = 0;
    size += sizeof(MemoType); // type
    return size;
}

