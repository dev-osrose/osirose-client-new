#include "srv_char_list_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvCharListReply::EquippedItem& SrvCharListReply::EquippedItem::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvCharListReply::EquippedItem::get_id() const {
    return data.id;
}

SrvCharListReply::EquippedItem& SrvCharListReply::EquippedItem::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvCharListReply::EquippedItem::get_gem_opt() const {
    return data.gem_opt;
}

SrvCharListReply::EquippedItem& SrvCharListReply::EquippedItem::set_socket(const unsigned int socket) {
    this->data.socket = socket;
    return *this;
}

unsigned int SrvCharListReply::EquippedItem::get_socket() const {
    return data.socket;
}

SrvCharListReply::EquippedItem& SrvCharListReply::EquippedItem::set_grade(const unsigned int grade) {
    this->data.grade = grade;
    return *this;
}

unsigned int SrvCharListReply::EquippedItem::get_grade() const {
    return data.grade;
}

SrvCharListReply::EquippedItem& SrvCharListReply::EquippedItem::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t SrvCharListReply::EquippedItem::get_data() const {
    return data.data;
}

bool SrvCharListReply::EquippedItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvCharListReply::EquippedItem::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvCharListReply::EquippedItem::size() {
    return sizeof(data);
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvCharListReply::CharInfo::get_name() const {
    return name;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_race(const uint8_t race) {
    this->race = race;
    return *this;
}

uint8_t SrvCharListReply::CharInfo::get_race() const {
    return race;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_level(const uint16_t level) {
    this->level = level;
    return *this;
}

uint16_t SrvCharListReply::CharInfo::get_level() const {
    return level;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_job(const uint16_t job) {
    this->job = job;
    return *this;
}

uint16_t SrvCharListReply::CharInfo::get_job() const {
    return job;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_remainSecsUntilDelete(const uint32_t remainSecsUntilDelete) {
    this->remainSecsUntilDelete = remainSecsUntilDelete;
    return *this;
}

uint32_t SrvCharListReply::CharInfo::get_remainSecsUntilDelete() const {
    return remainSecsUntilDelete;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_platinium(const uint8_t platinium) {
    this->platinium = platinium;
    return *this;
}

uint8_t SrvCharListReply::CharInfo::get_platinium() const {
    return platinium;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_face(const uint32_t face) {
    this->face = face;
    return *this;
}

uint32_t SrvCharListReply::CharInfo::get_face() const {
    return face;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_hair(const uint32_t hair) {
    this->hair = hair;
    return *this;
}

uint32_t SrvCharListReply::CharInfo::get_hair() const {
    return hair;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_items(const std::array<SrvCharListReply::EquippedItem, MAX_VISIBLE_ITEMS>& items) {
    this->items = items;
    return *this;
}

SrvCharListReply::CharInfo& SrvCharListReply::CharInfo::set_items(const EquippedItem& items, size_t index) {
    this->items[index] = items;
    return *this;
}

const std::array<SrvCharListReply::EquippedItem, MAX_VISIBLE_ITEMS>& SrvCharListReply::CharInfo::get_items() const {
    return items;
}

const SrvCharListReply::EquippedItem& SrvCharListReply::CharInfo::get_items(size_t index) const {
    return items[index];
}

bool SrvCharListReply::CharInfo::write(CRoseBasePolicy& writer) const {
    if (!writer.set_string(name)) {
        return false;
    }
    if (!writer.set_uint8_t(race)) {
        return false;
    }
    if (!writer.set_uint16_t(level)) {
        return false;
    }
    if (!writer.set_uint16_t(job)) {
        return false;
    }
    if (!writer.set_uint32_t(remainSecsUntilDelete)) {
        return false;
    }
    if (!writer.set_uint8_t(platinium)) {
        return false;
    }
    if (!writer.set_uint32_t(face)) {
        return false;
    }
    if (!writer.set_uint32_t(hair)) {
        return false;
    }
    for (size_t index = 0; index < MAX_VISIBLE_ITEMS; ++index) {
        if (!writer.set_iserialize(items[index])) {
            return false;
        }
    }
    return true;
}

bool SrvCharListReply::CharInfo::read(CRoseReader& reader) {
    if (!reader.get_string(name)) {
        return false;
    }
    if (!reader.get_uint8_t(race)) {
        return false;
    }
    if (!reader.get_uint16_t(level)) {
        return false;
    }
    if (!reader.get_uint16_t(job)) {
        return false;
    }
    if (!reader.get_uint32_t(remainSecsUntilDelete)) {
        return false;
    }
    if (!reader.get_uint8_t(platinium)) {
        return false;
    }
    if (!reader.get_uint32_t(face)) {
        return false;
    }
    if (!reader.get_uint32_t(hair)) {
        return false;
    }
    for (size_t index = 0; index < MAX_VISIBLE_ITEMS; ++index) {
        if (!reader.get_iserialize(items[index])) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvCharListReply::CharInfo::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // race
    size += sizeof(uint16_t); // level
    size += sizeof(uint16_t); // job
    size += sizeof(uint32_t); // remainSecsUntilDelete
    size += sizeof(uint8_t); // platinium
    size += sizeof(uint32_t); // face
    size += sizeof(uint32_t); // hair
    size += EquippedItem::size() * MAX_VISIBLE_ITEMS; // items
    return size;
}


SrvCharListReply::SrvCharListReply() : CRosePacket(SrvCharListReply::PACKET_ID) {}

SrvCharListReply::SrvCharListReply(CRoseReader reader) : CRosePacket(reader) {
    {
        uint8_t size;
        if (!reader.get_uint8_t(size)) {
            return;
        }
        while (size-- > 0) {
            SrvCharListReply::CharInfo elem;
            if (!reader.get_iserialize(elem)) {
                return;
            }
            characters.push_back(elem);
        }
    }
}

SrvCharListReply& SrvCharListReply::set_characters(const std::vector<SrvCharListReply::CharInfo>& characters) {
    this->characters = characters;
    return *this;
}

SrvCharListReply& SrvCharListReply::add_characters(const CharInfo& characters) {
    this->characters.emplace_back(characters);
    return *this;
}

const std::vector<SrvCharListReply::CharInfo>& SrvCharListReply::get_characters() const {
    return characters;
}

const SrvCharListReply::CharInfo& SrvCharListReply::get_characters(size_t index) const {
    return characters[index];
}

SrvCharListReply SrvCharListReply::create() {
    SrvCharListReply packet;
    return packet;
}

SrvCharListReply SrvCharListReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvCharListReply(reader);
}

std::unique_ptr<SrvCharListReply> SrvCharListReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvCharListReply>(reader);
}

bool SrvCharListReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(characters.size())) {
        return false;
    }
    for (const auto& elem : characters) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    return true;
}

constexpr size_t SrvCharListReply::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // characters
    size += CharInfo::size(); // characters
    return size;
}

