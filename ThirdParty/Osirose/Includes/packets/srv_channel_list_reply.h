#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>
#include <vector>

namespace RoseCommon {
namespace Packet {

class SrvChannelListReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKLC_CHANNEL_LIST_REPLY;
        SrvChannelListReply();
        SrvChannelListReply(CRoseReader reader);
        SrvChannelListReply(SrvChannelListReply&&) = default;
        SrvChannelListReply& operator=(SrvChannelListReply&&) = default;
        ~SrvChannelListReply() = default;
        
        static constexpr size_t size();
        
        
        struct ChannelInfo : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            ChannelInfo& set_id(const uint8_t);
            uint8_t get_id() const;
            ChannelInfo& set_lowAge(const uint8_t);
            uint8_t get_lowAge() const;
            ChannelInfo& set_highAge(const uint8_t);
            uint8_t get_highAge() const;
            ChannelInfo& set_capacity(const uint16_t);
            uint16_t get_capacity() const;
            ChannelInfo& set_name(const std::string);
            std::string get_name() const;
            
            private:
                uint8_t id;
                uint8_t lowAge;
                uint8_t highAge;
                uint16_t capacity;
                std::string name;
        };
        
        
        SrvChannelListReply& set_id(const uint32_t);
        uint32_t get_id() const;
        SrvChannelListReply& set_channels(const std::vector<ChannelInfo>);
        SrvChannelListReply& add_channels(const ChannelInfo);
        std::vector<ChannelInfo> get_channels() const;
        ChannelInfo get_channels(size_t index) const;
        
        
        static SrvChannelListReply create(const uint32_t& id);
        static SrvChannelListReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvChannelListReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint32_t id;
        std::vector<ChannelInfo> channels;
};

}
}
