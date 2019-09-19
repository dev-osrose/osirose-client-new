#include "cli_clan_icon_set.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliClanIconSet::CliClanIconSet() : CRosePacket(CliClanIconSet::PACKET_ID) {}

CliClanIconSet::CliClanIconSet(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(crc)) {
        return;
    }
    {
        uint8_t elem;
        while (reader.get_uint8_t(elem)) {
            data.push_back(elem);
        }
    }
}

CliClanIconSet& CliClanIconSet::set_crc(const uint16_t crc) {
    this->crc = crc;
    return *this;
}

uint16_t CliClanIconSet::get_crc() const {
    return crc;
}

CliClanIconSet& CliClanIconSet::set_data(const std::vector<uint8_t> data) {
    this->data = data;
    return *this;
}

CliClanIconSet& CliClanIconSet::add_data(const uint8_t data) {
    this->data.emplace_back(data);
    return *this;
}

std::vector<uint8_t> CliClanIconSet::get_data() const {
    return data;
}

uint8_t CliClanIconSet::get_data(size_t index) const {
    return data[index];
}

CliClanIconSet CliClanIconSet::create(const uint16_t& crc, const std::vector<uint8_t>& data) {
    CliClanIconSet packet;
    packet.set_crc(crc);
    packet.set_data(data);
    return packet;
}

CliClanIconSet CliClanIconSet::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliClanIconSet(reader);
}

std::unique_ptr<CliClanIconSet> CliClanIconSet::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliClanIconSet>(reader);
}

bool CliClanIconSet::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(crc)) {
        return false;
    }
    for (const auto& elem : data) {
        if (!writer.set_uint8_t(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t CliClanIconSet::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // crc
    size += sizeof(uint8_t); // data
    return size;
}

