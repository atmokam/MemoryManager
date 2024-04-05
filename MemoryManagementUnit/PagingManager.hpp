#ifndef PAGINGMANAGER_HPP
#define PAGINGMANAGER_HPP

#include <memory>
#include "EntryGroup.hpp"
#include "EntryGroupBuilder.hpp"
#include "VirtualAddressParser.hpp"

namespace MMU
{
    class PagingManager
    {
        std::shared_ptr<EntryGroup> pdbr;
        std::shared_ptr<EntryGroupBuilder> entryBuilder;
        std::shared_ptr<VirtualAddressParser> vaParser;
    public:

        PagingManager(uint32_t addressSize, uint32_t pageSize);

        uint32_t& translate(uint32_t virtualAddress) const;
        void mapPageEntry(PageAddressPtr page);
        void unmapPageEntry(uint32_t virtualAddress);
    };
}
#endif