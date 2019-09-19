#include "srv_damage.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvDamage::Header& SrvDamage::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvDamage::Header::get_type() const {
    return data.type;
}

SrvDamage::Header& SrvDamage::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvDamage::Header::get_id() const {
    return data.id;
}

SrvDamage::Header& SrvDamage::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvDamage::Header::get_isCreated() const {
    return data.isCreated;
}

SrvDamage::Header& SrvDamage::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvDamage::Header::get_header() const {
    return data.header;
}

bool SrvDamage::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvDamage::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDamage::Header::size() {
    return sizeof(data);
}

SrvDamage::Data& SrvDamage::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvDamage::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvDamage::Data& SrvDamage::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvDamage::Data::get_durability() const {
    return data.durability;
}

SrvDamage::Data& SrvDamage::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvDamage::Data::get_life() const {
    return data.life;
}

SrvDamage::Data& SrvDamage::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvDamage::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvDamage::Data& SrvDamage::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvDamage::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvDamage::Data& SrvDamage::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvDamage::Data::get_refine() const {
    return data.refine;
}

SrvDamage::Data& SrvDamage::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvDamage::Data::get_count() const {
    return data.count;
}

bool SrvDamage::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvDamage::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDamage::Data::size() {
    return sizeof(data);
}

SrvDamage::Item& SrvDamage::Item::set_header(const SrvDamage::Header header) {
    this->header = header;
    return *this;
}

SrvDamage::Header SrvDamage::Item::get_header() const {
    return header;
}

SrvDamage::Item& SrvDamage::Item::set_data(const SrvDamage::Data data) {
    this->data = data;
    return *this;
}

SrvDamage::Data SrvDamage::Item::get_data() const {
    return data;
}

bool SrvDamage::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvDamage::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDamage::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvDamage::SrvDamage() : CRosePacket(SrvDamage::PACKET_ID) {}

SrvDamage::SrvDamage(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(attackerId)) {
        return;
    }
    if (!reader.get_uint16_t(defenderId)) {
        return;
    }
    if (!reader.get_uint32_t(damage)) {
        return;
    }
    if (!reader.get_uint32_t(action)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_uint16_t(ownerId)) {
        return;
    }
}

SrvDamage& SrvDamage::set_attackerId(const uint16_t attackerId) {
    this->attackerId = attackerId;
    return *this;
}

uint16_t SrvDamage::get_attackerId() const {
    return attackerId;
}

SrvDamage& SrvDamage::set_defenderId(const uint16_t defenderId) {
    this->defenderId = defenderId;
    return *this;
}

uint16_t SrvDamage::get_defenderId() const {
    return defenderId;
}

SrvDamage& SrvDamage::set_damage(const uint32_t damage) {
    this->damage = damage;
    return *this;
}

uint32_t SrvDamage::get_damage() const {
    return damage;
}

SrvDamage& SrvDamage::set_action(const uint32_t action) {
    this->action = action;
    return *this;
}

uint32_t SrvDamage::get_action() const {
    return action;
}

SrvDamage& SrvDamage::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvDamage::get_x() const {
    return x;
}

SrvDamage& SrvDamage::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvDamage::get_y() const {
    return y;
}

SrvDamage& SrvDamage::set_item(const SrvDamage::Item item) {
    this->item = item;
    return *this;
}

SrvDamage::Item SrvDamage::get_item() const {
    return item;
}

SrvDamage& SrvDamage::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvDamage::get_id() const {
    return id;
}

SrvDamage& SrvDamage::set_ownerId(const uint16_t ownerId) {
    this->ownerId = ownerId;
    return *this;
}

uint16_t SrvDamage::get_ownerId() const {
    return ownerId;
}

SrvDamage SrvDamage::create(const uint16_t& attackerId, const uint16_t& defenderId, const uint32_t& damage, const uint32_t& action) {
    SrvDamage packet;
    packet.set_attackerId(attackerId);
    packet.set_defenderId(defenderId);
    packet.set_damage(damage);
    packet.set_action(action);
    return packet;
}

SrvDamage SrvDamage::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvDamage(reader);
}

std::unique_ptr<SrvDamage> SrvDamage::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvDamage>(reader);
}

bool SrvDamage::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(attackerId)) {
        return false;
    }
    if (!writer.set_uint16_t(defenderId)) {
        return false;
    }
    if (!writer.set_uint32_t(damage)) {
        return false;
    }
    if (!writer.set_uint32_t(action)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint16_t(ownerId)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDamage::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // attackerId
    size += sizeof(uint16_t); // defenderId
    size += sizeof(uint32_t); // damage
    size += sizeof(uint32_t); // action
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += Item::size(); // item
    size += sizeof(uint16_t); // id
    size += sizeof(uint16_t); // ownerId
    return size;
}

