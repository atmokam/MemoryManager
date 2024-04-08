#ifndef VABITS_HPP
#define VABITS_HPP

#include <cstddef>
#include <cstdint>

// Intent: to store the quantity of offset bits of a virtual address

namespace MMU
{
    struct AddressBits
    {
        unsigned int page;
        unsigned int pageTable;
        size_t pteLevels;
        unsigned int pageDir;
    };
}

#endif