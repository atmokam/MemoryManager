#ifndef PAGINGMANAGER_HPP
#define PAGINGMANAGER_HPP

#include <memory>
#include "EntryGroup.hpp"
#include "EntryGroupBuilder.hpp"

namespace PagingManager
{
    class PagingManager
    {
        std::shared_ptr<EntryGroup> pdbr;
        std::unique_ptr<EntryGroupBuilder> entryBuilder;

        std::shared_ptr<BlockAllocator> blockAlloc;
        std::shared_ptr<FreeListAllocator> freeListAlloc;
    public:

        PagingManager(uint32_t addressSize, uint32_t pageSize);
    };
}
#endif