#ifndef ENTRYGROUP_HPP
#define ENTRYGROUP_HPP

#include <vector>
#include <memory>

#include "EntryBase.hpp"

namespace PagingManager
{
    class EntryGroup : public EntryBase
    {
        std::vector<std::shared_ptr<EntryBase>> entries;

        uint32_t firstFree = 0;

    public:
        std::shared_ptr<EntryBase> getIndex(uint32_t index);
        void addEntry(std::shared_ptr<EntryBase> entry);
        EntryGroup(uint32_t size);
        ~EntryGroup() override = default;

        size_t size() const;
        uint32_t getFirstFreeIndex() const;
    };
}
#endif