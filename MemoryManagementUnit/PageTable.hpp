#ifndef PAGETABLE_HPP
#define PAGETABLE_HPP

#include "EntryGroup.hpp"

namespace MMU
{
    class PageTable : public EntryGroup
    {
    public:
        explicit PageTable(unsigned int size);
        std::shared_ptr<EntryBase> getEntry(size_t index) override;
        void setEntry(size_t index, std::shared_ptr<EntryBase> entry) override;

        void accept(IVisitor& visitor) override;
    };
}

#endif