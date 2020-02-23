#pragma once

#include "Predicate.h"
#include "Exception.h"

namespace hex
{

    template<class VAL>
    class Variable
    {
    public:
        Variable(VAL n) : val(n) {}
        Variable(VAL n, Predicate<VAL>* p) noexcept(false) : val(n) {
            if (!p(n)) {
                throw HexException(p->get_msg_error());
            }
        }
        void add_contrainte(Predicate<VAL>* p) {
            this.test(p);
            this.contraintes.push_back(p);
        }
        VAL get() {
            return this->val;
        }
        void set(VAL v) {
            this.val = v;
            this.test();
        }
    protected:
        VAL val;
        std::vector<Predicate<VAL>* > contraintes;
        void test() noexcept(false) {
            for (Predicate<VAL>* t : this.contraintes) {
                this->test(t);
            }
        }
        void test(Predicate<VAL>* t) noexcept(false) {
            if (!test(this.get())) {
                throw HexException(test->get_msg_error());
            }
        }
    };

}
