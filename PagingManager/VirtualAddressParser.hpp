#ifndef VAPARSER_HPP
#define VAPARSER_HPP

#include <cstdint>
#include "AddressIndices.hpp"

class VirtualAddressParser
{
    public:

        VirtualAddressParser() = default;
        AddressIndices parse(uint32_t virtualAddress) const;
};

#endif