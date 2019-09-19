#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvCraftStatus : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CRAFT_STATUS;
        SrvCraftStatus();
        SrvCraftStatus(CRoseReader reader);
        SrvCraftStatus(SrvCraftStatus&&) = default;
        SrvCraftStatus& operator=(SrvCraftStatus&&) = default;
        ~SrvCraftStatus() = default;
        
        static constexpr size_t size();
        
        
        enum CraftStatus : uint8_t {
            CRAFT_START = 0,
            CRAFT_SUCCESS = 1,
            CRAFT_FAIL = 2,
            UPGRADE_START = 3,
            UPGRADE_SUCCESS = 4,
            UPGRADE_FAIL = 5,
        };
        
        
        SrvCraftStatus& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvCraftStatus& set_stats(const CraftStatus);
        CraftStatus get_stats() const;
        SrvCraftStatus& set_type(const int8_t);
        int8_t get_type() const;
        SrvCraftStatus& set_id(const int16_t);
        int16_t get_id() const;
        
        
        static SrvCraftStatus create(const uint16_t& target, const CraftStatus& stats, const int8_t& type, const int16_t& id);
        static SrvCraftStatus create(const uint8_t* buffer);
        static std::unique_ptr<SrvCraftStatus> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        CraftStatus stats;
        int8_t type;
        int16_t id;
};

}
}
