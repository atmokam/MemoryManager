#ifndef PAGEDIRECTORY_HPP
#define PAGEDIRECTORY_HPP

#include "EntryGroup.hpp"

namespace MMU
{
    class PageDirectory : public EntryGroup
    {
    public:
        PageDirectory(uint32_t size);
        PageAddressPtr at(AddressOffsets offsets) override;
    };
}

#endif