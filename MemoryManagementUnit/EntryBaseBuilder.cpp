#include "EntryBaseBuilder.hpp"
#include "PageDirectory.hpp"


namespace MMU
{
    void EntryBaseBuilder::buildPageDirectory()
    {
        pdbr = std::make_shared<PageDirectory>(1u << vaOffsetBits.pageDir);
    }


   

    // void EntryBaseBuilder::buildPageTablesOn(std::shared_ptr<EntryGroup> pdbrEntry)
    // {

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
// I decided to go with creating the entire pd with nullptr initialization
// as in processes the pd is created with valid bits set to 0