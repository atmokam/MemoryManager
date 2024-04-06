#ifndef ENTRYBASEBUILDER_HPP
#define ENTRYBASEBUILDER_HPP

#include <memory>
#include <vector>
#include "EntryBase.hpp"
#include "AddressBits.hpp"

namespace MMU
{
    class EntryGroup;

    class EntryBaseBuilder
    {
        AddressBits vaOffsetBits;
        // Virtual address bits quantity, eg. 11 offset, 9 pte, 9 pte, 3 pde for 32 bit and 2048 byte page
        std::shared_ptr<EntryBase> pdbr; // pde
        
    public:
        std::shared_ptr<EntryGroup> buildPageDirectory();
        void setOffsetBits(AddressBits vaOffsetBits);
    };
}

#endif