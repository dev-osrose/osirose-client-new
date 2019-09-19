#include "srv_bank_move_money.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvBankMoveMoney::SrvBankMoveMoney() : CRosePacket(SrvBankMoveMoney::PACKET_ID) {}

SrvBankMoveMoney::SrvBankMoveMoney(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_int64_t  (inventory)) {
        return;
    }
    if (!reader.get_int64_t(bank)) {
        return;
    }
}

SrvBankMoveMoney& SrvBankMoveMoney::set_inventory(const int64_t   inventory) {
    this->inventory = inventory;
    return *this;
}

int64_t   SrvBankMoveMoney::get_inventory() const {
    return inventory;
}

SrvBankMoveMoney& SrvBankMoveMoney::set_bank(const int64_t bank) {
    this->bank = bank;
    return *this;
}

int64_t SrvBankMoveMoney::get_bank() const {
    return bank;
}

SrvBankMoveMoney SrvBankMoveMoney::create(const int64_t  & inventory, const int64_t& bank) {
    SrvBankMoveMoney packet;
    packet.set_inventory(inventory);
    packet.set_bank(bank);
    return packet;
}

SrvBankMoveMoney SrvBankMoveMoney::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvBankMoveMoney(reader);
}

std::unique_ptr<SrvBankMoveMoney> SrvBankMoveMoney::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvBankMoveMoney>(reader);
}

bool SrvBankMoveMoney::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_int64_t  (inventory)) {
        return false;
    }
    if (!writer.set_int64_t(bank)) {
        return false;
    }
    return true;
}

constexpr size_t SrvBankMoveMoney::size() {
    size_t size = 0;
    size += sizeof(int64_t  ); // inventory
    size += sizeof(int64_t); // bank
    return size;
}

