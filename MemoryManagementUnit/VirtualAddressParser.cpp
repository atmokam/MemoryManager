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
    
        offsets.pageDir = virtualAddress >> (offsetBits.pageTable * offsetBits.pteLevels + offsetBits.page);
        // eg. 10101010110000000000000000000000 -> 1010101011 for 10 bit PDE

        uint32_t ptMask = (1u << offsetBits.pageTable) - 1;
        auto levels = offsetBits.pteLevels;

        for(size_t i = 0; i < levels; ++i)
            offsets.pageTables.push_back(
                (virtualAddress >> (offsetBits.page + offsetBits.pageTable * i)) & ptMask);
        

        uint32_t pageMask = (1u << offsetBits.page) - 1;
        offsets.offset = virtualAddress & pageMask;

        return offsets;
    }

    void VirtualAddressParser::calculateVirtualAddressOffsets(auto addressSize, auto pageSize)
    {
        AddressBits bits;
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