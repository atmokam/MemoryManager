#ifndef VAPARSER_HPP
#define VAPARSER_HPP

#include "AddressOffsets.hpp"
#include "AddressBits.hpp"

namespace MMU
{

    class VirtualAddressParser
    {
        AddressBits offsetBits;

        void calculateVirtualAddressOffsets(auto addressSize, auto pageSize); 
    public:

        VirtualAddressParser(unsigned int addressSize, unsigned int pageSize);
        AddressOffsets parse(unsigned int virtualAddress) const;

        AddressBits getOffsetBits() const;

    };
}

#endif