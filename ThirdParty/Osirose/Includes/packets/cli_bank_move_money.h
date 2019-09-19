#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliBankMoveMoney : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_BANK_MOVE_MONEY;
        CliBankMoveMoney();
        CliBankMoveMoney(CRoseReader reader);
        CliBankMoveMoney(CliBankMoveMoney&&) = default;
        CliBankMoveMoney& operator=(CliBankMoveMoney&&) = default;
        ~CliBankMoveMoney() = default;
        
        static constexpr size_t size();
        
        
        enum BankMoveMode : uint8_t {
            INVENTORY_TO_BANK = 16,
            BANK_TO_INVENTORY = 17,
        };
        
        
        CliBankMoveMoney& set_mode(const BankMoveMode);
        BankMoveMode get_mode() const;
        CliBankMoveMoney& set_amount(const int64_t);
        int64_t get_amount() const;
        
        
        static CliBankMoveMoney create(const BankMoveMode& mode, const int64_t& amount);
        static CliBankMoveMoney create(const uint8_t* buffer);
        static std::unique_ptr<CliBankMoveMoney> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        BankMoveMode mode;
        int64_t amount;
};

}
}
