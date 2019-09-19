#include "isc_transfer_char.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



IscTransferChar::IscTransferChar() : CRosePacket(IscTransferChar::PACKET_ID) {}

IscTransferChar::IscTransferChar(CRoseReader reader) : CRosePacket(reader) {
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            std::string elem;
            if (!reader.get_string(elem)) {
                return;
            }
            names.push_back(elem);
        }
    }
    {
        uint16_t size;
        if (!reader.get_uint16_t(size)) {
            return;
        }
        while (size-- > 0) {
            uint8_t elem;
            if (!reader.get_uint8_t(elem)) {
                return;
            }
            blob.push_back(elem);
        }
    }
}

IscTransferChar& IscTransferChar::set_names(const std::vector<std::string>& names) {
    this->names = names;
    return *this;
}

IscTransferChar& IscTransferChar::add_names(const std::string& names) {
    this->names.emplace_back(names);
    return *this;
}

const std::vector<std::string>& IscTransferChar::get_names() const {
    return names;
}

const std::string& IscTransferChar::get_names(size_t index) const {
    return names[index];
}

IscTransferChar& IscTransferChar::set_blob(const std::vector<uint8_t>& blob) {
    this->blob = blob;
    return *this;
}

IscTransferChar& IscTransferChar::add_blob(const uint8_t& blob) {
    this->blob.emplace_back(blob);
    return *this;
}

const std::vector<uint8_t>& IscTransferChar::get_blob() const {
    return blob;
}

const uint8_t& IscTransferChar::get_blob(size_t index) const {
    return blob[index];
}

IscTransferChar IscTransferChar::create(const std::vector<std::string>& names) {
    IscTransferChar packet;
    packet.set_names(names);
    return packet;
}

IscTransferChar IscTransferChar::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return IscTransferChar(reader);
}

std::unique_ptr<IscTransferChar> IscTransferChar::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<IscTransferChar>(reader);
}

bool IscTransferChar::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(names.size())) {
        return false;
    }
    for (const auto& elem : names) {
        if (!writer.set_string(elem)) {
            return false;
        }
    }
    if (!writer.set_uint16_t(blob.size())) {
        return false;
    }
    for (const auto& elem : blob) {
        if (!writer.set_uint8_t(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t IscTransferChar::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // blob
    size += sizeof(uint8_t); // blob
    return size;
}

