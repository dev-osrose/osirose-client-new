#include "srv_npc_show.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvNpcShow::SrvNpcShow() : CRosePacket(SrvNpcShow::PACKET_ID) {}

SrvNpcShow::SrvNpcShow(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_uint8_t(show)) {
        return;
    }
}

SrvNpcShow& SrvNpcShow::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvNpcShow::get_id() const {
    return id;
}

SrvNpcShow& SrvNpcShow::set_show(const uint8_t show) {
    this->show = show;
    return *this;
}

uint8_t SrvNpcShow::get_show() const {
    return show;
}

SrvNpcShow SrvNpcShow::create(const uint16_t& id, const uint8_t& show) {
    SrvNpcShow packet;
    packet.set_id(id);
    packet.set_show(show);
    return packet;
}

SrvNpcShow SrvNpcShow::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvNpcShow(reader);
}

std::unique_ptr<SrvNpcShow> SrvNpcShow::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvNpcShow>(reader);
}

bool SrvNpcShow::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint8_t(show)) {
        return false;
    }
    return true;
}

constexpr size_t SrvNpcShow::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(uint8_t); // show
    return size;
}

