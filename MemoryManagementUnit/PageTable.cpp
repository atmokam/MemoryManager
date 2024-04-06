#include "PageTable.hpp"
#include "AddressOffsets.hpp"
#include "Page.hpp"

namespace MMU
{
    PageTable::PageTable(uint32_t size) : EntryGroup(size)
    {}

    PageAddressPtr PageTable::at(AddressOffsets offsets)
    {
        auto index = offsets.pageTables.back();
        offsets.pageTables.pop_back();

        if(offsets.pageTables.empty())
        {
            auto pte = std::dynamic_pointer_cast<Page>(entries[index]);
            return pte->getPhysicalAddressPtr() + offsets.offset;
        }

        if(entries[index] == nullptr)
        {
            return nullptr;
        }
        
        return entries[index]->at(std::move(offsets));
    }
}

