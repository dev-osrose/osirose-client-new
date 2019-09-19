#include "cli_damage.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliDamage::CliDamage() : CRosePacket(CliDamage::PACKET_ID) {}

CliDamage::CliDamage(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(targetId)) {
        return;
    }
    if (!reader.get_uint16_t(_randomId)) {
        return;
    }
}

CliDamage& CliDamage::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t CliDamage::get_targetId() const {
    return targetId;
}

CliDamage& CliDamage::set__randomId(const uint16_t _randomId) {
    this->_randomId = _randomId;
    return *this;
}

uint16_t CliDamage::get__randomId() const {
    return _randomId;
}

CliDamage CliDamage::create() {
    CliDamage packet;
    return packet;
}

CliDamage CliDamage::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliDamage(reader);
}

std::unique_ptr<CliDamage> CliDamage::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliDamage>(reader);
}

bool CliDamage::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(targetId)) {
        return false;
    }
    if (!writer.set_uint16_t(_randomId)) {
        return false;
    }
    return true;
}

constexpr size_t CliDamage::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // targetId
    size += sizeof(uint16_t); // _randomId
    return size;
}

