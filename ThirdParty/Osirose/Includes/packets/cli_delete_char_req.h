#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliDeleteCharReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_DELETE_CHAR_REQ;
        CliDeleteCharReq();
        CliDeleteCharReq(CRoseReader reader);
        CliDeleteCharReq(CliDeleteCharReq&&) = default;
        CliDeleteCharReq& operator=(CliDeleteCharReq&&) = default;
        ~CliDeleteCharReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliDeleteCharReq& set_charId(const uint8_t);
        uint8_t get_charId() const;
        CliDeleteCharReq& set_isDelete(const uint8_t);
        uint8_t get_isDelete() const;
        CliDeleteCharReq& set_name(const std::string&);
        const std::string& get_name() const;
        
        
        static CliDeleteCharReq create(const uint8_t& charId, const uint8_t& isDelete, const std::string& name);
        static CliDeleteCharReq create(const uint8_t* buffer);
        static std::unique_ptr<CliDeleteCharReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t charId;
        uint8_t isDelete;
        std::string name;
};

}
}
