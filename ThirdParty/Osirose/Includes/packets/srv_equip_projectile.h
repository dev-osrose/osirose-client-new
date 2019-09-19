#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvEquipProjectile : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_EQUIP_PROJECTILE;
        SrvEquipProjectile();
        SrvEquipProjectile(CRoseReader reader);
        SrvEquipProjectile(SrvEquipProjectile&&) = default;
        SrvEquipProjectile& operator=(SrvEquipProjectile&&) = default;
        ~SrvEquipProjectile() = default;
        
        static constexpr size_t size();
        
        
        struct ProjectileData : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            ProjectileData& set_type(const uint16_t);
            uint16_t get_type() const;
            ProjectileData& set_id(const uint16_t);
            uint16_t get_id() const;
            ProjectileData& set_data(const uint16_t);
            uint16_t get_data() const;
            
            private:
                union {
                    PACK(struct {
                        uint16_t type : 5;
                        uint16_t id : 10;
                    });
                    uint16_t data;
                } data;
        };
        
        
        SrvEquipProjectile& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvEquipProjectile& set_projectile(const ProjectileData);
        ProjectileData get_projectile() const;
        
        
        static SrvEquipProjectile create(const uint16_t& char_id, const ProjectileData& projectile);
        static SrvEquipProjectile create(const uint8_t* buffer);
        static std::unique_ptr<SrvEquipProjectile> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        ProjectileData projectile;
};

}
}
