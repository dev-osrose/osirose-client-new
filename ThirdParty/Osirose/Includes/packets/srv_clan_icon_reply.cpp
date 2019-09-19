#include "srv_clan_icon_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvClanIconReply::SrvClanIconReply() : CRosePacket(SrvClanIconReply::PACKET_ID) {}

SrvClanIconReply::SrvClanIconReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    {
        uint8_t elem;
        while (reader.get_uint8_t(elem)) {
            data.push_back(elem);
        }
    }
}

SrvClanIconReply& SrvClanIconReply::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvClanIconReply::get_id() const {
    return id;
}

SrvClanIconReply& SrvClanIconReply::set_data(const std::vector<uint8_t> data) {
    this->data = data;
    return *this;
}

SrvClanIconReply& SrvClanIconReply::add_data(const uint8_t data) {
    this->data.emplace_back(data);
    return *this;
}

std::vector<uint8_t> SrvClanIconReply::get_data() const {
    return data;
}

uint8_t SrvClanIconReply::get_data(size_t index) const {
    return data[index];
}

SrvClanIconReply SrvClanIconReply::create(const uint16_t& id, const std::vector<uint8_t>& data) {
    SrvClanIconReply packet;
    packet.set_id(id);
    packet.set_data(data);
    return packet;
}

SrvClanIconReply SrvClanIconReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvClanIconReply(reader);
}

std::unique_ptr<SrvClanIconReply> SrvClanIconReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvClanIconReply>(reader);
}

bool SrvClanIconReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    for (const auto& elem : data) {
        if (!writer.set_uint8_t(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvClanIconReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint8_t); // data
    return size;
}

