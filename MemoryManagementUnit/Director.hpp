#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP


#include <memory>


namespace MMU
{
    class Director
    {
        std::shared_ptr<PagingManager> pdbr;
        std::shared_ptr<AllocationManager> vaParser;
    public:

        Director(uint32_t addressSize, uint32_t pageSize);

        void allocate(size_t bytes);
        void deallocate(auto ptr);
        uint32_t& operator[](uint32_t virtualAddress);
    };
}

#endif