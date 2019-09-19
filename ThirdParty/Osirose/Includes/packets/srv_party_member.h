#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvPartyMember : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_PARTY_MEMBER;
        SrvPartyMember();
        SrvPartyMember(CRoseReader reader);
        SrvPartyMember(SrvPartyMember&&) = default;
        SrvPartyMember& operator=(SrvPartyMember&&) = default;
        ~SrvPartyMember() = default;
        
        static constexpr size_t size();
        
        
        enum PartyRule : uint8_t {
            EXP_PER_PLAYER = 0,
            ITEM_IN_ORDER = 1,
        };
        
        enum PartyMemberAction : int8_t {
            REMOVE = -1,
            ADD = 0,
        };
        
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
        
        
        SrvPartyMember& set_rule(const PartyRule);
        PartyRule get_rule() const;
        SrvPartyMember& set_action(const PartyMemberAction);
        PartyMemberAction get_action() const;
        SrvPartyMember& set_member(const PartyMember);
        PartyMember get_member() const;
        
        
        static SrvPartyMember create(const PartyRule& rule, const PartyMemberAction& action, const PartyMember& member);
        static SrvPartyMember create(const uint8_t* buffer);
        static std::unique_ptr<SrvPartyMember> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        PartyRule rule;
        PartyMemberAction action;
        PartyMember member;
};

}
}
