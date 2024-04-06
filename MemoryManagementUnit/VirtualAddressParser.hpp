#ifndef VAPARSER_HPP
#define VAPARSER_HPP

#include <cstdint>
#include "AddressOffsets.hpp"
#include "AddressBits.hpp"

namespace MMU
{

    class VirtualAddressParser
    {
        AddressBits offsetBits;

        void calculateVirtualAddressOffsets(auto addressSize, auto pageSize); 
    public:

        VirtualAddressParser(uint32_t addressSize, uint32_t pageSize);
        AddressOffsets parse(uint32_t virtualAddress) const;

        AddressBits getOffsetBits() const;

    };
}

#endif