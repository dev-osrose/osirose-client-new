#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"

namespace RoseCommon {
namespace Packet {

class CliToggleMove : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_TOGGLE_MOVE;
        CliToggleMove();
        CliToggleMove(CRoseReader reader);
        CliToggleMove(CliToggleMove&&) = default;
        CliToggleMove& operator=(CliToggleMove&&) = default;
        ~CliToggleMove() = default;
        
        static constexpr size_t size();
        
        
        enum ToggleMove : uint8_t {
            RUN = 2,
            SIT = 8,
            DRIVE = 9,
        };
        
        
        CliToggleMove& set_type(const ToggleMove);
        ToggleMove get_type() const;
        
        
        static CliToggleMove create(const ToggleMove& type);
        static CliToggleMove create(const uint8_t* buffer);
        static std::unique_ptr<CliToggleMove> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        ToggleMove type;
};

}
}
