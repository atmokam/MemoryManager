#include "PageTable.hpp"
#include "AddressOffsets.hpp"
#include "Page.hpp"
#include "IVisitor.hpp"

namespace MMU
{
    PageTable::PageTable(unsigned int size) : EntryGroup(size)
    {}


    std::shared_ptr<EntryBase> PageTable::getEntry(size_t index)
    {
        return entries.at(index);
    }

    void PageTable::setEntry(size_t index, std::shared_ptr<EntryBase> entry)
    {
        entries.at(index) = entry;
    }


    
}

