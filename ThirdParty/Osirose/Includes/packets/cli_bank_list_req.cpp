#include "cli_bank_list_req.h"

using namespace RoseCommon;
using namespace RoseCommon::Packet;



CliBankListReq::CliBankListReq() : CRosePacket(CliBankListReq::PACKET_ID) {}

CliBankListReq::CliBankListReq(CRoseReader reader) : CRosePacket(reader) {
    uint8_t request_temp;
    if (!reader.get_uint8_t(request_temp)) {
        return;
    }
    request = static_cast<BankListRequest>(request_temp);
    
    if (!reader.get_string(password)) {
        return;
    }
}

CliBankListReq& CliBankListReq::set_request(const CliBankListReq::BankListRequest request) {
    this->request = request;
    return *this;
}

CliBankListReq::BankListRequest CliBankListReq::get_request() const {
    return request;
}

CliBankListReq& CliBankListReq::set_password(const std::string& password) {
    this->password = password;
    return *this;
}

const std::string& CliBankListReq::get_password() const {
    return password;
}

CliBankListReq CliBankListReq::create(const CliBankListReq::BankListRequest& request, const std::string& password) {
    CliBankListReq packet;
    packet.set_request(request);
    packet.set_password(password);
    return packet;
}

CliBankListReq CliBankListReq::create(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return CliBankListReq(reader);
}

std::unique_ptr<CliBankListReq> CliBankListReq::allocate(const uint8_t* buffer) {
    CRoseReader reader(buffer, CRosePacket::size(buffer));
    return std::make_unique<CliBankListReq>(reader);
}

bool CliBankListReq::pack(CRoseBasePolicy& writer) const {
    if (!writer.set_uint8_t(request)) {
        return false;
    }
    if (!writer.set_string(password)) {
        return false;
    }
    return true;
}

constexpr size_t CliBankListReq::size() {
    size_t size = 0;
    size += sizeof(BankListRequest); // request
    return size;
}

