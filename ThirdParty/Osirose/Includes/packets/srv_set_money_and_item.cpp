#include "srv_set_money_and_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvSetMoneyAndItem::Header& SrvSetMoneyAndItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Header::get_type() const {
    return data.type;
}

SrvSetMoneyAndItem::Header& SrvSetMoneyAndItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Header::get_id() const {
    return data.id;
}

SrvSetMoneyAndItem::Header& SrvSetMoneyAndItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Header::get_isCreated() const {
    return data.isCreated;
}

SrvSetMoneyAndItem::Header& SrvSetMoneyAndItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvSetMoneyAndItem::Header::get_header() const {
    return data.header;
}

bool SrvSetMoneyAndItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvSetMoneyAndItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetMoneyAndItem::Header::size() {
    return sizeof(data);
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Data::get_durability() const {
    return data.durability;
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Data::get_life() const {
    return data.life;
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvSetMoneyAndItem::Data::get_refine() const {
    return data.refine;
}

SrvSetMoneyAndItem::Data& SrvSetMoneyAndItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvSetMoneyAndItem::Data::get_count() const {
    return data.count;
}

bool SrvSetMoneyAndItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvSetMoneyAndItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetMoneyAndItem::Data::size() {
    return sizeof(data);
}

SrvSetMoneyAndItem::Item& SrvSetMoneyAndItem::Item::set_header(const SrvSetMoneyAndItem::Header header) {
    this->header = header;
    return *this;
}

SrvSetMoneyAndItem::Header SrvSetMoneyAndItem::Item::get_header() const {
    return header;
}

SrvSetMoneyAndItem::Item& SrvSetMoneyAndItem::Item::set_data(const SrvSetMoneyAndItem::Data data) {
    this->data = data;
    return *this;
}

SrvSetMoneyAndItem::Data SrvSetMoneyAndItem::Item::get_data() const {
    return data;
}

bool SrvSetMoneyAndItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvSetMoneyAndItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetMoneyAndItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}

SrvSetMoneyAndItem::IndexAndItem& SrvSetMoneyAndItem::IndexAndItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t SrvSetMoneyAndItem::IndexAndItem::get_index() const {
    return index;
}

SrvSetMoneyAndItem::IndexAndItem& SrvSetMoneyAndItem::IndexAndItem::set_item(const SrvSetMoneyAndItem::Item item) {
    this->item = item;
    return *this;
}

SrvSetMoneyAndItem::Item SrvSetMoneyAndItem::IndexAndItem::get_item() const {
    return item;
}

bool SrvSetMoneyAndItem::IndexAndItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

bool SrvSetMoneyAndItem::IndexAndItem::read(CRoseReader& reader) {
    if (!reader.get_uint8_t(index)) {
        return false;
    }
    if (!reader.get_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetMoneyAndItem::IndexAndItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // index
    size += Item::size(); // item
    return size;
}


SrvSetMoneyAndItem::SrvSetMoneyAndItem() : CRosePacket(SrvSetMoneyAndItem::PACKET_ID) {}

SrvSetMoneyAndItem::SrvSetMoneyAndItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int64_t(zuly)) {
        return;
    }
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            SrvSetMoneyAndItem::IndexAndItem elem;
            if (!reader.get_iserialize(elem)) {
                return;
            }
            items.push_back(elem);
        }
    }
}

SrvSetMoneyAndItem& SrvSetMoneyAndItem::set_zuly(const int64_t zuly) {
    this->zuly = zuly;
    return *this;
}

int64_t SrvSetMoneyAndItem::get_zuly() const {
    return zuly;
}

SrvSetMoneyAndItem& SrvSetMoneyAndItem::set_items(const std::vector<SrvSetMoneyAndItem::IndexAndItem> items) {
    this->items = items;
    return *this;
}

SrvSetMoneyAndItem& SrvSetMoneyAndItem::add_items(const IndexAndItem items) {
    this->items.emplace_back(items);
    return *this;
}

std::vector<SrvSetMoneyAndItem::IndexAndItem> SrvSetMoneyAndItem::get_items() const {
    return items;
}

SrvSetMoneyAndItem::IndexAndItem SrvSetMoneyAndItem::get_items(size_t index) const {
    return items[index];
}

SrvSetMoneyAndItem SrvSetMoneyAndItem::create(const int64_t& zuly) {
    SrvSetMoneyAndItem packet;
    packet.set_zuly(zuly);
    return packet;
}

SrvSetMoneyAndItem SrvSetMoneyAndItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetMoneyAndItem(reader);
}

std::unique_ptr<SrvSetMoneyAndItem> SrvSetMoneyAndItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetMoneyAndItem>(reader);
}

bool SrvSetMoneyAndItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int64_t(zuly)) {
        return false;
    }
    if (!writer.set_uint8_t(items.size())) {
        return false;
    }
    for (const auto& elem : items) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvSetMoneyAndItem::size() {
    size_t size = 0;
    size += sizeof(int64_t); // zuly
    size += sizeof(uint8_t); // items
    size += IndexAndItem::size(); // items
    return size;
}

