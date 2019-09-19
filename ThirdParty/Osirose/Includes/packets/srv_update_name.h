#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvUpdateName : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_UPDATE_NAME;
        SrvUpdateName();
        SrvUpdateName(CRoseReader reader);
        SrvUpdateName(SrvUpdateName&&) = default;
        SrvUpdateName& operator=(SrvUpdateName&&) = default;
        ~SrvUpdateName() = default;
        
        static constexpr size_t size();
        
        
        
        SrvUpdateName& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvUpdateName& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static SrvUpdateName create(const uint16_t& target, const std::string& name);
        static SrvUpdateName create(const uint8_t* buffer);
        static std::unique_ptr<SrvUpdateName> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        std::string name;
};

}
}
