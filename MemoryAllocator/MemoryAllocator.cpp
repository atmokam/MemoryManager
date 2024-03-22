#include "MemoryAllocator.hpp"

#if defined(__linux__) //  to be changed  ///////////////
    #include <unistd.h>

    void* MemoryAllocator::alloc(size_t size){
        return sbrk(size);
    }

    void MemoryAllocator::dealloc(void* ptr){
        brk(ptr);
    }
#elif defined(_WIN32)
    #include <windows.h>

    void* alloc(size_t size){
        return HeapAlloc(GetProcessHeap(), 0, size);
    }

    void dealloc(void* ptr){
        HeapFree(GetProcessHeap(), 0, ptr);
    }
#endif