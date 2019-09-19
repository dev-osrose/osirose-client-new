#include "srv_set_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvSetItem::Header& SrvSetItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvSetItem::Header::get_type() const {
    return data.type;
}

SrvSetItem::Header& SrvSetItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvSetItem::Header::get_id() const {
    return data.id;
}

SrvSetItem::Header& SrvSetItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvSetItem::Header::get_isCreated() const {
    return data.isCreated;
}

SrvSetItem::Header& SrvSetItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvSetItem::Header::get_header() const {
    return data.header;
}

bool SrvSetItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvSetItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetItem::Header::size() {
    return sizeof(data);
}

SrvSetItem::Data& SrvSetItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvSetItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvSetItem::Data& SrvSetItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvSetItem::Data::get_durability() const {
    return data.durability;
}

SrvSetItem::Data& SrvSetItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvSetItem::Data::get_life() const {
    return data.life;
}

SrvSetItem::Data& SrvSetItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvSetItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvSetItem::Data& SrvSetItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvSetItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvSetItem::Data& SrvSetItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvSetItem::Data::get_refine() const {
    return data.refine;
}

SrvSetItem::Data& SrvSetItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvSetItem::Data::get_count() const {
    return data.count;
}

bool SrvSetItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvSetItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetItem::Data::size() {
    return sizeof(data);
}

SrvSetItem::Item& SrvSetItem::Item::set_header(const SrvSetItem::Header header) {
    this->header = header;
    return *this;
}

SrvSetItem::Header SrvSetItem::Item::get_header() const {
    return header;
}

SrvSetItem::Item& SrvSetItem::Item::set_data(const SrvSetItem::Data data) {
    this->data = data;
    return *this;
}

SrvSetItem::Data SrvSetItem::Item::get_data() const {
    return data;
}

bool SrvSetItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvSetItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}

SrvSetItem::IndexAndItem& SrvSetItem::IndexAndItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t SrvSetItem::IndexAndItem::get_index() const {
    return index;
}

SrvSetItem::IndexAndItem& SrvSetItem::IndexAndItem::set_item(const SrvSetItem::Item item) {
    this->item = item;
    return *this;
}

SrvSetItem::Item SrvSetItem::IndexAndItem::get_item() const {
    return item;
}

bool SrvSetItem::IndexAndItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

bool SrvSetItem::IndexAndItem::read(CRoseReader& reader) {
    if (!reader.get_uint8_t(index)) {
        return false;
    }
    if (!reader.get_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSetItem::IndexAndItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // index
    size += Item::size(); // item
    return size;
}


SrvSetItem::SrvSetItem() : CRosePacket(SrvSetItem::PACKET_ID) {}

SrvSetItem::SrvSetItem(CRoseReader reader) : CRosePacket(reader) {
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            SrvSetItem::IndexAndItem elem;
            if (!reader.get_iserialize(elem)) {
                return;
            }
            items.push_back(elem);
        }
    }
}

SrvSetItem& SrvSetItem::set_items(const std::vector<SrvSetItem::IndexAndItem> items) {
    this->items = items;
    return *this;
}

SrvSetItem& SrvSetItem::add_items(const IndexAndItem items) {
    this->items.emplace_back(items);
    return *this;
}

std::vector<SrvSetItem::IndexAndItem> SrvSetItem::get_items() const {
    return items;
}

SrvSetItem::IndexAndItem SrvSetItem::get_items(size_t index) const {
    return items[index];
}

SrvSetItem SrvSetItem::create() {
    SrvSetItem packet;
    return packet;
}

SrvSetItem SrvSetItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSetItem(reader);
}

std::unique_ptr<SrvSetItem> SrvSetItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSetItem>(reader);
}

bool SrvSetItem::pack(CRoseBasePolicy& writer) const {
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

constexpr size_t SrvSetItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // items
    size += IndexAndItem::size(); // items
    return size;
}

