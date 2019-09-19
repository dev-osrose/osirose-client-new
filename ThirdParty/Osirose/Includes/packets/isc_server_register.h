#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>
#include "isccommon.h"
#include <vector>

namespace RoseCommon {
namespace Packet {

class IscServerRegister : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::ISC_SERVER_REGISTER;
        IscServerRegister();
        IscServerRegister(CRoseReader reader);
        IscServerRegister(IscServerRegister&&) = default;
        IscServerRegister& operator=(IscServerRegister&&) = default;
        ~IscServerRegister() = default;
        
        static constexpr size_t size();
        
        
        
        IscServerRegister& set_serverType(const Isc::ServerType);
        Isc::ServerType get_serverType() const;
        IscServerRegister& set_name(const std::string&);
        const std::string& get_name() const;
        IscServerRegister& set_addr(const std::string&);
        const std::string& get_addr() const;
        IscServerRegister& set_port(const int32_t);
        int32_t get_port() const;
        IscServerRegister& set_right(const int32_t);
        int32_t get_right() const;
        IscServerRegister& set_id(const int32_t);
        int32_t get_id() const;
        IscServerRegister& set_maps(const std::vector<uint16_t>);
        IscServerRegister& add_maps(const uint16_t);
        std::vector<uint16_t> get_maps() const;
        uint16_t get_maps(size_t index) const;
        
        
        static IscServerRegister create(const Isc::ServerType& serverType, const std::string& name, const std::string& addr, const int32_t& port, const int32_t& right, const int32_t& id);
        static IscServerRegister create(const uint8_t* buffer);
        static std::unique_ptr<IscServerRegister> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        Isc::ServerType serverType;
        std::string name;
        std::string addr;
        int32_t port;
        int32_t right;
        int32_t id;
        // All the maps this client is responsible for
        std::vector<uint16_t> maps;
};

}
}
