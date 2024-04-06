#include "EntryBaseBuilder.hpp"
#include "EntryGroup.hpp"

namespace MMU
{
    std::shared_ptr<EntryGroup> EntryBaseBuilder::buildPageDirectory()
    {
        pdbr = std::make_shared<EntryGroup>(1 << vaOffsetBits.pageDir);
        return std::dynamic_pointer_cast<EntryGroup>(pdbr);
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