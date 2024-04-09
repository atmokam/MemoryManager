#ifndef ENTRYBASEBUILDER_HPP
#define ENTRYBASEBUILDER_HPP

#include <memory>
#include <vector>
#include "PagingDataStructure/EntryBase.hpp"

#include "AddressBits.hpp"


namespace MMU
{
    class EntryGroup;
    class PageDirectory;

    struct AddressOffsets;

    class EntryBaseBuilder
    {
        AddressBits vaOffsetBits;
        // Virtual address bits quantity, eg. 11 offset, 9 pte, 9 pte, 3 pde for 32 bit and 2048 byte page
        
        std::shared_ptr<EntryBase> pdbr; // pdbr
        
    private:
        std::shared_ptr<EntryGroup> castToEntryGroup(const std::shared_ptr<EntryBase>& entry);

    public:
        void buildPageDirectory();
        void buildPTE(AddressOffsets& offsets, PageAddressPtr page);
        void setOffsetBits(AddressBits vaOffsetBits);
        std::shared_ptr<EntryBase> getPDBR();
    };
}

#endif