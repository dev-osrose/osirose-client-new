#include "cli_pickup_item_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliPickupItemReq::CliPickupItemReq() : CRosePacket(CliPickupItemReq::PACKET_ID) {}

CliPickupItemReq::CliPickupItemReq(CRoseReader reader) : CRosePacket(reader) {
    if (!reader.get_uint16_t(item_id)) {
        return;
    }
}

CliPickupItemReq& CliPickupItemReq::set_item_id(const uint16_t item_id) {
    this->item_id = item_id;
    return *this;
}

uint16_t CliPickupItemReq::get_item_id() const {
    return item_id;
}

CliPickupItemReq CliPickupItemReq::create(const uint16_t& item_id) {
    CliPickupItemReq packet;
    packet.set_item_id(item_id);
    return packet;
}

CliPickupItemReq CliPickupItemReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliPickupItemReq(reader);
}

std::unique_ptr<CliPickupItemReq> CliPickupItemReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliPickupItemReq>(reader);
}

bool CliPickupItemReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint16_t(item_id)) {
        return false;
    }
    return true;
}

constexpr size_t CliPickupItemReq::size() {
    size_t size = 0;
    size += sizeof(uint16_t); // item_id
    return size;
}

