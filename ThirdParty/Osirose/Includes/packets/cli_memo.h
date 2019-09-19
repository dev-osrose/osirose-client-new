#pragma once

/* Generated with IDL v0.1.1 */


#include "packetfactory.h"
#include <string>

namespace RoseCommon {
namespace Packet {

class CliMemo : public CRosePacket {
    public:
        static constexpr ePacketType PACKET_ID = ePacketType::PAKCS_MEMO;
        CliMemo();
        CliMemo(CRoseReader reader);
        CliMemo(CliMemo&&) = default;
        CliMemo& operator=(CliMemo&&) = default;
        ~CliMemo() = default;
        
        static constexpr size_t size();
        
        
        enum MemoType : uint8_t {
            REQUEST_CONTENT = 0,
            SEND = 1,
            RECEIVED_COUNT = 2,
        };
        
        
        CliMemo& set_type(const MemoType);
        MemoType get_type() const;
        CliMemo& set_target(const std::string&);
        const std::string& get_target() const;
        CliMemo& set_message(const std::string&);
        const std::string& get_message() const;
        
        
        static CliMemo create(const MemoType& type, const std::string& target, const std::string& message);
        static CliMemo create(const uint8_t* buffer);
        static std::unique_ptr<CliMemo> allocate(const uint8_t* buffer);
    
    protected:
        virtual bool pack(CRoseBasePolicy&) const override;
    
    private:
        MemoType type;
        std::string target;
        std::string message;
};

}
}
