#ifndef IVISITABLE_HPP
#define IVISITABLE_HPP

namespace MMU
{
    class IVisitor;

    class IVisitable
    {
    public:
        virtual void accept(IVisitor& visitor) = 0;
    };
}

#endif