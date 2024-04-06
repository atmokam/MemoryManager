#ifndef VAPARSER_HPP
#define VAPARSER_HPP

#include <cstdint>
#include "AddressOffsets.hpp"
#include "AddressOffsetBits.hpp"

namespace MMU
{

    class VirtualAddressParser
    {
        AddressOffsetBits offsetBits;

        void calculateVirtualAddressOffsets(auto addressSize, auto pageSize); 
    public:

        VirtualAddressParser(uint32_t addressSize, uint32_t pageSize);
        AddressOffsets parse(uint32_t virtualAddress) const;

    };
}

#endif