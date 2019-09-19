#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvAppraisalReply : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_APPRAISAL_REPLY;
        SrvAppraisalReply();
        SrvAppraisalReply(CRoseReader reader);
        SrvAppraisalReply(SrvAppraisalReply&&) = default;
        SrvAppraisalReply& operator=(SrvAppraisalReply&&) = default;
        ~SrvAppraisalReply() = default;
        
        static constexpr size_t size();
        
        
        struct AppraisalReply : public ISerialize {
            virtual bool read(CRoseReader&) override;
            virtual bool write(CRoseBasePolicy&) const override;
            
            static constexpr size_t size();
            
            AppraisalReply& set_index(const uint16_t);
            uint16_t get_index() const;
            AppraisalReply& set_result(const uint16_t);
            uint16_t get_result() const;
            AppraisalReply& set_data(const uint16_t);
            uint16_t get_data() const;
            
            private:
                union {
                    PACK(struct {
                        uint16_t index : 12;
                        uint16_t result : 4;
                    });
                    uint16_t data;
                } data;
        };
        
        
        SrvAppraisalReply& set_result(const AppraisalReply);
        AppraisalReply get_result() const;
        
        
        static SrvAppraisalReply create(const AppraisalReply& result);
        static SrvAppraisalReply create(const uint8_t* buffer);
        static std::unique_ptr<SrvAppraisalReply> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        AppraisalReply result;
};

}
}
