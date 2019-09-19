#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class SrvCraftEnhanceReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CRAFT_ENHANCE_REPLY;
        SrvCraftEnhanceReply();
        SrvCraftEnhanceReply(CRoseReader reader);
        SrvCraftEnhanceReply(SrvCraftEnhanceReply&&) = default;
        SrvCraftEnhanceReply& operator=(SrvCraftEnhanceReply&&) = default;
        ~SrvCraftEnhanceReply() = default;
        
        static constexpr size_t size();
        
        
        enum CraftEnhancementResult : uint8_t {
            GEM_SUCCESS = 0,
            GEM_NO_SOCKET = 1,
            GEM_SOCKET_FULL = 2,
            DISASSEMBLE_GEM_SUCCESS = 3,
            DISASSEMBLE_GEM_DEGRADED = 4,
            DISASSEMBLE_GEM_LOST = 5,
            DISASSEMBLE_SUCCESS = 6,
            UPGRADE_SUCCESS = 16,
            UPGRADE_FAIL = 17,
            UPGRADE_INVALID_MATERIALS = 18,
        };
        
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
        
        
        SrvCraftEnhanceReply& set_result(const CraftEnhancementResult);
        CraftEnhancementResult get_result() const;
        SrvCraftEnhanceReply& set_items(const std::vector<Item>);
        SrvCraftEnhanceReply& add_items(const Item);
        std::vector<Item> get_items() const;
        Item get_items(size_t index) const;
        
        
        static SrvCraftEnhanceReply create(const CraftEnhancementResult& result);
        static SrvCraftEnhanceReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvCraftEnhanceReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        CraftEnhancementResult result;
        std::vector<Item> items;
};

}
}
