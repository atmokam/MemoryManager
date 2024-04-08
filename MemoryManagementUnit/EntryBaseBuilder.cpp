#include "EntryBaseBuilder.hpp"
#include "PageDirectory.hpp"
#include "AddressOffsets.hpp"
#include "PageTable.hpp"
#include "EntryGroup.hpp"
#include "Page.hpp"
#include <iostream>


namespace MMU
{
    void EntryBaseBuilder::buildPageDirectory()
    {
        pdbr = std::make_shared<PageDirectory>(1u << vaOffsetBits.pageDir);
    }


    void EntryBaseBuilder::buildPTE(AddressOffsets& offsets, PageAddressPtr page)
    {
        auto tempParent = pdbr;
        auto tempEntry = castToEntryGroup(tempParent)->getEntry(offsets.pageDir);

        if(tempEntry == nullptr)
        {
            tempEntry = std::make_shared<PageTable>(1u << vaOffsetBits.pageTable);
            castToEntryGroup(tempParent)->setEntry(offsets.pageDir, tempEntry);
        }

        tempParent = tempEntry;

        for(size_t i = 0; i < offsets.pageTables.size() - 1; ++i)
        {
            tempEntry = castToEntryGroup(tempParent)->getEntry(offsets.pageTables.at(i));
            if(tempEntry == nullptr)
            {
                tempEntry = std::make_shared<PageTable>(1u << vaOffsetBits.pageTable);
                castToEntryGroup(tempParent)->setEntry(offsets.pageTables.at(i), tempEntry);
            }
            tempParent = tempEntry;  
        }

        tempEntry = castToEntryGroup(tempParent)->getEntry(offsets.pageTables.back());
        if(tempEntry == nullptr)
        {
            tempEntry = std::make_shared<Page>(page);
            castToEntryGroup(tempParent)->setEntry(offsets.pageTables.back(), tempEntry);
        }
            
       
    }

    
    std::shared_ptr<EntryBase> EntryBaseBuilder::getPDBR()
    {
        return pdbr;
    }

    void EntryBaseBuilder::setOffsetBits(AddressBits vaOffsetBits)
    {
        this->vaOffsetBits = vaOffsetBits;
    }

    std::shared_ptr<EntryGroup> EntryBaseBuilder::castToEntryGroup(const std::shared_ptr<EntryBase>& entry)
    {
        return std::dynamic_pointer_cast<EntryGroup>(entry);
    }


   
    
}
// I decided to go with creating the entire pd with nullptr initialization
// as in processes the pd is created with valid bits set to 0