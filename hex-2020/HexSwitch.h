#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include "Constantes.h"

namespace hex
{

    template<class T>
    struct HexSwitch
    {
    public:
        HexSwitch() {}
        unsigned int operator()(T v) {
            int i = 0;
            for (std::vector<Predicate<T>*> t : this->tests) {
                bool ok = true;
                unsigned int n = 0;
                while (ok && n < t.size()) {
                    ok = t[n]->operator()(v);
                    n++;
                }
                if (ok) {
                    return i;
                }
                i++;
            }
            return hex::MINUS_ONE;
        }

        void add_case(Predicate<T>* t, int n = hex::MINUS_ONE) {
            int i = n;
            if (i <= hex::MINUS_ONE) {
                std::vector<Predicate<T>*> l;
                this->tests.push_back(l);
                i = this->tests.size() - 1;
            }
            this->tests[i].push_back(t);
        }

        void add_case(std::vector<Predicate<T>*> t, int n = hex::MINUS_ONE) {
            if (n <= hex::MINUS_ONE) {
                this->tests.push_back(t);
            }
            else {
                this->tests[n].insert(this->tests[n].end(), t.begin(), t.end());
            }
        }
        ~HexSwitch() {
            for (std::vector<Predicate<T>*> l : this->tests) {
                for (Predicate<T>* t : l) {
                    t = 0;
                }
            }
        }
    protected:
        std::vector<std::vector<Predicate<T>*>> tests;
    };

}
