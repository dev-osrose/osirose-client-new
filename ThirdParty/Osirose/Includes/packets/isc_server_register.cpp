#include "isc_server_register.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



IscServerRegister::IscServerRegister() : CRosePacket(IscServerRegister::PACKET_ID) {}

IscServerRegister::IscServerRegister(CRoseReader reader) : CRosePacket(reader) {
    uint8_t serverType_temp;
    if (!reader.get_uint8_t(serverType_temp)) {
        return;
    }
    serverType = static_cast<Isc::ServerType>(serverType_temp);
    
    if (!reader.get_string(name)) {
        return;
    }
    if (!reader.get_string(addr)) {
        return;
    }
    if (!reader.get_int32_t(port)) {
        return;
    }
    if (!reader.get_int32_t(right)) {
        return;
    }
    if (!reader.get_int32_t(id)) {
        return;
    }
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            uint16_t elem;
            if (!reader.get_uint16_t(elem)) {
                return;
            }
            maps.push_back(elem);
        }
    }
}

IscServerRegister& IscServerRegister::set_serverType(const Isc::ServerType serverType) {
    this->serverType = serverType;
    return *this;
}

Isc::ServerType IscServerRegister::get_serverType() const {
    return serverType;
}

IscServerRegister& IscServerRegister::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& IscServerRegister::get_name() const {
    return name;
}

IscServerRegister& IscServerRegister::set_addr(const std::string& addr) {
    this->addr = addr;
    return *this;
}

const std::string& IscServerRegister::get_addr() const {
    return addr;
}

IscServerRegister& IscServerRegister::set_port(const int32_t port) {
    this->port = port;
    return *this;
}

int32_t IscServerRegister::get_port() const {
    return port;
}

IscServerRegister& IscServerRegister::set_right(const int32_t right) {
    this->right = right;
    return *this;
}

int32_t IscServerRegister::get_right() const {
    return right;
}

IscServerRegister& IscServerRegister::set_id(const int32_t id) {
    this->id = id;
    return *this;
}

int32_t IscServerRegister::get_id() const {
    return id;
}

IscServerRegister& IscServerRegister::set_maps(const std::vector<uint16_t> maps) {
    this->maps = maps;
    return *this;
}

IscServerRegister& IscServerRegister::add_maps(const uint16_t maps) {
    this->maps.emplace_back(maps);
    return *this;
}

std::vector<uint16_t> IscServerRegister::get_maps() const {
    return maps;
}

uint16_t IscServerRegister::get_maps(size_t index) const {
    return maps[index];
}

IscServerRegister IscServerRegister::create(const Isc::ServerType& serverType, const std::string& name, const std::string& addr, const int32_t& port, const int32_t& right, const int32_t& id) {
    IscServerRegister packet;
    packet.set_serverType(serverType);
    packet.set_name(name);
    packet.set_addr(addr);
    packet.set_port(port);
    packet.set_right(right);
    packet.set_id(id);
    return packet;
}

IscServerRegister IscServerRegister::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return IscServerRegister(reader);
}

std::unique_ptr<IscServerRegister> IscServerRegister::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<IscServerRegister>(reader);
}

bool IscServerRegister::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(serverType)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    if (!writer.set_string(addr)) {
        return false;
    }
    if (!writer.set_int32_t(port)) {
        return false;
    }
    if (!writer.set_int32_t(right)) {
        return false;
    }
    if (!writer.set_int32_t(id)) {
        return false;
    }
    if (!writer.set_uint8_t(maps.size())) {
        return false;
    }
    for (const auto& elem : maps) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t IscServerRegister::size() {
    size_t size = 0;
    size += sizeof(Isc::ServerType); // serverType
    size += sizeof(int32_t); // port
    size += sizeof(int32_t); // right
    size += sizeof(int32_t); // id
    size += sizeof(uint8_t); // maps
    size += sizeof(uint16_t); // maps
    return size;
}

