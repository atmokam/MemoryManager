#include "EntryGroup.hpp"
#include "AddressOffsets.hpp"

namespace MMU
{
    EntryGroup::EntryGroup(uint32_t entriesQuantity) :
     entries(entriesQuantity, nullptr)
    {}


    size_t EntryGroup::size() const noexcept
    {
        return entries.size();
    }    

}