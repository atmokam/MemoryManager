#ifndef MEMORYALLOCATOR_HPP
#define MEMORYALLOCATOR_HPP

#include <cstddef>


class MemoryAllocator
{
    
public:
    void* alloc(size_t size);
    void dealloc(void* ptr);
    unsigned int& operator[](unsigned int address);
};


#endif