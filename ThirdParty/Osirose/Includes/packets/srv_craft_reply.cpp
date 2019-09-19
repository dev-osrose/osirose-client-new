#include "srv_craft_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvCraftReply::Header& SrvCraftReply::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvCraftReply::Header::get_type() const {
    return data.type;
}

SrvCraftReply::Header& SrvCraftReply::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvCraftReply::Header::get_id() const {
    return data.id;
}

SrvCraftReply::Header& SrvCraftReply::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvCraftReply::Header::get_isCreated() const {
    return data.isCreated;
}

SrvCraftReply::Header& SrvCraftReply::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvCraftReply::Header::get_header() const {
    return data.header;
}

bool SrvCraftReply::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvCraftReply::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftReply::Header::size() {
    return sizeof(data);
}

SrvCraftReply::Data& SrvCraftReply::Data::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvCraftReply::Data::get_gem_opt() const {
    return data.gem_opt;
}

SrvCraftReply::Data& SrvCraftReply::Data::set_durability(const unsigned int durability) {
    this->data.durability = durability;
    return *this;
}

unsigned int SrvCraftReply::Data::get_durability() const {
    return data.durability;
}

SrvCraftReply::Data& SrvCraftReply::Data::set_life(const unsigned int life) {
    this->data.life = life;
    return *this;
}

unsigned int SrvCraftReply::Data::get_life() const {
    return data.life;
}

SrvCraftReply::Data& SrvCraftReply::Data::set_hasSocket(const unsigned int hasSocket) {
    this->data.hasSocket = hasSocket;
    return *this;
}

unsigned int SrvCraftReply::Data::get_hasSocket() const {
    return data.hasSocket;
}

SrvCraftReply::Data& SrvCraftReply::Data::set_isAppraised(const unsigned int isAppraised) {
    this->data.isAppraised = isAppraised;
    return *this;
}

unsigned int SrvCraftReply::Data::get_isAppraised() const {
    return data.isAppraised;
}

SrvCraftReply::Data& SrvCraftReply::Data::set_refine(const unsigned int refine) {
    this->data.refine = refine;
    return *this;
}

unsigned int SrvCraftReply::Data::get_refine() const {
    return data.refine;
}

SrvCraftReply::Data& SrvCraftReply::Data::set_count(const uint32_t count) {
    this->data.count = count;
    return *this;
}

uint32_t SrvCraftReply::Data::get_count() const {
    return data.count;
}

bool SrvCraftReply::Data::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.count)) {
        return false;
    }
    return true;
}

bool SrvCraftReply::Data::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.count)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftReply::Data::size() {
    return sizeof(data);
}

SrvCraftReply::Item& SrvCraftReply::Item::set_header(const SrvCraftReply::Header header) {
    this->header = header;
    return *this;
}

SrvCraftReply::Header SrvCraftReply::Item::get_header() const {
    return header;
}

SrvCraftReply::Item& SrvCraftReply::Item::set_data(const SrvCraftReply::Data data) {
    this->data = data;
    return *this;
}

SrvCraftReply::Data SrvCraftReply::Item::get_data() const {
    return data;
}

bool SrvCraftReply::Item::write(CRoseBasePolicy& writer) const {
    if (!writer.set_iserialize(header)) {
        return false;
    }
    if (!writer.set_iserialize(data)) {
        return false;
    }
    return true;
}

bool SrvCraftReply::Item::read(CRoseReader& reader) {
    if (!reader.get_iserialize(header)) {
        return false;
    }
    if (!reader.get_iserialize(data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftReply::Item::size() {
    size_t size = 0;
    size += Header::size(); // header
    size += Data::size(); // data
    return size;
}


SrvCraftReply::SrvCraftReply() : CRosePacket(SrvCraftReply::PACKET_ID) {}

SrvCraftReply::SrvCraftReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<CraftResult>(result_temp);
    
    if (!reader.get_int16_t(stepOrIndex)) {
        return;
    }
    for (size_t index = 0; index < 4; ++index) {
        if (!reader.get_int16_t(progress[index])) {
            return;
        }
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

SrvCraftReply& SrvCraftReply::set_result(const SrvCraftReply::CraftResult result) {
    this->result = result;
    return *this;
}

SrvCraftReply::CraftResult SrvCraftReply::get_result() const {
    return result;
}

SrvCraftReply& SrvCraftReply::set_stepOrIndex(const int16_t stepOrIndex) {
    this->stepOrIndex = stepOrIndex;
    return *this;
}

int16_t SrvCraftReply::get_stepOrIndex() const {
    return stepOrIndex;
}

SrvCraftReply& SrvCraftReply::set_progress(const std::array<int16_t, 4> progress) {
    this->progress = progress;
    return *this;
}

SrvCraftReply& SrvCraftReply::set_progress(const int16_t progress, size_t index) {
    this->progress[index] = progress;
    return *this;
}

std::array<int16_t, 4> SrvCraftReply::get_progress() const {
    return progress;
}

int16_t SrvCraftReply::get_progress(size_t index) const {
    return progress[index];
}

SrvCraftReply& SrvCraftReply::set_item(const SrvCraftReply::Item item) {
    this->item = item;
    return *this;
}

SrvCraftReply::Item SrvCraftReply::get_item() const {
    return item;
}

SrvCraftReply SrvCraftReply::create(const SrvCraftReply::CraftResult& result, const int16_t& stepOrIndex, const std::array<int16_t, 4>& progress) {
    SrvCraftReply packet;
    packet.set_result(result);
    packet.set_stepOrIndex(stepOrIndex);
    packet.set_progress(progress);
    return packet;
}

SrvCraftReply SrvCraftReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvCraftReply(reader);
}

std::unique_ptr<SrvCraftReply> SrvCraftReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvCraftReply>(reader);
}

bool SrvCraftReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    if (!writer.set_int16_t(stepOrIndex)) {
        return false;
    }
    for (const auto& elem : progress) {
        if (!writer.set_int16_t(elem)) {
            return false;
        }
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCraftReply::size() {
    size_t size = 0;
    size += sizeof(CraftResult); // result
    size += sizeof(int16_t); // stepOrIndex
    size += sizeof(int16_t) * 4; // progress
    size += Item::size(); // item
    return size;
}

