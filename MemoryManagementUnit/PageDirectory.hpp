#ifndef PAGEDIRECTORY_HPP
#define PAGEDIRECTORY_HPP

#include "EntryGroup.hpp"

namespace MMU
{
    class PageDirectory : public EntryGroup
    {
    public:
        explicit PageDirectory(unsigned int size);
        std::shared_ptr<EntryBase> getEntry(size_t index) override;
        void setEntry(size_t index, std::shared_ptr<EntryBase> entry) override;

        void accept(IVisitor& visitor) override;
    };
}

#endif