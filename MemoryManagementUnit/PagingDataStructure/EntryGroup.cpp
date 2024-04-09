#include "EntryGroup.hpp"
#include "AddressOffsets.hpp"

namespace MMU
{
    EntryGroup::EntryGroup(unsigned int entriesQuantity) :
     entries(entriesQuantity, nullptr)
    {}


    size_t EntryGroup::size() const noexcept
    {
        return entries.size();
    }    

    size_t EntryGroup::getLevel() const noexcept
    {
        return level;
    }

    void EntryGroup::setLevel(size_t level) noexcept
    {
        this->level = level;
    }


}