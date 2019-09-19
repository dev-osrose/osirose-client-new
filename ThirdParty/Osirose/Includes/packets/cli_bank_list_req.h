#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliBankListReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_BANK_LIST_REQ;
        CliBankListReq();
        CliBankListReq(CRoseReader reader);
        CliBankListReq(CliBankListReq&&) = default;
        CliBankListReq& operator=(CliBankListReq&&) = default;
        ~CliBankListReq() = default;
        
        static constexpr size_t size();
        
        
        enum BankListRequest : uint8_t {
            OPEN = 0,
            CHANGE_PASSWORD = 17,
        };
        
        
        CliBankListReq& set_request(const BankListRequest);
        BankListRequest get_request() const;
        CliBankListReq& set_password(const std::string&);
        const std::string& get_password() const;
        
        
        static CliBankListReq create(const BankListRequest& request, const std::string& password);
        static CliBankListReq create(const uint8_t* buffer);
        static std::unique_ptr<CliBankListReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        BankListRequest request;
        std::string password;
};

}
}
