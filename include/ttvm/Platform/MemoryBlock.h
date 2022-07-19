#ifndef TTVM_MEMORY_BLOCK_H
#define TTVM_MEMORY_BLOCK_H

#include "ttvm/Platform/PlatformError.h"

#include <cstddef>
#include <cstdint>

namespace ttvm {

    using Address = std::size_t;
    using Byte = std::uint8_t;

    class MemoryBlock {
      protected:
        std::size_t _size;
        Byte *_data;
        bool _dead;

        inline void _throwIfDead() const {
            if (_dead) {
                throw PlatformError(InternalErrorCode::DEAD_MEMORY_BLOCK,
                                    "cannot do I/O operations on dead memory block");
            }
        }

      public:
        MemoryBlock(std::size_t);
        ~MemoryBlock();

        std::size_t getSize() const;
        bool isDead() const;

        inline void kill() {
            _throwIfDead();

            _dead = true;
        }

        bool operator==(const MemoryBlock &);
        bool operator!=(const MemoryBlock &);
        Byte &operator[](Address);
    };
} // namespace ttvm

#endif
