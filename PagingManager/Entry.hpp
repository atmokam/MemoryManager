#ifndef ENTRY_HPP
#define ENTRY_HPP

// Intent: leaf entry (only for PTE in my case)

#include "EntryBase.hpp"
#include <memory>

namespace PagingManager
{
    class Page;
    using PageAddress = unsigned int;

    class Entry : public EntryBase
    {
        protected:
            PageAddress& pageAddress;
            
        public:
            Entry(PageAddress& address);
            Entry() = default;

            bool isValid() const;
            
            PageAddress& getPage() const;
            void setPage(PageAddress& address);

            virtual ~Entry() override = default;
    };
}
#endif