#ifndef ENTRYBASE_HPP
#define ENTRYBASE_HPP


#include <cstdint>

namespace MMU
{    
    struct AddressOffsets;

    using PageAddressPtr = uint32_t*; // I suppose we can keep a raw pointer since this will only be used to keep an address to a page in memory

    class EntryBase
    {
        public:
            virtual PageAddressPtr at(AddressOffsets offsets) = 0;
            virtual ~EntryBase() = default;
    };
}

#endif 