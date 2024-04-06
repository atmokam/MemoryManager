#include "PageDirectory.hpp"
#include "AddressOffsets.hpp"
#include <algorithm>

namespace MMU
{
    PageDirectory::PageDirectory(uint32_t size) : EntryGroup(size)
    {}

    PageAddressPtr PageDirectory::at(AddressOffsets offsets)
    {
        auto index = offsets.pageDir;
        std::reverse(offsets.pageTables.begin(), offsets.pageTables.end());

        if(entries[index] == nullptr)
        {
            return nullptr;
        }
        
        return entries[index]->at(std::move(offsets));
    }
}