#include "cli_shop_open.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


CliShopOpen::Header& CliShopOpen::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int CliShopOpen::Header::get_type() const {
    return data.type;
}

CliShopOpen::Header& CliShopOpen::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int CliShopOpen::Header::get_id() const {
    return data.id;
}

CliShopOpen::Header& CliShopOpen::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int CliShopOpen::Header::get_isCreated() const {
    return data.isCreated;
}

CliShopOpen::Header& CliShopOpen::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t CliShopOpen::Header::get_header() const {
    return data.header;
}

bool CliShopOpen::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool CliShopOpen::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t CliShopOpen::Header::size() {
    return sizeof(data);
}

CliShopOpen::Data& CliShopOpen::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int CliShopOpen::Data::get_gem_opt() const {
    return data.gem_opt;
}

CliShopOpen::Data& CliShopOpen::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int CliShopOpen::Data::get_durability() const {
    return data.durability;
}

CliShopOpen::Data& CliShopOpen::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int CliShopOpen::Data::get_life() const {
    return data.life;
}

CliShopOpen::Data& CliShopOpen::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int CliShopOpen::Data::get_hasSocket() const {
    return data.hasSocket;
}

CliShopOpen::Data& CliShopOpen::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int CliShopOpen::Data::get_isAppraised() const {
    return data.isAppraised;
}

CliShopOpen::Data& CliShopOpen::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int CliShopOpen::Data::get_refine() const {
    return data.refine;
}

CliShopOpen::Data& CliShopOpen::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t CliShopOpen::Data::get_count() const {
    return data.count;
}

bool CliShopOpen::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool CliShopOpen::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t CliShopOpen::Data::size() {
    return sizeof(data);
}

CliShopOpen::Item& CliShopOpen::Item::set_header(const CliShopOpen::Header header) {
    this->header = header;
    return *this;
}

CliShopOpen::Header CliShopOpen::Item::get_header() const {
    return header;
}

CliShopOpen::Item& CliShopOpen::Item::set_data(const CliShopOpen::Data data) {
    this->data = data;
    return *this;
}

CliShopOpen::Data CliShopOpen::Item::get_data() const {
    return data;
}

bool CliShopOpen::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool CliShopOpen::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t CliShopOpen::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}

CliShopOpen::ShopItem& CliShopOpen::ShopItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t CliShopOpen::ShopItem::get_index() const {
    return index;
}

CliShopOpen::ShopItem& CliShopOpen::ShopItem::set_item(const CliShopOpen::Item item) {
    this->item = item;
    return *this;
}

CliShopOpen::Item CliShopOpen::ShopItem::get_item() const {
    return item;
}

CliShopOpen::ShopItem& CliShopOpen::ShopItem::set_price(const uint32_t price) {
    this->price = price;
    return *this;
}

uint32_t CliShopOpen::ShopItem::get_price() const {
    return price;
}

bool CliShopOpen::ShopItem::write(CRoseBasePolicy& writer) const {
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

bool CliShopOpen::ShopItem::read(CRoseReader& reader) {
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

constexpr size_t CliShopOpen::ShopItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // index
    size += Item::size(); // item
    size += sizeof(uint32_t); // price
    return size;
}


CliShopOpen::CliShopOpen() : CRosePacket(CliShopOpen::PACKET_ID) {}

CliShopOpen::CliShopOpen(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(sell_count)) {
        return;
    }
    if (!reader.get_uint8_t(wishlist_count)) {
        return;
    }
    {
        CliShopOpen::ShopItem elem;
        while (reader.get_iserialize(elem)) {
            items.push_back(elem);
        }
    }
}

CliShopOpen& CliShopOpen::set_sell_count(const uint8_t sell_count) {
    this->sell_count = sell_count;
    return *this;
}

uint8_t CliShopOpen::get_sell_count() const {
    return sell_count;
}

CliShopOpen& CliShopOpen::set_wishlist_count(const uint8_t wishlist_count) {
    this->wishlist_count = wishlist_count;
    return *this;
}

uint8_t CliShopOpen::get_wishlist_count() const {
    return wishlist_count;
}

CliShopOpen& CliShopOpen::set_items(const std::vector<CliShopOpen::ShopItem>& items) {
    this->items = items;
    return *this;
}

CliShopOpen& CliShopOpen::add_items(const ShopItem& items) {
    this->items.emplace_back(items);
    return *this;
}

const std::vector<CliShopOpen::ShopItem>& CliShopOpen::get_items() const {
    return items;
}

const CliShopOpen::ShopItem& CliShopOpen::get_items(size_t index) const {
    return items[index];
}

CliShopOpen CliShopOpen::create(const uint8_t& sell_count, const uint8_t& wishlist_count) {
    CliShopOpen packet;
    packet.set_sell_count(sell_count);
    packet.set_wishlist_count(wishlist_count);
    return packet;
}

CliShopOpen CliShopOpen::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliShopOpen(reader);
}

std::unique_ptr<CliShopOpen> CliShopOpen::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliShopOpen>(reader);
}

bool CliShopOpen::pack(CRoseBasePolicy& writer) const {
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

constexpr size_t CliShopOpen::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // sell_count
    size += sizeof(uint8_t); // wishlist_count
    size += ShopItem::size(); // items
    return size;
}

