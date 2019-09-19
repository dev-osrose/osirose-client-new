#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class SrvMove : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKWC_MOVE;
        SrvMove();
        SrvMove(CRoseReader reader);
        SrvMove(SrvMove&&) = default;
        SrvMove& operator=(SrvMove&&) = default;
        ~SrvMove() = default;
        
        static constexpr size_t size();
        
        
        enum MoveMode : uint8_t {
            WALK = 0,
            RUN = 1,
            DRIVE = 2,
            RIDEON = 3,
        };
        
        
        SrvMove& set_id(const uint16_t);
        uint16_t get_id() const;
        SrvMove& set_target_id(const uint16_t);
        uint16_t get_target_id() const;
        SrvMove& set_distance(const uint16_t);
        uint16_t get_distance() const;
        SrvMove& set_x(const float);
        float get_x() const;
        SrvMove& set_y(const float);
        float get_y() const;
        SrvMove& set_z(const uint16_t);
        uint16_t get_z() const;
        SrvMove& set_move_mode(const MoveMode);
        MoveMode get_move_mode() const;
        
        
        static SrvMove create(const uint16_t& id);
        static SrvMove create(const uint8_t* buffer);
        static std::unique_ptr<SrvMove> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        uint16_t id;
        uint16_t target_id = 0;
        uint16_t distance = 0;
        float x = 0;
        float y = 0;
        uint16_t z = 0;
        MoveMode move_mode = MoveMode::RUN;
};

}
}
