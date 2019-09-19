#include "srv_mob_char.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvMobChar::SrvMobChar() : CRosePacket(SrvMobChar::PACKET_ID) {}

SrvMobChar::SrvMobChar(CRoseReader reader) : CRosePacket(reader) {
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
    if (!reader.get_uint16_t(npcId)) {
        return;
    }
    if (!reader.get_uint16_t(questId)) {
        return;
    }
}

SrvMobChar& SrvMobChar::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvMobChar::get_id() const {
    return id;
}

SrvMobChar& SrvMobChar::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvMobChar::get_x() const {
    return x;
}

SrvMobChar& SrvMobChar::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvMobChar::get_y() const {
    return y;
}

SrvMobChar& SrvMobChar::set_destX(const float destX) {
    this->destX = destX;
    return *this;
}

float SrvMobChar::get_destX() const {
    return destX;
}

SrvMobChar& SrvMobChar::set_destY(const float destY) {
    this->destY = destY;
    return *this;
}

float SrvMobChar::get_destY() const {
    return destY;
}

SrvMobChar& SrvMobChar::set_command(const uint16_t command) {
    this->command = command;
    return *this;
}

uint16_t SrvMobChar::get_command() const {
    return command;
}

SrvMobChar& SrvMobChar::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t SrvMobChar::get_targetId() const {
    return targetId;
}

SrvMobChar& SrvMobChar::set_moveMode(const uint8_t moveMode) {
    this->moveMode = moveMode;
    return *this;
}

uint8_t SrvMobChar::get_moveMode() const {
    return moveMode;
}

SrvMobChar& SrvMobChar::set_hp(const int32_t hp) {
    this->hp = hp;
    return *this;
}

int32_t SrvMobChar::get_hp() const {
    return hp;
}

SrvMobChar& SrvMobChar::set_teamId(const int32_t teamId) {
    this->teamId = teamId;
    return *this;
}

int32_t SrvMobChar::get_teamId() const {
    return teamId;
}

SrvMobChar& SrvMobChar::set_statusFlag(const uint32_t statusFlag) {
    this->statusFlag = statusFlag;
    return *this;
}

uint32_t SrvMobChar::get_statusFlag() const {
    return statusFlag;
}

SrvMobChar& SrvMobChar::set_npcId(const uint16_t npcId) {
    this->npcId = npcId;
    return *this;
}

uint16_t SrvMobChar::get_npcId() const {
    return npcId;
}

SrvMobChar& SrvMobChar::set_questId(const uint16_t questId) {
    this->questId = questId;
    return *this;
}

uint16_t SrvMobChar::get_questId() const {
    return questId;
}

SrvMobChar SrvMobChar::create(const uint16_t& id) {
    SrvMobChar packet;
    packet.set_id(id);
    return packet;
}

SrvMobChar SrvMobChar::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvMobChar(reader);
}

std::unique_ptr<SrvMobChar> SrvMobChar::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvMobChar>(reader);
}

bool SrvMobChar::pack(CRoseBasePolicy& writer) const {
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
    if (!writer.set_uint16_t(npcId)) {
        return false;
    }
    if (!writer.set_uint16_t(questId)) {
        return false;
    }
    return true;
}

constexpr size_t SrvMobChar::size() {
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
    size += sizeof(uint16_t); // npcId
    size += sizeof(uint16_t); // questId
    return size;
}

