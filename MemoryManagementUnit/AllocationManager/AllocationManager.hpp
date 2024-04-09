#ifndef ALLOCATIONMANAGER_HPP
#define ALLOCATIONMANAGER_HPP

#include <memory>
#include <unordered_map>
#include "PagedBlockAllocator.hpp"

namespace MMU
{
    class AllocationManager
    {
        std::unordered_map<size_t,std::vector<std::shared_ptr<PagedBlockAllocator>>> allocators;
    public:
        unsigned int* allocate(size_t bytes);
        void deallocate(auto ptr); //  how???? maybe pass size?
    };
}
#endif