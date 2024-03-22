#ifndef ADDRESSINDICES_HPP
#define ADDRESSINDICES_HPP

namespace PagingManager
{
    struct AddressIndices
    {
        unsigned int pageDir;
        unsigned int pageTable;
        unsigned int offset;
    };
}

#endif