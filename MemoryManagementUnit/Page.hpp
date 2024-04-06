#ifndef PAGE_HPP
#define PAGE_HPP

#include <memory>
#include "EntryBase.hpp"

namespace MMU
{
    class Page : public EntryBase
    {
        PageAddressPtr physicalAddressPtr;
    public:
        Page(PageAddressPtr physicalAddressPtr);
        PageAddressPtr getPhysicalAddressPtr() const;
    };
}

#endif