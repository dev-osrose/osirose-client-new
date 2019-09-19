#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliAppraisalReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_APPRAISAL_REQ;
        CliAppraisalReq();
        CliAppraisalReq(CRoseReader reader);
        CliAppraisalReq(CliAppraisalReq&&) = default;
        CliAppraisalReq& operator=(CliAppraisalReq&&) = default;
        ~CliAppraisalReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliAppraisalReq& set_index(const uint16_t);
        uint16_t get_index() const;
        
        
        static CliAppraisalReq create(const uint16_t& index);
        static CliAppraisalReq create(const uint8_t* buffer);
        static std::unique_ptr<CliAppraisalReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t index;
};

}
}
