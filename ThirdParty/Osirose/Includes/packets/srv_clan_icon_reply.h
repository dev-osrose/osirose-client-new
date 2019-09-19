#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class SrvClanIconReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CLAN_ICON_REPLY;
        SrvClanIconReply();
        SrvClanIconReply(CRoseReader reader);
        SrvClanIconReply(SrvClanIconReply&&) = default;
        SrvClanIconReply& operator=(SrvClanIconReply&&) = default;
        ~SrvClanIconReply() = default;
        
        static constexpr size_t size();
        
        
        enum IconError : uint16_t {
            TOO_MANY_UPDATES = 0,
            DB_ERROR = 1,
            SP_ERROR = 2,
        };
        
        
        SrvClanIconReply& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvClanIconReply& set_data(const std::vector<uint8_t>);
        SrvClanIconReply& add_data(const uint8_t);
        std::vector<uint8_t> get_data() const;
        uint8_t get_data(size_t index) const;
        
        
        static SrvClanIconReply create(const uint16_t& id, const std::vector<uint8_t>& data);
        static SrvClanIconReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvClanIconReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        std::vector<uint8_t> data;
};

}
}
