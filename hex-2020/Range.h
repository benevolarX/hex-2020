#pragma once

#include <string>
#include "Constantes.h"
#include "DuoPredicate.h"

namespace hex
{

    template<class VAL> struct Range;
    template<class VAL> struct Min;
    template<class VAL>
    struct Max : Predicate<VAL>
    {
    public :
        Max(VAL v, bool b = false) : Predicate<VAL>(v), strict(b) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Max";
        }
        virtual Max<VAL> operator * (const Max<VAL> & et)
        {
            if (this->get_val() == et.get_val()) {
                return (this->is_strict()) ? *this : et;
            }
            return (this->val < et.val) ? et : *this;
        }
        virtual Range<VAL> operator * (const Min<VAL> & mini)
        {
            return Range<VAL>(mini, *this);
        }
        bool is_strict() const { return this->strict; }
    protected :
        bool strict;
        virtual bool test(const VAL & v) const
        {
            return (this->strict) ? v < this->get_val() : v <= this->get_val();
        }
    };

    template<class VAL> struct Range;
    template<class VAL>
    struct Min : Predicate<VAL>
    {
    public :
        Min(VAL v, bool b = false) : Predicate<VAL>(v), strict(b) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Min";
        }
        virtual Min<VAL> operator * (const Min<VAL> & et)
        {
            if (this->get_val() == et.get_val()) {
                return (this->is_strict()) ? *this : et;
            }
            return (this->val > et.val) ? et : *this;
        }
        virtual Range<VAL> operator * (const Max<VAL> & maxi)
        {
            return Range<VAL>(this->get_val(), maxi.get_val(), this->is_strict(), maxi.is_strict());
        }
        bool is_strict() const { return this->strict; }
    protected :
        bool strict;
        virtual bool test(const VAL & v) const
        {
            return (this->strict) ? this->get_val() < v : this->get_val() <= v;
        }
    };

    template<class A, class B, class C> struct PredicateEt;
    template<class VAL>
    struct Range : PredicateEt<VAL, Min<VAL>, Max<VAL> >
    {
    public :
        Range(VAL mini, VAL maxi, bool str_min = false, bool str_max = false) :
            PredicateEt<VAL, Min<VAL>, Max<VAL>>(Min<VAL>(mini, str_min), Max<VAL>(maxi, str_max)) {}
        Range(const Min<VAL> & mini, const Max<VAL> & maxi) : PredicateEt<VAL, Min<VAL>, Max<VAL>>(mini, maxi) {}
        Range(const Max<VAL> & maxi, const Min<VAL> & mini) : PredicateEt<VAL, Min<VAL>, Max<VAL>>(mini, maxi) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Range";
        }
    };

    struct Positif : Min<int>
    {
    public :
        Positif() : Min<int>(hex::ZERO) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Positif";
        }
    };

    struct Negatif : Max<int>
    {
    public :
        Negatif() : Max<int>(hex::ZERO) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Negatif";
        }
    };

}
