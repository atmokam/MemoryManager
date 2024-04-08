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

    void PageTable::accept(IVisitor& visitor)
    {
        visitor.visit(*this);
    }

    // std::shared_ptr<EntryBase> PageTable::getEntry(size_t index)
    // {
        // auto index = offsets.pageTables.back();
        // offsets.pageTables.pop_back();

        // if(offsets.pageTables.empty())
        // {
        //     return std::dynamic_pointer_cast<Page>(entries.at(index));
        // }

        // if(entries.at(index) == nullptr)
        // {
        //     return ;
        // }
        
        // return entries.at(index)->at(std::move(offsets));
    //}
}

