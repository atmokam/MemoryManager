#ifndef ENTRY_HPP
#define ENTRY_HPP

// Intent: leaf entry (only for PTE in my case)
// I don't know whether it's a good idea to do this or just go with Page instead

#include "EntryBase.hpp"

#include <memory>

namespace PagingManager
{
    class Page;

    class Entry : public EntryBase
    {
        protected:
            std::shared_ptr<Page> page = nullptr; // null if invalid
            
        public:
            Entry(std::shared_ptr<Page> page);
            Entry() = default;

            bool isValid() const;
            
            std::shared_ptr<Page> getPage() const;
            void setPage(std::shared_ptr<Page> page);
            virtual ~Entry() override = default;
    };
}
#endif