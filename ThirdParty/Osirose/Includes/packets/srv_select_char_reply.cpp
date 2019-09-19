#include "srv_select_char_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvSelectCharReply::EquippedItem& SrvSelectCharReply::EquippedItem::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvSelectCharReply::EquippedItem::get_id() const {
    return data.id;
}

SrvSelectCharReply::EquippedItem& SrvSelectCharReply::EquippedItem::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvSelectCharReply::EquippedItem::get_gem_opt() const {
    return data.gem_opt;
}

SrvSelectCharReply::EquippedItem& SrvSelectCharReply::EquippedItem::set_socket(const unsigned int socket) {
    this->data.socket = socket;
    return *this;
}

unsigned int SrvSelectCharReply::EquippedItem::get_socket() const {
    return data.socket;
}

SrvSelectCharReply::EquippedItem& SrvSelectCharReply::EquippedItem::set_grade(const unsigned int grade) {
    this->data.grade = grade;
    return *this;
}

unsigned int SrvSelectCharReply::EquippedItem::get_grade() const {
    return data.grade;
}

SrvSelectCharReply::EquippedItem& SrvSelectCharReply::EquippedItem::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t SrvSelectCharReply::EquippedItem::get_data() const {
    return data.data;
}

bool SrvSelectCharReply::EquippedItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvSelectCharReply::EquippedItem::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSelectCharReply::EquippedItem::size() {
    return sizeof(data);
}


SrvSelectCharReply::SrvSelectCharReply() : CRosePacket(SrvSelectCharReply::PACKET_ID) {}

