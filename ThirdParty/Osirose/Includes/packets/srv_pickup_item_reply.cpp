#include "srv_pickup_item_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvPickupItemReply::Header& SrvPickupItemReply::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvPickupItemReply::Header::get_type() const {
    return data.type;
}

SrvPickupItemReply::Header& SrvPickupItemReply::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvPickupItemReply::Header::get_id() const {
    return data.id;
}

SrvPickupItemReply::Header& SrvPickupItemReply::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvPickupItemReply::Header::get_isCreated() const {
    return data.isCreated;
}

SrvPickupItemReply::Header& SrvPickupItemReply::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvPickupItemReply::Header::get_header() const {
    return data.header;
}

bool SrvPickupItemReply::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvPickupItemReply::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPickupItemReply::Header::size() {
    return sizeof(data);
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvPickupItemReply::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvPickupItemReply::Data::get_durability() const {
    return data.durability;
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvPickupItemReply::Data::get_life() const {
    return data.life;
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvPickupItemReply::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvPickupItemReply::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvPickupItemReply::Data::get_refine() const {
    return data.refine;
}

SrvPickupItemReply::Data& SrvPickupItemReply::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvPickupItemReply::Data::get_count() const {
    return data.count;
}

bool SrvPickupItemReply::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvPickupItemReply::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPickupItemReply::Data::size() {
    return sizeof(data);
}

SrvPickupItemReply::Item& SrvPickupItemReply::Item::set_header(const SrvPickupItemReply::Header header) {
    this->header = header;
    return *this;
}

SrvPickupItemReply::Header SrvPickupItemReply::Item::get_header() const {
    return header;
}

SrvPickupItemReply::Item& SrvPickupItemReply::Item::set_data(const SrvPickupItemReply::Data data) {
    this->data = data;
    return *this;
}

SrvPickupItemReply::Data SrvPickupItemReply::Item::get_data() const {
    return data;
}

bool SrvPickupItemReply::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvPickupItemReply::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPickupItemReply::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvPickupItemReply::SrvPickupItemReply() : CRosePacket(SrvPickupItemReply::PACKET_ID) {}

SrvPickupItemReply::SrvPickupItemReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<Result>(result_temp);
    
    if (!reader.get_uint16_t(slot)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

SrvPickupItemReply& SrvPickupItemReply::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvPickupItemReply::get_id() const {
    return id;
}

SrvPickupItemReply& SrvPickupItemReply::set_result(const SrvPickupItemReply::Result result) {
    this->result = result;
    return *this;
}

SrvPickupItemReply::Result SrvPickupItemReply::get_result() const {
    return result;
}

SrvPickupItemReply& SrvPickupItemReply::set_slot(const uint16_t slot) {
    this->slot = slot;
    return *this;
}

uint16_t SrvPickupItemReply::get_slot() const {
    return slot;
}

SrvPickupItemReply& SrvPickupItemReply::set_item(const SrvPickupItemReply::Item item) {
    this->item = item;
    return *this;
}

SrvPickupItemReply::Item SrvPickupItemReply::get_item() const {
    return item;
}

SrvPickupItemReply SrvPickupItemReply::create(const SrvPickupItemReply::Result& result) {
    SrvPickupItemReply packet;
    packet.set_result(result);
    return packet;
}

SrvPickupItemReply SrvPickupItemReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPickupItemReply(reader);
}

std::unique_ptr<SrvPickupItemReply> SrvPickupItemReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPickupItemReply>(reader);
}

bool SrvPickupItemReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_uint16_t(slot)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPickupItemReply::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(Result); // result
    size += sizeof(uint16_t); // slot
    size += Item::size(); // item
    return size;
}

