#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

// a facade class responsible for coordinating memory allocation and pagetbl management

#include <memory>
#include "PagingManager.hpp"
#include "AllocationManager.hpp"


namespace MMU
{
    class Director
    {
        std::shared_ptr<PagingManager> pagingManager;
        std::shared_ptr<AllocationManager> allocManager;
    public:

        Director(unsigned int addressSize, unsigned int pageSize);

        void allocate(size_t bytes);
        void deallocate(auto virtualAddress);
        unsigned int& operator[](unsigned int virtualAddress);
    };
}

#endif