#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include "dataconsts.h"
#include <array>

namespace RoseCommon {
namespace Packet {

class SrvQuestData : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_QUEST_DATA;
        SrvQuestData();
        SrvQuestData(CRoseReader reader);
        SrvQuestData(SrvQuestData&&) = default;
        SrvQuestData& operator=(SrvQuestData&&) = default;
        ~SrvQuestData() = default;
        
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
        
        struct Quest : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            Quest& set_id(const uint16_t);
            uint16_t get_id() const;
            Quest& set_timer(const uint32_t);
            uint32_t get_timer() const;
            Quest& set_vars(const std::array<uint16_t, MAX_QUEST_VARS>);
            Quest& set_vars(const uint16_t, size_t index);
            std::array<uint16_t, MAX_QUEST_VARS> get_vars() const;
            uint16_t get_vars(size_t index) const;
            Quest& set_switches(const uint32_t);
            uint32_t get_switches() const;
            Quest& set_items(const std::array<Item, MAX_QUEST_ITEMS>);
            Quest& set_items(const Item, size_t index);
            std::array<Item, MAX_QUEST_ITEMS> get_items() const;
            Item get_items(size_t index) const;
            
            private:
                uint16_t id = 0;
                // timer: Unlimited if 0
                uint32_t timer = 0;
                std::array<uint16_t, MAX_QUEST_VARS> vars = {0};
                uint32_t switches = 0;
                std::array<Item, MAX_QUEST_ITEMS> items = {};
        };
        
        
        SrvQuestData& set_episodes(const std::array<uint16_t, MAX_CONDITIONS_EPISODE>);
        SrvQuestData& set_episodes(const uint16_t, size_t index);
        std::array<uint16_t, MAX_CONDITIONS_EPISODE> get_episodes() const;
        uint16_t get_episodes(size_t index) const;
        SrvQuestData& set_jobs(const std::array<uint16_t, MAX_CONDITIONS_JOB>);
        SrvQuestData& set_jobs(const uint16_t, size_t index);
        std::array<uint16_t, MAX_CONDITIONS_JOB> get_jobs() const;
        uint16_t get_jobs(size_t index) const;
        SrvQuestData& set_planets(const std::array<uint16_t, MAX_CONDITIONS_PLANET>);
        SrvQuestData& set_planets(const uint16_t, size_t index);
        std::array<uint16_t, MAX_CONDITIONS_PLANET> get_planets() const;
        uint16_t get_planets(size_t index) const;
        SrvQuestData& set_unions(const std::array<uint16_t, MAX_CONDITIONS_UNION>);
        SrvQuestData& set_unions(const uint16_t, size_t index);
        std::array<uint16_t, MAX_CONDITIONS_UNION> get_unions() const;
        uint16_t get_unions(size_t index) const;
        SrvQuestData& set_quests(const std::array<Quest, MAX_QUESTS>&);
        SrvQuestData& set_quests(const Quest&, size_t index);
        const std::array<Quest, MAX_QUESTS>& get_quests() const;
        const Quest& get_quests(size_t index) const;
        SrvQuestData& set_switches(const std::array<uint32_t, MAX_SWITCHES>);
        SrvQuestData& set_switches(const uint32_t, size_t index);
        std::array<uint32_t, MAX_SWITCHES> get_switches() const;
        uint32_t get_switches(size_t index) const;
        SrvQuestData& set_wishlist(const std::array<Item, MAX_WISHLIST>);
        SrvQuestData& set_wishlist(const Item, size_t index);
        std::array<Item, MAX_WISHLIST> get_wishlist() const;
        Item get_wishlist(size_t index) const;
        
        
        static SrvQuestData create();
        static SrvQuestData create(const uint8_t* buffer);
        static std::unique_ptr<SrvQuestData> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::array<uint16_t, MAX_CONDITIONS_EPISODE> episodes = {0};
        std::array<uint16_t, MAX_CONDITIONS_JOB> jobs = {0};
        std::array<uint16_t, MAX_CONDITIONS_PLANET> planets = {0};
        std::array<uint16_t, MAX_CONDITIONS_UNION> unions = {0};
        std::array<Quest, MAX_QUESTS> quests = {};
        std::array<uint32_t, MAX_SWITCHES> switches = {0};
        std::array<Item, MAX_WISHLIST> wishlist = {};
};

}
}
