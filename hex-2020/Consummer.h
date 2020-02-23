#pragma once

namespace hex
{

    template<class T>
    struct Consummer
    {
    public:
        Consummer() {}
        virtual void consommer(T) = 0;
    };

}
