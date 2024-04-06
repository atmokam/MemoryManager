#ifndef VABITS_HPP
#define VABITS_HPP

#include <cstddef>
#include <cstdint>

// Intent: to store the quantity of offset bits of a virtual address

namespace MMU
{
    struct AddressBits
    {
        uint32_t page;
        uint32_t pageTable;
        size_t pteLevels;
        uint32_t pageDir;
    };
}

#endif