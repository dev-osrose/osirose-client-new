#include "srv_bank_move_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvBankMoveItem::Header& SrvBankMoveItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvBankMoveItem::Header::get_type() const {
    return data.type;
}

SrvBankMoveItem::Header& SrvBankMoveItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvBankMoveItem::Header::get_id() const {
    return data.id;
}

SrvBankMoveItem::Header& SrvBankMoveItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvBankMoveItem::Header::get_isCreated() const {
    return data.isCreated;
}

SrvBankMoveItem::Header& SrvBankMoveItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvBankMoveItem::Header::get_header() const {
    return data.header;
}

bool SrvBankMoveItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvBankMoveItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankMoveItem::Header::size() {
    return sizeof(data);
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvBankMoveItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvBankMoveItem::Data::get_durability() const {
    return data.durability;
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvBankMoveItem::Data::get_life() const {
    return data.life;
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvBankMoveItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvBankMoveItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvBankMoveItem::Data::get_refine() const {
    return data.refine;
}

SrvBankMoveItem::Data& SrvBankMoveItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvBankMoveItem::Data::get_count() const {
    return data.count;
}

bool SrvBankMoveItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvBankMoveItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankMoveItem::Data::size() {
    return sizeof(data);
}

SrvBankMoveItem::Item& SrvBankMoveItem::Item::set_header(const SrvBankMoveItem::Header header) {
    this->header = header;
    return *this;
}

SrvBankMoveItem::Header SrvBankMoveItem::Item::get_header() const {
    return header;
}

SrvBankMoveItem::Item& SrvBankMoveItem::Item::set_data(const SrvBankMoveItem::Data data) {
    this->data = data;
    return *this;
}

SrvBankMoveItem::Data SrvBankMoveItem::Item::get_data() const {
    return data;
}

bool SrvBankMoveItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvBankMoveItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankMoveItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvBankMoveItem::SrvBankMoveItem() : CRosePacket(SrvBankMoveItem::PACKET_ID) {}

SrvBankMoveItem::SrvBankMoveItem(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int16_t(inventory_index)) {
        return;
    }
    if (!reader.get_int16_t(bank_index)) {
        return;
    }
    if (!reader.get_iserialize(inventory_item)) {
        return;
    }
    if (!reader.get_iserialize(bank_item)) {
        return;
    }
    if (!reader.get_int64_t(money)) {
        return;
    }
}

SrvBankMoveItem& SrvBankMoveItem::set_inventory_index(const int16_t inventory_index) {
    this->inventory_index = inventory_index;
    return *this;
}

int16_t SrvBankMoveItem::get_inventory_index() const {
    return inventory_index;
}

SrvBankMoveItem& SrvBankMoveItem::set_bank_index(const int16_t bank_index) {
    this->bank_index = bank_index;
    return *this;
}

int16_t SrvBankMoveItem::get_bank_index() const {
    return bank_index;
}

SrvBankMoveItem& SrvBankMoveItem::set_inventory_item(const SrvBankMoveItem::Item inventory_item) {
    this->inventory_item = inventory_item;
    return *this;
}

SrvBankMoveItem::Item SrvBankMoveItem::get_inventory_item() const {
    return inventory_item;
}

SrvBankMoveItem& SrvBankMoveItem::set_bank_item(const SrvBankMoveItem::Item bank_item) {
    this->bank_item = bank_item;
    return *this;
}

SrvBankMoveItem::Item SrvBankMoveItem::get_bank_item() const {
    return bank_item;
}

SrvBankMoveItem& SrvBankMoveItem::set_money(const int64_t money) {
    this->money = money;
    return *this;
}

int64_t SrvBankMoveItem::get_money() const {
    return money;
}

SrvBankMoveItem SrvBankMoveItem::create(const int16_t& inventory_index, const int16_t& bank_index, const SrvBankMoveItem::Item& inventory_item, const SrvBankMoveItem::Item& bank_item, const int64_t& money) {
    SrvBankMoveItem packet;
    packet.set_inventory_index(inventory_index);
    packet.set_bank_index(bank_index);
    packet.set_inventory_item(inventory_item);
    packet.set_bank_item(bank_item);
    packet.set_money(money);
    return packet;
}

SrvBankMoveItem SrvBankMoveItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvBankMoveItem(reader);
}

std::unique_ptr<SrvBankMoveItem> SrvBankMoveItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvBankMoveItem>(reader);
}

bool SrvBankMoveItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int16_t(inventory_index)) {
        return false;
    }
    if (!writer.set_int16_t(bank_index)) {
        return false;
    }
    if (!writer.set_iserialize(inventory_item)) {
        return false;
    }
    if (!writer.set_iserialize(bank_item)) {
        return false;
    }
    if (!writer.set_int64_t(money)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankMoveItem::size() {
    size_t size = 0;
    size += sizeof(int16_t); // inventory_index
    size += sizeof(int16_t); // bank_index
    size += Item::size(); // inventory_item
    size += Item::size(); // bank_item
    size += sizeof(int64_t); // money
    return size;
}

