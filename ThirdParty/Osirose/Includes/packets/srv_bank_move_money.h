#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvBankMoveMoney : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_BANK_MOVE_MONEY;
        SrvBankMoveMoney();
        SrvBankMoveMoney(CRoseReader reader);
        SrvBankMoveMoney(SrvBankMoveMoney&&) = default;
        SrvBankMoveMoney& operator=(SrvBankMoveMoney&&) = default;
        ~SrvBankMoveMoney() = default;
        
        static constexpr size_t size();
        
        
        
        SrvBankMoveMoney& set_inventory(const int64_t  );
        int64_t   get_inventory() const;
        SrvBankMoveMoney& set_bank(const int64_t);
        int64_t get_bank() const;
        
        
        static SrvBankMoveMoney create(const int64_t  & inventory, const int64_t& bank);
        static SrvBankMoveMoney create(const uint8_t* buffer);
        static std::unique_ptr<SrvBankMoveMoney> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int64_t   inventory;
        int64_t bank;
};

}
}
