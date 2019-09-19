#include "srv_npc_char.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvNpcChar::SrvNpcChar() : CRosePacket(SrvNpcChar::PACKET_ID) {}

SrvNpcChar::SrvNpcChar(CRoseReader reader) : CRosePacket(reader) {
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
    if (!reader.get_float(angle)) {
        return;
    }
    if (!reader.get_uint16_t(eventStatus)) {
        return;
    }
}

SrvNpcChar& SrvNpcChar::set_id(const uint16_t id) {
    this->id = id;
    return *this;
}

uint16_t SrvNpcChar::get_id() const {
    return id;
}

SrvNpcChar& SrvNpcChar::set_x(const float x) {
    this->x = x;
    return *this;
}

float SrvNpcChar::get_x() const {
    return x;
}

SrvNpcChar& SrvNpcChar::set_y(const float y) {
    this->y = y;
    return *this;
}

float SrvNpcChar::get_y() const {
    return y;
}

SrvNpcChar& SrvNpcChar::set_destX(const float destX) {
    this->destX = destX;
    return *this;
}

float SrvNpcChar::get_destX() const {
    return destX;
}

SrvNpcChar& SrvNpcChar::set_destY(const float destY) {
    this->destY = destY;
    return *this;
}

float SrvNpcChar::get_destY() const {
    return destY;
}

SrvNpcChar& SrvNpcChar::set_command(const uint16_t command) {
    this->command = command;
    return *this;
}

uint16_t SrvNpcChar::get_command() const {
    return command;
}

SrvNpcChar& SrvNpcChar::set_targetId(const uint16_t targetId) {
    this->targetId = targetId;
    return *this;
}

uint16_t SrvNpcChar::get_targetId() const {
    return targetId;
}

SrvNpcChar& SrvNpcChar::set_moveMode(const uint8_t moveMode) {
    this->moveMode = moveMode;
    return *this;
}

uint8_t SrvNpcChar::get_moveMode() const {
    return moveMode;
}

SrvNpcChar& SrvNpcChar::set_hp(const int32_t hp) {
    this->hp = hp;
    return *this;
}

int32_t SrvNpcChar::get_hp() const {
    return hp;
}

SrvNpcChar& SrvNpcChar::set_teamId(const int32_t teamId) {
    this->teamId = teamId;
    return *this;
}

int32_t SrvNpcChar::get_teamId() const {
    return teamId;
}

SrvNpcChar& SrvNpcChar::set_statusFlag(const uint32_t statusFlag) {
    this->statusFlag = statusFlag;
    return *this;
}

uint32_t SrvNpcChar::get_statusFlag() const {
    return statusFlag;
}

SrvNpcChar& SrvNpcChar::set_npcId(const uint16_t npcId) {
    this->npcId = npcId;
    return *this;
}

uint16_t SrvNpcChar::get_npcId() const {
    return npcId;
}

SrvNpcChar& SrvNpcChar::set_questId(const uint16_t questId) {
    this->questId = questId;
    return *this;
}

uint16_t SrvNpcChar::get_questId() const {
    return questId;
}

SrvNpcChar& SrvNpcChar::set_angle(const float angle) {
    this->angle = angle;
    return *this;
}

float SrvNpcChar::get_angle() const {
    return angle;
}

SrvNpcChar& SrvNpcChar::set_eventStatus(const uint16_t eventStatus) {
    this->eventStatus = eventStatus;
    return *this;
}

uint16_t SrvNpcChar::get_eventStatus() const {
    return eventStatus;
}

SrvNpcChar SrvNpcChar::create(const uint16_t& id) {
    SrvNpcChar packet;
    packet.set_id(id);
    return packet;
}

SrvNpcChar SrvNpcChar::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvNpcChar(reader);
}

std::unique_ptr<SrvNpcChar> SrvNpcChar::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvNpcChar>(reader);
}

bool SrvNpcChar::pack(CRoseBasePolicy& writer) const {
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
    if (!writer.set_float(angle)) {
        return false;
    }
    if (!writer.set_uint16_t(eventStatus)) {
        return false;
    }
    return true;
}

constexpr size_t SrvNpcChar::size() {
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
    size += sizeof(float); // angle
    size += sizeof(uint16_t); // eventStatus
    return size;
}

