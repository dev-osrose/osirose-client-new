#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class IscTransfer : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::ISC_TRANSFER;
        IscTransfer();
        IscTransfer(CRoseReader reader);
        IscTransfer(IscTransfer&&) = default;
        IscTransfer& operator=(IscTransfer&&) = default;
        ~IscTransfer() = default;
        
        static constexpr size_t size();
        
        
        
        IscTransfer& set_maps(const std::vector<uint16_t>&);
        IscTransfer& add_maps(const uint16_t&);
        const std::vector<uint16_t>& get_maps() const;
        const uint16_t& get_maps(size_t index) const;
        IscTransfer& set_blob(const std::vector<uint8_t>&);
        IscTransfer& add_blob(const uint8_t&);
        const std::vector<uint8_t>& get_blob() const;
        const uint8_t& get_blob(size_t index) const;
        
        
        static IscTransfer create(const std::vector<uint16_t>& maps);
        static IscTransfer create(const uint8_t* buffer);
        static std::unique_ptr<IscTransfer> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::vector<uint16_t> maps;
        std::vector<uint8_t> blob;
};

}
}
