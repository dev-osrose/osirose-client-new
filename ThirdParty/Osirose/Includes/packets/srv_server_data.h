#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvServerData : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SERVER_DATA;
        SrvServerData();
        SrvServerData(CRoseReader reader);
        SrvServerData(SrvServerData&&) = default;
        SrvServerData& operator=(SrvServerData&&) = default;
        ~SrvServerData() = default;
        
        static constexpr size_t size();
        
        
        
        
        
        static SrvServerData create();
        static SrvServerData create(const uint8_t* buffer);
        static std::unique_ptr<SrvServerData> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
};

}
}
