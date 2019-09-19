#include "srv_player_char.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


SrvPlayerChar::EquippedItem& SrvPlayerChar::EquippedItem::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvPlayerChar::EquippedItem::get_id() const {
    return data.id;
}

SrvPlayerChar::EquippedItem& SrvPlayerChar::EquippedItem::set_gem_opt(const unsigned int gem_opt) {
    this->data.gem_opt = gem_opt;
    return *this;
}

unsigned int SrvPlayerChar::EquippedItem::get_gem_opt() const {
    return data.gem_opt;
}

SrvPlayerChar::EquippedItem& SrvPlayerChar::EquippedItem::set_socket(const unsigned int socket) {
    this->data.socket = socket;
    return *this;
}

unsigned int SrvPlayerChar::EquippedItem::get_socket() const {
    return data.socket;
}

SrvPlayerChar::EquippedItem& SrvPlayerChar::EquippedItem::set_grade(const unsigned int grade) {
    this->data.grade = grade;
    return *this;
}

unsigned int SrvPlayerChar::EquippedItem::get_grade() const {
    return data.grade;
}

SrvPlayerChar::EquippedItem& SrvPlayerChar::EquippedItem::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t SrvPlayerChar::EquippedItem::get_data() const {
    return data.data;
}

bool SrvPlayerChar::EquippedItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool SrvPlayerChar::EquippedItem::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPlayerChar::EquippedItem::size() {
    return sizeof(data);
}

SrvPlayerChar::Header& SrvPlayerChar::Header::set_type(const unsigned int type) {
    this->data.type = type;
    return *this;
}

unsigned int SrvPlayerChar::Header::get_type() const {
    return data.type;
}

SrvPlayerChar::Header& SrvPlayerChar::Header::set_id(const unsigned int id) {
    this->data.id = id;
    return *this;
}

unsigned int SrvPlayerChar::Header::get_id() const {
    return data.id;
}

SrvPlayerChar::Header& SrvPlayerChar::Header::set_isCreated(const unsigned int isCreated) {
    this->data.isCreated = isCreated;
    return *this;
}

unsigned int SrvPlayerChar::Header::get_isCreated() const {
    return data.isCreated;
}

SrvPlayerChar::Header& SrvPlayerChar::Header::set_header(const uint16_t header) {
    this->data.header = header;
    return *this;
}

uint16_t SrvPlayerChar::Header::get_header() const {
    return data.header;
}

bool SrvPlayerChar::Header::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(data.header)) {
        return false;
    }
    return true;
}

