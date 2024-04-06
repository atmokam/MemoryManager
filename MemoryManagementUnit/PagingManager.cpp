#include "PagingManager.hpp"
#include "PageDirectory.hpp"
#include <iostream>

namespace MMU
{
    PagingManager::PagingManager(uint32_t addressSizeBits, uint32_t pageSizeBytes) :
        vaParser(std::make_shared<VirtualAddressParser>(addressSizeBits, pageSizeBytes))
    {
        entryBuilder = std::make_shared<EntryBaseBuilder>();
        entryBuilder->setOffsetBits(vaParser->getOffsetBits());
        entryBuilder->buildPageDirectory();
        pdbr = entryBuilder->getPDBR();
    }

    uint32_t& PagingManager::translate(uint32_t virtualAddress) const
    {
        auto addressIndices = vaParser->parse(virtualAddress);
        auto pdbrPtr = std::dynamic_pointer_cast<PageDirectory>(pdbr);
        auto pde = pdbrPtr->at(addressIndices);
        return *pde;
    }

    void PagingManager::mapPageTo(uint32_t virtualAddress, PageAddressPtr page)
    {
        auto addressIndices = vaParser->parse(virtualAddress);
        entryBuilder->buildPTE(addressIndices, page);
    }

    void PagingManager::unmapPageEntry(uint32_t virtualAddress)
    {
        auto addressIndices = vaParser->parse(virtualAddress);
        entryBuilder->removePTE(addressIndices);
    }

}