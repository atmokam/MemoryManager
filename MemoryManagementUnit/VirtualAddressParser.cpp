#include "VirtualAddressParser.hpp"
#include <cmath>


namespace MMU
{
    VirtualAddressParser::VirtualAddressParser(unsigned int addressSize, unsigned int pageSize)
    {
        calculateVirtualAddressOffsets(addressSize, pageSize);
    }

    // eg. 10101010110000000000000000000000 -> 1010101011 for 10 bit PDE
    AddressOffsets VirtualAddressParser::parse(unsigned int virtualAddress) const
    {
        AddressOffsets offsets;
    
        offsets.pageDir = virtualAddress >> (offsetBits.pageTable * offsetBits.pteLevels + offsetBits.page);

        unsigned int ptMask = (1u << offsetBits.pageTable) - 1;
        auto levels = offsetBits.pteLevels;

        for(size_t i = 0; i < levels; ++i)
            offsets.pageTables.push_back(
                (virtualAddress >> (offsetBits.page + offsetBits.pageTable * i)) & ptMask);
        

        unsigned int pageMask = (1u << offsetBits.page) - 1;
        offsets.offset = virtualAddress & pageMask;

        return offsets;
    }

    void VirtualAddressParser::calculateVirtualAddressOffsets(auto addressSize, auto pageSize)
    {
        AddressBits bits;

        bits.page = std::log2(pageSize);
        
        auto leftForIndexing = addressSize - bits.page;
        auto entriesPerPage = pageSize / (addressSize / 8);

        bits.pageTable = std::log2(entriesPerPage);

        size_t counter = 0;
        while(leftForIndexing > bits.pageTable)
        {
            leftForIndexing -= bits.pageTable;
            ++counter;
        }
        
        bits.pageDir = leftForIndexing;
        bits.pteLevels = counter;

        offsetBits = bits;
    }

    AddressBits VirtualAddressParser::getOffsetBits() const
    {
        return offsetBits;
    }
}