#pragma once

// #include "Constantes.h"

namespace hex
{

    template <class AVANT, class APRES>
    struct Fonction
    {
    public:
        Fonction() {}
        virtual APRES operator()(const AVANT&) const = 0;
        virtual ~Fonction() {}
    };

    template <class AVANT, class APRES>
    struct Getter : public Fonction<AVANT, APRES>
    {
    public:
        Getter(APRES AVANT::* g) : Fonction<AVANT, APRES>(), get(g) {}
        virtual APRES operator()(const AVANT& o) const {
            return get(o);
        }
    protected:
        APRES AVANT::* get;
    };

}
