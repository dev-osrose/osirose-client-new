#include "srv_login_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvLoginReply::ServerInfo& SrvLoginReply::ServerInfo::set_test(const char test) {
    this->test = test;
    return *this;
}

char SrvLoginReply::ServerInfo::get_test() const {
    return test;
}

SrvLoginReply::ServerInfo& SrvLoginReply::ServerInfo::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvLoginReply::ServerInfo::get_name() const {
    return name;
}

SrvLoginReply::ServerInfo& SrvLoginReply::ServerInfo::set_id(const uint32_t id) {
    this->id = id;
    return *this;
}

uint32_t SrvLoginReply::ServerInfo::get_id() const {
    return id;
}

bool SrvLoginReply::ServerInfo::write(CRoseBasePolicy& writer) const {
    if (!writer.set_char(test)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    if (!writer.set_uint32_t(id)) {
        return false;
    }
    return true;
}

bool SrvLoginReply::ServerInfo::read(CRoseReader& reader) {
    if (!reader.get_char(test)) {
        return false;
    }
    if (!reader.get_string(name)) {
        return false;
    }
    if (!reader.get_uint32_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvLoginReply::ServerInfo::size() {
    size_t size = 0;
    size += sizeof(char); // test
    size += sizeof(uint32_t); // id
    return size;
}


SrvLoginReply::SrvLoginReply() : CRosePacket(SrvLoginReply::PACKET_ID) {}

SrvLoginReply::SrvLoginReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<Result>(result_temp);
    
    if (!reader.get_uint16_t(right)) {
        return;
    }
    if (!reader.get_uint16_t(type)) {
        return;
    }
    {
        SrvLoginReply::ServerInfo elem;
        while (reader.get_iserialize(elem)) {
            serversInfo.push_back(elem);
        }
    }
}

SrvLoginReply& SrvLoginReply::set_result(const SrvLoginReply::Result result) {
    this->result = result;
    return *this;
}

SrvLoginReply::Result SrvLoginReply::get_result() const {
    return result;
}

SrvLoginReply& SrvLoginReply::set_right(const uint16_t right) {
    this->right = right;
    return *this;
}

uint16_t SrvLoginReply::get_right() const {
    return right;
}

SrvLoginReply& SrvLoginReply::set_type(const uint16_t type) {
    this->type = type;
    return *this;
}

uint16_t SrvLoginReply::get_type() const {
    return type;
}

SrvLoginReply& SrvLoginReply::set_serversInfo(const std::vector<SrvLoginReply::ServerInfo>& serversInfo) {
    this->serversInfo = serversInfo;
    return *this;
}

SrvLoginReply& SrvLoginReply::add_serversInfo(const ServerInfo& serversInfo) {
    this->serversInfo.emplace_back(serversInfo);
    return *this;
}

const std::vector<SrvLoginReply::ServerInfo>& SrvLoginReply::get_serversInfo() const {
    return serversInfo;
}

const SrvLoginReply::ServerInfo& SrvLoginReply::get_serversInfo(size_t index) const {
    return serversInfo[index];
}

SrvLoginReply SrvLoginReply::create(const SrvLoginReply::Result& result, const uint16_t& right, const uint16_t& type) {
    SrvLoginReply packet;
    packet.set_result(result);
    packet.set_right(right);
    packet.set_type(type);
    return packet;
}

SrvLoginReply SrvLoginReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvLoginReply(reader);
}

std::unique_ptr<SrvLoginReply> SrvLoginReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvLoginReply>(reader);
}

bool SrvLoginReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint16_t(right)) {
        return false;
    }
    if (!writer.set_uint16_t(type)) {
        return false;
    }
    for (const auto& elem : serversInfo) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvLoginReply::size() {
    size_t size = 0;
    size += sizeof(Result); // result
    size += sizeof(uint16_t); // right
    size += sizeof(uint16_t); // type
    size += ServerInfo::size(); // serversInfo
    return size;
}

