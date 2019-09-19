#include "srv_skill_damage.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvSkillDamage::Header& SrvSkillDamage::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvSkillDamage::Header::get_type() const {
    return data.type;
}

SrvSkillDamage::Header& SrvSkillDamage::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvSkillDamage::Header::get_id() const {
    return data.id;
}

SrvSkillDamage::Header& SrvSkillDamage::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvSkillDamage::Header::get_isCreated() const {
    return data.isCreated;
}

SrvSkillDamage::Header& SrvSkillDamage::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvSkillDamage::Header::get_header() const {
    return data.header;
}

bool SrvSkillDamage::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvSkillDamage::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillDamage::Header::size() {
    return sizeof(data);
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvSkillDamage::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvSkillDamage::Data::get_durability() const {
    return data.durability;
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvSkillDamage::Data::get_life() const {
    return data.life;
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvSkillDamage::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvSkillDamage::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvSkillDamage::Data::get_refine() const {
    return data.refine;
}

SrvSkillDamage::Data& SrvSkillDamage::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvSkillDamage::Data::get_count() const {
    return data.count;
}

bool SrvSkillDamage::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvSkillDamage::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillDamage::Data::size() {
    return sizeof(data);
}

SrvSkillDamage::Item& SrvSkillDamage::Item::set_header(const SrvSkillDamage::Header header) {
    this->header = header;
    return *this;
}

SrvSkillDamage::Header SrvSkillDamage::Item::get_header() const {
    return header;
}

SrvSkillDamage::Item& SrvSkillDamage::Item::set_data(const SrvSkillDamage::Data data) {
    this->data = data;
    return *this;
}

SrvSkillDamage::Data SrvSkillDamage::Item::get_data() const {
    return data;
}

bool SrvSkillDamage::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvSkillDamage::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillDamage::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvSkillDamage::SrvSkillDamage() : CRosePacket(SrvSkillDamage::PACKET_ID) {}

SrvSkillDamage::SrvSkillDamage(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_uint16_t(source)) {
        return;
    }
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_float(amount)) {
        return;
    }
    if (!reader.get_uint8_t(state)) {
        return;
    }
    if (!reader.get_uint32_t(damage)) {
        return;
    }
    if (!reader.get_uint32_t(action)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

SrvSkillDamage& SrvSkillDamage::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvSkillDamage::get_target() const {
    return target;
}

SrvSkillDamage& SrvSkillDamage::set_source(const uint16_t source) {
    this->source = source;
    return *this;
}

uint16_t SrvSkillDamage::get_source() const {
    return source;
}

SrvSkillDamage& SrvSkillDamage::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvSkillDamage::get_id() const {
    return id;
}

SrvSkillDamage& SrvSkillDamage::set_amount(const float amount) {
    this->amount = amount;
    return *this;
}

float SrvSkillDamage::get_amount() const {
    return amount;
}

SrvSkillDamage& SrvSkillDamage::set_state(const uint8_t state) {
    this->state = state;
    return *this;
}

uint8_t SrvSkillDamage::get_state() const {
    return state;
}

SrvSkillDamage& SrvSkillDamage::set_damage(const uint32_t damage) {
    this->damage = damage;
    return *this;
}

uint32_t SrvSkillDamage::get_damage() const {
    return damage;
}

SrvSkillDamage& SrvSkillDamage::set_action(const uint32_t action) {
    this->action = action;
    return *this;
}

uint32_t SrvSkillDamage::get_action() const {
    return action;
}

SrvSkillDamage& SrvSkillDamage::set_item(const SrvSkillDamage::Item item) {
    this->item = item;
    return *this;
}

SrvSkillDamage::Item SrvSkillDamage::get_item() const {
    return item;
}

SrvSkillDamage SrvSkillDamage::create(const uint16_t& target, const uint16_t& source, const uint16_t& id, const float& amount, const uint8_t& state, const uint32_t& damage, const uint32_t& action) {
    SrvSkillDamage packet;
    packet.set_target(target);
    packet.set_source(source);
    packet.set_id(id);
    packet.set_amount(amount);
    packet.set_state(state);
    packet.set_damage(damage);
    packet.set_action(action);
    return packet;
}

SrvSkillDamage SrvSkillDamage::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSkillDamage(reader);
}

std::unique_ptr<SrvSkillDamage> SrvSkillDamage::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSkillDamage>(reader);
}

bool SrvSkillDamage::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_uint16_t(source)) {
        return false;
    }
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_float(amount)) {
        return false;
    }
    if (!writer.set_uint8_t(state)) {
        return false;
    }
    if (!writer.set_uint32_t(damage)) {
        return false;
    }
    if (!writer.set_uint32_t(action)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSkillDamage::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += sizeof(uint16_t); // source
    size += sizeof(uint16_t); // id
    size += sizeof(float); // amount
    size += sizeof(uint8_t); // state
    size += sizeof(uint32_t); // damage
    size += sizeof(uint32_t); // action
    size += Item::size(); // item
    return size;
}

