#include "srv_npc_event.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvNpcEvent::SrvNpcEvent() : CRosePacket(SrvNpcEvent::PACKET_ID) {}

SrvNpcEvent::SrvNpcEvent(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int16_t(id)) {
        return;
    }
}

SrvNpcEvent& SrvNpcEvent::set_id(const int16_t id) {
    this->id = id;
    return *this;
}

int16_t SrvNpcEvent::get_id() const {
    return id;
}

SrvNpcEvent SrvNpcEvent::create(const int16_t& id) {
    SrvNpcEvent packet;
    packet.set_id(id);
    return packet;
}

SrvNpcEvent SrvNpcEvent::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvNpcEvent(reader);
}

std::unique_ptr<SrvNpcEvent> SrvNpcEvent::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvNpcEvent>(reader);
}

bool SrvNpcEvent::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int16_t(id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvNpcEvent::size() {
    size_t size = 0;
    size += sizeof(int16_t); // id
    return size;
}

