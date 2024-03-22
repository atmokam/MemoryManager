#ifndef PAGINGMANAGER_HPP
#define PAGINGMANAGER_HPP

#include <memory>

class PagingManager
{
    AddressSplitter addressSplitter;
    std::unique_ptr<EntryGroup> pdbr;
public:
    
    static PagingManager& getInstance()
    {
        static PagingManager instance;
        return instance;
    }


private:
    PagingManager();


    PagingManager(const PagingManager&) = delete;
    PagingManager& operator=(const PagingManager&) = delete;
    PagingManager(PagingManager&&) = delete;
    PagingManager& operator=(PagingManager&&) = delete;
    ~PagingManager() = default;
};

#endif