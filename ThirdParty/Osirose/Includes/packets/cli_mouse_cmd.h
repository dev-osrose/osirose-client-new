#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliMouseCmd : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_MOUSE_CMD;
        CliMouseCmd();
        CliMouseCmd(CRoseReader reader);
        CliMouseCmd(CliMouseCmd&&) = default;
        CliMouseCmd& operator=(CliMouseCmd&&) = default;
        ~CliMouseCmd() = default;
        
        static constexpr size_t size();
        
        
        
        CliMouseCmd& set_targetId(const uint16_t);
        uint16_t get_targetId() const;
        CliMouseCmd& set_x(const float);
        float get_x() const;
        CliMouseCmd& set_y(const float);
        float get_y() const;
        CliMouseCmd& set_z(const uint16_t);
        uint16_t get_z() const;
        
        
        static CliMouseCmd create(const uint16_t& targetId, const float& x, const float& y, const uint16_t& z);
        static CliMouseCmd create(const uint8_t* buffer);
        static std::unique_ptr<CliMouseCmd> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t targetId;
        float x;
        float y;
        uint16_t z;
};

}
}
