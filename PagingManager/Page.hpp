#ifndef PAGE_HPP
#define PAGE_HPP

#include "EntryBase.hpp"

namespace PagingManager
{
    class Page : public EntryBase
    {
        // if I keep just an address of allocated memory,
        // I can't do any checks, this must keep the a pointer to 
        // the data structure that does checks for the heap/allocated pages

        public:
            unsigned int& operator[](unsigned int offset);

    };  
}
#endif