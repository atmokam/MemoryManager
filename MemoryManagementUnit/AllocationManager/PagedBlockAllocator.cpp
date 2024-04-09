#include "PagedBlockAllocator.hpp"
#include <Windows.h>


namespace MMU
{
    PagedBlockAllocator::PagedBlockAllocator(size_t pageSize, size_t blockSize) :
        pageSize(pageSize), blockSize(blockSize)
    {}


    size_t PagedBlockAllocator::getBlockSize() const noexcept
    {
        return blockSize;
    }

    size_t PagedBlockAllocator::getPageSize() const noexcept
    {
        return pageSize;
    }

    void* PagedBlockAllocator::allocateBlock()
    {
        if (freeList == nullptr)
        {
            freeList = allocatePage();
        }

        Block* block = freeList;

        if (allocatedQuantity < pageSize / blockSize)
        {
            freeList->next = reinterpret_cast<Block*>(reinterpret_cast<char*>(freeList) + blockSize);
            freeList = freeList->next;
            ++allocatedQuantity;
        }
        else
        {
            return nullptr;
        }

        return block;
    }

    void PagedBlockAllocator::deallocateBlock(void* block)
    {
        Block* blockToDeallocate = static_cast<Block*>(block);
        blockToDeallocate->next = freeList;
        freeList = blockToDeallocate;
    }

    Block* PagedBlockAllocator::allocatePage()
    {
        Block* page = static_cast<Block*>(VirtualAlloc(nullptr, pageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        Block * currentBlock = page;
        
        return page;
    }


}