#include "EntryGroupWalker.hpp"
#include "PageDirectory.hpp"
#include "PageTable.hpp"

namespace MMU
{
    void EntryGroupWalker::visit(PageDirectory& pageDirectory)
    {
        auto pde = pageDirectory.getEntry(addressIndices.pageDir);

        if(pde == nullptr)
        {
            return;
        }

        lastNonNull = pde;

        auto pdePtr = std::dynamic_pointer_cast<EntryGroup>(pde);
        pdePtr->accept(*this);
    }

    void EntryGroupWalker::visit(PageTable& pageTable)
    {
        auto size = addressIndices.pageTables.size();

        if(level < size)
        {
            auto pte = pageTable.getEntry(addressIndices.pageTables.at(level));

            if(pte == nullptr)
            {
                return;
            }
            ++level;

            lastNonNull = pte;

            auto ptePtr = std::dynamic_pointer_cast<EntryGroup>(pte);
            ptePtr->accept(*this);
        }

    }
}
