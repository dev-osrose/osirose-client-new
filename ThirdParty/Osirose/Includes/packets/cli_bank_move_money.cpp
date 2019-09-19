#include "cli_bank_move_money.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliBankMoveMoney::CliBankMoveMoney() : CRosePacket(CliBankMoveMoney::PACKET_ID) {}

CliBankMoveMoney::CliBankMoveMoney(CRoseReader reader) : CRosePacket(reader) {
    uint8_t mode_temp;
    if (!reader.get_uint8_t(mode_temp)) {
        return;
    }
    mode = static_cast<BankMoveMode>(mode_temp);
    
    if (!reader.get_int64_t(amount)) {
        return;
    }
}

CliBankMoveMoney& CliBankMoveMoney::set_mode(const CliBankMoveMoney::BankMoveMode mode) {
    this->mode = mode;
    return *this;
}

CliBankMoveMoney::BankMoveMode CliBankMoveMoney::get_mode() const {
    return mode;
}

CliBankMoveMoney& CliBankMoveMoney::set_amount(const int64_t amount) {
    this->amount = amount;
    return *this;
}

int64_t CliBankMoveMoney::get_amount() const {
    return amount;
}

CliBankMoveMoney CliBankMoveMoney::create(const CliBankMoveMoney::BankMoveMode& mode, const int64_t& amount) {
    CliBankMoveMoney packet;
    packet.set_mode(mode);
    packet.set_amount(amount);
    return packet;
}

CliBankMoveMoney CliBankMoveMoney::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliBankMoveMoney(reader);
}

std::unique_ptr<CliBankMoveMoney> CliBankMoveMoney::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliBankMoveMoney>(reader);
}

bool CliBankMoveMoney::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(mode)) {
        return false;
    }
    if (!writer.set_int64_t(amount)) {
        return false;
    }
    return true;
}

constexpr size_t CliBankMoveMoney::size() {
    size_t size = 0;
    size += sizeof(BankMoveMode); // mode
    size += sizeof(int64_t); // amount
    return size;
}

