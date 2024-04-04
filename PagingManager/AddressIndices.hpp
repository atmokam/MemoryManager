#ifndef ADDRESSINDICES_HPP
#define ADDRESSINDICES_HPP

#include <cstdint>

namespace PagingManager
{
    struct AddressIndices
    {
        uint32_t pageDir;
        uint32_t pageTable;
        uint32_t offset;
    };
}

#endif