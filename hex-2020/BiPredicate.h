#pragma once

#include "Predicate.h"

namespace hex
{

    template<class A, class B>
    struct BiPredicate : public Predicate<A>
    {
    public:
        BiPredicate() : Predicate<A>() {}
        virtual bool operator()(const A& a, const B& b)
        {
            return this->test(a, b);
        }
    protected:
        virtual bool test(const A&) const {
            return false;
        }
        virtual bool test(const A&, const B&) const = 0;
    };

}
