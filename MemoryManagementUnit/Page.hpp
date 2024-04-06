#ifndef PAGE_HPP
#define PAGE_HPP

#include <memory>
#include "EntryBase.hpp"

namespace MMU
{
    using PageAddressPtr = uint32_t*; // I suppose we can keep a raw pointer since there is no ownership involved

    class Page : public EntryBase
    {
        PageAddressPtr physicalAddressPtr;
    public:
        Page(PageAddressPtr physicalAddressPtr);
        uint32_t& operator[](uint32_t offset);
    };
}

#endif