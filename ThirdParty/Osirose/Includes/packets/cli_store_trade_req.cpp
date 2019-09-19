#include "cli_store_trade_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;


CliStoreTradeReq::BuySellItem& CliStoreTradeReq::BuySellItem::set_buy_tab_id(const uint8_t buy_tab_id) {
    this->data.buy_tab_id = buy_tab_id;
    return *this;
}

uint8_t CliStoreTradeReq::BuySellItem::get_buy_tab_id() const {
    return data.buy_tab_id;
}

CliStoreTradeReq::BuySellItem& CliStoreTradeReq::BuySellItem::set_buy_col_id(const uint8_t buy_col_id) {
    this->data.buy_col_id = buy_col_id;
    return *this;
}

uint8_t CliStoreTradeReq::BuySellItem::get_buy_col_id() const {
    return data.buy_col_id;
}

CliStoreTradeReq::BuySellItem& CliStoreTradeReq::BuySellItem::set_buy_amount(const uint16_t buy_amount) {
    this->data.buy_amount = buy_amount;
    return *this;
}

uint16_t CliStoreTradeReq::BuySellItem::get_buy_amount() const {
    return data.buy_amount;
}

CliStoreTradeReq::BuySellItem& CliStoreTradeReq::BuySellItem::set_sell_inventory_idx(const uint8_t sell_inventory_idx) {
    this->data.sell_inventory_idx = sell_inventory_idx;
    return *this;
}

uint8_t CliStoreTradeReq::BuySellItem::get_sell_inventory_idx() const {
    return data.sell_inventory_idx;
}

CliStoreTradeReq::BuySellItem& CliStoreTradeReq::BuySellItem::set_sell_amount(const uint16_t sell_amount) {
    this->data.sell_amount = sell_amount;
    return *this;
}

uint16_t CliStoreTradeReq::BuySellItem::get_sell_amount() const {
    return data.sell_amount;
}

CliStoreTradeReq::BuySellItem& CliStoreTradeReq::BuySellItem::set_data(const uint32_t data) {
    this->data.data = data;
    return *this;
}

uint32_t CliStoreTradeReq::BuySellItem::get_data() const {
    return data.data;
}

bool CliStoreTradeReq::BuySellItem::write(CRoseBasePolicy& writer) const {
    if (!writer.set_uint32_t(data.data)) {
        return false;
    }
    return true;
}

bool CliStoreTradeReq::BuySellItem::read(CRoseReader& reader) {
    if (!reader.get_uint32_t(data.data)) {
        return false;
    }
    return true;
}

constexpr size_t CliStoreTradeReq::BuySellItem::size() {
    return sizeof(data);
}


CliStoreTradeReq::CliStoreTradeReq() : CRosePacket(CliStoreTradeReq::PACKET_ID) {}

CliStoreTradeReq::CliStoreTradeReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(npc_id)) {
        return;
    }
    if (!reader.get_uint8_t(is_buy)) {
        return;
    }
    if (!reader.get_uint8_t(is_sell)) {
        return;
    }
    if (!reader.get_uint32_t(time)) {
        return;
    }
    if (!reader.get_iserialize(item)) {
        return;
    }
}

CliStoreTradeReq& CliStoreTradeReq::set_npc_id(const uint16_t npc_id) {
    this->npc_id = npc_id;
    return *this;
}

uint16_t CliStoreTradeReq::get_npc_id() const {
    return npc_id;
}

CliStoreTradeReq& CliStoreTradeReq::set_is_buy(const uint8_t is_buy) {
    this->is_buy = is_buy;
    return *this;
}

uint8_t CliStoreTradeReq::get_is_buy() const {
    return is_buy;
}

CliStoreTradeReq& CliStoreTradeReq::set_is_sell(const uint8_t is_sell) {
    this->is_sell = is_sell;
    return *this;
}

uint8_t CliStoreTradeReq::get_is_sell() const {
    return is_sell;
}

CliStoreTradeReq& CliStoreTradeReq::set_time(const uint32_t time) {
    this->time = time;
    return *this;
}

uint32_t CliStoreTradeReq::get_time() const {
    return time;
}

CliStoreTradeReq& CliStoreTradeReq::set_item(const CliStoreTradeReq::BuySellItem item) {
    this->item = item;
    return *this;
}

CliStoreTradeReq::BuySellItem CliStoreTradeReq::get_item() const {
    return item;
}

CliStoreTradeReq CliStoreTradeReq::create(const uint16_t& npc_id, const uint8_t& is_buy, const uint8_t& is_sell, const uint32_t& time, const CliStoreTradeReq::BuySellItem& item) {
    CliStoreTradeReq packet;
    packet.set_npc_id(npc_id);
    packet.set_is_buy(is_buy);
    packet.set_is_sell(is_sell);
    packet.set_time(time);
    packet.set_item(item);
    return packet;
}

CliStoreTradeReq CliStoreTradeReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliStoreTradeReq(reader);
}

std::unique_ptr<CliStoreTradeReq> CliStoreTradeReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliStoreTradeReq>(reader);
}

bool CliStoreTradeReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(npc_id)) {
        return false;
    }
    if (!writer.set_uint8_t(is_buy)) {
        return false;
    }
    if (!writer.set_uint8_t(is_sell)) {
        return false;
    }
    if (!writer.set_uint32_t(time)) {
        return false;
    }
    if (!writer.set_iserialize(item)) {
        return false;
    }
    return true;
}

constexpr size_t CliStoreTradeReq::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // npc_id
    size += sizeof(uint8_t); // is_buy
    size += sizeof(uint8_t); // is_sell
    size += sizeof(uint32_t); // time
    size += BuySellItem::size(); // item
    return size;
}

