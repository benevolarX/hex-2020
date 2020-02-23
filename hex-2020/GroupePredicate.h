#pragma once


#include <vector>
#include <algorithm>
#include "Predicate.h"

namespace hex
{

    template<class T> struct Predicate;
    template<class T>
    struct GroupePredicate : public Predicate<std::vector<T>>
    {
    public:
        GroupePredicate() : Predicate<std::vector<T> >() {}
        GroupePredicate(T e) : Predicate<std::vector<T> >(), elem(e) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de GroupePredicate";
        }
    protected:
        T elem;
    };

    template<class T> struct GroupePredicate;
    template<class T>
    struct NoDoublon : public GroupePredicate<T>
    {
    public:
        NoDoublon() : GroupePredicate<T>() {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de NoDoublon";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            std::sort(v.begin(), v.end());
            auto last = std::unique(v.begin(), v.end());
            return std::distance(v.begin(), last) == v.size();
        }
    };

    template<class T> struct GroupePredicate;
    template<class T>
    struct MaxN : public GroupePredicate<T>
    {
    public:
        MaxN(int n) : GroupePredicate<T>(), mon_max(n) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de MaxN";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            for (T e : v) {
                if (this.mon_max > std::count(v.begin(), v.end(), e)) {
                    return false;
                }
            }
            return true;
        }
        int mon_max;
    };

    template<class T> struct GroupePredicate;
    template<class T>
    struct Contains : public GroupePredicate<T>
    {
    public:
        Contains(T e) : GroupePredicate<T>(e) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Contains";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return std::find(v.begin(), v.end(), this->elem) != v.end();
        }
    };

    template<class T> struct GroupePredicate;
    template<class T> struct Predicate;
    template<class T>
    struct MatchAll : public GroupePredicate<T>
    {
    public:
        MatchAll(Predicate<T>* t) : GroupePredicate<T>(), mon_test(t) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de MatchAll";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return std::any_of(v.begin(), v.end(), mon_test);
        }
        Predicate<T> mon_test;
    };

    template<class T> struct GroupePredicate;
    template<class T> struct Predicate;
    template<class T>
    struct MatchNone : public GroupePredicate<T>
    {
    public:
        MatchNone(Predicate<T>* t) : GroupePredicate<T>(), mon_test(t) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de MatchNone";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return std::none_of(v.begin(), v.end(), mon_test);
        }
        Predicate<T> mon_test;
    };

    template<class T> struct GroupePredicate;
    template<class T> struct Predicate;
    template<class T>
    struct Sorted : public GroupePredicate<T>
    {
    public:
        Sorted() : GroupePredicate<T>() {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Sorted";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return std::is_sorted(v.begin(), v.end());
        }
    };

    template<class T> struct GroupePredicate;
    template<class T> struct Predicate;
    template<class T>
    struct MaxElem : public GroupePredicate<T>
    {
    public:
        MaxElem(T e) : GroupePredicate<T>(e) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de MaxElem";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return this->elem >= std::max_element(v.begin(), v.end());
        }
    };

    template<class T> struct GroupePredicate;
    template<class T> struct Predicate;
    template<class T>
    struct MinElem : public GroupePredicate<T>
    {
    public:
        MinElem(T e) : GroupePredicate<T>(e) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de MinElem";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return this->elem <= std::min_element(v.begin(), v.end());
        }
    };

    template<class T> struct GroupePredicate;
    template<class T> struct Predicate;
    template<class T>
    struct Size : public GroupePredicate<T>
    {
    public:
        Size(int n) : GroupePredicate<T>(), taille(n) {}
        virtual std::string get_msg_error() {
            return "erreur inconnue de Size";
        }
    protected:
        virtual bool test(const std::vector<T>& v) const {
            return this->mon_max == v.size();
        }
        int taille;
    };

}