bool SrvPlayerChar::Header::read(CRoseReader& reader) {
    if (!reader.get_uint16_t(data.header)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPlayerChar::Header::size() {
    return sizeof(data);
}


SrvPlayerChar::SrvPlayerChar() : CRosePacket(SrvPlayerChar::PACKET_ID) {}

SrvPlayerChar::SrvPlayerChar(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(id)) {
        return;
    }
    if (!reader.get_float(x)) {
        return;
    }
    if (!reader.get_float(y)) {
        return;
    }
    if (!reader.get_float(destX)) {
        return;
    }
    if (!reader.get_float(destY)) {
        return;
    }
    if (!reader.get_uint16_t(command)) {
        return;
    }
    if (!reader.get_uint16_t(targetId)) {
        return;
    }
    if (!reader.get_uint8_t(moveMode)) {
        return;
    }
    if (!reader.get_int32_t(hp)) {
        return;
    }
    if (!reader.get_int32_t(teamId)) {
        return;
    }
    if (!reader.get_uint32_t(statusFlag)) {
        return;
    }
    if (!reader.get_uint8_t(race)) {
        return;
    }
    if (!reader.get_int16_t(runSpeed)) {
        return;
    }
    if (!reader.get_int16_t(atkSpeed)) {
        return;
    }
    if (!reader.get_uint8_t(weightRate)) {
        return;
    }
    if (!reader.get_uint32_t(face)) {
        return;
    }
    if (!reader.get_uint32_t(hair)) {
        return;
    }
    for (size_t index = 0; index < MAX_VISIBLE_ITEMS; ++index) {
        if (!reader.get_iserialize(inventory[index])) {
            return;
        }
    }
    for (size_t index = 0; index < BulletType::MAX_BULLET_TYPES; ++index) {
        if (!reader.get_iserialize(bullets[index])) {
            return;
        }
    }
    if (!reader.get_int16_t(job)) {
        return;
    }
    if (!reader.get_uint8_t(level)) {
        return;
    }
    for (size_t index = 0; index < RidingItem::MAX_RIDING_ITEMS; ++index) {
        if (!reader.get_iserialize(ridingItems[index])) {
            return;
        }
    }
    if (!reader.get_int16_t(z)) {
        return;
    }
    if (!reader.get_uint32_t(subFlag)) {
        return;
    }
    if (!reader.get_string(name)) {
        return;
    }
    if (!reader.get_string(otherName)) {
        return;
    }
}

SrvPlayerChar& SrvPlayerChar::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvPlayerChar::get_id() const {
    return id;
}

SrvPlayerChar& SrvPlayerChar::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvPlayerChar::get_x() const {
    return x;
}

SrvPlayerChar& SrvPlayerChar::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvPlayerChar::get_y() const {
    return y;
}

SrvPlayerChar& SrvPlayerChar::set_destX(const float destX) {
    this->destX = destX;
    return *this;
}

float SrvPlayerChar::get_destX() const {
    return destX;
}

SrvPlayerChar& SrvPlayerChar::set_destY(const float destY) {
    this->destY = destY;
    return *this;
}

float SrvPlayerChar::get_destY() const {
    return destY;
}

SrvPlayerChar& SrvPlayerChar::set_command(const uint16_t command) {
    this->command = command;
    return *this;
}

uint16_t SrvPlayerChar::get_command() const {
    return command;
}

SrvPlayerChar& SrvPlayerChar::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t SrvPlayerChar::get_targetId() const {
    return targetId;
}

SrvPlayerChar& SrvPlayerChar::set_moveMode(const uint8_t moveMode) {
    this->moveMode = moveMode;
    return *this;
}

uint8_t SrvPlayerChar::get_moveMode() const {
    return moveMode;
}

SrvPlayerChar& SrvPlayerChar::set_hp(const int32_t hp) {
    this->hp = hp;
    return *this;
}

int32_t SrvPlayerChar::get_hp() const {
    return hp;
}

SrvPlayerChar& SrvPlayerChar::set_teamId(const int32_t teamId) {
    this->teamId = teamId;
    return *this;
}

int32_t SrvPlayerChar::get_teamId() const {
    return teamId;
}

SrvPlayerChar& SrvPlayerChar::set_statusFlag(const uint32_t statusFlag) {
    this->statusFlag = statusFlag;
    return *this;
}

uint32_t SrvPlayerChar::get_statusFlag() const {
    return statusFlag;
}

SrvPlayerChar& SrvPlayerChar::set_race(const uint8_t race) {
    this->race = race;
    return *this;
}

uint8_t SrvPlayerChar::get_race() const {
    return race;
}

SrvPlayerChar& SrvPlayerChar::set_runSpeed(const int16_t runSpeed) {
    this->runSpeed = runSpeed;
    return *this;
}

int16_t SrvPlayerChar::get_runSpeed() const {
    return runSpeed;
}

SrvPlayerChar& SrvPlayerChar::set_atkSpeed(const int16_t atkSpeed) {
    this->atkSpeed = atkSpeed;
    return *this;
}

int16_t SrvPlayerChar::get_atkSpeed() const {
    return atkSpeed;
}

SrvPlayerChar& SrvPlayerChar::set_weightRate(const uint8_t weightRate) {
    this->weightRate = weightRate;
    return *this;
}

uint8_t SrvPlayerChar::get_weightRate() const {
    return weightRate;
}

SrvPlayerChar& SrvPlayerChar::set_face(const uint32_t face) {
    this->face = face;
    return *this;
}

uint32_t SrvPlayerChar::get_face() const {
    return face;
}

SrvPlayerChar& SrvPlayerChar::set_hair(const uint32_t hair) {
    this->hair = hair;
    return *this;
}

uint32_t SrvPlayerChar::get_hair() const {
    return hair;
}

SrvPlayerChar& SrvPlayerChar::set_inventory(const std::array<SrvPlayerChar::EquippedItem, MAX_VISIBLE_ITEMS>& inventory) {
    this->inventory = inventory;
    return *this;
}

SrvPlayerChar& SrvPlayerChar::set_inventory(const EquippedItem& inventory, size_t index) {
    this->inventory[index] = inventory;
    return *this;
}

const std::array<SrvPlayerChar::EquippedItem, MAX_VISIBLE_ITEMS>& SrvPlayerChar::get_inventory() const {
    return inventory;
}

const SrvPlayerChar::EquippedItem& SrvPlayerChar::get_inventory(size_t index) const {
    return inventory[index];
}

SrvPlayerChar& SrvPlayerChar::set_bullets(const std::array<SrvPlayerChar::Header, BulletType::MAX_BULLET_TYPES>& bullets) {
    this->bullets = bullets;
    return *this;
}

SrvPlayerChar& SrvPlayerChar::set_bullets(const Header& bullets, size_t index) {
    this->bullets[index] = bullets;
    return *this;
}

const std::array<SrvPlayerChar::Header, BulletType::MAX_BULLET_TYPES>& SrvPlayerChar::get_bullets() const {
    return bullets;
}

const SrvPlayerChar::Header& SrvPlayerChar::get_bullets(size_t index) const {
    return bullets[index];
}

SrvPlayerChar& SrvPlayerChar::set_job(const int16_t job) {
    this->job = job;
    return *this;
}

int16_t SrvPlayerChar::get_job() const {
    return job;
}

SrvPlayerChar& SrvPlayerChar::set_level(const uint8_t level) {
    this->level = level;
    return *this;
}

uint8_t SrvPlayerChar::get_level() const {
    return level;
}

SrvPlayerChar& SrvPlayerChar::set_ridingItems(const std::array<SrvPlayerChar::EquippedItem, RidingItem::MAX_RIDING_ITEMS>& ridingItems) {
    this->ridingItems = ridingItems;
    return *this;
}

SrvPlayerChar& SrvPlayerChar::set_ridingItems(const EquippedItem& ridingItems, size_t index) {
    this->ridingItems[index] = ridingItems;
    return *this;
}

const std::array<SrvPlayerChar::EquippedItem, RidingItem::MAX_RIDING_ITEMS>& SrvPlayerChar::get_ridingItems() const {
    return ridingItems;
}

const SrvPlayerChar::EquippedItem& SrvPlayerChar::get_ridingItems(size_t index) const {
    return ridingItems[index];
}

SrvPlayerChar& SrvPlayerChar::set_z(const int16_t z) {
    this->z = z;
    return *this;
}

int16_t SrvPlayerChar::get_z() const {
    return z;
}

SrvPlayerChar& SrvPlayerChar::set_subFlag(const uint32_t subFlag) {
    this->subFlag = subFlag;
    return *this;
}

uint32_t SrvPlayerChar::get_subFlag() const {
    return subFlag;
}

SrvPlayerChar& SrvPlayerChar::set_name(const std::string& name) {
    this->name = name;
    return *this;
}

const std::string& SrvPlayerChar::get_name() const {
    return name;
}

SrvPlayerChar& SrvPlayerChar::set_otherName(const std::string& otherName) {
    this->otherName = otherName;
    return *this;
}

const std::string& SrvPlayerChar::get_otherName() const {
    return otherName;
}

SrvPlayerChar SrvPlayerChar::create(const uint16_t& id) {
    SrvPlayerChar packet;
    packet.set_id(id);
    return packet;
}

SrvPlayerChar SrvPlayerChar::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvPlayerChar(reader);
}

