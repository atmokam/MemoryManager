#ifndef PAGINGMANAGER_HPP
#define PAGINGMANAGER_HPP

#include <memory>
#include "EntryGroup.hpp"
#include "Page.hpp"
#include "EntryBaseBuilder.hpp"
#include "VirtualAddressParser.hpp"

namespace MMU
{
    class PagingManager
    {
        std::shared_ptr<EntryBase> pdbr;
        std::shared_ptr<EntryBaseBuilder> entryBuilder;
        std::shared_ptr<VirtualAddressParser> vaParser;

        u_int32_t lastMappedAddress;
    public:

        PagingManager(uint32_t addressSize, uint32_t pageSize);

        uint32_t& translate(uint32_t virtualAddress) const;
        void mapPageTo(uint32_t virtualAddress, PageAddressPtr page);
        void unmapPageEntry(uint32_t virtualAddress);
    };
}
#endif