#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvMemo : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_MEMO;
        SrvMemo();
        SrvMemo(CRoseReader reader);
        SrvMemo(SrvMemo&&) = default;
        SrvMemo& operator=(SrvMemo&&) = default;
        ~SrvMemo() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static SrvMemo create();
        static SrvMemo create(const uint8_t* buffer);
        static std::unique_ptr<SrvMemo> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
