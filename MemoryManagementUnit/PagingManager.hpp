#ifndef PAGINGMANAGER_HPP
#define PAGINGMANAGER_HPP

#include <memory>
#include "EntryGroup.hpp"
#include "Page.hpp"
#include "PagingDataStructure/EntryBaseBuilder.hpp"
#include "VirtualAddressParser.hpp"

namespace MMU
{
    class PagingManager
    {
        std::shared_ptr<EntryBase> pdbr;
        std::shared_ptr<EntryBaseBuilder> entryBuilder;
        std::shared_ptr<VirtualAddressParser> vaParser;

        unsigned int lastMappedAddress;
    public:

        PagingManager(unsigned int addressSize, unsigned int pageSize);

        unsigned int& translate(unsigned int virtualAddress) const;
        void mapPageTo(unsigned int virtualAddress, PageAddressPtr page);
        void unmapEntry(unsigned int virtualAddress);
    };
}
#endif