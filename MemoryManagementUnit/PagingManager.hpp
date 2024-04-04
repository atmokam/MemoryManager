#ifndef PAGINGMANAGER_HPP
#define PAGINGMANAGER_HPP

#include <memory>
#include "EntryGroup.hpp"
#include "EntryGroupBuilder.hpp"

namespace MMU
{
    class PagingManager
    {
        std::shared_ptr<EntryGroup> pdbr;
        std::shared_ptr<EntryGroupBuilder> entryBuilder;
        std::shared_ptr<VAParser> vaParser;
    public:

        PagingManager(uint32_t addressSize, uint32_t pageSize);
    };
}
#endif