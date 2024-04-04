#include "EntryGroupBuilder.hpp"
#include <cmath> // pow

namespace MMU
{
    std::shared_ptr<EntryGroup> EntryGroupBuilder::initializePageDirectory()
    {
        entryGroup = std::make_shared<EntryGroup>(std::pow(2, pageDirOffsetBits));
        return entryGroup;
    }


    void EntryGroupBuilder::calculateVirtualAddressOffsets(auto addressSize, auto pageSize)
    {
        pageOffsetBits = std::log2(pageSize);
        
        auto leftForIndexing = addressSize - pageOffsetBits;
        auto entriesPerPage = pageSize / (addressSize / 8);
        pageTableOffsetBits = std::log2(entriesPerPage);

        while(leftForIndexing > pageTableOffsetBits)
        {
            leftForIndexing -= pageTableOffsetBits;
        }
        pageDirOffsetBits = leftForIndexing;
    }

    void EntryGroupBuilder::buildPageTables(std::shared_ptr<EntryGroup> pdbrEntry)
    {

        // we need to somehow walk the page table and if the chain contains no more nullptrs, we need to create a new entry group
        // but the entries by level in pts won't differ in size

        // auto currentEntry = pdbrEntry;
        // for(size_t i = 1; i < virtualAddressOffsets.size() - 1; i++)
        // {
        //     currentEntry = std::make_shared<EntryGroup>(std::pow(2, virtualAddressOffsets[i]));
        //     auto freeIndex = currentEntry->getFirstFreeIndex();
        //     auto nextEntry = currentEntry->getIndex(freeIndex);
        //     currentEntry = 
        // }
    }
    
    
}
// I decided to go with creating the entire pd with nullptr initialization
// as in processes the pd is created with valid bits set to 0