#include "VirtualAddressParser.hpp"
#include <cmath>
#include <iostream>

namespace MMU
{
    VirtualAddressParser::VirtualAddressParser(uint32_t addressSize, uint32_t pageSize)
    {
        calculateVirtualAddressOffsets(addressSize, pageSize);
    }

    AddressOffsets VirtualAddressParser::parse(uint32_t virtualAddress) const
    {
        AddressOffsets offsets;
    
        offsets.pageDir = virtualAddress >> (offsetBits.pageTableOffset * offsetBits.pteLevels + offsetBits.pageOffset);
        // eg. 10101010110000000000000000000000 -> 1010101011 for 10 bit PDE

        uint32_t ptMask = (1u << offsetBits.pageTableOffset) - 1;
        auto levels = offsetBits.pteLevels;

        for(size_t i = 0; i < levels; ++i)
            offsets.pageTables.push_back(
                (virtualAddress >> (offsetBits.pageOffset + offsetBits.pageTableOffset * i)) & ptMask);
        

        uint32_t pageMask = (1u << offsetBits.pageOffset) - 1;
        offsets.offset = virtualAddress & pageMask;

        return offsets;
    }

    void VirtualAddressParser::calculateVirtualAddressOffsets(auto addressSize, auto pageSize)
    {
        AddressOffsetBits bits;
        bits.pageOffset = std::log2(pageSize);
        
        auto leftForIndexing = addressSize - bits.pageOffset;
        auto entriesPerPage = pageSize / (addressSize / 8);

        bits.pageTableOffset = std::log2(entriesPerPage);

        size_t counter = 0;
        while(leftForIndexing > bits.pageTableOffset)
        {
            leftForIndexing -= bits.pageTableOffset;
            ++counter;
        }
        
        bits.pageDirOffset = leftForIndexing;
        bits.pteLevels = counter;


        offsetBits = bits;
    }
}