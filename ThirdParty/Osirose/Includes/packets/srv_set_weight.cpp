#include "srv_set_weight.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetWeight::SrvSetWeight() : CRosePacket(SrvSetWeight::PACKET_ID) {}

SrvSetWeight::SrvSetWeight(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(char_id)) {
        return;
    }
    if (!reader.get_uint8_t(weight)) {
        return;
    }
}

SrvSetWeight& SrvSetWeight::set_char_id(const uint16_t char_id) {
    this->char_id = char_id;
    return *this;
}

uint16_t SrvSetWeight::get_char_id() const {
    return char_id;
}

SrvSetWeight& SrvSetWeight::set_weight(const uint8_t weight) {
    this->weight = weight;
    return *this;
}

uint8_t SrvSetWeight::get_weight() const {
    return weight;
}

SrvSetWeight SrvSetWeight::create(const uint16_t& char_id, const uint8_t& weight) {
    SrvSetWeight packet;
    packet.set_char_id(char_id);
    packet.set_weight(weight);
    return packet;
}

SrvSetWeight SrvSetWeight::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetWeight(reader);
}

std::unique_ptr<SrvSetWeight> SrvSetWeight::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetWeight>(reader);
}

bool SrvSetWeight::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(char_id)) {
        return false;
    }
    if (!writer.set_uint8_t(weight)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetWeight::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // char_id
    size += sizeof(uint8_t); // weight
    return size;
}

