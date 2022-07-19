#ifndef TTVM_PLATFORM_ERROR_H
#define TTVM_PLATFORM_ERROR_H

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

#include <cstdint>

namespace ttvm {

    enum class InternalErrorCode : std::uint16_t {
        UNKNOWN_VM_ERROR = 0x00000000,
        CANNOT_ACCESS_ADDRESS = 0x00000001,
        DEAD_MEMORY_BLOCK = 0x00000002,
    };

    class PlatformError : std::runtime_error {
      public:
        PlatformError(InternalErrorCode, void *);
        PlatformError(InternalErrorCode, const std::string &);

        InternalErrorCode iErrCode;
        char *detail;
    };

    inline std::string internalErrorCodeToString(InternalErrorCode error) {
        std::stringstream ss;

        ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << (std::uint16_t)error;

        return ss.str();
    }
} // namespace ttvm

#endif
