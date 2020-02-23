#pragma once

namespace hex
{

    template <class T>
    struct Generator
    {
    public:
        Generator() {}
        virtual T generer() = 0;
        virtual ~Generator() {}
    };

}
