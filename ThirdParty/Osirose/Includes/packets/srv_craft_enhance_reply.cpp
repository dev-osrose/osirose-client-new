#include "srv_craft_enhance_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvCraftEnhanceReply::Header& SrvCraftEnhanceReply::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Header::get_type() const {
    return data.type;
}

SrvCraftEnhanceReply::Header& SrvCraftEnhanceReply::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Header::get_id() const {
    return data.id;
}

SrvCraftEnhanceReply::Header& SrvCraftEnhanceReply::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Header::get_isCreated() const {
    return data.isCreated;
}

SrvCraftEnhanceReply::Header& SrvCraftEnhanceReply::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvCraftEnhanceReply::Header::get_header() const {
    return data.header;
}

bool SrvCraftEnhanceReply::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvCraftEnhanceReply::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftEnhanceReply::Header::size() {
    return sizeof(data);
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Data::get_durability() const {
    return data.durability;
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Data::get_life() const {
    return data.life;
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvCraftEnhanceReply::Data::get_refine() const {
    return data.refine;
}

SrvCraftEnhanceReply::Data& SrvCraftEnhanceReply::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvCraftEnhanceReply::Data::get_count() const {
    return data.count;
}

bool SrvCraftEnhanceReply::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvCraftEnhanceReply::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftEnhanceReply::Data::size() {
    return sizeof(data);
}

SrvCraftEnhanceReply::Item& SrvCraftEnhanceReply::Item::set_header(const SrvCraftEnhanceReply::Header header) {
    this->header = header;
    return *this;
}

SrvCraftEnhanceReply::Header SrvCraftEnhanceReply::Item::get_header() const {
    return header;
}

SrvCraftEnhanceReply::Item& SrvCraftEnhanceReply::Item::set_data(const SrvCraftEnhanceReply::Data data) {
    this->data = data;
    return *this;
}

SrvCraftEnhanceReply::Data SrvCraftEnhanceReply::Item::get_data() const {
    return data;
}

bool SrvCraftEnhanceReply::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvCraftEnhanceReply::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftEnhanceReply::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvCraftEnhanceReply::SrvCraftEnhanceReply() : CRosePacket(SrvCraftEnhanceReply::PACKET_ID) {}

SrvCraftEnhanceReply::SrvCraftEnhanceReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<CraftEnhancementResult>(result_temp);
    
    {
        SrvCraftEnhanceReply::Item elem;
        while (reader.get_iserialize(elem)) {
            items.push_back(elem);
        }
    }
}

SrvCraftEnhanceReply& SrvCraftEnhanceReply::set_result(const SrvCraftEnhanceReply::CraftEnhancementResult result) {
    this->result = result;
    return *this;
}

SrvCraftEnhanceReply::CraftEnhancementResult SrvCraftEnhanceReply::get_result() const {
    return result;
}

SrvCraftEnhanceReply& SrvCraftEnhanceReply::set_items(const std::vector<SrvCraftEnhanceReply::Item> items) {
    this->items = items;
    return *this;
}

SrvCraftEnhanceReply& SrvCraftEnhanceReply::add_items(const Item items) {
    this->items.emplace_back(items);
    return *this;
}

std::vector<SrvCraftEnhanceReply::Item> SrvCraftEnhanceReply::get_items() const {
    return items;
}

SrvCraftEnhanceReply::Item SrvCraftEnhanceReply::get_items(size_t index) const {
    return items[index];
}

SrvCraftEnhanceReply SrvCraftEnhanceReply::create(const SrvCraftEnhanceReply::CraftEnhancementResult& result) {
    SrvCraftEnhanceReply packet;
    packet.set_result(result);
    return packet;
}

SrvCraftEnhanceReply SrvCraftEnhanceReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvCraftEnhanceReply(reader);
}

std::unique_ptr<SrvCraftEnhanceReply> SrvCraftEnhanceReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvCraftEnhanceReply>(reader);
}

bool SrvCraftEnhanceReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    for (const auto& elem : items) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvCraftEnhanceReply::size() {
    size_t size = 0;
    size += sizeof(CraftEnhancementResult); // result
    size += Item::size(); // items
    return size;
}

