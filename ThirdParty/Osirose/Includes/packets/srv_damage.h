#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvDamage : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_DAMAGE;
        SrvDamage();
        SrvDamage(CRoseReader reader);
        SrvDamage(SrvDamage&&) = default;
        SrvDamage& operator=(SrvDamage&&) = default;
        ~SrvDamage() = default;
        
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
        
        
        SrvDamage& set_attackerId(const uint16_t);
        uint16_t get_attackerId() const;
        SrvDamage& set_defenderId(const uint16_t);
        uint16_t get_defenderId() const;
        SrvDamage& set_damage(const uint32_t);
        uint32_t get_damage() const;
        SrvDamage& set_action(const uint32_t);
        uint32_t get_action() const;
        SrvDamage& set_x(const float);
        float get_x() const;
        SrvDamage& set_y(const float);
        float get_y() const;
        SrvDamage& set_item(const Item);
        Item get_item() const;
        SrvDamage& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvDamage& set_ownerId(const uint16_t);
        uint16_t get_ownerId() const;
        
        
        static SrvDamage create(const uint16_t& attackerId, const uint16_t& defenderId, const uint32_t& damage, const uint32_t& action);
        static SrvDamage create(const uint8_t* buffer);
        static std::unique_ptr<SrvDamage> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t attackerId;
        uint16_t defenderId;
        uint32_t damage;
        uint32_t action;
        float x = 0.f;
        float y = 0.f;
        Item item = {};
        uint16_t id = 0;
        uint16_t ownerId = 0;
};

}
}
