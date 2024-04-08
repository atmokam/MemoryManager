#include "PageDirectory.hpp"
#include "AddressOffsets.hpp"
#include "IVisitor.hpp"
#include <algorithm>

namespace MMU
{
    PageDirectory::PageDirectory(unsigned int size) : EntryGroup(size){}

    std::shared_ptr<EntryBase> PageDirectory::getEntry(size_t index)
    {
        return entries.at(index);
    }

    void PageDirectory::setEntry(size_t index, std::shared_ptr<EntryBase> entry)
    {
        entries.at(index) = entry;
    }

    void PageDirectory::accept(IVisitor& visitor)
    {
        visitor.visit(*this);
    }


}