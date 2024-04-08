#ifndef IVISITOR_HPP
#define IVISITOR_HPP

namespace MMU
{
    class Page;
    class PageTable;
    class PageDirectory;

    class IVisitor
    {
    public:
        virtual void visit(PageTable& pageTable) = 0;
        virtual void visit(PageDirectory& pageDirectory) = 0;
    };
}

#endif