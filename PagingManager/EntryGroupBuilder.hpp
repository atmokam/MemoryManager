#ifndef ENTRYBASEBUILDER_HPP
#define ENTRYBASEBUILDER_HPP

#include <memory>
#include <vector>
#include "EntryGroup.hpp"

namespace PagingManager
{
    class EntryGroupBuilder
    {
        uint32_t pageDirOffsetBits;
        uint32_t pageTableOffsetBits;
        uint32_t pageOffsetBits; 
        // Virtual address bits quantity, eg. 11 offset, 9 pte, 9 pte, 3 pde for 32 bit and 2048 byte page

        std::shared_ptr<EntryGroup> entryGroup; // pde
        
    public:
        std::shared_ptr<EntryGroup> initializePageDirectory();
        void calculateVirtualAddressOffsets(auto addressSize, auto pageSize);
        void buildPageTables(std::shared_ptr<EntryGroup> pdbrEntry);
    };
}

#endif