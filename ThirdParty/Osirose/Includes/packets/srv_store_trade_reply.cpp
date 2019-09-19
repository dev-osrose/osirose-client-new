#include "srv_store_trade_reply.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



SrvStoreTradeReply::SrvStoreTradeReply() : CRosePacket(SrvStoreTradeReply::PACKET_ID) {}

SrvStoreTradeReply::SrvStoreTradeReply(CRoseReader reader) : CRosePacket(reader) {
    uint8_t result_temp;
    if (!reader.get_uint8_t(result_temp)) {
        return;
    }
    result = static_cast<StoreTradeResult>(result_temp);
    
}

SrvStoreTradeReply& SrvStoreTradeReply::set_result(const SrvStoreTradeReply::StoreTradeResult result) {
    this->result = result;
    return *this;
}

SrvStoreTradeReply::StoreTradeResult SrvStoreTradeReply::get_result() const {
    return result;
}

SrvStoreTradeReply SrvStoreTradeReply::create(const SrvStoreTradeReply::StoreTradeResult& result) {
    SrvStoreTradeReply packet;
    packet.set_result(result);
    return packet;
}

SrvStoreTradeReply SrvStoreTradeReply::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return SrvStoreTradeReply(reader);
}

std::unique_ptr<SrvStoreTradeReply> SrvStoreTradeReply::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<SrvStoreTradeReply>(reader);
}

bool SrvStoreTradeReply::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(result)) {
        return false;
    }
    return true;
}

constexpr size_t SrvStoreTradeReply::size() {
    size_t size = 0;
    size += sizeof(StoreTradeResult); // result
    return size;
}

