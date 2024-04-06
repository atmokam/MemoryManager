#ifndef VAOFFSETBITS_HPP
#define VAOFFSETBITS_HPP

#include <cstddef>
#include <cstdint>

// Intent: to store the quantity of offset bits of a virtual address

namespace MMU
{
    struct AddressOffsetBits
    {
        uint32_t pageOffset;
        uint32_t pageTableOffset;
        size_t pteLevels;
        uint32_t pageDirOffset;
    };
}

#endif