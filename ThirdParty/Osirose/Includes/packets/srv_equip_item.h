#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvEquipItem : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_EQUIP_ITEM;
        SrvEquipItem();
        SrvEquipItem(CRoseReader reader);
        SrvEquipItem(SrvEquipItem&&) = default;
        SrvEquipItem& operator=(SrvEquipItem&&) = default;
        ~SrvEquipItem() = default;
        
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
        
        
        SrvEquipItem& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvEquipItem& set_slot(const int16_t);
        int16_t get_slot() const;
        SrvEquipItem& set_item(const EquippedItem);
        EquippedItem get_item() const;
        
        
        static SrvEquipItem create(const uint16_t& id, const int16_t& slot, const EquippedItem& item);
        static SrvEquipItem create(const uint8_t* buffer);
        static std::unique_ptr<SrvEquipItem> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        int16_t slot;
        EquippedItem item;
};

}
}
