#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvEquipItemRide : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_EQUIP_ITEM_RIDE;
        SrvEquipItemRide();
        SrvEquipItemRide(CRoseReader reader);
        SrvEquipItemRide(SrvEquipItemRide&&) = default;
        SrvEquipItemRide& operator=(SrvEquipItemRide&&) = default;
        ~SrvEquipItemRide() = default;
        
        static constexpr size_t size();
        
        
        enum EquippedPositionRide : uint16_t {
            BODY = 0,
            ENGINE = 1,
            LEG = 2,
            ABILITY = 3,
            ARM = 4,
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
        
        
        SrvEquipItemRide& set_char_id(const uint16_t);
        uint16_t get_char_id() const;
        SrvEquipItemRide& set_slot(const EquippedPositionRide);
        EquippedPositionRide get_slot() const;
        SrvEquipItemRide& set_item(const EquippedItem);
        EquippedItem get_item() const;
        SrvEquipItemRide& set_move_speed(const uint16_t);
        uint16_t get_move_speed() const;
        
        
        static SrvEquipItemRide create(const uint16_t& char_id, const EquippedPositionRide& slot, const EquippedItem& item, const uint16_t& move_speed);
        static SrvEquipItemRide create(const uint8_t* buffer);
        static std::unique_ptr<SrvEquipItemRide> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t char_id;
        EquippedPositionRide slot;
        EquippedItem item;
        uint16_t move_speed;
};

}
}
