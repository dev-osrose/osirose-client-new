#include "cli_bank_move_item.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


CliBankMoveItem::Header& CliBankMoveItem::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int CliBankMoveItem::Header::get_type() const {
    return data.type;
}

CliBankMoveItem::Header& CliBankMoveItem::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int CliBankMoveItem::Header::get_id() const {
    return data.id;
}

CliBankMoveItem::Header& CliBankMoveItem::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int CliBankMoveItem::Header::get_isCreated() const {
    return data.isCreated;
}

CliBankMoveItem::Header& CliBankMoveItem::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t CliBankMoveItem::Header::get_header() const {
    return data.header;
}

bool CliBankMoveItem::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool CliBankMoveItem::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t CliBankMoveItem::Header::size() {
    return sizeof(data);
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int CliBankMoveItem::Data::get_gem_opt() const {
    return data.gem_opt;
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int CliBankMoveItem::Data::get_durability() const {
    return data.durability;
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int CliBankMoveItem::Data::get_life() const {
    return data.life;
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int CliBankMoveItem::Data::get_hasSocket() const {
    return data.hasSocket;
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int CliBankMoveItem::Data::get_isAppraised() const {
    return data.isAppraised;
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int CliBankMoveItem::Data::get_refine() const {
    return data.refine;
}

CliBankMoveItem::Data& CliBankMoveItem::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t CliBankMoveItem::Data::get_count() const {
    return data.count;
}

bool CliBankMoveItem::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool CliBankMoveItem::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t CliBankMoveItem::Data::size() {
    return sizeof(data);
}

CliBankMoveItem::Item& CliBankMoveItem::Item::set_header(const CliBankMoveItem::Header header) {
    this->header = header;
    return *this;
}

CliBankMoveItem::Header CliBankMoveItem::Item::get_header() const {
    return header;
}

CliBankMoveItem::Item& CliBankMoveItem::Item::set_data(const CliBankMoveItem::Data data) {
    this->data = data;
    return *this;
}

CliBankMoveItem::Data CliBankMoveItem::Item::get_data() const {
    return data;
}

bool CliBankMoveItem::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool CliBankMoveItem::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t CliBankMoveItem::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


CliBankMoveItem::CliBankMoveItem() : CRosePacket(CliBankMoveItem::PACKET_ID) {}

CliBankMoveItem::CliBankMoveItem(CRoseReader reader) : CRosePacket(reader) {
    uint8_t mode_temp;
    if (!reader.get_uint8_t(mode_temp)) {
        return;
    }
    mode = static_cast<BankMoveMode>(mode_temp);
    
    if (!reader.get_uint8_t(index)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
    if (!reader.get_uint8_t(use_special_tab)) {
        return;
    }
}

CliBankMoveItem& CliBankMoveItem::set_mode(const CliBankMoveItem::BankMoveMode mode) {
    this->mode = mode;
    return *this;
}

CliBankMoveItem::BankMoveMode CliBankMoveItem::get_mode() const {
    return mode;
}

CliBankMoveItem& CliBankMoveItem::set_index(const uint8_t index) {
    this->index = index;
    return *this;
}

uint8_t CliBankMoveItem::get_index() const {
    return index;
}

CliBankMoveItem& CliBankMoveItem::set_item(const CliBankMoveItem::Item item) {
    this->item = item;
    return *this;
}

CliBankMoveItem::Item CliBankMoveItem::get_item() const {
    return item;
}

CliBankMoveItem& CliBankMoveItem::set_use_special_tab(const uint8_t use_special_tab) {
    this->use_special_tab = use_special_tab;
    return *this;
}

uint8_t CliBankMoveItem::get_use_special_tab() const {
    return use_special_tab;
}

CliBankMoveItem CliBankMoveItem::create(const CliBankMoveItem::BankMoveMode& mode, const uint8_t& index, const CliBankMoveItem::Item& item, const uint8_t& use_special_tab) {
    CliBankMoveItem packet;
    packet.set_mode(mode);
    packet.set_index(index);
    packet.set_item(item);
    packet.set_use_special_tab(use_special_tab);
    return packet;
}

CliBankMoveItem CliBankMoveItem::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliBankMoveItem(reader);
}

std::unique_ptr<CliBankMoveItem> CliBankMoveItem::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliBankMoveItem>(reader);
}

bool CliBankMoveItem::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(mode)) {
        return false;
    }
    if (!writer.set_uint8_t(index)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    if (!writer.set_uint8_t(use_special_tab)) {
        return false;
    }
    return true;
}

constexpr size_t CliBankMoveItem::size() {
    size_t size = 0;
    size += sizeof(BankMoveMode); // mode
    size += sizeof(uint8_t); // index
    size += Item::size(); // item
    size += sizeof(uint8_t); // use_special_tab
    return size;
}