SrvSelectCharReply::SrvSelectCharReply(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint8_t(race)) {
        return;
    }
    if (!reader.get_uint16_t(map)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
    if (!reader.get_uint16_t(spawn)) {
        return;
    }
    if (!reader.get_uint32_t(bodyFace)) {
        return;
    }
    if (!reader.get_uint32_t(bodyHair)) {
        return;
    }
    for (size_t index = 0; index < MAX_VISIBLE_ITEMS; ++index) {
        if (!reader.get_iserialize(equippedItems[index])) {
            return;
        }
    }
    if (!reader.get_uint8_t(stone)) {
        return;
    }
    if (!reader.get_uint8_t(face)) {
        return;
    }
    if (!reader.get_uint8_t(hair)) {
        return;
    }
    if (!reader.get_uint16_t(job)) {
        return;
    }
    if (!reader.get_uint8_t(factionId)) {
        return;
    }
    if (!reader.get_uint8_t(factionRank)) {
        return;
    }
    if (!reader.get_uint8_t(fame)) {
        return;
    }
    if (!reader.get_uint16_t(str)) {
        return;
    }
    if (!reader.get_uint16_t(dex)) {
        return;
    }
    if (!reader.get_uint16_t(int_)) {
        return;
    }
    if (!reader.get_uint16_t(con)) {
        return;
    }
    if (!reader.get_uint16_t(charm)) {
        return;
    }
    if (!reader.get_uint16_t(sense)) {
        return;
    }
    if (!reader.get_int32_t(hp)) {
        return;
    }
    if (!reader.get_int32_t(mp)) {
        return;
    }
    if (!reader.get_uint32_t(xp)) {
        return;
    }
    if (!reader.get_uint16_t(level)) {
        return;
    }
    if (!reader.get_uint32_t(statPoints)) {
        return;
    }
    if (!reader.get_uint32_t(skillPoints)) {
        return;
    }
    if (!reader.get_uint8_t(bodySize)) {
        return;
    }
    if (!reader.get_uint8_t(headSize)) {
        return;
    }
    if (!reader.get_uint32_t(penaltyXp)) {
        return;
    }
    for (size_t index = 0; index < 2; ++index) {
        if (!reader.get_uint16_t(factionFame[index])) {
            return;
        }
    }
    for (size_t index = 0; index < 10; ++index) {
        if (!reader.get_uint16_t(factionPoints[index])) {
            return;
        }
    }
    if (!reader.get_uint32_t(guildId)) {
        return;
    }
    if (!reader.get_uint16_t(guildContribution)) {
        return;
    }
    if (!reader.get_uint8_t(guildRank)) {
        return;
    }
    if (!reader.get_uint16_t(pkFlag)) {
        return;
    }
    if (!reader.get_uint16_t(stamina)) {
        return;
    }
    for (size_t index = 0; index < MAX_STATUS_EFFECTS; ++index) {
        if (!reader.get_iserialize(effects[index])) {
            return;
        }
    }
    if (!reader.get_uint16_t(patHp)) {
        return;
    }
    if (!reader.get_uint32_t(patCooldownTime)) {
        return;
    }
    for (size_t index = 0; index < MAX_SKILL_COUNT; ++index) {
        if (!reader.get_uint16_t(skills[index])) {
            return;
        }
    }
    for (size_t index = 0; index < MAX_HOTBAR_ITEMS; ++index) {
        if (!reader.get_iserialize(hotbar[index])) {
            return;
        }
    }
    if (!reader.get_uint32_t(tag)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
}

SrvSelectCharReply& SrvSelectCharReply::set_race(const uint8_t race) {
    this->race = race;
    return *this;
}

uint8_t SrvSelectCharReply::get_race() const {
    return race;
}

SrvSelectCharReply& SrvSelectCharReply::set_map(const uint16_t map) {
    this->map = map;
    return *this;
}

uint16_t SrvSelectCharReply::get_map() const {
    return map;
}

SrvSelectCharReply& SrvSelectCharReply::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvSelectCharReply::get_x() const {
    return x;
}

SrvSelectCharReply& SrvSelectCharReply::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvSelectCharReply::get_y() const {
    return y;
}

SrvSelectCharReply& SrvSelectCharReply::set_spawn(const uint16_t spawn) {
    this->spawn = spawn;
    return *this;
}

uint16_t SrvSelectCharReply::get_spawn() const {
    return spawn;
}

SrvSelectCharReply& SrvSelectCharReply::set_bodyFace(const uint32_t bodyFace) {
    this->bodyFace = bodyFace;
    return *this;
}

uint32_t SrvSelectCharReply::get_bodyFace() const {
    return bodyFace;
}

SrvSelectCharReply& SrvSelectCharReply::set_bodyHair(const uint32_t bodyHair) {
    this->bodyHair = bodyHair;
    return *this;
}

uint32_t SrvSelectCharReply::get_bodyHair() const {
    return bodyHair;
}

SrvSelectCharReply& SrvSelectCharReply::set_equippedItems(const std::array<SrvSelectCharReply::EquippedItem, MAX_VISIBLE_ITEMS>& equippedItems) {
    this->equippedItems = equippedItems;
    return *this;
}

SrvSelectCharReply& SrvSelectCharReply::set_equippedItems(const EquippedItem& equippedItems, size_t index) {
    this->equippedItems[index] = equippedItems;
    return *this;
}

const std::array<SrvSelectCharReply::EquippedItem, MAX_VISIBLE_ITEMS>& SrvSelectCharReply::get_equippedItems() const {
    return equippedItems;
}

const SrvSelectCharReply::EquippedItem& SrvSelectCharReply::get_equippedItems(size_t index) const {
    return equippedItems[index];
}

SrvSelectCharReply& SrvSelectCharReply::set_stone(const uint8_t stone) {
    this->stone = stone;
    return *this;
}

uint8_t SrvSelectCharReply::get_stone() const {
    return stone;
}

SrvSelectCharReply& SrvSelectCharReply::set_face(const uint8_t face) {
    this->face = face;
    return *this;
}

uint8_t SrvSelectCharReply::get_face() const {
    return face;
}

SrvSelectCharReply& SrvSelectCharReply::set_hair(const uint8_t hair) {
    this->hair = hair;
    return *this;
}

uint8_t SrvSelectCharReply::get_hair() const {
    return hair;
}

SrvSelectCharReply& SrvSelectCharReply::set_job(const uint16_t job) {
    this->job = job;
    return *this;
}

uint16_t SrvSelectCharReply::get_job() const {
    return job;
}

SrvSelectCharReply& SrvSelectCharReply::set_factionId(const uint8_t factionId) {
    this->factionId = factionId;
    return *this;
}

uint8_t SrvSelectCharReply::get_factionId() const {
    return factionId;
}

SrvSelectCharReply& SrvSelectCharReply::set_factionRank(const uint8_t factionRank) {
    this->factionRank = factionRank;
    return *this;
}

uint8_t SrvSelectCharReply::get_factionRank() const {
    return factionRank;
}

SrvSelectCharReply& SrvSelectCharReply::set_fame(const uint8_t fame) {
    this->fame = fame;
    return *this;
}

uint8_t SrvSelectCharReply::get_fame() const {
    return fame;
}

SrvSelectCharReply& SrvSelectCharReply::set_str(const uint16_t str) {
    this->str = str;
    return *this;
}

uint16_t SrvSelectCharReply::get_str() const {
    return str;
}

SrvSelectCharReply& SrvSelectCharReply::set_dex(const uint16_t dex) {
    this->dex = dex;
    return *this;
}

uint16_t SrvSelectCharReply::get_dex() const {
    return dex;
}

SrvSelectCharReply& SrvSelectCharReply::set_int_(const uint16_t int_) {
    this->int_ = int_;
    return *this;
}

uint16_t SrvSelectCharReply::get_int_() const {
    return int_;
}

SrvSelectCharReply& SrvSelectCharReply::set_con(const uint16_t con) {
    this->con = con;
    return *this;
}

uint16_t SrvSelectCharReply::get_con() const {
    return con;
}

SrvSelectCharReply& SrvSelectCharReply::set_charm(const uint16_t charm) {
    this->charm = charm;
    return *this;
}

uint16_t SrvSelectCharReply::get_charm() const {
    return charm;
}

SrvSelectCharReply& SrvSelectCharReply::set_sense(const uint16_t sense) {
    this->sense = sense;
    return *this;
}

uint16_t SrvSelectCharReply::get_sense() const {
    return sense;
}

SrvSelectCharReply& SrvSelectCharReply::set_hp(const int32_t hp) {
    this->hp = hp;
    return *this;
}

int32_t SrvSelectCharReply::get_hp() const {
    return hp;
}

SrvSelectCharReply& SrvSelectCharReply::set_mp(const int32_t mp) {
    this->mp = mp;
    return *this;
}

int32_t SrvSelectCharReply::get_mp() const {
    return mp;
}

SrvSelectCharReply& SrvSelectCharReply::set_xp(const uint32_t xp) {
    this->xp = xp;
    return *this;
}

uint32_t SrvSelectCharReply::get_xp() const {
    return xp;
}

SrvSelectCharReply& SrvSelectCharReply::set_level(const uint16_t level) {
    this->level = level;
    return *this;
}

uint16_t SrvSelectCharReply::get_level() const {
    return level;
}

SrvSelectCharReply& SrvSelectCharReply::set_statPoints(const uint32_t statPoints) {
    this->statPoints = statPoints;
    return *this;
}

uint32_t SrvSelectCharReply::get_statPoints() const {
    return statPoints;
}

SrvSelectCharReply& SrvSelectCharReply::set_skillPoints(const uint32_t skillPoints) {
    this->skillPoints = skillPoints;
    return *this;
}

uint32_t SrvSelectCharReply::get_skillPoints() const {
    return skillPoints;
}

SrvSelectCharReply& SrvSelectCharReply::set_bodySize(const uint8_t bodySize) {
    this->bodySize = bodySize;
    return *this;
}

uint8_t SrvSelectCharReply::get_bodySize() const {
    return bodySize;
}

SrvSelectCharReply& SrvSelectCharReply::set_headSize(const uint8_t headSize) {
    this->headSize = headSize;
    return *this;
}

uint8_t SrvSelectCharReply::get_headSize() const {
    return headSize;
}

SrvSelectCharReply& SrvSelectCharReply::set_penaltyXp(const uint32_t penaltyXp) {
    this->penaltyXp = penaltyXp;
    return *this;
}

uint32_t SrvSelectCharReply::get_penaltyXp() const {
    return penaltyXp;
}

SrvSelectCharReply& SrvSelectCharReply::set_factionFame(const std::array<uint16_t, 2>& factionFame) {
    this->factionFame = factionFame;
    return *this;
}

SrvSelectCharReply& SrvSelectCharReply::set_factionFame(const uint16_t& factionFame, size_t index) {
    this->factionFame[index] = factionFame;
    return *this;
}

const std::array<uint16_t, 2>& SrvSelectCharReply::get_factionFame() const {
    return factionFame;
}

const uint16_t& SrvSelectCharReply::get_factionFame(size_t index) const {
    return factionFame[index];
}

SrvSelectCharReply& SrvSelectCharReply::set_factionPoints(const std::array<uint16_t, 10>& factionPoints) {
    this->factionPoints = factionPoints;
    return *this;
}

SrvSelectCharReply& SrvSelectCharReply::set_factionPoints(const uint16_t& factionPoints, size_t index) {
    this->factionPoints[index] = factionPoints;
    return *this;
}

const std::array<uint16_t, 10>& SrvSelectCharReply::get_factionPoints() const {
    return factionPoints;
}

const uint16_t& SrvSelectCharReply::get_factionPoints(size_t index) const {
    return factionPoints[index];
}

SrvSelectCharReply& SrvSelectCharReply::set_guildId(const uint32_t guildId) {
    this->guildId = guildId;
    return *this;
}

uint32_t SrvSelectCharReply::get_guildId() const {
    return guildId;
}

SrvSelectCharReply& SrvSelectCharReply::set_guildContribution(const uint16_t guildContribution) {
    this->guildContribution = guildContribution;
    return *this;
}

uint16_t SrvSelectCharReply::get_guildContribution() const {
    return guildContribution;
}

SrvSelectCharReply& SrvSelectCharReply::set_guildRank(const uint8_t guildRank) {
    this->guildRank = guildRank;
    return *this;
}

uint8_t SrvSelectCharReply::get_guildRank() const {
    return guildRank;
}

SrvSelectCharReply& SrvSelectCharReply::set_pkFlag(const uint16_t pkFlag) {
    this->pkFlag = pkFlag;
    return *this;
}

uint16_t SrvSelectCharReply::get_pkFlag() const {
    return pkFlag;
}

SrvSelectCharReply& SrvSelectCharReply::set_stamina(const uint16_t stamina) {
    this->stamina = stamina;
    return *this;
}

uint16_t SrvSelectCharReply::get_stamina() const {
    return stamina;
}

SrvSelectCharReply& SrvSelectCharReply::set_effects(const std::array<StatusEffect, MAX_STATUS_EFFECTS>& effects) {
    this->effects = effects;
    return *this;
}

SrvSelectCharReply& SrvSelectCharReply::set_effects(const StatusEffect& effects, size_t index) {
    this->effects[index] = effects;
    return *this;
}

const std::array<StatusEffect, MAX_STATUS_EFFECTS>& SrvSelectCharReply::get_effects() const {
    return effects;
}

const StatusEffect& SrvSelectCharReply::get_effects(size_t index) const {
    return effects[index];
}

SrvSelectCharReply& SrvSelectCharReply::set_patHp(const uint16_t patHp) {
    this->patHp = patHp;
    return *this;
}

uint16_t SrvSelectCharReply::get_patHp() const {
    return patHp;
}

SrvSelectCharReply& SrvSelectCharReply::set_patCooldownTime(const uint32_t patCooldownTime) {
    this->patCooldownTime = patCooldownTime;
    return *this;
}

uint32_t SrvSelectCharReply::get_patCooldownTime() const {
    return patCooldownTime;
}

SrvSelectCharReply& SrvSelectCharReply::set_skills(const std::array<uint16_t, MAX_SKILL_COUNT>& skills) {
    this->skills = skills;
    return *this;
}

SrvSelectCharReply& SrvSelectCharReply::set_skills(const uint16_t& skills, size_t index) {
    this->skills[index] = skills;
    return *this;
}

const std::array<uint16_t, MAX_SKILL_COUNT>& SrvSelectCharReply::get_skills() const {
    return skills;
}

const uint16_t& SrvSelectCharReply::get_skills(size_t index) const {
    return skills[index];
}

SrvSelectCharReply& SrvSelectCharReply::set_hotbar(const std::array<HotbarItem, MAX_HOTBAR_ITEMS>& hotbar) {
    this->hotbar = hotbar;
    return *this;
}

SrvSelectCharReply& SrvSelectCharReply::set_hotbar(const HotbarItem& hotbar, size_t index) {
    this->hotbar[index] = hotbar;
    return *this;
}

const std::array<HotbarItem, MAX_HOTBAR_ITEMS>& SrvSelectCharReply::get_hotbar() const {
    return hotbar;
}

const HotbarItem& SrvSelectCharReply::get_hotbar(size_t index) const {
    return hotbar[index];
}

SrvSelectCharReply& SrvSelectCharReply::set_tag(const uint32_t tag) {
    this->tag = tag;
    return *this;
}

uint32_t SrvSelectCharReply::get_tag() const {
    return tag;
}

SrvSelectCharReply& SrvSelectCharReply::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvSelectCharReply::get_name() const {
    return name;
}

SrvSelectCharReply SrvSelectCharReply::create() {
    SrvSelectCharReply packet;
    return packet;
}

SrvSelectCharReply SrvSelectCharReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvSelectCharReply(reader);
}

