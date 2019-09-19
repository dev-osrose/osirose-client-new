#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class CliClanIconSet : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CLAN_ICON_SET;
        CliClanIconSet();
        CliClanIconSet(CRoseReader reader);
        CliClanIconSet(CliClanIconSet&&) = default;
        CliClanIconSet& operator=(CliClanIconSet&&) = default;
        ~CliClanIconSet() = default;
        
        static constexpr size_t size();
        
        
        
        CliClanIconSet& set_crc(const uint16_t);
        uint16_t get_crc() const;
        CliClanIconSet& set_data(const std::vector<uint8_t>);
        CliClanIconSet& add_data(const uint8_t);
        std::vector<uint8_t> get_data() const;
        uint8_t get_data(size_t index) const;
        
        
        static CliClanIconSet create(const uint16_t& crc, const std::vector<uint8_t>& data);
        static CliClanIconSet create(const uint8_t* buffer);
        static std::unique_ptr<CliClanIconSet> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t crc;
        std::vector<uint8_t> data;
};

}
}
