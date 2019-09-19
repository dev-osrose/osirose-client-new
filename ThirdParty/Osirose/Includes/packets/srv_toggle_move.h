#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvToggleMove : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_TOGGLE_MOVE;
        SrvToggleMove();
        SrvToggleMove(CRoseReader reader);
        SrvToggleMove(SrvToggleMove&&) = default;
        SrvToggleMove& operator=(SrvToggleMove&&) = default;
        ~SrvToggleMove() = default;
        
        static constexpr size_t size();
        
        
        enum ToggleMove : uint8_t {
            RUN = 2,
            SIT = 8,
            DRIVE = 9,
        };
        
        
        SrvToggleMove& set_object_id(const uint16_t);
        uint16_t get_object_id() const;
        SrvToggleMove& set_type(const ToggleMove);
        ToggleMove get_type() const;
        SrvToggleMove& set_run_speed(const uint16_t);
        uint16_t get_run_speed() const;
        
        
        static SrvToggleMove create(const ToggleMove& type);
        static SrvToggleMove create(const uint8_t* buffer);
        static std::unique_ptr<SrvToggleMove> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t object_id = 0;
        ToggleMove type;
        uint16_t run_speed = 0;
};

}
}
