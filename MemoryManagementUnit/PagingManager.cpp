#include "PagingManager.hpp"
#include <iostream>
#include "EntryGroupBuilder.hpp"

namespace MMU
{
    PagingManager::PagingManager(uint32_t addressSizeBits, uint32_t pageSizeBytes) :
     entryBuilder(std::make_unique<EntryGroupBuilder>())
    {
        entryBuilder->setEnrtiesQuantity(pageSizeBytes / (addressSizeBits / 8));
        pdbr = entryBuilder->initializePageDirectory();

    }

    


}