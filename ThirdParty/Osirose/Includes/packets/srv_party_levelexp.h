#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvPartyLevelexp : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_LEVELEXP;
        SrvPartyLevelexp();
        SrvPartyLevelexp(CRoseReader reader);
        SrvPartyLevelexp(SrvPartyLevelexp&&) = default;
        SrvPartyLevelexp& operator=(SrvPartyLevelexp&&) = default;
        ~SrvPartyLevelexp() = default;
        
        static constexpr size_t size();
        
        
        struct PartyExpData : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            PartyExpData& set_exp(const uint32_t);
            uint32_t get_exp() const;
            PartyExpData& set_level_up(const uint32_t);
            uint32_t get_level_up() const;
            PartyExpData& set_data(const uint32_t);
            uint32_t get_data() const;
            
            private:
                union {
                    PACK(struct {
                        uint32_t exp : 31;
                        uint32_t level_up : 1;
                    });
                    uint32_t data;
                } data;
        };
        
        
        SrvPartyLevelexp& set_level(const uint8_t);
        uint8_t get_level() const;
        SrvPartyLevelexp& set_exp_data(const PartyExpData);
        PartyExpData get_exp_data() const;
        
        
        static SrvPartyLevelexp create(const uint8_t& level, const PartyExpData& exp_data);
        static SrvPartyLevelexp create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyLevelexp> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t level;
        PartyExpData exp_data;
};

}
}
