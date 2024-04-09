#include "PagingManager.hpp"
#include "PageDirectory.hpp"
#include <iostream>

namespace MMU
{
    PagingManager::PagingManager(unsigned int addressSizeBits, unsigned int pageSizeBytes) :
        vaParser(std::make_shared<VirtualAddressParser>(addressSizeBits, pageSizeBytes))
    {
        entryBuilder = std::make_shared<EntryBaseBuilder>();
        entryBuilder->setOffsetBits(vaParser->getOffsetBits());
        entryBuilder->buildPageDirectory();
        pdbr = entryBuilder->getPDBR();
    }

    unsigned int& PagingManager::translate(unsigned int virtualAddress) const
    {
        auto addressIndices = vaParser->parse(virtualAddress);
        auto pdbrPtr = std::dynamic_pointer_cast<PageDirectory>(pdbr);
        
    }

    void PagingManager::mapPageTo(unsigned int virtualAddress, PageAddressPtr page)
    {
        auto addressIndices = vaParser->parse(virtualAddress);
        entryBuilder->buildPTE(addressIndices, page);
    }

    void PagingManager::unmapEntry(unsigned int virtualAddress)
    {
        auto addressIndices = vaParser->parse(virtualAddress);
        entryBuilder->removePTE(addressIndices);
    }

}