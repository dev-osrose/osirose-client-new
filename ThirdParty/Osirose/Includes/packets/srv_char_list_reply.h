#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include "dataconsts.h"
#include <string>
#include <vector>

namespace RoseCommon {
namespace Packet {

class SrvCharListReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCC_CHAR_LIST_REPLY;
        SrvCharListReply();
        SrvCharListReply(CRoseReader reader);
        SrvCharListReply(SrvCharListReply&&) = default;
        SrvCharListReply& operator=(SrvCharListReply&&) = default;
        ~SrvCharListReply() = default;
        
        static constexpr size_t size();
        
        
        enum EquippedPosition : uint8_t {
            HELMET = 0,
            ARMOR = 1,
            GAUNTLET = 2,
            BOOTS = 3,
            GOOGLES = 4,
            BACKPACK = 5,
            WEAPON_R = 6,
            WEAPON_L = 7,
            MAX_ITEMS = 8,
        };
        
        struct EquippedItem : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            EquippedItem& set_id(const unsigned int);
            unsigned int get_id() const;
            EquippedItem& set_gem_opt(const unsigned int);
            unsigned int get_gem_opt() const;
            EquippedItem& set_socket(const unsigned int);
            unsigned int get_socket() const;
            EquippedItem& set_grade(const unsigned int);
            unsigned int get_grade() const;
            EquippedItem& set_data(const uint32_t);
            uint32_t get_data() const;
            
            private:
                union {
                    PACK(struct {
                        unsigned int id : 10;
                        unsigned int gem_opt : 9;
                        unsigned int socket : 1;
                        unsigned int grade : 4;
                    });
                    uint32_t data = 0;
                } data;
        };
        
        struct CharInfo : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            CharInfo& set_name(const std::string&);
            const std::string& get_name() const;
            CharInfo& set_race(const uint8_t);
            uint8_t get_race() const;
            CharInfo& set_level(const uint16_t);
            uint16_t get_level() const;
            CharInfo& set_job(const uint16_t);
            uint16_t get_job() const;
            CharInfo& set_remainSecsUntilDelete(const uint32_t);
            uint32_t get_remainSecsUntilDelete() const;
            CharInfo& set_platinium(const uint8_t);
            uint8_t get_platinium() const;
            CharInfo& set_face(const uint32_t);
            uint32_t get_face() const;
            CharInfo& set_hair(const uint32_t);
            uint32_t get_hair() const;
            CharInfo& set_items(const std::array<EquippedItem, MAX_VISIBLE_ITEMS>&);
            CharInfo& set_items(const EquippedItem&, size_t index);
            const std::array<EquippedItem, MAX_VISIBLE_ITEMS>& get_items() const;
            const EquippedItem& get_items(size_t index) const;
            
            private:
                std::string name;
                uint8_t race;
                uint16_t level;
                uint16_t job;
                uint32_t remainSecsUntilDelete;
                uint8_t platinium = 0;
                uint32_t face;
                uint32_t hair;
                std::array<EquippedItem, MAX_VISIBLE_ITEMS> items;
        };
        
        
        SrvCharListReply& set_characters(const std::vector<CharInfo>&);
        SrvCharListReply& add_characters(const CharInfo&);
        const std::vector<CharInfo>& get_characters() const;
        const CharInfo& get_characters(size_t index) const;
        
        
        static SrvCharListReply create();
        static SrvCharListReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvCharListReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::vector<CharInfo> characters;
};

}
}