std::unique_ptr<SrvSelectCharReply> SrvSelectCharReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvSelectCharReply>(reader);
}

bool SrvSelectCharReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(race)) {
        return false;
    }
    if (!writer.set_uint16_t(map)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    if (!writer.set_uint16_t(spawn)) {
        return false;
    }
    if (!writer.set_uint32_t(bodyFace)) {
        return false;
    }
    if (!writer.set_uint32_t(bodyHair)) {
        return false;
    }
    for (const auto& elem : equippedItems) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    if (!writer.set_uint8_t(stone)) {
        return false;
    }
    if (!writer.set_uint8_t(face)) {
        return false;
    }
    if (!writer.set_uint8_t(hair)) {
        return false;
    }
    if (!writer.set_uint16_t(job)) {
        return false;
    }
    if (!writer.set_uint8_t(factionId)) {
        return false;
    }
    if (!writer.set_uint8_t(factionRank)) {
        return false;
    }
    if (!writer.set_uint8_t(fame)) {
        return false;
    }
    if (!writer.set_uint16_t(str)) {
        return false;
    }
    if (!writer.set_uint16_t(dex)) {
        return false;
    }
    if (!writer.set_uint16_t(int_)) {
        return false;
    }
    if (!writer.set_uint16_t(con)) {
        return false;
    }
    if (!writer.set_uint16_t(charm)) {
        return false;
    }
    if (!writer.set_uint16_t(sense)) {
        return false;
    }
    if (!writer.set_int32_t(hp)) {
        return false;
    }
    if (!writer.set_int32_t(mp)) {
        return false;
    }
    if (!writer.set_uint32_t(xp)) {
        return false;
    }
    if (!writer.set_uint16_t(level)) {
        return false;
    }
    if (!writer.set_uint32_t(statPoints)) {
        return false;
    }
    if (!writer.set_uint32_t(skillPoints)) {
        return false;
    }
    if (!writer.set_uint8_t(bodySize)) {
        return false;
    }
    if (!writer.set_uint8_t(headSize)) {
        return false;
    }
    if (!writer.set_uint32_t(penaltyXp)) {
        return false;
    }
    for (const auto& elem : factionFame) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : factionPoints) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    if (!writer.set_uint32_t(guildId)) {
        return false;
    }
    if (!writer.set_uint16_t(guildContribution)) {
        return false;
    }
    if (!writer.set_uint8_t(guildRank)) {
        return false;
    }
    if (!writer.set_uint16_t(pkFlag)) {
        return false;
    }
    if (!writer.set_uint16_t(stamina)) {
        return false;
    }
    for (const auto& elem : effects) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    if (!writer.set_uint16_t(patHp)) {
        return false;
    }
    if (!writer.set_uint32_t(patCooldownTime)) {
        return false;
    }
    for (const auto& elem : skills) {
        if (!writer.set_uint16_t(elem)) {
            return false;
        }
    }
    for (const auto& elem : hotbar) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    if (!writer.set_uint32_t(tag)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    return true;
}

