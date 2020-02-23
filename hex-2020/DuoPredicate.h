#pragma once

#include "Predicate.h"

namespace hex
{

    template<class V> struct Predicate;
    template<class V> class T1;
    template<class V> class T2;
    template<class VAL, class P1 = T1<VAL>, class P2 = T2<VAL>>
    struct DuoPredicate : public Predicate<VAL>
    {
    public :
        DuoPredicate(const P1 & t1, const P2 & t2) : Predicate<VAL>(), test1(t1), test2(t2) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de DuoPredicate";
        }
    protected :
        P1 test1;
        P2 test2;
    };

    template<class V> class T1;
    template<class V> class T2;
    template<class VAL, class P1, class P2> struct DuoPredicate;
    template<class VAL, class P1 = T1<VAL>, class P2 = T2<VAL>>
    struct PredicateEt : public DuoPredicate<VAL, P1, P2>
    {
    public :
        PredicateEt(const P1 & t1, const P2 & t2) : DuoPredicate<VAL, P1, P2>(t1, t2) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de PredicateEt";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return (this->test1(v)) && (this->test2(v));
        }
    };

    template<class V> class T1;
    template<class V> class T2;
    template<class VAL, class P1, class P2> struct DuoPredicate;
    template<class VAL, class P1 = T1<VAL>, class P2 = T2<VAL>>
    struct PredicateOu : public DuoPredicate<VAL, P1, P2>
    {
    public :
        PredicateOu(const P1 & t1, const P2 & t2) : DuoPredicate<VAL, P1, P2>(t1, t2) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de PredicateOu";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return (this->test1(v)) || (this->test2(v));
        }
    };

    template<class V> class T1;
    template<class V> class T2;
    template<class VAL, class P1, class P2> struct DuoPredicate;
    template<class VAL, class P1 = T1<VAL>, class P2 = T2<VAL>>
    struct PredicateOuEx : public DuoPredicate<VAL, P1, P2>
    {
    public :
        PredicateOuEx(const P1 & t1, const P2 & t2) : DuoPredicate<VAL, P1, P2>(t1, t2) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de PredicateOuEx";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return (test1(v) ^ test2(v));
        }
    };

}
