#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvGlobalFlags : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_GLOBAL_FLAGS;
        SrvGlobalFlags();
        SrvGlobalFlags(CRoseReader reader);
        SrvGlobalFlags(SrvGlobalFlags&&) = default;
        SrvGlobalFlags& operator=(SrvGlobalFlags&&) = default;
        ~SrvGlobalFlags() = default;
        
        static constexpr size_t size();
        
        
        
        SrvGlobalFlags& set_flags(const int32_t);
        int32_t get_flags() const;
        
        
        static SrvGlobalFlags create(const int32_t& flags);
        static SrvGlobalFlags create(const uint8_t* buffer);
        static std::unique_ptr<SrvGlobalFlags> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int32_t flags;
};

}
}
