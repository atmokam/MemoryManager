#ifndef ENTRYBASEBUILDER_HPP
#define ENTRYBASEBUILDER_HPP

#include <memory>
#include <vector>
#include "EntryGroup.hpp"

namespace MMU
{
    class EntryBaseBuilder
    {
        uint32_t pageDirOffsetBits;
        uint32_t pageTableOffsetBits;
        uint32_t pageOffsetBits; 
        // Virtual address bits quantity, eg. 11 offset, 9 pte, 9 pte, 3 pde for 32 bit and 2048 byte page

        std::shared_ptr<EntryGroup> entryGroup; // pde
        
    public:
        std::shared_ptr<EntryGroup> buildPageDirectory();
        //void calculateVirtualAddressOffsets(auto addressSize, auto pageSize); // remove this does belong here
        
        void buildPageTablesOn(std::shared_ptr<EntryGroup> pdbrEntry);
    };
}

#endif