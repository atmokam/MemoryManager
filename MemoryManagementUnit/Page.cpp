#include "Page.hpp"

namespace MMU
{
    Page::Page(PageAddressPtr physicalAddressPtr) : physicalAddressPtr(physicalAddressPtr){}

    uint32_t& Page::operator[](uint32_t offset)
    {
        return physicalAddressPtr[offset];
    }
}
