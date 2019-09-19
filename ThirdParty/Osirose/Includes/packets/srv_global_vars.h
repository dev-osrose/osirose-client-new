#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include "dataconsts.h"
#include <array>

namespace RoseCommon {
namespace Packet {

class SrvGlobalVars : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_GLOBAL_VARS;
        SrvGlobalVars();
        SrvGlobalVars(CRoseReader reader);
        SrvGlobalVars(SrvGlobalVars&&) = default;
        SrvGlobalVars& operator=(SrvGlobalVars&&) = default;
        ~SrvGlobalVars() = default;
        
        static constexpr size_t size();
        
        
        
        SrvGlobalVars& set_world_product(const int16_t);
        int16_t get_world_product() const;
        SrvGlobalVars& set_update_time(const int32_t);
        int32_t get_update_time() const;
        SrvGlobalVars& set_world_rate(const int16_t);
        int16_t get_world_rate() const;
        SrvGlobalVars& set_town_rate(const uint8_t);
        uint8_t get_town_rate() const;
        SrvGlobalVars& set_item_rate(const std::array<uint8_t, MAX_SELL_TYPE>&);
        SrvGlobalVars& set_item_rate(const uint8_t&, size_t index);
        const std::array<uint8_t, MAX_SELL_TYPE>& get_item_rate() const;
        const uint8_t& get_item_rate(size_t index) const;
        SrvGlobalVars& set_flags(const uint32_t);
        uint32_t get_flags() const;
        
        
        static SrvGlobalVars create();
        static SrvGlobalVars create(const uint8_t* buffer);
        static std::unique_ptr<SrvGlobalVars> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        int16_t world_product = 100;
        int32_t update_time = 0;
        int16_t world_rate = 100;
        uint8_t town_rate = 100;
        std::array<uint8_t, MAX_SELL_TYPE> item_rate = {50};
        uint32_t flags = 0;
};

}
}
