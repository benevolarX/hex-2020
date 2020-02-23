#pragma once

#include "Constantes.h"

namespace hex
{

    template<class T>
    struct Comparable
    {
    public:
        int operator()(const T& o1, const T& o2) const
        {
            return (o1 == o2) ? hex::ZERO : ((o1 < o2) ? hex::MINUS_ONE : hex::ONE);
        }
    };

    template<class OBJ, class GET>
    struct Comparator
    {
    public:
        Comparator(GET OBJ::* pm) : get(pm) {}
        int operator()(const OBJ& o1, const OBJ& o2) const
        {
            Comparable<GET> r;
            return r(get(o1), get(o2));
        }
    protected:
        GET OBJ::* get;
    };

}
