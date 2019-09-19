#include "srv_party_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvPartyItem::Header& SrvPartyItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvPartyItem::Header::get_type() const {
    return data.type;
}

SrvPartyItem::Header& SrvPartyItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvPartyItem::Header::get_id() const {
    return data.id;
}

SrvPartyItem::Header& SrvPartyItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvPartyItem::Header::get_isCreated() const {
    return data.isCreated;
}

SrvPartyItem::Header& SrvPartyItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvPartyItem::Header::get_header() const {
    return data.header;
}

bool SrvPartyItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvPartyItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyItem::Header::size() {
    return sizeof(data);
}

SrvPartyItem::Data& SrvPartyItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvPartyItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvPartyItem::Data& SrvPartyItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvPartyItem::Data::get_durability() const {
    return data.durability;
}

SrvPartyItem::Data& SrvPartyItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvPartyItem::Data::get_life() const {
    return data.life;
}

SrvPartyItem::Data& SrvPartyItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvPartyItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvPartyItem::Data& SrvPartyItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvPartyItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvPartyItem::Data& SrvPartyItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvPartyItem::Data::get_refine() const {
    return data.refine;
}

SrvPartyItem::Data& SrvPartyItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvPartyItem::Data::get_count() const {
    return data.count;
}

bool SrvPartyItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvPartyItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyItem::Data::size() {
    return sizeof(data);
}

SrvPartyItem::Item& SrvPartyItem::Item::set_header(const SrvPartyItem::Header header) {
    this->header = header;
    return *this;
}

SrvPartyItem::Header SrvPartyItem::Item::get_header() const {
    return header;
}

SrvPartyItem::Item& SrvPartyItem::Item::set_data(const SrvPartyItem::Data data) {
    this->data = data;
    return *this;
}

SrvPartyItem::Data SrvPartyItem::Item::get_data() const {
    return data;
}

bool SrvPartyItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvPartyItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvPartyItem::SrvPartyItem() : CRosePacket(SrvPartyItem::PACKET_ID) {}

SrvPartyItem::SrvPartyItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(target)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

SrvPartyItem& SrvPartyItem::set_target(const uint16_t target) {
    this->target = target;
    return *this;
}

uint16_t SrvPartyItem::get_target() const {
    return target;
}

SrvPartyItem& SrvPartyItem::set_item(const SrvPartyItem::Item item) {
    this->item = item;
    return *this;
}

SrvPartyItem::Item SrvPartyItem::get_item() const {
    return item;
}

SrvPartyItem SrvPartyItem::create(const uint16_t& target, const SrvPartyItem::Item& item) {
    SrvPartyItem packet;
    packet.set_target(target);
    packet.set_item(item);
    return packet;
}

SrvPartyItem SrvPartyItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPartyItem(reader);
}

std::unique_ptr<SrvPartyItem> SrvPartyItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPartyItem>(reader);
}

bool SrvPartyItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(target)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPartyItem::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // target
    size += Item::size(); // item
    return size;
}

