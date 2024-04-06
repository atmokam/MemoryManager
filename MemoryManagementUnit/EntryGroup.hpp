#ifndef ENTRYGROUP_HPP
#define ENTRYGROUP_HPP

#include <vector>
#include <memory>

#include "EntryBase.hpp"

namespace MMU
{
    struct AddressOffsets;

    class EntryGroup : public EntryBase
    {
    protected:
        std::vector<std::shared_ptr<EntryBase>> entries;

    public:
        explicit EntryGroup(uint32_t size);
        PageAddressPtr at(AddressOffsets offsets) override = 0;
        virtual ~EntryGroup() override = default;

        size_t size() const noexcept;
    };
}
#endif