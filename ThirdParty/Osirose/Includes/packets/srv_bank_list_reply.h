#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class SrvBankListReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_BANK_LIST_REPLY;
        SrvBankListReply();
        SrvBankListReply(CRoseReader reader);
        SrvBankListReply(SrvBankListReply&&) = default;
        SrvBankListReply& operator=(SrvBankListReply&&) = default;
        ~SrvBankListReply() = default;
        
        static constexpr size_t size();
        
        
        enum BankListReply : uint8_t {
            INIT_DATA = 0,
            SHOW_DATA = 1,
            NEED_PASSWORD = 2,
            CHANGED_PASSWORD = 3,
            CLEARED_PASSWORD = 4,
            PLATINUM = 5,
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
        
        struct BankListItem : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            BankListItem& set_index(const uint8_t);
            uint8_t get_index() const;
            BankListItem& set_item(const Item);
            Item get_item() const;
            
            private:
                uint8_t index;
                Item item;
        };
        
        
        SrvBankListReply& set_reply(const BankListReply);
        BankListReply get_reply() const;
        SrvBankListReply& set_items(const std::vector<BankListItem>);
        SrvBankListReply& add_items(const BankListItem);
        std::vector<BankListItem> get_items() const;
        BankListItem get_items(size_t index) const;
        
        
        static SrvBankListReply create(const BankListReply& reply);
        static SrvBankListReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvBankListReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        BankListReply reply;
        std::vector<BankListItem> items;
};

}
}
