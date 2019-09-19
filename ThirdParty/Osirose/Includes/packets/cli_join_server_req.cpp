#include "cli_join_server_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;

CliJoinServerReq::Password::Password() : is_valid(false) {}

CliJoinServerReq::Password::Password(std::string data) : password(data), is_valid(false) {
    bool valid = true;
    if (password.size() > 64) {
        password.resize(64);
        valid &= true;
    } else {
        valid &= true;
    }
    is_valid = valid;
}

bool CliJoinServerReq::Password::read(CRoseReader& reader) {
    bool valid = true;
    if (!reader.get_string(password, 64)) {
        return false;
    } else {
        valid &= true;
    }
    is_valid = valid;
    return true;
}

bool CliJoinServerReq::Password::write(CRoseBasePolicy& writer) const {
    if (!writer.set_string(password, 64)) {
        return false;
    }
    return true;
}

constexpr size_t CliJoinServerReq::Password::size() {
    size_t size = 0;
    size += 64; // password
    return size;
}



CliJoinServerReq::CliJoinServerReq() : CRosePacket(CliJoinServerReq::PACKET_ID) {}

CliJoinServerReq::CliJoinServerReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint32_t(sessionId)) {
        return;
    }
    if (!reader.get_iserialize(password)) {
        return;
    }
}

CliJoinServerReq& CliJoinServerReq::set_sessionId(const uint32_t sessionId) {
    this->sessionId = sessionId;
    return *this;
}

uint32_t CliJoinServerReq::get_sessionId() const {
    return sessionId;
}

CliJoinServerReq& CliJoinServerReq::set_password(const CliJoinServerReq::Password& password) {
    this->password = password;
    return *this;
}

const CliJoinServerReq::Password& CliJoinServerReq::get_password() const {
    return password;
}

CliJoinServerReq CliJoinServerReq::create(const uint32_t& sessionId, const CliJoinServerReq::Password& password) {
    CliJoinServerReq packet;
    packet.set_sessionId(sessionId);
    packet.set_password(password);
    return packet;
}

CliJoinServerReq CliJoinServerReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliJoinServerReq(reader);
}

std::unique_ptr<CliJoinServerReq> CliJoinServerReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliJoinServerReq>(reader);
}

bool CliJoinServerReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(sessionId)) {
        return false;
    }
    if (!writer.set_iserialize(password)) {
        return false;
    }
    return true;
}

constexpr size_t CliJoinServerReq::size() {
    size_t size = 0;
    size += sizeof(uint32_t); // sessionId
    size += Password::size(); // password
    return size;
}

