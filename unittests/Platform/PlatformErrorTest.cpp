#include <gtest/gtest.h>

#include "ttvm/Platform/PlatformError.h"

TEST(PlatformError, internalErrorCodeToString) {
    ASSERT_EQ("0x00000000", ttvm::internalErrorCodeToString(ttvm::InternalErrorCode::UNKNOWN_VM_ERROR));
    ASSERT_EQ("0x00000001", ttvm::internalErrorCodeToString(ttvm::InternalErrorCode::CANNOT_ACCESS_ADDRESS));
}

TEST(PlatformError, voidPtrArgument) {
    try {
        throw ttvm::PlatformError(ttvm::InternalErrorCode::UNKNOWN_VM_ERROR, (void *)"detail");
    } catch (const ttvm::PlatformError &platformError) {
        ASSERT_STREQ("detail", platformError.detail);
    }
}
