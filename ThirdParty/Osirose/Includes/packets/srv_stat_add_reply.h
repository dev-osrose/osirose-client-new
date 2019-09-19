#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvStatAddReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_STAT_ADD_REPLY;
        SrvStatAddReply();
        SrvStatAddReply(CRoseReader reader);
        SrvStatAddReply(SrvStatAddReply&&) = default;
        SrvStatAddReply& operator=(SrvStatAddReply&&) = default;
        ~SrvStatAddReply() = default;
        
        static constexpr size_t size();
        
        
        enum Stat : uint8_t {
            STR = 0,
            DEX = 1,
            INT = 2,
            CON = 3,
            CHA = 4,
            SEN = 5,
        };
        
        
        SrvStatAddReply& set_stat(const Stat);
        Stat get_stat() const;
        SrvStatAddReply& set_value(const int16_t);
        int16_t get_value() const;
        
        
        static SrvStatAddReply create(const Stat& stat, const int16_t& value);
        static SrvStatAddReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvStatAddReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        Stat stat;
        int16_t value;
};

}
}
