#include "MemoryManagementUnit/PagingManager.hpp"
#include <iostream>

int main()
{
    MMU::PagingManager pm(32, 1024);
    unsigned int va = 0b10010000001000000000101000000000;
    unsigned int pa = 0b10010010001000000000101000001000;
    unsigned int ha = 0b10010010001000000000101001001000;
    pm.mapPageTo(va, &pa);
    pm.mapPageTo(va , &ha);


    // MMU::VirtualAddressParser vap(32, 1024);
    // auto offsets = vap.parse(0b10010000001000000000101000000000);
    // std::cout << "Page Directory: " << offsets.pageDir << std::endl;
    // for(auto& pt : offsets.pageTables)
    //     std::cout << "Page Table: " << pt << std::endl;
    // std::cout << "Offset: " << offsets.offset << std::endl;

}