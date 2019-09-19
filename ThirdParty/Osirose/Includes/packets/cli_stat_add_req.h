#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliStatAddReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_STAT_ADD_REQ;
        CliStatAddReq();
        CliStatAddReq(CRoseReader reader);
        CliStatAddReq(CliStatAddReq&&) = default;
        CliStatAddReq& operator=(CliStatAddReq&&) = default;
        ~CliStatAddReq() = default;
        
        static constexpr size_t size();
        
        
        enum Stat : uint8_t {
            STR = 0,
            DEX = 1,
            INT = 2,
            CON = 3,
            CHA = 4,
            SEN = 5,
        };
        
        
        CliStatAddReq& set_stat(const Stat);
        Stat get_stat() const;
        
        
        static CliStatAddReq create(const Stat& stat);
        static CliStatAddReq create(const uint8_t* buffer);
        static std::unique_ptr<CliStatAddReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        Stat stat;
};

}
}
