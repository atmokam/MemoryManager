#include "AllocationManager.hpp"
#include <Windows.h>

namespace MMU
{
    AllocationManager::AllocationManager(size_t addressSize): 
    addressSpace(VirtualAlloc(nullptr, 1u << addressSize, MEM_RESERVE, PAGE_READWRITE)) 
    {}

    unsigned int* AllocationManager::allocate(size_t bytes)
    {
        auto allocator = allocators.find(bytes);
        if(allocator == allocators.end()) // none with that size
        {
            allocators[bytes].push_back(std::make_shared<PagedBlockAllocator>(bytes));
        }
        auto foundPage = allocator->second;
        auto ptr = static_cast<unsigned int*>(foundPage.back()->allocateBlock());

        if(ptr != nullptr)
            return ptr;
            
        else
        {
            foundPage.push_back(std::make_shared<PagedBlockAllocator>(bytes));
            return static_cast<unsigned int*>(foundPage.back()->allocateBlock());
        }
        
    }

    void AllocationManager::deallocate(auto ptr)
    {
    }
}