#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvPartyMemberUpdate : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_MEMBER_UPDATE;
        SrvPartyMemberUpdate();
        SrvPartyMemberUpdate(CRoseReader reader);
        SrvPartyMemberUpdate(SrvPartyMemberUpdate&&) = default;
        SrvPartyMemberUpdate& operator=(SrvPartyMemberUpdate&&) = default;
        ~SrvPartyMemberUpdate() = default;
        
        static constexpr size_t size();
        
        
        struct PartyMember : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            PartyMember& set_tag(const uint32_t);
            uint32_t get_tag() const;
            PartyMember& set_id(const uint16_t);
            uint16_t get_id() const;
            PartyMember& set_max_hp(const uint32_t);
            uint32_t get_max_hp() const;
            PartyMember& set_hp(const uint32_t);
            uint32_t get_hp() const;
            PartyMember& set_status(const uint32_t);
            uint32_t get_status() const;
            PartyMember& set_con(const uint16_t);
            uint16_t get_con() const;
            PartyMember& set_hp_recovery(const uint16_t);
            uint16_t get_hp_recovery() const;
            PartyMember& set_mp_recovery(const uint16_t);
            uint16_t get_mp_recovery() const;
            PartyMember& set_stamina(const int16_t);
            int16_t get_stamina() const;
            
            private:
                uint32_t tag;
                uint16_t id;
                uint32_t max_hp;
                uint32_t hp;
                uint32_t status;
                uint16_t con;
                uint16_t hp_recovery;
                uint16_t mp_recovery;
                int16_t stamina;
        };
        
        
        SrvPartyMemberUpdate& set_member(const PartyMember);
        PartyMember get_member() const;
        
        
        static SrvPartyMemberUpdate create(const PartyMember& member);
        static SrvPartyMemberUpdate create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyMemberUpdate> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyMember member;
};

}
}
