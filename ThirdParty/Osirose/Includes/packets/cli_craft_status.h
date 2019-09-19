#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliCraftStatus : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CRAFT_STATUS;
        CliCraftStatus();
        CliCraftStatus(CRoseReader reader);
        CliCraftStatus(CliCraftStatus&&) = default;
        CliCraftStatus& operator=(CliCraftStatus&&) = default;
        ~CliCraftStatus() = default;
        
        static constexpr size_t size();
        
        
        enum CraftStatus : uint8_t {
            CRAFT_START = 0,
            CRAFT_SUCCESS = 1,
            CRAFT_FAIL = 2,
            UPGRADE_START = 3,
            UPGRADE_SUCCESS = 4,
            UPGRADE_FAIL = 5,
        };
        
        
        CliCraftStatus& set_stats(const CraftStatus);
        CraftStatus get_stats() const;
        CliCraftStatus& set_type(const int8_t);
        int8_t get_type() const;
        CliCraftStatus& set_id(const int16_t);
        int16_t get_id() const;
        
        
        static CliCraftStatus create(const CraftStatus& stats, const int8_t& type, const int16_t& id);
        static CliCraftStatus create(const uint8_t* buffer);
        static std::unique_ptr<CliCraftStatus> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        CraftStatus stats;
        int8_t type;
        int16_t id;
};

}
}
