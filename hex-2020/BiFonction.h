#pragma once

namespace hex
{

    template <class A, class B, class APRES>
    struct BiFonction
    {
    public:
        BiFonction() {}
        APRES operator()(const A& a, const B& b) const {
            return reduce(a, b);
        }
        virtual ~BiFonction() {}
    protected:
        virtual APRES reduce(const A&, const B&) const = 0;
    };

    template <class A, class B, class C>
    struct Addition : public BiFonction<A, B, C>
    {
    public:
        Addition() : BiFonction<A, B, C>() {}
    protected:
        virtual C reduce(const A& a, const B& b) const {
            return a + b;
        }
    };

    template <class A, class B, class C>
    struct Soustraction : public BiFonction<A, B, C>
    {
    public:
        Soustraction() : BiFonction<A, B, C>() {}
    protected:
        virtual C reduce(const A& a, const B& b) const {
            return a - b;
        }
    };

    template <class A, class B, class C>
    struct Multiplication : public BiFonction<A, B, C>
    {
    public:
        Multiplication() : BiFonction<A, B, C>() {}
    protected:
        virtual C reduce(const A& a, const B& b) const {
            return a * b;
        }
    };

    template <class A, class B, class C>
    struct Division : public BiFonction<A, B, C>
    {
    public:
        Division() : BiFonction<A, B, C>() {}
    protected:
        virtual C reduce(const A& a, const B& b) const {
            return a / b;
        }
    };

    template <class A, class B, class C>
    struct Modulo : public BiFonction<A, B, C>
    {
    public:
        Modulo() : BiFonction<A, B, C>() {}
    protected:
        virtual C reduce(const A& a, const B& b) const {
            return a % b;
        }
    };

}
