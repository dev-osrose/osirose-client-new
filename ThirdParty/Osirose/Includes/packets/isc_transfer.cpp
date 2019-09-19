#include "isc_transfer.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



IscTransfer::IscTransfer() : CRosePacket(IscTransfer::PACKET_ID) {}

IscTransfer::IscTransfer(CRoseReader reader) : CRosePacket(reader) {
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

IscTransfer& IscTransfer::set_maps(const std::vector<uint16_t>& maps) {
    this->maps = maps;
    return *this;
}

IscTransfer& IscTransfer::add_maps(const uint16_t& maps) {
    this->maps.emplace_back(maps);
    return *this;
}

const std::vector<uint16_t>& IscTransfer::get_maps() const {
    return maps;
}

const uint16_t& IscTransfer::get_maps(size_t index) const {
    return maps[index];
}

IscTransfer& IscTransfer::set_blob(const std::vector<uint8_t>& blob) {
    this->blob = blob;
    return *this;
}

IscTransfer& IscTransfer::add_blob(const uint8_t& blob) {
    this->blob.emplace_back(blob);
    return *this;
}

const std::vector<uint8_t>& IscTransfer::get_blob() const {
    return blob;
}

const uint8_t& IscTransfer::get_blob(size_t index) const {
    return blob[index];
}

IscTransfer IscTransfer::create(const std::vector<uint16_t>& maps) {
    IscTransfer packet;
    packet.set_maps(maps);
    return packet;
}

IscTransfer IscTransfer::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return IscTransfer(reader);
}

std::unique_ptr<IscTransfer> IscTransfer::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<IscTransfer>(reader);
}

bool IscTransfer::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(maps.size())) {
        return false;
    }
    for (const auto& elem : maps) {
        if (!writer.set_uint16_t(elem)) {
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

constexpr size_t IscTransfer::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // maps
    size += sizeof(uint16_t); // maps
    size += sizeof(uint16_t); // blob
    size += sizeof(uint8_t); // blob
    return size;
}

