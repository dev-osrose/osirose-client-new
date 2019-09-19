#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliSelectCharReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SELECT_CHAR_REQ;
        CliSelectCharReq();
        CliSelectCharReq(CRoseReader reader);
        CliSelectCharReq(CliSelectCharReq&&) = default;
        CliSelectCharReq& operator=(CliSelectCharReq&&) = default;
        ~CliSelectCharReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliSelectCharReq& set_charId(const uint8_t);
        uint8_t get_charId() const;
        CliSelectCharReq& set_runMode(const uint8_t);
        uint8_t get_runMode() const;
        CliSelectCharReq& set_rideMode(const uint8_t);
        uint8_t get_rideMode() const;
        CliSelectCharReq& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static CliSelectCharReq create(const uint8_t& charId, const uint8_t& runMode, const uint8_t& rideMode, const std::string& name);
        static CliSelectCharReq create(const uint8_t* buffer);
        static std::unique_ptr<CliSelectCharReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t charId;
        uint8_t runMode;
        uint8_t rideMode;
        std::string name;
};

}
}
