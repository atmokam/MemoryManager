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
}

