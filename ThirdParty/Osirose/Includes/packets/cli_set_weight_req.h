#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliSetWeightReq : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_SET_WEIGHT_REQ;
        CliSetWeightReq();
        CliSetWeightReq(CRoseReader reader);
        CliSetWeightReq(CliSetWeightReq&&) = default;
        CliSetWeightReq& operator=(CliSetWeightReq&&) = default;
        ~CliSetWeightReq() = default;
        
        static constexpr size_t size();
        
        
        
        CliSetWeightReq& set_weight(const uint8_t);
        uint8_t get_weight() const;
        
        
        static CliSetWeightReq create(const uint8_t& weight);
        static CliSetWeightReq create(const uint8_t* buffer);
        static std::unique_ptr<CliSetWeightReq> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint8_t weight;
};

}
}
