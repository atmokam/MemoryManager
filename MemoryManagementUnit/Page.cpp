#include "Page.hpp"

namespace MMU
{
    Page::Page(PageAddressPtr physicalAddressPtr) : physicalAddressPtr(physicalAddressPtr){}

    PageAddressPtr Page::getPhysicalAddressPtr() const
    {
        return physicalAddressPtr;
    }
}