constexpr size_t SrvSelectCharReply::size() {
    size_t size = 0;
    size += sizeof(uint8_t); // race
    size += sizeof(uint16_t); // map
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(uint16_t); // spawn
    size += sizeof(uint32_t); // bodyFace
    size += sizeof(uint32_t); // bodyHair
    size += EquippedItem::size() * MAX_VISIBLE_ITEMS; // equippedItems
    size += sizeof(uint8_t); // stone
    size += sizeof(uint8_t); // face
    size += sizeof(uint8_t); // hair
    size += sizeof(uint16_t); // job
    size += sizeof(uint8_t); // factionId
    size += sizeof(uint8_t); // factionRank
    size += sizeof(uint8_t); // fame
    size += sizeof(uint16_t); // str
    size += sizeof(uint16_t); // dex
    size += sizeof(uint16_t); // int_
    size += sizeof(uint16_t); // con
    size += sizeof(uint16_t); // charm
    size += sizeof(uint16_t); // sense
    size += sizeof(int32_t); // hp
    size += sizeof(int32_t); // mp
    size += sizeof(uint32_t); // xp
    size += sizeof(uint16_t); // level
    size += sizeof(uint32_t); // statPoints
    size += sizeof(uint32_t); // skillPoints
    size += sizeof(uint8_t); // bodySize
    size += sizeof(uint8_t); // headSize
    size += sizeof(uint32_t); // penaltyXp
    size += sizeof(uint16_t) * 2; // factionFame
    size += sizeof(uint16_t) * 10; // factionPoints
    size += sizeof(uint32_t); // guildId
    size += sizeof(uint16_t); // guildContribution
    size += sizeof(uint8_t); // guildRank
    size += sizeof(uint16_t); // pkFlag
    size += sizeof(uint16_t); // stamina
    size += sizeof(StatusEffect) * MAX_STATUS_EFFECTS; // effects
    size += sizeof(uint16_t); // patHp
    size += sizeof(uint32_t); // patCooldownTime
    size += sizeof(uint16_t) * MAX_SKILL_COUNT; // skills
    size += sizeof(HotbarItem) * MAX_HOTBAR_ITEMS; // hotbar
    size += sizeof(uint32_t); // tag
    return size;
}

