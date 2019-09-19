#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvMouseCmd : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_MOUSE_CMD;
        SrvMouseCmd();
        SrvMouseCmd(CRoseReader reader);
        SrvMouseCmd(SrvMouseCmd&&) = default;
        SrvMouseCmd& operator=(SrvMouseCmd&&) = default;
        ~SrvMouseCmd() = default;
        
        static constexpr size_t size();
        
        
        
        SrvMouseCmd& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvMouseCmd& set_targetId(const uint16_t);
        uint16_t get_targetId() const;
        SrvMouseCmd& set_distance(const uint16_t);
        uint16_t get_distance() const;
        SrvMouseCmd& set_x(const float);
        float get_x() const;
        SrvMouseCmd& set_y(const float);
        float get_y() const;
        SrvMouseCmd& set_z(const uint16_t);
        uint16_t get_z() const;
        
        
        static SrvMouseCmd create(const uint16_t& id);
        static SrvMouseCmd create(const uint8_t* buffer);
        static std::unique_ptr<SrvMouseCmd> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        uint16_t targetId = 0;
        uint16_t distance = 0;
        float x = 0;
        float y = 0;
        uint16_t z = 0;
};

}
}
