#ifndef ENTRYGROUPWALKER_HPP
#define ENTRYGROUPWALKER_HPP

#include "IVisitor.hpp"
#include "AddressOffsets.hpp"
#include "EntryBase.hpp"

#include <memory>

namespace MMU
{

    class PageDirectory;
    class PageTable;

    class EntryGroupWalker : public IVisitor
    {

        AddressOffsets addressIndices;

        std::shared_ptr<EntryBase> lastNonNull = nullptr;
        size_t level = 0;
    public:

        EntryGroupWalker(AddressOffsets addressIndices);

        void visit(PageDirectory& pageDirectory) override;
        void visit(PageTable& pageTable) override;

    };
}

#endif