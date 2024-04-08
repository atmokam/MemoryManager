#ifndef ENTRYGROUP_HPP
#define ENTRYGROUP_HPP

#include <vector>
#include <memory>

#include "EntryBase.hpp"
#include "IVisitable.hpp"

namespace MMU
{
    struct AddressOffsets;

    class EntryGroup : public EntryBase, public IVisitable
    {
    protected:
        std::vector<std::shared_ptr<EntryBase>> entries;

        size_t level = 0;

    public:
        explicit EntryGroup(unsigned int size);
        virtual std::shared_ptr<EntryBase> getEntry(size_t index) = 0;
        virtual void setEntry(size_t index, std::shared_ptr<EntryBase> entry) = 0;

        virtual void accept(IVisitor& visitor) override = 0;
        virtual ~EntryGroup() override = default;

        size_t size() const noexcept;
        size_t getLevel() const noexcept;
        void setLevel(size_t level) noexcept;
    };
}
#endif