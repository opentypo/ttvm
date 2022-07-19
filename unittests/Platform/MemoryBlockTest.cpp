#include <gtest/gtest.h>

#include "ttvm/Platform/MemoryBlock.h"
#include "ttvm/Platform/PlatformError.h"

TEST(MemoryBlock, getSize) {
    ttvm::MemoryBlock block(10);

    ASSERT_EQ(10, block.getSize());
}

TEST(MemoryBlock, indexOperator) {
    ttvm::MemoryBlock block(10);

    try {
        block[10];
        block[-10];
    } catch (const ttvm::PlatformError &) {
        ASSERT_TRUE(true);
    }

    ASSERT_EQ(0, block[0]);
}
