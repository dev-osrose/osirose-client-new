#include "srv_drop_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvDropItem::Header& SrvDropItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvDropItem::Header::get_type() const {
    return data.type;
}

SrvDropItem::Header& SrvDropItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvDropItem::Header::get_id() const {
    return data.id;
}

SrvDropItem::Header& SrvDropItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvDropItem::Header::get_isCreated() const {
    return data.isCreated;
}

SrvDropItem::Header& SrvDropItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvDropItem::Header::get_header() const {
    return data.header;
}

bool SrvDropItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvDropItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDropItem::Header::size() {
    return sizeof(data);
}

SrvDropItem::Data& SrvDropItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvDropItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvDropItem::Data& SrvDropItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvDropItem::Data::get_durability() const {
    return data.durability;
}

SrvDropItem::Data& SrvDropItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvDropItem::Data::get_life() const {
    return data.life;
}

SrvDropItem::Data& SrvDropItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvDropItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvDropItem::Data& SrvDropItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvDropItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvDropItem::Data& SrvDropItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvDropItem::Data::get_refine() const {
    return data.refine;
}

SrvDropItem::Data& SrvDropItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvDropItem::Data::get_count() const {
    return data.count;
}

bool SrvDropItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvDropItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDropItem::Data::size() {
    return sizeof(data);
}

SrvDropItem::Item& SrvDropItem::Item::set_header(const SrvDropItem::Header header) {
    this->header = header;
    return *this;
}

SrvDropItem::Header SrvDropItem::Item::get_header() const {
    return header;
}

SrvDropItem::Item& SrvDropItem::Item::set_data(const SrvDropItem::Data data) {
    this->data = data;
    return *this;
}

SrvDropItem::Data SrvDropItem::Item::get_data() const {
    return data;
}

bool SrvDropItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvDropItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDropItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvDropItem::SrvDropItem() : CRosePacket(SrvDropItem::PACKET_ID) {}

SrvDropItem::SrvDropItem(CRoseReader reader) : CRosePacket(reader) {
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
    if (!reader.get_uint16_t(timeToLive)) {
        return;
    }
}

SrvDropItem& SrvDropItem::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvDropItem::get_x() const {
    return x;
}

SrvDropItem& SrvDropItem::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvDropItem::get_y() const {
    return y;
}

SrvDropItem& SrvDropItem::set_item(const SrvDropItem::Item item) {
    this->item = item;
    return *this;
}

SrvDropItem::Item SrvDropItem::get_item() const {
    return item;
}

SrvDropItem& SrvDropItem::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvDropItem::get_id() const {
    return id;
}

SrvDropItem& SrvDropItem::set_ownerId(const uint16_t ownerId) {
    this->ownerId = ownerId;
    return *this;
}

uint16_t SrvDropItem::get_ownerId() const {
    return ownerId;
}

SrvDropItem& SrvDropItem::set_timeToLive(const uint16_t timeToLive) {
    this->timeToLive = timeToLive;
    return *this;
}

uint16_t SrvDropItem::get_timeToLive() const {
    return timeToLive;
}

SrvDropItem SrvDropItem::create() {
    SrvDropItem packet;
    return packet;
}

SrvDropItem SrvDropItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvDropItem(reader);
}

std::unique_ptr<SrvDropItem> SrvDropItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvDropItem>(reader);
}

bool SrvDropItem::pack(CRoseBasePolicy& writer) const {
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
    if (!writer.set_uint16_t(timeToLive)) {
        return false;
    }
    return true;
}

constexpr size_t SrvDropItem::size() {
    size_t size = 0;
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += Item::size(); // item
    size += sizeof(uint16_t); // id
    size += sizeof(uint16_t); // ownerId
    size += sizeof(uint16_t); // timeToLive
    return size;
}

