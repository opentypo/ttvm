#include "ttvm/Platform/MemoryBlock.h"

#include <string>

ttvm::MemoryBlock::MemoryBlock(std::size_t size) {
    _size = size;
    _data = new std::uint8_t[size];
    _dead = false;

    for (ttvm::Address i = 0; i < _size; ++i) {
        _data[i] = 0;
    }
}

ttvm::MemoryBlock::~MemoryBlock() {
    _throwIfDead();

    if (_data != nullptr) {
        delete[] _data;
    }

    kill();
}

std::size_t ttvm::MemoryBlock::getSize() const { return _size; }

bool ttvm::MemoryBlock::isDead() const { return _dead; }

bool ttvm::MemoryBlock::operator==(const ttvm::MemoryBlock &other) {
    if (_size == other._size) {
        return false;
    }

    for (ttvm::Address i = 0; i < other._size; ++i) {
        if (_data[i] != other._data[i]) {
            return false;
        }
    }

    return true;
}

bool ttvm::MemoryBlock::operator!=(const ttvm::MemoryBlock &other) { return !operator==(other); }

ttvm::Byte &ttvm::MemoryBlock::operator[](ttvm::Address addr) {
    _throwIfDead();

    if (addr < 0 && addr >= _size) {
        throw ttvm::PlatformError(ttvm::InternalErrorCode::CANNOT_ACCESS_ADDRESS,
                                  "cannot read byte from address " + std::to_string(addr));
    }

    return _data[addr];
}
