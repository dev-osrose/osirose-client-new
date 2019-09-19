#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class SrvGmCommandCode : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_GM_COMMAND_CODE;
        SrvGmCommandCode();
        SrvGmCommandCode(CRoseReader reader);
        SrvGmCommandCode(SrvGmCommandCode&&) = default;
        SrvGmCommandCode& operator=(SrvGmCommandCode&&) = default;
        ~SrvGmCommandCode() = default;
        
        static constexpr size_t size();
        
        
        
        SrvGmCommandCode& set_target(const uint16_t);
        uint16_t get_target() const;
        SrvGmCommandCode& set_command(const std::string&);
        const std::string& get_command() const;
        
        
        static SrvGmCommandCode create(const uint16_t& target, const std::string& command);
        static SrvGmCommandCode create(const uint8_t* buffer);
        static std::unique_ptr<SrvGmCommandCode> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t target;
        std::string command;
};

}
}
