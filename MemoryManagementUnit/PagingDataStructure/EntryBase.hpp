#ifndef ENTRYBASE_HPP
#define ENTRYBASE_HPP


#include <cstdint>

namespace MMU
{    
    struct AddressOffsets;

    using PageAddressPtr = unsigned int*; // I suppose we can keep a raw pointer since this will only be used to keep an address to a page in memory

    class EntryBase
    {
        public:
            virtual ~EntryBase() = default;
    };
}

#endif 