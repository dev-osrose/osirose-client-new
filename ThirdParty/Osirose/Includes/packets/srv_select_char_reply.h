#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include "dataconsts.h"
#include <string>
#include <array>

namespace RoseCommon {
namespace Packet {

class SrvSelectCharReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_SELECT_CHAR_REPLY;
        SrvSelectCharReply();
        SrvSelectCharReply(CRoseReader reader);
        SrvSelectCharReply(SrvSelectCharReply&&) = default;
        SrvSelectCharReply& operator=(SrvSelectCharReply&&) = default;
        ~SrvSelectCharReply() = default;
        
        static constexpr size_t size();
        
        
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
        
        
        SrvSelectCharReply& set_race(const uint8_t);
        uint8_t get_race() const;
        SrvSelectCharReply& set_map(const uint16_t);
        uint16_t get_map() const;
        SrvSelectCharReply& set_x(const float);
        float get_x() const;
        SrvSelectCharReply& set_y(const float);
        float get_y() const;
        SrvSelectCharReply& set_spawn(const uint16_t);
        uint16_t get_spawn() const;
        SrvSelectCharReply& set_bodyFace(const uint32_t);
        uint32_t get_bodyFace() const;
        SrvSelectCharReply& set_bodyHair(const uint32_t);
        uint32_t get_bodyHair() const;
        SrvSelectCharReply& set_equippedItems(const std::array<EquippedItem, MAX_VISIBLE_ITEMS>&);
        SrvSelectCharReply& set_equippedItems(const EquippedItem&, size_t index);
        const std::array<EquippedItem, MAX_VISIBLE_ITEMS>& get_equippedItems() const;
        const EquippedItem& get_equippedItems(size_t index) const;
        SrvSelectCharReply& set_stone(const uint8_t);
        uint8_t get_stone() const;
        SrvSelectCharReply& set_face(const uint8_t);
        uint8_t get_face() const;
        SrvSelectCharReply& set_hair(const uint8_t);
        uint8_t get_hair() const;
        SrvSelectCharReply& set_job(const uint16_t);
        uint16_t get_job() const;
        SrvSelectCharReply& set_factionId(const uint8_t);
        uint8_t get_factionId() const;
        SrvSelectCharReply& set_factionRank(const uint8_t);
        uint8_t get_factionRank() const;
        SrvSelectCharReply& set_fame(const uint8_t);
        uint8_t get_fame() const;
        SrvSelectCharReply& set_str(const uint16_t);
        uint16_t get_str() const;
        SrvSelectCharReply& set_dex(const uint16_t);
        uint16_t get_dex() const;
        SrvSelectCharReply& set_int_(const uint16_t);
        uint16_t get_int_() const;
        SrvSelectCharReply& set_con(const uint16_t);
        uint16_t get_con() const;
        SrvSelectCharReply& set_charm(const uint16_t);
        uint16_t get_charm() const;
        SrvSelectCharReply& set_sense(const uint16_t);
        uint16_t get_sense() const;
        SrvSelectCharReply& set_hp(const int32_t);
        int32_t get_hp() const;
        SrvSelectCharReply& set_mp(const int32_t);
        int32_t get_mp() const;
        SrvSelectCharReply& set_xp(const uint32_t);
        uint32_t get_xp() const;
        SrvSelectCharReply& set_level(const uint16_t);
        uint16_t get_level() const;
        SrvSelectCharReply& set_statPoints(const uint32_t);
        uint32_t get_statPoints() const;
        SrvSelectCharReply& set_skillPoints(const uint32_t);
        uint32_t get_skillPoints() const;
        SrvSelectCharReply& set_bodySize(const uint8_t);
        uint8_t get_bodySize() const;
        SrvSelectCharReply& set_headSize(const uint8_t);
        uint8_t get_headSize() const;
        SrvSelectCharReply& set_penaltyXp(const uint32_t);
        uint32_t get_penaltyXp() const;
        SrvSelectCharReply& set_factionFame(const std::array<uint16_t, 2>&);
        SrvSelectCharReply& set_factionFame(const uint16_t&, size_t index);
        const std::array<uint16_t, 2>& get_factionFame() const;
        const uint16_t& get_factionFame(size_t index) const;
        SrvSelectCharReply& set_factionPoints(const std::array<uint16_t, 10>&);
        SrvSelectCharReply& set_factionPoints(const uint16_t&, size_t index);
        const std::array<uint16_t, 10>& get_factionPoints() const;
        const uint16_t& get_factionPoints(size_t index) const;
        SrvSelectCharReply& set_guildId(const uint32_t);
        uint32_t get_guildId() const;
        SrvSelectCharReply& set_guildContribution(const uint16_t);
        uint16_t get_guildContribution() const;
        SrvSelectCharReply& set_guildRank(const uint8_t);
        uint8_t get_guildRank() const;
        SrvSelectCharReply& set_pkFlag(const uint16_t);
        uint16_t get_pkFlag() const;
        SrvSelectCharReply& set_stamina(const uint16_t);
        uint16_t get_stamina() const;
        SrvSelectCharReply& set_effects(const std::array<StatusEffect, MAX_STATUS_EFFECTS>&);
        SrvSelectCharReply& set_effects(const StatusEffect&, size_t index);
        const std::array<StatusEffect, MAX_STATUS_EFFECTS>& get_effects() const;
        const StatusEffect& get_effects(size_t index) const;
        SrvSelectCharReply& set_patHp(const uint16_t);
        uint16_t get_patHp() const;
        SrvSelectCharReply& set_patCooldownTime(const uint32_t);
        uint32_t get_patCooldownTime() const;
        SrvSelectCharReply& set_skills(const std::array<uint16_t, MAX_SKILL_COUNT>&);
        SrvSelectCharReply& set_skills(const uint16_t&, size_t index);
        const std::array<uint16_t, MAX_SKILL_COUNT>& get_skills() const;
        const uint16_t& get_skills(size_t index) const;
        SrvSelectCharReply& set_hotbar(const std::array<HotbarItem, MAX_HOTBAR_ITEMS>&);
        SrvSelectCharReply& set_hotbar(const HotbarItem&, size_t index);
        const std::array<HotbarItem, MAX_HOTBAR_ITEMS>& get_hotbar() const;
        const HotbarItem& get_hotbar(size_t index) const;
        SrvSelectCharReply& set_tag(const uint32_t);
        uint32_t get_tag() const;
        SrvSelectCharReply& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static SrvSelectCharReply create();
        static SrvSelectCharReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvSelectCharReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t race = 0;
        uint16_t map = 0;
        float x = 0;
        float y = 0;
        uint16_t spawn = 0;
        // It's actually the face that is expected here
        uint32_t bodyFace = 0;
        // It's actually the hair that is expected here
        uint32_t bodyHair = 0;
        std::array<EquippedItem, MAX_VISIBLE_ITEMS> equippedItems = {};
        uint8_t stone = 0;
        uint8_t face = 0;
        uint8_t hair = 0;
        uint16_t job = 0;
        uint8_t factionId = 0;
        uint8_t factionRank = 0;
        uint8_t fame = 0;
        uint16_t str = 0;
        uint16_t dex = 0;
        uint16_t int_ = 0;
        uint16_t con = 0;
        uint16_t charm = 0;
        uint16_t sense = 0;
        int32_t hp = 0;
        int32_t mp = 0;
        uint32_t xp = 0;
        uint16_t level = 0;
        uint32_t statPoints = 0;
        uint32_t skillPoints = 0;
        uint8_t bodySize = 0;
        uint8_t headSize = 0;
        uint32_t penaltyXp = 0;
        std::array<uint16_t, 2> factionFame = {0};
        std::array<uint16_t, 10> factionPoints = {0};
        uint32_t guildId = 0;
        uint16_t guildContribution = 0;
        uint8_t guildRank = 0;
        uint16_t pkFlag = 0;
        uint16_t stamina = 0;
        std::array<StatusEffect, MAX_STATUS_EFFECTS> effects = {};
        uint16_t patHp = 0;
        uint32_t patCooldownTime = 0;
        std::array<uint16_t, MAX_SKILL_COUNT> skills = {0};
        std::array<HotbarItem, MAX_HOTBAR_ITEMS> hotbar = {};
        uint32_t tag = 0;
        std::string name = "test";
};

}
}
