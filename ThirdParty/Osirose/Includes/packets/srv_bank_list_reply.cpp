#include "srv_bank_list_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvBankListReply::Header& SrvBankListReply::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvBankListReply::Header::get_type() const {
    return data.type;
}

SrvBankListReply::Header& SrvBankListReply::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvBankListReply::Header::get_id() const {
    return data.id;
}

SrvBankListReply::Header& SrvBankListReply::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvBankListReply::Header::get_isCreated() const {
    return data.isCreated;
}

SrvBankListReply::Header& SrvBankListReply::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvBankListReply::Header::get_header() const {
    return data.header;
}

bool SrvBankListReply::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvBankListReply::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankListReply::Header::size() {
    return sizeof(data);
}

SrvBankListReply::Data& SrvBankListReply::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvBankListReply::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvBankListReply::Data& SrvBankListReply::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvBankListReply::Data::get_durability() const {
    return data.durability;
}

SrvBankListReply::Data& SrvBankListReply::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvBankListReply::Data::get_life() const {
    return data.life;
}

SrvBankListReply::Data& SrvBankListReply::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvBankListReply::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvBankListReply::Data& SrvBankListReply::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvBankListReply::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvBankListReply::Data& SrvBankListReply::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvBankListReply::Data::get_refine() const {
    return data.refine;
}

SrvBankListReply::Data& SrvBankListReply::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvBankListReply::Data::get_count() const {
    return data.count;
}

bool SrvBankListReply::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvBankListReply::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankListReply::Data::size() {
    return sizeof(data);
}

SrvBankListReply::Item& SrvBankListReply::Item::set_header(const SrvBankListReply::Header header) {
    this->header = header;
    return *this;
}

SrvBankListReply::Header SrvBankListReply::Item::get_header() const {
    return header;
}

SrvBankListReply::Item& SrvBankListReply::Item::set_data(const SrvBankListReply::Data data) {
    this->data = data;
    return *this;
}

SrvBankListReply::Data SrvBankListReply::Item::get_data() const {
    return data;
}

bool SrvBankListReply::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvBankListReply::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankListReply::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}

SrvBankListReply::BankListItem& SrvBankListReply::BankListItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t SrvBankListReply::BankListItem::get_index() const {
    return index;
}

SrvBankListReply::BankListItem& SrvBankListReply::BankListItem::set_item(const SrvBankListReply::Item item) {
    this->item = item;
    return *this;
}

SrvBankListReply::Item SrvBankListReply::BankListItem::get_item() const {
    return item;
}

bool SrvBankListReply::BankListItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

bool SrvBankListReply::BankListItem::read(CRoseReader& reader) {
    if (!reader.get_uint8_t(index)) {
        return false;
    }
    if (!reader.get_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankListReply::BankListItem::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // index
    size += Item::size(); // item
    return size;
}


SrvBankListReply::SrvBankListReply() : CRosePacket(SrvBankListReply::PACKET_ID) {}

SrvBankListReply::SrvBankListReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t reply_temp;
    if (!reader.get_uint8_t(reply_temp)) {
        return;
    }
    reply = static_cast<BankListReply>(reply_temp);
    
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            SrvBankListReply::BankListItem elem;
            if (!reader.get_iserialize(elem)) {
                return;
            }
            items.push_back(elem);
        }
    }
}

SrvBankListReply& SrvBankListReply::set_reply(const SrvBankListReply::BankListReply reply) {
    this->reply = reply;
    return *this;
}

SrvBankListReply::BankListReply SrvBankListReply::get_reply() const {
    return reply;
}

SrvBankListReply& SrvBankListReply::set_items(const std::vector<SrvBankListReply::BankListItem> items) {
    this->items = items;
    return *this;
}

SrvBankListReply& SrvBankListReply::add_items(const BankListItem items) {
    this->items.emplace_back(items);
    return *this;
}

std::vector<SrvBankListReply::BankListItem> SrvBankListReply::get_items() const {
    return items;
}

SrvBankListReply::BankListItem SrvBankListReply::get_items(size_t index) const {
    return items[index];
}

SrvBankListReply SrvBankListReply::create(const SrvBankListReply::BankListReply& reply) {
    SrvBankListReply packet;
    packet.set_reply(reply);
    return packet;
}

SrvBankListReply SrvBankListReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvBankListReply(reader);
}

std::unique_ptr<SrvBankListReply> SrvBankListReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvBankListReply>(reader);
}

bool SrvBankListReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(reply)) {
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

constexpr size_t SrvBankListReply::size() {
    size_t size = 0;
    size += sizeof(BankListReply); // reply
    size += sizeof(uint8_t); // items
    size += BankListItem::size(); // items
    return size;
}

