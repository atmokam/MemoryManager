#include "PagingManager.hpp"
#include <iostream>
#include "EntryGroupBuilder.hpp"

namespace MMU
{
    PagingManager::PagingManager(uint32_t addressSizeBits, uint32_t pageSizeBytes) :
        vaParser(std::make_shared<VirtualAddressParser>(addressSizeBits, pageSizeBytes))
    {
        entryBuilder = std::make_shared<EntryGroupBuilder>();
        entryBuilder->setPDEBits(vaParser->getPDEBits());
        entryBuilder->setPTEBits(vaParser->getPTEBits());
        entryBuilder->setPageOffsetBits(vaParser->getPageOffsetBits());
        pdbr = entryBuilder->buildPageDirectory();
    }

    uint32_t& PagingManager::translate(uint32_t virtualAddress) const
    {
        
    }

     
    


}