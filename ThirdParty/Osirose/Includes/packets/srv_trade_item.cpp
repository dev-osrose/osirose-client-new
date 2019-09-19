#include "srv_trade_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvTradeItem::Header& SrvTradeItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvTradeItem::Header::get_type() const {
    return data.type;
}

SrvTradeItem::Header& SrvTradeItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvTradeItem::Header::get_id() const {
    return data.id;
}

SrvTradeItem::Header& SrvTradeItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvTradeItem::Header::get_isCreated() const {
    return data.isCreated;
}

SrvTradeItem::Header& SrvTradeItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvTradeItem::Header::get_header() const {
    return data.header;
}

bool SrvTradeItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvTradeItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvTradeItem::Header::size() {
    return sizeof(data);
}

SrvTradeItem::Data& SrvTradeItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvTradeItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvTradeItem::Data& SrvTradeItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvTradeItem::Data::get_durability() const {
    return data.durability;
}

SrvTradeItem::Data& SrvTradeItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvTradeItem::Data::get_life() const {
    return data.life;
}

SrvTradeItem::Data& SrvTradeItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvTradeItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvTradeItem::Data& SrvTradeItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvTradeItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvTradeItem::Data& SrvTradeItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvTradeItem::Data::get_refine() const {
    return data.refine;
}

SrvTradeItem::Data& SrvTradeItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvTradeItem::Data::get_count() const {
    return data.count;
}

bool SrvTradeItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvTradeItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvTradeItem::Data::size() {
    return sizeof(data);
}

SrvTradeItem::Item& SrvTradeItem::Item::set_header(const SrvTradeItem::Header header) {
    this->header = header;
    return *this;
}

SrvTradeItem::Header SrvTradeItem::Item::get_header() const {
    return header;
}

SrvTradeItem::Item& SrvTradeItem::Item::set_data(const SrvTradeItem::Data data) {
    this->data = data;
    return *this;
}

SrvTradeItem::Data SrvTradeItem::Item::get_data() const {
    return data;
}

bool SrvTradeItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvTradeItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvTradeItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvTradeItem::SrvTradeItem() : CRosePacket(SrvTradeItem::PACKET_ID) {}

SrvTradeItem::SrvTradeItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(slot)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

SrvTradeItem& SrvTradeItem::set_slot(const uint8_t slot) {
    this->slot = slot;
    return *this;
}

uint8_t SrvTradeItem::get_slot() const {
    return slot;
}

SrvTradeItem& SrvTradeItem::set_item(const SrvTradeItem::Item item) {
    this->item = item;
    return *this;
}

SrvTradeItem::Item SrvTradeItem::get_item() const {
    return item;
}

SrvTradeItem SrvTradeItem::create(const uint8_t& slot, const SrvTradeItem::Item& item) {
    SrvTradeItem packet;
    packet.set_slot(slot);
    packet.set_item(item);
    return packet;
}

SrvTradeItem SrvTradeItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvTradeItem(reader);
}

std::unique_ptr<SrvTradeItem> SrvTradeItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvTradeItem>(reader);
}

bool SrvTradeItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(slot)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvTradeItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // slot
    size += Item::size(); // item
    return size;
}

