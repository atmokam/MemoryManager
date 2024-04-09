#include "Director.hpp"

namespace MMU
{
    Director::Director(unsigned int addressSize, unsigned int pageSize) 
    : pagingManager(std::make_shared<PagingManager>(addressSize, pageSize)),
        allocManager(std::make_shared<AllocationManager>())
        {}

    void Director::allocate(size_t bytes)
    {
        auto ptr = allocManager->allocate(bytes);
        if(ptr != nullptr)
            pagingManager->mapPageTo(getRecentFreeAddress(), ptr);
        // how?: some way to keep recently freed addresses 
    }

    void Director::deallocate(auto virtualAddress)
    {
        pagingManager->unmapEntry(virtualAddress);
        // add deallocate from allocManager
    }

    unsigned int& Director::operator[](unsigned int virtualAddress)
    {
        return pagingManager->translate(virtualAddress);
    }
}