std::unique_ptr<SrvPlayerChar> SrvPlayerChar::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvPlayerChar>(reader);
}

bool SrvPlayerChar::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(id)) {
        return false;
    }
    if (!writer.set_float(x)) {
        return false;
    }
    if (!writer.set_float(y)) {
        return false;
    }
    if (!writer.set_float(destX)) {
        return false;
    }
    if (!writer.set_float(destY)) {
        return false;
    }
    if (!writer.set_uint16_t(command)) {
        return false;
    }
    if (!writer.set_uint16_t(targetId)) {
        return false;
    }
    if (!writer.set_uint8_t(moveMode)) {
        return false;
    }
    if (!writer.set_int32_t(hp)) {
        return false;
    }
    if (!writer.set_int32_t(teamId)) {
        return false;
    }
    if (!writer.set_uint32_t(statusFlag)) {
        return false;
    }
    if (!writer.set_uint8_t(race)) {
        return false;
    }
    if (!writer.set_int16_t(runSpeed)) {
        return false;
    }
    if (!writer.set_int16_t(atkSpeed)) {
        return false;
    }
    if (!writer.set_uint8_t(weightRate)) {
        return false;
    }
    if (!writer.set_uint32_t(face)) {
        return false;
    }
    if (!writer.set_uint32_t(hair)) {
        return false;
    }
    for (const auto& elem : inventory) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    for (const auto& elem : bullets) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    if (!writer.set_int16_t(job)) {
        return false;
    }
    if (!writer.set_uint8_t(level)) {
        return false;
    }
    for (const auto& elem : ridingItems) {
        if (!writer.set_iserialize(elem)) {
            return false;
        }
    }
    if (!writer.set_int16_t(z)) {
        return false;
    }
    if (!writer.set_uint32_t(subFlag)) {
        return false;
    }
    if (!writer.set_string(name)) {
        return false;
    }
    if (!writer.set_string(otherName)) {
        return false;
    }
    return true;
}

constexpr size_t SrvPlayerChar::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // id
    size += sizeof(float); // x
    size += sizeof(float); // y
    size += sizeof(float); // destX
    size += sizeof(float); // destY
    size += sizeof(uint16_t); // command
    size += sizeof(uint16_t); // targetId
    size += sizeof(uint8_t); // moveMode
    size += sizeof(int32_t); // hp
    size += sizeof(int32_t); // teamId
    size += sizeof(uint32_t); // statusFlag
    size += sizeof(uint8_t); // race
    size += sizeof(int16_t); // runSpeed
    size += sizeof(int16_t); // atkSpeed
    size += sizeof(uint8_t); // weightRate
    size += sizeof(uint32_t); // face
    size += sizeof(uint32_t); // hair
    size += EquippedItem::size() * MAX_VISIBLE_ITEMS; // inventory
    size += Header::size() * BulletType::MAX_BULLET_TYPES; // bullets
    size += sizeof(int16_t); // job
    size += sizeof(uint8_t); // level
    size += EquippedItem::size() * RidingItem::MAX_RIDING_ITEMS; // ridingItems
    size += sizeof(int16_t); // z
    size += sizeof(uint32_t); // subFlag
    return size;
}

