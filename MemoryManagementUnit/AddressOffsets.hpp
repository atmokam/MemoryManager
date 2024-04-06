#ifndef ADDRESSOFFSETS_HPP
#define ADDRESSOFFSETS_HPP

#include <cstdint>
#include <vector>

// Intent: to store the indices, i.e. the offsets

namespace MMU
{
    struct AddressOffsets
    {
        uint32_t pageDir;
        std::vector<uint32_t> pageTables; // multi-level page table
        uint32_t offset;
    };
}

#endif