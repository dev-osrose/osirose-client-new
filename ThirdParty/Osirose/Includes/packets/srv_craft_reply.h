#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <array>

namespace RoseCommon {
namespace Packet {

class SrvCraftReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_CRAFT_REPLY;
        SrvCraftReply();
        SrvCraftReply(CRoseReader reader);
        SrvCraftReply(SrvCraftReply&&) = default;
        SrvCraftReply& operator=(SrvCraftReply&&) = default;
        ~SrvCraftReply() = default;
        
        static constexpr size_t size();
        
        
        enum CraftResult : uint8_t {
            SUCCESSS = 0,
            FAIL = 1,
            INVALID_CONDITION = 2,
            MISSING_ITEM = 3,
            INVALID_ITEM = 4,
            INVALID_SKILL_LEVEL = 5,
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
        
        
        SrvCraftReply& set_result(const CraftResult);
        CraftResult get_result() const;
        SrvCraftReply& set_stepOrIndex(const int16_t);
        int16_t get_stepOrIndex() const;
        SrvCraftReply& set_progress(const std::array<int16_t, 4>);
        SrvCraftReply& set_progress(const int16_t, size_t index);
        std::array<int16_t, 4> get_progress() const;
        int16_t get_progress(size_t index) const;
        SrvCraftReply& set_item(const Item);
        Item get_item() const;
        
        
        static SrvCraftReply create(const CraftResult& result, const int16_t& stepOrIndex, const std::array<int16_t, 4>& progress);
        static SrvCraftReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvCraftReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        CraftResult result;
        int16_t stepOrIndex;
        std::array<int16_t, 4> progress;
        Item item = {};
};

}
}
