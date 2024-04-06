#include "PagingManager.hpp"
#include <iostream>

namespace MMU
{
    PagingManager::PagingManager(uint32_t addressSizeBits, uint32_t pageSizeBytes) :
        vaParser(std::make_shared<VirtualAddressParser>(addressSizeBits, pageSizeBytes))
    {
        entryBuilder = std::make_shared<EntryBaseBuilder>();
        entryBuilder->setOffsetBits(vaParser->getOffsetBits());
        pdbr = entryBuilder->buildPageDirectory();
    }

    uint32_t& PagingManager::translate(uint32_t virtualAddress) const
    {
        
    }

    void PagingManager::mapPageTo(uint32_t virtualAddress, PageAddressPtr page)
    {
        auto addressIndices = vaParser->parse(virtualAddress);

    }

    void PagingManager::unmapPageEntry(uint32_t virtualAddress)
    {
        
    }

}