#pragma once

#include "Fonction.h"

namespace hex
{
    template<class VAL>
    struct Predicate : public Fonction<VAL, bool>
    {
    public :
        Predicate(const VAL & v) : val(v) {}
        Predicate() : val() {}
        virtual bool operator()(const VAL & a) const
        {
            return this->test(a);
        }
        VAL get_val() const
        {
            return this->val;
        }
        virtual std::string get_msg_error() {
            return "erreur inconnue de Predicate";
        }
    protected :
        virtual bool test(const VAL &) const = 0;
        VAL val;
    };

    template<class VAL>
    struct PredicateOui : Predicate<VAL>
    {
    public :
        virtual std::string get_msg_error() {
            return "erreur inconnue de PredicateOui";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return true;
        }
    };

    template<class VAL>
    struct PredicateNon : Predicate<VAL>
    {
    public :
        virtual std::string get_msg_error() {
            return "erreur inconnue de PredicateNon";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return false;
        }
    };

    template<class VAL>
    struct Equal : Predicate<VAL>
    {
    public :
        Equal(VAL v) : Predicate<VAL>(v) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Equal";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return (v == this->get_val());
        }
    };

    template<class VAL>
    struct NotEqual : Predicate<VAL>
    {
    public :
        NotEqual(VAL v) : Predicate<VAL>(v) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de NotEqual";
        }
    protected :
        virtual bool test(const VAL & v) const
        {
            return !(v == this->val);
        }
    };

    template<class T>
    struct NotNull : NotEqual<T>
    {
    public :
        NotNull() : NotEqual<T>(hex::ZERO) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de NotNull";
        }
    };

    template<class A, class B>
    struct PredicateMemFun : public Predicate<B>
    {
    public :
        PredicateMemFun(A B::*g, Predicate<A> * t) : Predicate<B>(), get(g), mon_test(t) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de PredicateMemFun";
        }
    protected :
        virtual bool test(const B & b) const
        {
            return mon_test(get(b));
        }
        A B::* get;
        Predicate<A> * mon_test;
    };

}
