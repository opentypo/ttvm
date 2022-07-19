#include "ttvm/Platform/PlatformError.h"

#include <cstddef>

ttvm::PlatformError::PlatformError(ttvm::InternalErrorCode iErrCode, void *CHAR_PTR)
    : std::runtime_error(ttvm::internalErrorCodeToString(iErrCode) + ": " + (char *)CHAR_PTR) {
    this->iErrCode = iErrCode;
    this->detail = (char *)CHAR_PTR;
}

ttvm::PlatformError::PlatformError(ttvm::InternalErrorCode iErrCode, const std::string &cxxString_message)
    : std::runtime_error(ttvm::internalErrorCodeToString(iErrCode) + ": " + cxxString_message) {
    this->iErrCode = iErrCode;
    detail = new char[cxxString_message.size()];

    for (std::size_t i = 0; i < cxxString_message.size(); ++i) {
        detail[i] = cxxString_message.at(i);
    }
}
