#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSetMoney : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SET_MONEY;
        SrvSetMoney();
        SrvSetMoney(CRoseReader reader);
        SrvSetMoney(SrvSetMoney&&) = default;
        SrvSetMoney& operator=(SrvSetMoney&&) = default;
        ~SrvSetMoney() = default;
        
        static constexpr size_t size();
        
        
        
        SrvSetMoney& set_zuly(const int64_t);
        int64_t get_zuly() const;
        
        
        static SrvSetMoney create(const int64_t& zuly);
        static SrvSetMoney create(const uint8_t* buffer);
        static std::unique_ptr<SrvSetMoney> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int64_t zuly;
};

}
}
