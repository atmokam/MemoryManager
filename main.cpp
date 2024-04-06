#include "MemoryManagementUnit/VirtualAddressParser.hpp"
#include <iostream>

int main()
{
    MMU::VirtualAddressParser vap(32, 4096);
    auto offsets = vap.parse(0b10010000001000000000101000000000);
    std::cout << "Page Directory: " << offsets.pageDir << std::endl;
    for(auto& pt : offsets.pageTables)
        std::cout << "Page Table: " << pt << std::endl;
    std::cout << "Offset: " << offsets.offset << std::endl;

}