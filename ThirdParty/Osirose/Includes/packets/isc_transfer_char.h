#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class IscTransferChar : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::ISC_TRANSFER_CHAR;
        IscTransferChar();
        IscTransferChar(CRoseReader reader);
        IscTransferChar(IscTransferChar&&) = default;
        IscTransferChar& operator=(IscTransferChar&&) = default;
        ~IscTransferChar() = default;
        
        static constexpr size_t size();
        
        
        
        IscTransferChar& set_names(const std::vector<std::string>&);
        IscTransferChar& add_names(const std::string&);
        const std::vector<std::string>& get_names() const;
        const std::string& get_names(size_t index) const;
        IscTransferChar& set_blob(const std::vector<uint8_t>&);
        IscTransferChar& add_blob(const uint8_t&);
        const std::vector<uint8_t>& get_blob() const;
        const uint8_t& get_blob(size_t index) const;
        
        
        static IscTransferChar create(const std::vector<std::string>& names);
        static IscTransferChar create(const uint8_t* buffer);
        static std::unique_ptr<IscTransferChar> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        std::vector<std::string> names;
        std::vector<uint8_t> blob;
};

}
}
