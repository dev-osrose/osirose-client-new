#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvSkillDamage : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SKILL_DAMAGE;
        SrvSkillDamage();
        SrvSkillDamage(CRoseReader reader);
        SrvSkillDamage(SrvSkillDamage&&) = default;
        SrvSkillDamage& operator=(SrvSkillDamage&&) = default;
        ~SrvSkillDamage() = default;
        
        static constexpr size_t size();
        
        
        struct Header : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            Header& set_type(const unsigned int);
            unsigned int get_type() const;
            Header& set_id(const unsigned int);
            unsigned int get_id() const;
            Header& set_isCreated(const unsigned int);
            unsigned int get_isCreated() const;
            Header& set_header(const uint16_t);
            uint16_t get_header() const;
            
            private:
                union {
                    PACK(struct {
                        unsigned int type : 5;
                        unsigned int id : 10;
                        unsigned int isCreated : 1;
                    });
                    uint16_t header = 0;
                } data;
        };
        
        struct Data : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            Data& set_gem_opt(const unsigned int);
            unsigned int get_gem_opt() const;
            Data& set_durability(const unsigned int);
            unsigned int get_durability() const;
            Data& set_life(const unsigned int);
            unsigned int get_life() const;
            Data& set_hasSocket(const unsigned int);
            unsigned int get_hasSocket() const;
            Data& set_isAppraised(const unsigned int);
            unsigned int get_isAppraised() const;
            Data& set_refine(const unsigned int);
            unsigned int get_refine() const;
            Data& set_count(const uint32_t);
            uint32_t get_count() const;
            
            private:
                union {
                    PACK(struct {
                        unsigned int gem_opt : 9;
                        unsigned int durability : 7;
                        unsigned int life : 10;
                        unsigned int hasSocket : 1;
                        unsigned int isAppraised : 1;
                        unsigned int refine : 4;
                    });
                    uint32_t count = 0;
                } data;
        };
        
        struct Item : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            Item& set_header(const Header);
            Header get_header() const;
            Item& set_data(const Data);
            Data get_data() const;
            
            private:
                Header header = {};
                Data data = {};
        };
        
        
        SrvSkillDamage& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvSkillDamage& set_source(const uint16_t);
        uint16_t get_source() const;
        SrvSkillDamage& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvSkillDamage& set_amount(const float);
        float get_amount() const;
        SrvSkillDamage& set_state(const uint8_t);
        uint8_t get_state() const;
        SrvSkillDamage& set_damage(const uint32_t);
        uint32_t get_damage() const;
        SrvSkillDamage& set_action(const uint32_t);
        uint32_t get_action() const;
        SrvSkillDamage& set_item(const Item);
        Item get_item() const;
        
        
        static SrvSkillDamage create(const uint16_t& target, const uint16_t& source, const uint16_t& id, const float& amount, const uint8_t& state, const uint32_t& damage, const uint32_t& action);
        static SrvSkillDamage create(const uint8_t* buffer);
        static std::unique_ptr<SrvSkillDamage> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        uint16_t source;
        uint16_t id;
        float amount;
        uint8_t state;
        uint32_t damage;
        uint32_t action;
        Item item = {};
};

}
}
