#ifndef PAGEDBLOCKALLOCATOR_HPP
#define PAGEDBLOCKALLOCATOR_HPP

#include <vector>
#include <cstddef>

namespace MMU
{
    struct Block {
        Block* next = nullptr;
    };

    class PagedBlockAllocator
    {
        Block* freeList = nullptr;
        size_t blockSize;
        size_t pageSize;

        size_t allocatedQuantity = 0;

        Block* allocatePage();

    public:
        PagedBlockAllocator(size_t pageSize, size_t blockSize);

        size_t getBlockSize() const noexcept;
        size_t getPageSize() const noexcept;

        void* allocateBlock();
        void deallocateBlock(void* block);
        // I don't want void* but I don't know how else to do it for now
    };
}

#endif