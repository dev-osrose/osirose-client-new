#include "srv_shop_list_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvShopListReply::Header& SrvShopListReply::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvShopListReply::Header::get_type() const {
    return data.type;
}

SrvShopListReply::Header& SrvShopListReply::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvShopListReply::Header::get_id() const {
    return data.id;
}

SrvShopListReply::Header& SrvShopListReply::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvShopListReply::Header::get_isCreated() const {
    return data.isCreated;
}

SrvShopListReply::Header& SrvShopListReply::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvShopListReply::Header::get_header() const {
    return data.header;
}

bool SrvShopListReply::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvShopListReply::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShopListReply::Header::size() {
    return sizeof(data);
}

SrvShopListReply::Data& SrvShopListReply::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvShopListReply::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvShopListReply::Data& SrvShopListReply::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvShopListReply::Data::get_durability() const {
    return data.durability;
}

SrvShopListReply::Data& SrvShopListReply::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvShopListReply::Data::get_life() const {
    return data.life;
}

SrvShopListReply::Data& SrvShopListReply::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvShopListReply::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvShopListReply::Data& SrvShopListReply::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvShopListReply::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvShopListReply::Data& SrvShopListReply::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvShopListReply::Data::get_refine() const {
    return data.refine;
}

SrvShopListReply::Data& SrvShopListReply::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvShopListReply::Data::get_count() const {
    return data.count;
}

bool SrvShopListReply::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvShopListReply::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShopListReply::Data::size() {
    return sizeof(data);
}

SrvShopListReply::Item& SrvShopListReply::Item::set_header(const SrvShopListReply::Header header) {
    this->header = header;
    return *this;
}

SrvShopListReply::Header SrvShopListReply::Item::get_header() const {
    return header;
}

SrvShopListReply::Item& SrvShopListReply::Item::set_data(const SrvShopListReply::Data data) {
    this->data = data;
    return *this;
}

SrvShopListReply::Data SrvShopListReply::Item::get_data() const {
    return data;
}

bool SrvShopListReply::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvShopListReply::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShopListReply::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}

SrvShopListReply::ShopListItem& SrvShopListReply::ShopListItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t SrvShopListReply::ShopListItem::get_index() const {
    return index;
}

SrvShopListReply::ShopListItem& SrvShopListReply::ShopListItem::set_item(const SrvShopListReply::Item item) {
    this->item = item;
    return *this;
}

SrvShopListReply::Item SrvShopListReply::ShopListItem::get_item() const {
    return item;
}

SrvShopListReply::ShopListItem& SrvShopListReply::ShopListItem::set_price(const uint32_t price) {
    this->price = price;
    return *this;
}

uint32_t SrvShopListReply::ShopListItem::get_price() const {
    return price;
}

bool SrvShopListReply::ShopListItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    if (!writer.set_uint32_t(price)) {
        return false;
    }
    return true;
}

bool SrvShopListReply::ShopListItem::read(CRoseReader& reader) {
    if (!reader.get_uint8_t(index)) {
        return false;
    }
    if (!reader.get_iserialize(item)) {
        return false;
    }
    if (!reader.get_uint32_t(price)) {
        return false;
    }
    return true;
}

constexpr size_t SrvShopListReply::ShopListItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // index
    size += Item::size(); // item
    size += sizeof(uint32_t); // price
    return size;
}


SrvShopListReply::SrvShopListReply() : CRosePacket(SrvShopListReply::PACKET_ID) {}

SrvShopListReply::SrvShopListReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(sell_count)) {
        return;
    }
    if (!reader.get_uint8_t(wishlist_count)) {
        return;
    }
    {
        SrvShopListReply::ShopListItem elem;
        while (reader.get_iserialize(elem)) {
            items.push_back(elem);
        }
    }
}

SrvShopListReply& SrvShopListReply::set_sell_count(const uint8_t sell_count) {
    this->sell_count = sell_count;
    return *this;
}

uint8_t SrvShopListReply::get_sell_count() const {
    return sell_count;
}

SrvShopListReply& SrvShopListReply::set_wishlist_count(const uint8_t wishlist_count) {
    this->wishlist_count = wishlist_count;
    return *this;
}

uint8_t SrvShopListReply::get_wishlist_count() const {
    return wishlist_count;
}

SrvShopListReply& SrvShopListReply::set_items(const std::vector<SrvShopListReply::ShopListItem>& items) {
    this->items = items;
    return *this;
}

SrvShopListReply& SrvShopListReply::add_items(const ShopListItem& items) {
    this->items.emplace_back(items);
    return *this;
}

const std::vector<SrvShopListReply::ShopListItem>& SrvShopListReply::get_items() const {
    return items;
}

const SrvShopListReply::ShopListItem& SrvShopListReply::get_items(size_t index) const {
    return items[index];
}

SrvShopListReply SrvShopListReply::create(const uint8_t& sell_count, const uint8_t& wishlist_count) {
    SrvShopListReply packet;
    packet.set_sell_count(sell_count);
    packet.set_wishlist_count(wishlist_count);
    return packet;
}

SrvShopListReply SrvShopListReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvShopListReply(reader);
}

std::unique_ptr<SrvShopListReply> SrvShopListReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvShopListReply>(reader);
}

bool SrvShopListReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(sell_count)) {
        return false;
    }
    if (!writer.set_uint8_t(wishlist_count)) {
        return false;
    }
    for (const auto& elem : items) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvShopListReply::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // sell_count
    size += sizeof(uint8_t); // wishlist_count
    size += ShopListItem::size(); // items
    return size;
}

