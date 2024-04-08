#ifndef ADDRESSOFFSETS_HPP
#define ADDRESSOFFSETS_HPP

#include <cstdint>
#include <vector>

// Intent: to store the indices of VA, i.e. the offsets

namespace MMU
{
    struct AddressOffsets
    {
        unsigned int pageDir;
        std::vector<unsigned int> pageTables; // multi-level page table indices
        unsigned int offset;
    };
}

#endif