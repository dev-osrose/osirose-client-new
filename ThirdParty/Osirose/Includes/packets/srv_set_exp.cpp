#include "srv_set_exp.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvSetExp::SrvSetExp() : CRosePacket(SrvSetExp::PACKET_ID) {}

SrvSetExp::SrvSetExp(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int64_t(exp)) {
        return;
    }
    if (!reader.get_int16_t(stamina)) {
        return;
    }
    if (!reader.get_uint16_t(source_id)) {
        return;
    }
}

SrvSetExp& SrvSetExp::set_exp(const int64_t exp) {
    this->exp = exp;
    return *this;
}

int64_t SrvSetExp::get_exp() const {
    return exp;
}

SrvSetExp& SrvSetExp::set_stamina(const int16_t stamina) {
    this->stamina = stamina;
    return *this;
}

int16_t SrvSetExp::get_stamina() const {
    return stamina;
}

SrvSetExp& SrvSetExp::set_source_id(const uint16_t source_id) {
    this->source_id = source_id;
    return *this;
}

uint16_t SrvSetExp::get_source_id() const {
    return source_id;
}

SrvSetExp SrvSetExp::create(const int64_t& exp, const int16_t& stamina) {
    SrvSetExp packet;
    packet.set_exp(exp);
    packet.set_stamina(stamina);
    return packet;
}

SrvSetExp SrvSetExp::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetExp(reader);
}

std::unique_ptr<SrvSetExp> SrvSetExp::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetExp>(reader);
}

bool SrvSetExp::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int64_t(exp)) {
        return false;
    }
    if (!writer.set_int16_t(stamina)) {
        return false;
    }
    if (!writer.set_uint16_t(source_id)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetExp::size() {
    size_t size = 0;
    size += sizeof(int64_t); // exp
    size += sizeof(int16_t); // stamina
    size += sizeof(uint16_t); // source_id
    return size;
}

