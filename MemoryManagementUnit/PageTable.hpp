#ifndef PAGETABLE_HPP
#define PAGETABLE_HPP

#include "EntryGroup.hpp"

namespace MMU
{
    class PageTable : public EntryGroup
    {
    public:
        PageTable(uint32_t size);
        PageAddressPtr at(AddressOffsets offsets) override;
    };
}

#endif