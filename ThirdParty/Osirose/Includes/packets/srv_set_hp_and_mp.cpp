#include "srv_set_hp_and_mp.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetHpAndMp::SrvSetHpAndMp() : CRosePacket(SrvSetHpAndMp::PACKET_ID) {}

SrvSetHpAndMp::SrvSetHpAndMp(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_int32_t(hp)) {
        return;
    }
    if (!reader.get_int32_t(mp)) {
        return;
    }
}

SrvSetHpAndMp& SrvSetHpAndMp::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvSetHpAndMp::get_id() const {
    return id;
}

SrvSetHpAndMp& SrvSetHpAndMp::set_hp(const int32_t hp) {
    this->hp = hp;
    return *this;
}

int32_t SrvSetHpAndMp::get_hp() const {
    return hp;
}

SrvSetHpAndMp& SrvSetHpAndMp::set_mp(const int32_t mp) {
    this->mp = mp;
    return *this;
}

int32_t SrvSetHpAndMp::get_mp() const {
    return mp;
}

SrvSetHpAndMp SrvSetHpAndMp::create(const uint16_t& id, const int32_t& hp, const int32_t& mp) {
    SrvSetHpAndMp packet;
    packet.set_id(id);
    packet.set_hp(hp);
    packet.set_mp(mp);
    return packet;
}

SrvSetHpAndMp SrvSetHpAndMp::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetHpAndMp(reader);
}

std::unique_ptr<SrvSetHpAndMp> SrvSetHpAndMp::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetHpAndMp>(reader);
}

bool SrvSetHpAndMp::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_int32_t(hp)) {
        return false;
    }
    if (!writer.set_int32_t(mp)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetHpAndMp::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(int32_t); // hp
    size += sizeof(int32_t); // mp
    return size;
}

