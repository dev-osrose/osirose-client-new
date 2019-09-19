#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSkillLevelReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SKILL_LEVEL_REQ;
        CliSkillLevelReq();
        CliSkillLevelReq(CRoseReader reader);
        CliSkillLevelReq(CliSkillLevelReq&&) = default;
        CliSkillLevelReq& operator=(CliSkillLevelReq&&) = default;
        ~CliSkillLevelReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliSkillLevelReq& set_slot(const uint8_t);
        uint8_t get_slot() const;
        CliSkillLevelReq& set_next_index(const int16_t);
        int16_t get_next_index() const;
        
        
        static CliSkillLevelReq create(const uint8_t& slot);
        static CliSkillLevelReq create(const uint8_t* buffer);
        static std::unique_ptr<CliSkillLevelReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t slot;
        int16_t next_index = 0;
};

}
}
