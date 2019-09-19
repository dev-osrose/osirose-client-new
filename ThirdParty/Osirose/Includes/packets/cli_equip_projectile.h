#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliEquipProjectile : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_EQUIP_PROJECTILE;
        CliEquipProjectile();
        CliEquipProjectile(CRoseReader reader);
        CliEquipProjectile(CliEquipProjectile&&) = default;
        CliEquipProjectile& operator=(CliEquipProjectile&&) = default;
        ~CliEquipProjectile() = default;
        
        static constexpr size_t size();
        
        
        struct ProjectileTypeAndIndex : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            ProjectileTypeAndIndex& set_type(const uint16_t);
            uint16_t get_type() const;
            ProjectileTypeAndIndex& set_index(const uint16_t);
            uint16_t get_index() const;
            ProjectileTypeAndIndex& set_data(const uint16_t);
            uint16_t get_data() const;
            
            private:
                union {
                    PACK(struct {
                        uint16_t type : 2;
                        uint16_t index : 14;
                    });
                    uint16_t data;
                } data;
        };
        
        
        CliEquipProjectile& set_projectile(const ProjectileTypeAndIndex);
        ProjectileTypeAndIndex get_projectile() const;
        
        
        static CliEquipProjectile create(const ProjectileTypeAndIndex& projectile);
        static CliEquipProjectile create(const uint8_t* buffer);
        static std::unique_ptr<CliEquipProjectile> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        ProjectileTypeAndIndex projectile;
};

}
}
