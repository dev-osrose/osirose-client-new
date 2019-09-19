#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliCreateCharReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_CREATE_CHAR_REQ;
        CliCreateCharReq();
        CliCreateCharReq(CRoseReader reader);
        CliCreateCharReq(CliCreateCharReq&&) = default;
        CliCreateCharReq& operator=(CliCreateCharReq&&) = default;
        ~CliCreateCharReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliCreateCharReq& set_race(const uint8_t);
        uint8_t get_race() const;
        CliCreateCharReq& set_stone(const uint8_t);
        uint8_t get_stone() const;
        CliCreateCharReq& set_hair(const uint8_t);
        uint8_t get_hair() const;
        CliCreateCharReq& set_face(const uint8_t);
        uint8_t get_face() const;
        CliCreateCharReq& set_weapon(const uint8_t);
        uint8_t get_weapon() const;
        CliCreateCharReq& set_zone(const uint16_t);
        uint16_t get_zone() const;
        CliCreateCharReq& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static CliCreateCharReq create(const uint8_t& race, const uint8_t& stone, const uint8_t& hair, const uint8_t& face, const uint8_t& weapon, const uint16_t& zone, const std::string& name);
        static CliCreateCharReq create(const uint8_t* buffer);
        static std::unique_ptr<CliCreateCharReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t race;
        uint8_t stone;
        uint8_t hair;
        uint8_t face;
        uint8_t weapon;
        uint16_t zone;
        std::string name;
};

}
}
