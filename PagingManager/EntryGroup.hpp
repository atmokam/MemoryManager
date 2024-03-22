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

    public:
        std::shared_ptr<EntryBase> operator[](unsigned int index) override;
        void addEntry(std::shared_ptr<EntryBase> entry);
        ~EntryGroup() override = default;
    };
}
#endif